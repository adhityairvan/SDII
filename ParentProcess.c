#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main() {
    pid_t child_pid;
    child_pid=fork();
    if(child_pid<0)printf("Pembuatan proses gagal");
    if(child_pid>0)printf("Pembuatan proses berhasil,parrent %d \nchild%d",(int)getppid(),(int)getpid());
    return 0;
}