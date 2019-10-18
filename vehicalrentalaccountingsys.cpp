#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<fstream.h>
#include<string.h>
#include<ctype.h>
//Function Prototypes
void EnterVName(char []);
void DeleteVehicle (char []);
void DisplayAll(char []);
void SearchVId(char []);
void SearchVName(char []);
void tprofit (char []);
void tfare(char []);
void tcost(char []);
//Classes
class VEHICLE
{
int VId;
char VehicleName[20],EmpName[20];
float Dist;
public:
void Enter()
{
cout<<"Enter vehicle Id :";cin>>VId;//inputting vehilce id
cout<<"Enter vehicle name :";gets(VehicleName);
cout<<"Enter Driver name:";gets(EmpName);
cout<<"Distance travelled:";cin>>Dist;
}
int ReturnVId()
{
return VId;
}
char *VName()
{
return VehicleName;
}
int ifare()
Project: <Vehicle Rental Accounting System> Developed By <Dhairya Sethi, Dhruv Agrawal> Page:#6/14
{
if (Dist<=3)
return 100;
else
return 100 + (Dist-3)*25;
}
int icost()
{
return Dist * 20;
}
int iprofit()
{
return ifare()-icost();
}
void Display()
{
cout<<"Vehicle Id :"<<VId<<endl;
cout<<"Vehicle name :"<<VehicleName<<endl;
cout<<"Driver name :"<<EmpName<<endl;
cout<<"Distance travelled:"<<Dist<<endl;
cout<<"Fare :"<<ifare()<<endl;
cout<<"Cost incurred to company:"<<icost()<<endl;
cout<<"Profit:"<<iprofit()<<endl;
}
};
//Main Function
void main()
{
clrscr();
char file[20];
int choice,c;
cout<<"Enter file name: ";gets(file);
do
{
cout<<" Enter the function to be performed:"<<endl;
cout<<"1. Enter Vehicle"<<endl;
cout<<"2. Delete Vehicle"<<endl;
cout<<"3. Display all vehicles"<<endl;
cout<<"4. Search for vehicle"<<endl;
cout<<"5. Calculate total:"<<endl;
cout<<"6. Quit"<<endl;
cin>>choice;
switch(choice)
{
case 1:EnterVName(file);break;
case 2:DeleteVehicle(file);
remove(file);
rename("temp",file);
break;
case 3:DisplayAll(file);break;
case 4:cout<<"Search: 1. Vehicle name 2. Vehicle Id"<<endl;
cin>>c;
if(c==1)
SearchVName(file);
Project: <Vehicle Rental Accounting System> Developed By <Dhairya Sethi, Dhruv Agrawal> Page:#7/14
else if(c==2)
SearchVId(file);
else
cout<<"Error try again "<<endl; break;
case 5:cout<<"Total: 1. Fare 2. Cost 3. Profit"<<endl;
cin>>c;
if (c==1)
tcost(file);
else if (c==2)
tfare(file);
else if (c==3)
tprofit(file);
else
cout<<"Invalid Option"<<endl;
break;
case 6:cout<<"Thank you"<<endl; break;
default:cout<<"Invalid Option"<<endl;
}
}while (choice!=6);
}
//Function Definitions
void EnterVName(char file[])
{
fstream F;
F.open(file,ios::binary|ios::app);
char choice;
VEHICLE v;
do
{
v.Enter();
F.write((char*)&v,sizeof(v));
cout<<"Do you want to continue(Y/N) :";
cin>>choice;
}
while (toupper(choice)!='N');
F.close();
}
void DeleteVehicle(char file[])
{
int Id;VEHICLE v;
fstream F1,F2;
F1.open(file,ios::binary|ios::in);
F2.open("temp",ios::binary|ios::out);
cout<<"Enter vehicle Id to delete :";cin>>Id;
int del=0;
while(F1.read((char*)&v,sizeof(v)))
{
if(v.ReturnVId()!=Id)
F2.write((char*)&v,sizeof(v));
else
del++;
Project: <Vehicle Rental Accounting System> Developed By <Dhairya Sethi, Dhruv Agrawal> Page:#8/14
}
if (!del)
cout<<"Vehicle not found"<<endl;
else
cout<<"Vehicle deleted"<<endl;
F1.close();
F2.close();
}
void DisplayAll(char file[])
{
fstream F;VEHICLE v;
F.open(file,ios::binary|ios::in);
while(F.read((char*)&v,sizeof(v)))
{
v.Display();
}
F.close();
}
void SearchVId(char file[])
{
fstream F;VEHICLE v;
int Id,found=0;
F.open(file,ios::binary|ios::in);
cout<<"Enter Vehicle Id to be searched:";cin>>Id;
while(F.read((char*)&v,sizeof(v)))
{
if(v.ReturnVId()==Id)
{
v.Display();
found++;
}
}
if (found==0)
cout<<"Record not found"<<endl;
F.close();
}
void SearchVName(char file[])
{
fstream F;VEHICLE v;
int found=0;
char Name[20];
F.open(file,ios::binary|ios::in);
cout<<"Enter name of vehicle to be searched:";gets(Name);
while(F.read((char*)&v,sizeof(v)))
{
if (strcmpi(v.VName(),Name)== 0)
{
v.Display();
found++;
}
}
Project: <Vehicle Rental Accounting System> Developed By <Dhairya Sethi, Dhruv Agrawal> Page:#9/14
if (found==0)
cout<<"Record not found"<<endl;
F.close();
}
void tprofit(char file[])
{
fstream F;VEHICLE v;int netp=0;
F.open(file,ios::binary|ios::in);
while(F.read((char*)&v,sizeof(v)))
netp+=v.iprofit();
cout<<"Total Profit:"<<netp<<endl;
F.close();
}
void tfare(char file[])
{
fstream F;VEHICLE v;int netf=0;
F.open(file,ios::binary|ios::in);
while(F.read((char*)&v,sizeof(v)))
netf+=v.ifare();
cout<<"Total Fare:"<<netf<<endl;
F.close();
}
void tcost(char file[])
{
fstream F;VEHICLE v;int netc=0;
F.open(file,ios::binary|ios::in);
while(F.read((char*)&v,sizeof(v)))
netc+=v.icost();
cout<<"Total Cost:"<<netc<<endl;
F.close();
}
