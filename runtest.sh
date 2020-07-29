YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

test_files=$(find . | grep "test.*.cpp")

echo '' > test_output

for test in $test_files;
do
	cd $(dirname ${test})
	echo -e "> [ Run Test $test ]"
	current_dict=$(cd -)
	
	g++ $(basename ${test}) -o ./a.out;
	./a.out >> $current_dict/test_output
	return_code=$?
	rm a.out
	cd $current_dict

	if [[ $return_code -eq 0 ]]
	then
		printf "${BLUE}\n[ PASS ]\n\n${NC}"
	else
		printf "${YELLOW}\n[ STUCK ]\n\n${NC}"
	fi

done