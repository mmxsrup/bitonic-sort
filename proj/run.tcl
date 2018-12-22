############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
open_project bitonic_sort
set_top bitonic_sort
add_files ../hls/swap.hpp
add_files ../hls/swap.cpp
add_files ../hls/sorting_network.hpp
add_files ../hls/sorting_network.cpp
add_files ../hls/bitonic_sort.hpp
add_files ../hls/bitonic_sort.cpp
add_files -tb ../hls/tb_bitonic_sort.cpp -cflags "-Wno-unknown-pragmas"

open_solution "solution1"
set_part {xczu9eg-ffvb1156-2-i} -tool vivado

create_clock -period 10 -name default
#source "directives.tcl"

csim_design
csynth_design
cosim_design
export_design -format ip_catalog

exit
