#include <iostream>

int partition(int A[],int p,int r)
{
    int x = A[r];
    int i = p-1;
    for (int j = p; j < r; ++j) {
        if (A[j]<=x){
            i++;
            std::swap(A[j],A[i]);
        }
    }
    std::swap(A[i+1],A[r]);
    return i+1;
}

void QuickSort(int A[],int p,int r)
{
    if (p<r)
    {
        int q=partition(A,p,r);
        QuickSort(A,p,q-1);
        QuickSort(A,q+1,r);
    }
}



int main() {
    int test[5]={5,4,3,2,1};
    QuickSort(test,0,4);
    for (int i = 0; i < 5; ++i) {
        std::cout<<test[i];
    }
    return 0;
}