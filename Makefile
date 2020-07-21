NAME = fdf
SRCS = read.c ft_draw.c main.c ft_event.c ft_draw_two.c ft_extra.c
OBJ = $(SRCS:.c=.o)
LIBDIR = libft/
LIBNAME = libft/libft.a
CFLAGS = -Wall -Wextra -Werror
all: $(NAME)
$(OBJ): %.o: %.c
	gcc -c $(CFLAGS) $< -o $@
$(LIBNAME):
	@make -C $(LIBDIR)
$(NAME): $(LIBNAME) $(OBJ)
	gcc $(CFLAGS) -lmlx -lm -framework OpenGL -framework AppKit \
	$(OBJ) -L $(LIBDIR) -lft -o $(NAME)
clean:
	@/bin/rm -f $(OBJ)
	@make -C $(LIBDIR) clean
	@echo OBJECTS FILES HAVE BEEN DELETED.
fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIBDIR) fclean
	@echo OBJECT FILES AND EXECUTABLE HAVE BEEN DELETED.
re: fclean all