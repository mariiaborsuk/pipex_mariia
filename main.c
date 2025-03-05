#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include "pipex.h"

char *get_path(char **envp)
{
	int i =0;
	while(envp[i]!=NULL)
	{
		if(strncmp("PATH=", envp[i], 5)==0)
			return envp[i]+5;
		i++;
	}
	return NULL;
}
int main(int argc, char *argv[], char *envp[])
{
	char *path_p=get_path(envp);
	printf("Pointer %s\n", path_p);
	if(argc==5)
	{
		int fd[2];

	if(pipe(fd)==-1)
	{
		return 1;
	}
	int pid1=fork();
	if(pid1<0)
	{
		return 2;
	}
	if(pid1==0)
	{
		int fd_in=open(argv[1], O_RDONLY);
		dup2(fd_in, STDIN_FILENO);
		close(fd_in);
		dup2(fd[1],STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		char **ar=ft_split(argv[2], ' ');
		char *path=ft_strjoin("/usr/bin/", ar[0]);
		// char **env[]={NULL};
		execve(path, ar, envp);
	}
	int pid2=fork();
	if(pid2<0)
	{
		return 3;
	}
	if(pid2==0){
		int fd_in2=open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
		dup2(fd[0], STDIN_FILENO);
		// close(fd[0]);
		dup2(fd_in2, STDOUT_FILENO);
		close(fd_in2);
		close(fd[0]);
		close(fd[1]);
		char **ar=ft_split(argv[3], ' ');
		char *path=ft_strjoin("/usr/bin/", ar[0]);
		// char **env[]={NULL};
		execve(path, ar, envp);


	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);

	}
	return 0;
}
