#include <stdio.h>


void foo(int *pa) {
    *pa = *pa + 1; // acessa variavel global
}

void main(void) {
    int a = 0; 
    int b = 0;
    int *pa;
    int *pb;
    
    pa = &a;
    pb =  &b;

    while (1) {
        foo(pa);
        
        if (a > 5) {
            *pb = 1;
        }
    }
}
