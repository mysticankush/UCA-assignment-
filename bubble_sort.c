/**
 * Program for Bubble_sort runtime analysis
 *
 * @Ankush and 1910990144  26/07/21
 * Assignment -> Day2_Coding_Assignment
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
* Function to generate Input
* type 1-> Random Numbers
* type 2-> Sorted Numbers in Descending Order
* type 3-> Sorted Numbers in Ascending Order
*/

void take_input(int a[],int n,int type){
    
    if(type == 1) {
        
       //rand()%n is used to find randon number between 0 to n-1.
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
            a[i] = i+1;
        }
        
    }
    
    
}


/*
* Function to Swap two numbers present at indices i and j
*/
void doswap(int arr[],int i,int j){
    
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    
}

/*
* Bubble Sort Algorithm
* It is a stable algorithm
* It is a cache friendly algorithm 
*/

void bubble_sort(int a[],int n){
    
    bool is_swap = false;
    
    for(int i=0;i<n-1;i++){
        
        is_swap = false;
        
        for(int j=0;j<=n-i-1;j++){
            
            // checking adjacent elements if the next element is smaller then swap it with the previous element
            if(a[j] > a[j+1]){
                doswap(a,j,j+1);
                is_swap = true;
            }
            
        }
    }
    
}

/*
* Function to calculate_time for different type of input
* intial_size -> 8000
* increment -> 4000
*final_size -> 36000
*/

void find_time(int intial_size,int incre,int type){
    struct timeval te;
    int i;
    
    for(i=0;i<8;i++){
        
        int size = intial_size + incre*i;
        int a[size];
        
        // Calling Function for generating Input
        take_input(a,size,type);
        
        gettimeofday(&te,NULL);
        
        // sec*1000 + microseconds/1000 == milliseconds 
        long long start_time = te.tv_sec * 1000LL + te.tv_usec / 1000;
        
        // Calling bubble_sort to sort array
        bubble_sort(a,size);
        
        gettimeofday(&te,NULL);
        
        long long end_time = te.tv_sec * 1000LL + te.tv_usec / 1000;
        printf("Time taken by %d elements -> ",size);
        printf(" %lld",end_time - start_time);
        printf("\n");
    }
    
}

int main()
{
    int intial_size = 8000;
    
    int increment = 4000;
    
    printf("For Random Numbers\n");
    
    // type 1-> Random Numbers
    find_time(intial_size,increment,1);
    
    printf("\n");
    
    printf("For Numbers in Descending order \n");
    
      
    // type 2-> Sorted Numbers in Descending Order 
    find_time(intial_size,increment,2);
        
    printf("\n");
    
    
    printf("For Numbers in Ascending order \n");
     
    // type 3-> Sorted Numbers in Ascending Order  
    find_time(intial_size,increment,3);
        
    printf("\n");

    return 0;
}
