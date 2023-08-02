#include <iostream>
#include <vector>
void maxHeapify(std::vector<int>& arr, int n, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left<n && arr[left]>arr[largest])
		largest = left;
	if (right<n && arr[right]>arr[largest])
		largest = right;
	if (largest != i) {
		std::swap(arr[i], arr[largest]);
		maxHeapify(arr, n, largest);
	}
}
void heapSort(std::vector<int>& arr, int n) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		maxHeapify(arr, n, i);
	}
	for (int i = n - 1; i >= 0; i--) {
		std::swap(arr[0], arr[i]);
		maxHeapify(arr, i, 0);
	}
}
void print(std::vector<int>arr, int n) {
	std::cout << "Elementele vectorului dupa sortare: ";
	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
}
int main()
{
	std::vector<int> arr = { 64, 25, 12, 22, 11 };
	int n = arr.size();
	heapSort(arr, n);
	print(arr, n);
	return 0;
}
