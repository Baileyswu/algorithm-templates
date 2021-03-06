/*--------------------------------------------
 * File Name: POJ 2653
 * Author: Danliwoo
 * Mail: Danliwoo@outlook.com
 * Created Time: 2015-10-23 20:44:04
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define eps 1e-8
#define N 100010
	int n;
struct point
{
	double x, y;
	void sc(){
		scanf("%lf%lf", &x, &y);
	}
	point operator - (const point &b) const{
		point c;
		c.x = x-b.x, c.y = y-b.y;
		return c;
	}
	point(){}
	point(double x, double y):x(x), y(y){}
	void pr(){
		printf("%.2lf %.2lf\n", x, y);
	}
}p[2*N];
double cross(point P, point Q){
	double t = P.x*Q.y - P.y*Q.x;
	if(fabs(t) < eps) return 0;
	return t > 0 ? 1: -1;
}
int stk[N], top;
bool h(point A, point B, point C, point D)
{
	double sa = cross(A-C, D-C);
	double sb = cross(B-C, D-C);
	//printf("%.3f %.3f\n", sa, sb);
	return sa*sb <= 0;
}
bool check(point &A, point &B, point &C, point &D)
{
	//for(int i = 0;i < n;i++)printf("%d%c", 1-stk[i], " \n"[i==n-1]);
	//	printf("\n");
	//A.pr(), B.pr(), C.pr(), D.pr();
	return /*(max(A.x, B.x) >= min(C.x, D.x))&&
		(max(A.y, B.y) >= min(C.y, D.y))&&
		(max(C.x, D.x) >= min(A.x, B.x))&&
		(max(C.y, D.y) >= min(A.y, B.y))&&*/
		h(A, B, C, D) && h(C, D, A, B);
}
int main()
{
	while(scanf("%d", &n), n)
	{
		int top = 0;
		for(int i = 0;i < n;i++)
		{
			p[2*i].sc();
			p[2*i+1].sc();
		}
		memset(stk, 0, sizeof(stk));
		for(int i = 0;i < n;i++)
			for(int j = i+1;j < n;j++)
				if(check(p[2*i], p[2*i+1], p[2*j], p[2*j+1]))
					stk[i] = 1;
		printf("Top sticks: ");
		for(int i = 0;i < n;i++) if(!stk[i])
			stk[top++] = i;
		for(int i = 0;i < top;i++)
			printf("%d%c%c", stk[i]+1, ",."[i==top-1], " \n"[i == top-1]);
	}
	return 0;
}