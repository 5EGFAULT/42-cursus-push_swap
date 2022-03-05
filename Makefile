NAME :=  so_long
SRC :=  srcs/main.c srcs/init_game.c srcs/draw.c srcs/hooks.c srcs/move_player.c srcs/validate_map_structure.c srcs/validate_map_objects.c srcs/Get_next_line/get_next_line_bonus.c srcs/Get_next_line/get_next_line_utils_bonus.c 
OBJ := srcs/main.o srcs/init_game.o srcs/draw.o srcs/hooks.o srcs/move_player.o srcs/validate_map_structure.o srcs/validate_map_objects.o srcs/Get_next_line/get_next_line_bonus.o srcs/Get_next_line/get_next_line_utils_bonus.o 
MAP := maps/map2.ber
LIBFT = srcs/libft/libft.a
CC:= gcc
all: $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx  -c $<  -o $@ 

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIBFT) -g -fsanitize=address 
$(LIBFT):
		@make -C srcs/libft
		@make -C srcs/libft clean
clean:
	@rm -f $(OBJ)
	@make -C srcs/libft fclean
fclean: clean
	@rm -f $(NAME)
	@make -C srcs/libft fclean
re: fclean all

t: $(NAME)
	./$(NAME) $(MAP)
