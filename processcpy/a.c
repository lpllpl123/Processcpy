#include"pcpy.h"

int procreate(const char *SFile,const char *DFile,int pronum,int blocksize)
{
	int flag;
	pid_t pid;
	int pos;
	char cpos[10];
	char cblock[10];
	bzero(cpos,sizeof(cpos));
	bzero(cblock,sizeof(cblock));
	for(flag=0;flag<pronum;flag++)
		{
			pid=fork();
			if(pid==0)
				break;
		}
	if(pid>0)
	{
		printf("Parent Pro pid[%d] 非阻塞回收..\n",getpid());
		pid_t zpid;
		while((zpid=waitpid(-1,NULL,WNOHANG))!=-1)
		{
			if(zpid>0)
				printf("Parent Wait Success zombie pid [%d] \n",zpid);
		}

	}
	else if(pid ==0)
	{
		pos =flag*blocksize;
		sprintf(cblock,"%d",blocksize);
		sprintf(cpos,"%d",pos);
		execl("/home/colin/20210322/Process/processcpy/Copy","./Copy",SFile,DFile,cblock,cpos,NULL);
	}
	else
	{
		perror("forx call failed");
		exit(-1);
	}
   return 0;
}
