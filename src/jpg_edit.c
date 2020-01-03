#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "jpg_edit.h"

char* jpg_edit_parse_argv(int argc, char** argv, char* filename)
{
  // Parse argv
  int opt;
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
          return NULL;
        }
        else
        {
          printf("\nCorrect usage: ./test -f <filename>\n\nExiting...\n\n");
          return NULL;
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
      return NULL;
    }
    else
    {
      filename = "test.jpg";
      printf("\nOutput filename is set to '%s'\n", filename);
    }
  }
  // Ensure the filename follows the format xxx.jpg
  else
  {
    for(int i = 0; i <= strlen(filename); i++)
    {
      if(filename[i] == '.' || filename[i] == '\0')
      {
        if(i == 0)
        {
          printf("No filename before '.jpg' extension\n");
          return NULL;
        }
        else if(
          strlen(filename) >= i+4 &&
          filename[i+1] == 'j' &&
          filename[i+2] == 'p' &&
          filename[i+3] == 'g' &&
          filename[i+4] == '\0')
        {
          // do nothing, the filename follows the format correctly
          break;
        }
        else
        {
          printf("\nThe filename must follow the format 'xxx.jpg'.  \nExiting...\n\n");
          return NULL;
        }
      }
    }
  }
  return filename;
}

void jpg_edit_read_image()
{

}

void jp_edit_write_image()
{

}
