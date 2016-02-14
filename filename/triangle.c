//
//  triangle.c
//  
//
//  Created by Nathan Liu on 09/10/2015.
//
//

#include "triangle.h"
#include <stdio.h>
#include "graphics.h"
#include <math.h>

int main(void)
{
    int n;
    n = 100;
    int theta;
    theta = 0;
    while (n > 0)
    {
        drawString(".", 30 + (n * sin(theta)), 30 + (n * sin(theta)));
        theta = theta + 0.1;
        n = n - 1;
    }
    return 0;
}
