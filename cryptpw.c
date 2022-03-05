#include <stdio.h>
#include "crypt.h"

extern char *xgetpass(const char *prompt);

static struct crypt_data cda;

int main(int argc, char **argv)
{
	char *salt, *pw, *res;

	if (argc < 2) salt = "$1$test$";
	else salt = argv[1];

	pw = xgetpass("Password: ");
	res = crypt_r(pw, salt, &cda);

	printf("%s\n", res ? res : "<error>");
	
	return 0;
}
