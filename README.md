![Linux](https://cdn.comparitech.com/wp-content/uploads/2018/08/Linux-Shell-Getting-Started-1.jpg)
![issues](https://img.shields.io/github/issues/ChongLeangUENG/holbertonschool-simple_shell)
![forks](https://img.shields.io/github/forks/ChongLeangUENG/holbertonschool-simple_shell)
![stars](https://img.shields.io/github/stars/ChongLeangUENG/holbertonschool-simple_shell)
![license](https://img.shields.io/github/license/ChongLeangUENG/holbertonschool-simple_shell)
![Ubuntu](https://img.shields.io/badge/-Ubuntu%2020.04.4-orange)
![C language](https://img.shields.io/badge/-C%20language-yellow)
![Vim](https://img.shields.io/badge/-Vim-yellowgreen)
![simple_shell project](https://img.shields.io/badge/-simple__shell-blue)
![holbertonschool](https://img.shields.io/badge/-Holberton%20School-red)
![Linux](https://img.shields.io/badge/-Linux-lightgrey)

# simple_shell :
# a simple recreation of the command-line interpreter for the Unix-like operating system


## TABLE OF CONTENTS

- __[Description](https://github.com/ChongLeangUENG/holbertonschool-simple_shell#description)__
- __[Structure of the project](https://github.com/ChongLeangUENG/holbertonschool-simple_shell#structure-of-the-project)__
- __[Functionality](https://github.com/ChongLeangUENG/holbertonschool-simple_shell#functionality)__
- __[Requirements](https://github.com/ChongLeangUENG/holbertonschool-simple_shell#requirements)__
- __[Installation, compilation and running](https://github.com/ChongLeangUENG/holbertonschool-simple_shell#installation-compilation-and-running)__
- __[Some examples](https://github.com/ChongLeangUENG/holbertonschool-simple_shell#some-examples)__
- __[Credits](https://github.com/ChongLeangUENG/holbertonschool-simple_shell#credits)__
- __[License](https://github.com/ChongLeangUENG/holbertonschool-simple_shell#license)__

***

### DESCRIPTION

__*simple_shell*__ is a command-line interpreter that provides a command line user interface.

The simple_shell project has been inspired by the real shell written by __*Ken Thompson*__ in 1971 (the first version of it was called "the Thompson shell").

It controls the execution of the operating system using shell scripts, and allows users to do multiple limited tasks, by entering some commands. All users interact with this simple_shell by using a terminal emulator.

The goal of this project was to make us understand how the shell works by rewriting our own version.

***

### STRUCTURE OF THE PROJECT

- __*README.md*__ : informations about this repository

- __*AUTHORS*__ : contributors to this repository

- __*man_1_simple_shell*__ : manual page for the simple_shell

- __*shell.h*__ : header file including all the prototypes of functions used

- __*execve.c*__ : file which contains the function related to the commands executions

- __*freegrid.c*__ : file which contains the function that frees dimensional grids

- __*getenv.c*__ : file which contains the function that gets the environment variables

- __*getpath.c*__ : file which contains the function that prints the PATH variable environment

- __*printenv.c*__ : file which contains the function that prints the environment variables

- __*readcmd.c*__ : file which contains the function that reads a command input by the user, and displays it

- __*sign.c*__ : file which contains the signal program that permits to re-prompt

- __*split.c*__ : file which contains the function that tokenizes the string of a command

- __*splitenv.c*__ : file which contains the function that tokenizes the PATH variable environment

- __*struse.c*__ : file which contains functions that concatenates and compares strings that we need to use

- __*super_shell.c*__ : main file for compilation

- __*trim.c*__ : file which contains the function that trims, separates the string

For our codes, we used Betty style.
For more information, see [betty-style.pl](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl) and [betty-doc.pl](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl)

***

### FUNCTIONALITY

You can see below a list of all functions and system calls allowed for our project :
(We used some of them)

- ``access`` (man 2 access)
- ``chdir`` (man 2 chdir)
- ``close`` (man 2 close)
- ``closedir`` (man 3 closedir)
- ``execve`` (man 2 execve) ![used](https://img.shields.io/badge/-used-red)
- ``exit`` (man 3 exit) ![used](https://img.shields.io/badge/-used-red)
- ``_exit`` (man 2 _exit)
- ``fflush`` (man 3 fflush)
- ``fork`` (man 2 fork) ![used](https://img.shields.io/badge/-used-red)
- ``free`` (man 3 free) ![used](https://img.shields.io/badge/-used-red)
- ``getcwd`` (man 3 getcwd)
- ``getline`` (man 3 getline) ![used](https://img.shields.io/badge/-used-red)
- ``getpid`` (man 2 getpid)
- ``isatty`` (man 3 isatty) ![used](https://img.shields.io/badge/-used-red)
- ``kill`` (man 2 kill)
- ``malloc`` (man 3 malloc) ![used](https://img.shields.io/badge/-used-red)
- ``open`` (man 2 open)
- ``opendir`` (man 3 opendir)
- ``perror`` (man 3 perror) ![used](https://img.shields.io/badge/-used-red)
- ``read`` (man 2 read)
- ``readdir`` (man 3 readdir)
- ``signal`` (man 2 signal) ![used](https://img.shields.io/badge/-used-red)
- ``stat`` (__xstat) (man 2 stat)
- ``lstat`` (__lxstat) (man 2 lstat)
- ``fstat`` (__fxstat) (man 2 fstat)
- ``strtok`` (man 3 strtok) ![used](https://img.shields.io/badge/-used-red)
- ``wait`` (man 2 wait) ![used](https://img.shields.io/badge/-used-red)
- ``waitpid`` (man 2 waitpid)
- ``wait3`` (man 2 wait3)
- ``wait4`` (man 2 wait4)
- ``write`` (man 2 write) ![used](https://img.shields.io/badge/-used-red)

***

### REQUIREMENTS

simple_shell has been running with __*Ubuntu 20.04.4 LTS Linux version*__, and has been compiling with the GNU compiler collection __*GCC 9.4.0*__, with flags ``-Wall, -Werror, -Wextra, and -pedantic``.

***

### INSTALLATION, COMPILATION AND RUNNING

To get a representation of this project, you have to do these following steps :

- Clone the repository :``git clone "https://github.com/ChongLeangUENG/holbertonschool-simple_shell.git"``
- Go to the directory of this repository :``cd simple_shell``
- Compile it : ``gcc -Wall -Werror -Wextra -pedantic *.c -o hsh``
- Run this shell in interactive mode : ``prompt$ ./hsh``
- Either, run it in non-interactive mode : ``prompt$ echo "/bin/ls" | .hsh``

***

### SOME EXAMPLES

```
root@user-name:~/holbertonschool-simple_shell# ./hsh

$ (enter your command here, for example ->  ls)
$ AUTHORS  README.md  execve.c  freegrid.c  getenv.c  getpath.c  hack  hsh  man_1_simple_shell  pidmax.sh  printenv.c  readcmd.c  shell  shell.h  sign.c  split.c  splitenv.c  struse.c  super_shell.c  testingcode

$ pwd
$ /root/holbertonschool-simple_shell

$ ls -al
total 128
drwxr-xr-x  5 root root  4096 Aug  1 15:43 .
drwxr-xr-x 15 root root  4096 Aug  1 15:28 ..
drwxr-xr-x  8 root root  4096 Aug  1 15:43 .git
-rw-r--r--  1 root root   224 Jul 29 12:54 AUTHORS
-rw-r--r--  1 root root  6047 Aug  1 15:43 README.md
-rw-r--r--  1 root root   660 Jul 29 14:40 execve.c
-rw-r--r--  1 root root   277 Jul 29 14:40 freegrid.c
-rw-r--r--  1 root root   333 Jul 29 14:40 getenv.c
-rw-r--r--  1 root root   665 Jul 29 14:40 getpath.c
drwxr-xr-x  2 root root  4096 Jul 29 12:54 hack
-rwxr-xr-x  1 root root 18208 Aug  1 11:14 hsh
-rw-r--r--  1 root root   452 Jul 28 16:00 man_1_simple_shell
-rwxr-xr-x  1 root root    42 Jul 26 11:11 pidmax.sh
-rw-r--r--  1 root root   257 Jul 29 14:40 printenv.c
-rw-r--r--  1 root root   449 Aug  1 11:01 readcmd.c
-rwxr-xr-x  1 root root 18256 Jul 29 14:40 shell
-rw-r--r--  1 root root  1101 Jul 29 14:40 shell.h
-rw-r--r--  1 root root   164 Aug  1 10:27 sign.c
-rw-r--r--  1 root root   520 Aug  1 11:14 split.c
-rw-r--r--  1 root root   475 Jul 29 14:40 splitenv.c
-rw-r--r--  1 root root  1195 Jul 29 14:40 struse.c
-rw-r--r--  1 root root   693 Aug  1 11:14 super_shell.c
drwxr-xr-x  4 root root  4096 Jul 29 14:40 testingcode

$

^D
(ctrl + D to quit the program)

root@user-name:~/holbertonschool-simple_shell# echo "/bin/ls" | ./hsh
AUTHORS  README.md  execve.c  freegrid.c  getenv.c  getpath.c  hack  hsh  man_1_simple_shell  pidmax.sh  printenv.c  readcmd.c  shell  shell.h  sign.c  split.c  splitenv.c  struse.c  super_shell.c  testingcode

root@user-name:~/holbertonschool-simple_shell#
```

***

### CREDITS

#### Authors

UENG Chong Leang : *[Github](https://github.com/ChongLeangUENG)* - *[Linkedin](https://www.linkedin.com/in/chong-leang-ueng-78521b23b/)*

BENGANA Razika : *[Github](https://github.com/Razika-Bengana)* - *[Linkedin](https://www.linkedin.com/in/razika-bengana-065284243/)*

***

### LICENSE

__*simple _shell*__ is an open-source project, so the download and the usage has no restriction.
