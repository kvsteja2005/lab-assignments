#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef long double ld;
using namespace std;

//a+n*b
void inplace_merge1(int* start, int m, int* end){
    int mx = max(*(start+(m-1)),*(end-1)) + 1;
    int n = end - start,i = 0,j = m,k = 0;
    while(i < m && j < n && k < n){
        int a = *(start+i) % mx;
        int b = *(start+j) % mx;
        if(a<=b){
            *(start+k) += (a*mx);
            i++; k++;
        }
        else{
            *(start+k) += (b*mx);
            j++; k++;
        }
    }

    while(i < m){
        int a = *(start+i) % mx;
        *(start+k) += (a*mx);
        i++; k++;
    }
    while(j < n){
        int b = *(start+j) % mx;
        *(start+k) += (b*mx);
        j++; k++;
    }

    rep(l,0,n) *(start+l) /= mx;
}

void inplace_mergesort(int* start, int* end){
    if((end - start) < 2) return;
    int m =  (end - start) / 2;
    inplace_mergesort(start,start+m);
    inplace_mergesort(start+m,end);
    inplace_merge1(start,m,end);
}

int main()
{
    // genarating random array of size 100000
    freopen("test_cases_Q3.txt","w",stdout);
    cout<<100000<<"\n"; 
    rep(i,0,100000){cout<<rand()<<" ";} cout<<"\n"; 
    fclose (stdout);


    freopen("test_cases_Q3.txt","r",stdin);
    freopen("output_Q3.txt","w",stdout);
    
    int n; cin>>n; int b[n]; 
    rep(i,0,n){cin>>b[i];} 
    cout<<"for large random input \n";

    cout<<"before sorting is_sorted value of array : "<<is_sorted(b,b+n)<<"\n"; // before sorting
    inplace_mergesort(b,b+n);
    cout<<"after sorting is_sorted value of array : "<<is_sorted(b,b+n)<<"\n"; // after sorting
}