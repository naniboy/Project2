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
	stat("./text1", &stat1);
}

void filestat2(void)
{
	stat("./text2", &stat2);
}

void filetime1(void)
{
	time1 = localtime(&stat1.st_mtime);
/*
	printf("- text1 last modified time -\n");
	printf("%d:%d\n", time1->tm_hour, time1->tm_min);
*/
}

void filetime2(void)
{
	time2 = localtime(&stat2.st_mtime);
/*
	printf("- text2 last modified time -\n");
	printf("%d:%d\n", time2->tm_hour, time2->tm_min);
*/
}

void sizecmp(void)
{
  printf("size compare\n");

if((int)stat1.st_size>(int)stat2.st_size)
{
  printf("text1 is bigger\n\n");
}else if((int)stat1.st_size==(int)stat2.st_size)
{  printf("size are equal\n\n");

}else
{
  printf("text2 is bigger\n\n");
}
}
void blockcmp(void)
{
  printf("block compare\n");


if((int)stat1.st_size>(int)stat2.st_blocks)
{
  printf("text1 is bigger\n\n");
}else if((int)stat1.st_size==(int)stat2.st_blocks)
{  printf("size are equal\n\n");

}else
{
  printf("text2 is bigger\n\n");
}
}

void datecmp(void)
{
	printf("date compare\n");
	if(localtime(&(stat1.st_mtime))->tm_mon > localtime(&(stat2.st_mtime))->tm_mon)
		printf("text2 is updated earlier\n");

	else if(localtime(&(stat1.st_mtime))->tm_mon < localtime(&(stat2.st_mtime))->tm_mon)	
		printf("text1 is updated earlier\n");

	else{
		if(localtime(&(stat1.st_mtime))->tm_mday > localtime(&(stat2.st_mtime))->tm_mday)
			printf("text2 is updated earlier\n");

		else if(localtime(&(stat1.st_mtime))->tm_mday < localtime(&(stat2.st_mtime))->tm_mday)
			printf("text1 is updated earlier\n");

		else
			printf("same date\n");
	}

	printf("\n");
}

void timecmp(void)
{

	printf("time compare\n");
	if(localtime(&(stat1.st_mtime))->tm_hour > localtime(&(stat2.st_mtime))->tm_hour)
		printf("text2 is updated earlier\n");

	else if(localtime(&(stat1.st_mtime))->tm_hour < localtime(&(stat2.st_mtime))->tm_hour)	
		printf("text1 is updated earlier\n");

	else{
		if(localtime(&(stat1.st_mtime))->tm_min > localtime(&(stat2.st_mtime))->tm_min)
			printf("text2 is updated earlier\n");

		else if(localtime(&(stat1.st_mtime))->tm_min < localtime(&(stat2.st_mtime))->tm_min)
			printf("text1 is updated earlier\n");

		else
			printf("same date\n");
	}

	printf("\n");

}
