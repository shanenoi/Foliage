#include "object.h"
#include <iostream>

using namespace std;

void test_object() {
	meta_path a = {
		.path = ".",
		.name = "object.h",
	};
	object test_file = object(a);
	printf(
		"===%ld===%s===%s===%ld===%ld===%ld\n",
		test_file.size,
		test_file.permissions,
		test_file.type_content,
		test_file.modified,
		test_file.accessed,
		test_file.status
	);

}

class a: public object {
	public:
		a(meta_path);
		virtual void open();
};

void a::open() {
	cout << "file is readly open!";
}

int main(int argc, char const *argv[]) {
	test_object();
	meta_path cc = {
		.path = ".",
		.name = "object.h",
	};
	object b = a(cc);
	return 0;
}