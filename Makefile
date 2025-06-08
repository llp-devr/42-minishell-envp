SOURCES = main.c \
		  unity/unity.c \
		  envp/__match_key.c \
		  envp/envp_del.c \
		  envp/envp_dup.c \
		  envp/envp_get.c \
		  envp/envp_set.c \
		  utils/ft_calloc.c \
		  utils/ft_strncpy.c

OBJECTS = $(SOURCES:.c=.o)

CC = cc

CFLAGS += -Wall -Werror -Wextra -g3

LIBFT_DIR = ./libft

test: $(OBJECTS)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(OBJECTS) -L$(LIBFT_DIR) -lft
	./a.out

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OBJECTS)
	rm -f a.out

.PHONY: clean

