
#include <string.h>
#include <assert.h>
#include "path-join.h"

int
main(void) {
  assert(0 == strcmp("/foo/bar/baz", path_join("/foo/bar", "baz")));
  assert(0 == strcmp("/foo/bar/baz", path_join("/foo/bar/", "baz")));
  assert(0 == strcmp("/foo/bar/baz", path_join("/foo/bar", "/baz")));
  assert(0 == strcmp("/foo/bar/baz", path_join("/foo/bar/", "/baz")));
  assert(0 == strcmp("/foo/bar/baz.c", path_join("/foo/bar", "baz.c")));
  return 0;
}
