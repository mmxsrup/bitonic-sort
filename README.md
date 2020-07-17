# FPGA Bitonic Sort
Project to synthesize bitonic sort circuit using Vivado HLS

## Usage
### Build
```
make -C hls/
make -C proj/
```
### Open hls project
```
make -C proj/ open
```
### Clean
```
make -C hls/ clean
make -C proj/ clean
```

## File hieralchy
```
├── cpp_model  # Used to verify the algorithm
├── hls        # cpp files for Vivado HLS
└── proj       # script files for Vivado HLS project
```

## reference
* [Bitonic sorter - wiki](https://en.wikipedia.org/wiki/Bitonic_sorter)
* [Bitonic sort](http://www.inf.fh-flensburg.de/lang/algorithmen/sortieren/bitonic/bitonicen.htm)
* [Bitonic Sort: Overview](https://www.cs.rutgers.edu/~venugopa/parallel_summer2012/bitonic_overview.html)
* [Bitonic sort (japanese)](https://t-pot.com/program/90_BitonicSort/index.html)
