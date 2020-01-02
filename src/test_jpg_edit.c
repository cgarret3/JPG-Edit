#include <unistd.h>
#include <stdio.h>
#include "jpg_edit.h"

int main(int argc, char** argv)
{
  // Parse argv
  int opt;
  char* filename = NULL;

  while((opt = getopt(argc, argv, "f:")) != -1)
  {
    switch(opt)
    {
      case 'f':
        filename = optarg;
        break;
      case '?':
        if(optopt == 'f')
        {
          printf("\nMissing filename after argument -- f");
        }
        else
        {
          printf("\nCorrect usage: ./test -f <filename>\n\nExiting...\n\n");
          return 0;
        }
        break;
     }
  }

  // Ensure the filename is set
  if(filename == NULL)
  {
    char user_answer = 'o';
    while(user_answer != 'y' && user_answer != 'Y' && user_answer != 'n' && user_answer != 'N')
    {
      printf("\nDefault filename is 'test.jpg'\nContinue with this filename? (y/n) ");
      scanf("%c", &user_answer);
    }
    if(user_answer == 'n' || user_answer == 'N')
    {
      printf("\nExiting...\n\n");
      return 0;
    }
    else
    {
      filename = "test.jpg";
    }
  }

  /*
    TODO: Ensure filename follows the format xxx.jpg
  */



  return 0;
}
