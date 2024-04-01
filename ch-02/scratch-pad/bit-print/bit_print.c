#include <stdio.h>
#include <math.h>
#include "bit_utils.h"


int main() {
    int n0 = 256 + 128 + 64 + 32 + 16 + 8 + 4 + 2 + 1;
    int n1 = 256 + 64 + 16 + 4 + 1;
    int n2 = 512 + 128 + 32 + 8 + 2;

    print_bits("n0 = ", &n0, sizeof(n0));
    print_bits("n1 = ", &n1, sizeof(n1));
    print_bits("n2 = ", &n2, sizeof(n2));

    return 0;
}

