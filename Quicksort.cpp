// Author: Shaun Robinson
// Program: Quicksort

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

void quicksort(int arr[], int size);
void quicksort(int arr[], int begin, int end);
int partition(int arr[], int begin, int pivot, int end);

int main() {
	int *arr, size;
	
	cout << "Enter a size for your array: ";
	cin >> size;

	arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 1000 + 1;
		cout << arr[i] << " ";
	}
	cout << endl;
	quicksort(arr, size);
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}
void quicksort(int arr[], int size) {
	quicksort(arr, 0, size - 1);
}
void quicksort(int arr[], int begin, int end) {
	if (begin >= end) {
		return;
	}
	int pivot = arr[(begin + end) / 2];            // pivot is chosen as center of array
	int index = partition(arr, begin, pivot, end); // index will "split" array according how far begin index travels
	quicksort(arr, begin, index - 1);              // first half of array
	quicksort(arr, index, end);                    // second half of array

}
int partition(int arr[], int begin, int pivot, int end) {
	while (begin <= end) {
		while (arr[begin] < pivot) { // finds int larger than pivot
			begin++;                 
		}
		while (arr[end] > pivot) {  // finds int smaller than pivot
			end--;
		}
		if (begin <= end) {         // swaps if called for
			int temp = arr[begin];
			arr[begin] = arr[end];
			arr[end] = temp;
			end--;
			begin++;
		}
	}

	return begin;                  // returns the partition point of the array
}
