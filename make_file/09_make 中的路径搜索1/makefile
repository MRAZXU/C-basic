
OBJS := func.o main.o
INC := inc
SRC := src
CFLAGS := -I $(INC)

vpath %.h $(INC)
vpath %.c $(SRC)

hello.out : $(OBJS)
	@gcc -o $@ $^
	@echo "Target File ==> $@"
	
# vpath %.h

$(OBJS) : %.o : %.c func.h
	@gcc $(CFLAGS) -o $@ -c $<
