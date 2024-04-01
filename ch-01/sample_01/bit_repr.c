#include <stdio.h>
#include <math.h>

int main() {
    int x = 0x80000000;
    int y = 0x80000000;
    
    int z = -(pow(2, 31) + 1);

    printf("x = %d, 2^31 = %d\n", x, z);
    printf("y = %d, 2^31 = %d\n", y, z);
    return 0;
}
