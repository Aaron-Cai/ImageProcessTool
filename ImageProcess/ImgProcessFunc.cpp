#include "ImgProcessFunc.h"
#include <math.h>


QImage* IPFbyCJY::rgb2gray(QImage* img)
{
	QImage *grayImg;
	int width=img->width();
	int height=img->height();
	int bytePerLine=(width*24+31)/8;

	unsigned char *data=img->bits();
	unsigned char *graydata=new unsigned char[bytePerLine*height];

	QImage::Format f = img->format();
	switch(img->format())
	{
	case QImage::Format_RGB32:
		unsigned char r,g,b;
		for (int i=0;i<height;i++)
		{
			for (int j=0;j<width;j++)
			{
				r = *(data+2);
				g = *(data+1);
				b = *data;

				graydata[i*bytePerLine+j*3]  =(r*30+g*59+b*11)/100;
				graydata[i*bytePerLine+j*3+1]=(r*30+g*59+b*11)/100;
				graydata[i*bytePerLine+j*3+2]=(r*30+g*59+b*11)/100;
				data+=4;
			}
		}	
		break;
	default:break;
	}

	grayImg=new QImage(graydata,width,height,bytePerLine,QImage::Format_RGB888);

	return grayImg;

}

int IPFbyCJY::otsuMethod(vector<int> histogram) 
{

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
	//return ( threshold1 + threshold2 ) / 2.0;
	return threshold1;
}

int IPFbyCJY::entropyMethod(vector<int> hist)
{
	int threshold=0;
	
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
	return threshold;
}