// clase de 27 de agosto de 2024

#include <iostream>
#include <vector>

using namespace std;

bool primos(int num) {
    if (num <= 1) return false; // porque ese no es primo
    for (int i = 2; i*i <= num; i++) { 
        if (num % i == 0) return false;
    }
    return true;
}

void insertionSort(vector<int>& arr){
    int n = arr.size();

    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    vector<int> arr = {12, 5, 3, 7, 11, 4, 8, 13};

    insertionSort(arr);

    for(int num:arr) {
        if(primos(num)){
        cout << num << " ";
        }
    }

    return 0;
}