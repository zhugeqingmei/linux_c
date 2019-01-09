#include <gnu/libc-version.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "csapp.h"

//display the version of the glibc
void getLibCVersion()
{
    printf("%s\n",gnu_get_libc_version());
}

//open() and close()
void teseOpenClose()
{
    int fd;
    if((fd=open("/home/meng/codes/test/test/systemPro1.c",O_CREAT|O_WRONLY|O_TRUNC,0600))<0)
    {
        perror("open:");
        exit(1);
    }
    else{
        printf("Open file:%d\n",fd);
    }
    if(close(fd)<0)
    {

        perror("close:");
        exit(1);
    }
    else
    {

        printf("Close file.\n");
    }
    exit(0);
}

//csapp 10.1
void testCsapp10_1()
{
    int fd1,fd2;
    fd1=Open("/home/meng/codes/test/test/foo.txt",O_RDONLY,0);
    Close(fd1);
    fd2=Open("/home/meng/codes/test/test/baz.txt",O_RDONLY,0);
    printf("fd2=%d\n",fd2);
    exit(0);
}
void testWrite()
{
    int fd,size,len;
    char* buf="Hello!,I'm writing to this file!";
    char buf_r[10];
    len=strlen(buf);
    //must allow to read the file!!
    if((fd=open("/home/meng/codes/test/test/systemPro1.c",O_CREAT|O_RDWR|O_TRUNC,0600))<0)
    {
        perror("open:");
        exit(1);
    }
    else{
        printf("Open file:%d\n",fd);
    }

    if((size=write(fd,buf,len))<0)
    {
        perror("write:");
        exit(1);
    }else
    {

        printf("Write:%s\n",buf);
    }

    //reset the pointer of the file and read 10chars from the fhile
    lseek(fd,0,SEEK_SET);
    if((size=read(fd,buf_r,10))<0)
    {

        perror("read:\n");
        exit(1);
    }else
    {
        printf("read from file:%s\n",buf_r);
    }
    if(close(fd)<0)
    {
        perror("close:");
        exit(1);
    }else
        printf("Close .c file.\n");
    exit(0);
}
//test fcntl() function
void lockSet(int fd,int type)
{
    struct flock lock;
    //to lock the hole file use the three parameters
    lock.l_whence=SEEK_SET;
    lock.l_start=0;
    lock.l_len=0;
    while(1)
    {
        lock.l_type=type;
        if((fcntl(fd,F_SETLK64,&lock))==0)//only set the lock,can into the block
        {
            if(lock.l_type==F_RDLCK)
                printf("read lock set by %d\n",getpid());
            else if(lock.l_type==F_WRLCK)
                printf("write lock set by %d\n",getpid());
            else if(lock.l_type==F_UNLCK)
                printf("release lock set by %d\n",getpid());
            return;
        }
        fcntl(fd,F_GETLK64,&lock);//if cannot get the lock ,it can still know the lock type
        if(lock.l_type!=F_UNLCK)
        {

            if(lock.l_type==F_RDLCK)
                printf("read lock already set by %d\n",lock.l_pid);
            else if(lock.l_type==F_WRLCK)
                printf("write lock already set by %d\n",lock.l_pid);
            getchar();
        }
    }
}
//
void testLockSet()
{
    int fd;
    fd=open("hello",O_RDWR|O_CREAT,0666);
    if(fd<0)
    {
        perror("open");
        exit(1);
    }
    lockSet(fd,F_WRLCK);
    getchar();
    lockSet(fd,F_UNLCK);
    getchar();
    close(fd);
    exit(0);
}
//lear select cmd
void testSelect()
{
    int fds[2];
    char buf[7];
    int i,rc,maxfd,temp;
    fd_set inset1,inset2;
    struct timeval tv;

    if((fds[0]=open("hello1",O_RDWR|O_CREAT,0666))<0)
        perror("open hello1");
    if((fds[1]=open("hello2",O_RDWR|O_CREAT,0666))<0)
        perror("open hello2");
    //write something to fds[0]
    if((rc=write(fds[0],"Hello!\n",7)))
        printf("rc=%d\n",rc);
    lseek(fds[0],0,SEEK_SET);
    maxfd=fds[0]>fds[1]?fds[0]:fds[1];

    FD_ZERO(&inset1);
    FD_SET(fds[0],&inset1);

    FD_ZERO(&inset2);
    FD_SET(fds[1],&inset2);

    tv.tv_sec=2;
    tv.tv_usec=0;
    //FD_ISSET:Returns a non-zero value if the bit for the file descriptor fd is set in the file descriptor set pointed to by fdset, and 0 otherwise.
    while(FD_ISSET(fds[0],&inset1)||FD_ISSET(fds[1],&inset2))
    {
        if(select(maxfd+1,&inset1,&inset2,NULL,&tv)<0)
            perror("select");
        else{
            temp=FD_ISSET(fds[0],&inset1);
            printf("temp read:%d\n",temp);
            if(temp)
            {
                rc=read(fds[0],buf,7);
                if(rc>0)
                {
                    buf[rc]='\0';
                    printf("read:%s\n",buf);
                }else
                {
                    perror("read");
                }
                lseek(fds[0],0,SEEK_SET);
            }
            if(FD_ISSET(fds[1],&inset2))
            {
                rc=write(fds[1],buf,7);
                if(rc>0)
                {
                    buf[rc]='\0';
                    printf("rc=%d,write:%s\n",rc,buf);
                }else
                {
                    perror("write");
                }
            sleep(10);
            }
        }
    }
    exit(0);
}

void systemProMain()
{
    // getLibCVersion();
    //teseOpenClose();
    //testCsapp10_1();
    //testWrite();
    //testLockSet();
    //testSelect();
    
}






























