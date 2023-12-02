  CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
LDLIBS = -lcs50 -lm

# Rule to compile a file into an executable
%: %.c
	$(CC) $(CFLAGS) $< -o $@ $(LDLIBS)

