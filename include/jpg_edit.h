#ifndef JPG_EDIT_H
#define JPG_EDIT_H

// Takes the argc, argv and a char* filename.
// Returns 0 on correct operation
char* jpg_edit_parse_argv(int argc, char** argv, char* filename);

void jpg_edit_read_image();

void jpg_edit_write_image();

#endif//JPG_EDIT_H
