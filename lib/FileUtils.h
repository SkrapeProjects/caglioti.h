#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <stdio.h>

void file_Read(char file[]);
void file_Read(FILE *file);
void file_Write(char file[]);
void file_Write(FILE *file);
void file_Find(char str[]);

#endif