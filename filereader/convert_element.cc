#include<stdio.h>
#include<iostream>
using namespace std;
//转换成整型
void ConvertElement( char*  element, int* num)
{
   if(element != NULL)
   {
       sscanf(element, "%d",num);
   }

}
//转换成字符串
void ConvertElement( char* element, char* cha)
{

    if(element != NULL && cha != NULL)
    {
        char*  source_element = element;
        char* dest_element = cha;
        while(*source_element != '\t' && *source_element != '\n' && *source_element != '\0')
        {
            *dest_element++ = *source_element++;
        }
        *dest_element ='\0';
    }
}
//词串分割成各个词语（\t和\n划分），word_list为待分割的文件首地址，用word_points指针指向各个词语的开头，
void Word_Split( char* word_list, int column_count, char ** word_points)
{

    int word_pos = 0;
    int i = 0;
    if(word_list == NULL && column_count < 0)
    {
        cout<< " input error"<<"\n";
    }
    word_points[word_pos] = &word_list[i];
    word_pos++;
    for(i=1; word_list[i] != '\0'; i++)
    {
        if( word_list[i] =='\t' || word_list[i] == '\n')
        {
            word_points[word_pos++]=&word_list[i+1];
        }  

    }
    printf("word_pos and column_ ,i: %d %d %d\n",word_pos, column_count,i);
    if(word_pos != column_count)
    {
        cout<<" split error: wrong counts of words output"<<"\n";
    } 
     
        
}

/*void Word_Split( char* word_list, int column_count, char ** word_points)
{

    int word_pos = 0;
    int i = 0;
    if(word_list == NULL && column_count < 0)
    {
        cout<< " input error"<<"\n";
    }
    word_points[word_pos] = &word_list[i];
    word_pos++;
    for(i=1; word_list[i] != '\n' && word_list[i] != '\0'; i++)
    {
        if( word_list[i] =='\t')
        {
            word_points[word_pos++]=&word_list[i+1];
        }  

    }
    if(word_pos != column_count)
    {
        cout<<" split error: wrong counts of words output"<<"\n";
    } 
     
        
}*/
