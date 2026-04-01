# _printf

A custom implementation of the C standard library `printf` function, developed as part of the Holberton School curriculum. This project demonstrates a deep understanding of variadic functions, formatted output, and low-level C programming.

---

## Table of Contents

- [Description](#description)
- [Requirements](#requirements)
- [Compilation](#compilation)
- [How It Works](#how-it-works)
- [Flowchart](#flowchart)
- [Supported Conversion Specifiers](#supported-conversion-specifiers)
- [Functions](#functions)
- [Usage Examples](#usage-examples)
- [Return Value](#return-value)
- [Edge Cases](#edge-cases)
- [Authors](#authors)

---

## Description

`_printf` is a custom recreation of the C standard library function `printf`. It writes formatted output to stdout based on a format string that can contain plain characters and conversion specifiers. This implementation was built from scratch using only a limited set of authorized functions, without relying on the standard library's `printf` or `sprintf`.

---

## Requirements

- Ubuntu 20.04 LTS
- GCC compiler
- Compilation flags: `-Wall -Werror -Wextra -pedantic -std=gnu89`
- Code follows the [Betty](https://github.com/alx-tools/Betty) style guide
- No global variables
- No more than 5 functions per file

---

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c -o printf
```

---

## How It Works

`_printf` reads through the format string one character at a time:

1. If the current character is **not** `%`, it is written directly to stdout.
2. If the current character **is** `%`, the next character is read to identify the conversion specifier.
3. The specifier is passed to `handle_specifier`, which calls the appropriate print function.
4. The total number of characters printed is tracked and returned at the end.

---

## Flowchart

```
+-------------------------+
|   _printf(format, ...)  |
+-------------------------+
            |
            v
+-------------------------+
|  format == NULL?        |
|  Yes → return -1        |
+-------------------------+
            |
            v
+-----------------------------+
| Iterate through format string|
+-----------------------------+
            |
     +------+------+
     |             |
     v             v
+----------+   +----------+
| char != %|   | char == % |
| _putchar  |   +----------+
+----------+        |
                    v
            +----------------+
            | Read next char  |
            +----------------+
                    |
          +---------+---------+
          |         |         |
          v         v         v
       +-----+   +-----+   +-----+
       | %c  |   | %s  |   | %d  |
       +-----+   +-----+   | %i  |
          |         |      +-----+
          v         v         |
     print_char  print_str  print_int
                           (with neg
                            support)
                    |
                    v
            +----------------+
            | Unknown spec?   |
            | Print % + char  |
            +----------------+
                    |
                    v
       +---------------------------+
       | Return total chars printed |
       +---------------------------+
```

---

## Supported Conversion Specifiers

| Specifier | Description |
|-----------|-------------|
| `%c` | Prints a single character |
| `%s` | Prints a string of characters |
| `%%` | Prints a literal `%` character |
| `%d` | Prints a decimal (base 10) integer |
| `%i` | Prints an integer in base 10 |

---

## Functions

### `printf.c`

| Function | Description |
|----------|-------------|
| `_printf` | Parses the format string and writes output to stdout. Delegates conversion specifiers to `handle_specifier`. Returns the total number of characters printed or `-1` on error. |

### `handlers.c`

| Function | Description |
|----------|-------------|
| `_putchar` | Writes a single character to stdout using `write`. Returns 1 on success, -1 on error. |
| `print_char` | Retrieves a `char` argument from `va_list` and prints it. Handles `%c`. |
| `print_string` | Retrieves a `char *` argument from `va_list` and prints it. Prints `(null)` if the pointer is NULL. Handles `%s`. |
| `print_percent` | Prints a literal `%` character. Handles `%%`. |
| `print_integer` | Retrieves an `int` from `va_list`, handles the negative sign, and calls `print_integer_helper`. Handles `%d` and `%i`. |
| `print_integer_helper` | Recursively breaks down an integer and prints each digit. |
| `handle_specifier` | Matches the conversion specifier to the correct print function. For unknown specifiers, prints `%` followed by the character. |

---

## Usage Examples

```c
#include "main.h"

int main(void)
{
    int len;

    _printf("Hello, %s!\n", "world");
    _printf("Character: %c\n", 'A');
    _printf("Percent sign: %%\n");
    _printf("Positive integer: %d\n", 42);
    _printf("Negative integer: %i\n", -762534);
    len = _printf("This sentence has %d characters.\n", 38);
    _printf("Previous line printed %d characters.\n", len);
    return (0);
}
```

**Output:**
```
Hello, world!
Character: A
Percent sign: %
Positive integer: 42
Negative integer: -762534
This sentence has 38 characters.
Previous line printed 38 characters.
```

---

## Return Value

- Returns the **total number of characters printed** to stdout (excluding the null terminator).
- Returns **-1** if the format string is `NULL`.

---

## Edge Cases

| Situation | Behavior |
|-----------|----------|
| `format` is `NULL` | Returns `-1` |
| `%s` with NULL pointer | Prints `(null)` |
| Unknown specifier (e.g. `%r`) | Prints `%` followed by the unknown character |
| `%%` | Prints a single `%` |
| Negative integers with `%d`/`%i` | Prints `-` sign followed by the number |

---

## Authors

- **Xander X. Roldan Villarrubia** — [GitHub](https://github.com/XXRV0423)
- **Alejandro J. Colombani** — [GitHub](https://github.com/alejandrojcolombani)

---

*This project was developed as part of the [Holberton School](https://www.holbertonschool.com/) software engineering curriculum.*
