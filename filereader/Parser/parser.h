#include<iostream>
using namespace std;

class Parser
{
public:
    Parser();
    ~Parser();
    void Run(void);
    
protected:
    int Init(void);
    int Uninit(void);
    void ConvertElement(char* element, int* num);
    void ConvertElement(char* element, char* cha);
    void Word_Split(char * word_list, int column_count, char ** word_points);
    int FileRead(FILE * file_fp, char* mem, int read_length);
    int GetFileLength(FILE * fp);

private:
    int COLUMN_COUNT;
    int ROW_COUNT;
    int file_length;
    int int_word;
    int word_total;
    int word_column;
    int word_row;
    int word_index;
    char * a[100];
    char * file_read;
    char type[10];
    char string_word[10];
    FILE * file_to_split;
};
