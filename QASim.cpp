#include "QASim.hpp"

/***************************************************************
 *   Student Name: Wilver Santos
 *   File Name: QASim.cpp
 *   Assignment number: Project 4
 *
 *   Other comments regarding the file - implements the attributes and methods used to run
 *   the chipset problem simulation.
 *
 ***************************************************************/

void QASim::RunFullSim()
{
	RunSim(1, SOURCENAME_ONE);
	RunSim(2, SOURCENAME_TWO);
	RunSim(3, SOURCENAME_THREE);
	RunSim(4, SOURCENAME_FOUR);
}

void QASim::RunSim(int simNum, string testFile)
{
	this->chipDataSets.Generate(testFile);
	AnalyticalModel testModel(this->chipDataSets.GetSampleSize(), this->chipDataSets.GetPContainsBad(), this->chipDataSets.GetPBadInSet());

	cout << setw(5) << right << "Simulation #" << simNum << endl;
	cout << setw(5) << right << "Number of batches of items:" << setw(25) << right <<  this->chipDataSets.GetNumBatches() << endl;
	cout << setw(5) << right << "Number of items in each batch:" << setw(22) << right <<  this->chipDataSets.GetNumItems()  << endl;
	cout << setw(5) << right << "Percentage of batches containing bad items:" << setw(8) << right <<  this->chipDataSets.GetPContainsBad() << "%" << endl;
	cout << setw(5) << right << "Percentage of items that are bad in a bad set:" << setw(5) << right <<  this->chipDataSets.GetPBadInSet() << "%" << endl;
	cout << setw(5) << right << "Items sampled from each set:" << setw(23) << right <<  this->chipDataSets.GetSampleSize() << endl << endl;

	cout << "Generating data sets:" << endl;
	cout << setw(5) << right << "Total bad sets = " <<  this->chipDataSets.GetNumBadSets() << endl;
	cout << setw(5) << right << "Max number of bad items in a bad set = " <<  this->chipDataSets.GetMaxBadItems() << endl;
	cout << setw(5) << right << "Min number of bad items in a bad set = " <<  this->chipDataSets.GetMinBadItems() << endl;
	cout << setw(5) << right << "Average number of bad items in a bad set  = " <<  this->chipDataSets.GetAvgBadItems() << endl << endl;

	cout << "Analyzing Data Sets" << endl;
	cout << setw(5) << right << "Base = " << testModel.GetBase()  << " Exponent = " << this->chipDataSets.GetSampleSize() << endl;
	cout << setw(5) << right << "P(failure to detect bad item) = " << testModel.CalcProbFailedToDetect() << endl;
        cout << setw(5) << right << "P(batch is good) = " << testModel.CalcProbBatchIsGood() << endl;
	cout << setw(5) << right << "Percentage of bad batches detected = " << testModel.CalcPBadDetected() << endl << endl;
}
