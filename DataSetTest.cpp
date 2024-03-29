#include <iostream>
#include <iomanip>
#include "DataSet.hpp"

using namespace std;

int main()
{
	cout << "creating dataset class object." << endl;
	DataSet testSet;
	
	cout << "reading test file 1." << endl;
	testSet.Generate("t1.txt");

	cout << "read data:" << endl;
	cout << "Number of batches of items:" << setw(25) << right << testSet.GetNumBatches() << endl;
	cout << "Number of items in each batch:" << setw(23) << right << testSet.GetNumItems()  << endl;
	cout << "Percentage of batches containing bad items:" << setw(8) << right << testSet.GetPContainsBad() << "%" << endl;
	cout << "Percentage of items that are bad in a bad set:" << setw(5) << right << testSet.GetPBadInSet() << "%" << endl;
	cout << "Items sampled from each set: " << setw(22) << right << testSet.GetSampleSize() << endl << endl;

	cout << "Generating data sets:" << endl;
	cout << setw(5) << right << "Total bad sets = " << testSet.GetNumBadSets() << endl;
	cout << setw(5) << right << "Max number of bad items in a bad set = " << testSet.GetMaxBadItems() << endl;
	cout << setw(5) << right << "Min number of bad items in a bad set = " << testSet.GetMinBadItems() << endl;
	cout << setw(5) << right << "Average number of bad items in a bad set  = " << testSet.GetAvgBadItems() << endl;
	
	cout << "Operations complete." << endl;

	return 0;
}
