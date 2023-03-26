# Third person character controller
![character gif](https://user-images.githubusercontent.com/60740181/210362255-6dd26f39-cb90-4058-affa-b3d705e1e0ba.gif)

Simple character controller made with Raylib to test GLTF animations.
There's no physics. I might add jumping later on.


Uses a custom third person camera and player controller.

# How to run
- On windows run the run.bat file.
- On Linux and Mac you'll have to build the executable yourself using a terminal or MakeFile.
```
gcc -O3 src/*.c -o TP.exe -O1 -Wall -std=c99 -Wno-missing-braces -I include/ -I headers/ -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm -luser32 -lshell32
```
