// Author: Shaun Robinson
// Program: Count Inversions 

#include<iostream>
#include<ctime>
using namespace std;

void insert_sort(int arr[], int size);

int main() {
	int *arr, size;
	
	cout << "Insert sort for an array" << endl;
	cout << "Please enter a size for your array: ";
	cin >> size;
	cout << endl;

	cout << "Before the sort: ";
	arr = new int[size];
	srand(time(0));
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 1000 + 1;
		cout << arr[i] << " ";
	}
	cout << endl;

	insert_sort(arr, size);

	cout << "Sorted array: ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}

	delete[] arr;

	return 0;
}
void insert_sort(int arr[], int size) {

	for (int i = 1; i < size; i++) {
		int key = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
