#include <iostream>
#include <string>
#include <cstdlib>
#include <regex>
#include <sstream>
#include <fstream>
using namespace std;

// Defualt Credintials for login
// note you can change the Credintials to anything you want
#define USERNAME "admin"
#define PASSWORD 12345


// class declaration section

void fordelay(); // prototype for delay function

// Email Vaildation Pattern
bool Emailcheck(string email)
{
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(email, pattern);
}


// class declaration space

class student{

private:
  string Fname,Last_Name,enroled_course,address,email_id;
  int contact_no,roll_no;

public:
  void login();
  void menu();
  void getdata();
  void Display_data();
  void modify();
  void Delete_record();
  void search();
  void reset_password();
};

// Class impelmentation details 


void student::menu(){

  int usr_choice ; // vatiable that will contain the user choice from menu
  cout <<endl;
  cout <<"\t\t\t\t    ---------------------------\n";
  cout << "\t\t\t\t    |STUDENT MANAGEMENT SYSTEM|\n";
  cout << "\t\t\t\t    ---------------------------\n";
  cout << "\n\n\n";
  cout << "\t\t\t\t";
  cout<< " 1. Enter new Records\n\n";
  cout <<"\t\t\t\t";
  cout<<" 2. Modify Records\n\n";
  cout<<"\t\t\t\t";
  cout<<" 3. Delete Records\n\n";
  cout<<"\t\t\t\t";
  cout<<" 4. Search  Records\n\n";
  cout<<"\t\t\t\t";
  cout <<" 5. View Records\n\n";
  cout <<"\t\t\t\t";
  cout<<" 6. Exit\n\n";
  cout<<"\t\t\t\t";
  cout << "Choose options:[1/2/3/4/5/6]:";
  cin >> usr_choice;
  switch (usr_choice) {
    case 1:
    getdata();
    break;
    case 2:
   modify();
    break;
    case 3:
    Delete_record();
    break;
    case 4:
    search();
    break;
    case 5:
    Display_data();
    case 6:
    exit(1); // exit with status code
    break;

defualt:
cout <<"Invaild input"<<endl;

  }



}




void fordelay(int j)
{   int i,k;
    for(int i=0;i<j;i++)
         k=i;
}






void student::Delete_record()// delete student record
{
  system("cls");
  fstream file, file1;
  int found = 0;
  int roll;
  cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
  cout << "------------------------------------- Delete Student Details ------------------------------------------" << endl;
  file.open("studentRecord.txt", ios::in);
  if (!file)
  {
      cout << "\n\t\t\tNo Data is Present..";
      file.close();
  }
  else
  {
      cout << "\nEnter Roll No. of Student which you want Delete Data: ";
      cin >> roll;
      file1.open("record.txt", ios::app | ios::out);
      file >> Fname >>Last_Name >> roll_no >> enroled_course >> email_id >> contact_no >> address;
      while (!file.eof())
      {
          if (roll != roll_no)
          {
              file1 << " " << Fname  <<" "<<Last_Name << " " << roll_no << " " << enroled_course << " " << email_id << " " << contact_no << " " << address << "\n";
          }
          else
          {
              found++;
              cout << "\n\t\t\tSuccessfully Delete Data";
          }
          file >> Fname >> Last_Name >>  roll_no >> enroled_course >> email_id >> contact_no >> address;
      }
      if (found == 0)
      {
          cout << "\n\t\t\t Student Roll NO. Not Found....";
      }
      file1.close();
      file.close();
      remove("studentRecord.txt");
      rename("record.txt", "studentRecord.txt");
  }




}

void student::modify() // Modify details of student
{
    system("cls");
    fstream file, file1;
    int rollno;
    int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Modify Details ------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Roll No. of Student which you want to Modify: ";
        cin >> rollno;
        file1.open("record.txt", ios::app | ios::out);
        file >> Fname  >>Last_Name>> roll_no >> enroled_course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (rollno != roll_no)
                file1 << " " << Fname <<" "<<Last_Name<< " " << roll_no << " " << enroled_course << " " << email_id << " " << contact_no << " " << address << "\n";
            else
            {
                cout << "\n\t\t\tEnter Name: ";
                cin >> Fname;
                cout <<"\n\t\t\tEnter Last Name : ";
                cin>>Last_Name;
                cout << "\t\t\tEnter Roll No.: ";
                cin >> roll_no;
                cout << "\t\t\tEnter Course: ";
                cin >> enroled_course;
            email:
                cout << "\t\t\tEnter Email Id(name@gmail.com): ";
                cin >> email_id;
                if (Emailcheck(email_id))
                {
                    cout << "\t\t\t Your Email-Id is Valid" << endl;
                }
                else
                {
                    cout << "\t\t\t Your Email-Id is InValid" << endl;
                    goto email;
                }
            contact:
                cout << "\t\t\tEnter Contact No(9639xxxxxx): ";
                cin >> contact_no;
                if (contact_no < 1000000000 || contact_no > 9999999999)
                {
                    cout << "\t\t\t Please Enter Only 10 Digits..." << endl;
                    goto contact;
                }
                cout << "\t\t\tEnter Address: \t\t\t(Enter only the city you live in )"<<endl;
                fflush(stdin);
                cout<<"\t\t\t";
                file1 << " " << Fname <<" "<<Last_Name<< " " << roll_no << " " << enroled_course << " " << email_id << " " << contact_no << " " << address << "\n";
                found++;
            }
            file >> Fname >> Last_Name >> roll_no >> enroled_course >> email_id >> contact_no >> address;
        }
        if (found == 0)
        {
            cout << "\n\n\t\t\t Student Roll No. Not Found....";
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("record.txt", "studentRecord.txt");
    }
}



void student::search() // search on student
{

  system("cls");
  fstream file;
  int found = 0;
  file.open("studentRecord.txt", ios::in);
  if (!file)
  {
      cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
      cout << "------------------------------------- Student Search Data --------------------------------------------" << endl;
      cout << "\n\t\t\tNo Data is Present... " << endl;
  }
  else
  {
      int rollno;
      cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
      cout << "------------------------------------- Student Search Table --------------------------------------------" << endl;
      cout << "\nEnter Roll No. of Student which you want to search: ";
      cin >> rollno;
      file >> Fname >> Last_Name >> roll_no >> enroled_course >> email_id >> contact_no >> address;
      while (!file.eof())
      {
          if (rollno == roll_no)
          {
              cout << "\n\n\t\t\tName: " << Fname << "\n";
              cout << "\n\n\t\t\tLast Name: " << Last_Name << "\n";
              cout << "\t\t\tRoll No.: " << roll_no << "\n";
              cout << "\t\t\tCourse: " << enroled_course << "\n";
              cout << "\t\t\tEmail Id: " << email_id << "\n";
              cout << "\t\t\tContact No.: " << contact_no << "\n";
              cout << "\t\t\tAddress: " << address << "\n";
              found++;
          }
          file >> Fname >>Last_Name>> roll_no >> enroled_course >> email_id >> contact_no >> address;

      }
      if (found == 0)
      {
          cout << "\n\t\t\t Student Roll NO. Not Found....";

        }
      file.close();
  }
}





void student::getdata() // get data of student
{

  system("cls");
      fstream file;
      cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
      cout << "------------------------------------- Add Student Details ---------------------------------------------" << endl;
      cout <<endl;
      fflush(stdin);
        cout <<"\t\t\tEnter First Name : ";
        cin>>Fname ; // notice that name should not contain spaces otherwise the program will crash in displaying the data
          fflush(stdin);
          cout <<"\t\t\tEnter Last Name : ";
          cin>>Last_Name;
         cout << "\t\t\tEnter Roll No.: ";
           fflush(stdin);
         cin >> roll_no;
         cout << "\t\t\tEnter Course: ";
         cin >> enroled_course;
     email:
         cout << "\t\t\tEnter Email Id(name@gmail.com): ";
         cin >> email_id;
         if (Emailcheck(email_id))
         {
             cout << "\t\t\t Your Email-Id is Valid" << endl;
         }
         else
         {
             cout << "\t\t\t Your Email-Id is InValid" << endl;
             goto email;
         }
     contact:
         cout << "\t\t\tEnter Contact No(9639xxxxxx): ";
         cin >> contact_no;
         if (contact_no < 1000000000 || contact_no > 9999999999)
         {
             cout << "\t\t\t Please Enter Only 10 Digits..." << endl;
             goto contact;
         }
         cout << "\t\t\tEnter Address: \t\t\t(Enter only the city you live in )"<<endl;
         fflush(stdin);
         cout<<"\t\t\t";
         cin>>address; //notice that address should not contain spaces otherwise the program will crash in displaying the data
         file.open("studentRecord.txt", ios::app | ios::out);
        file << " " << Fname <<" "<<Last_Name<< " " << roll_no << " " << enroled_course << " " << email_id << " " << contact_no << " " << address << "\n";
         file.close();
         cout <<endl<<endl;
         cout <<"\t\t\t Data has been added successfully "<<endl;


}

void student::Display_data()//Display data of students
{
  system("cls");
  fstream file;
  int total = 1;
  cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
  cout << "------------------------------------- Student Record Table --------------------------------------------" << endl;
  file.open("studentRecord.txt", ios::in);
  if (!file)
  {
      cout << "\n\t\t\tNo Data is Present... ";
      file.close();
  }
  else
  {
      file >> Fname >>Last_Name >>  roll_no >> enroled_course >> email_id >> contact_no >> address;
      while (!file.eof())
      {
          cout << "\n\n\t\t\tStudent No.: " << total++ << endl;
          cout << "\t\t\tFirst Name: " << Fname << "\n";
          cout << "\t\t\tLast Name: " << Last_Name << "\n";
          cout << "\t\t\tRoll No.: " << roll_no << "\n";
          cout << "\t\t\tCourse: " << enroled_course << "\n";
          cout << "\t\t\tEmail Id: " << email_id << "\n";
          cout << "\t\t\tContact No.: " << contact_no << "\n";
          cout << "\t\t\tAddress: " << address << "\n";
          file >> Fname >> Last_Name>> roll_no >> enroled_course >> email_id >> contact_no >> address;
      }
      if (total == 0)
      {

          cout << "\n\t\t\tNo Data is Present..." << endl;
      }
  }
}







void student::login()// login function that will be executed at the begining of the porgram
{
int log_choice;
string enterd_usrname;
int enterd_pass;

cout <<"Enter Usernmae : ";
cin >>enterd_usrname;
cout <<"Enter Passwod  : ";
scanf("%d",&enterd_pass); // used scanf instead of cin to define that the enterd value is integer %d, Because when using cin error occurs when user enters string password instead of int

if (enterd_usrname ==USERNAME && enterd_pass==PASSWORD){

            cout << "\n\nPassword Match!\nLOADING";
          for(int i=0;i<=6;i++)
          {
              fordelay(100000000);
              cout << ".";
          }
                  system("cls");
                 menu();

  }
  else {

        cout << "\n\nWrong password or username !!  \a\a\a" <<endl;
        cout <<"Enter 1 to try again or 0 to exit : ";
        fflush(stdin);
        scanf("%d",&log_choice);

        if (log_choice ==1 ){
        system("cls");
          login();
        }

        else if (log_choice==0)
        exit (2); // exitng with status code 2
        else {
          cout <<"\nInvalid input exiting !..... "<<endl;
          exit (3);
        }

  }


}



int main(){

student a;  // creating object from class student
a.login();


  return 0;
}
