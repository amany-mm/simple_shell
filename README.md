# simple_shell

A simple UNIX command interpreter.

## Features
TODO

## Compilation
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Testing

**Interactive Mode**
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

**Non Interactive Mode**
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

## Environment
* Language: C
* OS: Ubuntu 18.04.6 LTS
* Compiler: gcc 7.5.0
* Style guidelines: [Betty style](https://github.com/alx-tools/Betty/wiki)