// 5d array
#include<stdio.h>
#include<stdlib.h>
int main(){
    int *****arr ;
    int p,q,r,s,t,i,j,k,l,m ;
    printf("enter number of dimentions you want : \n") ;
    scanf("%d%d%d%d%d",&p,&q,&r,&s,&t) ;

    arr = (int*****)malloc(p*sizeof(int****)) ;
    for ( i=0 ; i<p ; i++)
    {
        arr[i] = (int****)malloc(q*sizeof(int***));
        for (j=0 ; j<q ; j++)
        {
            arr[i][j] = (int***)malloc(r*sizeof(int**));
            for(k=0 ; k<r ; k++)
            {
                arr[i][j][k] = (int**)malloc(s*sizeof(int*)) ;
                for( l=0 ; l<s ; l++)
                {
                    arr[i][j][k][l] = (int*)malloc(t*sizeof(int)) ;
                }
            }
        }
    }

    printf("give inputs \n") ;
    for ( i=0 ; i<p ; i++)
    {
        for (j=0 ; j<q ; j++)
        {
            for(k=0 ; k<r ; k++)
            {
                for( l=0 ; l<s ; l++)
                {
                   for (m=0 ; m<t ; m++)
                   {
                    scanf("%d",&arr[i][j][k][l][m]) ;
                   } 
                }
            } 
        }
    }

    printf("THE OUTPUT IS \n") ;
    for ( i=0 ; i<p ; i++)
    {
        for (j=0 ; j<q ; j++)
        {
            for(k=0 ; k<r ; k++)
            {
                for( l=0 ; l<s ; l++)
                {
                   for (m=0 ; m<t ; m++)
                   {
                    printf("arr[%d][%d][%d][%d][%d] is %d \n",i,j,k,l,m,arr[i][j][k][l][m]) ;
                   } 
                }
            } 
        }
    }

return 0;
}
