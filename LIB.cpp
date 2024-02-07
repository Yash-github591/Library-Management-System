#include<fstream.h>
#include<process.h>
#include<graphics.h>
#include<conio.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <dos.h>
void type(int x,int y,char c[])
{int i;
 gotoxy(x,y);
 for(i=0;i<=strlen(c);i++)
 {if(i[c]==' ')
   {cout<<i[c];}
  else if(i%2==0)
  {cout<<i[c];sound(1300);delay(20);
   nosound();delay(30);
   }
   else
  {cout<<i[c];delay(20);
   nosound();delay(30);
   }
 }
} //******************************************type function
void rect(int x,int y,int n)
 {x=x+60;
 setfillstyle(1,n);
  bar(x-70,y-10,x+70,y+10);
 }
//*********************************************rect funtion
struct stud
{ int admno,bno;
  char name[20],bname[15];
  time_t issue;
void output()
 {clrscr();highvideo();
  type(25,10,"name=");type(30,10,name);
  type(25,11,"admission number=");cout<<admno;
  type(25,12,"book issued=");type(40,12,bname);
  type(25,13,"book number=");cout<<bno;
  type(25,14,"date of issue=");cout<<ctime(&issue);
 }
void input()
 {clrscr();highvideo();
  type(25,10,"enter your name=");gets(name);
  type(25,11,"enter the admission number=");cin>>admno;
  type(25,12,"enter the name of the book to  be issued=");gets(bname);
  type(25,13,"enter the book number=");cin>>bno;
  issue=time(NULL);
  }
};//end of structure
void issue()
{ highvideo();
  clrscr();
  ofstream out("lib.dat",ios::binary|ios::app);
  ifstream in("lib .dat",ios::binary);
   int a,b,n=1;
   stud s,s1;char ch='y';
while(ch=='y')
 {   s.input(); a=s.admno; b=s.bno;
   while(!in.eof())
    {
     in.read((char*)&s1,sizeof(s1));
     if(s1.bno==b)
       {type(25,14,"this book has been already issued.");
	n=0;break;}
     if(s1.admno==a)
       {type(20,15,"sorry,a student can't issue more than one book at a time.");
	n=0;break;
       }
     }//while loop
	if(n)
	{  type(15,14,"you will be charged rupees 5 for each day.Enjoy reading the book.");
	  out.write((char*)&s,sizeof(s));
	}
    type(25,16,"do you want to try again(y/n).");cin>>ch;
   }
in.close();
out.close();
}///*****************************************************issue function
void give()
{clrscr();highvideo();
 stud s;int i,p,n=1; time_t give;char ch='y';
 give=time(NULL);
fstream read("lib .dat",ios::binary|ios::in|ios::out);
while(ch=='y')
{clrscr();
 type(25,10,"enter the book no. or admission no.");cin>>i;
  while(!read.eof())
   {
     read.read((char*)&s,sizeof(s));
     if(s.bno==i||s.admno==i)
       {
	s.output(); long float d=difftime(give,s.issue)/86400;
	 type(25,15,"number of days you kept the book=");
	cout<<difftime(give,s.issue)/86400<<"days";
	type(25,16,"press any key to return...");getch();
	ofstream tempout("temp .dat",ios::binary);//,ios::binary|ios::in|ios::out);
	ifstream tempin("lib .dat",ios::binary);
	while(!tempin.eof())
	 { tempin.read((char*)&s,sizeof(s));
	     if(s.bno!=i&&s.admno!=i)
	       {tempout.write((char*)&s,sizeof(s));}
	 }
	 tempout.close();tempin.close();
	 remove("lib.dat");rename("temp.dat","lib.dat");
	clrscr();type(25,10,"your book has been returned....");
	type(25,11,"Library charge=Rs");cout<<d*5;delay(100);
	n=0;break;
       }
    }
      if(n)
      { clrscr();
       type(25,11,"there is an error in the transaction.");
       type(25,12,"Either the book no. is not correct or");
       type(25,13,"your admission no. is wrong...");
       }
      type(25,17,"do you want to try again(y/n).");cin>>ch;
  }
 read.close();
}////*******************************************************give function
void see()
{highvideo();
  h:
 clrscr();
 stud s;int i,p,n=1;  char ch='y';
 while(ch=='y')
 {clrscr();
  type(25,10,"enter the book no. or admission no.");cin>>i;
  fstream read("lib .dat",ios::binary|ios::in|ios::out);
  while(!read.eof())
   {
     read.read((char*)&s,sizeof(s));
     if(s.bno==i||s.admno==i)
       {
	s.output();n=0;
	break;
       }
   }
      if(n)
      {
       type(25,11,"there is no book with this book no.");
	type(25,12,"or the admission no. of the owner of the book is wrong.");
      }  read.close();
       type(25,15,"do you want to try again(y/n).");cin>>ch;
   }
}//****************************************************see function
void bookdetails()
{h:
 clrscr();highvideo();
 char ch; int p,n,n2,i,n3=1,n4=1; stud s; i=8;
 type(25,9,"choose the desired option...");
 type(25,11,"1.see the details of a particular book.");
 type(25,12,"2.see the list of all the issued books.");
 type(25,14,"enter your choise..");gotoxy(25,15);cin>>ch;
 clrscr();
 fstream read("lib .dat",ios::binary|ios::in|ios::out);
 if(ch=='1')
 {n4=0;
 type(25,10,"Enter the book number.");cin>>n;
  n2=1;
  while(!read.eof())
    {
     read.read((char*)&s,sizeof(s));
     if(s.bno==n)
       {n2=0;clrscr();n3=0;
	type(15,10,"The book ");cout<<s.bname;
	type(15,11,"was issued to");cout<<s.name<<" on "<<ctime(&s.issue);
	break;
       }
    }
     if(n2)
      {clrscr();type(25,11,"the book with this book no. is not issued!!");n3=0;}
  }
 else
 {  //if(!read.eof())//read.read((char*)&s,sizeof(s)))
    if(read.read((char*)&s,sizeof(s)))
   { n3=0;
     type(10,7,"Book name");type(30,7,"issued to");type(50,7,"date of issue");
     while(read.read((char*)&s,sizeof(s)))
      { //n3=0;
	p=read.tellg();
	read.seekp(p-sizeof(s),ios::beg);
	read.read((char*)&s,sizeof(s));
	gotoxy(10,i);cout<<s.bname;
	gotoxy(30,i);cout<<s.name;
	gotoxy(50,i);cout<<ctime(&s.issue);
	i=i+2;delay(80);
     }
   }
 }
  if(n3)
   {clrscr();i=i+3;
    type(25,11,"no book has been issued till date.");}
 read.close();
 if(n4)
 { type(25,i+2,"do you want to try again(y/n).");}
 else
 {type(25,15,"do you want to try again(y/n).");}
  cin>>ch;
     if(ch=='y')
      {clrscr();n3=1;goto h;}

}//***********************************************************details
void main()
{highvideo();
clrscr();
int ch,i,x,y;char e,a[5],b[]="abcde";
//password*****************************************************
a2:
ch=0;
type(30,10,"enter the password:-");
gotoxy(30,11);
for(i=0;i<=4;i++)
{a[i]=getch();cprintf("*");
 if(a[i]==b[i])
  ch=ch+0;
 else
  ch++;}
 getch();
 if(ch==0)
{clrscr();
 gotoxy(33,10);cprintf("access granted.");sleep(1);
 int gd=DETECT,gm;
 initgraph(&gd, &gm, "c://turboc3//bgi");
   x = getmaxx() / 2;
   y = getmaxy() / 2;
   outtextxy(x-50,y-50,"wait starting...");
  int l;
  l=3;
     for (i=-190; i<190; i++)
   {
     rectangle(x-191,y-(l+1),x+191,y+(l+1));
     setfillstyle(4,getmaxcolor());
     bar(x-190,y-l,x+i,y+l);
      delay(20);
      }
   delay(500);
   closegraph();
}
else
{
 clrscr();
 gotoxy(33,10);cprintf("incorrect password.");
 gotoxy(33,11);cout<<"1.exit. ";
 gotoxy(33,12);cout<<"2.try again.";
 gotoxy(33,13);cprintf("enter your choice:");
 cin>>e;
  if(e=='1')
   {exit(0);}
  if(e=='2')
  {clrscr();goto a2;}
}
int gd=DETECT,gm;
initgraph(&gd,&gm,"c://turboc3//bgi");
x=getmaxx()/2;y=getmaxy()/2;
//******************************************************coverpage
x=x-50;y=y-80;
settextstyle(4,HORIZ_DIR,7);delay(400);
outtextxy(x-110,y-85,"welcome");delay(300);
outtextxy(x+120,y-85,"to");delay(300);
settextstyle(1,HORIZ_DIR,5);
setcolor(10);
outtextxy(x-30,y-20,"the");delay(500);
settextstyle(5,HORIZ_DIR,10);
setcolor(12);
outtextxy(x-250,y-30,"LIBRARY");settextstyle(0,HORIZ_DIR,1);delay(700);
setcolor(getmaxcolor());outtextxy(x+80,y+200,"presented by Yash and Aman");
getch();cleardevice();
//**********************************************************coverpage
x=x-50;y=y+50;
h:
settextstyle(5,HORIZ_DIR,5);
outtextxy(x-200,y-200,"choose the option of your choice...");settextstyle(0,HORIZ_DIR,1);
int y2=1;
char c,c1[]={"1.issue book"},
c2[]={"2.return book"},c3[]={"3.see records"},c4[]={"4.book details"},c5[]="5.exit";
outtextxy(x-50,y+110,"press a to go down,q to go up and s to select.");
rect(x,y,4);
setcolor(0); outtextxy(x,y,c1);setcolor(getmaxcolor());
 outtextxy(x,y+20,c2);
 outtextxy(x,y+40,c3);
 outtextxy(x,y+60,c4);
 outtextxy(x,y+80,c5);
while(c!='s')
    {c=getch();sound(1300);delay(20);nosound();
     setfillstyle(1,0);
    bar(x-200,y-100,x+200,y+100);
      if((c=='a'&&y2==1)||(c=='q'&&y2==3))
	  {rect(x,y+20,4);
	   outtextxy(x,y,c1);
	   setcolor(0);outtextxy(x,y+20,c2);setcolor(getmaxcolor());
	   outtextxy(x,y+40,c3);
	   outtextxy(x,y+60,c4);
	   outtextxy(x,y+80,c5);
	   y2=2;
	   }
      else if((c=='a'&&y2==2)||(c=='q'&&y2==4))
	   { rect(x,y+40,4);
	     outtextxy(x,y,c1);
	    outtextxy(x,y+20,c2);
	    setcolor(0);outtextxy(x,y+40,c3);setcolor(getmaxcolor());
	    outtextxy(x,y+60,c4);
	    outtextxy(x,y+80,c5);
	    y2=3;
	   }
    else if((c=='a'&&y2==3)||(c=='q'&&y2==5))
	  { rect(x,y+60,4);
	    outtextxy(x,y,c1);
	    outtextxy(x,y+20,c2);
	    outtextxy(x,y+40,c3);
	    setcolor(0);outtextxy(x,y+60,c4);setcolor(getmaxcolor());
	    outtextxy(x,y+80,c5);
	    y2=4;}
    else if((c=='a'&&y2==4)||(c=='q'&&y2==1))
	  { rect(x,y+80,4);
	    outtextxy(x,y,c1);
	    outtextxy(x,y+20,c2);
	    outtextxy(x,y+40,c3);
	    outtextxy(x,y+60,c4);
	    setcolor(0);outtextxy(x,y+80,c5);setcolor(getmaxcolor());
	    y2=5;}
     else if((c=='a'&&y2==5)||(c=='q'&&y2==2))
	  { rect(x,y,4);
	    setcolor(0);outtextxy(x,y,c1);setcolor(getmaxcolor());
	    outtextxy(x,y+20,c2);
	    outtextxy(x,y+40,c3);
	    outtextxy(x,y+60,c4);
	   outtextxy(x,y+80,c5);
	    y2=1;}
}
      cleardevice();closegraph();
      if(c=='s'&&y2==1)
       {issue();
       }
      else if(c=='s'&&y2==2)
	{give();
	}
       else if(c=='s'&&y2==3)
       {see();
	}
      else if(c=='s'&&y2==4)
	{bookdetails();
	}
	else
	{initgraph(&gd,&gm,"c://turboc3//bgi");
	 x=getmaxx()/2;y=getmaxy()/2;
	 settextstyle(4,HORIZ_DIR,10);
	 setcolor(getmaxcolor());
	 outtextxy(x-100,y-200,"Thank");
	 outtextxy(x-50,y-100,"you");
	 settextstyle(5,HORIZ_DIR,3);
	 outtextxy(x-170,y+70,"We would like to thank our computer teacher");
	 outtextxy(x-120,y+120,"for giving us this wonderful project.");
	 sleep(3); closegraph();exit(0);
	}
	c='e';y2=0;initgraph(&gd,&gm,"c://turboc3//bgi");goto h;
 }
