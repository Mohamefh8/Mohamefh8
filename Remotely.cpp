#include <stdio.h>
#include <stdlib.h>

char *strstrstr(char *str, char *front, char *rear)
{
	if (!str || !front || !rear)
		return NULL;
	char *s;
	char *t;
	while (*str)
	{
		s = str;
		t = front;
		while (*s == *t)
		{
			s++;
			t++;
			if (!*t)
			{
				str = s;
				char *old = str;
				do
				{
					s = str;
					t = rear;
					while (*s == *t)
					{
						s++;
						t++;
						if (!*t)
						{
							int charlen = str - old;
							char *newstr = (char *)malloc(charlen + 1);
							strncpy(newstr, old, charlen);
							newstr[charlen] = '\0';
							return newstr;
						}
					}
					str++;
				}
				while (*str);
				return NULL;
			}
		}
		str++;
	}
	return NULL;
}

int main(void)
{
	FILE *fp;
	char buf[BUFSIZ];
	if (NULL != (fp = popen("curl https://pastebin.com/raw/q9eSTagk","r")))
		fread(buf, BUFSIZ, 1, fp);
	else
	{
		fprintf(stderr, "Error...\n");
		exit(1);
	}


	char *kg = strstrstr(buf, "【switch】", "【switch】");
	char *edition = strstrstr(buf, "【version】", "【version】");
	char *Notice = strstrstr(buf, "【Ann】", "【Ann】");

	printf("\nSwitch ：%s\n", kg);
	printf("\nVersion ：%s\n", edition);
	printf("\nAnnouncement ：%s\n", Notice);
	pclose(fp);
	return 0;
}





/*
【switch】open【switch】

【version】1.0【version】

【Ann】There is no announcement for now【Ann】
*/