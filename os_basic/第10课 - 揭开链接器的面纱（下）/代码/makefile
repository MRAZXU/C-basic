
CC := gcc
LD := ld
RM := rm -fr

TARGET := program.out
SRC := $(TARGET:.out=.c)
OBJ := $(TARGET:.out=.o)
LDS := $(TARGET:.out=.lds)

.PHONY : rebuild clean all

$(TARGET) : $(OBJ) $(LDS)
	$(LD) -static -T $(LDS) -o $@ $<
	@echo "Target File ==> $@"
	
$(OBJ) : $(SRC)
	$(CC) -fno-builtin -o $@ -c $^
	
rebuild : clean all

all : $(TARGET)

clean :
	$(RM) $(TARGET) $(OBJ)
	
	