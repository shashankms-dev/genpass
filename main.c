#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DF_LENGTH 30
#define MAX_LENGTH 1048576

int main(int argc, char *argv[]) {
	unsigned int pass_length, size_charset = 94;
	char *passwd;
	if(argc >= 2) {
		pass_length = atoi(argv[1]);
		pass_length = (pass_length > MAX_LENGTH) ? MAX_LENGTH : pass_length;
	}
	else {
		pass_length = DF_LENGTH;
	}
	passwd = (char *) malloc( pass_length + 1 );
	srand(time(0));
	for(int i = 0; i < pass_length; i++) {
		passwd[i] = rand() % size_charset + 33;
	}
	passwd[pass_length] = '\0';
	printf("%s\n", passwd);
	free(passwd);
	return EXIT_SUCCESS;
}

/* Command line options:
 * -l : length of the password to be generated
 * -c : character set to use
 *
 *
 */
