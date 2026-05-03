#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include "calc_func.h"
void sum(int a, int b, int *ptr){
    *ptr = a + b;
};

void subtraction(int a, int b, int *ptr){
    *ptr = a - b;

}

void multiplication(int a, int b, int *ptr){
    *ptr = a * b;
}


int division(int a, int b, int *ptr){
    if (b == 0)
    {
        printf("\x1b[31m[ERROR] \x1b[0m Possível divisão por zero, insira um valor valido.\n");
        return -1;
    }
    *ptr = a / b;
    return 0;
}

