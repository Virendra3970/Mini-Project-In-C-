// Question: 
/*Write a C++ program to design a base class Person (name,address,phone_no) Derive a class Employee(eno, ename) from Person. Derive a class Manager(designation, department name, basic-salary) from Employee. Write a menu driven program to:
 a. Accept all details of 'n' managers.
 b. Display manager having highest salary*/
 
// Author:- Virendra Kumar
 
#include<iostream>
#include<cstring>
using namespace std;
class Person		//person class
{
  protected:		//protected member can be only accessed by derived class 
   char name[20];
   char address[50];
   long long int mobile_No;
  public:
  
};

class Employee: public Person		//Employee derived class inheriates Person
{
  protected:				//protected member can be only accessed by derived class
   int eNo;
   char eName[20];
  public:
  
};

class Manager: public Employee		//Manager class consists of Person class member alongwith Employee
{
  private:
   char designation[20];
   char departName[20];
   int basicSalary;
  
  public:
   void details(Manager m[], int j, int i)		//details() function to take the detail of Employee
   {
     cout<<"\nEnter the Id: ";
     cin>>eNo;
     try						//exception handing for employee's Id
     {
       if(eNo<=0)					//an Id must be greater than 0 and lesser than total number of  employees
         throw 101;
       else if(m[i].eNo==m[i-1].eNo)			// an Id must not be same to other employee's Id 
         throw 102;
     }
     catch(int a)					//catch block
     {
       if(a==101)
       {
 	 cout<<"Please, Enter valid employee Id.\n It must be b/w 1 to "<<j<<"Error...."<<a<<endl<<endl; 
       }
       else
       {
         cout<<"Employee Id is same to previous one. Error..."<<a<<endl<<endl;
       }
       exit(0);
     }
     catch(...)						//this is used for Unexpected error
     {
       cout<<"Unexpected error"<<endl<<endl;
       exit(0);
     }	
     
     cout<<"\nEnter the name : ";			//input the name of employee
     cin.ignore();					//used to empty the Input Buffer
     fgets(eName, 20, stdin);
    							//Exception Handling for Employee's name
     for(int i=0; eName[i]!='\n'; i++)		
     {
       try				
       {
         if(eName[i]>='A' && eName[i]<='Z' || eName[i]>='a' && eName[i]<='z' || eName[i]==' ')	//if user enters other special symbol instead of Alphabates and space 
           continue;
         else
           throw 301;
       }
       catch(int a)
       {
         cout<<"Please, enter a valid Name. Error..."<<a<<endl<<endl;
         exit(0);
       }
       catch(...)
       {
         cout<<"Unexpected Error"<<endl<<endl;
         exit(0);
       }
     }
     
     cout<<"\nEnter the address: ";			//input address of employee
     //cin.ignore();
     fgets(address, 50, stdin);
     							//Exception handing for employee's address
     for(int i=0; i<strlen(address)-1; i++)
     {
       try				
       {
         if(address[i]>='A' && address[i]<='Z' || address[i]>='a' && address[i]<='z' || address[i]==' ' || address[i]>='0' && address[i]<='9')
         {
          continue;
         }
         else
           throw 301;
       }
       catch(int a)
       {
         cout<<"Please, enter a valid address. Error..."<<a<<endl<<endl;
         exit(0);
       }catch(...){ cout<<"Unexpected Error"<<endl<<endl; exit(0);}
     }
     
     cout<<"\nEnter the mobile number: ";    		//Input for mobile number 
     cin>>mobile_No;
     int count=0; long long int mob=mobile_No;
     //Exception handling for mobile number
     while(mob!=0)
     {
      
      mob=mob/10;
      count++;
     try			
     {
       if(count>0 || count<10)
 	continue;
       else
         throw 301;
     }
     catch(int a)
     {
       cout<<"\nPlease, Enter a valid Mobile Number. Error.."<<a<<endl<<endl;
       exit(0);
     }
     catch(...)
     { 
       cout<<"\nUnexpected Error"<<endl<<endl; 
       exit(0);}
     }
     
     cout<<"\nEnter the designation: ";			//Input statement for designation(post)
     cin.ignore();					//this is used to flush the input buffer
     fgets(designation, 20, stdin);
       							//Exception handing for designation
     for(int i=0; i<strlen(designation)-1; i++)
     {
       try				
       {
         if(designation[i]>='A' && designation[i]<='Z' || designation[i]>='a' && designation[i]<='z' || designation[i]==' ')
           continue;
         else
           throw 301;
       }
       catch(int a)
       {
         cout<<"Please, enter a valid designation. Error..."<<a<<endl<<endl;
         exit(0);
       }
       catch(...)
       {
         cout<<"Unexpected Error"<<endl<<endl;
          exit(0);
       }
     }
     
     cout<<"\nEnter the department name: ";		//Input statement for departName
     //cin.ignore(); cin.ignore();
     fgets(departName, 20, stdin);
     
     for(int i=0; i<strlen(departName)-1; i++)		//Exception handing for departName
     {
       try			
       {
         if(departName[i]>='A' && departName[i]<='Z' || departName[i]>='a' && departName[i]<='z' || departName[i]==' ')
         {
           continue;
         }
         else
           throw 301;
       }
       catch(int a)
       {
         cout<<"Please, enter a valid departname. Error..."<<a<<endl<<endl;
         exit(0);
       }catch(...){ cout<<"Unexpected Error"<<endl<<endl; exit(0);}
     }
     
     cout<<"\nEnter the basic salary: ";			//Input statement for basicSalary
     cin>>basicSalary;
    
     try					//Exception handing for basicSalary
     {
       if(basicSalary<0)
         throw 101;
     }
     catch(int a)
     {
      cout<<"Please, Enter valid basicSalary. Error...."<<a<<endl<<endl; 
      exit(0);
     }
     catch(...)
     { 
       cout<<"Unexpected error"<<endl;
       exit(0);
     }
   }						//end of details class
  
   void display(int i)				//display(int) for display the details of employees
   {
     cout<<"\neNo          : "<<eNo<<endl;
     cout<<"Name         : "<<eName;
     cout<<"Address      : "<<address;
     cout<<"Mobile No    : "<<mobile_No<<endl;
     cout<<"Department   : "<<departName;
     cout<<"Designation  : "<<designation;
     cout<<"Basic Salary : "<<basicSalary<<"$/-"<<endl;
   }
};

int main()
{
  int a;						//size of array
  cout<<"\nEnter, How many manager's details, Do you want? : ";
  cin>>a;
  Manager m[a]; 					//object array of Manager class
  for(int i=0; i<a; i++)
  {
    cout<<"\nEnter "<<i+1<<". employee's details: _ _ _ _ _ _ _"<<endl;   
    m[i].details(m,a,i);				//here details() invoked by Manager class object
  }
  
  for(int i=0; i<a; i++)
  {
    cout<<endl<<i+1<<". employee's details: _ _ _ _ _ _ _ _ _ _ _ _"<<endl;
    m[i].display(i+1);					//here display() is invoked by Manager class object
  }
  return 0;
}


