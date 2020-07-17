#include "swap.hpp"


void swap1(ap_int<DATA_W> &data1, ap_int<DATA_W> &data2) {
	if (data1 < data2) {
		ap_int<DATA_W> tmp = data2;
		data2 = data1;
		data1 = tmp;
	}
}

void swap2(ap_int<DATA_W> &data1, ap_int<DATA_W> &data2) {
	if (data1 > data2) {
		ap_int<DATA_W> tmp = data2;
		data2 = data1;
		data1 = tmp;
	}
}
