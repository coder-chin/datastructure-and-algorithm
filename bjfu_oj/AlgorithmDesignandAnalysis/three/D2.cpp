#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
#define max 100000

struct point{
 float x;
 float y;
};

point points[max];
int n;

bool cmpxy(point& a, point& b)
{
    if(a.x != b.x)
        return a.x < b.x;
    return a.y < b.y;
}

bool cmp_y(int &a , int &b){
 return points[a].y < points[b].y;
}


float countDis(point &a , point &b){
 float num = sqrt(pow(a.x - b.x , 2) + pow(a.y - b.y , 2));
 return num;
}

float divide(int begin , int end){
 if(end <= begin){
  return -1;
 }
 if(end - begin == 2){
  return countDis(points[begin] , points[end-1]);
 }
 float d1 , d2 , d3;
 if(end - begin == 3){
  d1 = countDis(points[begin] , points[begin+1]);
  d2 = countDis(points[begin] , points[begin+2]);
  d3 = countDis(points[begin+1] , points[begin+2]);
  float less = min(d1 , min(d2 , d3));
  return less;
 }
 int mid = (begin + end)/2; 
 float disless;
 float dis1 , dis2;
 dis1 = divide(begin , mid);
 dis2 = divide(mid , end);
 disless = min(dis1 , dis2); 
 int midPoints[max];
 int i , j = 0 , k;
 for(i = begin;i < end;i++){
  if(abs(points[i].x - points[mid].x) < disless){
   midPoints[j] = i;
   j++;
  }
 }
 sort(midPoints , midPoints+j , cmp_y);
 for(i = 0;i < j;i++){
  for(k = i+1 ; k < j && points[midPoints[k]].y - points[midPoints[i]].y < disless ;k++){
   if(disless > countDis(points[midPoints[k]] , points[midPoints[i]])){
    disless = countDis(points[midPoints[k]] , points[midPoints[i]]);
   }
  }
 }
 return disless;
}

int main(){
 while(scanf("%d" , &n) != EOF){
  int i;
  memset(points , 0 , sizeof(points));
  for(i = 0;i < n;i++){
   float x = 0 , y = 0;
   scanf("%f%f" , &x , &y);
   points[i].x = x;
   points[i].y = y;
  }
  sort(points , points+n , cmpxy);
  float end = divide(0 , n);
  int a = end;
  printf("%d\n" , a);
 }
 return 0;
}