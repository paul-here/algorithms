/*
* Repl.it link: https://repl.it/@pwhipp/hw72
* Title: hw7_2.cpp
* Abstract: This program sorts data with multiple algorithms and 
*           compares the time each takes.
* Author: Paul Whipp
* ID: 1222 
* Date: 10/24/2019
* Atribution:
    https://stackoverflow.com/questions/41077377/how-to-get-current-time-in-milliseconds
    https://www.geeksforgeeks.org/
*/


#include <iostream>
#include <stdlib.h>
#include <string>
#include <chrono>


using namespace std;

void displayMenu(){

    string prompt1 = "========== Select Order of Input Numbers ==========\n";
    string prompt2 = "\t1. Ascending Order\n";
    string prompt3 = "\t2. Descending Order\n";
    string prompt4 = "\t3. Random Order\n";
    string prompt5 = "\tChoose order: ";

    cout << prompt1 << prompt2 << prompt3 << prompt4 << prompt5;
}

int getInputSize(){

    string prompt = "Enter input size: ";

    cout << prompt;
    int n;
    cin >> n;

    return n;
}

int getChoice(){

    displayMenu();
    
    int n;
    cin >> n;

    return n;
}

void displayGenMsg(int choice){

    string bar = "============================================================\n";
    string firstHalf = "Generate input data in ";
    string lastHalf = " order . . .\n";
    string done = "Done.\n";

    string method;
    if(choice == 1) {
        method = "ascending";
    } else if(choice == 2) {
        method = "descending";
    } else {
        method = "random";
    }

    cout << endl << bar << firstHalf << method << lastHalf;
    cout << done << bar;
}

void genAscend(int * arr, int n){

    srand (time(NULL));
    int max_step = 10;
    int curr_val = rand() % max_step + 1;
    
    for(int i = 0; i < n; i++) {

        arr[i] = curr_val;
        curr_val += rand() % max_step + 1;
    }
}

void genDescend(int * arr, int n){

    srand (time(NULL));
    int max_step = 10;
    int curr_val = rand() % max_step + 1;
    
    for(int i = 0; i < n; i++) {

        arr[n - i - 1] = curr_val;
        curr_val += rand() % max_step + 1;
    }
}

void genRand(int * arr, int n){

    srand(time(NULL));
    int max_step = 1000;
    
    for(int i = 0; i < n; i++) {

        arr[i] = rand() % max_step + 1;
    }
}

int * generateInput(int choice, int n) {

    int * inputArr;
    inputArr = new int [n];

    if(choice == 1){
        genAscend(inputArr, n);
    } else if(choice == 2) {
        genDescend(inputArr, n);
    } else {
        genRand(inputArr, n);
    }

    return inputArr;    
}

int * makeCopy(int arr [], int n){

    int * copy;
    copy = new int [n];

    for(int i = 0; i < n; i++){
        copy[i] = arr[i];
    }
    return copy;
}

// from geeksforgeeks.com
void insertionSort(int arr[], int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
  
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
}  

// the chrono code is from stackoverflow
double timeInsert(int * arr, int n){

    chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();

    insertionSort(arr, n);

    chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
    
    chrono::duration<double, std::milli> time_span = t2 - t1;

    return time_span.count();
}

// from geeksforgeeks.com
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 

double timeMerge(int * arr, int n){

    chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();

    mergeSort(arr, 0, n - 1);

    chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
    
    chrono::duration<double, std::milli> time_span = t2 - t1;

    return time_span.count();
}

// A utility function to swap two elements  
// from geeksforgeeks.com
void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  

// from geeksforgeeks.com
int partition (int arr[], int low, int high)  
{  
    int pivot = arr[high]; // pivot  
    int i = (low - 1); // Index of smaller element  
  
    for (int j = low; j <= high - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (arr[j] < pivot)  
        {  
            i++; // increment index of smaller element  
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}

// from geeksforgeeks.com
void quickSort(int arr[], int low, int high)  
{  
    if (low < high)  
    {  
        /* pi is partitioning index, arr[p] is now  
        at right place */
        int pi = partition(arr, low, high);  
  
        // Separately sort elements before  
        // partition and after partition  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}  

// the chrono code is from stackoverflow
double timeQuick(int * arr, int n){

    chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();

    quickSort(arr, 0, n - 1);

    chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
    
    chrono::duration<double, std::milli> time_span = t2 - t1;

    return time_span.count();
}

void sortAndDisplay(int * arr, int n){

    int * copy = makeCopy(arr, n);
    double insert_time = timeInsert(copy, n);
    
    copy = makeCopy(arr, n);
    double merge_time = timeMerge(copy, n);

    double quick_time = timeQuick(arr, n);

    string bar = "============================================================\n";
    string insertion = "Insertion sort: ";
    string merge = "Merge sort:     ";
    string quick = "Quick sort:     ";
    string ms = " milliseconds";

    cout << endl << bar << insertion << insert_time << ms << endl;
    cout << merge << merge_time << ms << endl;
    cout << quick << quick_time << ms << endl;
    cout << bar;
}


int main() {

    int n = getInputSize();
    int choice = getChoice();

    displayGenMsg(choice);
    
    int * inputArr = generateInput(choice, n);
    sortAndDisplay(inputArr, n);

}