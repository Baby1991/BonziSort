#include <iostream>
#include <stdlib.h>

using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void Heap (int k, int niz[], int sorted[], int n)
{
    if (k==1)
    {
    	try{
	        for(int i = 1; i < n; ++i)
			    {
			        if(niz[i-1]>niz[i])
			        	throw 0;
			    }
			copy(niz,niz+n,sorted);
		}
		catch(int e){
		}
    }
    
    else
    {
        Heap(k-1, niz, sorted, n);
        
        for(int i = 0; i<k-1; i++)
        {
            if(!(k%2)) swap(&niz[i], &niz[k-1]);
            
            else {
			swap(&niz[0], &niz[k-1]);
			}
            
            Heap(k-1, niz, sorted, n);
        }       
    }
}

void BonziSort(int arr[], int n){
	int sorted[n];
	Heap(n,arr,sorted,n);
	copy(sorted,sorted+n,arr);
}

int main(int argc, char *argv[]) {
	int n;
	cin>>n;
	
	int arr[n];

    for(int i = 0; i < n; ++i)
    {
        cin>>arr[i];
    }
    BonziSort(arr,n);
    for(auto j: arr) cout << j << " ";
    

    return 0;
}
