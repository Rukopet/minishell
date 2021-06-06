# minishell
Autors: @egums, @tsaiyan

For compile programm run:
```shell
make
```

the project supports some of the functionality of the ***bash***, such as:
  - All execve commands, implemented binary files, like standrart bash, for example ***echo, ls, cd, etc...***
  - Redirect functionality, ex. ***/$> echo 123 > 1*** or ***/$> echo 123 >> 1*** or ***/$> echo < 1 > 2***
  - Pipe functionality, ex. ***/$> ls | cat 1***
  - Bash history files.
  - Bash termcap navigations.
  - Signals ctal + C, ctrl + \, ctrl + d.
  - And more...
