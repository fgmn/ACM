#include <bits/stdc++.h>
using namespace std;

//字典树（字符串集合） 
struct trie{
	//child[now][x]表示节点now的第x个儿子 
	//flag[now]=1表示节点now是某个字符串的结尾
	 
	static const int N=1010,charset=30;
	int tot, root, child[N][charset],flag[N];
	
	trie(){
		memset(child,-1,sizeof child);
		memset(flag,0,sizeof flag);		//1、补充对flag[]的初始化 
		root = tot = 0;
	}
	
	void clear(){
		memset(child,-1,sizeof child);
		memset(flag,0,sizeof flag);
		root = tot = 0;
	} 
	
	void insert(string str){
		int now=root;
		for(int i=0;i<(int)str.length();i++){
			int x=str[i]-'a';
			if(child[now][x] == -1){
				child[now][x]= ++tot;
//				flag[now]=0;
			}
			now=child[now][x];
		}
		flag[now]=1;
	} 
	
	//查询字典树是否存在某个完整的字符串是str的前缀
	bool query(string str){
		int now=root;
		for(int i=0;i<(int)str.length();i++){
			int x=str[i]-'a';
			if(child[now][x] == -1) return false;
			now = child[now][x];	//2、若下一节点匹配了，则考虑其是否为终点 
			if(flag[now]) return true;		
		}
		return false;
	} 
	
}; 

int main() {
	trie t;
	t.insert("happy");
	t.insert("happiness");
	t.insert("happyyyyyyy");
	 
	cout<<(t.query("happyaaaa"))<<endl;
	
	cout<<((int)t.query("happ"))<<endl;
	
	for(int i=0;i<20;i++) cout<<i<<':'<<t.flag[i]<<endl;
	 
	return 0;
}
