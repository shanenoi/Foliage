#include "object.hpp"
#include <iostream>

using namespace std;

void test_object() {
	meta_path a = {
		.path = ".",
		.name = "object.h",
	};
	Object test_file = Object(a);
	printf(
		"===%ld===%s===%d===%ld===%ld===%ld\n",
		test_file.size,
		test_file.permissions,
		test_file.type_content,
		test_file.modified,
		test_file.accessed,
		test_file.status
	);

}

int main(int argc, char const *argv[]) {
	test_object();
	return 0;
}
