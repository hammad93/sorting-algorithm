# sorting-algorithm
Non comparison sorting algorithm with time complexity O(n) utilizing elementary data structures
This sorting algorithm has the following time constraints. Proof is left to the 
reader
Worst Case Time Complexity: O(n)
Worst Case Space Complexity: O(k^n) where k is the base for the key

Introduction:
Many sorting algorithms are complex and need data scructures such as arrays and 
trees to operate. The following sorting algorithm requires no abstract data 
structures and relies on integer values denoted as `key`s. 


Method :
Given a set of unique integers, we create a `key` value with a value from the 
following methodolgy:

    1 - Sum every value in the set by 2^i where i is the value in the set, denote
    this value as `key`
    
We are able to then produce output that is sorted in descending order through 
the following methodology:

    2 - Until we reach 0, take the log base two of the `key` and subtract this 
    value to the `key`
    3 - Every time we do a log operation, the ouput is the next value
    
Discussion:
The space complexity of this algorithm is hard to accurately understand within the
terms of applied computer science during the beginning of the 21st century. With 
the restrictions given above, this set of integers: {1002, 45, 5607, 13} will 
need an integer value of almost 2^6000. The tradeoff we are gaining is potentially the
fastest sorting algorithm possible with new applications in combinatorics and
number theory. If we make let go of the simple restriction of unique integers,
the space complexity is O(d^n) where d is the max number of repeated integers. 
Because of the current hardware limitations, the algorithm must be compared with
compatible hardware. The following sorting algorithms will be used for performance
benchmarking:
- Quick sort
- Merge sort
- Heap sort
- Insertion sort
- Bubble sort
- Selection sort
- Radix sort

Benchmarks (TODO) :
To show proper testing and performance, these two benchmarks will be performed:
1 ) LARGE INPUT CASE: The unsorted set of integers between 1 and 1000 of size 100
2 ) DUPLICATE INTEGER CASE: The unsorted array of integers between 1 and 1000 of
    size 50 with maximum duplicate amount of 3
    
_This is novel research with unknown impact. Please contact Hammad Usmani before distributing._
