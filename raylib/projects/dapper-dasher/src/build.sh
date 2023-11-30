# if there is an error exit
set -e
gcc dasher.cpp -o ../dasher.out -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
../dasher.out