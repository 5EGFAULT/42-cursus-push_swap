NAME :=  push_swap
SRC :=   main.c  s_d_list_0.c  s_d_list_1.c  ft_reverse_rotate_ft_push.c  ft_rotate_ft_swap.c   libft0.c  libft1.c   utils.c  init.c  sort.c  sort1.c  quick_sort_arr.c  sort_utils.c  sort_utils1.c
OBJ :=  main.o  s_d_list_0.o  s_d_list_1.o  ft_reverse_rotate_ft_push.o  ft_rotate_ft_swap.o  libft0.o  libft1.o   utils.o  init.o  sort.o  sort1.o  quick_sort_arr.o  sort_utils.o  sort_utils1.o
CC:= gcc

all: $(NAME)
%.o: %.c
	$(CC) -Wall -Wextra -Werror  -c $<  -o $@ 
$(NAME):  $(OBJ)
	$(CC) $(OBJ) -o $(NAME)
clean:
	@rm -f $(OBJ)
fclean: clean
	@rm -f $(NAME)
re: fclean all
test: $(NAME)
	./$(NAME) 3 21 11 34 214 114  37 217 115 347 2174 1154 225 64 655 98 45 56 54 564 654 5 464 55 8 7 546 3132
t: $(NAME)
	./$(NAME) 231 264 634 -202 598 -356 -792 521 -942 -610 -422 88 -549 -156 138 333 -60 -785 737 626 94 314 285 -920 946 -746 389 555 -528 177 -774 -679 -72 -784 395 -831 -808 733 635 -912 -257 275 190 -295 655 893 911 298 360 20 -908 7 -963 923 -129 926 -475 802 -56 -87 882 166 954 -951 -793 -27 864 -993 41 -162 340 267 183 835 584 -187 -772 907 -32 -660 -840 -406 -105 435 -600 -22
ss: $(NAME)
	./push_swap $ARG | ./checker_Mac $ARG