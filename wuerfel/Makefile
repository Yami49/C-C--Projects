CC = gcc
CFLAGS = -g -W -Wall -std=c11 -pedantic
RM = -rm -f

TARGET = wuerfeltest
OBJECTS = \
  wuerfel.o \
  quadrat.o \

SOURCES = $(TARGET).c $(OBJECTS:.o=.c)
HEADERS = $(OBJECTS:.o=.h)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean

all: $(TARGET)

clean:
	$(RM) $(TARGET) $(TARGET).o $(OBJECTS) depend

depend: $(SOURCES) $(HEADERS)
	$(CC) -MM $(SOURCES) > $@

$(TARGET): $(TARGET).o $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

include depend
