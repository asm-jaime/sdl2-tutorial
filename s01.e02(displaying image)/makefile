CXX = gcc

CFLAGS = -Wall -pedantic -Werror
LFLAGS = `sdl2-config --cflags --libs` -lSDL2 -lSDL2_image

BLDDIR = build

# object files to build.
OBJS = $(addprefix $(BLDDIR)/, init.o input.o graphics.o main.o)
PROG = tutorial02.out

# top-level rule to create the program.
all: dir $(BLDDIR)/$(PROG)
dir:
	mkdir -p $(BLDDIR)

# compiling other source files.
$(BLDDIR)/%.o: src/%.c src/%.h src/defs.h
	$(CXX) $(CFLAGS) -c -o $@ $<

# linking the program.
$(BLDDIR)/$(PROG): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LFLAGS)

# cleaning everything that can be automatically recreated with "make".
clean:
	rm $(PROG) *.o
