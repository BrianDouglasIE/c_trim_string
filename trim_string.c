#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>

char *ltrim_string(char *str)
{
  if(!str) return nullptr;

  size_t len = strlen(str);
  if(!len) return nullptr;

  size_t start = 0;
  while(start < len && isspace(str[start])) start++;

  if(start >= len) return nullptr;

  size_t new_size = len - start + 1;
  char *result = malloc(new_size);
  if (!result) return nullptr;

  memcpy(result, str + start, new_size);
  result[new_size] = '\0';

  return result;
}

char *rtrim_string(char *str)
{
  if(!str) return nullptr;

  size_t len = strlen(str);
  if(!len) return nullptr;

  size_t end = len - 1;
  while(end && isspace(str[end])) end--;

  if(0 >= end) return nullptr;

  size_t new_size = end + 1;
  char *result = malloc(new_size + 1);
  if (!result) return nullptr;

  memcpy(result, str, new_size);
  result[new_size] = '\0';

  return result;
}

char *trim_string(char *str)
{
    if (!str) return nullptr;
    
    char *ltrimmed = ltrim_string(str);
    if(!ltrimmed) return nullptr;

    char *result = rtrim_string(ltrimmed);
    free(ltrimmed);

    if(!result) return nullptr;
    
    return result;
}

int main(void)
{
  // ltrim
  char *test_str = ltrim_string("   hello   ");
  assert(test_str && 0 == strcmp("hello   ", test_str));
  free(test_str);

  test_str = ltrim_string("\r\nhello\n");
  assert(test_str && 0 == strcmp("hello\n", test_str));
  free(test_str);

  // rtrim
  test_str = rtrim_string("   hello   ");
  assert(test_str && 0 == strcmp("   hello", test_str));
  free(test_str);

  test_str = rtrim_string("\r\nhello\n");
  assert(test_str && 0 == strcmp("\r\nhello", test_str));
  free(test_str);

  // trim
  test_str = trim_string("   hello   ");
  assert(test_str && 0 == strcmp("hello", test_str));
  free(test_str);

  test_str = trim_string("\r\nhello\n");
  assert(test_str && 0 == strcmp("hello", test_str));
  free(test_str);

  return 0;
}
