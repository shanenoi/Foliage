#include "file.hpp"

int main() {
    int abc[] = {80, 75};
    DETECTER->file = "code.zip";
    DETECTER->get_extension();
    DETECTER->__test_read();
    printf("%d", DETECTER->compare(DEFAULT[0].header, DEFAULT[0].len, abc));
    printf("%d", DETECTER->astype());
}
