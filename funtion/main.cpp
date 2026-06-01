#include "stdio.h"
int add(int a, int b) {
    int c = a + b;
    printf("*****");
    return c;
}
int main() {
    int x = 10;
    int y = 20;
    int z = add(x, y);
    return 0;
}