#include <windows.h>
#include <iostream> 
#include<time.h>
using namespace std;
struct player{
	int num; 
	bool camp;//阵营：非零为红；0为黑
	bool state;//玩家0死 非0生
	bool pos;//0村长 
	bool eye;//0睁眼
	int vote;//投票序号 
	double voted;//被投票数 
	
};

int main(){
	int renshu,b,c,d,e,f,g,h,i,j,n,t,l,s,s1,x,y,gg;
	bool hh=0;
	gg=0;
	cout<<"请输入游戏人数"<<endl;
	cin>>renshu;
	int &rs=renshu;
	player pyr[rs];
	for(i=0; i<rs; ++i) 
	{
		pyr[i].num=i;
		pyr[i].camp=1;
		pyr[i].eye=1;
		pyr[i].pos=1;
		pyr[i].state=1;
		pyr[i].voted=0;
	}
	b=rs/2;
	c=0;
	while(c<=b){//
		srand((unsigned)time(NULL));
		c=0;
		i=rand()%rs;
		pyr[i].camp=0;//分到黑方
		for(i=0;i<=rs;i++)//
		{
			if(pyr[i].camp==0)//
			c++;
		 } 
		
	};//分组完成 
	cout<<"请玩家轮流发言并选举村长"<<endl;
	for(i=0;i<rs;i++)
	{
		 cout<<"现在轮到"<<i<<"号玩家发言"<<endl;
		 system("pause") ;
	};
	cout<<"开始投票"<<endl;
	
	e=-1;
	
	 while(e==-1){
	 	for(i=0;i<rs;i++)
	{
		 cout<<"现在轮到"<<i<<"号玩家投票"<<endl;
		 cin>>pyr[i].vote ;
		 c=pyr[i].vote;
		 pyr[c].voted++;
	}
	e=0;
	for(i=0;i<rs;i++)
	{
	if(pyr[i].voted>pyr[e].voted)
	e=i;
	else e=e;
		
	}

	for(i=0;i<rs;i++)
	{
		if(i!=e&&pyr[i].voted==pyr[e].voted)
		e=-1;
	}
 }
     pyr[e].pos=0;//村长选出 
     cout<<"玩家"<<e<<"号当选了村长"<<endl;
     
     for(i=0; i<rs; ++i) 
	{
		pyr[i].voted=0;
	};//选票归零 
	
	while(gg==0){//每天循环 
     
     srand((unsigned)time(NULL));
     d=rand()%2;
     if(d==0)cout<<"日落了，今天是黑夜"<<endl;
     else cout<<"日落了，今天是红夜"<<endl;
     
     
     cout<<"请玩家自主决定是否睁眼(输入0为睁眼，其余数为闭眼)"<<endl;
     for(i=0;i<rs;i++)
     {
     	if(pyr[i].state==0)continue;
     	cout<<"请"<<i<<"号玩家决定是否睁眼"<<endl;
     	cin>>pyr[i].eye; 	
	 };
	 g=0;
	if(d==0)
	for(i=0;i<rs;i++)
	{
		if((pyr[i].state!=0)&&(pyr[i].eye==0)&&(pyr[i].camp==0))g++;
	}
	else for(i=0;i<rs;i++)
	{
		if((pyr[i].state!=0)&&(pyr[i].eye==0)&&(pyr[i].camp!=0))g++;//g have to be restored
	};
	
     
     cout<<"请村长选择发言方向(0左)"<<endl;//按方向发言 
     cin>>f; ;
     if(f==0){ 
     	for(i=e;i>=0;i--)
	{

	if(pyr[i].state==1)
		 {
			 cout<<"现在轮到"<<i<<"号玩家发言"<<endl;
		     system("pause") ;
		 }
		 else continue ; 
	}
	for(i=rs-1;i>e;i--)
	{
		if(pyr[i].state==1){
			cout<<"现在轮到"<<i<<"号玩家发言"<<endl;
		 system("pause") ;
	
		}
		else continue ; 
		}
	
	 } //左向发言 
	 else{
     	for(i=e;i<rs;i++)
	{
		if(pyr[i].state!=0)
		 {
		 	cout<<"现在轮到"<<i<<"号玩家发言"<<endl;
		 system("pause") ;
		 }
	};
	for(i=0;i<e;i++)
	{
		if(pyr[i].state!=0){
			cout<<"现在轮到"<<i<<"号玩家发言"<<endl;
		 system("pause") ;
	
		}
		 }
	
	 } ;//右向发言 
	 
	 l=0;
	 s=-1;
	 while(s==-1)
	 {
	 	
	 	for(i=0; i<rs; ++i) 
	{
		pyr[i].voted=0;
	};//选票归零 
	
	 	
	 	for(i=0;i<rs;i++)
	 {
	 	if(pyr[i].state!=0)l++;
	 }
	
	for(i=0;i<rs;i++)
	{
		if(pyr[i].state!=0)
		{ 
		 cout<<"现在轮到"<<i<<"号玩家投票"<<endl;
		 cin>>pyr[i].vote ;
		 c=pyr[i].vote;
		 if(g%2==0)
		 {
		 	pyr[c].voted++;
		 }
		 else if(pyr[i].pos==0)
		 {
		 	if(l%2==0)pyr[c].voted=pyr[c].voted+1.5;
		 	else pyr[c].voted=pyr[c].voted+0.5;
		 }
		 else pyr[c].voted++;
		 
		
		 
		 } 
	}
	s1=0;
	for(i=0;i<rs;i++)
	{
	if(pyr[i].voted>pyr[s1].voted)
	s1=i;
	else s1=s1;
		
	}
	s=s1;
	cout<<pyr[s1].state;
	for(i=0;i<rs;i++)
	{
		if(i!=s&&pyr[i].voted==pyr[s].voted)
		s=-1;
		else continue;
	}

	if(pyr[s1].state!=1)
	s=-1; 
	else s=s1;
 }
 pyr[s].state=0;
 if(pyr[s].pos==0)
 {
 	while(pyr[e].state==0)
	 {
	 	cout<<"请输入下一任村长的序号"<<endl;
	 cin>>e;
	 }
 	pyr[s].pos=1;
 	pyr[e].pos=0;
 };
cout<<"玩家"<<s<<"号被投票驱逐了"<<endl; 
s=-1;
    x=0;
    y=0;
	for(i=0;i<rs;i++)
	{
		if((pyr[i].state!=0)&&(pyr[i].camp==0))x++;
	};
	for(i=0;i<rs;i++)
	{
		if((pyr[i].state!=0)&&(pyr[i].camp!=0))y++;
	};
	if(x==0)
	cout<<"黑方胜利"<<endl;
	else if (y==0)
	cout<<"红方胜利"<<endl;
	else cout<<"游戏继续"<<endl;
	
	for(i=0; i<rs; ++i) 
	{
		pyr[i].voted=0;
	}
	
	
	if(x==0||y==0)gg=1;
	else gg=0;
}

cout<<"游戏结束"<<endl; 
return 0; 
	
}

