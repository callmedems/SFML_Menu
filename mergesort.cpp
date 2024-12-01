// MERGE SORT
#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& leftArray, vector<int>& rightArray, vector<int>& array){

    int leftSize = leftArray.size();
    int rightSize = rightArray.size();

    // indices
    int leftIndex = 0;
    int rightIndex = 0;
    int mainIndex = 0;

    // main loop
    while( leftIndex < leftSize && rightIndex < rightSize){
        if(leftArray[leftIndex] < rightArray[rightIndex]) {
            array[mainIndex] = leftArray[leftIndex];
            mainIndex++;
            leftIndex++;
    } else {
        array[mainIndex] = rightArray[rightIndex];
        mainIndex++;
        rightIndex++;
        }
    }

    while (leftIndex < leftSize) {
        array[mainIndex] = leftArray[leftIndex];
        mainIndex++;
        leftIndex++;
    }
    while (rightIndex < rightSize) {
        array[mainIndex] = rightArray[rightIndex];
        mainIndex++;
        rightIndex++;
    }
}

void mergeSort(vector<int>& array){
    int n = array.size();

    if (n <= 1) return; // caso base

    int center = n / 2;

    vector<int> leftArray(center);
    vector<int> rightArray(n - center); // puntito rojo en vscode para breakpoint

    for(int i = 0; i < n; i++){
        if (i < center){
            leftArray[i] = array[i];
        } else {
            rightArray[i - center] = array[i];
        }

    }

// divide

    mergeSort(leftArray);
    mergeSort(rightArray);

// and conquer

    merge(leftArray, rightArray, array);

}


int main() {
    vector<int> array = {12, 3, 7, 9, 14, 6, 11, 2};
    //vector<int> array = {12, 3, 7, 9};

    mergeSort(array);

    for(int num:array){
        cout << num << " ";
    }


    return 0;
}