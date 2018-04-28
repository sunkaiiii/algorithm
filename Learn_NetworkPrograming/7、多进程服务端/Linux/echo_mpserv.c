#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>
#include<arpa/inet.h>
#include<sys/socket.h>

//基于多任务的并发服务器

#define BUF_SIZE 30
void error_handling(char *message);
void read_childproc(int sig);

int main(int argc,char *argv[])
{
  if(argc!=2)
  {
    printf("Usage :%s <port>\n",argv[0]);
    exit(1);
  }
  int serv_sock,clnt_sock;
  struct sockaddr_in serv_adr,clnt_adr;
  pid_t pid;
  struct sigaction act;
  socklen_t adr_sz;
  int str_len,state;
  char buf[BUF_SIZE];
  act.sa_handler=read_childproc; //当信号捕获时，触发的方法
  //初始化信号集合
  sigemptyset(&act.sa_mask);
  act.sa_flags=0;
  state=sigaction(SIGCHLD,&act,0); //捕获子进程的进程终止信号
  serv_sock=socket(PF_INET,SOCK_STREAM,0);
  memset(&serv_adr,0,sizeof(serv_adr));
  serv_adr.sin_family=AF_INET;
  serv_adr.sin_addr.s_addr=htonl(INADDR_ANY);
  serv_adr.sin_port=htons(atoi(argv[1]));
  if(bind(serv_sock,(struct sockaddr*)&serv_adr,sizeof(serv_adr))==-1)
    error_handling("bind() error");
  if(listen(serv_sock,5)==-1)
    error_handling("listen() erorr");

  while(1)
  {
    adr_sz=sizeof(clnt_adr);
    clnt_sock=accept(serv_sock,(struct sockaddr*)&clnt_adr,&adr_sz);
    if(clnt_sock==-1)
      continue;
    else
      puts("new client connected");

    pid=fork();
    if(pid==-1)
    {
      close(clnt_sock);
      continue;
    }
    else if(pid==0) //子进程区域
    {
      close(serv_sock); //fork了之后回复制原有的套接字描述符，所以要关闭一个servsock
      while((str_len=read(clnt_sock,buf,BUF_SIZE))!=0)
        write(clnt_sock,buf,str_len);

      close(clnt_sock);
      puts("client disconnected....");
      return 0;
    }
    else
      close(clnt_sock); //客户端连接的任务由子进程完成
  }
  close(serv_sock);
  return 0;
}

void read_childproc(int sig)
{
  pid_t pid;
  int status;
  pid=waitpid(-1,&status,WNOHANG); //防止僵尸进程，传入-1等同于使用wait()
  printf("removed pro id :%d\n",pid);
}

void error_handling(char *message)
{
  fputs(message,stderr);
  fputc('\n',stderr);
  exit(1);
}
