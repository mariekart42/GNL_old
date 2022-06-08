NAME = get_next_line.a
CC	= gcc
RM = rm -rf
HEAD = get_next_line.h
FLAGS = -Wall -Werror -Wextra

MAN_FILES = get_next_line.c get_next_line_utils.c

# mod buffer size here:
BUFFER_SIZE= 42

BUFFER_EXC= -D BUFFER_SIZE
#delete later lol
g:
	@$(CC) $(FLAGS) $(BUFFER_EXC=BUFFER_SIZE) $(MAN_FILES) 
	@./a.out

.PHONY: g