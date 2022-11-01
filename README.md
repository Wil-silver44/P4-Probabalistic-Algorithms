# P4-Probabalistic-Algorithms
## Project Description

The goals of this project are to:

- implement a probabilistic algorithm

- observe how expected results compare to observed results
- Develop and test a program that implements the bad microchip problem.

The idea is that some batches of micro-chips might not be tested, and the goal is to detect bad batches without testing all the chips in the batch. We will be simulating the process of sampling chips from a collection of batches of chips.

### Part A: Generate data sets.

Automate creation of what would otherwise be a user-specified number of datasets with a user-specified number of batches, batch size, percentage of the datasets containing bad chips, and percentage of bad chips in a dataset.

When the program runs, it will automatically read four (4) test files titled t1.txt, t2.txt, t3.txt, and t4.txt, simulating how the program would work if it were getting these parameters interactively from the user. These configuration files should have the following values written as integers, one per row:
![image](https://user-images.githubusercontent.com/89366767/199325356-23b178dd-1cc6-4554-aa96-a6e827ea421b.png)
Generate a dataset from the input specification. The dataset will contain an individual file for each batch of items. Save each file in the dataset as ds1.txt,  ds2.txt, ..., dsn.txt. To create an individual file, decide if it has bad items or not. Run a loop for the number of items in the batch. If it is a good batch, just write 'g' to the file (one per line) for the total number of items in the batch. If it is a bad batch, use a random number generator for the input-specified percentage of bad chips: Example - assume the spec is that 10% of chips are bad. Generate datasets by generating random numbers on [0..99] if 0 .. 9 comes up, add a bad chip (write the char 'b' to the file), otherwise, add a good chip to the data set (write a 'g' to the file).

 

Part B: Implement the Monte Carlo algorithm to determine which of the chip batches are bad. It should know how many data sets there are, read them one at a time, sample the appropriate number of items, and report good batch or bad batch. Your output should look like the output below.


Example output:
```
Simulation #1
     Number of batches of items:                      200
     Number of items in each batch:                  1000
     Percentage of batches containing bad items:       25
     Percentage of items that are bad in a bad set:    15
     Items sampled from each set:                      50

Generating data sets:
     Total bad sets = 50
     Max number of bad items in a bad set = 173
     Min number of bad items in the bad set  = 118
     Average number of bad items in a bad set  = 149.100000

Analyzing Data Sets
     Base = 0.850000 exponent = 50
     P(failure to detect bad item) = 0.000296
     P(batch is good) = 0.999704
     Percentage of bad batches detected =  98

Simulation #2
   Number of batches of items:                        200
   Number of items in each batch                     1000
   Percentage of batches containing bad items          10%
   Percentage of items that are bad in a bad set       10%
   Items sampled from each set                         40

. . .
```
## Inputs and Outputs

When your program runs, it will first automatically generate the data sets, carry out the simulation, and report results. NO user interaction should be needed. ALL results will go to the console.

Deliverables

You will submit the following for this project: 
1. A UML diagram
2. A User's manual that describes how to set up and run your program.
3. Your source code in C++.
4. t1.txt, t2.txt, t3.txt, t4.txt
5. A makefile for the project
