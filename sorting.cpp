//sorting implementation file//
#include "sorting.h"
using namespace std;

//constructor//
sorting::sorting(string file){
	read(file);
}

//destructor//
sorting::~sorting(){
	delete[] qarray;
	delete[] marray;
	delete[] sarray;
	delete[] iarray;
	delete[] barray;
}

//SORTS//
void sorting::quicksort(){
	clock_t start = clock();

	quicksortfunc(qarray, 0, asize-1);

	clock_t end = clock();
	float duration = (float(end - start)/(CLOCKS_PER_SEC))*1000;
	cout << "Start time: " << start << endl;
	cout << "End time: " << end << endl;
	cout << "Duration time: " << duration << endl;
}

void sorting::mergesort(){
	clock_t start = clock();

	mergesortfunc(marray, 0, asize-1);

	clock_t end = clock();
	float duration = (float(end - start)/(CLOCKS_PER_SEC))*1000;
	cout << "Start time: " << start << endl;
	cout << "End time: " << end << endl;
	cout << "Duration time: " << duration << endl;
}

void sorting::selectionsort(){
	clock_t start = clock();

	int min;
	for(int i = 0; i < asize; i++){
		min = i;
		for(int j = i+1; j < asize+1; j++){
			if (sarray[j] < sarray[min]){
				min = j;
			}
		}
		double temp = sarray[min];
		sarray[min] = sarray[i];
		sarray[i] = temp;
	}

	clock_t end = clock();
	float duration = (float(end - start)/(CLOCKS_PER_SEC))*1000;
	cout << "Start time: " << start << endl;
	cout << "End time: " << end << endl;
	cout << "Duration time: " << duration << endl;
}

void sorting::insertionsort(){
	clock_t start = clock();

	for (int j = 1; j < asize; j++){
		double temp = iarray[j];
		int k = j-1;
		while (k >= 0 && iarray[k] > temp){
			iarray[k+1] = iarray[k];
			k--;
		}
		iarray[k+1] = temp;
	}

	clock_t end = clock();
	float duration = (float(end - start)/(CLOCKS_PER_SEC))*1000;
	cout << "Start time: " << start << endl;
	cout << "End time: " << end << endl;
	cout << "Duration time: " << duration << endl;
}

void sorting::bubblesort(){
	clock_t start = clock();

	for(int i = 0; i < asize-1; i++){
		for(int j = 0; j < asize-i-1; j++){
			if (barray[j] > barray[j+1]){
				swap(barray[j], barray[j+1]);
			}
		}
	}

	clock_t end = clock();
	float duration = (float(end - start)/(CLOCKS_PER_SEC))*1000;
	cout << "Start time: " << start << endl;
	cout << "End time: " << end << endl;
	cout << "Duration time: " << duration << endl;
}

//QUICK SORT FUNCTIONS//
void sorting::quicksortfunc(double* arr, int l, int r){
	if (l < r){
  	int part = partition(arr, l, r);
		quicksortfunc(arr, l, part - 1);
  	quicksortfunc(arr, part + 1, r);
	}
}

int sorting::partition(double *arr, int l, int r){
	int pivot = arr[r];
  int p = (l - 1);
  for (int j = l; j <= r - 1; j++){
    if (arr[j] <= pivot){
    	p++;
      swap(arr[p], arr[j]);
    }
  }
  swap(arr[p + 1], arr[r]);
  return (p + 1);
}

//MERGE SORT FUNCTIONS//
void sorting::merges(double* array, int l, int m, int r){
  int leftsize = m-l+1;
  int rightsize = r-m;
  double left[leftsize];
	double right[rightsize];
	for(int i = 0; i < leftsize; i++){ //left
		left[i] = array[l+i];
	}
	for(int j = 0; j < rightsize; j++){ //right
		right[j] = array[m+1+j];
	}
	int i = 0;
	int j = 0;
	int k = l;
	while(i < leftsize && j < rightsize) {
		if(left[i] <= right[j]){
			array[k] = left[i++];
		}
		else{
			array[k] = right[j++];
		}
		k++;
	}
	while(i < leftsize){
		array[k++] = left[i++];
	}
	while(j < rightsize){
		array[k++] = right[j++];
	}
}

void sorting::mergesortfunc(double* ar, int l, int r){
	if(l < r){
  	int m = (l+r-1)/2;
  	mergesortfunc(ar,l,m);
  	mergesortfunc(ar,m+1,r);
  	merges(ar,l,m,r);
	}
}

//ETC//
void sorting::read(string file){
	ifstream instream;
	instream.open(file);
	if (instream.fail()){
		cerr << "ERROR: UNABLE TO OPEN FILE" << endl;
		instream.close();
		exit(1);
	}

	double curr;
	int count = 0; //line count
	while (instream >> curr){
		if (count == 0){
			asize = curr;
			qarray = new double[asize]; //quick sort array
			marray = new double[asize]; //merge sort array
			sarray = new double[asize]; //selection sort array
			iarray = new double[asize]; //insertion sort array
			barray = new double[asize]; //bubble sort array
		}
		else{
			if (count > asize){
				break;
			}
			else{ //adding numbers to array
				qarray[count-1] = curr;
				marray[count-1] = curr;
				sarray[count-1] = curr;
				iarray[count-1] = curr;
				barray[count-1] = curr;
			}
		}
		count++;
	}
	instream.close();
}

void sorting::run(string file){
	read(file);

	cout << "Sorting through quick sort..." << endl;
	quicksort();
	cout << endl;

	cout << "Sorting through merge sort..." << endl;
	mergesort();
	cout << endl;

	cout << "Sorting through selection sort..." << endl;
	selectionsort();
	cout << endl;

	cout << "Sorting through insertion sort..." << endl;
	insertionsort();
	cout << endl;

	cout << "Sorting through bubble sort..." << endl;
	bubblesort();
	cout << endl;

	cout << "------------------------" << endl;
	cout << "Sorting complete." << endl;
	cout << endl;

}
