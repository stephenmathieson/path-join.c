
//
// path-join.c
//
// Copyright (c) 2013 Stephen Mathieson
// MIT licensed
//

#include <string.h>
#include <stdlib.h>
#include "str-copy.h"
#include "str-ends-with.h"
#include "str-starts-with.h"
#include "path-join.h"

#ifdef _WIN32
#define SEPERATOR   "\\"
#else
#define SEPERATOR   "/"
#endif

/*
 * Join `dir` with `file`
 */

char *path_join(char *dir, char *file) {
  int size = strlen(dir) + strlen(file) + 2;
  char *buf = malloc(size * sizeof(char));

  strcpy(buf, dir);

  // add the sep if necessary
  if (!str_ends_with(dir, SEPERATOR)) {
    strcat(buf, SEPERATOR);
  }

  // remove the sep if necessary
  if (str_starts_with(file, SEPERATOR)) {
    char *filecopy = str_copy(file);
    filecopy++;
    strcat(buf, filecopy);
  } else {
    strcat(buf, file);
  }

  return buf;
}
