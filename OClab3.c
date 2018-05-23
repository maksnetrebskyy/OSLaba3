#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	FILE *file, *pipe_fp;
	char readbuf[20];
	file = fopen("file.txt", "r");
	if (file == NULL) {
	   perror("fopen");
	   exit(1);
	}
	pipe_fp = popen("cat","w");
	if (pipe_fp == NULL) {
	   perror("popen");
	   exit(1);
	}
	do {
	   fgets(readbuf,20,file);
	   if (feof(file)) break;
	   fputs(readbuf, pipe_fp);
	}
	while (!feof(file));
	fclose(file);
	pclose(pipe_fp);
	return 0;

}
