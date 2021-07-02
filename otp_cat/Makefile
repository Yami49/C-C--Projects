#
# Makefile
# Georgios Gerontidis
# 1.07.21
#

CC = gcc
CFLAGS = -g -W -Wall -std=c11 -pedantic
RM = rm -f


TARGET1 = otp
TARGET2 = cat
SOURCES1 = $(TARGET1).c
SOURCES2 = $(TARGET2).c

TAR = tar
TARFLAGS = cvzf


%.tar.gz: %
	$(TAR) $(TARFLAGS) $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


.PHONY: all clean

all: $(TARGET1) $(TARGET2)

tar: $(TARGET1).tar.gz $(TARGET2).tar.gz

clean:
	$(RM) $(TARGET1) $(TARGET1).o $(TARGET1).tar.gz depend1
	$(RM) $(TARGET2) $(TARGET2).o $(TARGET2).tar.gz depend2

depend1: $(SOURCES1)
	$(CC) $(CFLAGS) -MM $(SOURCES1) > $@

depend2: $(SOURCES2)
	$(CC) $(CFLAGS) -MM $(SOURCES2) > $@


$(TARGET1): $(TARGET1).o
	$(CC) $(CFLAGS) $^ -o $@

$(TARGET2): $(TARGET2).o
	$(CC) $(CFLAGS) $^ -o $@


include depend1
include depend2
