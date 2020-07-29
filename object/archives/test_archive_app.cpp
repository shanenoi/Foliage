#include "archive_app.h"

void test_archive_app_zip() {
	zip a;
	a.input_files = "archive_app.h";
	a.output_file = "out";
	a.compress();
	a.extract("out.zip");
	system("rm out.zip");
}

void test_archive_app_seven_zip() {
	seven_zip a;
	a.input_files = "archive_app.h";
	a.output_file = "out";
	a.compress();
	a.extract("out.7z");
	system("rm out.7z");
}


int main(int argc, char const *argv[])
{
	test_archive_app_zip();
	test_archive_app_seven_zip();
	return 0;
}