#include "kernel.hpp"

void kernel(
  const float table[256],
  const uint8_t in[1024],
  const int size,
  float out[1024]
) {
# pragma HLS INTERFACE mode=axis port=table
# pragma HLS INTERFACE mode=axis port=in
# pragma HLS INTERFACE mode=axis port=size
# pragma HLS INTERFACE mode=axis port=out
# pragma HLS ARRAY_PARTITION variable=table type=cyclic factor=16 dim=1
# pragma HLS ARRAY_PARTITION variable=in type=cyclic factor=16 dim=1
# pragma HLS ARRAY_PARTITION variable=out type=cyclic factor=16 dim=1

    float lut[256];
# pragma HLS ARRAY_PARTITION variable=lut type=cyclic factor=16


    for (int i = 0; i < 256; ++i){
# pragma HLS PIPELINE
# pragma HLS UNROLL factor=16 skip_exit_check
        lut[i] = table[i];
    }

    for (int i = 0; i < size; ++i){
# pragma HLS PIPELINE
# pragma HLS UNROLL factor=16 skip_exit_check
        out[i] = lut[in[i]];
    }
}