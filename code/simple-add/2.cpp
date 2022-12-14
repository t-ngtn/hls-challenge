#include "kernel.hpp"

// use axis
void kernel(int a, int b, int *c) {
#pragma HLS interface axis port = a
#pragma HLS interface axis port = b
#pragma HLS interface axis port = c
    *c = a + b;
}