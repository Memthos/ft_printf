*This project has been created as part of the 42 curriculum by mperrine.*

## Description

`ft_printf` is a project that recreates the standard `printf` function from the C library.

The function supports the following specifiers:
- `%c` - Character
- `%s` - String
- `%p` - Pointer address
- `%d` - Decimal (base 10) number
- `%i` - Integer (base 10)
- `%u` - Unsigned decimal number
- `%x` - Hexadecimal (lowercase)
- `%X` - Hexadecimal (uppercase)
- `%%` - Percent sign

The bonus part allows the use of all the sub-specifiers of the original function :

**Flags :**
- `-` - Left justify within the given field
- `+` - Forces the result to be preceded by a plus or minus sign
- `(space)` - If no sign is written, a blank space is inserted before the value.
- `#` - For `x` and `X`, if their value is not 0, it will be preceded by `0x` or `0X` respectively.
- `0` - Left-pads the number with zeroes instead of spaces

**Width :**
- `(number)` - Minimum number of characters to be printed. If the number of characters is shorter than this number, the result is padded with spaces. The value is not truncated even if the result is larger
- `*` - The width is not specified in the format string, but as an additional integer argument preceding the argument that has to be formatted

**Precision :**
- `.(number)` - For `d`, `i`, `u`, `x` and `X`, specifies the minimum number of digits to be written. If the number of characters is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. For `s` this is the maximum number of characters to be printed. If no number follow the `.`, a precision of 0 is assumed
- `.*` - The precision is not specified in the format string, but as an additional integer argument preceding the argument that has to be formatted

## Implementation

For the mandatory part, the function loops through the format and writes all characters encountered. Whenever a `%` is found, the next character is checked to determine if it is a valid specifier. If it is, the corresponding `va_arg` is retrieved and printed; otherwise the `%` and the character are printed as-is.

For the bonus part, sub-specifiers are also parsed whenever a `%` is encountered. The `va_arg` result is then converted to a `char *` and formatted according to the given flags before being printed.

## Instructions

A `Makefile` is provided to compile the project.

**Build**
```bash
make
make bonus
```

**Clean**
```bash
make clean
make fclean
```

**Rebuild**
```bash
make re
```

## Usage

Include the header in your C file:
```c
#include "ft_printf.h"
```
or
```c
#include "ft_printf_bonus.h"
```

Use it like the standard printf:
```c
ft_printf("Hello %s! The number is %d\n", "world", 42);
```

Then compile your project like this :
```bash
gcc -Wall -Werror -Wextra *.c libftprintf.a
```

## Resources

AI was used to better understand the bonus flags and to check spelling errors in this readme

This [website](https://cplusplus.com/reference/cstdio/printf/) was used to look at the function details
