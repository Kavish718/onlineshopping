#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<fstream.h>
#include<stdlib.h>
#include<iomanip.h>
#include<dos.h>
class product{
 char cname[20],pno[10],email[20],plist[100][100],fb[200],add[200];
 int age,nop,rat,da,mo,ye;
 float cost[100],tc;
 public:
 product(){
  nop=0;
  tc=0;
  rat=0;
 }
 int retda(){
  return da;
 }
 int retm(){
  return mo;
 }
 int rety(){
  return ye;
 }
 void dispers(){
 //to display personal details
  cout<<"NAME OF CUSTOMER :"<<cname<<endl;
  cout<<"AGE OF CUSTOMER :"<<age<<endl;
  cout<<"ADDRESS OF CUSTOMER :"<<add<<endl;
  cout<<"PHONE NUMBER OF CUSTOMER :"<<pno<<endl;
 }
 void accept(){
  //to accept the details of the customer
  for(int i=0;i<25;i++)
   cout<<' ';
  cout<<"PLEASE ENTER YOUR DETAILS"<<endl;
  delay(800);
  cout<<"Enter your name :";
  for(int j=0;j<24;j++)
   cout<<' ';
  gets(cname);
  delay(800);
  cout<<"Enter your phone number :";
  for(int k=0;k<16;k++)
   cout<<' ';
  gets(pno);
  while(strlen(pno)!=10){
   delay(500);
   cout<<"Re enter a valid number :";
   gets(pno);
  }
  delay(800);
  cout<<"Enter your email :";
  for(int l=0;l<23;l++)
   cout<<' ';
  gets(email);
  delay(800);
  cout<<"Enter your age :";
  for(int m=0;m<25;m++)
   cout<<' ';
  cin>>age;
  delay(800);
  cout<<"Enter your address:";
  for(int g=0;g<22;g++)
   cout<<' ';
  gets(add);
  struct date(d);
  getdate(&d);
  da=(int)d.da_day;
  mo=(int)d.da_mon;
  ye=(int)d.da_year;
 }
 void display(){
  //to display the products purchased, their cost and the discount
  if(tc!=0){
  gotoxy(10,10);
  struct date(d);
  getdate(&d);
  for(int a=0;a<21;a++)
   cout<<' ';
  cout<<"THE 12A2 STORE"<<endl;
  cout<<endl<<"Date:";
  for(int m=0;m<30;m++)
   cout<<' ';
  cout<<(int)d.da_day<<'/'<<(int)d.da_mon<<'/'<<d.da_year<<endl;
  for(int b=0;b<15;b++)
   cout<<' ';
  cout<<"You have puchased the following products :"<<endl;
  for(b=0;b<15;b++)
   cout<<' ';
  cout<<setw(5)<<"Sno"<<'\t'<<setw(5)<<"Name"<<'\t'<<setw(5)<<"Cost (INR)"<<endl;

  for(int i=0;i<nop;i++){
  delay(1000);
  for(int b=0;b<15;b++)
   cout<<' ';
  cout<<setw(5)<<i+1<<'\t'<<setw(5)<<plist[i]<<'\t'<<setw(5)<<cost[i]<<endl;

  }

  for(b=0;b<15;b++)
   cout<<' ';
  cout<<"Total cost is INR:"<<tc<<endl;
  for(b=0;b<15;b++)
   cout<<' ';
  cout<<"Congrats. You have a discount of :";
  randomize();
  float disc=random(11)*5;
  cout<<disc<<"%";
  cout<<"\n";
  delay(800);
  for(b=0;b<15;b++)
   cout<<' ';
  cout<<"Therefore your new total is INR :";
  float x=tc*disc/100;
  float nc=tc-x;
  cout<<(long)nc<<endl;}
  cout<<endl;
  for( int b=0;b<12;b++)
   cout<<' ';
  cout<<"Thank you for shopping with us. Please visit us again";
 }
 void co(float c){
  //to calculate the total cost
  static int x=0;
  cost[x++]=c;
  tc+=c;
 }
 void prod(char* pn){
  //to store the names of products purchased
  static int y=0;
  strcpy(plist[y++],pn);
  nop++;
 }
 void feed(char s[],int p){
  //to accept the feedback of the customer
  static int t=1;
  rat=(rat+p)/t;
  strcpy(fb,s);
 }
};
class item{
 int scode,stock;
 float cost;
 char name[30],description[100];
 public:
 void accept(int s,int ss,float c,char str[20],char str1[200]){
  /*to store details of all products available
   extracted from the text files*/
  scode=s;
  stock=ss;
  strcpy(name,str);
  cost=c;
  strcpy(description,str1);
 }

 void upstock(){
  //to update the value of stock
  stock--;
 }
 int retscode(){
 //to return scode
  return scode;
 }
 int retstock(){
 //to return stock
  return stock;
 }
 char*retname(){
 //to return name
  return name;
 }
 char*retdesc(){
 //to return description
  return description;
 }
 float retcost(){
 //to return cost
  return cost;
 }
 void display(){
 //to display the products available
  cout<<scode<<' '<<name<<' '<<description<<' '<<"INR "<<cost<<endl;
 }
}ob1[50],ob2[50],ob3[50],ob4[50];
char retreply(){
//to return reply as y or n based on the input
 cout<<"Would you like to browse through other brands ? y/n:";
   char str;
   cin>>str;
   if(str=='y')
    return'y';
   else
    return'n';
}
void o_avail(product &ob,int ch,int ch1,int count){
//to display the products available in outfits based on the customers' interests
cout<<"please enter the range of price you are searching for :"<<endl;
cout<<"maximum value :";
float max,min;
cin>>max;
cout<<"minimum value :";
cin>>min;
randomize();
cout<<"here are our availabilities :";
cout<<"\n";
for(int i=0;i<count-1;i++){
delay(100);
int a=ob1[i].retscode();
a/=10;
int g=a%10;
a/=10;
int f=a%10;
if(g==ch1 && f==ch)
if((ob1[i].retcost()>=min && ob1[i].retcost()<=max) && ob1[i].retstock()!=0)
ob1[i].display();
}
}
void o_purchase(product &ob,char &rep,int count){
//to confirm the purchase from outfits
char z;
int sc;
cout<<"Do you want to purchase any of these ?enter y for yes and n for no :";
cin>>z;
if(z=='y'){
cout<<"choose your scode :";
cin>>sc;
cout<<"please confirm your purchase. enter yes or no :";
char a[10];
gets(a);
if(!strcmpi(a,"yes")){
   for(int i=0;i<count-1;i++)
   if(ob1[i].retscode()==sc){
    ob.co(ob1[i].retcost());
    ob.prod(ob1[i].retname());

  }
  rep=retreply();

 }

 else{
  rep=retreply();
 }
 }
 else
  rep=retreply();
}
void plist_outfits(){
//to display the sections available in outfits
cout<<"LOADING...";
delay(800);
for(int i=0;i<10;i++)
 cout<<'\b';
cout<<"please choose among one of the following options :"<<'\n';
delay(800);
cout<<"1.shirts and tshirts(men)";
cout<<'\n';
delay(800);
cout<<"2.pants and jeans(men)";
cout<<'\n';
delay(800);
cout<<"3.kurthis";
cout<<'\n';
delay(800);
cout<<"4.sarees";
cout<<'\n';
delay(800);
cout<<"5 return back";
cout<<"\n";
}
void brand_men1(){
//to display the brands in shirts and tshirts
cout<<"LOADING...";
delay(800);
for(int i=0;i<10;i++)
 cout<<'\b';
cout<<"which brand would you like ?";
cout<<"\n";
delay(800);
cout<<"1 for ucb";
cout<<"\n";
delay(800);
cout<<"2 for us polo";
cout<<"\n";
delay(800);
cout<<"3 return back";
cout<<"\n";
}
void brand_men2(){
//to display the brands in pants and jeans
cout<<"LOADING...";
for(int i=0;i<10;i++)
 cout<<'\b';
delay(800);
cout<<"which brand would you like ?";
cout<<"\n";
delay(800);
cout<<"1 for levis";
cout<<"\n";
delay(800);
cout<<"2 for being human";
cout<<"\n";
delay(800);
cout<<"3 return back";
cout<<"\n";
}
void brand_kurthis(){
//to display the brands in kurthis
cout<<"LOADING...";
delay(800);
for(int i=0;i<10;i++)
 cout<<'\b';
cout<<"which brand would you like ?";
cout<<"\n";
delay(800);
cout<<"1 for co-optex";
cout<<"\n";
delay(800);
cout<<"2 for pothys";
cout<<"\n";
delay(800);
cout<<"3 return back";
cout<<"\n";
}
void brand_sarees(){
//to display the brands in sarees
cout<<"LOADING...";
delay(800);
for(int i=0;i<10;i++)
 cout<<'\b';
cout<<"which brand would you like ?";
cout<<"\n";
delay(800);
cout<<"1 for sm silks";
cout<<"\n";
delay(800);
cout<<"2 for fabindia";
cout<<"\n";
delay(800);
cout<<"3 return back";
cout<<"\n";
}
void outfits(product &ob){
// to explore outfits
int count=0;
ifstream f1("outfits.txt");
while(!f1.eof()){
int x,y;
float z;
char str1[30],str[100];
f1>>x>>str1>>y>>z;
f1.getline(str,50,'\n');
ob1[count++].accept(x,y,z,str1,str);
}
f1.close();
cout<<"welcome to outfits department";
cout<<"\n";
char r='y';
while(r=='y'){
plist_outfits();
int ch;
char rep='y',rep1='y',rep2='y',rep3='y';
cin>>ch;
if(ch==1)
while(rep=='y'){
brand_men1();
int ch1;
cin>>ch1;
if(ch1==3)
break;
for(;(ch1!=1 && ch1!=2 && ch1!=3);){
cout<<"please re enter a valid option :";
cin>>ch1;
}
o_avail(ob,ch,ch1,count);
o_purchase(ob,rep,count);}
else if(ch==2)
while(rep1=='y'){
brand_men2();
int ch1;
cin>>ch1;
if(ch1==3)
break;
for(;(ch1!=1 && ch1!=2 && ch1!=3);){
cout<<"please re enter a valid option :";
cin>>ch1;
}
o_avail(ob,ch,ch1,count);
o_purchase(ob,rep1,count);
}
else if(ch==3)
while(rep2=='y'){
brand_kurthis();
int ch1;
cin>>ch1;
if(ch1==3)
break;
for(;(ch1!=1 && ch1!=2 && ch1!=3);){
cout<<"please re enter a valid option :";
cin>>ch1;
}
o_avail(ob,ch,ch1,count);
o_purchase(ob,rep2,count);
}
else if(ch==4)
while(rep3=='y'){
brand_sarees();
int ch1;
cin>>ch1;
if(ch1==3)
break;
for(;(ch1!=1 && ch1!=2 && ch1!=3);){
cout<<"please re enter a valid option :";
cin>>ch1;
}
o_avail(ob,ch,ch1,count);
o_purchase(ob,rep3,count);
}
else if(ch==5)
return;
else{
while(!(ch>=1 && ch<=5)){
cout<<"re enter a valid option :";
cin>>ch;
}
}
cout<<"Do you want to browse through outfits further ?. enter yes or no:";
char str2[10];
gets(str2);
if(!strcmpi(str2,"yes"))
r='y';
else
r='n';
}
return;
}

void plist_spacc(){
 //to display the sections available in sports
 cout<<"LOADING...";
 delay(800);
for(int i=0;i<10;i++)
 cout<<'\b';
cout<<"please choose among one of the folowing options :"<<'\n';
 delay(800);
 cout<<"1.Cricket Kit";
 cout<<"\n";
 delay(800);
cout<<"2.Badmiton Kit";
 cout<<"\n";
delay(800);
 cout<<"3.Football";
 cout<<"\n";
delay(800);
 cout<<"4.Cycling";
 cout<<"\n";
delay(800);
 cout<<"5 Return back";
 cout<<"\n";
}
void brand_cric(){
//to display the brands in cricket
 cout<<"LOADING...";
delay(800);
for(int i=0;i<10;i++)
 cout<<'\b';
 cout<<"which brand would you like ?";
  cout<<"\n";
delay(800);
  cout<<"1 for SG FULL CRICKET KIT ";
  cout<<"\n";
delay(800);
  cout<<"2 for KLAPP CHAMPION CRICKET KIT ";
  cout<<"\n";
delay(800);
  cout<<"3 for SPARTAN CRICKET KIT ";
  cout<<"\n";
delay(800);
  cout<<"4 Return back";
  cout<<"\n";
}
void brand_bad(){

//to display the brands in badminton
cout<<"LOADING...";
delay(800);
for(int i=0;i<10;i++)
 cout<<'\b';
 cout<<"which brand would you like ?";
  cout<<"\n";
delay(800);
  cout<<"1 for YONEX ";
  cout<<"\n";
  delay(800);
cout<<"2 for LI-NING";
  cout<<"\n";
delay(800);
  cout<<"3 for ASHAWAY";
  cout<<"\n";
delay(800);
  cout<<"4 Return back";
  cout<<"\n";
}
void brand_fb(){
//to display the brands in football
cout<<"LOADING...";
delay(800);
for(int i=0;i<10;i++)
 cout<<'\b';
cout<<"which brand would you like ?";
  cout<<"\n";
delay(800);
  cout<<"1 for ADIDAS";
  cout<<"\n";
delay(800);
  cout<<"2 for NIKE ";
  cout<<"\n";
delay(800);
  cout<<"3 for MITRE ";
  cout<<"\n";
delay(800);
  cout<<"4 Return back";
  cout<<"\n";
}
void brand_cyc(){
//to display the brands in cycling
cout<<"LOADING...";
delay(800);
for(int i=0;i<10;i++)
 cout<<'\b';
cout<<"which brand would you like ?";
  cout<<"\n";
delay(800);
  cout<<"1 for BSA";
  cout<<"\n";
delay(800);
  cout<<"2 for LADYBIRD ";
  cout<<"\n";
delay(800);
  cout<<"3 for AVON ";
  cout<<"\n";
delay(800);
  cout<<"4 Return back";
  cout<<"\n";
}

void sp_avail(product&ob,int ch,int ch1,int count){
  //to display the products available from sports  based on the customers' interests
  cout<<"please enter the range of price you are searching for :"<<endl;
  cout<<"maximum value :";
  float max,min;
  cin>>max;
  cout<<"minimum value :";
  cin>>min;
  randomize();
  cout<<"here are our availabilities :";
  cout<<"\n";
  for(int i=0;i<count-1;i++){
  delay(100);
  int a=ob2[i].retscode();
  a/=10;
  int g=a%10;
  a/=10;
  int f=a%10;
  if(g==ch1 && f==ch)
  if((ob2[i].retcost()>=min && ob2[i].retcost()<=max)&& ob2[i].retstock()!=0)
   ob2[i].display();
  }
}
void sp_purchase(product&ob,char&rep,int count){
 //to confirm the purchase from sports 
 char z;
  int sc;
  cout<<"Do you want to purchase any of these ?enter y for yes and n for no:";
  cin>>z;
  if(z=='y'){
  cout<<"choose your scode :";
  cin>>sc;
  cout<<"please confirm your purchase. enter yes or no :";
  char a[10];
  gets(a);
  if(!strcmpi(a,"yes")){
   for(int i=0;i<count-1;i++)
    if(ob2[i].retscode()==sc){
     ob.co(ob2[i].retcost());
     ob.prod(ob2[i].retname());

  }
  rep=retreply();

 }

 else{
  rep=retreply();
 }
 }
 else
  rep=retreply();
}
void spacc(product &ob){
// to explore sports department
 int count=0;
 ifstream f("spacc.txt");
 while(!f.eof()){
  int x,y;
  float z;
  char str1[5],str[200];
  f>>x>>str1>>y>>z;
  f.getline(str,50,'\n');
  ob2[count++].accept(x,y,z,str1,str);
 }
 f.close();
 cout<<"Welcome to the sports department  :) ";
 cout<<"\n";
 char r='y';
 while(r=='y'){
 plist_spacc();
 int ch;
 char rep='y',rep1='y',rep2='y';
 cin>>ch;
 if(ch==1)
  while(rep=='y'){
  brand_cric();
  int ch1;
  cin>>ch1;
  if(ch1==5)
  break;
  for(;(ch1!=1 && ch1!=2 && ch1!=3 &&ch1!=4 &&ch1!=5);){
   cout<<"please re enter a valid option :";
   cin>>ch1;
  }
  sp_avail(ob,ch,ch1,count);
  sp_purchase(ob,rep,count);}
 else if(ch==2)
  while(rep1=='y'){
  brand_bad();
  int ch1;
  cin>>ch1;
  if(ch1==4)
  break;
  for(;(ch1!=1 && ch1!=2&& ch1!=3 && ch1!=4);){
   cout<<"re enter a valid number ";
   cin>>ch1;
  }
  sp_avail(ob,ch,ch1,count);
  sp_purchase(ob,rep1,count);
 }
 else if(ch==3)
  while(rep2=='y'){
  brand_fb();
  int ch1;
  cin>>ch1;
  if(ch1==4)
  break;
  for(;(ch1!=1 && ch1!=2 && ch1!=3 && ch1!=4);){
   cout<<"Please re enter an appropriate option :";
   cin>>ch1;
  }
  sp_avail(ob,ch,ch1,count);
  sp_purchase(ob,rep2,count);
 }
else if(ch==4)
  while(rep2=='y'){
  brand_cyc();
  int ch1;
  cin>>ch1;
  if(ch1==4)
  break;
  for(;(ch1!=1 && ch1!=2 && ch1!=3 && ch1!=4);){
   cout<<"please re enter an appropriate option :";
   cin>>ch1;
  }
  sp_avail(ob,ch,ch1,count);
  sp_purchase(ob,rep2,count);
 }
 else if(ch==5)
  return;
 else{
  while(!( ch>=1 && ch<=5))  {
   cout<<"re enter a valid option :";
   cin>>ch;
 }
 }
 cout<<" Do you want to browse through sports accesories further ?. Enter yes or no:";
 char str2[10];
 gets(str2);
 if(!strcmpi(str2,"yes"))
  r='y';
 else
  r='n';
 }
 return;
}
void plist_elec()
{
 //to display the sections available in electronics
     cout<<"LOADING...";
    delay(800);
for(int i=0;i<10;i++)
 cout<<'\b';
 cout<<"You have the following options to choose from:"<<endl;
delay(800);
     cout<<"1:MOBILES"<<endl;
delay(800);
     cout<<"2:TELEVISIONS"<<endl;
     delay(800);
cout<<"3:LAPTOPS"<<endl;
delay(800);
     cout<<"4:Return Back"<<endl;
      }
void brand_mob()
    {
//to display the brands in mobiles
     cout<<"LOADING...";
delay(800);
for(int i=0;i<10;i++)
 cout<<'\b';
     cout<<"Which brand would you like?"<<endl;
delay(800);
     cout<<"1:APPLE"<<endl;
delay(800);
     cout<<"2:MI"<<endl;
delay(800);
     cout<<"3:ONEPLUS"<<endl;
delay(800);
     cout<<"4:SAMSUNG"<<endl;
delay(800);
     cout<<"5:Return Back"<<endl;
    }
void brand_tv()
    {
//to display the brands in tv
     cout<<"LOADING...";
delay(800);
for(int i=0;i<10;i++)
 cout<<'\b';
     cout<<"Which brand would you like?"<<endl;
delay(800);
     cout<<"1:LG"<<endl;
delay(800);
     cout<<"2:SAMSUNG"<<endl;
delay(800);
     cout<<"3:SONY"<<endl;
     delay(800);
cout<<"4:Return Back"<<endl;
    }
void brand_lptp()
    {
//to display the brands in laptops
     cout<<"LOADING...";
delay(800);
for(int i=0;i<10;i++)
 cout<<'\b';
     cout<<"Which brand would you like?"<<endl;
delay(800);
     cout<<"1:APPLE"<<endl;
delay(800);
     cout<<"2:LENOVO"<<endl;
delay(800);
     cout<<"3:MICROSOFT"<<endl;
delay(800);
     cout<<"4:Return Back"<<endl;
    }
void eavail(product&ob,int ch,int ch1,int count)
	  {
           //to display the products available in electronics based on the customers' interests
	   cout<<"Please enter the range of price you are searching for:"<<endl;
	   cout<<"Maximum value:";
	   float max,min;
	   cin>>max;
	   cout<<"Minimum value:";
	   cin>>min;
	   cout<<"Here are our avalabilities:";
	   cout<<"\n";
	   for(int i=0;i<count-1;i++)
	      {
	       delay(100);
	       int a=ob3[i].retscode();
	       a/=10;
	       int g=a%10;
	       a/=10;
	       int f=a%10;
	       if(g==ch1 && f==ch)
		 if(ob3[i].retcost()>=min && ob3[i].retcost()<=max)
		   ob3[i].display();
	      }
	  }
void epurchase(product&ob5,char&rep,int count)
	     {
              //to confirm the purchase from electronics
	      char z;
	      int sc;
	      cout<<"Do you want to purchse any of these? enter y for yes and n for no";
	      cin>>z;
	      if(z=='y')
		{
		 cout<<"Choose your scode:";
		 cin>>sc;
		 cout<<"Please confirm your purchase.enter yes or no:";
		 char a[10];
		 gets(a);
		 if(!(strcmpi(a,"yes")));
		   {
		    for(int i=0;i<count-1;i++)
		    {
		       if(ob3[i].retscode()==sc)
			 {
			  ob5.co(ob3[i].retcost());
			  ob5.prod(ob3[i].retname());
			 }
		    }
		       rep=retreply();
		    } }
		else
		 rep=retreply();


	     }
void elec(product &ob)
{
//to explore electronics
 int count=0;
 ifstream e("electron.txt");
  while(!e.eof())
  {
   int x,y;
   float z;
   char str1[5],str[200];
   e>>x>>str1>>y>>z;
   e.getline(str,150,'\n');
   ob3[count++].accept(x,y,z,str1,str);
  }
  e.close();
  cout<<"Welcome to the ELECTRONIC department!"<<endl;
  char r='y';
  while(r=='y')
   {
    plist_elec();
    int ch;
    char rep='y',rep1='y',rep2='y';
    cin>>ch;
	if(ch==1)
	  while(rep=='y')
	    {
	brand_mob();
	int ch1;
	cin>>ch1;
	if(ch1==5)
	  break;
	for( ;(ch1!=1&&ch1!=2&&ch1!=3&&ch1!=4&&ch1!=5);)
	   {
	    cout<<"Please re enter a valid option:";
	    cin>>ch1;
	   }
	eavail(ob,ch,ch1,count);
	epurchase(ob,rep,count);
       }
	else if(ch==2)
       while(rep1=='y')
	    {
	     brand_tv();
	     int ch1;
	     cin>>ch1;
	     if(ch1==4)
	       break;
	     for( ;(ch1!=1&&ch1!=2&&ch1!=3&&ch1!=4);)
		{
		 cout<<"Please re enter a valid opstion:";
		 cin>>ch1;
		}
	     eavail(ob,ch,ch1,count);
	     epurchase(ob,rep1,count);
	    }
	  else if(ch==3)
	      while(rep2=='y')
	    {
	     int ch1;
	     brand_lptp();
	     cin>>ch1;
	     if(ch1==4)
	       break;
	     for( ;(ch1!=1&&ch1!=2&&ch1!=3&&ch1!=4);)
		{
		 cout<<"please re enter a valid option:";
		 cin>>ch1;
		}
	     eavail(ob,ch,ch1,count);
	     epurchase(ob,rep2,count);
	    }
	else if(ch==4)
	      return;
	else
	   {
	    while(!(ch>=1 && ch<=4))
	  {
	   cout<<"Re enter a valid option:";
	   cin>>ch;
	  }
	   }
	cout<<"Do you want to browse through electronics further?.enter yes or no";
	char str2[10];
	gets(str2);
	if(!(strcmpi(str2,"yes")))
	  r='y';
	else
	  r='n';
	      }
	 return;
     }
void plist_acc(){
//to display the sections available in  accesories
 cout<<"LOADING...";
delay(800);
for(int i=0;i<10;i++)
 cout<<'\b';
 cout<<"please choose among one of the folowing options :"<<'\n';
delay(800);
 cout<<"1.watches";
 cout<<"\n";
delay(800);
 cout<<"2.caps";
 cout<<"\n";
delay(800);
 cout<<"3.sunglasses";
 cout<<"\n";
delay(800);
 cout<<"4 Return back";
 cout<<"\n";
}
void brand_watch(){
//to display the brands in watches
cout<<"LOADING...";
delay(800);
for(int i=0;i<10;i++)
 cout<<'\b';
cout<<"which brand would you like ?";
  cout<<"\n";
delay(800);
  cout<<"1 for fasttrack ";
  cout<<"\n";
delay(800);
  cout<<"2 for sonata ";
  cout<<"\n";
delay(800);
  cout<<"3 for rolex ";
  cout<<"\n";
delay(800);
  cout<<"4 Return back";
  cout<<"\n";
}
void brand_cap(){
//to display the brands in caps
  cout<<"LOADING...";
delay(800);
for(int i=0;i<10;i++)
 cout<<'\b';
 cout<<"which brand would you like ?";
  cout<<"\n";
delay(800);
  cout<<"1 for nike ";
  cout<<"\n";
delay(800);
  cout<<"2 for puma";
  cout<<"\n";
delay(800);
  cout<<"3 Return back";
  cout<<"\n";
}
void brand_glass(){
//to display the brands in sunglasses
cout<<"LOADING...";
delay(800);
for(int i=0;i<10;i++)
 cout<<'\b';
cout<<"which brand would you like ?";
  cout<<"\n";
delay(800);
  cout<<"1 for EDITH";
  cout<<"\n";
delay(800);
  cout<<"2 for fasttrack ";
  cout<<"\n";
delay(800);
  cout<<"3 for Ray Bann ";
  cout<<"\n";
delay(800);
  cout<<"4 Return back";
  cout<<"\n";
}
void avail(product&ob,int ch,int ch1,int count){
  //to display the products available in accesories based on the customers' interests
  cout<<"please enter the range of price you are searching for :"<<endl;
  cout<<"maximum value :";
  float max,min;
  cin>>max;
  cout<<"minimum value :";
  cin>>min;
  randomize();
  cout<<"here are our availabilities :";
  cout<<"\n";
  for(int i=0;i<count-1;i++){
  delay(100);
  int a=ob4[i].retscode();
  a/=10;
  int g=a%10;
  a/=10;
  int f=a%10;
  if(g==ch1 && f==ch)
  if((ob4[i].retcost()>=min && ob4[i].retcost()<=max)&& ob4[i].retstock()!=0)
   ob4[i].display();
  }
}
void purchase(product&ob,char&rep,int count){ 
  //to confirm the purchase from sports accesories
  char z;
  int sc;
  cout<<"Do you want to purchase any of these ?enter y for yes and n for no:";
  cin>>z;
  if(z=='y'){
  cout<<"choose your scode :";
  cin>>sc;
  cout<<"please confirm your purchase. enter yes or no :";
  char a[10];
  gets(a);
  if(!strcmpi(a,"yes")){
   for(int i=0;i<count-1;i++)
    if(ob4[i].retscode()==sc){
     ob.co(ob4[i].retcost());
     ob.prod(ob4[i].retname());

  }
  rep=retreply();

 }

 else{
  rep=retreply();
 }
 }
 else
  rep=retreply();
}
void acc(product &ob){
//to explore accesories 
 int count=0;
 ifstream f4("acc.txt");
 while(!f4.eof()){
  int x,y;
  float z;
  char str1[5],str[200];
  f4>>x>>str1>>y>>z;
  f4.getline(str,50,'\n');
  ob4[count++].accept(x,y,z,str1,str);
 }
 f4.close();
 cout<<"welcome to the accesories department ";
 cout<<"\n";
 char r='y';
 while(r=='y'){
 plist_acc();
 int ch;
 char rep='y',rep1='y',rep2='y';
 cin>>ch;
 if(ch==1)
  while(rep=='y'){
  brand_watch();
  int ch1;
  cin>>ch1;
  if(ch1==4)
  break;
  for(;(ch1!=1 && ch1!=2 && ch1!=3 &&ch1!=4);){
   cout<<"please re enter a valid option :";
   cin>>ch1;
  }
  avail(ob,ch,ch1,count);
 purchase(ob,rep,count);}
 else if(ch==2)
  while(rep1=='y'){
  brand_cap();
  int ch1;
  cin>>ch1;
  if(ch1==3)
  break;
  for(;(ch1!=1 && ch1!=2&& ch1!=3);){
   cout<<"re enter a valid number ";
   cin>>ch1;
  }
  avail(ob,ch,ch1,count);
 purchase(ob,rep1,count);
 }
 else if(ch==3)
  while(rep2=='y'){
  int ch1;
  cin>>ch1;
  if(ch1==4)
  break;
  for(;(ch1!=1 && ch1!=2 && ch1!=3 && ch1!=4);){
   cout<<"please re enter an appropriate option :";
   cin>>ch1;
  }
  avail(ob,ch,ch1,count);
 purchase(ob,rep2,count);
 }
 else if(ch==4)
  return;
 else{
  while(!( ch>=1 && ch<=4))  {
   cout<<"re enter a valid option :";
   cin>>ch;
 }
 }
 cout<<" Do you want to browse through accesories further ?. enter yes or no:";
 char str2[10];
 gets(str2);
 if(!strcmpi(str2,"yes"))
  r='y';
 else
  r='n';
 }
 return;
}
void feedback(product ob){
//the feedback counter
 cout<<"LOADING...";
 delay(800);
for(int i=0;i<10;i++)
 cout<<'\b';
 cout<<"Welcome to the feedback section.Would you like to rate us? :";
 char rep,str[100];
 int x;
 cin>>rep;

 if(rep=='y'){
 cout<<"Please enter a rating from 1 to 10 :";
  cin>>x;
 if(x>=7)
  cout<<"Thank you for your positive feedback. We are happy that you are satisfied "<<endl;
 else
  cout<<"Sorry for disappointing you. We will make it up the next time";

 }
 cout<<"please enter your feeedback :";
 gets(str);
 cout<<"Thank you for sharing your experience. We look forward to improve our service ."<<endl;
 ob.feed(str,x);
}
void lp(){
 char str[]="$$$ WELCOME TO 12A2 STORE $$$";
 for(int i=0;i<11;i++)
  cout<<endl;
 for(int k=0;k<25;k++)
  cout<<' ';
 for(int j=0;str[j];j++){
  cout<<str[j];
  delay(200);
 }
 cout<<endl<<endl;
 for(j=0;j<34;j++)
  cout<<' ';
 char str1[]="LOADING";
 for(i=0;str1[i];i++){
  cout<<str1[i];
  delay(200);
 }
  for( j=0;j<3;j++){
   cout<<'.'<<' ';
   delay(200);
  }

clrscr();
}
void admin(){
 clrscr();
 product x;
 char pass[]="c++shop";
 for(int j=0;j<25;j++)
  cout<<' ';
 cout<<"ADMIN ACCESS"<<endl;
 cout<<"ENTER PASSWORD :";
 char str[20];
 gets(str);
 while(strcmpi(pass,str)){
  cout<<"1.RE ENTER THE VALID PASSWORD:"<<endl;
  cout<<"2.RETURN TO MAIN MENU:"<<endl<<"enter your choice:";
  int ch;
  cin>>ch;
  if(ch==1){
   cout<<"ENTER THE PASSWORD:";
   gets(str);
  }
  else if(ch==2)
   return;
  else
   while(!(ch==1 || ch==2)){
    cout<<"re enter a valid option:";
    cin>>ch;
   }
  }
 l:
 {int da,mo,ye;
 ifstream f("customer.dat",ios::binary);
 int d,m,y;
 cout<<"enter the date to display the purchases (dd mm yyyy):"<<endl;
 cout<<"date :";
 cin>>d;
 cout<<"month:";
 cin>>m;
 cout<<"year:";
 cin>>y;
 while(f.read((char*)&x,sizeof(x))){
  da=x.retda();mo=x.retm();ye=x.rety();
  if(d==da && m==mo && y==ye){
   x.dispers();
   x.display();
   delay(800);
   clrscr();
  }
 }}
 cout<<"1.check records for another date "<<endl;
 cout<<"2.return"<<endl;
 cout<<"enter your choice :";
 int ch1;
 cin>>ch1;
 if(ch1==1)
  goto l;
 else if(ch1==2)
  return;
 else
  while(!(ch1==1 || ch1==2)){
   cout<<"re enter a valid option:";
   cin>>ch1;
  }
}
void main(){
 clrscr();
 lp();
 for(int i=0;i<26;i++)
  cout<<' ';
 cout<<"WELCOME TO THE 12A2 STORE"<<endl;
  product ob;
  char x='y';
  ob.accept();
  cout<<"We offer you the following categories. Please choose from one of the options :";
  cout<<"\n";
  while(x=='y')
  {
   cout<<"1.Outfits ";
   cout<<"\n";
   delay(500);
   cout<<"2.Sports Accesories ";
   cout<<"\n";
   delay(500);
   cout<<"3.Electronics ";
   cout<<"\n";
   delay(500);
   cout<<"4.Accesories ";
   cout<<"\n";
   delay(500);
   cout<<"5.Feedback ";
   cout<<"\n";
   delay(500);
   cout<<"6.Admin access ";
   cout<<'\n';
   delay(500);
   cout<<"7.Quit"<<'\n';
   cout<<"please choose your option :";
   int ch;
   cin>>ch;
   while(!(ch>=1 && ch<=7)){
    cout<<"please re enter a valid option :";
    cin>>ch;
   }
   switch(ch){
    case 1:
	   delay(800);
	   outfits(ob);
	   break;
    case 2:
	   delay(800);
	   spacc(ob);
	   break;
    case 3:
	   delay(800);
	   elec(ob);
	   break;
    case 4:
	   delay(800);
	   acc(ob);
	   break;
    case 5:
	   delay(800);
	   feedback(ob);
	   break;
    case 6:
	   delay(800);
	   admin();
	   break;
    case 7:exit(0);
   }
   cout<<"Do you want to continue with the next purchase ? Enter y for yes and n for no:";
   cin>>x;
  }
  clrscr();
  ob.display();
 ofstream fout("customer.dat",ios::binary|ios::app);
 fout.write((char*)&ob,sizeof(ob));
 fout.close();
 getch();
}

