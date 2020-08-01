#include "file_manager.h"
#include "object/object.h"
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
	
	m.cut();
	m.paste();

}

int main(int argc, char const *argv[]){
	test_manager();
}