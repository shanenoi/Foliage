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

	object a = object(_a);
	object b = object(_b);
	
	manager m = manager(".");
	
	m.selected_files.push_back(a);
	m.selected_files.push_back(b);

	// m.open();
	// printf("open: %s", m.present_status.message);
	
	// m.cut();
	// printf("cut: %s\n", m.present_status.message);
	// m.paste();
	// printf("paste: %s\n", m.present_status.message);
	// m.copy();
	// printf("copy: %s\n", m.present_status.message);
	// m.paste();
	// printf("paste: %s\n", m.present_status.message);

}

int main(int argc, char const *argv[]){
	test_manager();
}