#pragma once

#include "Processer.h"

namespace IPFbyCJY
{
	typedef vector<vector<int>> SE;
	
	class Morphology:public Processer
	{
		
	public:
		enum BASIC_SE
		{CROSS_SE,
		//0 1 0
		//1 1 1
		//0 1 0
		VER_SE,
		//1 1 1
		HON_SE
		//1
		//1
		//1
		};
		SE m_se;// structure element
		int m_se_sizex; // size of horizon
		int m_se_sizey; // size of vertical
		int m_ox; //origin x
		int m_oy; //origin y

		Morphology(QImage *img,SE se,int x,int y):Processer(img),m_se(se),m_ox(x),m_oy(y)
		{
			if(se.size()!=0)
			{
				m_se_sizex = se[0].size();
				m_se_sizey = se.size();
			}
		}
		Morphology(QImage *img,BASIC_SE se=CROSS_SE):Processer(img)
		{
			switch(se)
			{
			case CROSS_SE:
				m_se.resize(3);
				m_se[0].push_back(-1);
				m_se[0].push_back(1);
				m_se[0].push_back(-1);
				m_se[1].push_back(1);
				m_se[1].push_back(1);
				m_se[1].push_back(1);
				m_se[2].push_back(-1);
				m_se[2].push_back(1);
				m_se[2].push_back(-1);
				m_ox = 1;
				m_oy = 1;
				m_se_sizex=3;
				m_se_sizey=3;
				break;
			case VER_SE:
				m_se.resize(3);
				m_se[0].push_back(1);
				m_se[1].push_back(1);
				m_se[2].push_back(1);
				m_ox = 0;
				m_oy = 1;
				m_se_sizex=1;
				m_se_sizey=3;
				break;
			case HON_SE:
				m_se.resize(1);
				m_se[0].push_back(1);
				m_se[0].push_back(1);
				m_se[0].push_back(1);
				m_ox=1;
				m_oy=0;
				m_se_sizex=3;
				m_se_sizey=1;
				break;
			default:
				break;
			}
		}
		virtual QImage* process()=0;

		void GetOffset(int &minx,int &maxx,int &miny,int &maxy)
		{
			minx = 0 - m_ox;
			maxx = m_se_sizex - m_ox-1;
			miny = 0 - m_oy;
			maxy = m_se_sizey - m_oy - 1;
		}
	
		inline SE getSE(){return m_se;}

	protected:
		inline bool compare(const unsigned char* imgdata,const unsigned char* imgdata1,int bytesPerLine,vector<int> &diff_table)const;
		inline void fitmask(const unsigned char* mask, unsigned char* data);

	public:
		unsigned char* bitdilation(const unsigned char* img,int bytesperline);
		unsigned char* biterosion(const unsigned char* img,int bytesperline);
	};
	class Dilation:public Morphology
	{
	public:
		Dilation(QImage* img,SE se,int x ,int y):Morphology(img,se,x,y)
		{		
		}
		Dilation(QImage* img,BASIC_SE se=CROSS_SE):Morphology(img,se)
		{
		}
		~Dilation(){}
		QImage* process();
	};

	class Erosion:public Morphology
	{
	public:
		Erosion(QImage *img,SE se,int x ,int y):Morphology(img,se,x,y)
		{
		}
		Erosion(QImage* img,BASIC_SE se=CROSS_SE):Morphology(img,se)
		{
		}
		~Erosion(){}
		QImage* process();
	};

	class Open:public Morphology
	{
	public:
		Open(QImage *img,SE se,int x, int y):Morphology(img,se,x,y)
		{}
		Open(QImage *img,BASIC_SE se = CROSS_SE):Morphology(img,se){}
		~Open()
		{
			if(mp_erosion!=NULL)
				delete mp_erosion;
			if(mp_dilation != NULL)
				delete mp_dilation;
		}
		QImage* process()
		{
			mp_erosion = new Erosion(mp_img,m_se,m_ox,m_oy);
			mp_dilation= new Dilation(mp_erosion->process(),m_se,m_ox,m_oy);
			return mp_dilation->process();
		}
	private:
		Erosion		*mp_erosion;
		Dilation	*mp_dilation;
	};

	class Close:public Morphology
	{
	public: 
		Close(QImage *img, SE se, int x, int y):Morphology(img,se,x,y){}
		Close(QImage* img,BASIC_SE se = CROSS_SE):Morphology(img,se){}
		~Close()
		{
			if(mp_erosion!=NULL)
				delete mp_erosion;
			if(mp_dilation != NULL)
				delete mp_dilation;
		}
		QImage* process()
		{
			mp_dilation = new Dilation(mp_img,m_se,m_ox,m_oy);
			mp_erosion = new Erosion(mp_dilation->process(),m_se,m_ox,m_oy);
			return mp_erosion->process();
		}
	private:
		Erosion		*mp_erosion;
		Dilation	*mp_dilation;
	};

	class DistanceTransform:public Morphology
	{
	public:
		DistanceTransform(QImage* img,SE se,int x,int y):Morphology(img,se,x,y){}
		DistanceTransform(QImage* img ,BASIC_SE se=CROSS_SE):Morphology(img,se){}
		~DistanceTransform()
		{
			if(mp_erosion!=NULL)
				delete mp_erosion;
		}

		QImage* process();

	
	private:
		Erosion* mp_erosion;
	};

	class Skeleton:public Morphology
	{
	public:
		Skeleton(QImage* img,SE se,int x,int y):Morphology(img,se,x,y){}
		Skeleton(QImage* img,BASIC_SE se = CROSS_SE):Morphology(img,se){}
		~Skeleton()
		{
			if (mp_erosion!=NULL)
			{
				delete mp_erosion;
			}
		}
		QImage* process();
	private:
		Erosion* mp_erosion;
	};


	class MorphEdgeDect:public Morphology
	{
	public:
		MorphEdgeDect(QImage* img,BASIC_SE se = CROSS_SE):Morphology(img,se){}
		MorphEdgeDect(QImage* img,SE se,int x, int y):Morphology(img,se,x,y){}
		~MorphEdgeDect()
		{
			if(mp_erosion!=NULL)
				delete mp_erosion;
		}
		QImage* process();

	private:
		Erosion* mp_erosion;
	};


	class MorphGradient:public Morphology
	{
	public:
		enum GradientType{DEFAULT,EXTERNAL,INTERNAL};
		MorphGradient(QImage* img,GradientType gt = DEFAULT,BASIC_SE se=CROSS_SE):Morphology(img,se),m_GradientType(gt){}
		MorphGradient(QImage* img,SE se,int x,int y,GradientType gt = DEFAULT):Morphology(img,se,x,y),m_GradientType(gt){}
		~MorphGradient()
		{
			if(mp_erosion!=NULL)
				delete mp_erosion;
			if(mp_dilation!=NULL)
				delete mp_dilation;
		}
		QImage* process();
	private:
		Erosion* mp_erosion;
		Dilation* mp_dilation;

		GradientType m_GradientType;
	};


	class GrayScaleReconstruction:public Morphology
	{
	public:
		GrayScaleReconstruction(QImage* img,QImage* mask,bool step=false,BASIC_SE se = CROSS_SE):Morphology(img,se),m_mask(mask),isStepbyStep(step){}
		~GrayScaleReconstruction()
		{
			if(mp_dilation != NULL)
				delete  mp_dilation;
		}

		QImage* process();

	protected:
	
	private:
		Dilation* mp_dilation;
		QImage* m_mask;
		bool isStepbyStep;
	};

	class ConditionalDilation:public Morphology
	{
	public:
		ConditionalDilation(QImage* img,QImage* mask,vector<vector<int>> seeds,bool step = false,BASIC_SE se = CROSS_SE):Morphology(img,se),m_mask(mask),isStepbyStep(step),m_seeds(seeds){}
		~ConditionalDilation()
		{
			if(mp_dilation != NULL)
				delete mp_dilation;
		}

		QImage* process();

	private:
		Dilation* mp_dilation;
		QImage* m_mask;
		bool isStepbyStep;

		vector<vector<int>> m_seeds;
	};
}
