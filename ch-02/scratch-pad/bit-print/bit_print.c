#include <stdio.h>
#include <math.h>
#include "bit_utils.h"


int main() {
    int number = 256 + 128 + 64 + 32 + 16 + 8 + 4 + 2 + 1;
    print_bits("print_bits_v1 = ", &number, sizeof(number));
    print_bits("print_bits_v2 = ", &number, sizeof(number));

    return 0;
}

