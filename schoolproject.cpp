#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;

//Structure defining

//For students
struct student
{
 string firstName;//for student first name
 string LastName;//for student last name
 string Address;//Student Address
 string classes;//for class info such as class number or letter
 string parents_name;//Student's parents name
 string parents_number; //Students parents number
 
}
 studentData;//Variable of student type

//For teachers
struct teacher
{
 string fist_name;//first name of teacher
 string last_name;//last name of teacher
 string qualification;//Qualification of teacher
 string experience;//Experiance of teacher
 string payment;//Payment of Teacher
 string subject;//subject he/she teachs
 string lecture;//Lecture
 string addrs;//teacher's address
 string cel_number;//Teacher's phone number 
 string serves;//Number of years serving in School

}teach[50];//Variable of teacher type

///////////////////////////////////////////////////
//Main function

int main()
{

int i=0,j;//for processing usage 
char choice;//for getting choice
string find;//for sorting
string srch;
char CreateUsername [7]; //creating user name to access the system
char CreatePassword [7]; //Password to login
string userName; //user name ID validation
string userPassword; //User input password
int loginAttempt = 0;

cout <<"-----> ";
cout <<" Please Create UserName and Password for ADMIN access: "<<endl;
cout <<" MAXIMUM OF 6 LETTERS AND NUMBERS, DO NOT USE SPECIAL CHARACTERS!";
cout <<"<-----\n";
cout <<"Create your username: ";
cin >> CreateUsername;
cout <<"Create your password: ";
cin >> CreatePassword;
 
while (loginAttempt < 3)
{ 
cout <<"----------------------------\n";
cout << "Please enter your username: ";
cin >> userName;
cout << "Please enter your password: ";
cin >> userPassword;

if (userName == CreateUsername && userPassword == CreatePassword)
{
cout << "Welcome! "<<CreateUsername<<endl;
break;
}
       
else
{
cout << "Invalid login attempt. Please try again.\n" << '\n';
loginAttempt++;
}
}
if (loginAttempt == 3)
{
cout << "Too many login attempts! Try again later.";
return 0;
}

cout << "Thank you for log in."<<endl;

while(1)
{ 

//Level 1-Display process 
 cout<<"----------------------------------------------------------------------------------------------------------------------";
 cout<<"\n\n\t\t\t----> SCHOOL INFORMATION SYSTEM <----\n\n";
 cout<<"----------------------------------------------------------------------------------------------------------------------";
 cout<<"\n\n\t\t\tMENU OPTIONS\n\n";
 cout<<"Enter your choice: "<<endl;
 cout<<"1.Student's information"<<endl;
 cout<<"2.Teacher's information"<<endl;
 cout<<"3.Exit program"<<endl;
 cin>>choice; 

system("cls");//Clear screen

switch(choice)//First switch
{
 
case '1': //Student
 { 
while(1)//inner loop-1
{ 
system("cls");//Clear screen
//Level-2 display
cout<<"\t\t\tSTUDENTS INFORMATION SECTION\n\n\n";
cout<<"Enter your choice: "<<endl;
cout<<"1.Insert New Student's data?\n";
cout<<"2.Find and display Student's data?\n";
cout<<"3.BACK TO MAIN MENU?\n";
cin>>choice;

switch (choice)//Second switch

{
case '1'://Insert data
{  ofstream f1("student.txt",ios::app);

for( i=0;choice!='n';i++)
{

if((choice=='y')||(choice=='Y')||(choice=='1'))
{
 cout<<"Enter First name: ";
 cin>>studentData.firstName;
 cout<<"Enter Last name: ";
 cin>>studentData.LastName;
 cout<<"Enter the Address: ";
 cin>>studentData.Address;
 cout<<"Enter class: ";
 cin>>studentData.classes;
 cout<<"Enter the parent's name: ";
 cin>>studentData.parents_name;
 cout<<"Enter the parent's number: ";
 cin>>studentData.parents_number;

 
 f1<<studentData.firstName<<endl<<studentData.LastName<<endl<<studentData.Address<<endl<<studentData.classes<<endl<<studentData.parents_name<<endl<<studentData.parents_number<<endl;
 cout<<"Do you want to enter new student's data? "<<endl;
 cout<<"Press Y for Continue and N to Finish: ";
 cin>>choice;
}

} 
f1.close();
}
continue;//control back to inner loop -1

case '2'://Display data
{  ifstream f2("student.txt"); 

cout<<"Enter the First name of the student to display data: ";
cin>>find;
cout<<endl;
int notFound = 0;
for( j=0;(j<i)||(!f2.eof());j++)
{ 

getline(f2,studentData.firstName);

if(studentData.firstName==find)
{
 notFound = 1;
 cout<<"First Name: "<<studentData.firstName<<endl;
 cout<<"Last Name: "<<studentData.LastName<<endl;

 getline(f2,studentData.Address);
 cout<<"Registration number: "<<studentData.Address<<endl;
 getline(f2,studentData.classes);
 cout<<"Class: "<<studentData.classes<<endl;
 getline(f2,studentData.parents_name);
 cout<<"Parent's Name: "<<studentData.parents_name<<endl;
 getline(f2,studentData.parents_number);
 cout<<"Parent's Number: "<<studentData.parents_number<<endl;
}

}

if(notFound == 0){

cout<<"No Record Found"<<endl;
}
f2.close();
cout<<"Press any key two times to proceed";
getch();//To hold data on screen
getch();//To hold data on screen

}
continue;//control back to inner loop -1

case '3'://Back to the main menu
{
break;//inner switch breaking
}
}

break;//inner loop-1 breaking
}
continue;//Control pass to 1st loop    
}

case '2'://Teachers biodata
{ 
while(1)//inner loop-2
{ 
system("cls");//Clear screen
//Level-2 Display process
cout<<"\t\t\tTEACHER'S INFORMATION\n\n\n";
cout<<"Enter your choice: "<<endl;
cout<<"1.Insert New teacher's data\n";
cout<<"2.Find and display the teacher's data\n";
cout<<"3.BACK TO MAIN MENU\n";
cin>>choice;

switch (choice)//Third switch
{
case '1'://Insert data
{ 
ofstream t1("teacher.txt",ios::app);

for(i=0;choice!='n'&& choice!='N';i++)
{
 
 if((choice=='y')||(choice=='Y')||(choice=='1'))
 {
  cout<<"Enter First name: ";
  cin>>teach[i].fist_name;
  cout<<"Enter Last name:: ";
  cin>>teach[i].last_name;
  cout<<"Enter qualification: ";
  cin>>teach[i].qualification;
  cout<<"Enter experiance(year): ";
  cin>>teach[i].experience;
  cout<<"Enter number of year in this School: ";
  cin>>teach[i].serves;
  cout<<"Enter the Subject of the teacher: ";
  cin>>teach[i].subject;
  cout<<"Enter Lecture(per Week): ";
  cin>>teach[i].lecture;
  cout<<"Enter annual salary: $ ";
  cin>>teach[i].payment;
  cout<<"Enter Phone Number: ";
  cin>>teach[i].cel_number;
  
  
  t1<<teach[i].fist_name<<endl<<teach[i].last_name<<endl 
  <<teach[i].qualification<<endl<<teach[i].experience<<endl
  <<teach[i].serves<<endl<<teach[i].subject<<endl<<teach[i].lecture
  <<endl<<teach[i].payment<<endl<<teach[i].cel_number<<endl;
  cout<<"Would you like to insert new teacher's data? "<<endl;
  cout<<"Press Y for Continue and N to Finish: ";
  cin>>choice;
 }//if
 
}//for loop
//for finding data through name 
system("cls");

t1.close();
}//case 1

continue;//Control pass to inner loop-2

case '2'://Display data
{ 
ifstream t2("teacher.txt"); 

cout<<"Enter name to be displayed: ";
cin>>find;

cout<<endl;
int notFound = 0;
for( j=0;((j<i)||(!t2.eof()));j++)
{ 
 
 getline(t2,teach[j].fist_name);
 
 if(teach[j].fist_name==find)
 {
  notFound = 1;
  cout<<"First name: "<<teach[j].fist_name<<endl;
  getline(t2,teach[j].last_name);
  cout<<"Last name: "<<teach[j].last_name<<endl;
  getline(t2,teach[j].qualification);
  cout<<"Qualification: "<<teach[j].qualification<<endl;
  getline(t2,teach[j].experience);
  cout<<"Experience: "<<teach[j].experience<<endl;

  getline(t2,teach[j].serves);
  cout<<" number of year in this School: "<<teach[j].serves<<endl;

  getline(t2,teach[j].subject);
  cout<<"Subject whos teach: "<<teach[j].subject<<endl;

  getline(t2,teach[j].lecture);
  cout<<"Enter Lecture(per Week): "<<teach[j].lecture<<endl;
  getline(t2,teach[j].payment);
  cout<<"pay: "<<teach[j].payment<<endl;

  getline(t2,teach[j].addrs);
  cout<<"Address: "<<teach[j].addrs<<endl;

  getline(t2,teach[j].cel_number);
  cout<<"Phone Number: "<<teach[j].cel_number<<endl;

 }//if
 
}//for loop
t2.close();
if(notFound == 0){

 cout<<"No Record Found"<<endl;
}
cout<<"Type any key two times to continue!";
getch();//To hold data on screen
getch();//To hold data on screen
}//case 2

continue;//Control pass to inner loop-2

case '3'://Back to the main menu
{
break;//inner switch
}//case 3

}//inner switch

break;//inner while
}//inner loop

continue;//control pass to 1st loop
}//outer case 2


case '3':
{
break;//outer case 3
}//outer case 3
}   
break;//outer looping
}
}
