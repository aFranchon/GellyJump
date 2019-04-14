##
## EPITECH PROJECT, 2019
## Projet1
## File description:
## Makefile
##

NAME	=	GellyJump

SRC		=	Core/Core.cpp				\
			LibMenu/Button/Button.cpp	\
			Scene/Game/Player/Player.cpp\
			Scene/Game/Game.cpp			\
			Scene/Menu/Menu.cpp			\
			Main.cpp

OBJ		=	$(SRC:.cpp=.o)

INCLUDE	=	-I./Scene/Game/ -I./Scene/Menu -I./LibMenu/ -I./LibMenu/Button -I./LibMenu/Slider -I./Scene -I./Core

LINK_FLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system

all: $(NAME)

%.o: %.cpp
		g++ $(LINK_FLAGS) $(INCLUDE) -c $^ -o $@

$(NAME): $(OBJ)
		g++ -o $(NAME) $(OBJ) $(LINK_FLAGS) $(INCLUDE)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all