#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 5009
struct point
{
	int x, y;
	point(){}
	point(int a, int b){
		x = a, y = b;
	}
}P, Q, U[N], L[N], T;
int ans[N];
int find(point M, int i)
{
	point v1 = point(U[i].x-M.x, U[i].y-M.y);
	point v2 = point(L[i].x-M.x, L[i].y-M.y);
	return v1.x*v2.y-v2.x*v1.y > 0 ? -1:1;
}
int get(point M, int a, int b)
{
	//printf("a, b %d %d\n", a, b);
	if(find(M, a) > 0) return a-1;
	if(find(M, b) < 0) return b;
	int t = find(M, (a+b)/2);
	if(t > 0) return get(M, a, (a+b)/2);
	if(t < 0) return get(M, (a+b)/2+1, b);
}
int main()
{
	int n, m;
	while(scanf("%d", &n), n)
	{
		memset(ans, 0, sizeof(ans));
		scanf("%d%d%d%d%d", &m, &P.x, &P.y, &Q.x, &Q.y);
		for(int i = 1;i <= n;i++)
		{
			scanf("%d%d", &U[i].x, &L[i].x);
			U[i].y = P.y, L[i].y = Q.y;
		}
		//printf("------\n");
		for(int i = 0;i < m;i++)
		{
			scanf("%d%d", &T.x, &T.y);
			//printf("put %d %d\n", T.x, T.y);
			ans[get(T, 1, n)]++;
			//int p = get(T, 1, n);
			//printf("get %d\n", p);
			//ans[p]++;
		}
		for(int i = 0;i <= n;i++)
			printf("%d: %d\n", i, ans[i]);
		printf("\n");
	}
	return 0;
}