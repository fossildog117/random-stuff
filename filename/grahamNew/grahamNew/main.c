//
//  main.c
//  grahamNew
//
//  Created by Nathan Liu on 24/10/2015.
//  Copyright © 2015 Liu Empire. All rights reserved.
//

#import <stdio.h>
#import <stdlib.h>

// program on Graham's worksheet - START

/*int main(int argc, char const *argv[])
{
    int higherNumber;
    printf("Enter higher number: ");
    scanf("%i", &higherNumber);
    
    int lowerNumber;
    printf("Enter lower number: ");
    scanf("%i", &lowerNumber);
    
    int output = higherNumber;
    
    while (lowerNumber < higherNumber) {
        
        output = output * lowerNumber;
        lowerNumber++;
        
    }
    
    printf("%i \n", output);
    
    return 0;
}*/

// program on Graham's worksheet - END

int main() {
    
    int firstDate[3];
    printf("Enter date (day/month/year): ");
    scanf("%i %i %i", &firstDate[0], &firstDate[1], &firstDate[2]);
    
    if (0 <= firstDate[0] && firstDate[0] < 31 && 0 <= firstDate[1] && firstDate[1] < 13) {
    
    printf("%i %i %i", firstDate[0], firstDate[1], firstDate[2]);
        
    } else {
        
        printf("Please enter a valid date (day/month/year): ");
        scanf("%i %i %i", &firstDate[0], &firstDate[1], &firstDate[2]);
        
    }
    
    return 0;
}

