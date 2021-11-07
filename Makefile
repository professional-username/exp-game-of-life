game_of_life: main.cpp graphics.cpp logic.cpp
	g++ -I /usr/include/eigen3/ -lglfw -lGL main.cpp graphics.cpp logic.cpp
