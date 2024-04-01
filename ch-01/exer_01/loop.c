#include <stdio.h>

void for_loop_incr(int *num, int num_incr) {
    for (int i = 0; i < num_incr; i++)
        *num += 1;
}


void while_loop_incr(int *num, int num_incr) {
    int counter = 0;
    while (counter++ < num_incr)
        *num += 1;
}

void do_while_loop_incr(int *num, int num_incr) {
    int counter = 1;
    do {
        *num +=  1;
    } while (counter++ < num_incr);
}

int main(int argc, char* argv[]){
    int n0 = 10;
    int n1 = 10;
    int n2 = 10;

    int num_incr = 10;

    for_loop_incr(&n0, num_incr);
    while_loop_incr(&n1, num_incr);
    do_while_loop_incr(&n2, num_incr);

    printf("n0 = %d\n", n0);
    printf("n1 = %d\n", n1);
    printf("n2 = %d\n", n2);
    
    return 0;
}
