//echo.c 파일 참고


#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
  // 인자 개수 확인 (에러 처리)
  if(argc != 2){
    fprintf(2, "Usage: sleep <ticks>\n"); 
    exit(1);
  }
  
  // 문자열을 정수로 변환
  int ticks = atoi(argv[1]);
  
  // sleep 시스템 콜 호출
  sleep(ticks);
  
  // 종료
  exit(0);
}