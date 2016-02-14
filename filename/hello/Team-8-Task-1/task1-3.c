#include "simpletools.h"
#include "abdrive.h"

int main()                    
{
  drive_goto(1,1);    //to pass the slowly command

  while(1)
  {
   drive_goto(102,-102);
  } 
}