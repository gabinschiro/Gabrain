# Gabrain

Welcome to the **Gabrain**, a robust and extended interpreter for the minimalist programming language **Brainfuck**. This project adds custom commands and provides a user-friendly way to execute and debug Brainfuck scripts.

---

## Features

- **Standard Brainfuck Commands**:
  - `>`: Increment the data pointer.
  - `<`: Decrement the data pointer.
  - `+`: Increment the byte at the data pointer.
  - `-`: Decrement the byte at the data pointer.
  - `.`: Output the byte at the data pointer as a character.
  - `,`: Input a character and store it at the data pointer.

- **Enhanced Commands**:
  - `^`: Convert the byte to uppercase if it is a lowercase ASCII letter.
  - `_`: Convert the byte to lowercase if it is an uppercase ASCII letter.
  - `@`: Reset the byte at the data pointer to zero.
  - `~`: Perform a bitwise NOT operation on the byte at the data pointer.
  - `#`: Output the current value of the byte as an integer.
  - `!`: Exit the program immediately.

- **Error Handling**:
  - Detects and reports memory out-of-bounds access.
  - Alerts the user about failed program loading or memory allocation issues.

---

## Usage

### Prerequisites

- A C compiler (e.g., GCC or Clang).
- A Makefile (included in the project directory).
- A Brainfuck script file (`.bf`).

### Compilation

To compile the interpreter, use the provided `Makefile`. Simply run:

```bash
make
```

This will generate an executable named `brainfuck`.

### Running a Brainfuck Script

Execute the interpreter with the Brainfuck script file as an argument:

```bash
./gabrain <brainfuck_script.bf>
```

### Cleaning Up

To remove the compiled executable and other generated files, use:

```bash
make clean
```

### Example

Consider the following Brainfuck script (`hello_world.bf`):

```brainfuck
+[----->+++<]>+.---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.
```

Run it with:

```bash
./gabrain hello_world.bf
```

---

## Custom Commands in Detail

| Command | Description                                             |
|---------|---------------------------------------------------------|
| `>`     | Moves the data pointer to the right.                   |
| `<`     | Moves the data pointer to the left.                    |
| `+`     | Increments the byte at the data pointer.               |
| `-`     | Decrements the byte at the data pointer.               |
| `.`     | Outputs the byte as a character.                       |
| `,`     | Inputs a character into the byte at the data pointer.  |
| `^`     | Converts lowercase ASCII letters to uppercase.         |
| `_`     | Converts uppercase ASCII letters to lowercase.         |
| `@`     | Resets the byte at the data pointer to `0`.            |
| `~`     | Applies a bitwise NOT operation to the byte.           |
| `!`     | Exits the program immediately.                         |

---

## Error Handling

- **Memory Out of Bounds**:
  - Ensures the data pointer does not exceed allocated memory.
- **Program Loading**:
  - Checks if the provided script file is readable and valid.
- **Graceful Exits**:
  - Handles errors with informative messages to aid debugging.

---

## License

This Brainfuck Interpreter Enhanced is open-source and free to use. Contributions are welcome!
