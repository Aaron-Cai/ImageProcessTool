#pragma once

#include <QImage>
#include <vector>
#include <assert.h>
using namespace std;

namespace IPFbyCJY
{
	QImage* rgb2gray(QImage* img);


	int otsuMethod(vector<int> hist);
	int entropyMethod(vector<int> hist);


	//void convolution();
}