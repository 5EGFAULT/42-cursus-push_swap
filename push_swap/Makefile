NAME :=  push_swap
CHECKER := checker
SRC :=   main.c  s_d_list_0.c  s_d_list_1.c  ft_reverse_rotate_ft_push.c  ft_rotate_ft_swap.c   libft0.c  libft1.c   utils.c  init.c  sort.c  quick_sort_arr.c  sort_utils.c
OBJ :=  main.o  s_d_list_0.o  s_d_list_1.o  ft_reverse_rotate_ft_push.o  ft_rotate_ft_swap.o  libft0.o  libft1.o   utils.o  init.o  sort.o  quick_sort_arr.o  sort_utils.o
SRCB :=   main_bonus.c  s_d_list_0.c  s_d_list_1.c  ft_reverse_rotate_ft_push_bonus.c  ft_rotate_ft_swap_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c  libft0.c  libft1.c   utils.c  init.c  sort_bonus.c  sort_utils.c fill_inst_bonus.c
OBJB :=  main_bonus.o  s_d_list_0.o  s_d_list_1.o  ft_reverse_rotate_ft_push_bonus.o  ft_rotate_ft_swap_bonus.o get_next_line_bonus.o get_next_line_utils_bonus.o libft0.o  libft1.o   utils.o  init.o  sort_bonus.o  sort_utils.o fill_inst_bonus.o
CC:= gcc

all: $(NAME)
%.o: %.c
	$(CC) -Wall -Wextra -Werror -c $<  -o $@ 
$(NAME):  $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

bonus: $(CHECKER)

$(CHECKER): $(OBJB)
	$(CC) $(OBJB) -o $(CHECKER)
clean:
	@rm -f $(OBJ) $(OBJB)
fclean: clean
	@rm -f $(NAME) $(CHECKER)
re: fclean all
