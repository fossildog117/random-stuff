//
//  question11.c
//  
//
//  Created by Nathan Liu on 08/10/2015.
//
//

#include "question11.h"
#include "graphics.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    char myName[] = "A Person";
    printf("Hello, my name is %s\n", myName);
    
    int index = strlen(myName) - 1;
    while (index > -1)
    {
        printf("%c", myName[index]);
        index = index - 1;
    }
    printf("\n");
    return 0;
}