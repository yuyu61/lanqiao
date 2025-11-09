//快排  归并  二分（整数）  二分（浮点）

//快排模版
#include<iostream>
using namespace std;

const int N=1e6+10;

int n;
int q[N];

void quick_sort(int q[],int l,int r){
    if(l>=r) return;
    int x=q[l],i=l-1,j=r+1;
    while(i<j){
        do i++; while(q[i]<x);
        do j--; while(q[j]>x);
        if(i<j) swap(q[i],q[j]);
    }
    quick_sort(q,l,j);
    quick_sort(q,j+1,r);
    //边界问题 这样写不能搭配x=q[r]
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&q[i]);

    quick_sort(q,0,n-1);

    for(int i=0;i<n;i++) printf("%d",q[i]);

    return 0;
}

//归并模版
#include<iostream>
using namespace std;

const int N=100010;

int n;
int q[N],tmp[N];

void merge_sort(int q[],int l,int r){
    if(l>=r) return;
    int mid=(l+r)/2;
    merge_sort(q,l,mid),merge_sort(q,mid+1,r);

    int k=0,i=l,j=mid+1;
    while(i<=mid && j<=r)
        if(q[i]<=q[j]) tmp[k++]=q[i++];
        else tmp[k++]=q[j++];
    while(i<=mid) tmp[k++]=q[i++];
    while(j<=mid) tmp[k++]=q[j++];

    for(i=l,j=0;i<=r;i++,j++) q[i]=tmp[j];
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&q[i]);

    merge_sort(q,0,n-1);

    for(int i=0;i<n;i++) printf("%d",q[i]);
    return 0;
}


//整数二分
bool check(int x) {/* ... */} // 检查x是否满足某种性质

// 区间[l, r]被划分成[l, mid]和[mid + 1, r]时使用：
int bsearch_1(int l, int r)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;    // check()判断mid是否满足性质
        else l = mid + 1;
    }
    return l;
}
// 区间[l, r]被划分成[l, mid - 1]和[mid, r]时使用：
int bsearch_2(int l, int r)
{
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}

//浮点二分——开根号为例
#include<iostream>
using namespace std;

int main(){
    double n;
    cin>>n;

    double l=0,r=n;
    while(r-l>=10*1e-8){
        double mid=(l+r)/2;
        if(mid*mid<n) l=mid;
        else r=mid;
    }
    printf("%lf\n",l);

    return 0;
}