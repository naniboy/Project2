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
  printf("size compare\n"); 
 if(0>stat("text1",&stat1)) 
 { 
  printf("text1 is not in  file\n"); 
  return; 
} 
  else if(0>stat("text2",&stat2)) 
  { 
printf("%d\n",(int)stat1.st_size); 
return; 
} 
 
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
 if(0>stat("text1",&stat1)) 
 { 
  printf("text1 is not in  file\n"); 
  return; 
} 
  else if(0>stat("text2",&stat2)) 
  { 
printf("%d\n",(int)stat1.st_blocks); 
return; 
} 
 
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
} 
 
void timecmp(void) 
{ 
} 