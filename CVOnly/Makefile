TGT=cvsample
CFLAGS=$(shell pkg-config --cflags opencv)
LFLAGS=$(shell pkg-config --libs opencv)
all: main.o
	gcc $^ -o $(TGT) $(LFLAGS)
%.o:%.c
	gcc -c $^ $(CFLAGS)
clean:
	rm -f *.o $(TGT)
