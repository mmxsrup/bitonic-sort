#include "bitonic_sort.hpp"
#include "sorting_network.hpp"

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


void bitonic_sort(hls::stream<ap_int<DATA_W> > axis_in[DATA_SIZE], hls::stream<ap_int<DATA_W> > axis_out[DATA_SIZE]) {
#pragma HLS interface ap_ctrl_hs port=return
#pragma HLS interface axis port=axis_in register
#pragma HLS interface axis port=axis_out register
#pragma HLS dataflow

	ap_int<DATA_W> datas[DATA_SIZE];
	#pragma HLS ARRAY_RESHAPE variable=datas complete dim=1


	input(datas, axis_in);

	sorting_network(datas);

	output(datas, axis_out);

}
