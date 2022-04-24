CC=gcc
INSTALL_DIR=/usr/local/bin/
TARGET=pass-gen
TEST_TARGET=pg

$(TEST_TARGET): main.c
	$(CC) $^ -o $@

build: main.c
	$(CC) -Wall -O2 $^ -o $(TARGET)

install:
	cp -f $(TARGET) $(INSTALL_DIR)

uninstall:
	rm $(INSTALL_DIR)$(TARGET)

clean:
	rm -f $(TARGET) $(TEST_TARGET)
