//Libaries
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
#include <tchar.h>
#include <windows.h>

//Constants
#define VERBOSE_OPT "-Verbose"
#define DEBUG_OPT "-Debug"
#define ADD_OPT "-Add"
#define MUL_OPT "-Mul"
#define	BUFSIZE 256


//Global Variables
static unsigned char AddFlag = 0;
static unsigned char MulFlag = 0;
static const char delimiters[4] = "  \t\n";

//Main Function
int main(int argc, char** argv) {
	//Parse Command Line Args
	char* FileName_String;
	for (int i = 1; i < argc; i++)
	{
		if(0 == strcmp(ADD_OPT, argv[i]))AddFlag =1;
	    else if(0 == strcmp(MUL_OPT, argv[i]))MulFlag = 1;
	    else {
	    	printf("Command line option: %s\n", argv[i]);
	    	FileName_String = argv[i];
		}
	}

	//Get current working Directory
	TCHAR Buffer[256];
	GetCurrentDirectory(BUFSIZE, Buffer);
	printf("Current Working Directory: %s \n", Buffer);
	strcat(Buffer,"\\");
	strcat(Buffer,FileName_String);
	printf("File name and path: %s \n", Buffer);

	//Find and open file
	FILE* FP;
    char line[256];
    FP = fopen(Buffer, "r");
    if (FP == NULL) {
    	printf("File Pointer is set to NULL!!!!");
        exit(EXIT_FAILURE);
    }

    //Add Function
    if(AddFlag==1){
        int linenumber = 1;
        int num1, num2, ans;
        while (fgets(line, 256, FP) != NULL){
        	printf("%i: ", linenumber);
			printf("Retrieved line: %s", line);
			linenumber++;
        	num1 = atoi(strtok(line, delimiters));
        	num2 = atoi(strtok(NULL, delimiters));
        	ans = atoi(strtok(NULL, delimiters));
        	if(num1 + num2 != ans){
        		printf( "    Failed Test %i + %i != %i \n", num1, num2, ans);
        	}
        }
    }

    //Square Function
    else if(MulFlag==1){
    	int linenumber = 1;
			int num1, ans;
			while (fgets(line, 256, FP) != NULL){
				printf("%i: ", linenumber);
				printf("Retrieved line: %s", line);
				linenumber++;
				num1 = atoi(strtok(line, delimiters));
				ans = atoi(strtok(NULL, delimiters));
				if(num1 * num1 != ans){
					printf( "    Failed Test %i + %i != %i \n", num1, num1, ans);
				}
			}
    }
    else {
    	fprintf(stderr, "No Flag Set!!!");
    	fclose(FP);
    	exit(EXIT_SUCCESS);
    }
    fclose(FP);

	return EXIT_SUCCESS;
}


