##
## EPITECH PROJECT, 2019
## Projet1
## File description:
## Makefile
##

NAME	=	GellyJump

SRC		=	Core/Core.cpp							\
			LibMenu/Button/Button.cpp				\
			LibMenu/Slider/Slider.cpp				\
			Scene/Game/Player/Player.cpp			\
			Scene/Game/Player/Actions/Shoot.cpp		\
			Scene/Game/Environnement/Wall.cpp		\
			Scene/Game/Game.cpp						\
			Scene/Menu/Menu.cpp						\
			Scene/Game/GameUtils/Animator.cpp		\
			Main.cpp

OBJ		=	$(SRC:.cpp=.o)

INCLUDE	=	-I./Scene/Game/ -I./Scene/Menu -I./LibMenu/ -I./LibMenu/Button -I./LibMenu/Slider -I./Scene -I./Core -I./Scene/Game/GameUtils -I./Movements -I./Scene/Game/Environnement

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