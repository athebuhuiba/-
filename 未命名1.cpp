#include <windows.h>
#include <iostream> 
#include<time.h>
using namespace std;
struct player{
	int num; 
	bool camp;//��Ӫ������Ϊ�죻0Ϊ��
	bool state;//���0�� ��0��
	bool pos;//0�峤 
	bool eye;//0����
	int vote;//ͶƱ��� 
	double voted;//��ͶƱ�� 
	
};

int main(){
	int renshu,b,c,d,e,f,g,h,i,j,n,t,l,s,s1,x,y,gg;
	bool hh=0;
	gg=0;
	cout<<"��������Ϸ����"<<endl;
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
		pyr[i].camp=0;//�ֵ��ڷ�
		for(i=0;i<=rs;i++)//
		{
			if(pyr[i].camp==0)//
			c++;
		 } 
		
	};//������� 
	cout<<"������������Բ�ѡ�ٴ峤"<<endl;
	for(i=0;i<rs;i++)
	{
		 cout<<"�����ֵ�"<<i<<"����ҷ���"<<endl;
		 system("pause") ;
	};
	cout<<"��ʼͶƱ"<<endl;
	
	e=-1;
	
	 while(e==-1){
	 	for(i=0;i<rs;i++)
	{
		 cout<<"�����ֵ�"<<i<<"�����ͶƱ"<<endl;
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
     pyr[e].pos=0;//�峤ѡ�� 
     cout<<"���"<<e<<"�ŵ�ѡ�˴峤"<<endl;
     
     for(i=0; i<rs; ++i) 
	{
		pyr[i].voted=0;
	};//ѡƱ���� 
	
	while(gg==0){//ÿ��ѭ�� 
     
     srand((unsigned)time(NULL));
     d=rand()%2;
     if(d==0)cout<<"�����ˣ������Ǻ�ҹ"<<endl;
     else cout<<"�����ˣ������Ǻ�ҹ"<<endl;
     
     
     cout<<"��������������Ƿ�����(����0Ϊ���ۣ�������Ϊ����)"<<endl;
     for(i=0;i<rs;i++)
     {
     	if(pyr[i].state==0)continue;
     	cout<<"��"<<i<<"����Ҿ����Ƿ�����"<<endl;
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
	
     
     cout<<"��峤ѡ���Է���(0��)"<<endl;//�������� 
     cin>>f; ;
     if(f==0){ 
     	for(i=e;i>=0;i--)
	{

	if(pyr[i].state==1)
		 {
			 cout<<"�����ֵ�"<<i<<"����ҷ���"<<endl;
		     system("pause") ;
		 }
		 else continue ; 
	}
	for(i=rs-1;i>e;i--)
	{
		if(pyr[i].state==1){
			cout<<"�����ֵ�"<<i<<"����ҷ���"<<endl;
		 system("pause") ;
	
		}
		else continue ; 
		}
	
	 } //������ 
	 else{
     	for(i=e;i<rs;i++)
	{
		if(pyr[i].state!=0)
		 {
		 	cout<<"�����ֵ�"<<i<<"����ҷ���"<<endl;
		 system("pause") ;
		 }
	};
	for(i=0;i<e;i++)
	{
		if(pyr[i].state!=0){
			cout<<"�����ֵ�"<<i<<"����ҷ���"<<endl;
		 system("pause") ;
	
		}
		 }
	
	 } ;//������ 
	 
	 l=0;
	 s=-1;
	 while(s==-1)
	 {
	 	
	 	for(i=0; i<rs; ++i) 
	{
		pyr[i].voted=0;
	};//ѡƱ���� 
	
	 	
	 	for(i=0;i<rs;i++)
	 {
	 	if(pyr[i].state!=0)l++;
	 }
	
	for(i=0;i<rs;i++)
	{
		if(pyr[i].state!=0)
		{ 
		 cout<<"�����ֵ�"<<i<<"�����ͶƱ"<<endl;
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
	 	cout<<"��������һ�δ峤�����"<<endl;
	 cin>>e;
	 }
 	pyr[s].pos=1;
 	pyr[e].pos=0;
 };
cout<<"���"<<s<<"�ű�ͶƱ������"<<endl; 
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
	cout<<"�ڷ�ʤ��"<<endl;
	else if (y==0)
	cout<<"�췽ʤ��"<<endl;
	else cout<<"��Ϸ����"<<endl;
	
	for(i=0; i<rs; ++i) 
	{
		pyr[i].voted=0;
	}
	
	
	if(x==0||y==0)gg=1;
	else gg=0;
}

cout<<"��Ϸ����"<<endl; 
return 0; 
	
}

