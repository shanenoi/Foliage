GRAY='\033[1;30m'; YELLOW='\033[1;33m'
BLUE='\033[0;34m'; NC='\033[0m'

selected_file=$1

test_files=$(find $(pwd) | grep "test.*.cpp")

echo '' > test_output

for test in $test_files; do
	cd $(dirname ${test})
	printf "> [ Run Test ${GRAY}${test}${NC} ]\n"
	current_dict=$(cd -)
	bname=$(basename ${test})
	if [ "$bname" = "$selected_file" ]
	then
		g++ $bname -o ./$bname.out && ./$bname.out && rm ./a.out
		return_code=$?
	else
		g++ $bname -o ./a.out && ./a.out >> $current_dict/test_output && rm ./a.out
		return_code=$?
	fi

	cd $current_dict

	if [[ $return_code -eq 0 ]]
	then
		printf "${BLUE}\n \e[1m[ PASS ]\n\n${NC}"
	else
		printf "${YELLOW}\n \e[1m[ STUCK ]\n\n${NC}"
	fi

done