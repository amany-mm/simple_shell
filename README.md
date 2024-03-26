# simple_shell

A simple UNIX command interpreter.

## Resources
* [Unix shell](https://en.wikipedia.org/wiki/Unix_shell)
* [Thompson shell](https://en.wikipedia.org/wiki/Thompson_shell)
* [Ken Thompson](https://en.wikipedia.org/wiki/Ken_Thompson)
* man or help: `sh` (Run sh as well)
  
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
* OS: Ubuntu
* Compiler: gcc
* Style guidelines: [Betty style](https://github.com/alx-tools/Betty/wiki)
