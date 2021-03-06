//
//  main.cpp
//  f-HDU-1102-Constructing Roads
//
//  Created by ZYJ on 2016/10/28.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

#define mem(a, b) memset(a, b, sizeof(a))

using namespace std;

/*
 * Prim求MST
 * 耗费矩阵cost[][]，初始化为INF，标号从0开始，0 ~ n－1
 * 返回最小生成树的权值，返回-1表示原图不连通
 */

const int INF = 0x3f3f3f3f;
const int MAXN = 110;
bool vis[MAXN];
int lowc[MAXN];
int cost[MAXN][MAXN];

//  修正cost（添加边）
void updata(int x, int y, int v)
{
    cost[x - 1][y - 1] = v;
    cost[y - 1][x - 1] = v;
    return ;
}

int Prim(int cost[][MAXN], int n)   //  0 ~ n - 1
{
    int ans = 0;
    memset(vis, false, sizeof(vis));
    vis[0] = true;
    for (int i = 1; i < n; i++)
    {
        lowc[i] = cost[0][i];
    }
    for (int i = 1; i < n; i++)
    {
        int minc = INF;
        int p = -1;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && minc > lowc[j])
            {
                minc = lowc[j];
                p = j;
            }
        }
        if (minc == INF)
        {
            return -1;  //  原图不连通
        }
        ans += minc;
        vis[p] = true;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && lowc[j] > cost[p][j])
            {
                lowc[j] = cost[p][j];
            }
        }
    }
    return ans;
}

int main(int argc, const char * argv[])
{
    int N, Q;
    int a, b;
    
    while (cin >> N)
    {
        mem(cost, 0x3f);
        mem(vis, 0);
        
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                scanf("%d", cost[i] + j);
            }
        }
        
        cin >> Q;
        for (int i = 0; i < Q; i++)
        {
            scanf("%d%d", &a, &b);
            cost[a - 1][b - 1] = 0;
            cost[b - 1][a - 1] = 0;
        }
        
        int ans = Prim(cost, N);
        cout << ans << '\n';
    }
    
    return 0;
}
