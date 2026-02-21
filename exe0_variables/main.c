#include <stdio.h>


void foo(int *a) {
    *a = *a + 1; 
}

void main(void) {
    int a = 0; 
    
    while (1) {
        foo(&a);
        
        if (a > 5) {
            int b = 1;

        }
    }
}
