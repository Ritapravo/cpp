#include<stdio.h>
#include <conio.h>

//using namespace std;

int main()
{

    //cout<<"hello";
    //cout << endl; 
    int n = 5;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%d ",j);
            
        }
        printf("\n");
        
    }
    
    

    //getch();

    return 0;

}