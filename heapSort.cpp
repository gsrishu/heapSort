#include <bits/stdc++.h>
using namespace std;
void heppify(int arr[], int n, int i){
    
    int l = 2*i + 1;
    int r = 2*i + 2;
    int longest = i;
    if(l < n && arr[l] > arr[i])
      longest = l;
    if(r < n && arr[r] > arr[longest])
     longest = r;
     
    if(longest != i){
        swap(arr[i],arr[longest]);
        heppify(arr,n,longest);
    }
}
void maxheap(int arr[], int n){
    int s = ceil(n/2) - 1;
    for(int i = s; i >= 0; i--)
      heppify(arr,n,i);
     for(int i = n-1; i >= 0; i--){
         swap(arr[0],arr[i]);
         heppify(arr,i,0);
     }
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i = 0; i < n; i++)
	     cin>>arr[i];
	 
	    maxheap(arr,n);
	      for(int i = 0; i < n; i++)
	   cout<<arr[i]<<" ";
	}
	return 0;
}
