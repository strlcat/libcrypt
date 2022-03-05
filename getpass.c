#include <stddef.h>
#include <string.h>
#include "getpasswd.h"

char *xgetpass(const char *prompt)
{
	static char pwd[256];
	struct getpasswd_state getps;

	memset(pwd, 0, sizeof(pwd));
	memset(&getps, 0, sizeof(struct getpasswd_state));

	getps.fd = 0;
	getps.efd = 2;
	getps.passwd = pwd;
	getps.pwlen = sizeof(pwd)-1;
	getps.echo = prompt;
	getps.maskchar = 'x';

	if (getpasswd(&getps) >= 0) return pwd;
	return NULL;
}
