/*28. Write a class for your Grade card. The grade card is given to each student of a department per semester. The 
grade card typically contains the name of the department, name of the student, roll number, semester, a list of 
subjects with their marks and a calculated CGPA. Create 60 such grade cards in a 3rd semester with relevant data 
and find the name and roll number of student having highest CGPA.*/
#include<iostream>
#include<string.h>
using namespace std;
struct subject
{
    char name[20];
    float marks;
};
class grade_card
{
    char dept[20], name[20],roll[12];
    int sem;
    subject sub[3];
    float cgpa;
    public :
        friend void max_cgp(grade_card*, int);
        void getdata();
};

int main()
{
    grade_card a[6];
    for(int i=0; i<6; i++)
        a[i].getdata();
    max_cgp(a,6);
    return 0;
}
void max_cgp(grade_card *a, int n)
{
    int mi=0;
    for(int i=0; i<n; i++)
    {
        if(a[i].cgpa > a[mi].cgpa)
        {
            mi = i;
            continue;
        }
    }
    cout << "The student with hieghest cgpa is :" << endl;
    puts(a[mi].name);
    puts(a[mi].roll);
}
void grade_card::getdata()
{
    cout << "Enter the name of the student : "; 
    int i=0;
    fflush(stdin);
    do
    {
        name[i] = getchar(); 
        i++;
    }while(name[i-1] != '\n');
    name[i-1] = '\0';

    cout << "Enter the department name of the student : "; 
    i=0;
    fflush(stdin);
    do
    {
        dept[i]=getchar();
        i++;
    }while(dept[i-1] != '\n');
    dept[i-1] = '\0';

    cout << "Enter the Roll No. of the student : "; 
    i=0;
    fflush(stdin);
    do
    {
        roll[i]=getchar();
        i++;
    }while(roll[i-1] != '\n');
    roll[i-1] = '\0';

    cout << "Enter the semester of the student : ";
    fflush(stdin);
    cin >> sem;
    cout << "Enter the CGPA of the student : ";
    fflush(stdin);
    cin >> cgpa;
    for(int j=0; j<3; j++)
    {
        cout << "Subject" << j+1 << ": ";
        i=0;
        fflush(stdin);
        do
        {
            sub[j].name[i] = getchar();
            i++;
        }while(sub[j].name[i-1] != '\n');
        sub[j].name[i-1] = '\0';
        cout << "Enter marks obtained in subject" << j+1 << ": ";
        fflush(stdin);
        cin >> sub[j].marks;
    } 
    cout << endl << endl;
}