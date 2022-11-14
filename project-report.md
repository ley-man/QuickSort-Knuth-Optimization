METHODS
1. Fischer Yates shuffling was used to shuffle the array using uniform random int generator.
2. Randomized versions of Lomuto and Hoare partitioning schemes were created and tested for an array fo size upto 10^8 elements.
3. partialQuicksort method was used with arbitrary k to sort elements such that each unsorted element was at most k elements far from the pivot.
4. Knuth Quicksort employed partialQuicksort and insertionSort consecutively to sort the almost sorted array. 

SYS CONFIG
please insert your system configuration

ARBITRARY TESTING (All passed)
1. For arbitrary size: n=11, 23, 60762, 477113
2. For Ascending 
3. For Descending
4. For repititive elements

TESTING RESULTS
Lomuto Partioning Scheme (with shuffle)
n = 10^1, time = .. ms,
n = 10^2, time = .. ms,
n = 10^3, time = .. ms,
n = 10^4, time = .. ms,
n = 10^5, time = .. ms,
n = 10^6, time = .. ms,
n = 10^7, time = .. ms,
n = 10^8, time = .. ms.

Lomuto Partioning Scheme (with shuffle)
n = 10^1, time = .. ms,
n = 10^2, time = .. ms,
n = 10^3, time = .. ms,
n = 10^4, time = .. ms,
n = 10^5, time = .. ms,
n = 10^6, time = .. ms,
n = 10^7, time = .. ms,
n = 10^8, time = .. ms.

Knuth Sort (partialQuicksort + insertionSort)
n = 10^6, k = 1, time = .. ms,
n = 10^6, k = 10^6, time = .. ms,
n = 10^6, k = , time = .. ms,
n = 10^6, k = , time = .. ms,
n = 10^6, k = , time = .. ms,
n = 10^6, k = , time = .. ms,
n = 10^6, k = , time = .. ms,
n = 10^6, k = , time = .. ms.
