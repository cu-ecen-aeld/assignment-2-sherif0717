SOURCES = ./writer.c

# Platform Overrides
#CROSS_COMPILE=HOST

# General Flags for all platforms
CFLAGS = \
                        -Wall \
                        -Werror \
                        -g \
                        -O0
TARGET = writer

ifeq ($(CROSS_COMPILE),aarch64-none-linux-gnu-)
	# @echo compile using cross-compiler
	CC = aarch64-none-linux-gnu-gcc
else
	# @echo compile using host Platform compiler
	CC = gcc
endif

OBJS = $(SOURCES:.c=.o)

.PHONY: build clean

build: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $@

#generate the object file for all c-source files
%.o: %.c
	$(CC) -c $< $(CFLAGS) -o $@


clean:
	@echo removing all built files
	rm -f *.o $(TARGET)
