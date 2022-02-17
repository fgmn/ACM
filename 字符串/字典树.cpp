#include <bits/stdc++.h>
using namespace std;

//�ֵ������ַ������ϣ� 
struct trie{
	//child[now][x]��ʾ�ڵ�now�ĵ�x������ 
	//flag[now]=1��ʾ�ڵ�now��ĳ���ַ����Ľ�β
	 
	static const int N=1010,charset=30;
	int tot, root, child[N][charset],flag[N];
	
	trie(){
		memset(child,-1,sizeof child);
		memset(flag,0,sizeof flag);		//1�������flag[]�ĳ�ʼ�� 
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
	
	//��ѯ�ֵ����Ƿ����ĳ���������ַ�����str��ǰ׺
	bool query(string str){
		int now=root;
		for(int i=0;i<(int)str.length();i++){
			int x=str[i]-'a';
			if(child[now][x] == -1) return false;
			now = child[now][x];	//2������һ�ڵ�ƥ���ˣ��������Ƿ�Ϊ�յ� 
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
