#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#define DEF_LENGTH 30
#define MAX_LENGTH 4096

char *charspace = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()`~-_+={[}]|\\;:'\",<.>/?\0";
unsigned int pass_length = DEF_LENGTH;
unsigned int prefix_len;
unsigned int mode = 1;
char *passphrase, opt;
unsigned int mode_arr[] = {72, 10, 36, 62, 94};

void print_usage() {
};

int main(int argc, char *argv[]) {
	while( (opt = getopt(argc, argv, "l:m:")) != EOF ) {
		switch(opt) {
			case 'l':
				pass_length = atoi(optarg);
				pass_length = (pass_length > MAX_LENGTH) ? MAX_LENGTH : pass_length;
				break;
			case 'm':
				mode = atoi(optarg);
				mode = (mode < 1 || mode > 5) ? 1 : mode;
				break;
			case 'h':
				print_usage();
				return EXIT_SUCCESS;
			default:
				print_usage();
				return EXIT_FAILURE;
		}
	}

	passphrase = (char *) malloc( pass_length + 1 );
	srand(time(0));
	prefix_len = mode_arr[mode - 1];
	for(int i = 0; i < pass_length; i++) {
		passphrase[i] = charspace[rand() % prefix_len];
	}
	passphrase[pass_length] = '\0';
	printf("%s\n", passphrase);
	free(passphrase);
	return EXIT_SUCCESS;
}

/* Command line options:
 * -l : length of the password to be generated <int>
 * -m : <int> character mode
 */
