/*
Assignment#1Exercise#3
Named pipe
Author: Ishan Tiwari
	Shashi Ravula Reddy
*/
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>

#define MAX_BUF 120

int main()
{
    int fd,count=0;
    char * myfifo = "/tmp/myfifo";
    char buf[MAX_BUF];

    /* open, read, and display the message from the FIFO */
    fd = open(myfifo, O_RDONLY);
	while (count<sizeof(buf))
	
	{
		ssize_t x = read(fd, buf, MAX_BUF);
			if(x==0)
			exit(1);
		printf("String consumed by the consumer\n %s",buf);
		printf("Enter the new string or Press Enter to Exit\n");
		count++;
	}
 
    close(fd);

    return 0;
}
