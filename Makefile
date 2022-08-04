game_clang:
	clang++ *.cpp -o flappy_ripoff -I include/SDL2 -L lib -l SDL2-2.0.0 -l SDL2_image -std=c++20
game_gcc:
	g++ *.cpp -o flappy_ripoff_gcc -I include/SDL2 -L lib -l SDL2.0.0 -l SDL2_image -std=c++20
