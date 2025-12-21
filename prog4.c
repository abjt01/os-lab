//mkfifo.c
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
int main()
{
	int res;
	res=mkfifo("fifo1",0777);
	if(res==-1)
	{
		printf("named pipe is created");
	}
	else
	{
		printf("named pipe not created");
	}
}

//writer.c
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	int res,n;
	res=open("fifo1",O_WRONLY);
	write(res,"HelloWorld",10);
	printf("Sender PID %d has sent data\n", getpid());
	close(res);
	return 0;
}

//reader.c
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	int res,n;
	char buffer[100];
	res=open("fifo1",O_RDONLY);
	n=read(res,buffer,100);
	buffer[n]='\0';
	printf("reader with PID %d started \n",getpid());
	printf("Data received as  %s\n",buffer);
	close(res);
	return 0;
}