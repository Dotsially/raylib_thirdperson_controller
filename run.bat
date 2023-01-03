gcc -g src/*.c -o TP.exe -O1 -Wall -std=c99 -Wno-missing-braces -I include/ -I headers/ -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm -luser32 -lshell32
