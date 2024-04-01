#include <stdio.h>
#include "bit_utils.h"


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

/*
   Use the following formula to turn off the rightmost 1-bit in a word, producing 
   0 if none (e.g., 01011000  01010000):
   
   Formula:
        x & (x - 1)
*/
uint32 off_rightmost(uint32 lhs) {
    uint32 rhs = lhs - 1;
    uint32 res = lhs & rhs;
    printf("------------------------------------\n");
    printf("off_rightmost(%u)\n", lhs);
    print_ops_bits(" & ", &lhs, &rhs, &res, sizeof(lhs), sizeof(rhs), sizeof(res));  
    return res;
}

/*
   Use the following formula to turn on the rightmost 1-bit in a word, producing 
   0 if none (e.g., 10100111  10101111): 
   
   Formula:
        x | (x + 1)
*/
uint32 on_rightmost(uint32 lhs) {
    uint32 rhs = lhs + 1;
    uint32 res = lhs | rhs;
    printf("------------------------------------\n");
    printf("on_rightmost(%u)\n", lhs);
    print_ops_bits(" | ", &lhs, &rhs, &res, sizeof(lhs), sizeof(rhs), sizeof(res));  
    return res;
}

/*
   Use the following formula to turn off trailing 1's in a word, producing 
   x if none (e.g., 10100111  10100000): 
   
   Formula:
        x & (x + 1)
*/
uint32 off_rightmost_trailing_ones(uint32 lhs) {
    uint32 rhs = lhs + 1;
    uint32 res = lhs & rhs;
    printf("------------------------------------\n");
    printf("off_trailing_ones(%u)\n", lhs);
    print_ops_bits(" & ", &lhs, &rhs, &res, sizeof(lhs), sizeof(rhs), sizeof(res));  
    return res;
}

int main(int argc, char* argv[]) {
    uint32 off_n0 = 8 + 4 + 2 + 1;
    
    printf("------------------------------------\n");
    printf("Turning Off Right Most Bits: \n");
    printf("------------------------------------\n");

    uint32 off_n1 = off_rightmost(off_n0);
    uint32 off_n2 = off_rightmost(off_n1);
    uint32 off_n3 = off_rightmost(off_n2);
    
    printf("\n");
    printf("------------------------------------\n");
    printf("Turning On Right Most Bits: \n");
    printf("------------------------------------\n");
    
    uint32 on_n1 = on_rightmost(off_n3);
    uint32 on_n2 = on_rightmost(on_n1);
    uint32 on_n3 = on_rightmost(on_n2);

    uint32 on_off_trails = 2048 + 1024 + 512 + 256  + 8 + 4 + 2 + 1;
    
    printf("\n");
    printf("------------------------------------\n");
    printf("Turning Off Right Most Trailing Ones: \n");
    printf("------------------------------------\n");
    uint32 off_trails = off_rightmost_trailing_ones(on_off_trails);

    return 0;
}
