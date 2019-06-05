#pragma once
#include "Processer.h"
namespace IPFbyCJY
{
	class Binarization :
		public Processer
	{
	public:
		Binarization(QImage* img);
		virtual ~Binarization();
		virtual QImage* process();
		int threshold;
	};

	class OtsuBinarization:public Binarization
	{
	public:
		OtsuBinarization(QImage* img):Binarization(img)
		{
			vector<int> histogram = Histogram(img);
			int total = 0;
			for (int i=0;i!=histogram.size();i++)
			{
				total += histogram[i];
			}

			double sum = 0;
			for (int i = 1; i < histogram.size(); ++i)
				sum += i * histogram[i];
			double sumB = 0;
			double wB = 0;
			double wF = 0;
			double mB;
			double mF;
			double max = 0.0;
			double between = 0.0;
			double threshold1 = 0.0;
			double threshold2 = 0.0;
			for (int i = 0; i != 256; ++i)
			{
				wB += histogram[i];
				if (wB == 0)
					continue;
				wF = total - wB;
				if (wF == 0)
					break;
				sumB += i * histogram[i];
				mB = sumB / wB;
				mF = (sum - sumB) / wF;
				between = wB * wF * (mB - mF)*(mB - mF);
				if ( between > max )
				{
					threshold1 = i;
					// 			if ( between > max )
					// 			{
					// 				threshold2 = i;
					// 			}
					max = between;            
				}
			}
			threshold = threshold1;

		}
		virtual	~OtsuBinarization(){}
	};

	class EntropyBinarization:public Binarization
	{
	public:
		EntropyBinarization(QImage* img):Binarization(img)
		{
			vector<int> hist = Histogram(img);

			int graylevel = hist.size();
			//int graylevel = 256;
			int sum=0;
			for (int i=0;i!=graylevel;i++)
			{
				sum += hist[i];
			}

			int lefsum = 0;
			int rightsum = 0;

			double max=0;
			for (int t=0;t!=graylevel;t++)
			{
				lefsum += hist[t];

				if(lefsum == 0)
					continue;

				rightsum = sum - lefsum;
				if(rightsum == 0)
					break;


				/*long*/ double h_b=0;
				/*long*/ double h_w=0;

				for (int i=0;i<=t;i++)
				{
					//double p = double(hist[i])/double(lefsum);
					if(hist[i]==0)
						continue;
					h_b -= double(hist[i])/double(lefsum)* (log(double(hist[i]))-log(double(lefsum)));
				}
				for (int i=t+1;i!=graylevel;i++)
				{
					// 			double p = double(hist[i])/double(rightsum);
					// 			h_w -= p * logl(p);
					if(hist[i]==0)
						continue;
					h_b -= double(hist[i])/double(rightsum)* (log(double(hist[i]))-log(double(rightsum)));

				}
				if(h_b + h_w > max)
				{
					max = h_b + h_w;
					threshold = t;
				}

			}
		}
		~EntropyBinarization(){}
	};

}
