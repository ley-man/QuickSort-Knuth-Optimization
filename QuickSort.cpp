#include <stdio.h>

#include <iostream>
#include <vector>
using namespace std;

class QuickSortRandomizedLomuto {
 private:
 public:
  template <typename Type, int Size>
  void printArray(Type const (&array)[Size]) {
    for (int i = 0; i < Size; i++) std::cout << array[i] << ' ';
  }
};

int main() {
  int input[] = {2, 8, 7, 1, 3, 5, 6, 4};

  QuickSortRandomizedLomuto a;
  swap(input[0], input[1]);
  a.printArray(input);
}
