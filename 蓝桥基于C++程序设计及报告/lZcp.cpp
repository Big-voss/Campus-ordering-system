#include<iostream>
#include<stdlib.h>
#include<ctime> 
#include<vector>
#include<string>
#include <sstream>
#include<cstring>
using namespace std;

typedef struct _MENU
{
	string name;//菜名
	float price;//菜价
}Menu;
void fuck(){
	    cout<<"***********************************" <<endl; 
	cout<<"*****  Lzcp校园食堂点餐系统  ******"<<endl;
    cout<<"******      1.登陆系统      *******"<<endl;
    cout<<"******      2.座位查找      *******"<<endl;
    cout<<"******      3.意见反馈      *******"<<endl;
    cout<<"******      0.退出系统      *******"<<endl;
    cout<<"***********************************" <<endl; 
}

	//查找座位 
	 void seat()
{
   int n, t;
   int a[21][6] = {0}; 
   
   for(int i=0; i<20; i++)
        a[i][5] = 5;
         cout<<"请输入几批人: "<<endl; 
   cin>>n;
   cout<<"\n";
   cout<<"请输入每组几个人: "<<endl; 
   while(n--) 	 //n自减1，一直到n等于0时跳出 
    { 
   	   
       cin>>t;
       cout<<"\n";
       int flag=0;
       for(int i=0; i<20; i++)  //有连续座位  列 
       {
          if(a[i][5]>=t)		// 行 
          {
             a[i][5]-=t;
            for(int j=0; j<5; j++)
            {
                if(!a[i][j])
                {
                    a[i][j]=1;
                    t--;
                    if(t)     	
                    {
                    
                    			printf("%d\t", i*5+j+1);
					}
			
                    else
                    {
                  	   if(n)  
						 printf("%d\t", i*5+j+1);
                       else 
                       {
                       	
                       	        	 printf("%d\t", i*5+j+1);
					   } 
					    
                       flag=1;
                       break;
                      }
                   }
               }
            }
        if(flag)  break;
   }
    if(!flag)
   {
     for(int i=0; i<20; i++)	//列 
     {  for(int j=0; i<5; j++)		//行 
        {
           if(!a[i][j])
            {  a[i][j]=1;
                t--;
                a[i][5]--;
              if(t)  
              {
      
              	 printf("%d\t", i*5+j+1);
			  }
			 
              else{
                   if(n) 
				   printf("%d\t", i*5+j+1);
                    
                    flag=1;
                    break;
                   }
               }
           }
           if(flag) break;     
        }
      }
  }
  		
			system("pause");
			system("cls");
}
	
	
	//意见反馈 
	class feed{
		private:
			char idea[20];
		public:
			feed();
			feed(char idea[]);
			char* getidea();
			void inidea();
	};
	feed::feed(){
		strcpy(idea,"");
	}
    feed::feed(char idea[]){
		strcpy(this->idea,idea);
	}
	char* feed::getidea(){
		return idea;
	}
	void feed::inidea(){
		cin>>idea;
	}
	void  Feedback()
	{
		feed feedback[20];
		char idea[20];
		int x,z=0;
		cin>>x;
		while(x){
			switch(x){
				case 1:{
		cout<<"请输入您对我们的意见或者建议"<<endl;
		feedback[z].inidea();
		z=z+1;
		cout<<"感谢您宝贵的建议"<<endl;
		break;
	}
	           case 2:{
	           	for(int y=0;y<z;y++){
	           		cout<<feedback[y].getidea()<<endl;
				   }
				break;
			   }
	}
	cout<<"按1提出建议，按2查看意见箱，按0返回主页面"<<endl;
	cin>>x; 
}
		system("pause");
		system("cls");
}
	
	
//饭堂
class cateen
{
private:
    static Menu menu[5];//菜单
     	
public:
     //罗列显示菜单
     static void list()
	 {
		cout<<"菜单名\t价格"<<endl;
		for(int i=0;i<5;i++)
		{
			cout<<menu[i].name<<"\t"<<menu[i].price<<endl;
		}
				 
	 }
	 
	 //获取菜单价格
	 static float getPrice(string n)
	 {
		for(int i=0;i<5;i++)
        {
			if(menu[i].name == n)//找到菜单名
			{
				return menu[i].price;//获取到菜单价格
			}
		}			
		 
		 return -1;//没找到菜单	
	 }
	
};

//定义菜单和价格
Menu cateen::menu[5]=
{
	{"臭豆腐",7.8},
	{"老干妈",5.8},
	{"秘制小汉堡",9.8},
	{"五香花生",4.8},
	{"大扒鸭",24.8},
};


//饭卡
class card
{
private:
     float money;

public:
    //初始化卡的余额 
    card()
	{
		money=100;
	}

    //刷饭卡
    bool pay(float m)
	{
		if(m>money)//余额不足
	    {
			cout<<"余额不足，无法购买"<<endl;
			return false;			
		}
		
		cout<<"价格为"<<m<<endl;
		
		money -= m;
		return true;
	}	
	
	//充值
	void charge(float m)
	{
		money += m;
	}
			
	
	//显示余额
	void shomoney()
	{
		cout<<"饭卡余额:"<<money<<endl;
	}
		
};


//人
class person: public card
{
private:
	
public:	
	//点餐
	virtual bool order(string n) = 0;
	//登录
	virtual bool login(string n)=0;
	//显示信息
    virtual void show() =0;

};


//普通学生（继承人）
class student:public person
{
private:
	 const int num;//学号
	 const string name;//姓名
	 
public:
    student(string ni,int n):num(n),name(ni)//const修饰成员变量只能在初始化列表中完成
	{
		
	}

     //点餐
	virtual bool order(string n)
	{
		float price=cateen::getPrice(n);//获取菜单价格		
		//没找到菜
		if(price == -1)
		{
			return false;
		}		
		//刷饭卡
		return pay(price);
	
	}	
	
	//登录
    virtual bool login(string n)
	{
		if(n==name)
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	//显示信息
	virtual void show()
	{
		shomoney();//显示余额
		cout<<"学号:"<<num<<"\t"<<"名字:"<<name<<endl;//显示学号和名字
		
	}
	 
};

//研究生(继承学生)
class graduate:public student
{
private:	
	float wage;//工资
	
public: 
	//定义工资
    graduate(string ni,int n):student(ni,n)
	{
		wage=10000;
	}	
	
	//显示信息
	void show()
	{
       student::show();
	   cout<<"工资："<<wage<<endl;	   
	}
};


//员工
class staff:public person
{
private:
	const string name;
	
public:
	staff(string n):name(n)
	{
		
	}

	//点餐
	virtual bool order(string n)
	{
		//获取菜单价
		float price = cateen::getPrice(n);
		if(price == -1)
		{
			return false;
		}
		
		//刷卡，打9折
		return pay(0.9*price);
	}
	
	//登录
    virtual bool login(string n)
	{
		if(n == name)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	
	//显示信息
	virtual void show()
	{
		//显示余额
		shomoney();
		cout<<"员工名字："<<name<<endl;			
	}
	
};

int main(int argc,char *argv[])
{
	int i=0;
	int login_break=1;//登录标志位
	int order_continue=0;//继续点餐标志位
	float money;//充值金额
	fuck();
	vector<person*> pvec;
	//100个普通的学生
	//学号: 10001-10100
	//姓名: student1 - student100
	for(i=0;i<100;i++)
	{
		stringstream ss;
		ss<<i+1;
		string str ="学生"+ss.str();
		
		person* p=new student(str,1+i);//姓名和学号
		
        pvec.push_back(p);//加入容器	
	}
	
	//10个研究生
	//学号: 10101-10110
	//姓名: graduate101 - graduate110
	for(;i<110;i++)
	{
		stringstream ss;
		ss<<i+1;
		string str ="研究生"+ss.str();
		
		person* p=new graduate(str,1+i);//姓名和学号
		
        pvec.push_back(p);//加入容器	
			
		
	}
	
	//10个员工
    //姓名: staff111 - staff120
	for(;i<120;i++)
	{
		stringstream ss;
		ss<<i+1;
		string str ="员工"+ss.str();
		
		person* p=new staff(str);//姓名和学号
		
		 pvec.push_back(p);//加入容器
	}
	
	//登录
	string name;
	person * pcur=NULL;
	int x; 
	cout<<"请选择要执行的功能："; 
	cin>>x;
	while(x){
	switch(x){
		case 1:{ 
	while(login_break)
	{
		cout<<"请输入你的名字："<<endl;
		cin>>name;
		
		for(int i=0;i<pvec.size();i++)
		{
			if(pvec[i]->login(name))
			{
				cout<<"登录成功"<<endl;
				pcur = pvec[i];
				login_break=0;
				break;
			}	
		}
		
		if(pcur ==NULL)//登录失败
		{
			cout<<"输入错误，请重新输入"<<endl;
		}
	}
			
	//显示该用户的信息
	pcur->show();
		
	//列出菜单
	cateen::list();
	
	//点菜
	string eating;	
	while(1)
	{
		cout<<"按1点餐,按2充值饭卡,按0退出点餐"<<endl;
		cin>>order_continue;
		if(order_continue==0)
		{
			break;
		}
		else if(order_continue==1){
				cout<<"请点餐："<<endl;
		cin>>eating;
		if(!pcur->order(eating))
		{
			cout<<"点餐失败,重新点餐"<<endl;	
		}	
		else
		{
			cout<<"点餐成功,你点的为:"<<eating<<endl;
            //显示当前饭卡剩余余额
	        cout<<"当前";
            pcur->shomoney();			
		}
		}
		else if(order_continue ==2)
		{
			cout<<"请输入充值的金额:";
			cin>>money;
			pcur->charge(money);
			//显示饭卡余额
			cout<<"充值成功,";
            pcur->shomoney();		
		}
	
	}
	login_break=1;
	system("pause");
	system("cls");
	break;
	}
		//座位查找 
		case 2:{
			seat();
			break;
		}
		
	//意见反馈 
		case 3:{
			cout<<"按1提出建议，按2查看意见箱，按0返回主页面"<<endl;
			Feedback();
			break;
		} 
}
    fuck();
    cout<<"请选择要执行的功能："<<endl; 
	cin>>x;
}
	cout<<"***********************************" <<endl;
    cout<<"*  欢迎下次使用Lzcp校园点餐系统!  *"<<endl;
    cout<<"***********************************" <<endl;
	return 0;
	
}

