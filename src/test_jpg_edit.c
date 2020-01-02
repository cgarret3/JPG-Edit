//#include <unistd.h>
#include <stdio.h>
//#include <string.h>
#include "jpg_edit.h"

int main(int argc, char** argv)
{
  printf("TODO: Not yet implemented.\n");
  return(-1);

  
  char* filename = NULL;
  if((filename = jpg_edit_parse_argv(argc, argv, filename)))
  {
    perror("Issue encountered parsing argv: ");
    return(-1);
  }

  printf("%s", filename);




  return 0;
}
