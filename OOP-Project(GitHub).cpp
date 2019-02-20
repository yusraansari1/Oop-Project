#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<process.h>
using namespace std;
class worker
{
	protected:
		char name[30];
	public:
		void input()
		{
			cout<<"What is the name of the worker? ";
			cin>>name;
		}
		void display()
		{
			cout<<"\nThe name of the worker is: "<<name;
		}
};
class r_worker: public worker
{
	private:
		float salary;
		int hours;
	public:
		void input()
		{
			worker::input();
			cout<<"\nHow much is the monthly income? "; cin>>salary;
			cout<<"\nHow many hours do the worker work? "; cin>>hours;
		}	
		void display()
		{
			worker::display();
			cout<<"\nThe monthly income of the worker is: "<<salary;
			cout<<"\nNo. of hours the worker works are: "<<hours;
		}
};
class db_worker: public worker 
{
	private:
		float salary;
		int hours;
	public:
		void input()
		{
			worker::input();
			cout<<"\nHow much is the monthly income of the delivery boy? ";
			cin>>salary;
			cout<<"\nHow many hours do the delivery boy work? ";
			cin>>hours;
		}	
		void display()
		{
			worker::display();
			cout<<"\nThe monthly income of the delivery boy is: "<<salary;
			cout<<"\nNo. of hours the delivery boy works are: "<<hours;
		}
};
class customer
{
	protected:
		char name[30];
		char pza[40];
	public:
		void intake()
		{
			cout<<"\nWhat is the name of the customer? ";
			cin>>name;
			cout<<"\nWhich pizza do the customer wants? ";
			cin>>pza;
		}
		void show()
		{
			cout<<"\nThe name of the customer is: "<<name;
			cout<<"\nThe pizza which the customer wants is: "<<pza;
		}	
};
class reg_customer: public customer
{
	private:
		char come[40];
	public:
		void intake()
		{
			customer::intake();
			cout<<"\nHow often do the customer come? ";
			cin>>come;
		}
		void show()
		{
			customer::show();
			cout<<"\nThe customer comes: "<<come;
			cout<<"\nThe customer will get either a free salad or a free pasta as he/she is our regular customer!";
		}	
};
class irreg_customer: public customer
{
	private:
		char come[40];
	public:
		void intake()
		{
			customer::intake();
			cout<<"\nHow often do the customer come? ";
			cin>>come;
		}
		void show()
		{
			customer::show();
			cout<<"\nThe customer comes: "<<come;
			cout<<"\nThe customer will only get a free cold drink as he/she is our irregular customer!";
		}	
};
class pizza
{
    void add_cheese()
    {
        cout << "Cheese added!  ";
    }
    void add_sauces()
    {
        cout << "\nSauces added!  ";
    }
    virtual void ph1() = 0;
  public:
    // 1. Standardize the skeleton of an algorithm in a base class "template method"
    void make_p()
    {
        add_cheese();
        ph1();
        add_sauces();
		cout<<"\nYour Pizza is ready";
    }
};
class p_veggie: public pizza
{
    // 3. Derived classes implement placeholder methods
     /*virtual*/void ph1()
    {
        cout << "\nVeggies added!  ";
    }
};
class p_tikka: public pizza
{
     /*virtual*/void ph1()
    {
        cout << "\nChicken tikka chunks added!  ";
    }
};
int main()
{
  cout<<"       WELCOME TO PIZZERIA      ";
  cout<<"       \nPress 1 if you want to order Veggie Pizza ";
  cout<<"       \nPress 2 if you want to order Chicken Tikka Pizza ";
  cout<<"       \nPress 3 if you want to enter the details of the customer & get it displayed  ";
  cout<<"       \nPress 4 if you want to enter the details of the worker & get it displayed   ";
  cout<<"       \nPress 5 if you want to exit\n ";
  char ch,op,lg;
  reg_customer r1;
  irreg_customer i1;
  r_worker w1;
  db_worker d1;
  pizza *array[] = 
  {
     &p_veggie(), &p_tikka()
  };
  while(1)
  {
  cin>>ch;
  if(ch=='1')
  {
  for (int i = 0; i < 1; i++)
  {
    array[i]->make_p();
    cout << '\n';
  }
  }
  else if(ch=='2')
  {
  for (int i = 1; i < 2; i++)
  {
    array[i]->make_p();
    cout << '\n';
  }
  }
  else if(ch=='3')
  {
	cout<<"Enter 1 for regular customer OR Enter 2 for irregular customer!";
    cin>>op;
	if(op=='1')
	{
		r1.intake();
	    r1.show();
	}
	else if(ch=='2')
	{
	    i1.intake();
	    i1.show();
	}
  }
  else if(ch=='4')
  {
     cout<<"Enter 1 for the worker at the restaurant OR Enter 2 for the delivery boy!";
     cin>>lg;
	 if(lg=='1')
	{
		w1.input();
	    w1.display();
	}
	else if(lg=='2')
	{
	    d1.input();
	    d1.display();
	} 
  }
  else if(ch=='5')
  {
	  cout<<" People disappoint !";
	  cout<<" Pizza is eternal !!";
	  exit(0);
  }
  }
  getch();
}

