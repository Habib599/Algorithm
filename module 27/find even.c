#include <stdio.h>

int main() 
{
    int AUTO[] = {400, 2, 5, 302, 9, 10, 602};
    int n = sizeof(AUTO) / sizeof(AUTO[0]);

    int num=0;
    for (int k = 0; k < n; k++) 
    {
        if (AUTO[k]>300) 
        {
            num=num+1;
        }
    }
    printf("Years:- ");
    printf("%d\n", num);
    return 0;
}
