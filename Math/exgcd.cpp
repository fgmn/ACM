#include <bits/stdc++.h>
using namespace std;


//�ݹ飬����һ���

int exgcd(int a,int b,int &x,int &y){
	int r;
	if(!b){
		x=1;
		y=0;
		return a;
	}
	else{
		r=exgcd(b,a%b,x,y);
		int t=x;
		x=y;
		y=t-(a/b)*y;
		
	}
	return r;
	//rʵ����gcd? 
} 



int main(){
	int x,y;
	exgcd(17,18,x,y);
	cout<<x<<' '<<y;
	//�������һ���ֵ
	 
	return 0;
}
