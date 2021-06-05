CLIENT		:= client
SERVER		:= server

CC		:= gcc 
CFLAGS		:= -Wall -Werror -Wextra
CPPFLAGS	:= -I./libft/include -I./include -I./include_bonus
LDFLAGS		:= -L./libft/
LDLIBS		:= -lft

SRCS1	:= $(addprefix ./srcs/, client.c)
SRCS2	:= $(addprefix ./srcs/, server.c)
SRCS1_B	:= $(addprefix ./srcs_bonus/, client_bonus.c)
SRCS2_B	:= $(addprefix ./srcs_bonus/, server_bonus.c)
OBJS1	:= $(SRCS1:.c=.o)
OBJS2	:= $(SRCS2:.c=.o)
OBJS1_B	:= $(SRCS1_B:.c=.o)
OBJS2_B	:= $(SRCS2_B:.c=.o)
RM	:= rm -rf

.Phony: lft re all clean fclean bonus

all: lft $(CLIENT) $(SERVER)

lft:
	@make --silent -C ./libft

%.o: %.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(CLIENT): $(OBJS1)
	@$(CC) $(CFLAGS) $< $(LDFLAGS) $(LDLIBS) -o $@

$(SERVER): $(OBJS2)
	@$(CC) $(CFLAGS) $(OBJS2) $(LDFLAGS) $(LDLIBS) -o $@

clean:
	@make clean --silent -C ./libft
	@$(RM) $(OBJS1) $(OBJS2) $(OBJS1_B) $(OBJS2_B)

fclean: clean
	@make fclean --silent -C ./libft
	@$(RM) $(CLIENT) $(SERVER)

bonus: lft $(OBJS1_B) $(OBJS2_B)
	@$(CC) $(CFLAGS) $(OBJS1_B) $(LDFLAGS) $(LDLIBS) -o client
	@$(CC) $(CFLAGS) $(OBJS2_B) $(LDFLAGS) $(LDLIBS) -o server

re: fclean all
