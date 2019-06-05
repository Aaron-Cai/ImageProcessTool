#include "Morphology.h"
#include <fstream>
#include <windows.h>
using namespace IPFbyCJY;



// shift version of erosion and dilation, long bu not work ,a pity
// QImage* Dilation::process()
// {
// 	unsigned char* data = mp_img->bits();
// 	int bytesperline = mp_img->bytesPerLine();
// 
// 	vector<unsigned char*> shiftdata;
// 	for (int i=0;i!=m_se_sizey;i++)
// 	{
// 		for (int j=0;j!=m_se_sizex;j++)
// 		{
// 			if(m_se[i][j]==0)
// 			{
// 				unsigned char* data1 = new unsigned char[bytesperline*h];
// 				memset(data1,0x00,sizeof(char)*bytesperline*h);
// 				shiftdata.push_back(data1);
// 			}
// 			if(m_se[i][j]==1)
// 			{
// 				unsigned char* data1 = new unsigned char[bytesperline*h];
// 				memset(data1,0x00,sizeof(char)*bytesperline*h);
// 				int offsetx = j - m_ox;
// 				int offsety = i - m_oy;
// 				for (int k = 0 ;k!=h;k++)
// 				{
// 					for (int l=0;l!=w;l++)
// 					{
// 						if(k-offsety<0||k+offsety>=h)
// 							continue;
// 						if(l-offsetx<0||l+offsetx>=(w*3))
// 							continue;
// 						data1[k*bytesperline+l]   = data[(k-offsety)*bytesperline+(l-offsetx)];
// 						data1[k*bytesperline+l+1] = data[(k-offsety)*bytesperline+(l-offsetx)+1];
// 						data1[k*bytesperline+l+2] = data[(k-offsety)*bytesperline+(l-offsetx)+2];
// 					}
// 				}
// 				shiftdata.push_back(data1);
// 			}
// 		}
// 	}
// 	//merge shifted image;
// 	unsigned char* outdata=new unsigned char[bytesperline*h];
// 	for (int i=0;i!=h;i++)
// 	{
// 		for (int j=0;j!=w;j++)
// 		{
// 			char max=0;
// 			for (int k=0;k!=shiftdata.size();k++)
// 			{
// 				if(shiftdata[k][i*bytesperline+j]>=max)
// 					max = shiftdata[k][i*bytesperline+j];
// 			}
// 			outdata[i*bytesperline+j]=max;
// 			outdata[i*bytesperline+j+1]=max;
// 			outdata[i*bytesperline+j+2]=max;
// 		}
// 	}
// 
// 	QImage *out = new QImage(outdata,w,h,bytesperline,QImage::Format_RGB888);
// 	//clear the shift data
// 	for (vector<unsigned char*>::iterator itr=shiftdata.begin();itr!=shiftdata.end();itr++)
// 	{
// 		delete[] *itr;
// 		*itr = NULL;
// 	}
// 
// 	return out;
// }
// 
// QImage* Erosion::process()
// {
// 	unsigned char* data = mp_img->bits();
// 	int bytesperline = mp_img->bytesPerLine();
// 
// 	vector<unsigned char*> shiftdata;
// 	for (int i=0;i!=m_se_sizey;i++)
// 	{
// 		for (int j=0;j!=m_se_sizex;j++)
// 		{
// 			if(m_se[i][j]==0)
// 			{
// 				unsigned char* data1 = new unsigned char[bytesperline*h];
// 				memset(data1,0x00,sizeof(char)*bytesperline*h);
// 				shiftdata.push_back(data1);
// 			}
// 			if(m_se[i][j]==1)
// 			{
// 				unsigned char* data1 = new unsigned char[bytesperline*h];
// 				memset(data1,0x00,sizeof(char)*bytesperline*h);
// 				int offsetx = j - m_ox;
// 				int offsety = i - m_oy;
// 				for (int k = 0 ;k!=h;k++)
// 				{
// 					for (int l=0;l!=w;l++)
// 					{
// 						if(k-offsety<0||k+offsety>=h)
// 							continue;
// 						if(l-offsetx<0||l+offsetx>=(w*3))
// 							continue;
// 						data1[k*bytesperline+l]   = data[(k-offsety)*bytesperline+(l-offsetx)];
// 						data1[k*bytesperline+l+1] = data[(k-offsety)*bytesperline+(l-offsetx)+1];
// 						data1[k*bytesperline+l+2] = data[(k-offsety)*bytesperline+(l-offsetx)+2];
// 					}
// 				}
// 				shiftdata.push_back(data1);
// 			}
// 		}
// 	}
// 	//merge shifted image
// 	unsigned char* outdata=new unsigned char[bytesperline*h];
// 	for (int i=0;i!=h;i++)
// 	{
// 		for (int j=0;j!=w;j++)
// 		{
// 			char min=0xFF;
// 			for (int k=0;k!=shiftdata.size();k++)
// 			{
// 				if(shiftdata[k][i*bytesperline+j]<=min)
// 					min = shiftdata[k][i*bytesperline+j];
// 			}
// 			outdata[i*bytesperline+j]=min;
// 			outdata[i*bytesperline+j+1]=min;
// 			outdata[i*bytesperline+j+2]=min;
// 		}
// 	}
// 
// 	QImage *out = new QImage(outdata,w,h,bytesperline,QImage::Format_RGB888);
// 	//clear the shift data
// 	for (vector<unsigned char*>::iterator itr=shiftdata.begin();itr!=shiftdata.end();itr++)
// 	{
// 		delete[] *itr;
// 		*itr = NULL;
// 	}
// 
// 	return out;
// }

QImage* Dilation::process()
{
	unsigned char* data = mp_img->bits();
	int bytesperline = mp_img->bytesPerLine();
	unsigned char* datacpy = new unsigned char[bytesperline*h];
	memset(datacpy,0,bytesperline*h*sizeof(char));
	for (int i=0;i!=h;i++)
	{
		for (int j =0;j!=w;j++)
		{
			if(m_se[m_oy][m_ox]!=0)
			{
				unsigned char max = data[i*bytesperline+3*j];
				for (int k=0;k!=m_se.size();k++)
				{
					for (int l=0;l!=m_se[k].size();l++)
					{
						if(m_se[k][l]==1)
						{
							int offseth = k-m_oy;
							int offsetw = l-m_ox;
							if(i-offseth<0||i-offseth>=h||j-offsetw<0||j-offsetw>=w)
								continue;
							if(data[(i-offseth)*bytesperline+3*(j-offsetw)]>=max)
								max = data[(i-offseth)*bytesperline+3*(j-offsetw)];
						}
					}
				}
				datacpy[i*bytesperline+j*3]=max;
				datacpy[i*bytesperline+j*3+1]=max;
				datacpy[i*bytesperline+j*3+2]=max;
			}
		}
	}
	QImage* out = new QImage(datacpy,w,h,bytesperline,QImage::Format_RGB888);
	return out;
}

QImage* Erosion::process()
{
	unsigned char* data = mp_img->bits();
	int bytesperline = mp_img->bytesPerLine();
	unsigned char* datacpy = new unsigned char[bytesperline*h];
	memset(datacpy,0,bytesperline*h*sizeof(char));
	for (int i=0;i!=h;i++)
	{
		for (int j =0;j!=w;j++)
		{
			if(m_se[m_oy][m_ox]!=0)
			{
				unsigned char min = data[i*bytesperline+3*j];
				for (int k=0;k!=m_se.size();k++)
				{
					for (int l=0;l!=m_se[k].size();l++)
					{
						if(m_se[k][l]==1)
						{
							int offseth = k-m_oy;
							int offsetw = l-m_ox;
							if(i-offseth<0||i-offseth>=h||j-offsetw<0||j-offsetw>=w)
								continue;
							if(data[(i-offseth)*bytesperline+3*(j-offsetw)]<=min)
								min = data[(i-offseth)*bytesperline+3*(j-offsetw)];
						}
						else if(m_se[k][l]==0)
						{
							min = 0;
						}
					}
				}
				datacpy[i*bytesperline+j*3]=min;
				datacpy[i*bytesperline+j*3+1]=min;
				datacpy[i*bytesperline+j*3+2]=min;
			}
		}
	}
	QImage* out = new QImage(datacpy,w,h,bytesperline,QImage::Format_RGB888);
	return out;
}

QImage* DistanceTransform::process()
{

	mp_erosion = new Erosion(mp_img);
	int bytesperLine = mp_img->bytesPerLine();
	unsigned char* data = new unsigned char[bytesperLine*h];
	memcpy(data,mp_img->bits(),bytesperLine*h);
	unsigned char* data1 = mp_erosion->process()->bits();
	unsigned char* outdata = new unsigned char[bytesperLine*h];
	memset(outdata,0,bytesperLine*h);
	vector<int> diff_table;
	int count=1;
	while(!compare(data,data1,bytesperLine,diff_table))
	{
		for (int k=0;k!=diff_table.size();k++)
		{
			int i=diff_table[k];
			outdata[i]	=	unsigned char(count);
			outdata[i]	=	unsigned char(count);
			outdata[i]	=	unsigned char(count);
		}
		count++;
		unsigned char* tmp = data;
		data = data1;
		data1 = biterosion(data1,bytesperLine);
		//mp_erosion->SetImage(new QImage(data1,w,h,bytesperLine,QImage::Format_RGB888));
		//data1 = mp_erosion->process()->bits();
		delete []tmp;
		tmp = NULL;
	}
	delete []data1;
	delete []data;
	//gray level scaled
	//find the max distance
	char max = 0;
	for (int i=0;i!=bytesperLine*h;i++)
	{
		if(outdata[i]>=max)
			max = outdata[i];
	}
	//scale gray level
	for (int i=0;i!=bytesperLine*h;i++)
	{
		outdata[i] = char(int(int(outdata[i])*1.0/(int(max))*255));
	}
	return new QImage(outdata,w,h,bytesperLine,QImage::Format_RGB888);
}

inline bool Morphology::compare(const unsigned char* imgdata,const unsigned char* imgdata1,int bytesPerLine,vector<int> &diff_table)const
{
	bool out = true;
	diff_table.clear();
	for (int i=0;i!=h*bytesPerLine;i++)
	{
		if(i%bytesPerLine >= 3*w)
			continue;
		if(imgdata[i] != imgdata1[i])
		{
			diff_table.push_back(i);
			out =false;
		}		
	}
	return out;
}

QImage* Skeleton::process()
{

	int bytesperLine = mp_img->bytesPerLine();

	unsigned char* data = new unsigned char[bytesperLine*h];
	memcpy(data,mp_img->bits(),bytesperLine*h);

	mp_erosion = new Erosion(mp_img);
	unsigned char* data1 = mp_erosion->process()->bits();
	
	unsigned char* outdata = new unsigned char[bytesperLine*h];
	memset(outdata,0,bytesperLine*h);
	vector<int> diff_table;
	int count=1;
	while(!compare(data,data1,bytesperLine,diff_table))
	{
		for (int k=0;k!=diff_table.size();k++)
		{
			int i=diff_table[k];
			outdata[i]	=	unsigned char(count);
			outdata[i]	=	unsigned char(count);
			outdata[i]	=	unsigned char(count);
		}
		count++;
		unsigned char* tmp = data;
		data = data1;
		data1 = biterosion(data1,bytesperLine);
		//mp_erosion->SetImage(new QImage(data1,w,h,bytesperLine,QImage::Format_RGB888));
		//data1 = mp_erosion->process()->bits();
		delete []tmp;
		tmp = NULL;
	}
	delete[] data;
	delete[] data1;
	//label skeleton
	unsigned char* outdata1 = new unsigned char[bytesperLine * h];
	memset(outdata1,0,bytesperLine*h);
	for (int i=1;i!=h-1;i++)
	{
		for (int j=1;j!=w-1;j++)
		{
			if(outdata[i*bytesperLine+j*3]==0||outdata[i*bytesperLine+j*3]==1)
				continue;
			if (outdata[i*bytesperLine+j*3] >= outdata[i*bytesperLine+(j-1)*3]
				&& outdata[i*bytesperLine+j*3] >= outdata[i*bytesperLine + (j+1)*3]
				&& outdata[i*bytesperLine+j*3] >= outdata[(i-1)*bytesperLine+j*3]
				&& outdata[i*bytesperLine+j*3] >= outdata[(i+1)*bytesperLine+j*3]
// 				&& outdata[i*bytesperLine+j*3] >= outdata[(i+1)*bytesperLine+(j+1)*3]
// 				&& outdata[i*bytesperLine+j*3] >= outdata[(i+1)*bytesperLine+(j-1)*3]
// 				&& outdata[i*bytesperLine+j*3] >= outdata[(i-1)*bytesperLine+(j-1)*3]
// 				&& outdata[i*bytesperLine+j*3] >= outdata[(i-1)*bytesperLine+(j+1)*3]
				)
			{
				outdata1[i*bytesperLine+j*3] = 0xFF;
				outdata1[i*bytesperLine+j*3+1] = 0xFF;
				outdata1[i*bytesperLine+j*3+2] = 0xFF;
			}
		}
	}
	delete outdata;
	return new QImage(outdata1,w,h,bytesperLine,QImage::Format_RGB888);
}


QImage* MorphEdgeDect::process()
{
	mp_erosion = new Erosion(mp_img);
	 unsigned char* data1 = mp_img->bits();
	 unsigned char* data2 = mp_erosion->process()->bits();

	//vector<int> diff_table;
	//compare(data1,data2,mp_img->bytesPerLine(),diff_table);
	for (int i=0;i!=h*mp_img->bytesPerLine();i++)
	{
		data2[i] = data1[i] - data2[i];
	}
	return new QImage(data2,w,h,mp_img->bytesPerLine(),QImage::Format_RGB888);
}

QImage* MorphGradient::process()
{
	mp_dilation = new Dilation(mp_img);
	mp_erosion = new Erosion(mp_img);
	unsigned char* data0 = mp_img->bits();
	unsigned char* data1 = mp_erosion->process()->bits();
	unsigned char* data2 = mp_dilation->process()->bits();

	switch(m_GradientType)
	{
	case DEFAULT:
		for (int i=0;i!=h*mp_img->bytesPerLine();i++)
		{
			data2[i] = (data2[i] - data1[i]) / 2;
		}
		break;
	case EXTERNAL:
		for (int i=0;i!=h*mp_img->bytesPerLine();i++)
		{
			data2[i] = (data2[i] - data0[i]) / 2;
		}
		break;
	case  INTERNAL:
		for (int i=0;i!=h*mp_img->bytesPerLine();i++)
		{
			data2[i] = (data0[i] - data2[i]) / 2;
		}
		break;
	defult:
		break;
	}
	delete[] data1;
	return new QImage(data2,w,h,mp_img->bytesPerLine(),QImage::Format_RGB888);
}


QImage* GrayScaleReconstruction::process()
{
	const unsigned char* mask = m_mask->bits();
	int bytesPerLine = mp_img->bytesPerLine();
	vector<int> diff_table;
	unsigned char* data;
	unsigned char* data1;

	mp_dilation = new Dilation(mp_img);

	data = mp_dilation->process()->bits();
	fitmask(mask,data);

	data1 = new unsigned char[h*bytesPerLine];
	memset(data1,0,h*bytesPerLine);
	if(!isStepbyStep)
	{
		do 
		{	
			unsigned char* tmp = data1;
			data1 = data;
			data = bitdilation(data,bytesPerLine);
			//mp_dilation->SetImage(new QImage(data,w,h,bytesPerLine,QImage::Format_RGB888));
			//data = mp_dilation->process()->bits();
			fitmask(mask,data);

			delete []tmp;
			
		} while (!compare(data,data1,bytesPerLine,diff_table));
	}
	delete []data1;


	return new QImage(data,w,h,mp_img->bytesPerLine(),QImage::Format_RGB888);

}

inline void Morphology::fitmask(const unsigned char* mask, unsigned char* data)
{
	int bytesPerLine = mp_img->bytesPerLine();
	for (int i=0;i!=h*bytesPerLine;i++)
	{
		data[i] = data[i]<=mask[i]?data[i]:mask[i];
	}
}


QImage* ConditionalDilation::process()
{
	const unsigned char* mask = m_mask->bits();
	int bytesPerLine = mp_img->bytesPerLine();
	
	unsigned char* data = new unsigned char[h*bytesPerLine];
	unsigned char* data1;
	memset(data,0,h*bytesPerLine);
	//memset(data1,0,h*bytesPerLine);

	for (int i=0;i!=m_seeds.size();i++)
	{
		if(m_seeds[i].size()!=2)
			return NULL;
		
		int x = m_seeds[i][0];
		int y = m_seeds[i][1];


		unsigned char *tmp =  mp_img->bits();
		unsigned char value = tmp[y*bytesPerLine+x*3];
		int r = qRed(mp_img->pixel(x,y));
		data[y*bytesPerLine + x*3] = 0xFF;
		data[y*bytesPerLine + x*3 + 1] = 0xFF;
		data[y*bytesPerLine + x*3 +2] = 0xFF;
	}

	mp_dilation = new Dilation(new QImage(data,w,h,bytesPerLine,QImage::Format_RGB888));
	data = mp_dilation->process()->bits();
	fitmask(mask,data);

	data1 = new unsigned char[h*bytesPerLine];
	memset(data1,0,h*bytesPerLine);
	if(!isStepbyStep)
	{
		vector<int> diff_table;
		do 
		{	
			unsigned char *tmp = data1;
			data1 = data;
			//mp_dilation->SetImage(new QImage(data,w,h,bytesPerLine,QImage::Format_RGB888));
			//data = mp_dilation->process()->bits();
			data = bitdilation(data,bytesPerLine);
			delete []tmp;
			fitmask(mask,data);

		} while (!compare(data,data1,bytesPerLine,diff_table));
		delete data1;
	}
	
	QImage *tmp = new QImage(data,w,h,mp_img->bytesPerLine(),QImage::Format_RGB888);

	QImage *out = new QImage(*mp_img);

	for (int i=0;i!=out->width();i++)
	{
		for (int j=0;j!=out->height();j++)
		{
			if(qRed(tmp->pixel(i,j)) == 255)
			{
				out->setPixel(i,j,qRgb(255,0,0));
			}
		}
	}

	delete data;
	delete tmp;

	return out;

}



unsigned char* Morphology::bitdilation(const unsigned char* img,int bytesperline)
{

	vector<unsigned char*> datalst;
	
	for (int i=0;i!=m_se.size();i++)
	{
		for (int j=0;j!=m_se[i].size();j++)
		{
			if(m_se[i][j] < 0)
				continue;
			unsigned char* datacpy = new unsigned char[bytesperline * h];
			memset(datacpy,0x00,sizeof(char) * bytesperline * h);
			if(m_se[i][j] == 0)
			{
				datalst.push_back(datacpy);
			}
			if(m_se[i][j] == 1)
			{
				int offseth = j - m_ox;	//horizonal shift
				int offsetv = i - m_oy; //vertical shift

				for (int k=0;k!=h;k++)
				{
					if(k+offsetv < 0 || k+offsetv >= h)
					{
						continue;
					}
					if(offseth < 0)
						memcpy(&datacpy[(k+offsetv) * bytesperline],&img[k*bytesperline - offseth*3] ,w*3 + offseth*3);
					else
						memcpy(&datacpy[(k+offsetv) * bytesperline + offseth*3],&img[k*bytesperline] , w*3 - offseth*3);
				}
				datalst.push_back(datacpy);
			}
		}
	}
	
	unsigned char* outdata=new unsigned char[bytesperline*h];
	memset(outdata,0,bytesperline*h);
	for (int i=0;i!=bytesperline*h;i++)
	{
		unsigned char max = 0;
		for (int k=0;k!=datalst.size();k++)
		{
			if(datalst[k][i] > max)
			{
				max = datalst[k][i];
			}
		}
		outdata[i] = max;
	}

	for (vector<unsigned char*>::iterator itr = datalst.begin();itr != datalst.end();++itr)
	{
		delete *itr;
		*itr = NULL;
	}


	return outdata;
}

unsigned char* Morphology::biterosion(const unsigned char* img,int bytesperline)
{
	vector<unsigned char*> datalst;

	for (int i=0;i!=m_se.size();i++)
	{
		for (int j=0;j!=m_se[i].size();j++)
		{
			if(m_se[i][j] < 0)
				continue;
			unsigned char* datacpy = new unsigned char[bytesperline * h];
			memset(datacpy,0x00,sizeof(char) * bytesperline * h);
			if(m_se[i][j] == 0)
			{
				datalst.push_back(datacpy);
			}
			if(m_se[i][j] == 1)
			{
				int offseth = j - m_ox;	//horizonal shift
				int offsetv = i - m_oy; //vertical shift

				for (int k=0;k!=h;k++)
				{
					if(k+offsetv < 0 || k+offsetv >= h)
					{
						continue;
					}
					if(offseth < 0)
						memcpy(&datacpy[(k+offsetv) * bytesperline],&img[k*bytesperline - offseth*3] ,w*3 + offseth*3);
					else
						memcpy(&datacpy[(k+offsetv) * bytesperline + offseth*3],&img[k*bytesperline] , w*3 - offseth*3);
				}
				datalst.push_back(datacpy);
			}
		}
	}

	unsigned char* outdata=new unsigned char[bytesperline*h];
	memset(outdata,0,bytesperline*h);
	for (int i=0;i!=bytesperline*h;i++)
	{
		unsigned char min = datalst[0][i];
		for (int k=1;k!=datalst.size();k++)
		{
			if(datalst[k][i] < min)
			{
				min = datalst[k][i];
			}
		}
		outdata[i] = min;
	}

	for (vector<unsigned char*>::iterator itr = datalst.begin();itr != datalst.end();++itr)
	{
		delete *itr;
		*itr = NULL;
	}

	return outdata;
}