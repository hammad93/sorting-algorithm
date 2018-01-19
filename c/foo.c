#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#include <sys/resource.h>

/* SORTING ALGORITHM
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
*/

/*Delcare functions used in main*/
long long getKey(double *array, int size);
int* sort(double key, int size);
double get_process_time();

main() {
    /*Test case input
    */
    int size = 0;
    //Size of the test case
    printf("Enter array size\n");
    scanf("%d", &size);
    double array[size];
    //Test case values
    int i = 0, input = 0;
    for (i = 0; i < size; i++){
        printf("Enter in value %d\n", i + 1);
        scanf("%d", &input);
        array[i] = input;
    }
    
    //Timer
    double t_begin, t_end;
    //Begin timer
    t_begin = get_process_time();
    
    /*Construct `key`
    - `key` is an integer value, not an abstract data structure
    */
    long long key = getKey(array, size);
    printf("`key`: %lld\n", key);
    
    /*Output sorted array
    - The new key is denoted by the double `next`
    */
    int *sorted = sort(key, size);
    
    /*Output results
    */
    for (i = 0; i < size; i++) printf("Position #%d: %d\n", i, sorted[i]);
    
    /*Done*/
    //End timer
    t_end = get_process_time();
    printf("Time: %f\n", t_end - t_begin);
}
/*
PURPOSE: Create the key
INPUT: 
double *array => an array of doubles denoting the array to make the key
int size => size of the mentioned array
METHOD:
OUTPUT: double value with the key*/
long long getKey(double *array, int size){
    long long key = 0;
    int i = 0;
    
    for (i = 0; i < size; i++){
        key += pow(2, array[i]);
    }
    
    return key;
}

/*
PURPOSE: Sort the array
INPUT: 
    double key => `key` value for the sorting algorithm
    int size => Size of the output array
METHOD: 
OUTPUT: An array of doubles
*/
int* sort(double key, int size){
    int *sorted = (int*)calloc(size, sizeof(int));
    double next = 0;
    int output = 0, i = 0;
    
    for (i = 0; i < size; i++){
        output = (log(key))/(log(2));
        sorted[i] = output;
        key -= pow(2, output);
    }
    
    return sorted;
}

double get_process_time() {
    struct rusage usage;
    if( 0 == getrusage(RUSAGE_SELF, &usage) ) {
        return (double)(usage.ru_utime.tv_sec + usage.ru_stime.tv_sec) +
               (double)(usage.ru_utime.tv_usec + usage.ru_stime.tv_usec) / 1.0e6;
    }
    return 0;
}