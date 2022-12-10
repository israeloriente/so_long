NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -Iheaders/
SRCS		=   ft_main.c
OBJS		= 	$(SRCS:.c=.o)

MLX_LIB_DIR = minilibx-linux/
MLX_INCLUDE = -Imlx_linux
MLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

# ^ primeira dependencia
# @ nome da regra
all: $(NAME)

$(NAME): $(OBJS)
		@$(CC) $(^) $(MLX_FLAGS) -o $(@)

%.o: %.c
	@$(CC) $(INCLUDE) $(MLX_INCLUDE) -c $(^) -o $(@)

clean:
	@$(RM) $(OBJS)
	@echo "\033[0;31mREMOVED OBJECT FILES\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[0;31mREMOVED so_long EXECUTABLE\033[0m"

re: fclean all

norm :
	@norminette -R CheckForbiddenSourceHeader $(SRCS)

m: fclean

v:
	@make re && make clean && clear && valgrind --leak-check=full --log-file="logfile.out" -v ./so_long
r:
	@make re && make clean && clear && ./so_long maps/map.ber maps/maps1.car maps/map.ber

rr:
	@make re && make clean && clear && ./so_long maps/map.ber
