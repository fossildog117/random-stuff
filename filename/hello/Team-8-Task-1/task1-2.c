#include "simpletools.h"
#include "abdrive.h"

int main()                    
{
  drive_goto(1,1);    //to pass the slowly command
  
  drive_goto(256, 256);
  drive_goto(26, -25);
  
  drive_goto(256, 256);
  drive_goto(26, -25);
  
  drive_goto(256, 256);
  drive_goto(26, -25);
  
  drive_goto(256, 256);
  drive_goto(26, -25);

}