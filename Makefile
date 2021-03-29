# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egums <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/30 11:45:53 by egums             #+#    #+#              #
#    Updated: 2021/03/17 03:20:27 by egums            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = minishell
PATHLIB = ./libft
NAMELIB = libft.a
LIBS = $(PATHLIB)/$(NAMELIB)

FLAG = -Wall #-Wextra -Werror
HEADER = includes/header.h
INC = -I./libft -I./includes -I./gnl
OBJ = $(SRC:.c=.o)

PATHSRC = parser
SRCLIST = $(wildcard $(dir)/*.c)
SRC =$(shell cat $(DEP_SRC))
HEAD =$(shell cat $(DEP_INC))
#MAKEFLAG += --silent
DIR_DEP =.deps
DEP_INC =$(DIR_DEP)/include_list.txt
DEP_SRC =$(DIR_DEP)/source_list.txt
SRC_FOR_SAVE =$(foreach dir, $(PATHSRC), $(SRCLIST))
INC_FOR_SAVE = $(wildcard includes/*.h)

.PHONY: all libs clean fclean re norme save

all: libs $(NAME) $(SRC)

$(NAME): $(OBJ) $(LIB_MLX)
	$(CC) $(FLAG) -o $(NAME) $(LIBX) $(SRC_FOR_SAVE) $(INC) $(LIBS)
	@echo "$(BOLD)$(GB)Compilation done$(EB)$(SGR0)";

%.o: %.c $(HEAD) $(LIB_MLX) $(LIBS)
	$(CC) -c $(FLAG) $< $(INC) -o $@

libs:
	$(MAKE) bonus -C$(PATHLIB) --silent

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C$(PATHLIB)
	@echo "$(BOLD)$(RB)Del done$(EB)$(SGR0)";

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C$(PATHLIB)

norme:
	@if ! norminetteV3 $(SRC) headers/headers.h\
     libft/*.c libft/*.h \
     | grep -q "Error"; then \
  		echo "Check norminette - $(BOLD)$(GB)Успешно$(EB)$(SGR0)"; \
  	else \
		echo "Check norminette - $(BOLD)$(RB)Ошибка$(EB)$(SGR0)"; \
  	fi

norm:
	@norminette $(SRC)
	@norminette includes/solve_mlx.h includes/inc.h \
	includes/intersect_and_light.h includes/minirt.h \
	includes/solve_mlx.h includes/structs.h includes/vectors.h

wc:
	wc -l $(SRC) $(HEAD)

# Check fonts and bolds

BOLD:=$(shell tput bold)
SGR0:=$(shell tput sgr0)
GB:=\033[92m
EB:=\033[0m
RB:=\033[31m

# Check file existing and write list sources
# Change path to DEPENDENS >
# < Need for silent mode
# .SILENT: libs

save:
	@if [ ! -d $(DIR_DEP) ]; \
	then \
		mkdir $(DIR_DEP); \
	fi
	@if [ ! -f $(DEP_SRC) ]; \
	then \
		touch $(DEP_SRC); \
	else \
		cat /dev/null > $(DEP_SRC); \
	fi
	@if [ ! -f $(DEP_INC) ]; \
    then \
    	touch $(DEP_INC); \
    else \
    	cat /dev/null > $(DEP_INC); \
    fi
	@printf "$(SRC_FOR_SAVE)" >> $(DEP_SRC)
	@printf "$(INC_FOR_SAVE)" >> $(DEP_INC)
	@echo "Сохранение листа исходных файлов - $(BOLD)$(GB)Успешно$(EB)$(SGR0)"

re: fclean all clean