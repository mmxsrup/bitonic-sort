#include "swap.hpp"


void swap1(ap_int<DATA_W> &data1, ap_int<DATA_W> &data2) {
	if (data1 < data2) {
		std::swap(data1, data2);
	}
}

void swap2(ap_int<DATA_W> &data1, ap_int<DATA_W> &data2) {
	if (data1 > data2) {
		std::swap(data1, data2);
	}
}
