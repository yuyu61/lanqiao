//快排  归并  二分（整数）  二分（浮点）

//快排模版
// #include<iostream>
// using namespace std;

// int main(){
//     int n=1e6*10;
    
//     return 0;
// }

//归并


//整数二分

////////////////////////////////s
//浮点二分
#include<iostream>
using namespace std;

int main(){
    double n;
    cin>>n;

    double l=0,r=n;
    while(r-l>=10*1e-6){
        double mid=(l+r)/2;
        if(mid*mid<n) l=mid;
        else r=mid;
    }
    printf("%lf\n",l);

    return 0;
}