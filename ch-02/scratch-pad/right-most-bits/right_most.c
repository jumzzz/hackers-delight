#include <stdio.h>
#include "bit_utils.h"

// Use the following formula to turn off the rightmost 1-bit in a word, producing 
// 0 if none (e.g., 01011000  01010000):
// Formula:
// x & (x - 1)

typedef unsigned int uint32;
typedef void const* const const_void_ptr;
typedef char* char_ptr;
typedef size_t const const_size_t;

void print_ops_bits(
        char_ptr ops,
        const_void_ptr lhs_ptr, 
        const_void_ptr rhs_ptr,
        const_void_ptr res_ptr,
        const_size_t lhs_size,
        const_size_t rhs_size,
        const_size_t res_size) {

    printf("------------------------------------\n");
    print_bits("   ", lhs_ptr, lhs_size);
    print_bits(ops, rhs_ptr, rhs_size); 
    print_bits(" = ", res_ptr, res_size);
    printf("------------------------------------\n\n");
}

void remove_rightmost(uint32 lhs) {
    uint32 rhs = lhs - 1;
    uint32 res = lhs & rhs;
    printf("------------------------------------\n");
    printf("remove_right_most(%u)\n", lhs);
    print_ops_bits(" & ", &lhs, &rhs, &res, sizeof(lhs), sizeof(rhs), sizeof(res));  
}


int main(int argc, char* argv[]) {
    uint32 n0 = 256 + 128 + 64 + 32 + 16 + 8 + 4 + 2 + 1;
    uint32 n1 = 256; 
    uint32 n2 = 256 + 64 +  16 +  4 +  1;
    uint32 n3 = 128 + 1;
    
    remove_rightmost(n0);
    remove_rightmost(n1);
    remove_rightmost(n2);
    remove_rightmost(n3);

    return 0;
}
