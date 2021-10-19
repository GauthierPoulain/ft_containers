NAME = containers

CC = clang++
MAKE = make --no-print-directory

CPPFLAGS = -Wall -Wextra -Werror -g -std=c++98
# CPPFLAGS += -fsanitize=address

INCLUDE = ./includes

HEADERS = \
	$(INCLUDE)/map.hpp \
	$(INCLUDE)/stack.hpp \
	$(INCLUDE)/vector.hpp \


SRCS = \
	./main.cpp \

OBJS = $(SRCS:%.cpp=%.o)

%.o: %.cpp Makefile $(HEADERS)
	$(CC) $(CPPFLAGS) -I$(INCLUDE) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

test: all
	/usr/bin/time -p ./containers

.PHONY: all clean fclean test
