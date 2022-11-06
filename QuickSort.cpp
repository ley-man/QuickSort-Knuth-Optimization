#include <stdio.h>

#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

class QuickSort {
 private:
 public:
  template <typename Type, int Size>
  void printArray(Type const (&array)[Size]) {
    for (int i = 0; i < Size; i++) std::cout << array[i] << ' ';
    cout << '\n';
  }

  void selectRandom(int a[], int size_array) {}

  void swap(int *array, int pos1, int pos2) {
    int temp = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = temp;
  }
  void QuickSortRandomLomuto(int array[], int size_a) {}

  void QuickSortRandomHoare(int *array, int left, int right) {
    // Left and Right are extreme indexes of the array
    int i = left;
    int j = right;
    // srand((unsigned int)time(NULL));  // Generate random numbers using time
    srand(10);
    int pick = rand() % (j - i);
    int pivot = array[pick];
    // cout << pivot << '\n';
    // while (i < j) {
    // while
    // array[i] <= pivot and i < j
    // }
  }
};

int main() {
  QuickSort a;

  int input[] = {2, 8, 7, 1, 3, 5, 6, 4};
  size_t size_array = sizeof(input) / sizeof(input[0]);
  a.QuickSortRandomHoare(input, 0, size_array);
  a.printArray(input);
  a.swap(input, 2, 3);
  a.printArray(input);
}
