TARGET	=	moon
CC		=	g++
CFLAGS	=	-g
OBJECTS = 	$(patsubst ./src/%.cpp,%.o,$(wildcard ./src/*.cpp))
INCLUDE	= 	-I./include/

export OBJSDIR = ${shell pwd}/OBJECTS
OBJ		=	${shell find $(OBJSDIR) -name *.o}

all:$(TARGET)

#objects = %.o:%.cpp

$(TARGET):$(OBJSDIR) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o:./src/%.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(OBJSDIR)/$@

$(OBJSDIR) :
	mkdir -p $(OBJSDIR)

clean:
	rm -rf test $(objects) 

