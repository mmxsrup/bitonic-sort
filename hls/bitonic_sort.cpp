#include "bitonic_sort.hpp"


void input(ap_int<DATA_W> datas[DATA_SIZE], hls::stream<ap_int<DATA_W> > axis_in[DATA_SIZE]) {
	// input data from stream
	for (int i = 0; i < DATA_SIZE; ++i) {
	#pragma HLS unroll
		datas[i] = axis_in[i].read();
	}
}


void output(ap_int<DATA_W> datas[DATA_SIZE], hls::stream<ap_int<DATA_W> > axis_out[DATA_SIZE]) {
	// output data to stream
	for (int i = 0; i < DATA_SIZE; ++i) {
	#pragma HLS unroll
		axis_out[i].write(datas[i]);
	}
}


void sort_network(ap_int<DATA_W> datas[DATA_SIZE]) {
	// This loop creates bitonic seq of length block
	LOOP_BLOCK: for (int block = 2; block <= DATA_SIZE; block *= 2) {
	#pragma HLS
		// This loop merge the two bitnic seq(seq size is step) and make bitnic seq
		LOOP_STEP: for (int step = block / 2; step >= 1; step /= 2) {
		#pragma HLS loop_tripcount min=1 max=4 avg=2 // max = n (DATA_SIZE=2^n)
			 // This loop replaces data
			LOOP_IDX: for (int idx1 = 0; idx1 < DATA_SIZE; ++idx1) {
			#pragma HLS unroll
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
}



void bitonic_sort(hls::stream<ap_int<DATA_W> > axis_in[DATA_SIZE], hls::stream<ap_int<DATA_W> > axis_out[DATA_SIZE]) {
#pragma HLS interface ap_ctrl_hs port=return
#pragma HLS interface axis port=axis_in register
#pragma HLS interface axis port=axis_out register
#pragma HLS dataflow

	ap_int<DATA_W> datas[DATA_SIZE];
	#pragma HLS ARRAY_RESHAPE variable=datas complete dim=1


	input(datas, axis_in);

	sort_network(datas);

	output(datas, axis_out);

}
