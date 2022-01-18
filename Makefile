
all : main

main : main.o myJump.o

main.o : main.c myJump.h
	gcc -c main.c

myJump.o : myJump.c myJump.h
	gcc -c -m32 myJump.c
	
clean : 
	rm *.o main
