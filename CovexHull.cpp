#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct point{
   int x,y;
};

point p0;
int n;

stack<point> s;
point arr[100005];

bool cmp(point a,point b){
	if(a.y<b.y)return true;
	else if(a.y==b.y){
		 if(a.x<=b.x)return true;
		 return false;
	}
	else return false;
}

bool cmp2(point a,point b){
	double x1=a.x;
	double y1=a.y;
	double x2=b.x;
	double y2=b.y;
	double x=p0.x;
	double y=p0.y;
	return -(x-x1)/(y-y1)> -(x-x2)/(y-y2);
}

bool fun(point p,point q,point r){
	int val = (q.y - p.y) * (r.x - q.x) -(q.x - p.x) * (r.y - q.y);
    if (val == 0) return false;
    else if(val<0)return false;
    else return true; 
}

int main(){
	cin >> n;
	int a,b;
	for(int i=0;i<n;i++){
		cin >> a >> b;
		arr[i].x=a;
		arr[i].y=b;
	}
	sort(arr,arr+n,cmp);
	p0=arr[0];
	sort(arr+1,arr+n,cmp2);
	point pp;point qq,rr;
	s.push(p0);s.push(arr[1]);s.push(arr[2]);
	for(int i=3;i<n;i++){
		qq=s.top();
		s.pop();
		pp=s.top();
		s.push(qq);
		if(fun(pp,qq,arr[i])){
			s.push(arr[i]);
		}
		else{
				while(!s.empty()){
					s.pop();
					if(!s.empty())
					qq=s.top();
					if(!s.empty())
					 s.pop();
					if(!s.empty())
					pp=s.top();
					s.push(qq);
					if(fun(pp,qq,arr[i])){
						s.push(arr[i]);
						break;
					}

				}
		}
	}
	while(!s.empty()){
		pp=s.top();
		s.pop();
		cout << pp.x <<"  "<<pp.y<<endl;
	}
	return 0;
}
