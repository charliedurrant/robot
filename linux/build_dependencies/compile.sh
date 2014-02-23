#!/bin/bash

  printf "\n"
  printf "\t+----------------------------+\n"
  printf "\t|       Compile main.c       |\n"
  printf "\t|          SDL2 test         |\n"
  printf "\t+----------------------------+\n\t"
  printf "\n\t Start Compile: "; date

  date > compile.log; printf "\n" >> compile.log

  # file locations
  LIB="-L./ -L./lib -L~/lib -L/lib -L/usr/lib -L/usr/local/lib -L/usr/lib/arm-linux-gnueabihf"
  INC="-I./ -I./lib -I~/include -I/usr/include"

  # graphic file locations
  GLIB="-L/opt/vc/lib"
  GINC="-I/opt/vc/include -Iopt/vc/src/hello_pi/libs"

  # compile program
  gcc `sdl2-config --cflags --libs` $LIB $GLIB $INC $GINC -v -o sdl2_test main.c  >> compile.log 2>&1

  # run program
  if [ -f sdl2_test ]; then
    ./sdl2_test
    printf "\tEnd of program... \n"    
  else  
    cat ./compile.log
    printf "\t *** There where errors, compile aborted. ***\n"
  fi

  # required so xterm will not close
  printf "\n\t%s" "press any key to exit: "
  read -n 1