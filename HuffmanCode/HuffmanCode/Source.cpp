#include<iostream>
#include<stdlib.h>
#include <fstream>
#include "Node.h"
#include "BInary.h"
#define len 100                                           
using namespace std;
using std::ifstream;

void findChar(int k, char c, char arr[], int count[])
{
    int i;
    for (i = 0; i < len - 1; i++)
    {
        if (arr[i] == c)
        {
            count[i]++;
            return;
        }
    }
    arr[i++] = c;
    return;
}

void getData()
{
   
    string myfile("Test.txt");
    string arr[len];
    int count[len] = { 1 };
    FILE* stream;
    errno_t err = fopen_s(&stream, myfile.c_str(), "r");
    if (err != 0) 
    {
        cout << "Could not open file" << endl;
    }
    char c;
    while ((c = fgetc(stream)) != EOF) 
    {
        std::string data;
        data = c;
        
    }
    
    return;

}




int main() {
    
    getData();
   
    

    return 0;
    
}
