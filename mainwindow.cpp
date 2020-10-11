#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "player.h"
#include <QMainWindow>
#include <QPushButton>
#include <QTime>
#include <QDebug>
#include <QDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
{
    ui->setupUi(this);//初始化
}

butten =new QPushButton("开始游戏",this);
butten->setGeometry(370,470,300,70);

qsrand(uint(QTime(0,0,0).secsTo(QTime::currentTime())));//随机种子设置

connect(butten,SIGNAL(clicked()),this,SLOT(slotstarts()));

}

void MainWindow::slotstarts()
{
    butten->setText("重新开始");
int rs;bool ok=false;
rs=QInputDialog::getInt(this,"开始游戏","请输入玩家人数",4,4,15,1,&ok);
 if(!ok)return;
int b,c,d,e,f,g,i,l,s,s1,x,y,gg;
gg=0;
player pyr[rs];
for(i=0;i<15;i++)
{
      st[i/5][i%5]=0;
      k[i/5][i%5]=0;
      m[i/5][i%5]=0;
}
bgpic=0;
for(i=0; i<rs; ++i)
    {
        pyr[i].num=i+1;
        pyr[i].camp=1;
        pyr[i].eye=1;
        pyr[i].pos=1;
        pyr[i].state=1;
        st[i/5][i%5]=1;
        pyr[i].voted=0;

    }


   b=rs/2;
    c=0;
    while(c<=b){//
        qsrand(uint(QTime(0,0,0).secsTo(QTime::currentTime())));
        c=0;
        i=rand()%rs;
        pyr[i].camp=0;//分到黑方
        for(i=0;i<=rs;i++)
        {
            if(pyr[i].camp==0)
            c++;
         }
    }

    for(i=0; i<rs; ++i)
    {
        if(pyr[i].camp==0)
            QMessageBox::information(this,"开始游戏","您的号码为"+QString::number(i+1)+"，身份是黑方");
        else QMessageBox::information(this,"开始游戏","您的号码为"+QString::number(i+1)+"，身份是红方");
    }
    QMessageBox::information(this,"游戏开始","玩家轮流发言并选举村长");
    for(i=0; i<rs; ++i)
    {
m[i/5][i%5]=1;
 QMessageBox::information(this,"游戏进行","现在是"+QString::number(i+1)+"号玩家发言");
m[i/5][i%5]=0;
    }
    QMessageBox::information(this,"游戏进行","现在请选举村长");
    e=-1;

     while(e==-1){
        for(i=0;i<rs;i++)
    {
         QMessageBox::information(this,"游戏进行","现在是"+QString::number(i+1)+"号玩家投票");
        ok=false;
         pyr[i].vote=QInputDialog::getInt(this,"选举村长","投票给",1,1,rs,1,&ok);
          if(!ok)return;
         c=pyr[i].vote;
         c--;
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
         }}
     k[e/5][e%5]=1;
      pyr[e].pos=0;//村长选出

      for(i=0; i<rs; ++i)
          {
              pyr[i].voted=0;
          };//选票归零
      QMessageBox::information(this,"投票结果",QString::number(e+1)+"号玩家当选了村长");


while(gg==0){//每天循环
      qsrand(uint(QTime(0,0,0).secsTo(QTime::currentTime())));
           d=rand()%2;
           if(d==0){QMessageBox::information(this,"日落了","今晚是黑夜");bgpic=1;}
           else {QMessageBox::information(this,"日落了","今晚是红夜");bgpic=2;}

           QMessageBox::information(this,"游戏进行","请玩家自主决定是否睁眼(输入0为睁眼，其余数为闭眼)");

           for(i=0;i<rs;i++)
                {
                   if(pyr[i].state==0)continue;
                   QMessageBox::information(this,"游戏进行","请决定是否睁眼");
                  ok=false;
                 pyr[i].eye=QInputDialog::getInt(this,"睁眼","是否睁眼",0,0,1,1,&ok);
                    if(!ok)return;
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

QMessageBox::information(this,"游戏进行","天亮了");
 bgpic=0;

QMessageBox::information(this,"游戏进行","请村长选择发言方向(0左)");
ok=false;
f=QInputDialog::getInt(this,"","请选择发言方向",0,0,1,1,&ok);
 if(!ok)return;
if(f==0){
        for(i=e;i>=0;i--)
    {

    if(pyr[i].state==1)
         {
        m[i/5][i%5]=1;
         QMessageBox::information(this,"游戏进行","现在是"+QString::number(i+1)+"号玩家发言");
        m[i/5][i%5]=0;
         }
         else continue ;
    }
    for(i=rs-1;i>e;i--)
    {
        if(pyr[i].state==1){
            m[i/5][i%5]=1;
             QMessageBox::information(this,"游戏进行","现在是"+QString::number(i+1)+"号玩家发言");
            m[i/5][i%5]=0;
        }
        else continue ;
        }

     } //左向发言
     else{
        for(i=e;i<rs;i++)
    {
        if(pyr[i].state!=0)
         {
            m[i/5][i%5]=1;
             QMessageBox::information(this,"游戏进行","现在是"+QString::number(i+1)+"号玩家发言");
            m[i/5][i%5]=0;
         }
    };
    for(i=0;i<e;i++)
    {
        if(pyr[i].state!=0){
            m[i/5][i%5]=1;
             QMessageBox::information(this,"游戏进行","现在是"+QString::number(i+1)+"号玩家发言");
            m[i/5][i%5]=0;

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
           c=-1;
           while(c==-1)
           {
               c=-1;
               QMessageBox::information(this,"游戏进行","现在是"+QString::number(i+1)+"号玩家投票");
             ok=false;
                pyr[i].vote=QInputDialog::getInt(this,"投票踢人","投票给",1,1,rs,1,&ok);
                 if(!ok)return;
                c=pyr[i].vote;
                c--        ;
                if(pyr[c].state==0)c=-1;
           }

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
           QMessageBox::information(this,"游戏进行","请输入下一任村长序号");
              ok=false;
           e=QInputDialog::getInt(this,"","下一任村长是",1,1,rs,1,&ok);
            if(!ok)return;
           e--;
        }
       pyr[s].pos=1;
       k[s/5][s%5]=0;
       pyr[e].pos=0;
       k[e/5][e%5]=1;
    };
   if(pyr[s].camp==0)
      { QMessageBox::information(this,"身份公布","玩家"+QString::number(s+1)+"号被驱逐了，他的身份是黑方");
        st[s/5][s%5]=3;}
   else  {QMessageBox::information(this,"身份公布","玩家"+QString::number(s+1)+"号被驱逐了，他的身份是红方");
          st[s/5][s%5]=2;}

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
       QMessageBox::information(this,"游戏结果","红方胜利");
       else if (y==0)
        QMessageBox::information(this,"游戏结果","黑方胜利");
       else {QMessageBox::information(this,"游戏结果","游戏继续");}

       for(i=0; i<rs; ++i)
       {
           pyr[i].voted=0;
       }


       if(x==0||y==0)gg=1;
       else gg=0;

}


QMessageBox::information(this,"游戏结果","游戏结束");



}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{

    int i=0;
    int j=0;
    QPainter p(this);
    if (bgpic==0){p.setBrush(Qt::white);p.drawRect(0,0,1040,600);}
     else if(bgpic==1){p.setBrush(Qt::black);p.drawRect(0,0,1040,600);}
     else{p.setBrush(Qt::darkRed);p.drawRect(0,0,1040,600);}

    while(i<3)
    {
       j=0;
        while(j<5)
        {
            if(st[i][j]==0){p.setBrush(Qt::lightGray);p.drawRect(30+210*j,30+150*i,140,100);}
            else if(st[i][j]==1){
                p.setBrush(Qt::cyan);
                p.drawRect(30+210*j,30+150*i,140,100);
                p.drawText(QRect(30+210*j,30+150*i,140,100),QString::number(i*5+j+1),QTextOption(Qt::AlignCenter));
                }
            else if(st[i][j]==2){
                p.setBrush(Qt::red);
                p.drawRect(30+210*j,30+150*i,140,100);
                p.drawText(QRect(30+210*j,30+150*i,140,100),QString::number(i*5+j+1),QTextOption(Qt::AlignCenter));}
            else if(st[i][j]==3){
                p.setBrush(Qt::black);
                p.drawRect(30+210*j,30+150*i,140,100);
                p.drawText(QRect(30+210*j,30+150*i,140,100),QString::number(i*5+j),QTextOption(Qt::AlignCenter));}
            j++;
        }
        j=0;
              while(j<6)
              {
                  if(m[i][j]==1) qDrawPlainRect(&p,30+210*j,30+150*i,140,100,Qt::darkMagenta,3,0);
                  if(k[i][j]==1) qDrawPlainRect(&p,30+210*j,30+150*i,140,100,Qt::yellow,3,0);
                  j++;
              }
        i++;
    }

    p.drawPixmap(0,0,1040,600,QPixmap());







}



















