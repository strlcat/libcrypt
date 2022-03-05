#ifndef _GETPASSWD_H
#define _GETPASSWD_H

#define GETP_NOECHO 1
#define GETP_NOINTERP 2
#define GETP_WAITFILL 4

struct getpasswd_state;
struct termios;

typedef int (*getpasswd_filt)(struct getpasswd_state *, char, size_t);

struct getpasswd_state {
	char *passwd;
	size_t pwlen;
	const char *echo;
	char maskchar;
	getpasswd_filt charfilter;
	int fd;
	int efd;
	int error;
	struct termios *sanetty;
	int flags;
	size_t retn;
};

size_t getpasswd(struct getpasswd_state *getps);

#endif
