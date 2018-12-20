#ifndef __BITONIC_SORT_HPP__
#define __BITONIC_SORT_HPP__

#include "ap_int.h"
#include "hls_stream.h"

#define DATA_SIZE 16
#define DATA_W 14

void bitonic_sort(hls::stream<ap_int<DATA_W> > axis_in[], hls::stream<ap_int<DATA_W> > axis_out[]);


#endif
