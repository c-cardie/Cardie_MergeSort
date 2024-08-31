#include <iostream>
#include <array>
using namespace std;

//function to print an array of any type of element
//passing in the size because there is no length() function for the array class
template <typename T>
void printArray(T array[], int size) {

    for (int i = 0; i < size; i++) {

        cout << array[i] << " ";

    }

    cout << endl;

}

//helper function for the mergeSort function
template <typename X>
void merge(X array[], int start, int mid, int end) {

    //create two new arrays
    //and calculate their sizes
    X left[mid - start];
    int leftSize = mid - start + 1;
    X right[end - (mid - 1)];
    int rightSize = end - mid;

    //copy array[start:mid] into left[]
    for (int i = 0; i < leftSize; i++) {

        left[i] = array[start + i];

    }

    //copy array[mid + 1:end] into right[]
    for (int j = 0; j < rightSize; j++) {

        right[j] = array[mid + 1 + j];

    }

    //i indexes the smallest remaining element in left[]
    int i = 0;
    
    //j indexes the smallest remaining element in right[]
    int j = 0;

    //k indexes the location in array[] to fill
    int k = start;

    //As long as each of the arrays left[] and right[] contains an 
    //unmerged element
    //copy the smallest unmerged element back into array[]
    while ((i < leftSize) && (j < rightSize)) {

        //if the number inside the ith element of left[]
        //is smaller than the jth element of right[]
        if (left[i] <= right[j]) {

            //assign the number inside the ith element of left[] 
            //to the kth element in array[]
            array[k] = left[i];

            //increment i
            i = i + 1;

        } else {

            //assign the number inside the jth element of right[]
            //to the kth element in array[]
            array[k] = right[j];

            //increment j
            j = j + 1;

        }

        //increment k
        k = k + 1;

    }

    //Having gone through one of left[] or right[] entirely,
    //copy the remainder of the other to the end of array[]
    while (i < leftSize) {

        array[k] = left[i];
        i = i + 1;
        k = k + 1;

    }

    while (j < rightSize) {

        array[k] = right[j];
        j = j + 1;
        k = k + 1;

    }

}

template <typename Y>
void mergeSort(Y array[], int start, int end) {

//if there is zero or one element
if (start >= end) {

    return;

}
else {

    //calculate the midpoint of the array 
    int mid = (start + end) / 2;

    //recursively sort array[start:mid]
    mergeSort(array, start, mid);

    //recursively sort array[mid+1:end]
    mergeSort(array, mid + 1, end);

    //merge array[start:mid] and array[mid+1:end]
    //into array[start:end]
    merge(array, start, mid, end);

    }

}

int main() {

    //my first array of integers
    int intArray[] = {1,2,7,3,5,6,9,8,10};
    int intSize = sizeof(intArray) / sizeof(intArray[0]);
    cout << "The first sorted array of integers: " << endl;
    mergeSort(intArray, 0, intSize - 1);
    printArray(intArray, intSize);

    //my second array of integers
    int intArray2[] = {1,2,3,4,5,6,7,8,9,10};
    int intSize2 = sizeof(intArray2) / sizeof(intArray2[0]);
    cout << "The second sorted array of integers: " << endl;
    mergeSort(intArray2, 0, intSize2 - 1);
    printArray(intArray2, intSize2);

    //my third array of integers
    int intArray3[] = {4,3,4,3,4,3, 8,11,3, 0,2,2,3,2,0};
    int intSize3 = sizeof(intArray3) / sizeof(intArray3[0]);
    cout << "The third sorted array of integers: " << endl;
    mergeSort(intArray3, 0, intSize3 - 1);
    printArray(intArray3, intSize3);

    //an array of doubles
    double doubleArray[] = {9, -2, 5, 12, -3.14, 7, 1.922, 0, -0.6};
    int doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);
    cout << "The sorted array of doubles and negatives: " << endl;
    mergeSort(doubleArray, 0, doubleSize - 1);
    printArray(doubleArray, doubleSize);

}