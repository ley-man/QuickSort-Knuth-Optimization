#include <stdio.h>
#include <time.h>
#include <math.h>
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

  // Fisher Yates shuffle
  // Pseudo code found on
  // https://www.geeksforgeeks.org/shuffle-a-given-array-using-fisher-yates-shuffle-algorithm/
  void shuffleArray(int *array, int size_arr) {
    int randIndex;
    srand(time(NULL));  // Seed with time

    // size_t arrLen = sizeof(array) / sizeof(array[0]);
    // cout << arrLen << '\n';
    for (int iter = 0; iter < size_arr - 1; iter++) {
      randIndex = rand() % (iter + 1);
      swap(array, iter, randIndex);
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
    srand((unsigned int)time(NULL));  // Generate random numbers using time
    // srand(10);
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


  void knuthQuicksort()
  {

  }      

  void partialQuicksort()
  {

  }
};

int main() {
  QuickSort a;
<<<<<<< Updated upstream
  constexpr int n = pow(10, 6);

=======
  constexpr int n = 1000000;
>>>>>>> Stashed changes
  // Allocate an array of n size
  int *fishYatesArr = (int *)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) *(fishYatesArr + i) = i;
  
  a.shuffleArray(fishYatesArr, n);

<<<<<<< Updated upstream
  //a.QuickSortLomuto(fishYatesArr, 0, n - 1);

  a.printArray(fishYatesArr, n);
 
=======
  // a.printArray(fishYatesArr, n);
>>>>>>> Stashed changes
  int size_array = n;
  // int array[] = {2, 8, 7, 1, 3, 5, 6, 4};
  // int array[] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  // TO be tested on larger arrays and Fishcer_Yates!

  std::cout << "Before Quick Sort :" << ' ';
  // a.printArray(fishYatesArr, size_array);

  // a.QuickSortHoare(array, 0, size_array - 1);
  a.QuickSortLomuto(fishYatesArr, 0, size_array - 1);

  std::cout << "After Quick Sort :" << ' ';
  // a.printArray(fishYatesArr, size_array);

  /*// int array[] = {1, 2, 2, 1, 2, 1, 1, 2};
  size_t size_array = sizeof(array) / sizeof(array[0]);

  std::cout << "Before Quick Sort :" << ' ';
  a.printArray(array, size_array);

  // a.QuickSortHoare(array, 0, size_array - 1);
  a.QuickSortLomuto(array, 0, size_array - 1);

  std::cout << "After Quick Sort :" << ' ';
  a.printArray(array, size_array);

  a.QuickSortLomuto(array, 0, size_array - 1);
  std::cout << "QS on sorted array :" << ' ';
  a.printArray(array, size_array);
  */

  return (0);
}
