CC=gcc
CFLAGS= -lglut -lGLU -lGL
DEPS = laberinto.h resolverLaberinto.h
LDFLAGS = -framework GLUT -framework OpenGL

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

make: laberinto.o resolverLaberinto.o
	$(CC) -o progra resolverLaberinto.o laberinto.o $(CFLAGS)
                           
