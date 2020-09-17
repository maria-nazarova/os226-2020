
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int retCode = 0;
size_t buf_len = 256;

int echo(int argc, char *argv[]) {
	for (int i = 1; i < argc; ++i) {
		printf("%s%c", argv[i], i == argc - 1 ? '\n' : ' ');
	}
	return argc - 1;
}

void retcode(int argc, char *argv[]) {
	printf("%d\n", retCode);
}

int main(int argc, char* argv[]) {

	char* operationNULL= NULL;
	char* wordNULL = NULL;
	char str[buf_len];
	int newArgc;
	char* newArgv[buf_len];
	
	while(fgets(str, buf_len, stdin)) {
		
		char* operation = strtok_r(str, ";\n", &operationNULL);
		while(operation != NULL) {
			
			char* word = strtok_r(operation, " ", &wordNULL);
			newArgc = 0;
			while (word != NULL) {
				newArgv[newArgc] = word;
				newArgc++;
				word = strtok_r(NULL, " ", &wordNULL);
			}

			if(strcmp(newArgv[0], "echo") == 0) {
				retCode = echo(newArgc, newArgv);
			}
			else if(strcmp(newArgv[0], "retcode") == 0) {
				retcode(newArgc, newArgv);
			}
			else {
				printf("Operation %s is unknown\n", newArgv[0]);
			}

			operation = strtok_r(NULL, ";\n", &operationNULL);
		}
	}

	return 0;
} 