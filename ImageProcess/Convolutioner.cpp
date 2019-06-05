#include "Convolutioner.h"
#include <algorithm>
using namespace IPFbyCJY;
Convolutioner::Convolutioner(QImage *img):Processer(img)
{
}

Convolutioner::~Convolutioner()
{
}

// int Convolutioner::conv(const mat &a,const mat &b)const
// {
// 	int out = 0;
// 
// 	if(a.size()!=b.size())
// 		return -1;
// 	int h = a.size();
// 	int w = a[0].size();
// 	for (int i=0;i!=h;i++)
// 	{
// 		if(a[i].size()!=w || b[i].size()!=w)
// 			return -1;
// 		for (int j=0;j!=w;j++)
// 		{
// 			out += a[i][j] * b[i][j];
// 		}
// 	}
// 	
// 	if(out < 0)
// 		out = 0;
// 	if(out > 255)
// 		out = 255;
// 
// 	return out;
// }
// 
// mat Convolutioner::GetNeighbour(int x,int y,int s,const mat &m,int w, int h)
// {
// 	mat out;
// 	out.resize(s);
// 	int offset = s / 2;
// 	for (int i=-offset;i!=offset+1;i++)
// 	{
// 		for (int j=-offset;j!=offset+1;j++)
// 		{
// 			if(i+x < 0 || j + y <0 || i + x>=w || j+y >= h)
// 			{
// 				out[i+offset].push_back(0);
// 				continue;
// 			}
// 			out[i+offset].push_back(m[i+x][j+y]);
// 		}
// 	}
// 	return out;
// }
Sobel::Sobel(QImage *img):EdgeDector(img)
{
	kernal.resize(3);
		kernal[0].push_back(-1);
		kernal[0].push_back(-2);
		kernal[0].push_back(-1);
		kernal[1].resize(3);
		kernal[2].push_back(1);
		kernal[2].push_back(2);
		kernal[2].push_back(1);
	kernal1.resize(3);
		kernal1[0].push_back(-1);
		kernal1[0].push_back(0);
		kernal1[0].push_back(1);
		kernal1[1].push_back(-2);
		kernal1[1].push_back(0);
		kernal1[1].push_back(2);
		kernal1[2].push_back(-1);
		kernal1[2].push_back(0);
		kernal1[2].push_back(1);

	InverseKernel();
}

Sobel::~Sobel(){}

CunstomCon::CunstomCon(QImage* img):Convolutioner(img)
{

}
CunstomCon::~CunstomCon(){}
void Convolutioner::setKernel(mat k)
{
	kernal = k;
	inverse_kernal = kernal;
	int w = inverse_kernal.size();
	int h = inverse_kernal[0].size();
	for (int i=0;i!=w;i++)
	{
		for (int j=0;j!=h;j++)
		{
			inverse_kernal[i][j] = kernal[w-1-i][h-1-j];
		}
	}
}


QImage* CunstomCon::process()
{
	mat imgdata = img2mat();
	mat datacpy = imgdata;
	
	int s1 = kernal.size();
	int s2 = kernal[0].size();
	int offset1 = s1 / 2;
	int offset2 = s2 / 2;
	
	int value = 0;
	for (int i=0;i!=w;i++)
	{
		for (int j=0;j!=h;j++)
		{
			for (int k=-offset1; k!=offset1+1; k++)
			{
				for (int l=-offset2; l!=offset2+1;l++)
				{
					if(i + k<0 || i+k>=w || j+l <0 || j+l>=h)
						value += 0;
					else
						value += imgdata[i+k][j+l] * inverse_kernal[k+offset1][l+offset2];
				}
			}
			if(value>255)
				value = 255;
			if(value<0)
				value = 0;
			datacpy[i][j] = value;
			value = 0;
		}
	}
	return mat2img(datacpy);
}


Prewitt::Prewitt(QImage *img):EdgeDector(img)
{
	kernal.resize(3);
	kernal[0].push_back(-1);
	kernal[0].push_back(-1);
	kernal[0].push_back(-1);
	kernal[1].resize(3);
	kernal[2].push_back(1);
	kernal[2].push_back(1);
	kernal[2].push_back(1);

	kernal1.resize(3);
	kernal1[0].push_back(-1);
	kernal1[0].push_back(0);
	kernal1[0].push_back(1);
	
	kernal1[1].push_back(-1);
	kernal1[1].push_back(0);
	kernal1[1].push_back(1);

	kernal1[2].push_back(-1);
	kernal1[2].push_back(0);
	kernal1[2].push_back(1);

	InverseKernel();
}


Prewitt::~Prewitt(){}

QImage* EdgeDector::process()
{
	mat imgdata = img2mat();
	mat datacpy = imgdata;
	int valueH = 0;
	int valueV = 0;
	int value = 0;
	for (int i=0;i!=w;i++)
	{
		for (int j=0;j!=h;j++)
		{
			for (int k=-1;k!=2;k++)
			{
				for (int l=-1;l!=2;l++)
				{
					if(i + k<0 || i+k>=w || j+l <0 || j+l>=h)
					{
						valueH += 0;
						valueV += 0;
					}
					else
					{
						valueH += imgdata[i+k][j+l] * inverse_kernal[k+1][l+1];
						valueV += imgdata[i+k][j+l] * inverse_kernal1[k+1][l+1];
 					}
				}
			}
			value = valueH>valueV? valueH:valueV;
			if(value>255)
				value = 255;
			if(value<0)
				value = 0;
			datacpy[i][j] = value;
			value = 0;
			valueH = 0;
			valueV = 0;
		}
	}
	return mat2img(datacpy);
}







GaussianFilter::GaussianFilter(QImage* img, int size,float the):Filter(img,size),theta(the)
{
	kernal.resize(size);
	for (int i=0;i!=size;i++)
	{
		kernal[i].resize(size);
	}

	int offset = size / 2;
	
	float coff = 1/(2*PI * theta * theta);

	for (int i=0;i!=size;i++)
	{
		for (int j=0;j!=size;j++)
		{
			kernal[i][j] =  coff * pow(e,float(-((i-offset)*(i-offset)+(j-offset)*(j-offset))/(2*theta*theta)));
		}
	}
	float mini = kernal[0][0];
	int sum=0;
	for (int i=0;i!=size;i++)
	{
		for (int j=0;j!=size;j++)
		{
			kernal[i][j] = (int)(kernal[i][j] / mini);
			sum+= kernal[i][j];
		}
	}
	for (int i=0;i!=size;i++)
	{
		for (int j=0;j!=size;j++)
		{
			kernal[i][j] = kernal[i][j] / sum;
		}
	}
	InverseKernel();
}

MeanFilter::MeanFilter(QImage* img, int size):Filter(img,size)
{
	kernal.resize(size);
	float value = 1.0 / (size*size);
	for (int i=0;i!=size;i++)
	{
		for (int j=0;j!=size;j++)
		{
			kernal[i].push_back(value);
		}
	}
	InverseKernel();
}

MedianFilter::MedianFilter(QImage* img,int size):Filter(img,size){}

QImage* Filter::process()
{
	mat imgdata = img2mat();
	mat datacpy = imgdata;

	int offset= m_size / 2;

	int value = 0;
	for (int i=0;i!=w;i++)
	{
		for (int j=0;j!=h;j++)
		{
			for (int k=-offset; k!=offset+1; k++)
			{
				for (int l=-offset; l!=offset+1;l++)
				{
					if(i + k<0 || i+k>=w || j+l <0 || j+l>=h)
						value += 0;
					else
						value += imgdata[i+k][j+l] * inverse_kernal[k+offset][l+offset];
				}
			}
			if(value>255)
				value = 255;
			if(value<0)
				value = 0;
			datacpy[i][j] = value;
			value = 0;
		}
	}
	return mat2img(datacpy);
}

QImage* MedianFilter::process()
{
	mat imgdata = img2mat();
	mat datacpy = imgdata;

	int offset = m_size / 2;
	int value = 0;
	vector<float> sortlst;
	for (int i=0;i!=w;i++)
	{
		for (int j=0;j!=h;j++)
		{
			for (int k=-offset; k!=offset+1; k++)
			{
				for (int l=-offset; l!=offset+1;l++)
				{
					if(i + k<0 || i+k>=w || j+l <0 || j+l>=h)
					{
 							sortlst.push_back(0);
					}
					else
					{
 							sortlst.push_back(imgdata[i+k][j+l]);
					}
				}
			}
			sort(sortlst.begin(),sortlst.end());
			int value = sortlst[m_size*m_size/2+1];
			value = value>255?255:value;
			value = value<0?0:value;
			datacpy[i][j] = value;

			value = 0;
			sortlst.clear();
		}
	}
	return mat2img(datacpy);
}