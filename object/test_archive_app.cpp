#include "archive.hpp"

void test_archive_app_zip() {
	Zip a;
	a.input_files = "code.hpp";
	a.output_file = "out";
	a.compress();
	a.extract("out.zip");
	system("rm out.zip");
}

void test_archive_app_seven_zip() {
	SevenZip a;
	a.input_files = "code.hpp";
	a.output_file = "out";
	a.compress();
	a.extract("out.7z");
	system("rm out.7z");
}

void test_archive_app_rar() {
	Rar a;
	a.input_files = "archive.hpp";
	a.output_file = "out";
	a.compress();
	a.extract("out.rar");
	system("rm out.rar");
}


int main(int argc, char const *argv[]) {
	test_archive_app_zip();
	test_archive_app_seven_zip();
	return 0;
}