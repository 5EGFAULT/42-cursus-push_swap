NAME :=  push_swap
SRC :=   main.c  s_d_list_0.c  s_d_list_1.c  ft_reverse_rotate_ft_push.c  ft_rotate_ft_swap.c   libft0.c  libft1.c   utils.c  init.c  sort.c  quick_sort_arr.c  sort_utils.c
OBJ :=  main.o  s_d_list_0.o  s_d_list_1.o  ft_reverse_rotate_ft_push.o  ft_rotate_ft_swap.o  libft0.o  libft1.o   utils.o  init.o  sort.o  quick_sort_arr.o  sort_utils.o
CC:= gcc

all: $(NAME)
%.o: %.c
	$(CC) -Wall -Wextra -Werror  -c $<  -o $@ 
$(NAME):  $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -fsanitize=address -g
clean:
	@rm -f $(OBJ)
fclean: clean
	@rm -f $(NAME)
re: fclean all
