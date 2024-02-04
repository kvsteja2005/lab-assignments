#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef long double ld;
using namespace std;

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

// void inplace_merge2(int* start, int* end,int m){
//     int i=0,j=m,k=-1,n=(end - start);
//     while( )
//     {
//         if( *(start+i)<=*(start+j) ) i++;
//         else
//         {
//             int a = *(start+i); 
//             *(start+i) = *(start+j);
//             *(start+j) = a; k++; j++; k=k%(j-m);
//         }
//     }
// }

int main()
{

    // genarating random array of size 100000
    freopen("test_cases_Q2.txt","w",stdout);
    int n = 100000 , b[n]; 
    int m = rand()%n; // random middle position

    rep(i,0,n){b[i] = rand();} 
    sort(b,b+m); sort(b+m,b+n); // modifying  according to question

    cout<<n<<" "<<m<<"\n"; 
    rep(i,0,n){cout<<b[i]<<" ";} cout<<"\n"; 
    fclose (stdout);



    freopen("test_cases_Q2.txt","r",stdin);
    freopen("output_Q2.txt","w",stdout);

    // int a[10] = {10,11,12,14,15,1,2,3,4,5};
    // inplace_merge1(a,5,a+10);
    // cout<<"for small input after merging\n";
    // rep(i,0,10){cout<<a[i]<<" ";}cout<<"\n";

    cout<<"for large random input \n";

    cin>>n>>m;
    rep(i,0,n){cin>>b[i];} 

    cout<<"before merging is_sorted value of array : "<<is_sorted(b,b+n)<<"\n"; // before merging
    inplace_merge1(b,m,b+n);
    rep(i,0,n){cout<<b[i]<<" ";}cout<<"\n";
    cout<<"after merging is_sorted value of array : "<<is_sorted(b,b+n)<<"\n"; // after merging
}