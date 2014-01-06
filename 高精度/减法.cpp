#include <iostream>    
#include <string>    

using namespace std;    
string a,b;   
   
string  substr(string a,string b )     //a-b                       
{   
	int  i,j,k,c,s,flag=1;   
	string s1,s2;  
	if(a.size()<b.size()||a.size()==b.size()&&a.compare(b)<0)  
	{  
		s1=a;  
		a=b;  
		b=s1;  
		flag=0;  
	}  
	while (a.length()>b.length())  b='0'+b;               
	//字符短的加前导零，使他们一样长     
	for (i=a.length()-1; i>=0; i--)        //减，规整   
	{   
		if(a[i]>=b[i])  
			a[i]=a[i]-b[i];  
		else   
		{  
			a[i]=a[i]-b[i];     
			while(a[i]<0){
				a[i] += 10;
				a[i-1] -=1;
			}      
		}   
	}  
	for(i=0;i<a.length();i++)//去掉开头的0
		if(a[i]!='0' && a[i]!=0)
			break;  
	for(j=i,k=0;j<a.length();j++,k++)    //转化字符   
		a[k]=a[j]+'0';  
	if(flag)  
	{  
		s2=a;  
	}  
	else   
	{  
		s2="-";  
		s2+=a;  
	}   
	return s2;  
}    
int main()    
{  int cas;  
	cin>>cas;  
	while(cas--)  
	{  
		cin>>a;    
		cin>>b ;  
         
		cout<<substr(a,b)<<endl;    
       
	}  
	return 0;  
}  