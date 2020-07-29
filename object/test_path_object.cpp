#include "path.h"
#include "object.h"


void test_path() {
	path test_file = path("./path.h");
	printf(
		"===%d===%s===%s===%ld===%ld===%ld",
		test_file.size(),
		test_file.permissions(),
		test_file.type(),
		test_file.modified(),
		test_file.accessed(),
		test_file.status()
	);

}

void test_object() {
	object a = object("2323");
}

int main(int argc, char const *argv[]) {
	test_path();
	return 0;
}