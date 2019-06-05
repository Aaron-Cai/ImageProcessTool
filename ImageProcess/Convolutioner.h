#pragma once

#include "Processer.h"


namespace IPFbyCJY
{
	const  float PI = 3.1415926;
	const  float e = 3.71828;
	class Convolutioner:public Processer
	{
	public:
		Convolutioner(QImage *img);

		mat getKernal()
		{
			return kernal;
		}
		void setKernel(mat k);

		virtual	~Convolutioner();

		virtual QImage* process()=0;

	protected:
		//QImage *mp_img;
		mat kernal;
		mat inverse_kernal;

		//inline int conv(const mat &a,const mat &b)const;

		//inline mat GetNeighbour(int x,int y,int s,const mat &m, int w, int h);
// 		int w;
// 		int h;
	};



	class CunstomCon:public Convolutioner
	{
	public:
		CunstomCon(QImage *img = NULL);
		~CunstomCon();

		

		QImage* process();
	};

	class EdgeDector:public Convolutioner
	{
	public:
		EdgeDector(QImage* img = NULL):Convolutioner(img){}
		virtual ~EdgeDector(){}
		virtual QImage* process();
	protected:
		void InverseKernel()
		{
			int size = kernal.size();
			inverse_kernal.resize(size);
			inverse_kernal1.resize(size);
			for (int i=0;i!=size;i++)
			{
				inverse_kernal[i].resize(size);
				inverse_kernal1[i].resize(size);
				for (int j=0;j!=size;j++)
				{
					inverse_kernal[i][j] = kernal[size-1-i][size-1-j];
					inverse_kernal1[i][j] = kernal1[size-1-i][size-1-j];
				}
			}
		}
		mat kernal1;
		mat inverse_kernal1;
	};

	class Filter:public Convolutioner
	{
	public:
		Filter(QImage* img = NULL,int size = 3):Convolutioner(img),m_size(size){}
		virtual ~Filter(){}
		virtual QImage* process();
	protected: 
		void InverseKernel()
		{
			inverse_kernal.resize(m_size);
			for (int i=0;i!=m_size;i++)
			{
				inverse_kernal[i].resize(m_size);
				for (int j=0;j!=m_size;j++)
				{
					inverse_kernal[i][j] = kernal[m_size-1-i][m_size-1-j];
				}
			}
		}
		int m_size;
	
	};

	class GaussianFilter:public Filter
	{
	public:
		GaussianFilter(QImage* img = NULL, int size = 3,float the = 1);
		virtual ~GaussianFilter(){}
	private: 
		float theta;
		//virtual QImage* process();	
	};
	class MeanFilter:public Filter
	{
	public:
		MeanFilter(QImage* img = NULL,int size = 3);
		virtual ~MeanFilter(){}
		//virtual QImage* process();
	};
	class MedianFilter:public Filter
	{
	public:
		MedianFilter(QImage* img=NULL,int size = 3);
		virtual ~MedianFilter(){}
		virtual QImage* process();
	};

	class Sobel:public EdgeDector
	{
	public:
		Sobel(QImage *img = NULL);
		~Sobel();
	};


	class Prewitt:public EdgeDector
	{
	public:
		Prewitt(QImage* img=NULL);
		~Prewitt();
	};
}
