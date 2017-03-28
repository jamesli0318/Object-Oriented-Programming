/*
Name:Zhen Xun Li
Student ID:403410035
Dept:Computer Science and Information engineering
Year:2
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;

void initailMatrix(int (&input)[10][10]);
void multiMatrix(int (&input1)[10][10] , int (&input2)[10][10]);
void filter(int (&intput)[10][10] , int (&output)[10][10]);
int cmp(const void*a , const void *b);
void pMarix(int matrix[10][10]);

int main()
{
    /*creat new matrice*/
    int matrixA[10][10];
    int matrixB[10][10];
    srand(time(NULL));
    /*initialize them by random number between 0 and 225*/
    initailMatrix(matrixA);
    initailMatrix(matrixB);
    /*show matrice*/
    cout<<"matrix A=\n";
    pMarix(matrixA);
    cout<<"matrix B=\n";
    pMarix(matrixB);
    /*Multiply*/
    multiMatrix(matrixA , matrixB);
    cout<<"Multiply array A by array B\n"
        <<" The result A=\n";
    pMarix(matrixA);
    /*filter*/
    filter(matrixA,matrixB);
    cout<<"After Median filter\n"
        <<"The result B=\n";
    pMarix(matrixB);


    return 0;
}

void initailMatrix(int (&input)[10][10])
{
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            input[i][j]=rand()%256;
        }
    }
}

void multiMatrix(int (&A)[10][10] , int (&B)[10][10])
{
    int temp[10][10]= {0};
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            for(int k=0; k<10; k++) {
                temp[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            A[i][j]=temp[i][j];
        }
    }
}

void filter(int (&input)[10][10] , int (&output)[10][10])
{
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            int Q[10];
            for(int k=0; k<10; k++) {
                Q[k]=INT_MAX;
            }
            int index=0;
            Q[index]=input[i][j];
            index++;
            if((i>=0 && i<=9) && (j+1>=0 && j+1<=9)) {
                Q[index]=input[i][j+1];
                index++;
            }
            if((i-1>=0 && i-1<=9) && (j+1>=0 && j+1<=9)) {
                Q[index]=input[i-1][j+1];
                index++;
            }
            if((i-1>=0 && i-1<=9) && (j>=0 && j<=9)) {
                Q[index]=input[i-1][j];
                index++;
            }
            if((i-1>=0 && i-1<=9) && (j-1>=0 && j-1<=9)) {
                Q[index]=input[i-1][j-1];
                index++;
            }
            if((i>=0 && i<=9) && (j-1>=0 && j-1<=9)) {
                Q[index]=input[i][j-1];
                index++;
            }
            if((i+1>=0 && i+1<=9) && (j-1>=0 && j-1<=9)) {
                Q[index]=input[i+1][j-1];
                index++;
            }
            if((i+1>=0 && i+1<=9) && (j>=0 && j<=9)) {
                Q[index]=input[i+1][j];
                index++;
            }
            if((i+1>=0 && i+1<=9) && (j+1>=0 && j+1<=9)) {
                Q[index]=input[i+1][j+1];
                index++;
            }
            /*Find mid number*/
            qsort(Q,10,sizeof(int),cmp);
            if(index%2==0) {
                int mid=index/2;
                output[i][j]=(Q[mid]+Q[mid-1])/2;
            } else {
                int mid=index/2;
                output[i][j]=Q[mid];
            }
        }
    }
}

int cmp(const void*a , const void *b)
{
    int c=*(int *)a;
    int d=*(int *)b;
    return c-d;
}

void pMarix(int matrix[10][10])
{
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            cout<<matrix[i][j]<<"\t";
        }
        cout<<"\n";
    }
}