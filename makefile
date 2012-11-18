CPP =g++
CFLAGS = -Wall -g -c
LDFLAGS = -o
COMMON_FILES = Common.h
EXECUTABLE = bnb.exe

OBJ_FILES := $(patsubst %.c,%.o,$(wildcard *.c))
COMMON_FILES = Common.h

$(EXECUTABLE): $(OBJ_FILES)
	@echo "Linking" $^
	@$(CPP) $(LDFLAGS) $@ $^

%.o : %.cpp %.h $(COMMON_FILES)
	@echo "Compiling" $<
	@$(CPP) $(CFLAGS) $<

clean:
	@echo "Cleaning up..."
	@rm -rf $(OBJ_FILES) $(EXECUTABLE)
