# minishell
Autors: @egums, @tsaiyan

<img width="207" alt="Screen Shot 2021-06-06 at 4 36 07 PM" src="https://user-images.githubusercontent.com/69805852/120926534-fc70e680-c6e5-11eb-9345-c94a7aa609f7.png">

For compile programm run:
```shell
make
```

For check leaks in real time use script:
```shell
./leaks_minishell.sh
```

the project supports some of the functionality of the ***bash***, such as:
  - All execve commands, implemented binary files, like standrart bash, for example ***echo, ls, cd, etc...***
  - Redirect functionality, ex. ***/$> echo 123 > 1*** or ***/$> echo 123 >> 1*** or ***/$> echo < 1 > 2***
  - Pipe functionality, ex. ***/$> ls | cat 1***
  - Bash history files.
  - Bash termcap navigations.
  - Signals ctal + C, ctrl + \, ctrl + d.
  - And more...



[TASK DICRIPTION](https://github.com/Rukopet/subjects/blob/main/en.subject_minishell.pdf)
