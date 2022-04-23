#include<iostream>
#include<vector>
#include<cmath>
#include<time.h>
#include<cstring>
#include<algorithm>
 
using namespace std;
const int maxn = 10000;//定义点的数量
const int mod = 10000;//定义点值的范围

struct Point{//点集
	double x;
	double y;
};
struct PointPair{//记录最近对的可能值
    Point a, b;
    double d;
};

bool Compx(const Point &p1, const Point &p2)
{
	return p1.x < p2.x;
}
bool Compy(const Point &p1, const Point &p2)
{
	return p1.y < p2.y;
}
double Distance(const Point &a, const Point &b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
//归并左右两个点集
void Merge(vector<Point> &v, int left, int mid, int right)
{
	vector<Point> vl(v.begin()+left,v.begin()+mid);
	int i = left;
	int j = 0;
	int k = mid;
	while(i < right){
		if(j < vl.size() && (k == right || vl[j].y <= v[k].y))
			v[i++] = vl[j++];
		if(k < right && (j == vl.size() || vl[j].y > v[k].y))
			v[i++] = v[k++];
	}
}

PointPair Closest(vector<Point> &vx, int left, int right)
{
    PointPair ans;
    //当点集内只有2-3个点时特殊考虑，直接用暴力解答
    if(right - left == 2){
		if(vx[left].y > vx[right-1].y){
			swap(vx[left],vx[right-1]);
		}
        ans.a= vx[left];
        ans.b= vx[right-1];
        ans.d=Distance(vx[left],vx[right-1]);
        return ans;
    }
	if(right - left == 3){
		sort(vx.begin()+left,vx.begin()+right,Compy); 
		double d1 = Distance(vx[left],vx[left+1]);
		double d2 = Distance(vx[left],vx[right-1]);
		double d3 = Distance(vx[left+1],vx[right-1]);
        //记录最近对
        if(min({d1,d2,d3})==d1){
            ans.a = vx[left];
            ans.b = vx[left+1];
        }
        else if(min({d1,d2,d3})==d2){
            ans.a = vx[left];
            ans.b = vx[right-1]; 
        }
        else if(min({d1,d2,d3})==d3){
            ans.a = vx[left+1];
            ans.b = vx[right-1];
        }
        //返回最近距离
		ans.d=min({d1,d2,d3});
        return ans;
    }
    //若点集超过3个，要用递归进行分治
	int mid = (left + right) / 2; 
	double mx = vx[mid].x;
	PointPair pl = Closest(vx,left,mid);
	PointPair pr = Closest(vx,mid,right);
	if(pl.d<pr.d)
        ans = pl;
    else
        ans = pr;
    double d = min(pl.d, pr.d);
    //查找两个区间的中间部分是否存在最小值
    Merge(vx,left,mid,right);
	vector<Point> vp;
	for(int i = left; i < right; ++i){
		if(abs(vx[i].x - mx) < d)
			vp.push_back(vx[i]);
	}
	for(int i = 0; i < vp.size(); ++i){
		for(int j = i + 1; j < i+1+6 && vp.size(); ++j){//可以只遍历相邻六个点
			if(vp[j].y - vp[i].y >= d)
				break;
			else{
				double dm = Distance(vp[i],vp[j]);
				if(dm < d){
                    d = dm;
                    ans.a = vp[i];
                    ans.b = vp[j];
                }	
			}
		}
	}
    ans.d = d;
    return ans;
}

int main()
{
	int n;
	while(cin >> n) {
		vector<Point> v;
	    Point points[maxn];
	   
	    for (int i = 0; i < n;i++){
	    	cin >> points[i].x >> points[i].y;
			v.push_back(points[i]);
	    }

	    sort(v.begin(),v.end(), Compx);

	    PointPair ans = Closest(v, 0, v.size());

	    cout << int(ans.d) << endl;
	}
	

    return 0;
}
