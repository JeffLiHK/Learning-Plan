//
// Created by Jeff Li on 2023/2/10.
//
#include <iostream>
#include "sort_lib.h"

using namespace std;

void printArr(const int arr[], int len);

int main() {
    int arr[10] = {6,2,-4,-1,9,4,2,1,63,0};
    cout << "Before sorting: " << endl;
    printArr(arr, sizeof(arr) / sizeof(int));

    // sorting command
    // todo
    bubble_sort(arr, 10);

    cout << "After sorting: " << endl;
    printArr(arr, sizeof(arr) / sizeof(int));


    return 0;
}

void printArr(const int arr[], int len) {
    cout << "arr: ";
    int count = 0;
    for (int i=0; i < len; i++) {
        cout << arr[i];
        count++;
        if (count < 10)
            cout << ", ";
    }
}