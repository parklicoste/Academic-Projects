Author: KHUSHAL KUMAR SINGH
Purpose:
    opening and reading binary files, using command line parameters
    spawning multiple processes from parent processes Pids(Process id)
    morphing
Developer: KHUSHAL KUMAR SINGH
Date:      10th' December' 2018

The software is organised in 3 parts:
  singleMorph is an executable file made from singlePrime.c and it uses iPrime executable to read prime.bin, isPrime is made from isPrime.c
  singleSpawn is an executable file made from singleSpawn.c and it uses iPrime executable to read prime.bin, isPrime is made from isPrime.c
  multiSpawn is an executable file made from multiSpawn.c and it uses iPrime executable to read prime.bin, isPrime is made from isPrime.c

To Compile part 1 type: "make -f Makefile1" and to decompile "make -f Makefile1 clean" ------> singleMorph And isPrime
To Compile part 2 type: "make -f Makefile2" and to decompile "make -f Makefile2 clean" ------> singleSpawn And isPrime
To Compile part 3 type: "make -f Makefile3" and to decompile "make -f Makefile3 clean" ------> multiSpawn And isPrime

Limitations:
    The user have to type the name of binary file too, while running the code for eg: ./singleSpawn prime.bin
  to use the software: first compile the file using command which you want to use then type the executable with prime.bin
