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
    int sum=0;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            for(int k=0;k<size;k++)
            {
                //temp.m[i][j]=(m[i][j]*b.m[i][j])+(m[i][j+1]*b.m[i+1][j]);
                sum=sum+(m[i][k]*b.m[k][j]);
            }
            temp.m[i][j]=sum;
            sum=0;
        }
    }
    return temp;
}