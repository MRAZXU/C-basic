#include <stdio.h>

#define NAME(n) name##n

int main()
{
    
    int NAME(1);
    int NAME(2);
    
    NAME(1) = 1;
    NAME(2) = 2;
    
    printf("%d\n", NAME(1));
    printf("%d\n", NAME(2));

    return 0;
}