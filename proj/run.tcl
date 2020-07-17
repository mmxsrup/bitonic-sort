# Create a project
open_project -reset bitonic_sort

# Add design files
add_files ../hls/swap.hpp
add_files ../hls/swap.cpp
add_files ../hls/sorting_network.hpp
add_files ../hls/sorting_network.cpp
add_files ../hls/bitonic_sort.hpp
add_files ../hls/bitonic_sort.cpp

# Add test bench
add_files -tb ../hls/tb_bitonic_sort.cpp

# Set the top-level function
set_top bitonic_sort

# Create a solution
open_solution -reset solution1

# Define technology and clock rate
set_part  {xc7k160tfbg484-1}
create_clock -period 10 -name default

# C simulation
csim_design

# Run synthesis
csynth_design

# RTL simulation
cosim_design -trace_level all

# RTL implementation
export_design

exit
