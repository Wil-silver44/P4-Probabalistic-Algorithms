#include "AnalyticalModel.hpp"

/***************************************************************
 *   Student Name: Wilver Santos
 *   File Name: AnalyticalModel.cpp
 *   Assignment number: Project 4
 *
 *   Other comments regarding the file - implements methods and attributes defined in AnalyticalModel.hpp
 *
 ***************************************************************/

AnalyticalModel::AnalyticalModel(int someSampleSize, int somePContainsBad, int somePBadInSet)
{
	this->pContainsBad = somePContainsBad;
	this->pBadInSet = somePBadInSet;
	this->sampleSize = someSampleSize;
	this->base = (1.00 - (this->pBadInSet / 100.0));
}

double AnalyticalModel::CalcProbFailedToDetect()
{ return (1.00 - CalcProbBatchIsGood()); }

double AnalyticalModel::CalcProbBatchIsGood()
{
	double exponent = this->sampleSize * 1.0;
	return pow(this->base, exponent);
}

double AnalyticalModel::CalcPBadDetected()
{
	return ((CalcProbFailedToDetect() - CalcProbBatchIsGood()) * 100);
}

double AnalyticalModel::GetBase()
{ return this->base; }
