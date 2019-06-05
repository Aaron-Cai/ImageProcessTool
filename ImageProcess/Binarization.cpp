#include "Binarization.h"


using namespace IPFbyCJY;


Binarization::Binarization(QImage* img):Processer(img)
{
}

Binarization::~Binarization()
{
}

QImage* Binarization::process()
{
	int width=mp_img->width();
	int height=mp_img->height();
	int bytePerLine = mp_img->bytesPerLine();
	unsigned char *data=mp_img->bits();
	unsigned char *binarydata=new unsigned char[bytePerLine*height];

	unsigned char g;
	for (int i=0;i<height;i++)
	{
		for (int j=0;j<width;j++)
		{
			g = *(data+i*bytePerLine+j*3);
			if(int(g) >= threshold)
			{
				binarydata[i*bytePerLine+j*3]  =0xFF;
				binarydata[i*bytePerLine+j*3+1]=0xFF;
				binarydata[i*bytePerLine+j*3+2]=0xFF;
			}
			else
			{
				binarydata[i*bytePerLine+j*3]  =0x00;
				binarydata[i*bytePerLine+j*3+1]=0x00;
				binarydata[i*bytePerLine+j*3+2]=0x00;
			}
		}
	}	
	QImage *out=new QImage(binarydata,width,height,bytePerLine,QImage::Format_RGB888);
	return out;
}
