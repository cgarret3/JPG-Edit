//#include <unistd.h>
#include <stdio.h>
//#include <string.h>
#include "jpg_edit.h"

int main(int argc, char** argv)
{
  char* filename = NULL;
  if((filename = jpg_edit_parse_argv(argc, argv, filename)) != NULL)
  {
    printf("\n%s\n", filename);
  }
  else
  {
    return 0;
  }

  return 0;
}
