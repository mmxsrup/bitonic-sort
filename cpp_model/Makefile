CXX = g++
CFLAGS = -std=c++14 -Wall
OBJS = bitonic_sort.o


bitonic_sort: bitonic_sort.o
	$(CXX) $(CFLAGS) -o bitonic_sort $(OBJS)

test: bitonic_sort
	# ./test.sh test_num data_num
	./test.sh 100 1024

clean: 
	rm -f bitonic_sort *.o tmp*
	rm -rf in out ret
