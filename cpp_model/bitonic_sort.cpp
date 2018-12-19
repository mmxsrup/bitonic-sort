#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


template <typename T>
void bitonic_sort(vector<T>& datas) {
	size_t acutual_size = datas.size();

	// need to make datas size 2^n
	size_t size = 1;
	while (size < acutual_size) size *= 2;

	auto max_data = max_element(datas.begin(), datas.end());
	for (size_t i = 0; i < size - acutual_size; ++i) {
		datas.emplace_back(*max_data);
	}


	// This loop creates bitonic seq of length block
	for (size_t block = 2; block <= size; block *= 2) {
		// This loop merge the two bitnic seq(seq size is step) and make bitnic seq
		for (size_t step = block / 2; step >= 1; step /= 2) {
			// This loop replaces data
			for (size_t idx1 = 0; idx1 < size; ++idx1) {

				size_t idx2 = idx1 ^ step; // Determine the elements to compare
				if (idx1 >= idx2) continue; // Comparison already done

				if ( (idx1 & block) != 0) { // upper
					if (datas[idx1] < datas[idx2]) {
						swap(datas[idx1], datas[idx2]);
					}
				} else { // lower
					if (datas[idx1] > datas[idx2]) {
						swap(datas[idx1], datas[idx2]);
					}
				}

			}
		}
	}
}


int main(int argc, char const *argv[])
{
	// data input
	size_t n; cin >> n; // datasize
	vector<int> datas(n); {
		for (int i = 0; i < n; ++i) {
			cin >> datas[i];
		}
	}

	// sort
	bitonic_sort<int>(datas);

	// output
	for (size_t i = 0; i < n; ++i) {
		cout << datas[i] << endl;
	}

	return 0;
}