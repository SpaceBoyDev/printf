_This project has been created as part of the 42 curriculum by darmarti_

# ft_printf

## Description

`ft_printf` is a custom implementation of the C standard library `printf`
function. It uses variadic arguments to format and print data to the standard
output while returning the number of characters written.

The project is focused on variadic functions, formatted output, type
conversion, recursion, and static library creation.

## Supported conversions

The implementation supports the required conversions:

| Conversion | Description |
| --- | --- |
| `%c` | Prints a character |
| `%s` | Prints a string |
| `%p` | Prints a pointer in hexadecimal format |
| `%d` | Prints a decimal integer |
| `%i` | Prints an integer |
| `%u` | Prints an unsigned decimal integer |
| `%x` | Prints a hexadecimal number in lowercase |
| `%X` | Prints a hexadecimal number in uppercase |
| `%%` | Prints a percent sign |

## Function prototype

```c
int ft_printf(const char *format, ...);
```

## Compilation

Build the static library with the provided `Makefile`:

```bash
make
```

This creates `libftprintf.a`. The available targets are:

```bash
make        # Build the library
make clean  # Remove object files
make fclean # Remove object files and the library
make re     # Rebuild everything
```

## Usage

Include the header and link the library when compiling your program:

```c
#include "ft_printf.h"

int main(void)
{
	ft_printf("Hello, %s! Number: %d\n", "42", 42);
	return (0);
}
```

Compile it from the project directory:

```bash
cc -Wall -Wextra -Werror example.c -L. -lftprintf -I. -o example
./example
```

`main_printf.c` contains a local comparison between `printf` and
`ft_printf`, including their returned character counts. It can be compiled
after building the library with:

```bash
cc -Wall -Wextra -Werror main_printf.c -L. -lftprintf -I. -o main_printf
./main_printf
```

## Files

- `ft_printf.c` — format parsing and conversion selection.
- `ft_printcharacters.c` — character and string output.
- `ft_printnumbers.c` — integer, unsigned, hexadecimal, and pointer output.
- `ft_printf.h` — public function prototype and declarations.
- `Makefile` — static library build rules.
- `main_printf.c` — local test program.

## Resources

- `printf(3)` — reference behavior for formatted output.
- `stdarg.h` — variadic argument handling with `va_list`.
- `write(2)` — writing output to the standard output.
- `ar(1)` — creating the static library.
- 42 project subject: **ft_printf**.

