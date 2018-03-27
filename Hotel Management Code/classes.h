//beginning of classes.h header file
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <cstdlib>
#include<conio.h>
#include<unistd.h>
using namespace std;

class Person
{
    public:
    char name[20];
    char adrs[30];
    char ph[10];
    char adhaar[15];

    public:
        //friend istream& operator >>(istream&,Person);
        void read();
        friend ostream& operator <<(ostream&,Person);
};




class Room
{
    public:
    char size,ac,tv;
    int roomNumber,status,rent,days;
    class Person cust;
    Room()
    {
        status=5;
    }
    Room operator +(int);
    void operator -(int);
    friend ostream& operator <<(ostream&,Room);
};


class HotelMgnt:protected Room
{
    public:
    void reserveRoom();
    void searchRoom(int);
    void getAvailRoom();
    void generateBill(int);
};

class administrator
{
    char name[15];
    char id[10];
    char password[20]="admin";
    public:
        char * getname();
        char * getid();
        char * getpass();
        void update_details(char );
};

class WORKER
{
    char name[15];
    char section[10];
    int pay;
    char password[10];

    public:
        char id[10];
        int status=0;
        void operator ++();
        void operator --();
        int searchWorker(char temp[]);
        friend ostream& operator <<(ostream&,WORKER);
        char * getname();
        char * getid();
        char * getsection();
        char * getpass();
        void update_details(char );
};
//end of classes.h header file
