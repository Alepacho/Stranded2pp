#! /bin/bash

cd build/

valgrind --leak-check=full ./stranded2pp

cd ../