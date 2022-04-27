#include<bits/stdc++.h>

using namespace std;

#define MAX 1005
int r,c,n,PK;
char m[MAX][MAX];
map<pair<int, int>, bool>  visited;
map<pair<int, int>, int> indexes;

bool isValid(int x,int y)
{
    return  0 <= x && x < r && 
            0 <= y && y < c ;
}

void getPathsOfOnes(int a,int b)
{
    pair<int,int> p = make_pair(a,b);
    visited[p] = true;
    indexes[p] = PK;
    if ( isValid(a,b+1) && !visited[{a,b+1}] && m[a][b+1] == '1' )
        getPathsOfOnes(a,b+1);
    if ( isValid(a,b-1) && !visited[{a,b-1}] && m[a][b-1] == '1' )
        getPathsOfOnes(a,b-1);
    if ( isValid(a+1,b) && !visited[{a+1,b}] && m[a+1][b] == '1' )
        getPathsOfOnes(a+1,b);
    if ( isValid(a-1,b) && !visited[{a-1,b}] && m[a-1][b] == '1' )
        getPathsOfOnes(a-1,b);
}
void getPathsOfZeros(int a,int b)
{
    pair<int,int> p = make_pair(a,b);
    visited[p] = true;
    indexes[p] = PK;
    if ( isValid(a,b+1) && !visited[{a,b+1}] && m[a][b+1] == '0' )
        getPathsOfZeros(a,b+1);
    if ( isValid(a,b-1) && !visited[{a,b-1}] && m[a][b-1] == '0' )
        getPathsOfZeros(a,b-1);
    if ( isValid(a+1,b) && !visited[{a+1,b}] && m[a+1][b] == '0' )
        getPathsOfZeros(a+1,b);
    if ( isValid(a-1,b) && !visited[{a-1,b}] && m[a-1][b] == '0' )
        getPathsOfZeros(a-1,b);
}

bool solve(int a,int b,int c,int d,char index)
{
    pair<int,int> start = make_pair(a,b);
    pair<int,int> end = make_pair(c,d);
    return  m[a][b] == m[c][d] && indexes[start] == indexes[end];  
}

int main()
{
    cin >> r >> c;
    for ( int i = 0 ; i < r ; i++ )
    {
        for ( int j = 0 ; j < c ; j++ )
        {
            cin >> m[i][j];
        }
    }
    for ( int i = 0 ; i < r ; i++ )
    {
        for ( int j = 0 ; j < c ; j++ )
        {
            if ( visited[make_pair(i,j)] == false )
            {
                if ( m[i][j] == '1' )
                {
                    getPathsOfOnes(i,j);
                    PK ++;
                }
                else
                {
                    getPathsOfZeros(i,j);
                    PK ++;
                }
            }
            
        }
    }
    cin >> n;
    while ( n -- )
    {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 --;y1 --;x2 --;y2 --;
        char index = m[x1][y1];
        if ( solve(x1,y1,x2,y2,index) )
        {
            if ( index == '1')
                cout << "decimal" << endl ;
            else 
                cout << "binary" << endl ;
        }
        else 
        {
            cout << "neither" << endl;
        }
    }
}