CC := gcc
CFLAGS := -Wall -Wextra -pedantic -std=c99
TARGET = futurerestore
OBJS = futurerestore.o
COMMANDS = -o futurerestore -lcurl

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(COMMANDS)

.PHAUNY: clean

clean:
	$(RM) $(OBJS) $(TARGET)
