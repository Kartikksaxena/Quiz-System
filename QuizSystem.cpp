#include<iostream>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<fstream>
using namespace std;
class Student
{
    public:
    // char name[20];
    string name;
    int roll_no;
    int marks;
}St;
void PrintQuestion(string Lang)
{
    
    bool arr[5]={false,false,false,false,false};
    cout<<"\n\t********** "<<Lang<<" Quiz **********\n\n"<<endl;

    for(int i=0;i<5;i++)
    {
        xyyy:
        //for random generate question
        int random = rand()%5;
        if(arr[random])
            goto xyyy;
        else 
            arr[random]=true;

        string line,file_name = "./"+Lang+"/" + to_string(random)+".txt";
        ifstream file;
        // cout<<file_name;
        file.open(file_name);

        cout<<i+1<<") ";
        int j=6;
        while(j--)
        {
            getline(file,line);  //store line in file_name
            cout<<line<<endl;
        }
        string choose;
        cin>>choose;
        string ans;
        file>>ans; //last line contain ans 
        // cout<<ans<<endl;
        file.close();
        if(choose==ans)
        {
            cout<<"your ans is correct ..\n\n";
            St.marks++;
        }
        else
        {
            cout<<"your ans is incorrect ..\n";
            cout<<"Correct ans is  "<<ans<<"\n\n";
        }
    }
    system("cls");

    cout<<"\n  ********** "<<Lang<<" Result **********\n\n"<<endl;
}
void Result()
{
    cout<<"\tStudent Name: "<<St.name<<endl;
    cout<<"\tStudent Roll No : "<<St.roll_no<<endl;
    cout<<"\tMarks: "<<St.marks<<" out of 5"<<endl;
    cout<<"\tPercentage: "<<100*St.marks/5<<endl;
    cout<<"\tStatus: ";
    if(St.marks>1)
        cout<<"Pass\n\n";
    else
        cout<<"Fail\n\n";
}
int main() {
    char press,Select_Lang;
    do{
        system("cls");
        cout<<"\n\n\n\n\n\n\t\t\t\t\t*******************************************************************\n";
        cout<<"\t\t\t\t\t\t\t\t\tQuiz System\n";
        cout<<"\t\t\t\t\t****************************************************************8**\n";
        cout<<"\n\t\t\t\t\tEnter Name: ";
        // gets(St.name);
        getline(cin,St.name);
        cout<<"\n\t\t\t\t\tEnter Roll_no: ";
        cin>>St.roll_no;
        system("cls");

        cout<<"\n\n\n\n\n\t\t\t\t\tMarks less than 50% will be fail \n\n";
        cout<<"\n\t\t\t\t\tSelect option which subject's quiz you want to perform \n";
        cout<<"\n\t\t\t\t\t1) C++\n";
        cout<<"\t\t\t\t\t2) Java\n\t\t\t\t\t3) Html\n\n\t\t\t\t\t";
        cin>>Select_Lang;
        system("cls");
        St.marks=0;
        switch(Select_Lang)
        {
            case '1':
                PrintQuestion("cpp");
                break;
            case '2':
                PrintQuestion("java");
                break;
            case '3':
                PrintQuestion("html");
                break;
            default:
                cout<<"Invalid Input ....\n";
                break;                
        }
        Result();

        cout<<"   press y to continue else press any key....\n";
        cin>>press;
        cin.ignore();
    }while(press=='y' || press=='Y');
    return 0;
}
