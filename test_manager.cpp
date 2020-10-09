#include "file_manager.hpp"
#include "object/object.hpp"
#include <iostream>

using namespace std;

void test_manager() {
	meta_path _a = {
		.path = ".",
		.name = "runtest.sh"
	};
	meta_path _b = {
		.path = ".",
		.name = "test_output"
	};

	Object a = Object(_a);
	Object b = Object(_b);
	
	Manager m = Manager(".");
	
	m.selected_files.push_back(a);
	m.selected_files.push_back(b);

	m.cut();
	m.paste();

	printf("paste: %s\n", m.present_status.message);

}

int main(int argc, char const *argv[]){
	test_manager();
}