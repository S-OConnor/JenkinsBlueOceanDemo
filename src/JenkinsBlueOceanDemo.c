
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <assert.h>
#include <sys/types.h>
#include <string.h>

#define _PATH "PATH"
#define _PATH_CURRENT_DIR "./"
#define _PATH_SEP ":"
#define VERBOSE_OPT "-Verbose"
#define DEBUG_OPT "-Debug"
#define ADD_OPT "-Add"
#define MUL_OPT "-Mul"

static unsigned char AddFlag = 0;
static unsigned char MulFlag = 0;

int main(int argc, char** argv) {
	char* FileName_String;
	printf("!!!Hello World!!!"); /* prints !!!Hello World!!! */

	//Parse Command Line Args
	for (int i = 1; i < argc; i++)
	{
		if(0 == strcmp(ADD_OPT, argv[i]))AddFlag =1;
	    else if(0 == strcmp(MUL_OPT, argv[i]))MulFlag = 1;
	    else {
	    	fprintf(stderr, "Command line option: %s\n", argv[i]);
	    	FileName_String = argv[i];
		}
	}
	fprintf(stderr, "File name from command argument: %s\n", FileName_String);
	char * path = getenv(_PATH);
	int Buffer_Length;
	Buffer_Length = strlen(_PATH_CURRENT_DIR) + strlen(_PATH_SEP) + strlen(path) + 1;
	char buf[Buffer_Length];
	char buf2[strlen(_PATH_CURRENT_DIR) + strlen(_PATH_SEP) + strlen(path) + 1];

	strcpy(buf,_PATH_CURRENT_DIR);
	strcat(buf,_PATH_SEP);
	strcat(buf,path);
	fprintf(stderr, "path=%s\n",buf);

	setenv(_PATH, buf, 1);
	fprintf(stderr, "path=%s\n", getenv(_PATH));


/*
	FILE* FP;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    FP = fopen("/etc/motd", "r");
    if (FP == NULL)
        exit(EXIT_FAILURE);
    while ((read = getline(&line, &len, FP)) != -1) {
        printf("Retrieved line of length %zu :\n", read);
        printf("%s", line);
    }
    fclose(FP);
*/
	return EXIT_SUCCESS;
}
