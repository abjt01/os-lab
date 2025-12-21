#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
	pid_t child_t;
	int status;
	printf("Parent Process Id is %d\n",getpid());
	child_t=fork();
	if (child_t<0)
	{
		perror("Fork Error");
		exit(1);
	}
	if (child_t==0)
	{
		printf("In child Process---Parent ID is %d, Child Process PID is %d\n",getppid(),getpid());
		char *args[]={"/bin/ls","-a","/",NULL};
		execv(args[0],args);
		printf("after exec command\n");
		perror("exec error");
		exit(1);
	}
	else
	{
	wait(&status);
	if(WIFEXITED(status))
	{
		printf("Child Process terminated with status: %d\n", WEXITSTATUS(status));
	}
	if(WIFSIGNALED(status))
	{
		printf("Child Process terminated with status: %d\n", WTERMSIG(status));
	}
	}
return 0;
}