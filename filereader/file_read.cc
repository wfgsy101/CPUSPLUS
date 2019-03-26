#include<stdio.h>
#include<stdlib.h>
#include<iostream>
//#define SEEK_END 2
//#define SEEK_SET 0
using namespace std;

//读取文件字符个数
int GetFileLength(FILE *fp)
{
     int length;
     fseek(fp,0,SEEK_END);
     length = ftell(fp);
     fseek(fp,0,SEEK_SET);
     return length;
}
//把此表文件读入mem内存区，
int FileRead( FILE * file_fp, char * mem, int read_length)
{
   FILE *fp;
   int length = 0;
   char * mem_copy = mem;
   fp=file_fp;
   length = read_length; 
   length = GetFileLength(fp);
   fread(mem_copy,length,1,fp);
   *(mem_copy+length-1)='\0';
   return 0;
}

