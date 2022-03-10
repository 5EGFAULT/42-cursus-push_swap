NAME :=  push_swap
SRC :=   main.c  s_d_list_0.c  s_d_list_1.c  ft_push.c  ft_reverse_rotate.c  ft_rotate.c  ft_swap.c  libft0.c  libft1.c   utils.c  init.c  sort.c  sort1.c  quick_sort_arr.c  sort_utils.c  sort_utils1.c
OBJ :=  main.o  s_d_list_0.o  s_d_list_1.o   ft_push.o  ft_reverse_rotate.o  ft_rotate.o  ft_swap.o  libft0.o  libft1.o   utils.o  init.o  sort.o  sort1.o  quick_sort_arr.o  sort_utils.o  sort_utils1.o
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
ss: $(NAME)
	./push_swap $ARG | ./checker_Mac $ARG