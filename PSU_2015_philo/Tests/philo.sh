#!/usr/bin/env bash

make re && make clean;
LD_LIBRARY_PATH=$PWD ./philo -p $1 -e $2
