#!/bin/bash


gen_data_files() {

	file_idx="$1"
	data_num="$2"

	in_file_prefix="in/data"
	in_filename=$in_file_prefix$file_idx
	out_file_prefix="out/data"
	out_filename=$out_file_prefix$file_idx

	echo $data_num >> $in_filename
	for (( i=0; i<$data_num; i++ ))
	do
		echo $RANDOM >> $in_filename
	done
	(tail -n $data_num $in_filename | sort -n)  > $out_filename

}


check() {

	file_idx="$1"
	data_num="$2"

	in_file_prefix="in/data"
	in_filename=$in_file_prefix$file_idx
	out_file_prefix="out/data"
	out_filename=$out_file_prefix$file_idx

	ret_file_prefix="ret/data"
	ret_filename=$ret_file_prefix$file_idx

	./bitonic_sort < $in_filename > $ret_filename
	diff $out_filename $ret_filename

}


try() {

	time="$1"
	data_num=$2

	rm -rf in out ret
	mkdir in out ret

	for (( t=0; t<$time; t++ ))
	do
		gen_data_files $t $data_num
	done

	for (( t=0; t<$time; t++ ))
	do
		check $t $data_num
		if [ $? = 0 ]; then
			echo $t": Pass"
		else
			echo "Wrong"
			exit 1
		fi
	done

}


try $1 $2

echo OK
