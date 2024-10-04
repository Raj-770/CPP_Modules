NAME	:= account
CC		:= c++
CFLAGS	:= -Wextra -Wall -Werror -std=c++98

SRCS	:=	tests.cpp \
			Account.cpp

OBJS	:= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
