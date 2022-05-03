#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdint.h>
#include <time.h>

#define DEFAULT_LENGTH 30
#define MAX_LENGTH 4096

typedef struct string {
	char *val;
	uint64_t length;
} string;

char charset[100];
uint32_t len_charset = 0;

bool check_valid(char *regex_str) {
	return false;
}

char **parse(char *regex_str) {
	char **tokens;
	return tokens;
}

int gen_charset(char *regex_str) {
	return -1;	
}

void print_usage() {
	return;
}

int main(int argc, char *argv[]) {
	char *passphrase;
	char opt, regex_str;
	uint32_t len_p = DEFAULT_LENGTH;
	
	while( (opt = getopt(argc, argv, "l:c:")) != EOF ) {
		switch(opt) {
			case 'l':
				len_p = atoi(optarg);
				len_p = (len_p > MAX_LENGTH) ? MAX_LENGTH : len_p;
				break;
			case 'c':
				regex_str = optarg;
				break;
			case 'h':
				print_usage();
				return EXIT_SUCCESS;
			default:
				print_usage();
				return EXIT_FAILURE;
		}
	}

	passphrase = (char *) malloc( len_p + 1 );
	srandom(time(0));
	
	for(int i = 0; i < len_p; i++) {
		passphrase[i] = charset[random() % len_charset];
	}
	passphrase[len_p] = '\0';
	
	printf("%s\n", passphrase);
	return EXIT_SUCCESS;
}

/* Command line options:
 * -l : length of the password to be generated <int>
 * -c : character set regex <str>
 */
