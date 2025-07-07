CFLAGS = -fPIC
LDFLAGS = -ldl
TARGET = calculator
LIB_NAME = libcalc.so

all: $(LIB_NAME) $(TARGET)

$(LIB_NAME): calc.c
	gcc $(CFLAGS) -shared $< -o $@

$(TARGET): main.c
	gcc $(CFLAGS) $< -o $@ $(LDFLAGS)

run: $(TARGET)
	LD_LIBRARY_PATH=. ./$(TARGET)

