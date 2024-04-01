#ifndef BIT_UTILS_H
#define BIT_UTILS_H

typedef unsigned char uchar;

void print_bits(
        char* start_msg, 
        void const* const ptr,
        size_t const size ) {
    uchar* b = (uchar*) ptr;
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

#endif // EXAMPLE_H

