PROGS = cryptpw
SUPPORT = getpasswd.c getpass.c
PROGSRCS = $(PROGS:=.c)
PROGOBJS = $(PROGSRCS:.c=.o)
SRCS = $(filter-out $(PROGSRCS) $(SUPPORT), $(wildcard *.c))
HDRS = $(wildcard *.h)
SUPPOBJS = $(SUPPORT:.c=.o)
OBJS = $(SRCS:.c=.o)

ifneq (,$(DEBUG))
override CFLAGS+=-fPIC -Wall -O0 -g
else
override CFLAGS+=-fPIC -O3
endif

default: $(OBJS) libcrypt.a
all: $(OBJS) libcrypt.a cryptpw

%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c -o $@ $<

libcrypt.a: $(OBJS)
	$(AR) cru $@ $^

libsupp.a: $(SUPPOBJS)
	$(AR) cru $@ $^

$(PROGS): %: %.o libcrypt.a libsupp.a
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

clean:
	rm -f libcrypt.a libsupp.a $(OBJS) $(PROGOBJS) $(SUPPOBJS) $(PROGS)
