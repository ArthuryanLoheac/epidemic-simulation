##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##


.SILENT:
.PHONY: clean fclean

GREEN=\033[0;32m
RED=\033[0;31m
YELLOW=\033[01;33m
BLUE=\e[1;34m
NC=\033[0m

.SILENT:
.PHONY: clean fclean

SRC_LIB	=	\

SRC_MAIN	=	src/main.cpp \

SRC	=	src/draw.cpp \
		src/compute.cpp \
		src/create_window.cpp \
		src/update.cpp \
		src/person.cpp \
		src/interetPoint.cpp \
		src/housePoint.cpp \
		src/workPoint.cpp \
		src/create_persons.cpp \
		src/create_InteretPoints.cpp \
		src/update_all_person.cpp \
		src/newDay.cpp \

SRC_TESTS	= 	tests/test_1.cpp \

COMPILER = g++

EXTENSION = cpp

CFLAGS	= -I./include -lsfml-graphics -lsfml-window -lsfml-system -std=c++20 \

FLAGS_TEST	=	-std=c++20 -Wall -Wextra -Werror \
				-lcriterion --coverage	\

CFLAGS_LIB 	=	-std=c++20 -Wall -Wextra -Werror

OBJ	=	$(SRC_LIB:.$(EXTENSION)=.o)

OBJ_SRC	=	$(SRC:.$(EXTENSION)=.o)

OBJ_MAIN	=	$(SRC_MAIN:.$(EXTENSION)=.o)

NAME_LIB	= \

NAME	=	simulation

all: $(NAME) $(NAME_LIB)

$(NAME): $(OBJ_SRC) $(OBJ_MAIN)
	$(COMPILER) -o $(NAME) $(OBJ_SRC) $(OBJ_MAIN) $(CFLAGS)
	@printf "$(YEL)[🕹️ ] $(BLUE)$(NAME), $(GREEN)Build complete ! $(NC)\n"

$(NAME_LIB): $(OBJ)
	@printf "$(YEL)[📚 ] $(BLUE)$(NAME_LIB), $(GREEN)Library complete !$(NC)\n"
	ar rc $(NAME_LIB) $(OBJ)

clean:
	@printf "$(RED)[🚫] $(BLUE)Clean$(NC)\n"
	rm -f *.gcda
	rm -f *.gcno
	rm -f $(OBJ)
	rm -f $(OBJ_MAIN)
	rm -f $(OBJ_SRC)

fclean: clean
	@printf "$(RED)[🚫] $(BLUE)Fclean$(NC)\n"
	rm -f $(NAME)
	rm -f $(NAME_LIB)
	rm -f unit_tests

%.o: %.cpp
	@printf "$(YEL)[⚒️ ] $(BLUE)Compiling, $(GREEN)$@$(NC)\n"
	@$(COMPILER) -c $(CFLAGS) $< -o $@

re: fclean all

run: all
	./$(NAME)

unit_tests:
	$(COMPILER) -o unit_tests $(SRC_TESTS) $(SRC) $(FLAGS_TEST)

tests_run: unit_tests
	./unit_tests --verbose

tests_run_coverage: tests_run
	gcovr -r . -e tests/

tests_clean_run: fclean tests_run

tests_clean_run_coverage: tests_clean_run
	gcovr -r . -e tests/