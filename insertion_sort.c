/**
 * Program for Insertion_sort runtime analysis
 *
 * Compilation : gcc -o Insertion_sort Insertion_sort.c
 * Execution : ./a.out
 *
 * @Ankush and 1910990144  28/07/21
 * Assignment -> Day2_Coding_Assignment
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*It is a stable algorithm
/*it is a In place

/*
* type 1-> Random Numbers
* type 2-> Sorted Numbers in Descending Order
* type 3-> Sorted Numbers in Ascending Order
*/

void Input_generator(int a[],int n,int type){
    
    if(type == 1) {
        
        // random -> rand()
        for(int i=0;i<n;i++){
            a[i] = rand() % n + 1;
        }
        
    }
    else if(type == 2) {
        
       for(int i=0;i<n;i++){
            a[i] = n-i-1;
        }
        
    }
    else if(type == 3) {
        
         for(int i=0;i<n;i++){
            a[i] = i;
        }
        
    }
    
    
}
void insertion_sort(int a[],int n){
    
   for(int i=1;i<n;i++)
   {
        int curr_index = i;
        //current element
        int curr_element = a[i];
        
        int j = curr_index-1;
        
        //right shifting the elements till we find the current position of the current element
        while(j>=0 && a[j]>curr_element){
            a[j+1] = a[j];
            j--;
        }
        
        // placing current_element into its correct position
        a[j+1] = curr_element;
    }
}

/*
* Function to find time for different types of input
* intial_size -> 8000
* increment at each step -> 4000
*/

void get_time(int current_size,int increase_by,int type){
    struct timeval te;
    int i;
    printf("\n");
    for(i=0;i<8;i++){
        
        int size = current_size + increase_by*i;
        int a[size];
        //generating the input
        Input_generator(a,size,type);
        
        gettimeofday(&te,NULL);
        
        // sec*1000 + microseconds/1000 == milliseconds 
        long long start_time = te.tv_sec * 1000LL + te.tv_usec / 1000;
        
        // Calling insertion_sort to sort array
        insertion_sort(a,size);
        
        gettimeofday(&te,NULL);
        
        long long end_time = te.tv_sec * 1000LL + te.tv_usec / 1000;
        printf("for %d elements :- ",size);
        printf("\t %lld",end_time - start_time);
        printf("\n");
    }
    
}

int main()
{
    int current_size = 8000;
    
    int increase_by = 4000;
    
    printf("Time Taken to sort Random Numbers");
    
    get_time(current_size,increase_by,1);
    
    printf("\n");
    
    printf("Time Taken to Sort Numbers in Descending Order");
      
    get_time(current_size,increase_by,2);
        
    printf("\n");
    
    
    printf("Time Taken to Sort Numbers in Ascending Order");
    
    get_time(current_size,increase_by,3);
        
    printf("\n");

    return 0;
}
