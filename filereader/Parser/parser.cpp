#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include"parser.h"

using namespace std;

Parser::Parser()
{
    COLUMN_COUNT = 10;
    ROW_COUNT = 10;
    file_length = -1;
    int_word = -1;
    word_total = -1;
    word_column = -1;
    word_row = -1;
    word_index = -1;    
    for(int i = 0; i < 100; i++)
    {
        a[i] = NULL;
    }    
    file_read = NULL;    
    memset(type, 0, 10);
    memset(string_word, 0, 10);
    file_to_split = NULL;
};

Parser::~Parser()
{
    COLUMN_COUNT = 10;
    ROW_COUNT = 10;
    file_length = -1;
    int_word = -1;
    word_total = -1;
    word_column = -1;
    word_row = -1;
    word_index = -1;    
    for(int i = 0; i < 100; i++)
    {
        a[i] = NULL;
    }    
    file_read = NULL;    
    memset(type, 0, 10);
    memset(string_word, 0, 10);
    file_to_split = NULL;
}

int Parser::Init(void)
{
    if((file_to_split = fopen("file_input.txt", "r")) == NULL)
    {
        cout << "file open error";

        return -1;
    }

    file_length = GetFileLength(file_to_split);
    cout << "file length is" << file_length << "\n";

    file_read = (char*)malloc(file_length);

    FileRead(file_to_split, file_read, file_length);

    Word_Split(file_read, word_total, a);

    return 0;
}

int Parser::Uninit(void)
{
    if(file_read)
    {
        free(file_read);
        file_read = NULL;
    }

    fclose(file_to_split);
    
    return 0;
}

void Parser::Run(void)
{
    Init();

    printf("input row of word ( < %d ) : \n", ROW_COUNT);  //输入要处理的词语元素所在行
    scanf("%d", &word_row);
       
    printf("input column of word ( < %d ) : \n", COLUMN_COUNT);//输入要处理的词语元素所在列
    scanf("%d", &word_column); 
   
    printf("input type of word ( int, string ) : \n");
    scanf("%s", type);

    word_index = word_column + COLUMN_COUNT * ( word_row -1 ) - 1; //计算要处理词语所在的数组下标
    if(strcmp("int", type) == 0)          //如果输入的是int,按照int解析，
    {
        ConvertElement(a[word_index], &int_word);
        printf("row: %d, column: %d, type: %s, value: %d\n", word_row, word_column, type, int_word);   
    }
    if(strcmp("string", type) == 0)  //如果输入的是string,按照string解析，
    { 
        ConvertElement(a[word_index], string_word);
        printf("row: %d, column: %d, type: %s, value: %s\n", word_row, word_column, type, string_word);
    }

    Uninit();
}

//转换成整型
void Parser::ConvertElement(char* element, int* num)
{
    if(element != NULL)
    {
        sscanf(element, "%d", num);
    }
}

//转换成字符串
void Parser::ConvertElement(char* element, char* cha)
{
    if(element != NULL && cha != NULL)
    {
        char* source_element = element;
        char* dest_element = cha;
        while(*source_element != '\t' && *source_element != '\n' && *source_element != '\0')
        {
            *dest_element++ = *source_element++;
        }
        *dest_element ='\0';
    }
}

//词串分割成各个词语（\t和\n划分），word_list为待分割的文件首地址，用word_points指针指向各个词语的开头，
void Parser::Word_Split(char* word_list, int column_count, char ** word_points)
{
    int word_pos = 0;
    int i = 0;
    if(word_list == NULL && column_count < 0)
    {
        cout<< "input error"<<"\n";
    }
    word_points[word_pos] = &word_list[i];
    word_pos++;
    for(i = 1; word_list[i] != '\0'; i++)
    {
        if( word_list[i] == '\t' || word_list[i] == '\n')
        {
            word_points[word_pos++] = &word_list[i+1];
        }  

    }
    printf("word_pos and column_ , i: %d %d %d\n", word_pos, column_count, i);
    if(word_pos != column_count)
    {
        cout << "split error: wrong counts of words output" << "\n";
    }
}

//读取文件字符个数
int Parser::GetFileLength(FILE *fp)
{
     int length;
     fseek(fp, 0, SEEK_END);
     length = ftell(fp);
     fseek(fp, 0, SEEK_SET);

     return length;
}

//把此表文件读入mem内存区，
int Parser::FileRead(FILE * file_fp, char * mem, int read_length)
{
   FILE *fp;
   int length = 0;
   char * mem_copy = mem;
   fp = file_fp;
   length = read_length; 
   length = GetFileLength(fp);
   fread(mem_copy, length, 1, fp);
   *(mem_copy+length-1) = '\0';

   return 0;
}

