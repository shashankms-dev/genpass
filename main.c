#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <time.h>
#include <regex.h>

#define DEFAULT_LENGTH 30
#define MAX_LENGTH 4096

char charset[100];
uint32_t len_charset = 0;

void gen_charset(char *regex_str) {
	if(regex_str == NULL) {
		for(uint8_t ch = '0'; ch <= '9'; ch++)
			charset[len_charset++] = ch;
		for(uint8_t ch = 'A'; ch <= 'Z'; ch++)
			charset[len_charset++] = ch;
		for(uint8_t ch = 'a'; ch <= 'z'; ch++)
			charset[len_charset++] = ch;
		charset[len_charset] = '\0';
		return;
	}

	regex_t preg;
	regmatch_t pmatch[1];
	int ret = regcomp(&preg, regex_str, REG_NOSUB | REG_NEWLINE);
	if(ret != 0) {
        fprintf(stderr, "Error: while compiling regular expression. \n");
        exit(-1);
    }
	char chstr[2] = {'\0', '\0'};
    for(uint8_t i = '!'; i <= '~'; i++) {
        chstr[0] = i;
        if(regexec(&preg, chstr, 1, pmatch, REG_NOTBOL | REG_NOTEOL) == 0) {
            //string matched the given regex
            charset[len_charset++] = chstr[0];
        }
    }
	charset[len_charset] = '\0';
    regfree(&preg);
}

void print_usage() {
	return;
}

int main(int argc, char *argv[]) {
	char *passphrase;
	char opt, *regex_str = NULL;
	uint32_t pass_len = DEFAULT_LENGTH;
	
	while( (opt = getopt(argc, argv, "l:c:")) != EOF ) {
		switch(opt) {
			case 'l':
				pass_len = atoi(optarg);
				pass_len = (pass_len > MAX_LENGTH) ? MAX_LENGTH : pass_len;
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

	gen_charset(regex_str);
	
	passphrase = (char *) malloc( pass_len + 1 );
	srandom(time(0));
	for(int i = 0; i < pass_len; i++) {
		passphrase[i] = charset[random() % len_charset];
	}
	passphrase[pass_len] = '\0';
	
	printf("charset: %s\n", charset);
	printf("%s\n", passphrase);
	return EXIT_SUCCESS;
}

