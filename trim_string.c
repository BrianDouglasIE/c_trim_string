#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>

char *empty_string()
{
  char *str = malloc(1);
  if(!str) return nullptr;
  str[0] = '\0';
  return str;
}

char *ltrim_string(char *str)
{
  if(!str) return nullptr;

  size_t len = strlen(str);
  if(!len) return empty_string();

  size_t start = 0;
  while(start < len && isspace(str[start])) start++;

  if(start >= len) return empty_string();

  size_t new_size = len - start;
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
  if(!len) return empty_string();

  size_t end = len - 1;
  while(end && isspace(str[end])) end--;

  if(0 >= end) return empty_string();

  size_t new_size = end + 1;
  char *result = malloc(new_size);
  if (!result) return nullptr;

  memcpy(result, str, new_size);
  result[new_size] = '\0';

  return result;
}

char *trim_string(char *str)
{
  if (!str) return nullptr;

  size_t len = strlen(str);
  if(!len) return empty_string();

  size_t start = 0;
  while(isspace(str[start])) start++;
  
  size_t end = len - 1;
  if(start >= end) return empty_string();
  while(end && isspace(str[end])) end--;

  size_t new_size = end - start + 1;
  char *result = malloc(new_size + 1);
  if(!result) return nullptr;

  memcpy(result, str + start, new_size);
  result[new_size] = '\0';

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

  // empty strings
  test_str = ltrim_string("    ");
  assert(test_str && 0 == strcmp("", test_str));
  free(test_str);

  test_str = ltrim_string("");
  assert(test_str && 0 == strcmp("", test_str));
  free(test_str);

  test_str = rtrim_string("    ");
  assert(test_str && 0 == strcmp("", test_str));
  free(test_str);

  test_str = rtrim_string("");
  assert(test_str && 0 == strcmp("", test_str));
  free(test_str);

  test_str = trim_string("    ");
  assert(test_str && 0 == strcmp("", test_str));
  free(test_str);

  test_str = trim_string("");
  assert(test_str && 0 == strcmp("", test_str));
  free(test_str);

  assert(trim_string(nullptr) == nullptr);

  return 0;
}
