CC = gcc
CFLAG = -Wall

PROGRAMM = temperature

SRCDIRS := $(addprefix ./, $(notdir $(patsubst '\n', ' ', $(shell find . -type d))))
SRCS := $(shell find . -depth -type f -name "*.c")
SRCS_NODIR := $(notdir $(SRCS))
OBJS := $(SRCS:.c=.o)
OBJS_NODIR := $(notdir $(OBJS))

RELDIR = release
RELBIN = $(RELDIR)/$(PROGRAMM)
RELCFLAGS = $(CFLAG) -O3
RELOBJS = $(addprefix $(RELDIR)/, $(OBJS_NODIR))

DBGDIR = debug
DBGBIN = $(DBGDIR)/$(PROGRAMM)
DBGCFLAGS = $(CFLAG) -O0 -g
DBGOBJS = $(addprefix $(DBGDIR)/, $(OBJS_NODIR))

VPATH := SOURCES_DIRS

#override compile_flags += -pipe

.PHONY:	all clear report run

all: prep release

#$(PROGRAMM): $(OBJS)
#	$(CC) $^ -o $@

#%.o: %.c
#	$(CC) -c -MD $(RELCFLAGS) $(addprefix -I, $(SRCS)) -o $@ $<

release: $(RELBIN)

$(RELBIN): $(RELOBJS)
	$(CC) $(RELCFLAGS) -o $@ $^

$(RELDIR)/%.o: %.c
	$(CC) -c -MD $(RELCFLAGS) -o $@ $<

debug: $(DBGBIN)

$(DBGBIN): $(DBGOBJS)
	$(CC) $(DBGCFLAGS) -o $@ $^

$(DBGDIR)/%.o: %.c
	$(CC) -c -MD $(DBGCFLAGS) -o $@ $<

prep:
	@mkdir -p $(DBGDIR) $(RELDIR)

clear:
	rm 	$(RELDIR)/$(PROGRAMM) \
	 	$(DBGDIR)/$(PROGRAMM) \
		$(RELDIR)/$(OBJS) \
		$(DBGDIR)/$(OBJS) \
		$(patsubst %.c, %.d, $(RELDIR)/$(SRCS_NODIR)) \
		$(patsubst %.c, %.d, $(DBGDIR)/$(SRCS_NODIR))

include $(wildcard *.d)

test:
	@echo SRCDIRS: $(SRCDIRS)
	@echo SRCS: $(SRCS)
	@echo OBJS: $(OBJS)
	@echo
	@echo SRCS_NODIR: $(SRCS_NODIR)
	@echo OBJS_NODIR: $(OBJS_NODIR)
	@echo
	@echo RELOBJS: $(RELOBJS)
	@echo DBGOBJS: $(DBGOBJS)
