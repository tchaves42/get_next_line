# get_next_line
This project is part of the curriculum at the 42 school and aims to develop a function that reads lines from a text file, one at a time when called. The function should return the next line with each call until all lines have been read. The project helps students develop skills in file manipulation, dynamic memory allocation, and working with pointers in the C language.

## Objectives
- Read and understand the project's prompt.
- Implement a function called get_next_line that reads one line at a time from a text file.
- Use dynamic memory allocation to store the read lines.
- Manage reading multiple lines from the same file.
- Handle potential errors and ensure the release of allocated resources.

## Install

```sh
git clone https://github.com/tchaves42/get_next_line.git
```

## Usage

1. Inside project dir create a text file (`file.txt`)

```
Never gonna give you up
Never gonna let you down
Never gonna run around and desert you
```

2. Create a `main.c` file

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	int	fd;
	fd = open("file.txt", O_RDONLY);
	printf("%s", get_next_line(fd)); // Never gonna give you up
	printf("%s", get_next_line(fd)); // Never gonna let you down
	printf("%s", get_next_line(fd)); // Never gonna run around and desert you
	close(fd);
}
```

## Run

```sh
 gcc get_next_line.c get_next_line.h get_next_line_utils.c main.c && ./a.out
```
