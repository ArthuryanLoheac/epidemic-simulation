##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

GREEN=\033[0;32m
RED=\033[0;31m
YELLOW=\033[01;33m
BLUE=\e[1;34m
NC=\033[0m

.SILENT:
.PHONY: clean fclean


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

NAME	=	simulation

CPPFLAGS	= -I./include -lsfml-graphics -lsfml-window -lsfml-system -std=c++20 \

all: $(NAME)

$(NAME):
	g++ -o $(NAME) $(SRC) $(SRC_MAIN) $(CPPFLAGS)
	@printf "$(BLUE)[🕹️ ] $(NAME), $(GREEN)Build complete ! $(NC)\n"

clean:
	@printf "$(RED)[🚫]$(BLUE)Clean$(NC)\n"

fclean: clean
	@printf "$(RED)[🚫]$(BLUE)Fclean$(NC)\n"
	rm -f $(NAME)

re: fclean all

run: re
	./$(NAME)