#include "simpletools.h"
#include "abdrive.h"

int testArrayTotal=5;
int testArray[testArrayTotal]={5,2,3,1,4};

void *bubblesort(int *a, int n) {
    
    int k=-1;
    int temp; //for swapping
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            
            if (a[j] > a[j+1]) 
            {
                
                drive_goto((j-k)*62,(j-k)*62);
                k=j;
                high(26);
                pause(500);
                low(26);
                
                drive_goto((j-k+1)*62,(j-k+1)*62);
                high(26);
                pause(500);
                low(26);
                k=j+1;
                         
                print("\n%d ",j);  
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                                
                print("\nThe array this swap is ");
                
                for (int p = 0; p < n; p++) {
                    print("%d ", a[p]);
                }
            }
        }
    }
  drive_goto((n/2-k)*100,(n/2-k)*100); // moving back into position after completing bubble sort
  drive_goto(26,-25);
}


int main()                    
{
  drive_goto(1,1);    //to pass the slowly command
  
  bubblesort(testArray, testArrayTotal);

}