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
	cout << "Items sampled from each set: " << setw(22) << right << testSet.GetSampleSize() << endl;

	cout << "Operations complete." << endl;

	return 0;
}
