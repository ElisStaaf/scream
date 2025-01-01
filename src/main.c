#include <stdio.h>
#include "scream.h"

#define BUF_LEN 65536

int main(int argc, char **argv) {
    if (argc <= 1) {
        printf("USAGE: scream <file>\n");
        return 1;
    }
    FILE *file_ptr;
    char buf[BUF_LEN];

    file_ptr = fopen(argv[1], "r");

    if (NULL == file_ptr) {
        printf("File can't be opened \n");
    }

    while (fgets(buf, BUF_LEN, file_ptr) != NULL) {}
	
	char *input = "";
	expr(buf, input);
	return 0;
}
