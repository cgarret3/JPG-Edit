#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "jpg_edit.h"

int main(int argc, char** argv)
{
  // Parse argv
  int opt;
  char* filename = NULL;
  char user_answer;

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
    printf("\nNo filename specified. Set output filename to 'test.jpg'? (y/n) ");
    scanf("%c", &user_answer);
    if(user_answer != 'y' && user_answer != 'Y')
    {
      printf("\nExiting...\n\n");
      return 0;
    }
    else
    {
      filename = "test.jpg";
      printf("Output filename is set to '%s'\n\n", filename);
    }
  }
  // Ensure the filename follows the format xxx.jpg
  else
  {
    printf("\nTODO: Not yet implemented\n\n");
    return -1;

    for(int i = 0; i < strlen(filename); i++)
    {
      if(filename[i] == '.' && filename[i] == '\0')
      {
        if(
          filename[i+1] == 'j' &&
          filename[i+2] == 'p' &&
          filename[i+3] == 'g' &&
          filename[i+4] == '\0')
        {
          // do nothing
        }
        else
        {
          printf("\nThe filename must follow the format 'xxx.jpg'.  End this filename in '.jpg'? (y/n) ");
          scanf("%c", &user_answer);
          if(user_answer == 'y' || user_answer == 'Y')
          {
            char tmp[i+4];
            int j;
            for(j = 0; j < i; j++)
            {
              tmp[j] = filename[j];
            }
            tmp[j+1] = '.';
            tmp[j+2] = 'j';
            tmp[j+3] = 'p';
            tmp[j+4] = 'g';
            tmp[j+5] = '\0';
            filename = tmp;
            printf("The filename has been set to '%s'", filename);
          }
          else
          {
            printf("\nExiting...\n\n");
          }
        }
      }
    }
  }




  return 0;
}
