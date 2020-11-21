#include <bits/stdc++.h>
using namespace std;
/*
    Author: Ranjeet Walia
*/
vector <vector <int> > result;
void Search(vector <int> &v, vector <int> &subset, int i, int n)
{
    if(i==n){
        result.push_back(subset);
        return;
    }
    else{
        subset.push_back(v[i]);
        Search(v, subset, i+1, n);
        subset.pop_back();
        Search(v, subset, i+1, n);
        return;
    }
}
int main()
{
    cout << "Enter the size of vector : ";
    int n;
    cin >> n;
    vector <int> vec(n);
    for(int i=0; i<n; i++)
        cin >> vec[i];

    vector <int> subset;
    Search(vec, subset, 0, n);

    for(auto x: result){
        cout <<"{ ";
        for(auto y: x)
            cout << y << " ";
        cout <<"}\n";
    }
    return 0;
}

