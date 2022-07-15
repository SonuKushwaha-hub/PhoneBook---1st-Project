#include <iostream>
#include <cstdio>
#include <conio.h>
#include <cstring>
#include <cstdlib>
#include <windows.h>
using namespace std;
class person
{
public:
    char name[35];
    char address[50];
    char father_name[35];
    char mother_name[30];
    long int mble_no;
    char sex[8];
    char mail[100];
    char citision_no[20];
};
void menu();
void got(char *name);
void start();
void back();
void addrecord();
void listrecord();
void modifyrecord();
void deleterecord();
void searchrecord();
int main()
{
    system("color 5f");
    start();
    return 0;
}
void back()
{
    start();
}
void start()
{
    menu();
}
void menu()
{
    system("cls");
    cout << "\t\t**********WELCOME TO PHONEBOOK*************";
    cout << "\n\n\t\t\t  MENU\t\t\n\n";
    cout << "\t1.Add New   \t2.List   \t3.Exit  \n\t4.Modify \t5.Search \t6.Delete";
    switch (getch())
    {
    case '1':
        addrecord();
        break;
    case '2':
        listrecord();
        break;
    case '3':
        exit(0);
        break;
    case '4':
        modifyrecord();
        break;
    case '5':
        searchrecord();
        break;
    case '6':
        deleterecord();
        break;
    default:
        system("cls");
        cout << "\nEnter 1 to 6 only";
        cout << "\n Enter any key";
        getch();
        menu();
    }
}
void addrecord()
{
    system("cls");
    FILE *f;
    class person p;
    f = fopen("project", "ab+");
    cout << "\n Enter name: ";
    got(p.name);
    cout << "\nEnter the address: ";
    got(p.address);
    cout << "\nEnter father name: ";
    got(p.father_name);
    cout << "\nEnter mother name: ";
    got(p.mother_name);
    cout << "\nEnter phone no.:";
    cin >> p.mble_no;
    cout << "Enter sex:";
    got(p.sex);
    cout << "\nEnter e-mail:";
    got(p.mail);
    cout << "\nEnter citizen no:";
    got(p.citision_no);
    fwrite(&p, sizeof(p), 1, f);
    fflush(stdin);
    cout << "\nrecord saved";
    fclose(f);
    cout << "\n\nEnter any key";
    getch();
    system("cls");
    menu();
}
void listrecord()
{
    class person p;
    FILE *f;
    f = fopen("project", "rb");
    if (f == NULL)
    {
        cout << "\nCONTACT'S DATA NOT ADDED YET.";
    }
    else
    {
        while (fread(&p, sizeof(p), 1, f) == 1)
        {
            cout << "\n\n\n YOUR RECORD IS\n\n ";
            cout << "\nName=" << p.name << "\nAdress=" << p.address << "\nFather name=" << p.father_name << "\nMother name=" << p.mother_name << "\nMobile no=" << p.mble_no << "\nSex=" << p.sex << "\nE-mail=" << p.mail << "\nCitizen no=" << p.citision_no;
            getch();
            system("cls");
        }
    }
    fclose(f);
    cout << "\n Enter any key";
    getch();
    system("cls");
    menu();
}
void searchrecord()
{
    class person p;
    FILE *f;
    char name[100];
    f = fopen("project", "rb");
    if (f == NULL)
    {
        cout << "\nCONTACT'S DATA NOT ADDED YET.";
    }
    cout << "\nEnter name of person to search\n";
    got(name);
    while (fread(&p, sizeof(p), 1, f) == 1)
    {
        if (strcmp(p.name, name) == 0)
        {
            cout << "\n\tDetail Information About" << name;
            cout << "\nName=" << p.name << "\nAdress=" << p.address << "\nFather name=" << p.father_name << "\nMother name=" << p.mother_name << "\nMobile no=" << p.mble_no << "\nSex=" << p.sex << "\nE-mail=" << p.mail << "\nCitizen no=" << p.citision_no;
        }
        else
            cout << "\n file not found";
    }
    fclose(f);
    cout << "\n Enter any key";
    getch();
    system("cls");
    menu();
}
void deleterecord()
{
    class person p;
    FILE *f, *ft;
    int flag;
    char name[100];
    f = fopen("project", "rb");
    if (f == NULL)
    {
        cout << "\nCONTACT'S DATA NOT ADDED YET.";
    }
    else
    {
        ft = fopen("temp", "wb+");
        if (ft == NULL)
            cout << "\nfile opaning error";
        else
        {
            system("cls");
            cout << "\nEnter CONTACT'S NAME:";
            got(name);
            fflush(stdin);
            while (fread(&p, sizeof(p), 1, f) == 1)
            {
                if (strcmp(p.name, name) != 0)
                    fwrite(&p, sizeof(p), 1, ft);
                if (strcmp(p.name, name) == 0)
                    flag = 1;
            }
            fclose(f);
            fclose(ft);
            if (flag != 1)
            {
                cout << "\nNO CONACT'S RECORD TO DELETE.";
                remove("temp.txt");
            }
            else
            {
                remove("project");
                rename("temp.txt", "project");
                cout << "\nRECORD DELETED SUCCESSFULLY.";
            }
        }
    }
    cout << "\n Enter any key";
    getch();
    system("cls");
    menu();
}
void modifyrecord()
{
    int c;
    FILE *f;
    int flag = 0;
    class person p, s;
    char name[50];
    f = fopen("project", "rb+");
    if (f == NULL)
    {
        cout << "\nCONTACT'S DATA NOT ADDED YET.";
    }
    else
    {
        system("cls");
        cout << "\nEnter CONTACT'S NAME TO MODIFY:\n";
        got(name);
        while (fread(&p, sizeof(p), 1, f) == 1)
        {
            if (strcmp(name, p.name) == 0)
            {
                cout << "\n Enter name: ";
                got(s.name);
                cout << "\nEnter the address: ";
                got(s.address);
                cout << "\nEnter father name: ";
                got(s.father_name);
                cout << "\nEnter mother name: ";
                got(s.mother_name);
                cout << "\nEnter phone no.:";
                cin >> s.mble_no;
                cout << "Enter sex:";
                got(s.sex);
                cout << "\nEnter e-mail:";
                got(s.mail);
                cout << "\nEnter citizen no:";
                got(s.citision_no);
                fseek(f, sizeof(p), SEEK_CUR);
                fwrite(&s, sizeof(p), 1, f);
                flag = 1;
                break;
            }
            fflush(stdin);
        }
        if (flag == 1)
        {
            cout << "\n your data id modified";
        }
        else
        {
            cout << " \n data is not found";
        }
        fclose(f);
    }
    cout << "\n Enter any key";
    getch();
    system("cls");
    menu();
}
void got(char *name)
{
    int i = 0, j;
    char c, ch;
    do
    {
        c = getch();
        if (c != 8 && c != 13)
        {
            *(name + i) = c;
            putch(c);
            i++;
        }
        if (c == 8)
        {
            if (i > 0)
            {
                i--;
            }
            system("cls");
            for (j = 0; j < i; j++)
            {
                ch = *(name + j);
                putch(ch);
            }
        }
    } while (c != 13);
    *(name + i) = '\0';
}
