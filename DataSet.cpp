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

void DataSet::Generate(string sourceFileName)
{
	std::random_device rand; //generates seed for random num generator
	std::mt19937 gen(rand()); //Standard mersenne twister engine seeded with the above random device.
	std::uniform_int_distribution<> distribute(0, 99);
	//generates random ints uniformly distributed along a closed range.	

	this->maxBadItems = 0;
        this->minBadItems = 0;
        this->numBadSets = 0;
	this->avgBadItems = 0.00;

	//opens dataset paramater file
	this->fileRead.open(sourceFileName);
	
	int numHolder = 0;

	//reads all paramater data
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
	
	//tracks total number of bad items across all batches.
	int totBadItems = 0;

	//generates batch files.
	for(int i = 1; i <= GetNumBatches(); ++i)
	{
		string helper = "batchHolder/ds" + std::to_string(i) + ".txt";
		this->fileWrite.open(helper);
		
		//determine if bach is bad
		numHolder = distribute(gen);
		//generates bad batch
		if(numHolder < GetPContainsBad())
		{
			int badItemHelper = 0;
			this->numBadSets++;

			for(int j = 0; j < GetNumItems(); ++j)
			{
				numHolder =  distribute(gen);
				//write bad item
				if(numHolder < GetPBadInSet())
				{
					this->fileWrite << 'b' << std::endl;
					badItemHelper++;
					totBadItems++;
				}
				//write good item
				else
				{
					this->fileWrite << 'g' << std::endl;
						
				}
			}

			if(i == 1)
			{
				this->maxBadItems = badItemHelper;
				this->minBadItems = badItemHelper;
			}
			else
			{
				if(this->maxBadItems < badItemHelper)
				{ this->maxBadItems = badItemHelper; }

				if(this->minBadItems > badItemHelper)
				{ this->minBadItems = badItemHelper; }
			}
		}
		
		//generates good batch
		else
		{
			for(int i = 0; i < GetNumItems(); ++i)
			{
				this->fileWrite << 'g' << std::endl;
			}
		}
		
		this->fileWrite.close();
	}
	
	//batches written, calc avg bad items
	this->avgBadItems = (totBadItems / (GetNumBadSets() * 1.0) );
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
{ return this->avgBadItems; }
