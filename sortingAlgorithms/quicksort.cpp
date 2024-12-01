#include <iostream>
using namespace std;

// swap variables
void swap(int& a, int& b) { 
    int temp = a;
    a = b;
    b = temp;
}

// partition function 
int partition(int arr[], int low, int high) {
    // last element as pivot
    int pivot = arr[high];   
    int i = low - 1;        // index of the smaller element

    // partition the array
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // sort the left and right parts
        quickSort(arr, low, pi - 1);  // sorting the left part
        quickSort(arr, pi + 1, high); // sorting the right part
    }
}

// print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {17,92,56,3,22};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: ";
    printArray(arr, n);
    return 0;
}