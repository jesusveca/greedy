#include <iostream>
#include <vector>

using namespace std;

vector<int> iterativo_greedy_activity_selector(int s[], int f[], int n){
    
    vector<int> comodin;
    
    comodin.push_back(s[0]);
    int k=0;
    for(int m=1; m<n; ++m){
        
        if(s[m]>=f[k]){
            comodin.push_back(s[m]);
            k=m;
        }
    }
    return comodin;
}


vector<int> Recursive_Activity_Selector(vector<int> *vectorin, int ss[], int ff[], int k, int n){
    
    int m = k+1;
    while(m<=n && k>-1 && ss[m]<ff[k]){
        ++m;
    }
    if (m<n){
        vectorin->push_back(ss[m]);
        cout<<"actividad  "<<m+1<<"  :: "<<ss[m]<<endl;
        Recursive_Activity_Selector(vectorin, ss, ff, m, n);
        return *vectorin;
    }
    return *vectorin;
}

int main(){
    
    int n=11;

    int ss[11] = {1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
    int ff[11] = {3, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};
    
    vector<int> comodin;
    vector<int> vectorin;
    
    comodin=iterativo_greedy_activity_selector(ss,ff,n);
    Recursive_Activity_Selector(&vectorin,ss,ff,-1,n);
    
    for(int i=0; i<comodin.size(); ++i)
        cout<<comodin[i]<<" ";
    cout<<endl;
    
    for(int i=0; i<vectorin.size(); ++i)
        cout<<vectorin[i]<<" ";
    cout<<endl;
    
    return 0;
}