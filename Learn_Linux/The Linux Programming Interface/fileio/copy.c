//
//  copy.c
//  LearnLinux
//
//  Created by 孙楷 on 22/7/19.
//  Copyright © 2019 孙楷. All rights reserved.
//

#include <sys/stat.h>
#include <fcntl.h>
#include "tlpi_hdr.h"

#ifndef BUF_SZE
#define BUF_SIZE 1024
#endif

int main(int argc,char *argv[])
{
    //简单的复制操作
    //将源文件复制到新文件当中
    int inputFd,outputFd,openFlags;
    mode_t filePerms;
    ssize_t numRead;
    char buf[BUF_SIZE];
    
    if(argc!=3||strcmp(argv[1], "--help")==0)
    {
        usageErr("%s old-file new-file\n",argv[0]);
    }
    inputFd=open(argv[1],O_RDONLY);
    if(inputFd==-1)
        errExit("opening file %s",argv[1]);
    
    openFlags=O_CREAT|O_WRONLY|O_TRUNC;
    filePerms=S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH;
    outputFd=open(argv[2],openFlags,filePerms);
    if(outputFd==-1)
        errExit("opening file %s",argv[2]);
    
    //开始复制数据
    while((numRead=read(inputFd,buf,BUF_SIZE))>0)
    {
        if(write(outputFd,buf,BUF_SIZE)!=numRead)
        {
            fatal("could not write whole buffer");
        }
    }
    if(numRead==-1)
        errExit("read");
    if(close(inputFd)==-1)
        errExit("close input");
    if(close(outputFd)==-1)
        errExit("close output");
    exit(EXIT_SUCCESS);
}