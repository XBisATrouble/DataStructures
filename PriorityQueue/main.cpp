#include <iostream>

class p_queue
{
public:
    p_queue(int *A, int n);
    void insert(int x);
    int maximum(void);
    int extract_max(void);


private:
    int a[10000];
    int size;

    int parent(int i);
    int left(int i);
    int right(int i);
    void maxHeapify(int A[], int n, int i);
    void buildMaxHeap(int A[], int n);
};

p_queue::p_queue(int *A, int n)
{
    for(int i = 0;i < n;i++)
    {
        a[i] = A[i];
    }
    size = n;
    buildMaxHeap(a, size);
}

void p_queue::insert(int x)
{
    size++;
    a[size-1] = x;
    int i = size-1;
    while(i > 0 && a[parent(i) < a[i]])
    {
        std::swap(a[i], a[parent(i)]);
        i = parent(i);
    }
}

int p_queue::maximum()
{
    if(size <= 0)
    {
        std::cerr << "heap overflow" << std::endl;
        return -1;
    }
    return a[0];
}

int p_queue::extract_max()
{
    if(size <= 0)
    {
        std::cerr << "heap overflow" << std::endl;
        return -1;
    }
    int max = a[0];
    a[0] = a[size-1];
    size--;
    maxHeapify(a, size, 0);
    return max;
}

int p_queue::parent(int i)
{
    return (i-1)/2;
}

int p_queue::left(int i)
{
    return 2*i+1;
}

int p_queue::right(int i)
{
    return 2*i+2;
}

//核心函数，选取三个节点中最大的数移到根节点，然后递归被交换节点
void p_queue::maxHeapify(int A[], int n, int i)
{
    int l = left(i);
    int r = right(i);
    int largest(0);
    if (l <= (n-1) && A[l] > A[i])
        largest = l;
    else
        largest = i;
    if (r <= (n-1) && A[r] > A[largest])
        largest = r;
    if(largest != i)
    {
        std::swap(A[i], A[largest]);
        maxHeapify(A, n, largest);
    }
}

void p_queue::buildMaxHeap(int A[], int n)
{
    for(int i = n/2-1;i >= 0;i--)
        maxHeapify(A, n, i);
}

int main()
{
    int A[10] = {10,9,8,7,6,5,4,3,2,1};
    p_queue q1(A, 10);

    std::cout << q1.maximum() << std::endl;
    q1.insert(20);
    std::cout << q1.maximum() << std::endl;
    q1.extract_max();
    std::cout << q1.maximum() << std::endl;
    return 0;
}
