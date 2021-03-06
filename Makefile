##
## EPITECH PROJECT, 2019
## Projet1
## File description:
## Makefile
##

NAME	=	GellyJump

SRC		=	Core/Core.cpp								\
			LibMenu/Button/Button.cpp					\
			LibMenu/Slider/Slider.cpp					\
			Scene/Game/Player/Player.cpp				\
			Scene/Game/Player/Actions/Shoot.cpp			\
			Scene/Game/Environnement/IEnvironement.cpp	\
			Scene/Game/Game.cpp							\
			Scene/Menu/Menu.cpp							\
			Scene/Win/Win.cpp							\
			Scene/Lose/Lose.cpp							\
			GameUtils/Animator.cpp						\
			GameUtils/MapLoader.cpp						\
			Main.cpp

OBJ		=	$(SRC:.cpp=.o)

INCLUDE	=	-I./Scene/Game/ -I./Scene/Win -I./Scene/Lose -I./Scene/Game/Player -I./Scene/Game/Player/Actions -I./Scene/Menu -I./LibMenu/ -I./LibMenu/Button -I./LibMenu/Slider -I./Scene -I./Core -I./GameUtils -I./Movements -I./Scene/Game/Environnement -I./Scene/Game/Environnement/EndLevelTrigger -I./Scene/Game/Environnement/StaticMurderer -I./Scene/Game/Environnement/Walls

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