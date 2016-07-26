objects = main.o charater.o

test:$(objects)
	g++ -o test $(objects)

main.o:main.cpp charater.h
	g++ -c main.cpp

charater.o:charater.cpp charater.h
	g++ -c charater.cpp

clean:
	rm -rf test $(objects) 

