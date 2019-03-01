#!/bin/bash
gcc -c *.c
ar -rc liball.a *.o
ar -s liball.a
