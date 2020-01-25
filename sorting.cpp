#include <stdio.h>
#include <assert.h>

/*common function */
void swap(int& a, int& b);
void traverse(int* array , size_t len);

/* sorting impl*/
//swap
void bubbleSort(int* array, size_t len);
void bubbleSortOptimize(int* array, size_t len);
void quitSort(int* a, int low, int high); //meet and kiss


/* testing function*/
void testSort();



int main(void) 
{
    testBubbleSort();
    return 0;
}

void swap(int& a, int& b) {
    int tmpValue;
    tmpValue= a;
    a = b;
    b = tmpValue;
}
void traverse(int* a  , size_t n) {
    if(a == NULL) {
        return;
    }
    for(int i=0; i< n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
//upper sort  0 1 2
void bubbleSort(int* a , size_t n) {
    if( a== NULL || n == 1) {
        return ;
    }
    int i , j;
  
    for(i=0; i<n-1; i++) {
        for(j=i+1; j<n; j++) {
            if(a[i] > a[j]) {
                 swap(a[i], a[j]);
            }
        }
    }
}

void bubbleSortOptimize(int* a, size_t n) {
    if(a == NULL || n == 1) {
        return;
    }
  
    size_t end = n;
    int exchange = 0;
    while( end > 0 )//end作为每趟排序的终止条件
    {
        for( size_t i = 0; i < end-1 ; ++i )
        {
            if( a[i] > a[i+1] )
            {
                swap(a[i],a[i+1]);
                exchange = 1;
            }
        }
        if( 0 == exchange )//数组本身为升序，如果一趟排序结束，并没有进行交换，那么直接跳出循环（减少循环次数，升高效率）
            break;
        --end;
    }

}

void quickSort(int* a, int low, int high) {
    int i = low;
    int j = high;
    if(i > j ) {
        return;
    }
    int tmpValue = a[i];

    while (i != j)
    {
        //find value lower than tmpValue
        while (a[j] >=tmpValue && i < j) 
            j--;
        
        while(a[i] <= tmpValue && i< j)
            i++;
        if(i<j) 
            swap(a[i], a[j]);
    }
    //meet and kiss then do thing
    swap(a[low], a[i]);
    quitSort(a, low, i-1);
    quitSort(a, i+1, high);
    
}

void testSort() {
    //升序排序
    int a[] = {9,8,7,6,5,4,3,2,1};
    /*  int a[] = {2,5,4,0,9,3,6,8,7,1};*/
    int len = sizeof(a)/sizeof(a[0]);
    printf("before sort :\n");
    traverse(a,len);
    //1.***************bubble sort test case
    //bubbleSort(a,len);
    // bubbleSortOptimize(a, len);

    //2.***************quick sort test case
    quickSort(a, 0, len-1);

    printf("after sort :\n");
    traverse(a,len);
}