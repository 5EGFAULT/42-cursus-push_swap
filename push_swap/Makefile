NAME :=  push_swap
SRC :=  src/main.c src/s_d_list_0.c src/s_d_list_1.c src/ft_push.c src/ft_reverse_rotate.c src/ft_rotate.c src/ft_swap.c src/libft0.c src/libft1.c  src/utils.c src/init.c src/sort.c
OBJ := src/main.o src/s_d_list_0.o src/s_d_list_1.o  src/ft_push.o src/ft_reverse_rotate.o src/ft_rotate.o src/ft_swap.o src/libft0.o src/libft1.o  src/utils.o src/init.o src/sort.o
CC:= gcc

all: $(NAME)
%.o: %.c
	$(CC) -Wall -Wextra -Werror  -c $<  -o $@ 

$(NAME):  $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -g -fsanitize=address 
#	$(CC) $(OBJ) -o $(NAME) 
clean:
	@rm -f $(OBJ)
	@make -C src/libft fclean
fclean: clean
	@rm -f $(NAME)

re: fclean all

test: $(NAME)
	./$(NAME)  10 25 55
#ss: $(NAME)
#	ARG="10 25 55"; ./push_swap $ARG | ./test/checker_Mac $ARG