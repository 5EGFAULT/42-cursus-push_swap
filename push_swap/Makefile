NAME :=  push_swap
SRC :=  src/main.c src/s_d_list_0.c src/s_d_list_1.c src/ft_push.c src/ft_reverse_rotate.c src/ft_rotate.c src/ft_swap.c src/libft.c src/utils.c
OBJ := src/main.o src/s_d_list_0.o src/s_d_list_1.o  src/ft_push.o src/ft_reverse_rotate.o src/ft_rotate.o src/ft_swap.o src/libft.o src/utils.o
CC:= gcc

all: $(NAME)
%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx  -c $<  -o $@ 

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -g -fsanitize=address 
clean:
	@rm -f $(OBJ)
	@make -C src/libft fclean
fclean: clean
	@rm -f $(NAME)

re: fclean all

test: $(NAME)
	./$(NAME)