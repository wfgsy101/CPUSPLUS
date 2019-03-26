#include<iostream>
#include"parser.h"

using namespace std;

Parser::Parser()
{
    cout << "Constructor!" << endl;
};

Parser::~Parser()
{
    cout << "Destructor!" << endl;
}

void Parser::run()
{
    cout << "Parser is running!" << endl;
}
