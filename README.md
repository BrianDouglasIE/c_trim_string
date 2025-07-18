# Trimming Strings

```c
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
```

