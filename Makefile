objects = main.o utf8-character.o base-character.o gbk-character.o

test:$(objects)
	g++ -o test $(objects)

main.o:main.cpp utf8-character.h
	g++ -c main.cpp

utf8-character.o:utf8-character.cpp utf8-character.h 
	g++ -c utf8-character.cpp

gbk-character.o:gbk-character.cpp gbk-character.h
	g++ -c gbk-character.cpp

base-character.o:base-character.cpp base-character.h
	g++ -c base-character.cpp

clean:
	rm -rf test $(objects) 

