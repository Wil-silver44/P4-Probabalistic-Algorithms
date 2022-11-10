CXX = g++

# compiler flags:
# -g adds debugging information to the executeable file.
#  -wall turns on most, but not all, compiler warnings.
#

CXXFLAGS = -g -Wall

OBJECTS = DataSet.o QASim.o AnalyticalModel.o

main: main.cpp $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

DataSetTest: DataSetTest.cpp DataSet.o
	 $(CXX) $(CXXFLAGS) -o $@ $^


clean:
	rm -rf *.dSYM
	$(RM) *.o *.gc main DataSetTest
