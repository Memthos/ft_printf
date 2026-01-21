*This project has been created as part of the 42 curriculum by mperrine.*

## Description

`ft_printf` is a project that recreates the standard `printf` function from the C library.

The function supports the following conversions:
- `%c` - Character
- `%s` - String
- `%p` - Pointer address
- `%d` - Decimal (base 10) number
- `%i` - Integer (base 10)
- `%u` - Unsigned decimal number
- `%x` - Hexadecimal (lowercase)
- `%X` - Hexadecimal (uppercase)
- `%%` - Percent sign

## Instructions

Include the header in your C file:
```c
#include "ft_printf.h"
```

Use it like the standard printf:
```c
ft_printf("Hello %s! The number is %d\n", "world", 42);
```

## Resources

This project was developed without the use of any AI tools.

The terminal was used as an example to observe the function behavior.
