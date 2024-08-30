#include <iostream>
#include <array>
using namespace std;

//function to print an array of any type of element
template <typename T>
void printArray(T array[], int size) {

    for (int i = 0; i < size; i++) {

        cout << array[i] << " ";

    }

    cout << endl;

}

int main() {

//my first array of integers
int intArray[] = {1,2,7,3,5,6,9,8,10};
int intSize = sizeof(intArray) / sizeof(intArray[0]);
printArray(intArray, intSize); //testing print function

double doubleArray[] = {9, -2, 5, 12, -3.14, 7, 1.922, 0, -0.6};
int doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);
printArray(doubleArray, doubleSize);


}