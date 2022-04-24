gcc -c aCEForth.c
gcc -c VFM_Headers.c
gcc -c VFM_Macros.c
gcc -c VFM_Primitives.c
gcc -c main.c
gcc -o 4th.exe main.o aCEForth.o  VFM_Headers.o VFM_Macros.o VFM_Primitives.o
