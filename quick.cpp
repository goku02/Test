/*
	Implementing Quick Sort Algorithm.
*/

#include <iostream>
#include <algorithm>

void display(int arr[], int n){
	for (int i = 0; i < n; ++i){
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

// Random Comment

int partition(int arr[], int low, int high){
	int left,right;
	int item = arr[low];

	left = low;
	right = high;
	while(left < right){
		while(arr[left] <= item)
			left++;
		while(arr[right] > item)
			right--;
		if(left < right)
			std::swap(arr[left], arr[right]);
	}
	arr[low] = arr[right];
	arr[right] = item;
	return right;
}


void quickSort(int arr[], int low, int high){
	int pivot;

	if(high > low){
		pivot = partition(arr, low, high);
		quickSort(arr, low, pivot-1);
		quickSort(arr, pivot + 1, high);
	}
}

int main(int argc, char const *argv[]){
	//std::cout << "Hello" << endl;
	int arr[] = {3,1,2,9,33,55,2,10,7};
	int n = sizeof(arr)/sizeof(arr[0]);

	display(arr, n);
	quickSort(arr, 0, n-1);
	display(arr, n);

	return 0;
}