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

template <typename X>
void merge(X array[], int start, int mid, int end) {

    //create two new arrays
    X left[mid - start];
    int leftSize = sizeof(left) / sizeof(left[0]);
    X right[end - (mid - 1)];
    int rightSize = sizeof(right) / sizeof(right[0]);
    //cout << "size of left subarray is " << leftSize <<
    //"and size of right subarray is " << rightSize << endl;

    //copy array[start:mid] into left[]
    for (int i = 0; i < leftSize; i++) {

        left[i] = array[start + i];

    }

    cout << "The left subarray: " << endl;
    printArray(left, leftSize);

    //copy array[mid + 1:end] into right[]
    for (int j = 0; j < rightSize; j++) {

        right[j] = array[mid + j];

    }

    cout << "The right subarray: " << endl;
    printArray(right, rightSize);

}

int main() {

//my first array of integers
int intArray[] = {1,2,7,3,5,6,9,8,10};
int intSize = sizeof(intArray) / sizeof(intArray[0]);
//cout << intSize;
merge(intArray, 0, 4, intSize - 1);
//printArray(intArray, intSize); //testing print function

//an array of doubles
double doubleArray[] = {9, -2, 5, 12, -3.14, 7, 1.922, 0, -0.6};
int doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);
//printArray(doubleArray, doubleSize);
merge(doubleArray, 0, 4, doubleSize - 1);


}