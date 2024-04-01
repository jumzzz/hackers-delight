#include <stdio.h>
#include <math.h>

typedef unsigned char uchar;

void print_bits_v1(
        char* start_msg, 
        void const* const ptr,
        size_t const size ) {
    
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;
    
    printf("%s", start_msg);
    
    for (i = size-1; i >= 0; i--) {
        for (j = 7; j >= 0; j--) {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}

void print_bits_v2(
        char* start_msg, 
        void const* const ptr,
        size_t const size ) {
    uchar *b = (unsigned char*) ptr;
    
    printf("%s", start_msg);
    
    for (int i = size - 1; i >= 0; i--) {
        uchar b7 = (b[i] >> 7) & 1;
        uchar b6 = (b[i] >> 6) & 1;
        uchar b5 = (b[i] >> 5) & 1;
        uchar b4 = (b[i] >> 4) & 1;
        uchar b3 = (b[i] >> 3) & 1;
        uchar b2 = (b[i] >> 2) & 1;
        uchar b1 = (b[i] >> 1) & 1;
        uchar b0 = (b[i] >> 0) & 1;
        
        printf("%u", b7);
        printf("%u", b6);
        printf("%u", b5);
        printf("%u", b4);
        printf("%u", b3);
        printf("%u", b2);
        printf("%u", b1);
        printf("%u", b0);
    }
    puts("");
}

int main() {
    int number = 256 + 128 + 64 + 32 + 16 + 8 + 4 + 2 + 1;
    print_bits_v1("print_bits_v1 = ", &number, sizeof(number));
    print_bits_v2("print_bits_v2 = ", &number, sizeof(number));

    return 0;
}

