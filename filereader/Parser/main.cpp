#include<iostream>
#include"parser.h"

using namespace std;

int main(int argc, char* argv[])
{
    Parser *pParser = new Parser;

    if(!pParser)
    {
        cout << "Memory error!" << endl;
    }

    pParser->Run();

    if(NULL != pParser)
    {
        delete pParser;
        pParser = NULL;
    }

    return 0;
}
