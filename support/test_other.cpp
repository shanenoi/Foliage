#include "other.hpp"
#include <iostream>

void test_process(function* func) {
	status_return result = func->process(strdup("echo ddd"));
	printf("%d-%s\n", result.code, result.message);
}

void test_gen_random(function* func) {
	char abc[] = "ubysudb";
	func->gen_random(abc, 7);
	std::cout << abc;
}


int main(int argc, char const *argv[])
{
	function* func;
	test_process(func);
	test_gen_random(func);
	return 0;
}