# if there is an error exit
set -e
gcc game.cpp -o ../game.out -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
../game.out