// Author: Shaun Robinson
// Program: Count Inversions 

#include<iostream>
#include<ctime>
using namespace std;

int inversions(int arr[], int temp[], int size);
int merge_sort(int arr[], int temp[], int begin, int end);
int merge(int arr[], int temp[], int begin, int middle, int end);

int main() {
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 }, temp[10], size, result;
	size = (sizeof(arr) / sizeof(arr[0]));

	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	result = inversions(arr, temp, size - 1);

	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << result << endl;

	return 0;
}

int inversions(int arr[], int temp[], int size) {

	return merge_sort(arr, temp, 0, size);
}
int merge_sort(int arr[], int temp[], int begin, int end) {
	int counta, countb, countc;

	counta = countb = countc = 0;
	if (begin < end) {
		int middle = (begin + end) / 2;

		counta += merge_sort(arr, temp, begin, middle);
		countb += merge_sort(arr, temp, middle + 1, end);

		countc += merge(arr, temp, begin, middle, end);
	}

	return counta + countb + countc;
}
int merge(int arr[], int temp[], int begin, int middle, int end) {
	int leftend = (begin + end) / 2;
	int rightstart = leftend + 1;
	int inv_count = 0;
	int k = begin;
	int left = begin;
	int right = leftend + 1;

	while (left <= leftend && right <= end) {
		if (arr[left] < arr[right]) {
			temp[k] = arr[left];
			k++;
			left++;
		}
		else {
			temp[k] = arr[right];
			inv_count += ((leftend + 1) - left);
			k++;
			right++;
		}
	}

	while (left <= leftend) {
		temp[k] = arr[left];
		k++;
		left++;
	}
	while (right <= end) {
		temp[k] = arr[right];
		k++;
		right++;
	}

	for (int i = begin; i < k; i++) {
		arr[i] = temp[i];
	}

	return inv_count;
}