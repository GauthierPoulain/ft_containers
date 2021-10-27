NAME = containers

CC = clang++
MAKE = make --no-print-directory

CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -g
# CPPFLAGS += -fsanitize=address

INCLUDE = ./includes

HEADERS = \
	$(INCLUDE)/map.hpp \
	$(INCLUDE)/stack.hpp \
	$(INCLUDE)/vector.hpp \
	$(INCLUDE)/iterators/random_access_iterator.hpp \
	$(INCLUDE)/iterators/reverse_iterator.hpp \
	$(INCLUDE)/iterators/iterator_traits.hpp \
	$(INCLUDE)/utils/commons.hpp \
	$(INCLUDE)/utils/is_integral.hpp \


SRCS = \
	./main.cpp \

FT_OBJS = $(SRCS:%.cpp=%_ft.o)
STL_OBJS = $(SRCS:%.cpp=%_stl.o)

%_ft.o: %.cpp Makefile $(HEADERS)
	$(CC) $(CPPFLAGS) -I$(INCLUDE) -c $< -o $@

%_stl.o: %.cpp Makefile $(HEADERS)
	$(CC) $(CPPFLAGS) -DSTL -I$(INCLUDE) -c $< -o $@

all: ft_$(NAME) stl_$(NAME)

ft_$(NAME): $(FT_OBJS)
	$(CC) $(CPPFLAGS) -o ft_$(NAME) $(FT_OBJS)

stl_$(NAME): $(STL_OBJS)
	$(CC) $(CPPFLAGS) -o stl_$(NAME) $(STL_OBJS)

clean:
	$(RM) $(FT_OBJS)
	$(RM) $(STL_OBJS)

fclean: clean
	$(RM) ft_$(NAME)
	$(RM) stl_$(NAME)

re: fclean
	$(MAKE) all

test: all
	/usr/bin/time -p ./stl_$(NAME) 
	/usr/bin/time -p ./ft_$(NAME) 

bench: all
	/usr/bin/time -p ./stl_$(NAME) bench
	/usr/bin/time -p ./ft_$(NAME) bench

.PHONY: all clean fclean test bench
