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
	string name;//����
	float price;//�˼�
}Menu;
void fuck(){
	    cout<<"***********************************" <<endl; 
	cout<<"*****  LzcpУ԰ʳ�õ��ϵͳ  ******"<<endl;
    cout<<"******      1.��½ϵͳ      *******"<<endl;
    cout<<"******      2.��λ����      *******"<<endl;
    cout<<"******      3.�������      *******"<<endl;
    cout<<"******      0.�˳�ϵͳ      *******"<<endl;
    cout<<"***********************************" <<endl; 
}

	//������λ 
	 void seat()
{
   int n, t;
   int a[21][6] = {0}; 
   
   for(int i=0; i<20; i++)
        a[i][5] = 5;
         cout<<"�����뼸����: "<<endl; 
   cin>>n;
   cout<<"\n";
   cout<<"������ÿ�鼸����: "<<endl; 
   while(n--) 	 //n�Լ�1��һֱ��n����0ʱ���� 
    { 
   	   
       cin>>t;
       cout<<"\n";
       int flag=0;
       for(int i=0; i<20; i++)  //��������λ  �� 
       {
          if(a[i][5]>=t)		// �� 
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
     for(int i=0; i<20; i++)	//�� 
     {  for(int j=0; i<5; j++)		//�� 
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
	
	
	//������� 
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
		cout<<"�������������ǵ�������߽���"<<endl;
		feedback[z].inidea();
		z=z+1;
		cout<<"��л������Ľ���"<<endl;
		break;
	}
	           case 2:{
	           	for(int y=0;y<z;y++){
	           		cout<<feedback[y].getidea()<<endl;
				   }
				break;
			   }
	}
	cout<<"��1������飬��2�鿴����䣬��0������ҳ��"<<endl;
	cin>>x; 
}
		system("pause");
		system("cls");
}
	
	
//����
class cateen
{
private:
    static Menu menu[5];//�˵�
     	
public:
     //������ʾ�˵�
     static void list()
	 {
		cout<<"�˵���\t�۸�"<<endl;
		for(int i=0;i<5;i++)
		{
			cout<<menu[i].name<<"\t"<<menu[i].price<<endl;
		}
				 
	 }
	 
	 //��ȡ�˵��۸�
	 static float getPrice(string n)
	 {
		for(int i=0;i<5;i++)
        {
			if(menu[i].name == n)//�ҵ��˵���
			{
				return menu[i].price;//��ȡ���˵��۸�
			}
		}			
		 
		 return -1;//û�ҵ��˵�	
	 }
	
};

//����˵��ͼ۸�
Menu cateen::menu[5]=
{
	{"������",7.8},
	{"�ϸ���",5.8},
	{"����С����",9.8},
	{"���㻨��",4.8},
	{"���Ѽ",24.8},
};


//����
class card
{
private:
     float money;

public:
    //��ʼ��������� 
    card()
	{
		money=100;
	}

    //ˢ����
    bool pay(float m)
	{
		if(m>money)//����
	    {
			cout<<"���㣬�޷�����"<<endl;
			return false;			
		}
		
		cout<<"�۸�Ϊ"<<m<<endl;
		
		money -= m;
		return true;
	}	
	
	//��ֵ
	void charge(float m)
	{
		money += m;
	}
			
	
	//��ʾ���
	void shomoney()
	{
		cout<<"�������:"<<money<<endl;
	}
		
};


//��
class person: public card
{
private:
	
public:	
	//���
	virtual bool order(string n) = 0;
	//��¼
	virtual bool login(string n)=0;
	//��ʾ��Ϣ
    virtual void show() =0;

};


//��ͨѧ�����̳��ˣ�
class student:public person
{
private:
	 const int num;//ѧ��
	 const string name;//����
	 
public:
    student(string ni,int n):num(n),name(ni)//const���γ�Ա����ֻ���ڳ�ʼ���б������
	{
		
	}

     //���
	virtual bool order(string n)
	{
		float price=cateen::getPrice(n);//��ȡ�˵��۸�		
		//û�ҵ���
		if(price == -1)
		{
			return false;
		}		
		//ˢ����
		return pay(price);
	
	}	
	
	//��¼
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

	//��ʾ��Ϣ
	virtual void show()
	{
		shomoney();//��ʾ���
		cout<<"ѧ��:"<<num<<"\t"<<"����:"<<name<<endl;//��ʾѧ�ź�����
		
	}
	 
};

//�о���(�̳�ѧ��)
class graduate:public student
{
private:	
	float wage;//����
	
public: 
	//���幤��
    graduate(string ni,int n):student(ni,n)
	{
		wage=10000;
	}	
	
	//��ʾ��Ϣ
	void show()
	{
       student::show();
	   cout<<"���ʣ�"<<wage<<endl;	   
	}
};


//Ա��
class staff:public person
{
private:
	const string name;
	
public:
	staff(string n):name(n)
	{
		
	}

	//���
	virtual bool order(string n)
	{
		//��ȡ�˵���
		float price = cateen::getPrice(n);
		if(price == -1)
		{
			return false;
		}
		
		//ˢ������9��
		return pay(0.9*price);
	}
	
	//��¼
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
	
	//��ʾ��Ϣ
	virtual void show()
	{
		//��ʾ���
		shomoney();
		cout<<"Ա�����֣�"<<name<<endl;			
	}
	
};

int main(int argc,char *argv[])
{
	int i=0;
	int login_break=1;//��¼��־λ
	int order_continue=0;//������ͱ�־λ
	float money;//��ֵ���
	fuck();
	vector<person*> pvec;
	//100����ͨ��ѧ��
	//ѧ��: 10001-10100
	//����: student1 - student100
	for(i=0;i<100;i++)
	{
		stringstream ss;
		ss<<i+1;
		string str ="ѧ��"+ss.str();
		
		person* p=new student(str,1+i);//������ѧ��
		
        pvec.push_back(p);//��������	
	}
	
	//10���о���
	//ѧ��: 10101-10110
	//����: graduate101 - graduate110
	for(;i<110;i++)
	{
		stringstream ss;
		ss<<i+1;
		string str ="�о���"+ss.str();
		
		person* p=new graduate(str,1+i);//������ѧ��
		
        pvec.push_back(p);//��������	
			
		
	}
	
	//10��Ա��
    //����: staff111 - staff120
	for(;i<120;i++)
	{
		stringstream ss;
		ss<<i+1;
		string str ="Ա��"+ss.str();
		
		person* p=new staff(str);//������ѧ��
		
		 pvec.push_back(p);//��������
	}
	
	//��¼
	string name;
	person * pcur=NULL;
	int x; 
	cout<<"��ѡ��Ҫִ�еĹ��ܣ�"; 
	cin>>x;
	while(x){
	switch(x){
		case 1:{ 
	while(login_break)
	{
		cout<<"������������֣�"<<endl;
		cin>>name;
		
		for(int i=0;i<pvec.size();i++)
		{
			if(pvec[i]->login(name))
			{
				cout<<"��¼�ɹ�"<<endl;
				pcur = pvec[i];
				login_break=0;
				break;
			}	
		}
		
		if(pcur ==NULL)//��¼ʧ��
		{
			cout<<"�����������������"<<endl;
		}
	}
			
	//��ʾ���û�����Ϣ
	pcur->show();
		
	//�г��˵�
	cateen::list();
	
	//���
	string eating;	
	while(1)
	{
		cout<<"��1���,��2��ֵ����,��0�˳����"<<endl;
		cin>>order_continue;
		if(order_continue==0)
		{
			break;
		}
		else if(order_continue==1){
				cout<<"���ͣ�"<<endl;
		cin>>eating;
		if(!pcur->order(eating))
		{
			cout<<"���ʧ��,���µ��"<<endl;	
		}	
		else
		{
			cout<<"��ͳɹ�,����Ϊ:"<<eating<<endl;
            //��ʾ��ǰ����ʣ�����
	        cout<<"��ǰ";
            pcur->shomoney();			
		}
		}
		else if(order_continue ==2)
		{
			cout<<"�������ֵ�Ľ��:";
			cin>>money;
			pcur->charge(money);
			//��ʾ�������
			cout<<"��ֵ�ɹ�,";
            pcur->shomoney();		
		}
	
	}
	login_break=1;
	system("pause");
	system("cls");
	break;
	}
		//��λ���� 
		case 2:{
			seat();
			break;
		}
		
	//������� 
		case 3:{
			cout<<"��1������飬��2�鿴����䣬��0������ҳ��"<<endl;
			Feedback();
			break;
		} 
}
    fuck();
    cout<<"��ѡ��Ҫִ�еĹ��ܣ�"<<endl; 
	cin>>x;
}
	cout<<"***********************************" <<endl;
    cout<<"*  ��ӭ�´�ʹ��LzcpУ԰���ϵͳ!  *"<<endl;
    cout<<"***********************************" <<endl;
	return 0;
	
}

