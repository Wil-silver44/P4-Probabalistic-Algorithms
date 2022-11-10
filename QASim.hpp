#ifndef QASIM_HPP
#define QASIM_HPP
#include <iostream>
#include <iomanip>
#include "DataSet.hpp"
#include "AnalyticalModel.hpp"

/***************************************************************
 *   Student Name: Wilver Santos
 *   File Name: QASim.hpp
 *   Assignment number: Project 4
 *
 *   Other comments regarding the file - defines the attributes and methods used to run
 *   the chipset problem simulation.
 *
 ***************************************************************/

using std::cout;
using std::endl;
using std::setw;
using std::right;

class QASim
{
	private:
	const string SOURCENAME_ONE = "t1.txt";
	const string SOURCENAME_TWO = "t2.txt";
	const string SOURCENAME_THREE = "t3.txt";
	const string SOURCENAME_FOUR = "t4.txt";
	DataSet chipDataSets;

	public:
	void RunFullSim();
	void RunSim(int simNum, string testFile);
};

#endif
