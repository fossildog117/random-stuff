#include "simpletools.h"
#include "abdrive.h"

int testArray[100]={5,2,3,1,4}; // Array for input values
int testArrayTotal=5; // total number of elements being sorted

void *bubblesort(int *a, int n) {
    
    int temp; //for swapping
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[j] > a[j+1]) 
            {    
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}


int main()                    
{
    
  print("Enter number of entries: ");
  scan("%d", &testArrayTotal);

  int i = 0;
  for (i = 0; i < testArrayTotal; i++) {
      print("Enter a number: ");
      scan("%d", &testArray[i]);
  }

  i = 0;
  
  bubblesort(testArray, testArrayTotal);

}