#ifndef __MAIN_H__
#define __MAIN_H__

#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int printMenu();

int getInput();

int deleteStudent();

int updateStudent();

int searchStudent();

int getInput(char *buf, size_t size) {
  assert(size > 0 && size <= INT32_MAX);
  size_t i = 0;
  int8_t c;

  while ((c = getchar()) != EOF && c != '\n') {
    if (i + 1 < size) {
      buf[i++] = c;
    }
  }
  buf[i] = '\0';
  if (i == 0) {
    return EOF;
  }

  return i;
}

#endif
