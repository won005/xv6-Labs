// 명령줄 인자를 화면에 출력하는 프로그램

#include "kernel/types.h" // uint, int 기본 타입 정의
#include "kernel/stat.h" 
#include "user/user.h" // write, strlen, exit 등 사용자 함수 선언

int
main(int argc, char *argv[])
/*
argc : 인자 개수
echo hello world -> argc =3

argv [0] = echo
argv [1] = hello
argv [2] = world
*/

{
  int i;

  for(i = 1; i < argc; i++){ //[0] 은 이름이니까 건너뜀
    write(1, argv[i], strlen(argv[i])); // 1: stdout 출력, argv[i]출력할 문자열, strlen()문자열 길이
    
    if(i + 1 < argc){
      write(1, " ", 1);
    } else {
      write(1, "\n", 1);
    }
  }
  exit(0);
}
