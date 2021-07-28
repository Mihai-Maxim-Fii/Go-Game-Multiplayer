g++ -c game.cpp -I/home/michael/MyWorkspace/SFML-2.5.1/include
g++ game.o -o sfml-app -L/home/michael/MyWorkspace/SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system
export LD_LIBRARY_PATH=/home/michael/MyWorkspace/SFML-2.5.1/lib && ./sfml-app
