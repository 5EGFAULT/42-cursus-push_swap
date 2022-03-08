NAME :=  push_swap
SRC :=  src/main.c src/s_d_list_0.c src/s_d_list_1.c src/ft_push.c src/ft_reverse_rotate.c src/ft_rotate.c src/ft_swap.c src/libft0.c src/libft1.c  src/utils.c src/init.c src/sort.c src/sort1.c src/quick_sort_arr.c src/sort_utils.c
OBJ := src/main.o src/s_d_list_0.o src/s_d_list_1.o  src/ft_push.o src/ft_reverse_rotate.o src/ft_rotate.o src/ft_swap.o src/libft0.o src/libft1.o  src/utils.o src/init.o src/sort.o src/sort1.o src/quick_sort_arr.o src/sort_utils.o
CC:= gcc

all: $(NAME)
%.o: %.c
	$(CC) -Wall -Wextra -Werror  -c $<  -o $@ 
$(NAME):  $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -g -fsanitize=address 
clean:
	@rm -f $(OBJ)
fclean: clean
	@rm -f $(NAME)
re: fclean all
test: $(NAME)
	./$(NAME) 3 21 11 34 214 114  37 217 115 347 2174 1154 225 64 655 98 45 56 54 564 654 5 464
#ss: $(NAME)
#	ARG="10 25 55"; ./push_swap $ARG | ./test/checker_Mac $ARG