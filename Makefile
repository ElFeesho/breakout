OBJS=main.o gamescene.o paddle.o ball.o block.o
LIBS=`pkg-config --libs sdl SDL_gfx` -L../sge -lsge
CFLAGS=`pkg-config --cflags sdl SDL_gfx` -g -O0 -I../sge
PROG=breakout

all:$(OBJS)
	g++ -o $(PROG) $(OBJS) $(LIBS)

%o:%cpp
	g++ $(CFLAGS) $< -c

clean:
	rm -f $(OBJS) $(PROG)
