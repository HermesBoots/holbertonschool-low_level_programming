#!/bin/bash
wget -O /tmp/libinjected.so https://github.com/HermesBoots/holbertonschool-low_level_programming/raw/master/0x17-dynamic_libraries/libinjected.so
export LD_PRELOAD=/tmp/libinjected.so
