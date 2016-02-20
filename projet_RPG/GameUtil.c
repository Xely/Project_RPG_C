#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int max(int a, int b)
{
    if(a > b){
        return a;
    } else {
        return b;
    }
}

int min(int a, int b)
{
    if(a > b){
        return b;
    } else {
        return a;
    }
}

// returns a random integer between StartValue and endValue
int doRand(int startValue, int endValue)
{
    /*srand(time(0));
    return (rand() % (endValue - startValue + 1) + startValue);*/

    int n = rand() % (endValue - startValue + 1) + startValue;
    return (n);
}

int dice(int diceMax)
{
    int n = doRand(1, diceMax);
    return n;
}
