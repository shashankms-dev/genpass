CC=gcc
CFLAGS=-Wall -O2
INSTALL_DIR=/usr/local/bin/
TARGET=pass-gen

$(TARGET): main.c
	$(CC) $(CFLAGS) $^ -o $(TARGET)

install:
	cp -f $(TARGET) $(INSTALL_DIR)

uninstall:
	rm $(INSTALL_DIR)$(TARGET)

clean:
	rm -f $(TARGET)
