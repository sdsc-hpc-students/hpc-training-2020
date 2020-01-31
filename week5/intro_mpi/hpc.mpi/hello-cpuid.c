/* 
 * File: hello-cpuid.c by Mary Thomas, 2/12/15
 *             based on hello.c by James Otto, 1/31/11 f
 * used to get informationa about the node.
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/*
* This code is adapted from an example at:
* http://brokestream.com/procstat.html
*/

int get_cpu_id()
{
    /* Get the the current process' stat file from the proc filesystem */
    FILE* procfile = fopen("/proc/self/stat", "r");
    long to_read = 8192;
    char buffer[to_read];
    int read = fread(buffer, sizeof(char), to_read, procfile);
    fclose(procfile);

    // Field with index 38 (zero-based counting) is the one we want
    char* line = strtok(buffer, " ");
    int i; 
    for (i = 1; i < 38; i++)
    {
        line = strtok(NULL, " ");
    }

    line = strtok(NULL, " ");
    int cpu_id = atoi(line);
    return cpu_id;
}



int main(void)
{
  char cptr[100];
  int cpuid;

  gethostname(cptr,100);
  cpuid = get_cpu_id();
  printf("hello, world from node: %s, core: %d\n", cptr, cpuid);

  return 0;
}
