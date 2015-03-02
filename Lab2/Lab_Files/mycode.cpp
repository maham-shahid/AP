#include <iostream>
#include "mycode.h"
using namespace std;

matrix::matrix()
{
	size=2;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            m[i][j]=0;
        }
    }
}

matrix::matrix(int x)
{
    size=2;
    int array[]={1,2,3,4};
    int pointer=0;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            // std::cout<<"Enter value: ";
            // std::cin>>m[i][j];
            m[i][j]=array[pointer];
            pointer++;
        }
    }
}

void matrix::display()
{
    std::cout<<endl;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            std::cout<<m[i][j]<<" ";
        }
        std::cout<<endl;
    }
}

matrix matrix::operator +(matrix b)
{
    matrix temp;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            temp.m[i][j]=m[i][j]+b.m[i][j];
        }
    }
    return temp;
}

matrix matrix::operator -(matrix b)
{
    matrix temp;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            temp.m[i][j]=m[i][j]-b.m[i][j];
        }
    }
    return temp;
}

matrix matrix::operator *(matrix b)
{
    matrix temp;
    int turn=0;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(turn%2==0)
            {
                temp.m[i][j]=(m[i][j]*b.m[0][0])+(m[i][j+1]*b.m[1][0]);
            }
            else
            {
                temp.m[i][j]=(m[i][j-1]*b.m[0][1])+(m[i][j]*b.m[1][1]);
            }
            turn++;
        }
    }
    return temp;
}