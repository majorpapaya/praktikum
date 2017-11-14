# praktikum

## getting started

open terminal

```bash
cd Development
code .
```

ctrl + c clears the current line of code in the terminal
cmd + k resets the view of the terminal

## how to compile and debug c applications

example file -> praktium1/ex.c

first compile the written code...

```bash
gcc praktium1/ex.c -o praktikum1/ex.out
```

- if no failures, it is compiled. no debugging required.#
- if failures, they will appear in terminal.

fix it, recompile, and run the application you just wrote.

```bash
./praktikum1/ex.out
```

shorthand for quicker development

```bash
gcc praktium1/ex.c -o praktikum1/ex.out && ./praktikum1/ex.out
```

## saving changes to git

Using the Terminal:

```bash
git status
git add .
git commit -m "message goes here"
git push
```

Or you can optionally use the Github Desktop application which is more visual, easier to user for beginners.