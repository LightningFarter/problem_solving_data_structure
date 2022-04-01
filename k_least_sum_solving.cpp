#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int Mp[100][1000];

struct Node
{
    int sum, point;
    Node(int sum, int point):sum(sum), point(point){}
    friend bool operator < (Node a,Node b)
    {
        return a.sum>b.sum;
    }
};

void Merge(int *a, int *b, int *c, int n)
{
    sort(a, a+n);
    sort(b, b+n);
    priority_queue<Node> DL;
    for(int i = 0; i < n; i++)
    {
        DL.push(Node(a[i] + b[0], 0));
    }
    for(int i = 0; i < n; i++)
    {
        Node d = DL.top();
        DL.pop();
        c[i]=d.sum;
        DL.push(Node(d.sum - b[d.point] + b[d.point + 1], d.point + 1));
    }
}

int main()
{
    int O, K;
    cin >> O >> K;
    for(int i = 0; i < O; i++) for(int j = 0; j < K; j++) cin >> Mp[i][j];
    for(int i = 1; i < O; i++) Merge(Mp[0], Mp[i], Mp[0], K);
    for (int i = 0; i < K; i++)
    {
        if(i > 0)
            cout << " ";
        cout << Mp[0][i];
    }
    return 0;
}
