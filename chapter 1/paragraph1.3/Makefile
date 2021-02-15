CC = gcc
CFLAG = -Wall

PROGRAMM = temperature

SRCDIR = src
BIN = bin
DIRS := $(shell find . -type d)
SRCS:= $(notdir $(shell find . -depth -type f -name "*.c"))
OBJS:= $(SRCS:.c=.o)

RELDIR = release
RELBIN = $(RELDIR)/$(BIN)/$(PROGRAMM)
RELCFLAGS = $(CFLAG) -O3
RELOBJS = $(addprefix $(RELDIR)/, $(OBJS))

DBGDIR = debug
DBGBIN = $(DBGDIR)/$(BIN)/$(PROGRAMM)
DBGCFLAGS = $(CFLAG) -O0 -g
DBGOBJS = $(addprefix $(DBGDIR)/, $(OBJS))

VPATH := $(DIRS)

#override compile_flags += -pipe

.PHONY:	all prep clear test 

all: prep release

release: $(RELBIN)

$(RELBIN): $(RELOBJS)
	$(CC) $(RELCFLAGS) -o $@ $^

$(RELDIR)/%.o: %.c
	#-MD для создания списка зависимостей 
	#$(CC) -c -MD $(RELCFLAGS) -o $@ $<
	$(CC) -c $(RELCFLAGS) -o $@ $<

debug: prep $(DBGBIN)

$(DBGBIN): $(DBGOBJS)
	$(CC) $(DBGCFLAGS) -o $@ $^

$(DBGDIR)/%.o: %.c
	#-MD для создания списка зависимостей 
	#$(CC) -c -MD $(DBGCFLAGS) -o $@ $<
	$(CC) -c $(DBGCFLAGS) -o $@ $<

prep:
	@mkdir -p $(DBGDIR) $(RELDIR) $(RELDIR)/$(BIN) $(DBGDIR)/$(BIN)

clear:
	rm -f $(RELDIR)/$(BIN)/$(PROGRAMM) \
	 	$(DBGDIR)/$(BIN)/$(PROGRAMM) \
		$(RELDIR)/*.*\
		$(DBGDIR)/*.*

# Включает список зависимостей на основе которых сделан объектный файл
#include $(wildcard *.d)

test:
	@echo DIRS: $(DIRS)
	@echo SRCS: $(SRCS)
	@echo
	@echo SRCS: $(SRCS)
	@echo OBJS: $(OBJS)
	@echo
	@echo RELOBJS: $(RELOBJS)
	@echo DBGOBJS: $(DBGOBJS)
