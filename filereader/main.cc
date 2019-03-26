#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#define COLUMN_COUNT 10
#define ROW_COUNT 10
using namespace std;
void ConvertElement(char* element, int* num);
void ConvertElement(char* element, char* cha);
void Word_Split(char * word_list, int column_count, char ** word_points);
int FileRead(FILE * file_fp, char* mem, int read_length);
int GetFileLength(FILE * fp);
int main()
{
   char * file_read; //词表文件整个读入放入file_read指向的char内存区
   FILE * file_to_split; //文件指针，指向要读取的词表文件
   int file_length,int_word;// file_length存放词表文件字符总个数，int_word存放解析出来的某个整型数
   int word_total = COLUMN_COUNT * ROW_COUNT; //词表中的词语总个数
   char * a[ word_total ]; //一个指针数组，后续操作实现每个指针将指向file_read一个词，
   char type[10],string_word[10]; //type用于存放词语类型，string或者int等，
   int word_column,word_row,word_index;//file_length存放词表文件字符总个数，int_word存放解析出来的某个字符串词语，
   if((file_to_split = fopen("file_input.txt","r"))==NULL)
   {
       cout<<"file open error";
       return 0;
   }
   file_length = GetFileLength(file_to_split);
   cout<<"file length is"<<file_length<<"\n"; 
   file_read = (char*) malloc(file_length); //给file_read指针分配file_length个字节
   FileRead(file_to_split,file_read,file_length); //把整个文件中的词语顺序读出放到file_read中，
   Word_Split(file_read,word_total,a);//分割词语，用指针数组a中的指针分别指向每个词语的起始字符
  
   printf("input row of word ( < %d ) : \n",ROW_COUNT);  //输入要处理的词语元素所在行
   scanf("%d", &word_row); 
   
   printf("input column of word ( < %d ) : \n",COLUMN_COUNT);//输入要处理的词语元素所在列
   scanf("%d", &word_column); 
  
   
   printf("input type of word ( int, string ) : \n");
   scanf("%s", type);

   word_index = word_column + COLUMN_COUNT * ( word_row -1 ) -1 ; //计算要处理词语所在的数组下标
   if(strcmp("int",type)==0)          //如果输入的是int,按照int解析，
   {
        
       ConvertElement(a[word_index],&int_word);
       printf("row: %d, column: %d, type: %s, value: %d\n",word_row,word_column,type,int_word);
   
   }
   if(strcmp("string",type)==0)  //如果输入的是string,按照string解析，
   {
        
 
   ConvertElement(a[word_index],string_word);
   printf("row: %d, column: %d, type: %s, value: %s\n",word_row,word_column,type,string_word);
    }
//   ConvertElement(a[2],&x);
 //  printf(" a[2] number is %d\n",x);
   
   free(file_read);  
   fclose(file_to_split); 
   return 0;
}

