/*
Sorting mini-project: Professor Dov Kruger
Team Members
1. Noah Malhi
2. Quentin Jimenez
3. Prashant Kumar
References:
1. CLRS
2. The art of computer programming- Don Knuth
3. // Pseudo code found on
https://www.geeksforgeeks.org/shuffle-a-given-array-using-fisher-yates-shuffle-algorithm/
4. https://www.cs.upc.edu/~conrado/research/reports/ALCOMFT-TR-03-50.pdf
Partial QuickSort- Conrado Martinez
*/ 

#include <math.h>
#include <stdio.h>
#include <time.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
#include <cmath>
#include <chrono>
using std::chrono::duration_cast;
using std::chrono::nanoseconds;
using std::chrono::microseconds;
using std::chrono::steady_clock;
// using namespace std::chrono;
using namespace std;

class QuickSort {
 private:
 public:
  void printArray(int *array, int size) {
    for (int i = 0; i < size; ++i) std::cout << array[i] << ' ';
    cout << '\n';
  }
  
  void printFew(int *array, int size) {
    for (int i = 0; i < 5; i++) std::cout << array[i] << ' ';
    cout<<"...";
    for (int i = size-5; i < size; i++) std::cout << array[i] << ' ';
    cout << '\n';
  }

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
    for (int iter = size_arr - 1; iter > 0; iter--) {
      std::uniform_int_distribution<int> distribution(0, iter);
      // int randIndex = rand() % (iter + 1);
      swap(array, iter, distribution(generator));
    }
  }
  
  void shuffleArrayFY(int *array, int size_arr) { //Fisher-Yates Shuffle
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    for (int iter = size_arr - 1; iter > 0; iter--) {
      std::uniform_int_distribution<> distrib(0, iter);
      swap(array, iter, distrib(gen));
    }
  }
  void partialQuicksort(int *array, int left, int right, int k){ 
    if ((right-left)>k){
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
        if((q-1-left)>k){
          QuickSortLomuto(array, left, q - 1);
        }
        if ((right-q-1)>k){
          QuickSortLomuto(array, q + 1, right);
        }
      }
    }
  }
  
  void insertionSort(int *array, int size){
    int iter;
    int currVal, prevIter;
    for(iter = 1; iter < size; iter++){
      currVal = *(array + iter);
      prevIter = iter - 1;
      while(prevIter >= 0 && *(array + prevIter) > currVal ){
        *(array + prevIter + 1) = *(array + prevIter);
        prevIter = prevIter - 1;
      }
      *(array + prevIter + 1) = currVal;
    }
  }
  void QuickSortLomuto(int *array, int left, int right) {
    if (left < right) {
      int i = left - 1;
      // int q;
      // int pivot = array[right]; //Pick right element as pivot
      std::uniform_int_distribution<int> distribution(left, right);
      int pick = distribution(generator);
      int pivot = array[pick];
      for (int j = left; j <= right - 1; j++) {
        if (array[j] <= pivot) {
          i++;
          swap(array, i, j);
        }
      }
      swap(array, i + 1, right);
      int q = i + 1;
      QuickSortLomuto(array, left, q - 1);
      QuickSortLomuto(array, q + 1, right);
    }
  }

  void QuickSortHoare(int *array, int left, int right) {
    // Left and Right are extreme indexes of the array
    int i = left;
    int j = right;
    std::uniform_int_distribution<int> distribution(left, right);
    int pick = distribution(generator);
    int pivot = array[pick];
    // cout << "pivot = " << pivot << ' ' << pick << '\n';
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
  
  void knuthQuickSort(int *array, int left, int right, int k) {
    int n = right-left+1;
    partialQuicksort(array, 0, n-1, k);
    insertionSort(array, n);
  }

  float knuthQuickSortTimed(int *array, int left, int right, int k) { //returns time for golden mean
    int size = sizeof(array)/sizeof(array[0]);
    int *array_copy = new int[size];
    for (int i = 0; i < size; i++){ // Create a copy of the original for golden mean
      array_copy[i] = array[i];
    }
    steady_clock::time_point t1 = steady_clock::now(); //Start clock
    int n = right-left+1;
    partialQuicksort(array_copy, 0, n-1, k);
    printFew(array_copy, n);
    insertionSort(array_copy, n);
    
    steady_clock::time_point t2 = steady_clock::now();  //Stop clock
    float del_t = (float)duration_cast<microseconds>(t2-t1).count();
    cout<<"Runtime in microseconds: "<<del_t<<'\n';
    printFew(array, n);
    return del_t;
  }
  
  int goldenSectionSearch(int *array, int a, int b){ //a-left, b-right
    int n = sizeof(array)/sizeof(array[0]);
    float phi = (1 + sqrt(5))/2;
    int tolerance = 2; //stop if end points of search is less than tolerance
    int k_optimum = (a + b)/2;
    int s = (b-a)/phi;
    int d = a + s;
    int c = b - s;
    while ((b-a)>tolerance){
      if (knuthQuickSortTimed(array, 0, n-1 ,c) < knuthQuickSortTimed(array, 0, n-1 ,d)){
        b = d;
        d = c;
        s = (b - a)/phi;
        c = b - s;
        k_optimum = (a + b)/2;
      }
      else{
        a = c;
        c = d;
        s = (b - a)/phi;
        d = a + s;
        k_optimum = (a + b)/2;
      }
    }
    return k_optimum;
  }
    
};
void testLargeQS(int n) {
  int *fishYatesArr = new int[n];
  for (int i = 0; i < n; i++) *(fishYatesArr + i) = i;
  QuickSort a;
  a.printFew(fishYatesArr, n);
  a.shuffleArray(fishYatesArr, n);
  a.printFew(fishYatesArr, n);
  a.QuickSortLomuto(fishYatesArr, 0, n - 1);
  a.printFew(fishYatesArr, n);
}
int main() {
  QuickSort a;
  constexpr int n = 1000000;
  constexpr int k = 10;
  // testLargeQS(n);
  int *array = new int[n];
  for (int i =0; i < n; i++){
    array[i] = i;
  }
  a.printFew(array, n);
  a.shuffleArrayFY(array, n);
  a.printFew(array, n);
  a.knuthQuickSortTimed(array, 0, n-1, k);
  std::cout << "Test Completed" << ' ';
  return (0);
}