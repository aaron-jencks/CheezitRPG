CC=gcc
CFLAGS=-Wall -O3
DEBUG=-Wall -g -Ddebug
INCLUDES=-I./astera/include -I./astera/dep/stb -L./astera/build -lastera -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl -lm -lopenal

COMPILE=$(CC) $(CFLAGS) -o $(1) -c $(2)

ifeq ($(MAKECMDGOALS),debug)
	FLAGS := $(DEBUG)
endif

OBJS=arraylist.o error.o

all: astera/build/libastera.a $(OBJS)
	$(CC) $(CFLAGS) -o main main.c $(OBJS) $(INCLUDES)

debug: astera/build/libastera.a $(OBJS)
	$(CC) $(CFLAGS) -o main main.c $(OBJS) $(INCLUDES)

astera/build/libastera.a: 
	cd astera && cmake -Bbuild -S. -DCMAKE_BUILD_TYPE=Release && cmake --build build 

%.o: %.c %.h
	$(call COMPILE,$@,$<)

.PHONY:clean
clean:
	rm main $(OBJS)
	rm -rf ./astera/build