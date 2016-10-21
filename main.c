#include <stdio.h>
#include "takuzu.h"

int main(int argc, char **argv)
{
  if(argc != 2) {
    printf("Provide N\n");
    return 1;
  }
  
  takuzuString(atoi(argv[1]));

  return 0;
}
