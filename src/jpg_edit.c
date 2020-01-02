#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "jpg_edit.h"

char* jpg_edit_parse_argv(int argc, char** argv, char* filename)
{
  printf("%s\n", argv[0]);//////////////////////////////////////////////////////

  // Parse argv
  int opt;
  char user_answer;

  while((opt = getopt(argc, argv, "f:")) != -1)
  {
    switch(opt)
    {
      case 'f':
        filename = optarg;
        printf("%s\n", filename);///////////////////////////////////////////////
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

  // Ensure the filename is/has been set
  if(filename == NULL)
  {
    printf("\nNo filename specified. Set output filename to 'test.jpg'? \n(Press 'y' for 'yes' or any other key to quit) ");
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
    printf("filename != NULL\n");///////////////////////////////////////////////
    for(int i = 0; i <= strlen(filename); i++)
    {
      if(filename[i] == '.' || filename[i] == '\0')
      {
        if(
          strlen(filename) >= i+4 &&
          filename[i+1] == 'j' &&
          filename[i+2] == 'p' &&
          filename[i+3] == 'g' &&
          filename[i+4] == '\0')
        {
          // do nothing, the filename follows the format correctly
          printf("Correct Format\n");///////////////////////////////////////////
        }
        else
        {
          printf("\nThe filename must follow the format 'xxx.jpg'.  End this filename in '.jpg'? \n(Press 'y' for 'yes' or any other key to quit) ");
          scanf("%c", &user_answer);
          if(user_answer == 'y' || user_answer == 'Y')
          {
            // I choose not to sprintf directly onto filename in case
            // of memory overwrite (unlikely but still...) so it's
            // a bit verbose

            char tmp[i+4];
            int j;
            for(j = 0; j < i; j++)
            {
              tmp[j] = filename[j];
            }

            tmp[j] = '.';
            tmp[j+1] = 'j';
            tmp[j+2] = 'p';
            tmp[j+3] = 'g';
            tmp[j+4] = '\0';
            filename = tmp;

            printf("The filename has been set to '%s'\n", filename);
            break;
          }
          else
          {
            printf("\nExiting...\n\n");
            return 0;
          }
        }
      }
    }
  }

  return 0;
}

void jpg_edit_read_image()
{

}

void jp_edit_write_image()
{

}
