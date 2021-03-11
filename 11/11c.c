#include <stdio.h> // using do-while loop
#include <stdlib.h>
void main()
{
    int n, i = 1, f = 1;
    // clrscr();
    printf("\n Enter The Number:");
    scanf("%d", &n);
    //LOOP TO CALCULATE THE FACTORIAL OF A NUMBER
    do
    {
        f = f * i;
        i++;
    } while (i <= n);
    printf("\n The Factorial of %d is %d", n, f);
    // getch();
}