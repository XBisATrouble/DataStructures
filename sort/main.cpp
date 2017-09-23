#include <iostream>
#include <time.h>
const int MAXNUM=88888;

void print_r(int a[],int len){
    for (int i = 0; i < len; ++i) {
        std::cout<<a[i]<<",";
    }
    std::cout<<"\n";
}

//插入排序
void InsertionSort(int a[],int len){
    for (int i = 1; i < len; ++i) {
        int key = a[i];
        int j = i-1;
        while (j>=0 && a[j]>key){
            a[j+1]=a[j];//让数字向后滚动
            j--;
        }
        a[j+1]=key;
    }
}

//归并排序
//整合两个数组
void MergeArray(int array[],int p,int q,int r){
    int n1=q-p+1;
    int n2=r-q;
    int *left,*right;
    left = (int *)malloc((n1+1) * sizeof(int));
    right = (int *)malloc ((n2+1) * sizeof(int));
    for (int i=1;i<=n1;i++)
        left[i] = array[p+i-1];
    for (int j=1;j<=n2;j++)
        right[j] = array[q+j];
    left[n1+1]=MAXNUM;
    right[n2+1]=MAXNUM;
    int i=1,j=1;
    for (int k = p; k <= r; ++k) {
        if (left[i]<=right[j]){
            array[k]=left[i];
            i++;
        }else{
            array[k]=right[j];
            j++;
        }
    }
}

void MergeSort(int array[],int p,int r){
    if (p<r){
        int q=(p+r)/2;
        MergeSort(array,p,q);
        MergeSort(array,q+1,r);
        MergeArray(array,p,q,r);
    }
}

int main() {
    int a[8]={2,4,1,3,7,6,5,8};

    clock_t start,finish;
    double totaltime;
    start=clock();
    //InsertionSort(a,8);
    //MergeSort(a,0,8);

    finish=clock();
    totaltime=(double)(finish-start);
    std::cout<<"\n此程序的运行时间为"<<totaltime<<"毫秒！"<<std::endl;

    print_r(a,8);
}