#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//Assuming point in 2D plane
struct point{
   int x,y;
};

point p0;
int n;


stack<point> s;
point arr[100005];

//Sorts array based on the Y co0ordinate smallest to largest.In case of equal y-co-ordinates sort based on x -coordinate
bool cmp(point a,point b){
	if(a.y<b.y)return true;
	else if(a.y==b.y){
		 if(a.x<=b.x)return true;
		 return false;
	}
	else return false;
}

//Sort based on the polar angle with reference to p0
bool cmp2(point a,point b){
	double x1=a.x;
	double y1=a.y;
	double x2=b.x;
	double y2=b.y;
	double x=p0.x;
	double y=p0.y;
	return -(x-x1)/(y-y1)> -(x-x2)/(y-y2);
}

// returns true if points p,q,r form a counter clockwise angle else returns false
// orientation is checked based on cross product of vectors
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
	sort(arr,arr+n,cmp); // sort based on y-ordinate.Could have also done it O(n) by doing a linear scan
	p0=arr[0];           // selecting the initial point
	sort(arr+1,arr+n,cmp2); // sort based on polar angle
	point pp;point qq,rr;
	s.push(p0);s.push(arr[1]);s.push(arr[2]);
	for(int i=3;i<n;i++){
		qq=s.top();
		s.pop();
		pp=s.top();
		s.push(qq);
		if(fun(pp,qq,arr[i])){ // if counter clockwise
			s.push(arr[i]);
		}
		else{
				while(!s.empty()){ //keep popping till current point forms a counter clockwise direction with top 
					s.pop();   // of stack and next to top of stack
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
	//The convex hull points remain in the stack
	// Output hull
	while(!s.empty()){
		pp=s.top();
		s.pop();
		cout << pp.x <<"  "<<pp.y<<endl;
	}
	return 0;
}
