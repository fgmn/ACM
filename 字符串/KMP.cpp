#include <bits/stdc++.h>
using namespace std;
const int maxn=1e7+10;

int nextt[maxn];//ambiguous:next 

void get_next(const string ptr, int len){

	nextt[0]=0;
	
	for(int i=1, j=0;i<len;i++){
		while(j && ptr[j]!=ptr[i]) j=nextt[j-1];
		if(ptr[i]==ptr[j]) j++;
		nextt[i]=j;
	}
}

bool kmp(const string str, const string ptr){

	int len1 = str.length();
	int len2 = ptr.length();
	
	int j=0;//ptr[]������ 
	
//	get_next(ptr, len2);
	
	for(int i=0;i<len1;++i){
		
		//����ptr[j]��ʧ�䣬�����ó���Ϊnextt[j-1]��ǰ׺�����ǰ�ĺ�׺
		//����ptr[nextt[j-1]]����ַ���׼�ո�ʧ���λ��
		 
		while(j && ptr[j]!=str[i]) j=nextt[j-1];
		
		if(ptr[j]==str[i]) j++;
		
		if(j==len2){
			//matched here
//			j=nextt[j-1];
			return true; 
		}
	}
	return false;
} 

int main() {
	int n;
	cin>>n;
	
	string t,m,s;
	cin>>t;
	get_next(t,t.length());
	
	bool flag=false;
	
	for(int k=2;k<=16;k++){
		s="";
		for(int i=1;i<=n;i++){
			int cur=i;
			m="";
			//����ת�� 
			while(cur){
				int temp=cur%k;
				cur/=k;
				if(temp<=9) m+=temp+'0';
				else m+=temp-10+'A';
			}
			
			reverse(m.begin(), m.end());
			s+=m;
			
		}
				 
//		if(kmp(s,t)){
		if(s.find(t)!=-1){//�ƺ�����kmp 
			cout<<"yes"<<endl;
			flag=true;
			break;
		}	
	} 
	
	if(!flag) cout<<"no"<<endl;
	
	return 0;
}
