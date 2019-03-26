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
   char * file_read; 
   FILE * file_to_split; 
   int file_length,int_word;
   int word_total = COLUMN_COUNT * ROW_COUNT;
   char * a[ word_total ];
   char type[10],string_word[10];
   int word_column,word_row,word_index;
   if((file_to_split = fopen("file_input.txt","r"))==NULL)
   {
       cout<<"file open error";
       return 0;
   }
   file_length = GetFileLength(file_to_split);
   cout<<"file length is"<<file_length<<"\n"; 
   file_read = (char*) malloc(file_length); 
   FileRead(file_to_split,file_read,file_length); 
   Word_Split(file_read,word_total,a);
  
   printf("input row of word ( < %d ) : \n",ROW_COUNT);
   scanf("%d", &word_row); 
   
   printf("input column of word ( < %d ) : \n",COLUMN_COUNT);
   scanf("%d", &word_column); 
  
   
   printf("input type of word ( int, string ) : \n");
   scanf("%s", type);

   word_index = word_column + COLUMN_COUNT * ( word_row -1 ) -1 ; 
   if(strcmp("int",type)==0)
   {
        
       ConvertElement(a[word_index],&int_word);
       printf("row: %d, column: %d, type: %s, value: %d\n",word_row,word_column,type,int_word);
   
   }
   if(strcmp("string",type)==0)
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

