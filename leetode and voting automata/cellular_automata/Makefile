CC = gcc
CFLAGS = -g -Wall -O0
INCLUDES = -IC:/msys64/ucrt64/include
LDFLAGS = -LC:/Windows/System32
LIBS = -lucrt -lmsvcrt -lmingw32 -ld2d1 -lmingwex

SOURCES = main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = main.exe

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJECTS) $(LDFLAGS) $(LIBS) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
