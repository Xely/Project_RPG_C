#include <stdio.h>
#include <stdlib.h>
//#include "GameUtil.c"

int main()
{
    int i = 0;

    for(i=0;i<50;i++){
        printf("%d",dice(6));
    }
    return 0;
}
