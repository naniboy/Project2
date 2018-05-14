#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

struct stat stat1, stat2;
struct tm *time1, *time2;

void filestat1(void);
void filestat2(void);
void filetime1(void);
void filetime2(void);
void sizecmp(void);
void blockcmp(void);
void datecmp(void);
void timecmp(void);

int main(void)
{
   filestat1();
   filestat2();
   filetime1();
   filetime2();
   sizecmp();
   blockcmp();
   datecmp();
   timecmp();
}

void filestat1(void)
{
}

void filestat2(void)
{
}

void filetime1(void)
{
}

void filetime2(void)
{
}

void sizecmp(void)
{
}

void blockcmp(void)
{
}

void datecmp(void)
{
	struct stat f1,f2;
	struct tm *t_f1, *t_f2;

	//파일 정보를 가져옵니다.
	stat("./text1",&f1);
	stat("./text2",&f2);

	//localtime()함수로 받아온 시간 정보를 tm구조체에 저장합니다.
	t_f1=*(localtime(&f1.st_mtime));
	t_f2=*(localtime(&f2.st_mtime));
	
	//두 tm 구조체를 비교 후 출력합니다.
	printf("date compare\n");
	if(t_f1.tm_mon > t_f2.tm_mon)
		printf("text2 is updated earlier\n");

	else if(t_f1.tm_mon < t_f2.tm_mon)	
		printf("text1 is updated earlier\n");

	else{
		if(t_f1.tm_mday > t_f2.tm_mday)
			printf("text2 is updated earlier\n");

		else if(t_f1.tm_mday < t_f2.tm_mday)
			printf("text1 is updated earlier\n");

		else
			printf("same date\n");
	}

	printf("\n");
}

void timecmp(void)
{
	
	struct stat f1,f2;
	struct tm t_f1, t_f2;
	
	//파일 정보를 가져옵니다.
	stat("./text1",&f1);
	stat("./text2",&f2);
	
	//localtime()함수로 받아온 시간 정보를 tm구조체에 저장합니다.
	t_f1=*(localtime(&f1.st_mtime));
	t_f2=*(localtime(&f2.st_mtime));
	
	//두 tm 구조체를 비교 후 출력합니다.
	printf("time compare\n");
	if(t_f1.tm_hour > t_f2.tm_hour)
		printf("text2 is updated earlier\n");

	else if(t_f1.tm_hour < t_f2.tm_hour)	
		printf("text1 is updated earlier\n");

	else{
		if(t_f1.tm_min > t_f2.tm_min)
			printf("text2 is updated earlier\n");

		else if(t_f1.tm_min < t_f2.tm_min)
			printf("text1 is updated earlier\n");

		else
			printf("same date\n");
	}

	printf("\n");

}