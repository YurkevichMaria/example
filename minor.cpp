#include "minor.h"
#include <iostream>
#include <conio.h>
#include <cassert>
#include <stdlib.h>

using namespace std;

//constructor
minor::minor():
    n(0),
    m(0),
    M(0) {}

//constructor with parameter
minor::minor(int n, int m):
    n(n),
    m(m),
    M(0)
    {
        M=new int*[n];
        for (int i=0; i<n; i++)
            M[i]=new int[m];
    }

//copy constructor
minor::minor (const minor &old):
    n(old.n),
    m(old.m),
    M(0)
{
    M=new int*[n];
    for (int i=0; i<n; i++)
        M[i]=new int[m];

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            M[i][j]=old.M[i][j];
}

//operator =
minor &minor::operator=(const minor &eq)
{
    if(this!=&eq)
    {
        for (int i=0; i<n; i++)
            delete[] M[i];
        delete[] M;
        M=0;
        n=0;
        m=0;


        M=new int*[eq.n];
        for (int i=0; i<eq.n; i++)
            M[i]=new int[eq.m];
        n=eq.n;
        m=eq.m;


        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                M[i][j]=eq.M[i][j];
    }
    return *this;
}

//create a matrix
void minor::MatrInit()
{
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            M[i][j]=rand() % 15;
}

//output matrix
void minor::MatrPrint()
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cout.width(5);
            cout<<M[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}

//Enter numbers of rows and columns for minor
int** minor::FunNumbers(int DimOfMinor)
{
    cout<<"Enter numbers of rows and columns for minor: \n";
    int **ListNumbers=0;
    ListNumbers=new int*[2];
    for (int i=0; i<2; i++)
        ListNumbers[i]=new int[DimOfMinor];

    int k=n;
    for (int i=0; i<2; i++)
    {
        for (int j=0; j<DimOfMinor; j++)
        {
            cin>>ListNumbers[i][j];
            assert(ListNumbers[i][j]>0&&ListNumbers[i][j]<=k);
            k=m;
        }
        cout<<endl;
    }
    return ListNumbers;
}

//создание минора
minor minor::CreateMinor(int DimOfMinor, int** ListNumbers)
{
    minor newminor(DimOfMinor, DimOfMinor);
    int iM, jM;
    for (int i=0; i<DimOfMinor; i++)
    {
        iM=ListNumbers[0][i]-1;
        for (int j=0; j<DimOfMinor; j++)
        {
            jM=ListNumbers[1][j]-1;
            newminor.M[i][j]=M[iM][jM];
        }
    }


    for (int i=0; i<2; i++)
        delete[] ListNumbers[i];
    delete[] ListNumbers;
    ListNumbers=0;

    return newminor;
}

//+
minor minor::operator+(minor &ob)
{
    minor temp(ob.n, ob.m);
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            temp.M[i][j]=M[i][j]+ob.M[i][j];
    return temp;
}

//-
minor minor::operator-(minor &ob)
{
    minor temp(ob.n, ob.m);
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            temp.M[i][j]=M[i][j]-ob.M[i][j];
    return temp;
}

//*
minor minor::operator*(minor &ob)
{
   int res;
    minor temp(ob.n, ob.m);
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
        {
            res=0;
            for(int k=0; k<n; k++)
            res+=M[i][k]*ob.M[k][j];
            temp.M[i][j]=res;
        }
    return temp;
}

//matrix multiplication by a constant
minor minor::multiplByConst(minor ob, int c)
{
    minor res(ob.n, ob.m);
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            res.M[i][j]=c*ob.M[i][j];
    return res;
}

//destructor
minor::~minor()
{
    for (int i=0; i<n; i++)
        delete[] M[i];
    delete[] M;
    M=0;
    n=0;
    m=0;
}
