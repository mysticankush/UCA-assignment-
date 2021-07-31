/**
 * Program for Selection sort runtime analysis
 *
 * Compilation : gcc selection_sort.c
 * Execution : ./a.out
 *
 * @Ankush and 1910990144  28/07/21
 * Assignment -> Day2_Coding_Assignment
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* It is an unstable algorithm
/*It is In place
/*
* Function to generate Input
* type 1-> Random Numbers
* type 2-> Sorted Numbers in Descending Order
* type 3-> Sorted Numbers in Ascending Order
*/

void Input_generator(int a[],int n,int type){
    
    if(type == 1) {
        
        // rand()->for generating random number
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

/*
* Function to Swap two numbers
*/
void customswap(int a[],int i,int j){
    
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
 
}

void selection_sort(int a[],int n){
   
   for(int i = 0; i < n; i++){
        int min_idx = i;
        
        // Finding the index of minimum element in the subarray from i+1 to n 
        for(int j = i + 1; j < n; j++){
            if(a[j] < a[min_idx]){
                min_idx = j;
            }
        }
        
        //swaping the position of minimum element with the current elements position 
        if(min_idx!=i){
            customswap(a,min_idx,i);
        }
    } 
   
}

/*
* Function to calculate time for different types of input
* intial_size -> 8000
* increment at each step -> 4000
*/

void calculate_time(int current_size,int increase_by,int type){
    struct timeval te;
    int i;
    printf("\n");
    for(i=0;i<8;i++){
        
        int size = current_size + increase_by*i;
        int a[size];
        
        // Calling Function for generating Input
        Input_generator(a,size,type);
        
        gettimeofday(&te,NULL);
        
        // sec*1000 + microseconds/1000 == milliseconds 
        long long start_time = te.tv_sec * 1000LL + te.tv_usec / 1000;
        
        // Calling selection_sort to sort array
        selection_sort(a,size);
        
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
    
    printf("Time Taken By Random Numbers");
    
    calculate_time(current_size,increase_by,1);
    
    printf("\n");
    
    printf("Time Taken By Sorted Numbers in Descending Order");
      
    calculate_time(current_size,increase_by,2);
        
    printf("\n");
    
    printf("Time Taken By Sorted Numbers in Ascending Order");
    
    calculate_time(current_size,increase_by,3);
        
    printf("\n");
    
    return 0;
    
}

