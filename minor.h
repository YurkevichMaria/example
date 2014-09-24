#ifndef MINOR_H
#define MINOR_H


class minor
{
    private:
        int n, m;
        int **M;
    public:
        minor();                           //constructor
        minor(int, int);                   //constructor with parameter
        minor (const minor &original);     //copy constructor
        minor & operator = (const minor &rhs);    //operator =
        void MatrInit();                   //create a matrix
        void MatrPrint();                  //output matrix
        int** FunNumbers(int);             //Enter numbers of rows and columns for minor
        minor CreateMinor(int, int**);     //Create Minor
        minor operator+(minor &ob);
        minor operator-(minor &ob);
        minor operator*(minor &ob);
        minor multiplByConst(minor, int);  //matrix multiplication by a constant
        ~minor();                          //destructor

};

#endif // MINOR_H
