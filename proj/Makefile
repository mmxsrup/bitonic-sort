HLS = vivado_hls
RM  = rm

build: run.tcl
	$(HLS) -f run.tcl

open:
	cd bitonic_sort && $(HLS) vivado_hls.app&

clean:
	$(RM) -rf bitonic_sort vivado_hls.log
