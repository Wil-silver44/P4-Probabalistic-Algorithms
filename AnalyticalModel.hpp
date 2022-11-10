#ifndef ANALYTICALMODEL_HPP
#define ANALYTICALMODEL_HPP
#include <math.h>

/***************************************************************
 *   Student Name: Wilver Santos
 *   File Name: AnalyticalModel.hpp
 *   Assignment number: Project 4
 *
 *   Other comments regarding the file - implements the attributes and methods used to calculate the Probabilites
 *   of failing and succeeding to detect
 *   bad batches
 *
 ***************************************************************/

using std::pow;

class AnalyticalModel
{
	private:
	int pContainsBad;
	int pBadInSet;
	int sampleSize;
	double base;
	public:
	AnalyticalModel(int someSampleSize, int somePContainsBad, int somePBadInSet);
	double CalcProbFailedToDetect();
	double CalcProbBatchIsGood();
	double CalcPBadDetected();
	double GetBase();
};

#endif
