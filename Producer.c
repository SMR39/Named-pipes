/*
Assignment#1Exercise#3
Named pipe
Author: Ishan Tiwari
	Shashi Ravula Reddy
*/
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    int fd;
    char * myfifo = "/tmp/myfifo";
    char s[30];
    mknod(myfifo, S_IFIFO | 0666, 0);
    /* write s buffer to the FIFO */
    fd = open(myfifo, O_WRONLY);
    
	while((fgets(s,sizeof(s),stdin))[0]!= *"\n")
	{
		write(fd, s, sizeof(s));
	}
		close(fd);

    /* remove the FIFO */
    unlink(myfifo);

    return 0;
}
