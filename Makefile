##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

# ============= COLORS ============= #

GREEN=\033[0;32m
RED=\033[0;31m
YELLOW=\033[01;33m
BLUE=\e[1;34m
NC=\033[0m

.SILENT:
.PHONY: clean fclean all re run unit_tests tests_run tests_run_coverage tests_clean_run tests_clean_run_coverage

# ============= SOURCES ============= #

SRC_LIB = \

SRC_MAIN = src/main.cpp \

SRC = src/draw.cpp \
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
	include/button.cpp \
	include/slideur.cpp \

SRC_TESTS = tests/test_1.cpp \

# ============= PARAMETERS ============= #

COMPILER = g++

EXTENSION = cpp

# ============= FLAGS ============= #

CFLAGS = -I./include -lsfml-graphics -lsfml-window -lsfml-system -std=c++20 -MMD -MP \

FLAGS_TEST = -std=c++20 -Wall -Wextra -Werror \
			-lcriterion --coverage \

CFLAGS_LIB = -std=c++20 -Wall -Wextra -Werror

# ============= OBJECTS ============= #

OBJ_DIR = obj

OBJ = $(SRC_LIB:.$(EXTENSION)=$(OBJ_DIR)/%.o)

OBJ_SRC = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

OBJ_MAIN = $(SRC_MAIN:%.cpp=$(OBJ_DIR)/%.o)

DEPS = $(OBJ_SRC:.o=.d) $(OBJ_MAIN:.o=.d)

# ============= NAMES ============= #

NAME_LIB = \

NAME = simulation

# ============= RULES ============= #

all: $(NAME) $(NAME_LIB)

$(NAME): $(OBJ_SRC) $(OBJ_MAIN)
	$(COMPILER) -o $(NAME) $(OBJ_SRC) $(OBJ_MAIN) $(CFLAGS)
	@printf "$(YELLOW)[✅] $(BLUE)$(NAME), $(GREEN)Build complete ! $(NC)\n"

$(NAME_LIB): $(OBJ)
	@printf "$(YELLOW)[📚] $(BLUE)$(NAME_LIB), $(GREEN)Library complete !$(NC)\n"
	ar rc $(NAME_LIB) $(OBJ)

# ============= CLEANS ============= #

clean:
	@printf "$(RED)[🚫] $(BLUE)Clean$(NC)\n"
	rm -rf $(OBJ_DIR)
	rm -f *.gcda *.gcno

fclean: clean
	@printf "$(RED)[🚫] $(BLUE)Fclean$(NC)\n"
	rm -f $(NAME) $(NAME_LIB) unit_tests

# ============= COMPILATION ============= #

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@printf "$(YELLOW)[⚒️] $(BLUE)Compiling, $(GREEN)$(@F)$(NC)\n"
	$(COMPILER) -c $(CFLAGS) $< -o $@

-include $(DEPS)

# ============= OTHERS ============= #

re: fclean all

run: all
	./$(NAME)

# ============= TESTS ============= #

unit_tests:
	@mkdir -p $(OBJ_DIR)
	$(COMPILER) -o $(OBJ_DIR)/unit_tests $(SRC_TESTS) $(SRC) $(FLAGS_TEST)

tests_run: unit_tests
	./$(OBJ_DIR)/unit_tests --verbose

tests_run_coverage: tests_run
	gcovr -r . -e tests/

tests_clean_run: fclean tests_run

tests_clean_run_coverage: tests_clean_run
	gcovr -r . -e tests/
