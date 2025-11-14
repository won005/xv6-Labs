// pipe 는 두 프로세스가 통신할 수 있게 하는 전달자
// IPC(inter- process communication. 프로세스간 통신) 을 코드로 구현해보는 것
// test

#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]){

    //pipe fork write read

    int parent_fd[2];
    int child_fd[2]; //parent, child 파일 디스크립터
    char get_buf[128]; //pingpong 메세지 받기

    // 단방향 두 개 = 양방향 하나
    pipe(parent_fd); //pipe 만들기
    pipe(child_fd);

    if(fork() == 0) //child
    {
        close(parent_fd[1]);
        read(parent_fd[0], get_buf,4); //read 4 바이트
        close(parent_fd[0]);

        printf("%d: received %s\n", getpid(),get_buf);

        close(child_fd[0]);
        write(child_fd[1],"pong",4);
        close(child_fd[1]);
    }
    else //parent 
    {
        close(parent_fd[0]);
        write(parent_fd[1],"ping",4);
        close(parent_fd[1]);

        close(child_fd[1]);
        read(child_fd[0], get_buf,4);
        close(child_fd[0]);

        printf("%d: received %s\n", getpid() , get_buf);
        
    }
    exit(0);
}

 