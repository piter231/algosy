#include "jas.h"
using namespace std;

int main()
{
    int n = init();
    
    bool B[n];
    for(int i=0; i<n; i++)
    	B[i]=true;
    	
    int P[n];
    for(int i=0; i<n; i++)
    	P[i]=i;
    
    int d=wyprobuj(B);
    
    odpowiedz(B, P);    
}
