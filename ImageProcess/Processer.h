#pragma  once
#include <QImage>
#include <math.h>
#include <vector>
using namespace std;


namespace IPFbyCJY
{
	typedef vector<vector<float>> mat;
	class Processer
	{
	public:
		Processer(QImage* img):mp_img(img),w(mp_img->width()),h(mp_img->height())
		{
		}
		virtual ~Processer(){}
		
		virtual QImage* process()=0;


		void SetImage(QImage* image)
		{
			mp_img = image;
		}
		static vector<int> Histogram(QImage* img)
		{
			unsigned char* graydata = img->bits();
			vector<int> hist(256);
			for (int i=0;i!=img->width();i++)
			{
				for (int j=0;j!=img->height();j++)
				{
					int index = int(*graydata);
					hist[index] = hist[index]+1;
					graydata+=3;
				}
			}
			graydata = NULL;
			return hist;
		}


		static QImage* rgb2gray(QImage* img)
		{
			QImage *grayImg;
			int width=img->width();
			int height=img->height();
			int bytePerLine=(width*24+31)/8;
			unsigned char *data=img->bits();
			unsigned char *graydata=new unsigned char[bytePerLine*height];
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
			case QImage::Format_Indexed8:
				unsigned char graylevel;
				for (int i=0;i!=height;i++)
				{
					for (int j=0;j!=width;j++)
					{
						graylevel = data[img->bytesPerLine()*i+j];
						graydata[i*bytePerLine+j*3]  =graylevel;
						graydata[i*bytePerLine+j*3+1]=graylevel;
						graydata[i*bytePerLine+j*3+2]=graylevel;
					}
				}
				break;
			default:break;
			}

			grayImg=new QImage(graydata,width,height,bytePerLine,QImage::Format_RGB888);

			return grayImg;
		}
	protected:
		QImage* mat2img(const mat &data)
		{
			QImage *out = new QImage(*mp_img);
			int w = out->width();
			int h = out->height();
			for (int i=0;i!=w;i++)
			{
				for (int j=0;j!=h;j++)
				{
					out->setPixel(i,j,qRgb(data[i][j],data[i][j],data[i][j]));
				}
			}
			return out;
		}
		mat img2mat()
		{
			mat imgdata;
			//int w = mp_img->width();
			//int h = mp_img->height();
			imgdata.resize(w);
			for (int i=0;i!=w;i++)
				imgdata[i].resize(h);
			for (int i=0;i!=w;i++)
			{
				for (int j=0;j!=h;j++)
				{
					imgdata[i][j] = qGray(mp_img->pixel(i,j));
				}
			}
			return imgdata;
		}
	protected:
		QImage* mp_img;
		vector<int> m_histogram;
		int w;
		int h;
	};
}
