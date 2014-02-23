Debian compiler frags start

# Compiler flags...
CPP_COMPILER = g++
C_COMPILER = gcc

INC=-I./ -I~/include -I/usr/include -I/usr/local/include/SDL2

# Include paths...
Debug_Include_Path=${INC}
Release_Include_Path=${INC}

# Library paths...
Debug_Library_Path=
Release_Library_Path=

# Additional libraries...
Debug_Libraries=-Wl,--start-group -lSDL2 -lSDL2main -lSDL2_image  -Wl,--end-group
Release_Libraries=-Wl,--start-group -lSDL2 -lSDL2main -lSDL2_image  -Wl,--end-group

# Preprocessor definitions...
Debug_Preprocessor_Definitions=-D TIXML_USE_STL -D GCC_BUILD -std=c++11
Release_Preprocessor_Definitions=-D GCC_BUILD -std=c++11

PI compiler flags start

# Compiler flags...
CPP_COMPILER = g++
C_COMPILER = gcc

INC=-I./ -I~/include -I/usr/include -I/usr/local/include/SDL2

# Include paths...
Debug_Include_Path=${INC}
Release_Include_Path=${INC}

# Library paths...
Debug_Library_Path=-L./ -L./lib -L~/lib -L/lib -L/usr/lib -L/usr/local/lib -L/usr/lib/arm-linux-gnueabihf 
Release_Library_Path=-L./ -L./lib -L~/lib -L/lib -L/usr/lib -L/usr/local/lib -L/usr/lib/arm-linux-gnueabihf 

# Additional libraries...
Debug_Libraries=-Wl,--start-group -lSDL2 -lSDL2main -lSDL2_image  -Wl,--end-group
Release_Libraries=-Wl,--start-group -lSDL2 -lSDL2main -lSDL2_image  -Wl,--end-group