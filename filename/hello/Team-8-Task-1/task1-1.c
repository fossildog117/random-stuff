#include "simpletools.h"
#include "abdrive.h"

int main()                    
{
  drive_goto(1,1);    //to pass the slowly command

  drive_goto(255,255);
  pause(500);
  
}