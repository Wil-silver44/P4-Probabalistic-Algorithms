#ifndef DATASET_HPP
#define DATASET_HPP
#include <fstream>
#include <string>
#include <random>

/***************************************************************
 *   Student Name: Wilver Santos
 *   File Name: DataSet.hpp
 *   Assignment number: Project 4
 *
 *   Other comments regarding the file - defines the attributes and methods used to generate datasets containing information batches
 *   of microchips. 
 *
 ***************************************************************/

using std::ifstream;
using std::ofstream;
using std::string;

class DataSet
{
	private:
		int numBatches;
		int numItemsPerBatch;
		int pContainsBad;	//p is abbreviation for "percent."
		int pBadInSet;
		int sampleSize;
		int numBadSets;
		int maxBadItems;
		int minBadItems;
		double avgBadItems;
		ifstream fileRead;
		ofstream fileWrite;

	public:
		void Generate(string sourceFileName);
		void SetNumBatches(int someNum);
		void SetNumItems(int someNum);
		void SetPContainsBad(int someNum);
		void SetPBadInSet(int someNum);
		void SetSampleSize(int someNum);
		int GetNumBatches();
		int GetNumItems();
		int GetPContainsBad();
		int GetPBadInSet();
		int GetSampleSize();
		int GetNumBadSets();
		int GetMaxBadItems();
		int GetMinBadItems();
		double GetAvgBadItems();
};

#endif
