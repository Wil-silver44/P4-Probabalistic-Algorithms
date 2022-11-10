#include "DataSet.hpp"

/***************************************************************
 *   Student Name: Wilver Santos
 *   File Name: DataSet.hpp
 *   Assignment number: Project 4
 *
 *   Other comments regarding the file - implements the attributes and methods used to generate datasets containing information batches
 *   of microchips.
 *
 ***************************************************************/

DataSet::DataSet()
{
	this->maxBadItems = 0;
	this->minBadItems = 0;
	this->avgBadItems = 0.00;
}

void DataSet::Generate(string sourceFileName)
{
	int numHolder = 0;

	this->fileRead.open(sourceFileName);

	fileRead >> numHolder;

	SetNumBatches(numHolder);

	fileRead >> numHolder;

	SetNumItems(numHolder);

	fileRead >> numHolder;

	SetPContainsBad(numHolder);

	fileRead >> numHolder;

	SetPBadInSet(numHolder);

	fileRead >> numHolder;

	SetSampleSize(numHolder);

	this->fileRead.close();
}

void DataSet::SetNumBatches(int someNum)
{ this->numBatches = someNum; }

void DataSet::SetNumItems(int someNum)
{ this->numItemsPerBatch = someNum; }

void DataSet::SetPContainsBad(int someNum)
{ this->pContainsBad = someNum;  }

void DataSet::SetPBadInSet(int someNum)
{ this->pBadInSet = someNum; }

void DataSet::SetSampleSize(int someNum)
{ this->sampleSize = someNum; }

int DataSet::GetNumBatches()
{ return this->numBatches; }

int DataSet::GetNumItems()
{ return this->numItemsPerBatch; }

int DataSet::GetPContainsBad()
{ return this->pContainsBad; }

int DataSet::GetPBadInSet()
{ return this->pBadInSet; }

int DataSet::GetSampleSize()
{ return this->sampleSize; }

int DataSet::GetNumBadSets()
{ return this->numBadSets; }

int DataSet::GetMaxBadItems()
{ return this->maxBadItems; }

int DataSet::GetMinBadItems()
{ return this->minBadItems; }

double DataSet::GetAvgBadItems()
{
	double someNum = 0;
	return someNum;
}
