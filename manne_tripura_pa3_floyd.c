//Author : Sai Tripura Manne
//DAA Assignment 3
//ALL PAIRS SHORTESET PATH-FLOYDS ALGORITHM

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//function to randomly select the number of vertices 
int printRandoms(int lower,int upper)
{
    int n;
    n = (rand()%(upper-lower+1))+lower;
    //printf("Displayed n value is : %d\n",n);
    return n;

}
//function to create an adjacency matrix randomly
void adjacencyMatrix(int n,int A[n][n])
{
    int i,j;    // (i,j) - edge of the graph 
    for(i=0;i<n;i++)
    {
       
        for(j=0;j<n;j++)

        {
            
            if(i>=j)

            {
               
                if(i==j)        //when i=j the edge should be 0
                {
                    A[i][j] = 0;
                    
                }
                else        //when i!=j an integer is assigned randomly between 1 and 10
                {           //and also A[j][i] = A[i][j]
                    A[i][j] = printRandoms(1,10);
                   
                    A[j][i] = A[i][j];
                                        
                }
                
            }
        }
    }
}
//function to compute the shortest path between all pairs of vertices n
void floyds(int n, int A[n][n],  int P[n][n])
{
    int i,j,k;
    for(i=0;i<n;i++)    //initialize P array to [0]
    {
        for(j=0;j<n;j++)
        {
            P[i][j] = 0;
        }
    }
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(A[i][j] > A[i][k]+A[k][j])
                {
                    A[i][j] = A[i][k] + A[k][j];
                    P[i][j] = k;            
                }
                else
                {
                    A[i][j] = A[i][j];
                }
            }
        }
    }
}
//function to print final Adjacency matrix and Point matrix
void printMatrix(int n, int A[n][n],int P[n][n])
{
    printf("Amatrix : \n\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d \t",A[i][j]);
        }
        printf("\n");
    }
    printf("Pmatrix : \n\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d \t",P[i][j]);
        }
        printf("\n");
    }
}
//function to compute shortest path between two vertices in the graph
void printShortestPath(int q, int r, int n, int P[n][n])
{
    
    if(P[q][r] != 0)
    {
        printShortestPath(q,P[q][r],n,P);
        printf("V%d ",P[q][r]+1);
        printShortestPath(P[q][r],r,n,P);
    }
}
//Driver code
int main()
{
    int lower = 5,upper = 10;
    int n;
    
    srand(time(0)); //Using current time as seed for random generator
    n = printRandoms(lower, upper);
    printf("randomly selected n is : %d\n",n);
    int A[n][n];
    int P[n][n];
    adjacencyMatrix(n,A);

    
    
    floyds(n,A,P);
    printMatrix(n,A,P);
    //print the shortest paths between all the vertices of the graph
    for(int i=0;i<n;i++)
    {
        printf("V%d - Vj:shortest path and length\n",i+1);
        for(int j=0;j<n;j++)
        {
            
            printf("V%d ",i+1);
            printShortestPath(i,j,n,P);
            printf("V%d:%d",j+1,A[i][j]);
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}
