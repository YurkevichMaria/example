#include <iostream>
#include "minor.h"

using namespace std;

void byConst(minor[], int, int, int);
int main()
{
    int n, m;
    cout<<"Enter n = ";
    cin>>n;
    cout<<"Enter m = ";
    cin>>m;
    minor matr(n ,m);
    matr.MatrInit();
    matr.MatrPrint();
    int DimOfMatrix=min(n,m);

    int N;
    cout<<"enter the number of minors N = ";
    cin>>N;

    int k;
        if (k>DimOfMatrix)
            k=DimOfMatrix;

    minor *MasMinor=new minor[N];
    int DimOfMinor;
    cout<<"Enter the minor dimension = ";
    cin>>DimOfMinor;

    for (int i=0; i<N; i++)
    {
        MasMinor[i]=matr.CreateMinor(DimOfMinor, matr.FunNumbers(DimOfMinor));
        MasMinor[i].MatrPrint();
    }

//Sum of minors
    minor sum=MasMinor[0];
    for (int i=1; i<N; i++)
        sum=sum+MasMinor[i];
    cout<<"The sum of minors:\n";
    sum.MatrPrint();

//Difference of minors
    minor difference=MasMinor[0];
    for (int i=1; i<N; i++)
        difference=difference-MasMinor[i];
    cout<<"The difference of minors:\n";
    difference.MatrPrint();

//Product of minors
    minor product=MasMinor[0];
    for (int i=1; i<N; i++)
        product=product*MasMinor[i];
    cout<<"The product of minors:\n";
    product.MatrPrint();

//Multiplying each of the minor by a constant
    int c;
    cout<<"\nEnter the constant c = ";    cin>>c;
    byConst(MasMinor, N, DimOfMinor, c);

    delete []MasMinor;
    return 0;
}


void byConst(minor MasMinor[], int N, int DimOfMinor, int c)
{
    for (int i=0; i<N; i++)
    {
        minor Minor=MasMinor[i];
        minor r=Minor.multiplByConst(Minor, c);
        cout<<"minor"<<i+1<<" * "<<c<<endl;
        r.MatrPrint();
    }
}
