/*
Sorting mini-project: Professor Dov Kruger
Team Members
1. Noah Malhi
2. Quentin Jimenez
3. Prashant Kumar

References:
1. CLRS
2. // Pseudo code found on
https://www.geeksforgeeks.org/shuffle-a-given-array-using-fisher-yates-shuffle-algorithm/

*/
#include <math.h>
#include <stdio.h>
#include <time.h>

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
using namespace std;

class QuickSort {
 private:
 public:
  void printArray(int *array, int size) {
    for (int i = 0; i < size; ++i) std::cout << array[i] << ' ';
    cout << '\n';
  }
  void printFew(int *array, int size) {
    for (int i = 0; i < 4; i++) std::cout << array[i] << ' ';
    cout<<"...";
    for (int i = size-5; i < size; i++) std::cout << array[i] << ' ';
    cout << '\n';
  }

  void selectRandom(int a[], int size_array) {}

  void swap(int *array, int pos1, int pos2) {
    int temp = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = temp;
  }
  // srand(time(nullptr)1);  // Seed with time
  // srand(0);
  // Fisher Yates shuffle

  std::default_random_engine generator;

  void shuffleArray(int *array, int size_arr) {
    // size_t arrLen = sizeof(array) / sizeof(array[0]);
    // cout << arrLen << '\n';
    for (int iter = size_arr - 1; iter > 0; iter--) {
      std::uniform_int_distribution<int> distribution(0, iter);
      // int randIndex = rand() % (iter + 1);
      swap(array, iter, distribution(generator));
    }
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
    std::uniform_int_distribution<int> distribution(left, right);

    // srand(10);
    // int pick = rand() % (j - i) + i;  // Check!!
    int pick = distribution(generator);
    int pivot = array[pick];
    cout << "pivot = " << pivot << ' ' << pick << '\n';
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

  void knuthQuicksort() {}

  void partialQuicksort() {}
};
void testLargeQS(int n) {
  int *fishYatesArr = new int[n];
  for (int i = 0; i < n; i++) *(fishYatesArr + i) = i;
  QuickSort a;
  a.shuffleArray(fishYatesArr, n);

  a.QuickSortLomuto(fishYatesArr, 0, n - 1);

  // // a.printArray(fishYatesArr, n);
  int size_array = n;
}
int main() {
  QuickSort a;
  constexpr int n = 10000000;
  testLargeQS(n);
  // // Allocate an array of n size

  // // int array[] = {2, 8, 7, 1, 3, 5, 6, 4};
  // // int array[] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

  std::cout << "Test Completed" << ' ';
  // // a.printArray(fishYatesArr, size_array);

  // // a.QuickSortHoare(array, 0, size_array - 1);

  // std::cout << "After Quick Sort :" << ' ';
  // // a.printArray(fishYatesArr, size_array);

  return (0);
}
