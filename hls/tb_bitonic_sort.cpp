#include "bitonic_sort.hpp"

// #include "ap_int.h"
// #include <hls_stream.h>
#include <cstdio>
#include <algorithm>


// Number of test case
#define TEST_NUM 32

struct TestData {
	ap_int<DATA_W> datas[DATA_SIZE];
	ap_int<DATA_W> datas_acutual[DATA_SIZE];
	ap_int<DATA_W> datas_expected[DATA_SIZE];
};


void makeTestData(TestData& td);
int check(TestData& td);
int tb_bitonic_sort();


int main() {
	// return number of error
	return tb_bitonic_sort();
}


int tb_bitonic_sort() {

	hls::stream<ap_int<DATA_W>> axis_in[DATA_SIZE];
	hls::stream<ap_int<DATA_W>> axis_out[DATA_SIZE];

	// Make test data
	TestData testdatas[TEST_NUM];
	for (int i = 0; i < DATA_SIZE; ++i) {
		makeTestData(testdatas[i]);
	}

	// Set input data
	for (int id = 0; id < TEST_NUM; ++id) {
		for (int i = 0; i < DATA_SIZE; ++i) {
			axis_in[i].write(testdatas[id].datas[i]);
		}
	}

	// Execute
	for (int id = 0; id < TEST_NUM; ++id) {
		bitonic_sort(axis_in, axis_out);
	}

	// Get output
	bool flag = true;
	for (int id = 0; id < TEST_NUM; ++id) {
		for (int i = 0; i < DATA_SIZE; ++i) {
			testdatas[id].datas_acutual[i] = axis_out[i].read();
		}
	}

	// Check
	int err = 0;
	for (int id = 0; id < TEST_NUM; ++id) {
		err += check(testdatas[id]);
	}
	return err;

}


void makeTestData(TestData& td) {
	const int MAX = 2047;
	const int MIN = -2047;
	for (int i = 0; i < DATA_SIZE; ++i) {
		td.datas[i] = rand()% (MAX - MIN + 1) + MIN;
		td.datas_expected[i] = td.datas[i];
	}
	std::sort(td.datas_expected, td.datas_expected + DATA_SIZE);
}


int check(TestData& td) {
	int ret = 0;
	for (int i = 0; i < DATA_SIZE; ++i) {
		if (td.datas_acutual[i] != td.datas_expected[i])
			ret++;
	}
	return ret;
}
