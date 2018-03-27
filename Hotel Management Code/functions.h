//beginning of functions.h header file.
int rcount=0;
int arcount=0;
int wcount=0;
int ocount=0;
Room rooms[100];
Room out[100];
FILE *adminp;
HotelMgnt hm;
WORKER worker[100];
//istream& operator >>(istream &din,Person temp)
void Person::read()
    {
        cout<<"Customer Name\t\t: ";
        cin>>name;
        cout<<"Customer Address\t: ";
        cin>>adrs;
        cout<<"Customer Phone no.\t: ";
        cin>>ph;
        cout<<"Customer Adhaar no.\t: ";
        cin>>adhaar;
    }
ostream& operator <<(ostream &dout,Person temp)
    {
        dout<<"\nCustomer Name\t\t: "<<temp.name;
        dout<<"\nCustomer Address\t: "<<temp.adrs;
        dout<<"\nCustomer Phone no.\t: "<<temp.ph;
        dout<<"\nCustomer Adhaar no.\t: "<<temp.adhaar;
        return dout;
    }



Room Room::operator +(int rno)
    {
        Room room;
        room.roomNumber=rno;
        cout<<"\nSingle/Double (S/D)\t: ";
        cin>>room.size;
        cout<<"\nAC facility (Y/N)\t: ";
        cin>>room.ac;
        cout<<"\nTV facility (Y/N)\t: ";
        cin>>room.tv;
        cout<<"\nRoom rent per day\t: Rs.";
        cin>>room.rent;
        room.status=0;
        return room;
    }

void Room::operator -(int rno)
{
    int found=0;
    for(int i=0;i<100;i++)
    {
        if(rooms[i].roomNumber==rno)
        {
            found=1;
            if(rooms[i].status==0)
            {
                rooms[i].status=5;
                rooms[i].roomNumber=0;
                rcount--;
                cout<<"\nROOM DELETED SUCCESSFULLY!\n";
            }
            else
            {
                cout<<"Currently the room has been allocated. Continue (Y/N) :  ";
                char c;
                cin>>c;
                if(c=='Y')
                {
                    rooms[i].status=5;
                    rooms[i].roomNumber=0;
                    rcount--;
                    arcount--;
                    cout<<"\nROOM DELETED SUCCESSFULLY!\n";
                }
            }
        }
    }
    if(found==0)
        cout<<"This room number does not exist\n";
    sleep(1);
}

ostream& operator <<(ostream &dout,Room temp)
{
    dout<<"\n     Room Number:"<<temp.roomNumber;
    dout<<"\t\tSize:"<<temp.size;
    dout<<"\t\tAC:"<<temp.ac;
    dout<<"\t\tTV:"<<temp.tv;
    dout<<"\t\tRent:Rs."<<temp.rent;
    return dout;
}



void HotelMgnt:: reserveRoom()
{
    int i,found=0,rno;
    cout<<"\nEnter Room number: ";
    cin>>rno;
    for(i=0;i<100;i++)
    {
        if(rooms[i].roomNumber==rno)
        {
            found=1;
            break;
        }
    }
    if(found==1)
    {
        if(rooms[i].status==1)
        {
            cout<<"\nRoom is already Reserved";
            sleep(1);
            return;
        }
        cout<<"\nEnter Customer Name: ";
        cin>>rooms[i].cust.name;
        rooms[i].status=1;
    }
}

void HotelMgnt::searchRoom(int rno)
{
    int i,found=0;
    for(i=0;i<100;i++)
    {
        if(rooms[i].roomNumber==rno)
        {
            found=1;
            break;
        }
    }
    if(found==1)
    {
        if(rooms[i].status==1)
        {
            cout<<"\nRoom is Reserved to";
            cout<<rooms[i].cust;
        }
        else
        {
            cout<<"\nRoom is available";
        }
        getch();
    }
    else
    {
        cout<<"\nRoom not found";
        sleep(1);
    }
}



void HotelMgnt:: getAvailRoom()
{
    int i,found=0,rno;char opt;
    for(i=0;i<100;i++)
    {
        if(rooms[i].status==0)
        {
            cout<<rooms[i];
            found=1;
        }
    }
    if(found==1)
    {
        cout<<"\n\nAllocate room? (Y/N) :  ";
        cin>>opt;
        if(opt=='Y')
        {
            cout<<"\nEnter room no: ";
            cin>>rno;
            int check=0;
            for(int m=0;m<100;m++)
            {
                if(rooms[m].roomNumber==rno)
                {
                    check=1;
                    if(rooms[m].status==0)
                    {
                        rooms[m].cust.read();
                        rooms[m].status=1;
                        arcount++;
                        break;
                    }
                    else
                    {
                        cout<<"\nThis room is not in the above list\n";
                        sleep(1);
                        break;
                    }
                }
            }
            if(check==0)
            {
                cout<<"\nThis room does not exist\n";
                sleep(1);
            }
        }
    }
    if(found==0)
    {
        cout<<"\nAll rooms are reserved";
        sleep(1);
    }
}




void HotelMgnt::generateBill(int roomNum)
{
    int i,found=0,days;
    float roomrent=0.0,tax=0.0;//,other=0.0;
    for(i=0;i<100;i++)
    {
        if(rooms[i].roomNumber==roomNum)
        {
            if(rooms[i].status==1)
            {
                found=1;
                break;
            }
            else
            {
                cout<<"Room has not been allocated\n";
                sleep(1);return;
            }
        }

    }
    if(found==1)
    {
        cout<<rooms[i].cust;
        cout<<"\nEnter Number of Days: ";
        cin>>days;
        roomrent=days * rooms[i].rent;
        tax=0.02*roomrent;
        cout<<"\nRoom Rent\t: Rs."<<roomrent;
        cout<<"\nTaxAmount\t: Rs."<<tax<<" (2% of room rent)";
        cout<<"\nTotal Amount\t: Rs. "<<roomrent+tax<<" /-";
        cout<<"\nTHANK YOU. VISIT AGAIN\n";
        rooms[i].status=0;
        out[ocount]=rooms[i];
        out[ocount++].days=days;
        arcount--;
        getch();
    }
    if(found==0)
    {
        cout<<"Room not found\n";
        sleep(1);
    }
}



char * administrator::getname()
    {
        return name;
    }
    char * administrator::getid()
    {
        return id;
    }
    char * administrator::getpass()
    {
        return password;
    }
    void administrator::update_details(char up)
    {
        if(up=='N')
        {
            cout<<"\nEnter new name: ";
            cin>>name;
        }
        else if(up=='I')
        {
            cout<<"\nEnter new ID: ";
            cin>>id;
        }
        else if(up=='P')
        {
            cout<<"\nEnter new password: ";
            cin>>password;
            adminp=fopen("adminpassword.txt","w");
            fputs(password,adminp);
            fclose(adminp);
        }
    }

void WORKER::operator ++()
    {
        cout<<"\nWorker Name\t: ";
        cin>>name;
        cout<<"Worker ID\t: ";
        cin>>id;
        cout<<"Section\t\t: ";
        cin>>section;
        cout<<"Payment\t\t: Rs.";
        cin>>pay;
        wcount+=1;
        strcat(password,"worker");
        FILE *zab;
        zab=fopen("workerpassword.txt","w");
        fputs(password,zab);
        fclose(zab);
        status=1;
    }
    int WORKER::searchWorker(char temp[])
    {
        int wsearch=0;
        if(status==1)
        {
            if(strcmp(name,temp)==0)
            {
                cout<<"\n WORKER FOUND!!\n";
                cout<<*this;
                wsearch=1;
            }
            else if(strcmp(id,temp)==0)
            {
                cout<<"\n WORKER FOUND!!\n";
                cout<<*this;
                wsearch=1;
            }
        }
        return wsearch;
    }
    void WORKER::operator --()
    {
        status=0;
        wcount-=1;
    }
    ostream& operator <<(ostream &dout,WORKER temp)
    {
        dout<<"      Worker Name: "<<temp.name;
        dout<<"\t\tWorker ID: "<<temp.id;
        dout<<"\t\tSection: "<<temp.section;
        dout<<"\t\tPayment: "<<temp.pay;
        dout<<endl;
        return dout;
    }
    char * WORKER::getname()
    {
        return name;
    }
    char * WORKER::getid()
    {
        return id;
    }
    char * WORKER::getsection()
    {
        return section;
    }
    char * WORKER::getpass()
    {
        return password;
    }
    void WORKER::update_details(char upw)
    {
        if(upw=='N')
        {
            cout<<"Enter new name: ";
            cin>>name;
        }
        else if(upw=='I')
        {
            cout<<"Enter new ID: ";
            cin>>id;
        }
        else if(upw=='S')
        {
            cout<<"Enter new section: ";
            cin>>section;
        }
        else if(upw=='P')
        {
            cout<<"Enter new password: ";
            cin>>password;
        }
    }





void manageRooms()
{
    Room room;
    int opt,rno,i,flag=0;
    do
    {
        system("cls");
        for(int d=1;d<20;d++){cout<<"=";}
        cout<<"\n   MANAGE ROOMS\n";
        for(int d=1;d<20;d++){cout<<"=";}
        cout<<"\n1.Add Room";
        cout<<"\n2.Delete Room";
        cout<<"\n3.Rooms list";
        cout<<"\n4.Return to Main Menu";
        cout<<"\nEnter Option: ";
        cin>>opt;

        switch(opt)
        {
            case 1:cout<<"\nEnter Room Number:";
                    cin>>rno;
                    i=0;
                    for(i=0;i<100;i++)
                    {
                        if(rooms[i].roomNumber==rno)
                        {
                            flag=1;
                        }
                    }
                    if(flag==1)
                    {
                        cout<<"\nRoom Number is Present.\nPlease enter unique Number";
                        flag=0;
                        sleep(2);
                    }
                    else
                    {
                        rooms[rcount]=room+rno;
                        rcount++;
                        cout<<"\nROOM ADDED SUCCESSFULLY!";
                        sleep(1);
                    }
            break;

            case 2:if(rcount>0)
                    {
                        cout<<"\nEnter room number: ";
                        cin>>rno;
                        room-rno;
                    }
                    else
                    {
                        cout<<"\nRoom's data is not available.\nPlease add the rooms first.\n";
                        sleep(2);
                    }
            break;

            case 3:cout<<endl;
                    if(rcount>0)
                    {
                        for(int av=0;av<100;av++)
                        {
                            if(rooms[av].status==0 || rooms[av].status==1)
                            {
                                    cout<<rooms[av];
                            }
                        }
                        cout<<"\n\n     Total number of rooms: "<<rcount;
                        getch();
                    }
                    else
                    {
                        cout<<"\nRoom's data is not available.\nPlease add the rooms first.\n";
                        sleep(2);
                    }
            break;

            case 4:
            break;

            default:cout<<"\nPlease Enter correct option";
            break;
        }
    }while(opt!=4);
}
//end of functions.h header file.
