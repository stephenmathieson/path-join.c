
#ifndef __PATH_H__
#define __PATH_H__ 1

#include <stdlib.h>
#include <string.h>


int
path_split (char *path, char *parts[], char *delimiter) {
  char *pch;
  int i = 0;
  pch = strtok(path, delimiter);

  while ((NULL != pch)) {
    pch = strtok(NULL, delimiter);
    if (NULL == pch) break;
    parts[i++] = strdup(pch);
  }

  free(pch);
  return i;
}

#endif
