# if there is an error exit
set -e
gcc axeGame.cpp -o axeGame.out -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
./axeGame.out