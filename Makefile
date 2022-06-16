NAME = get_next_line.a
CC	= gcc
RM = rm -rf
HEAD = get_next_line.h
CFLAGS = -Wall -Werror -Wextra -g

MAN_FILES = get_next_line.c get_next_line_utils.c

#CLEAN_FILES = same_but_clean.c get_next_line_utils.c

# mod buffer size here:
BUFFER_SIZE= 20

BUFFER_EXC= -D BUFFER_SIZE
#delete later lol
g:
	@$(CC) $(FLAGS) $(BUFFER_EXC=BUFFER_SIZE) $(MAN_FILES) 
	@./a.out

d:
	@$(CC) $(FLAGS) $(MAN_FILES)
	@./a.out

# c:
# 	@$(CC) $(FLAGS) $(BUFFER_EXC=BUFFER_SIZE) $(CLEAN_FILES)
# 	@./a.out /dev/tty

.PHONY: g