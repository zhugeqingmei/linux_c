#include <stdio.h>
#include <assert.h>

#define LEN 5
#define NEW_LEN 8
#define MAX_ROW 5
#define MAX_COL 5

static int a[NEW_LEN] = {5, 2, 4, 7, 1, 3, 2, 6};
static int ordered_a[NEW_LEN] = {1, 3, 3, 3, 4, 5, 6, 7};
static int random_a[NEW_LEN] = {1, 30, 13, 23, -4, 105, 6, 7};
static char stack[512];
static int top = 0;
static int maze[5][5] = {
                    0, 1, 0, 0, 0,
                    0, 1, 0, 1, 0,
                    0, 0, 0, 0, 0,
                    0, 1, 1, 1, 0,
                    0, 0, 0, 1, 0,};

static int add_range(int low,int high)
{
    int i,sum;
    sum=0;
    for (i=low;i<=high;i++)
        sum+=i;
    return sum;
}

static int test_add_range(void)
{
    int result[100];
    result[0]=add_range(1,10);
    result[1]=add_range(1,100);
    printf("result[0]=%d\nresult[1]=%d\n",result[0],result[1]);
    return 0;
}

static int ex10_2(void)
{
    int sum = 0, i = 0;
    char input[5];

    while(1)
    {
        sum = 0;
        scanf("%s",input);/*get a '\0' in the end*/
        for(i = 0; input[i] != '\0'; i++)
            sum = sum*10 + input[i] - '0';
        printf("input=%d\n", sum);
    }
    return 0;
}

static void excise_1()
{
    int i;
    char str[6] = "hello";
    char reverse_str[6] = "";

    printf("%s\n", str);
    for (i = 0; i < 5; i++)
        reverse_str[5-i] = str[i];
    printf("%s\n", reverse_str);
    return;
}

static void insertion_sort()
{
    int i, j, key;

    int a[LEN] = {10, 5, 2, 4, 7};

    for (j = 1;j < LEN; ++j)
    {
        printf("%d, %d, %d, %d, %d\n",a[0], a[1], a[2], a[3], a[4]);
        key = a[j];
        i = j - 1;
        while (i >= 0 && a[i] > key)
        {
            a[i+1] = a[i];
            --i;
        }
        a[i+1] = key;
    }
    printf("%d, %d, %d, %d, %d\n",a[0], a[1], a[2], a[3], a[4]);

}

static void merge(int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int left[n1], right[n2];
    int i, j, k;

    for(i = 0; i < n1; i++)
    {
        left[i] = a[start+i];
    }
    for(j = 0; j < n2; ++j)
    {
        right[j] = a[mid+1+j];
    }

    i = j = 0;
    for(k = start; i < n1 && j < n2; ++k)
    {
        if(left[i] < right[j])
        {
            a[k] = left[i];
            ++i;
        }else
        {
            a[k] = right[j];
            ++j;
        }
    }

    if(i<n1)
    {
        for(; i < n1; i++)
        {
            a[k] = left[i];
            ++k;
        }
    }
    if(j<n2)
    {
        for(; j < n2; ++j)
        {
            a[k] = right[j];
            ++k;
        }
    }
}

static void sort(int start, int end)
{
    int mid;
    if(start < end)
    {
        mid = (start + end) / 2;
        printf("sort (%d-%d, %d-%d) %d %d %d %d %d %d %d %d\n",start, mid, mid+1,end,
                a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);
        sort(start, mid);
        sort(mid + 1, end);
        merge(start, mid, end);
        printf("merge (%d-%d, %d-%d) to %d %d %d %d %d %d %d %d\n",start, mid, mid+1,end,
                a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);
    }
}

static void exch(int a[],int low, int high)
{
    int temp = a[low];
    a[low] = a[high];
    a[high] = temp;
}

static int partition(int start, int end)
{
    int i, j, v;

    i = start;
    j = end + 1;
    v = a[start];

    while(1)
    {
        i++;
        while(a[i]<v)
        {
            if(i == end)
                break;
            i++;
        }
        j--;
        while(v < a[j])
        {
            if(j == start)
                break;
            j--;
        }
        if(i >= j)
            break;
        exch(a, i, j);
    }
    exch(a, start, j);
    return j;
}

static void quicksort(int start, int end)
{
    printf(" (%d-%d) to %d %d %d %d %d %d %d %d\n",start, end,
                a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);
    int mid;
    if(end > start)
    {
        mid = partition(start, end);
        quicksort(start, mid-1);
        quicksort(mid+1, end);
    }
}

/*
array size is n, want the k-th smallest number
*/
static int k_th_order_statistics(int a[], int n, int k)
{
    int l, r;

    l = 1;
    r = n;

    while(1)
    {
        if(r <= l + 1)
        {
            if(r == l + 1 && a[r] < a[l])
                exch(a, l, r);
            return a[k];

        }

        int mid = (l + r) >> 1;
        exch(a, mid, l + 1);
        if(a[l] > a [r])
            exch(a, l, r);
        if(a[l + 1] > a[r])
            exch(a, l + 1, r);
        if(a[l] > a[l + 1])
            exch(a, l, l + 1);

        int i = l + 1;
        int j = r;
        int cur = a[l + 1];
        while(1)
        {
            while(a[++i] < cur);
            while(a[--j] > cur);
            if(i > j)
                break;
            exch(a, i, j);
        }

        a[l + 1] = a[j];
        a[j] = cur;

        if(j >= k)
            r = j - 1;
        if(j <= k)
            l = i;
    }
}

/*
search item in ordered array,return the index,or -1.
if the item appear has one more index, return anyone is ok.
*/
static int binary_search(int number)
{
    int start, end, mid;

    start = 0;
    end = NEW_LEN - 1;

    while(start <= end)
    {
        mid = (start + end) / 2;

        if(ordered_a[mid] == number)
        {
            return mid;
        }else if(ordered_a[mid] < number)
        {
            start = mid + 1;
        }else
        {
            end = mid - 1;
        }
    }
    return -1;
}

static void push(char c)
{
    stack[top] = c;
    top++;
}

char pop(void)
{
    top--;
    return stack[top];
}

int is_empty(void)
{
    return top == 0;
}

void test_stack()
{
    push('a');
    push('b');
    push('c');

    while(!is_empty())
    {
        assert('c' == pop());
        assert('b' == pop());
        assert('a' == pop());
    }
}

int test_ex_10_1(void)
{
    printf("I am in ex_10_1.c\n");
    //test_add_range();
    //ex10_2();
    //excise_1();
    //insertion_sort();
    //sort(0,NEW_LEN-1);
    //quicksort(0,NEW_LEN-1);
    // printf("binary search:%d\n",binary_search(4));
    // printf("binary search:%d\n",binary_search(8));
    // printf("binary search:%d\n",binary_search(7));
    // printf("binary search:%d\n",binary_search(6));
    // printf("binary search:%d\n",binary_search(5));
    // printf("binary search:%d\n",binary_search(0));
    // printf("binary search:%d\n",binary_search(3));

    // printf("k_th_order_statistics:%d\n", k_th_order_statistics(random_a, NEW_LEN - 1, 1));
    // printf("k_th_order_statistics:%d\n", k_th_order_statistics(random_a, NEW_LEN - 1, 2));
    // printf("k_th_order_statistics:%d\n", k_th_order_statistics(random_a, NEW_LEN - 1, 3));
    // printf("k_th_order_statistics:%d\n", k_th_order_statistics(random_a, NEW_LEN - 1, 4));
    // printf("k_th_order_statistics:%d\n", k_th_order_statistics(random_a, NEW_LEN - 1, 5));
    // printf("k_th_order_statistics:%d\n", k_th_order_statistics(random_a, NEW_LEN - 1, NEW_LEN - 1));

    test_stack();
    return 0;
}
