//header file for sorting program//
#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <ctime>
using namespace std;

class sorting{
	public:
		sorting(string file);
		~sorting();

		void run(string file); //run the program

		void quicksort();
		void mergesort();
		void selectionsort();
		void insertionsort();
		void bubblesort();
	private:
		int asize = -1; //array size

		double* qarray; //quick sort array
		double* marray; //merge sort array
		double* sarray; //seceltion sort array
		double* iarray; //insertion sort array
		double* barray; //bubble sort array

		//quick sort functions
		void quicksortfunc(double* arr, int l, int r);
		int partition(double *a, int l, int r);

		//merge sort functions
		void mergesortfunc(double* ar, int l, int r);
		void merges(double *array, int l, int m, int r);

		void read(string f); //read the list from file
};
