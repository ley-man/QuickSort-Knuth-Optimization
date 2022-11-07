#include <stdio.h>

#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

class QuickSort {
 private:
 public:
  void printArray(int *array, int size) {
    for (int i = 0; i < size; ++i) std::cout << array[i] << ' ';
    cout << '\n';
  }

  void selectRandom(int a[], int size_array) {}

  void swap(int *array, int pos1, int pos2) {
    int temp = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = temp;
  }

  void QuickSortLomuto(int *array, int left, int right) {
    if (left < right) {
      int i = left - 1;
      int q;
      int pivot = array[right];
      for (int j = left; j <= right - 1; j++) {
        if (array[j] <= pivot) {
          i++;
          swap(array, i, j);
        }
      }
      swap(array, i + 1, right);
      q = i + 1;
      QuickSortLomuto(array, left, q - 1);
      QuickSortLomuto(array, q + 1, right);
    }
  }

  void QuickSortHoare(int *array, int left, int right) {
    // Left and Right are extreme indexes of the array
    int i = left;
    int j = right;
    // srand((unsigned int)time(NULL));  // Generate random numbers using time
    srand(10);
    int pick = rand() % (j);
    int pivot = array[pick];
    while (i <= j) {
      while (array[i] < pivot) {
        i++;
      }
      while (array[j] > pivot) {
        j--;
      }
      if (i <= j) {
        swap(array, i, j);
        i++;
        j--;
      }
    }
    if (j > left) QuickSortHoare(array, left, j);
    if (i < right) QuickSortHoare(array, i, right);
  }
};

int main() {
  QuickSort a;

  // int array[] = {2, 8, 7, 1, 3, 5, 6, 4};
  int array[] = {1, 2, 2, 1, 2, 1, 1, 2};
  size_t size_array = sizeof(array) / sizeof(array[0]);

  std::cout << "Before Quick Sort :" << ' ';
  a.printArray(array, size_array);

  // a.QuickSortHoare(array, 0, size_array - 1);
  a.QuickSortLomuto(array, 0, size_array - 1);

  std::cout << "After Quick Sort :" << ' ';
  a.printArray(array, size_array);
  return (0);
}
