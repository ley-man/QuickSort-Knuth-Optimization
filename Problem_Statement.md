Working as a group implement quicksort both the original and Lomuto partitioning schemes (Lomuto is the one in the textbook that ends up with the pivot in the middle between the two partitions).

The pivot should be selected randomly. In order to facilitate testing, seed the random number generator with 0 (Kruger's rule of simulations: never simulate with random numbers since any bug becomes non-repeatable).

Once your code works, you could in theory seed from time so  each run is different, but you don't have to for this project.

Test cases you should definitely make sure work:

1. Already sorted ascending, n=10, 11, 12, 100, 1000, 10^6, 10^7, 10^8 give run times on your machine
2. Descending order (same)
3. Duplicate elements:  1, 2, 2, 2, 2, 2, 2, 2, 2 , 2, 2, 3
4. unique numbers from 1 to n, n = 1000, 10^6, 10^8, then shuffled using Fischer-Yates. There should therefore be exactly one of each number, and you can therefore verify if the sort works, because after sorting the result should be:
1 2 3 4 ... n

 

Last, for an extra 50 points write Knuth optimized quicksort. Write a golden mean search to find optimal k for the following algorithm:

knuthQuicksort(a)
  partialQuicksort(a, k); // k is the size of the minimum partition, so for example, stop partitioning when R - L <= 10 elements or 100 elements
  insertionSort(a); // complete the almost-sorted list using insertion sort. If you do it right this should be O(n)
end


This means for the extra 50 points you need to write a) insertion sort and b) golden mean in addition to the partial quicksort.

Generate a report showing your search results which should look like:
n=10000000    time = .520 seconds   k = 4
n=10000000    time = .386 seconds  k = 10
n=10000000   time = .250 seconds  k = 100
n=10000000   time= .286 seconds k = 150
n=10000000   time= .323 seconds k = 200

These numbers are made up, but if this were true then our best found k = 100, but of course you should be zeroing in using golden mean, finding the most accurate k.

Something like:
L = 1, R = 1000
x = 392  y = 608
and homing in until you find the best k
