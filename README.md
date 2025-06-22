# max-vowel-words-c

## Overview

This C program analyzes a given line of text (up to 255 characters) and finds
all the words that contain the 
**maximum number of Latin vowels** (`a`, `e`, `i`, `o`, `u`, `y`). 
It uses a simple text-based UI using windows.h and custom console functions
such as `GotoXY`, `frame`, and `Sleep`.

## Features

- Menu interface with a keyboard navigation
- Windows-only UI using `windows.h`, `conio.h`, and `winuser.h`
- Checks each word for Latin vowels and displays those with the maximum count
- Handles invalid input and edge cases (for example, no vowels case)
- Title and requirements pages for lab context


## Requirements

- **Windows OS**
- Compiled with GCC (MinGW) or another Windows-compatible C compiler
- Terminal/console capable of displaying extended ASCII (frame characters)


## Running

A compiled binary `main.exe` is included in this repository.
To run:

```cmd
main.exe
```
