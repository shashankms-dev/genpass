CC=gcc
INSTALL_DIR=/usr/local/bin/
TARGET=passgen

$(TARGET): main.c
	$(CC) $^ -o $@

install:
	cp -f $(TARGET) $(INSTALL_DIR)

uninstall:
	rm $(INSTALL_DIR)$(TARGET)

clean:
	rm -f $(TARGET)
