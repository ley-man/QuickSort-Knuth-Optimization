  // This function chooses a random pivot point resulting in average case nlogn
  void QuickSortLomuto(int *array, int left, int right) {
    if (left < right) {
      std::uniform_int_distribution<int> distribution(left, right);
      int pivot = array[distribution(generator)];
      swap(array, right, pivot);
      int x = array[right];
      int i = left - 1;
      for (int j = left; j<=right-1; j++){
        if (array[j]<=x){
          i = i + 1;
          swap(array, i, j);
        }
      }
      swap(array, i+1, right);
      int q = i+1;
      QuickSortLomuto(array, left, q-1);
      QuickSortLomuto(array, q+1, right);
    }
  }
