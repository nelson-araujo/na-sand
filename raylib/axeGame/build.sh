# if there is an error exit
set -e
gcc axeGame.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
./a.out
