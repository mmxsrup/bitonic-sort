#include "bitonic_sort.hpp"

#include "ap_int.h"
#include <hls_stream.h>

void bitonic_sort(hls::stream<ap_int<DATA_W>> axis_in[], hls::stream<ap_int<DATA_W>> axis_out[]) {

	ap_int<DATA_W> datas[DATA_SIZE];

	// input data from stream
	for (int i = 0; i < DATA_SIZE; ++i) {
		datas[i] = axis_in[i].read();
	}


	// This loop creates bitonic seq of length block
	for (int block = 2; block <= DATA_SIZE; block *= 2) {
		// This loop merge the two bitnic seq(seq size is step) and make bitnic seq
		for (int step = block / 2; step >= 1; step /= 2) {
			// This loop replaces data
			for (int idx1 = 0; idx1 < DATA_SIZE; ++idx1) {

				int idx2 = idx1 ^ step; // Determine the elements to compare
				if (idx1 < idx2) {
					if ( (idx1 & block) != 0) { // upper
						if (datas[idx1] < datas[idx2]) {
							std::swap(datas[idx1], datas[idx2]);
						}
					} else { // lower
						if (datas[idx1] > datas[idx2]) {
							std::swap(datas[idx1], datas[idx2]);
						}
					}
				}

			}
		}
	}


	// output data to stream
	for (int i = 0; i < DATA_SIZE; ++i) {
		axis_out[i].write(datas[i]);
	}

}
