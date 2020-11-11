// Author: Shaun Robinson
// Program: Count Inversions 

#include<iostream>
#include<ctime>
using namespace std;

void insert_sort(int arr[], int size);

int main() {
	int arr[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 }, size;
	size = (sizeof(arr) / sizeof(arr[0]));
	cout << "Insert sort for an array" << endl;

	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	insert_sort(arr, size);

	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}

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
