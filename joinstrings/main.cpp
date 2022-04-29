#include <bits/stdc++.h>

using namespace std;

unordered_map<int,string> words;
unordered_map<int,vector<int>> mp ;

void show(int index)
{
    cout << words[index];
    vector<int> outputs = mp[index];
    for ( int i = 0; i < outputs.size(); i ++ )
    {
        int index = outputs[i];
        show(index);
    }
}

int main()
{
    int n,a,b;
    cin >> n ;
    string x;
    for ( int i = 1; i <= n ; i++ )
    {
        cin >> x;
        words[i] = x;
        vector<int> v;
        mp[i] = v;
    }
    if( n == 1 )
    {
        cout << words[1] << endl;
        return 0;
    }
    for ( int i = 1; i <= n - 1 ; i ++)
    {
        cin >> a >> b;
        mp[a].push_back(b);
    }
    show(a);
    cout << endl;
}