#include "other.h"
#include <iostream>

void test_concat(function* func) {
	char* a=strdup("123");
	char* b=strdup("456");
	printf("%s\n", func->concat(a,b));
}

void test_process(function* func) {
	printf("%s\n", func->process("echo ddd"));
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
	test_concat(func);
	test_gen_random(func);
	return 0;
}