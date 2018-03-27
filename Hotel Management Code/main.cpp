//beginning of main.cpp file
#include"classes.h"
#include"functions.h"
int main()
{
    administrator admin;
    Room room;
    int logch,adch,wch,a=0;
    char epassword[10],password[10],pass;
    int wsearch=0,flag=0;
    //for(int z=0;z<100;z++)
        //rooms[z].status=5;
    while(1)
    {
        logout:
        system("cls");
        for(int d=1;d<40;d++){cout<<"=";}
        cout<<"\n\n WELCOME TO HOTEL MANAGEMENT PROJECT\n\n";
        for(int d=1;d<40;d++){cout<<"=";}
        cout<<"\n\n1.ADMINISTRATOR LOGIN";
        cout<<"\n2.WORKER LOGIN";
        cout<<"\n3.CLOSE PROJECT";
        cout<<"\n\nchoice: ";
        cin>>logch;

        switch(logch)
        {
            case 1:
                cout<<"Enter your administrator password: ";
                cin>>epassword;
                adminp=fopen("adminpassword.txt","r");
                a=0;
                while((pass=getc(adminp))!=EOF)
                    password[a++]=pass;

                password[a]='\0';
                fclose(adminp);
                if(strcmp(password,epassword)==0)
                {
                    cout<<"\nLOGIN SUCCESSFUL!!";
                    sleep(1);
                    while(1)
                    {
                        system("cls");
                        for(int d=1;d<22;d++){cout<<"=";}
                        cout<<"\n    MAIN MENU\n";
                        for(int d=1;d<22;d++){cout<<"=";}
                        cout<<"\n1.Manage rooms";
                        cout<<"\n2.Reserve rooms";
                        cout<<"\n3.Workers Details";
                        cout<<"\n4.Checked in customers";
                        cout<<"\n5.Checked out customers";
                        cout<<"\n6.Admin A/c details";
                        cout<<"\n7.Logout";
                        cout<<"\nchoice: ";
                        cin>>adch;

                        switch(adch)
                        {
                            case 1:manageRooms();
                            break;
                            case 2:if(rcount==0)
                                    {
                                        cout<<"\nRoom's data is not available.\nPlease add the rooms first.";
                                        sleep(2);
                                    }
                                    else
                                        hm.reserveRoom();
                            break;
                            case 3:int adwch;
                                    do
                                    {
                                        system("cls");
                                        for(int d=1;d<25;d++){cout<<"=";}
                                        cout<<"\n    WORKERS DETAILS\n";
                                        for(int d=1;d<25;d++){cout<<"=";}
                                        cout<<"\n1.Add worker";
                                        cout<<"\n2.Delete worker";
                                        cout<<"\n3.Search worker";
                                        cout<<"\n4.Display workers list";
                                        cout<<"\n5.Return to main menu";
                                        cout<<"\nchoice: ";
                                        cin>>adwch;

                                        switch(adwch)
                                        {
                                            case 1:for(int j=0;j<100;j++)
                                                    {
                                                        if(worker[j].status==0)
                                                        {
                                                            ++worker[j];
                                                            cout<<"\nWORKER ADDED SUCCESSFULLY!\n";
                                                            sleep(1);
                                                            break;
                                                        }
                                                    }
                                            break;
                                            case 2:char tempid[10];
                                                    if(wcount==0)
                                                    cout<<"\nThere are no workers to delete\n";
                                                    else
                                                    {
                                                        int check=0;
                                                        cout<<"\nEnter worker ID: ";
                                                        cin>>tempid;
                                                        for(int i=0;i<100;i++)
                                                        {
                                                            if(worker[i].status==1)
                                                            {
                                                                if(strcmp(tempid,worker[i].id)==0)
                                                                {
                                                                     check=1;
                                                                     --worker[i];
                                                                     cout<<"\nWORKER DELETED SUCCESSFULLY!\n";
                                                                     break;
                                                                }
                                                            }
                                                        }
                                                        if(check==0)
                                                        {
                                                            cout<<"There is no worker with ID: "<<tempid<<endl;
                                                        }
                                                    }
                                                    sleep(1);
                                            break;
                                            case 3:char temp[10];
                                                    cout<<"\nEnter worker's name or ID: ";
                                                    cin>>temp;
                                                    for(int i=0;i<=100;i++)
                                                    {
                                                        wsearch=worker[i].searchWorker(temp);
                                                        if(wsearch==1)
                                                        {
                                                            getch();
                                                            break;
                                                        }
                                                    }
                                                    if(wsearch==0)
                                                    {
                                                        cout<<"\nWORKER NOT FOUND\n";
                                                        sleep(1);
                                                    }
                                            break;
                                            case 4:cout<<endl;
                                                    if(wcount>0)
                                                    {
                                                        for(int i=0;i<100;i++)
                                                        {
                                                            if(worker[i].status==1)
                                                            {
                                                                cout<<worker[i];
                                                            }
                                                        }
                                                        cout<<"\n      Total number of workers: "<<wcount;
                                                        getch();
                                                    }
                                                    else
                                                    {
                                                        cout<<"There are no workers\n";
                                                        sleep(1);
                                                    }
                                            break;
                                            case 5:
                                            break;
                                        }
                                    }while(adwch!=5);
                                break;
                                case 4:if(arcount>0)
                                       {
                                            int s=1;
                                            cout<<"\nSL NO.\tROOM NO\t\tCUSTOMER NAME\n";
                                            for(int r=0;r<100;r++)
                                            {
                                                if(rooms[r].status==1)
                                                          cout<<""<<s++<<"\t"<<rooms[r].roomNumber<<"\t\t"<<
rooms[r].cust.name<<endl;
                                            }
                                            getch();
                                        }
                                        else
                                        {
                                            cout<<"\nNo room has been checked in.\n";
                                            sleep(1);
                                        }
                                break;
                                case 5:if(ocount>0)
                                    {
                                        int sum=0,y=1,billamount;
                                        cout<<"\nSL NO.\tROOM NO\tCUSTOMER NAME\tDAYS\tAMOUNT\n";
                                        for(int q=0;q<ocount;q++)
                                        {

cout<<""<<y++<<"\t"<<out[q].roomNumber<<"\t"<<
out[q].cust.name<<"\t\t"<<out[q].days;
                                            billamount=(out[q].days*out[q].rent)+(out[q].days*out[q].rent)*0.02;
                                            cout<<"\tRs."<<billamount<<endl;
                                            sum+=billamount;
                                        }
                                        cout<<"\nTotal amount: Rs."<<sum<<endl;
                                        getch();
                                    }
                                    else
                                    {
                                        cout<<"\nNo room was checked out till now\n";
                                        sleep(1);
                                    }
                                break;
                                case 6: char up;
                                        updateAdmin:
                                        system("cls");
                                        for(int d=1;d<48;d++){cout<<"=";}
                                        cout<<"\n          ADMINISTRATOR DETAILS\n";
                                        for(int d=1;d<48;d++){cout<<"=";}
                                        cout<<"\nAdmin name\t: "<<admin.getname()<<"\t\tUpdate? Press N\n";
                                        cout<<"Admin ID\t: "<<admin.getid()<<"\t\tUpdate? Press I\n";
                                        cout<<"Password\t: "<<admin.getpass()<<"\t\tUpdate? Press P\n";
                                        up=getch();
                                        if(up=='N' || up=='I' || up=='P')
                                        {
                                            admin.update_details(up);
                                            goto updateAdmin;
                                        }
                                break;
                                case 7:cout<<"\n  LOGGING OUT...";
                                        sleep(1);
                                        goto logout;
                            }
                        }
                }
                else
                {
                    cout<<"\nWRONG PASSWORD\n";
                    sleep(1);
                }
                break;
                case 2:cout<<"Enter your worker password: ";
                        cin>>password;flag=0;
                        for(int e=0;flag==0 && e<100;e++)
                        {
                            if(strcmp(worker[e].getpass(),password)==0)
                            {
                                cout<<"\nLOGIN SUCCESSFUL!!";flag=1;
                                sleep(1);
                                while(1)
                                {
                                    system("cls");
         for(int d=1;d<20;d++){cout<<"=";}
                                    cout<<"\n     MAIN MENU\n";
                                    for(int d=1;d<20;d++){cout<<"=";}
                                    cout<<"\n1.Room Description";
                                    cout<<"\n2.Available rooms";
                                    cout<<"\n3.Reserve room";
                                    cout<<"\n4.Search room";
                                    cout<<"\n5.Generate bill";
                                    cout<<"\n6.Worker A/c details";
                                    cout<<"\n7.Logout";
                                    cout<<"\nchoice: ";
                                    cin>>wch;

                                    switch(wch)
                                    {
                                        case 1:char ch;
                                                FILE *fp1;
                                                fp1=fopen("description.txt","r");
                                                system("cls");
                                                while((ch=getc(fp1))!=EOF)
                                                    printf("%c",ch);

                                                fclose(fp1);
                                                cout<<"\n\nPress any key return to main menu ";
                                                getch();
                                        break;
                                        case 2:if(rcount==0)
                                                {
                                                    cout<<"\nRoom's data is not available.\nPlease add the rooms first.";
                                                    sleep(2);
                                                }
                                                else
                                                    hm.getAvailRoom();
                                        break;
                                        case 3:if(rcount==0)
                                                {
                                                    cout<<"\nRoom's data is not available.\nPlease add the rooms first.";
                                                    sleep(2);
                                                }
                                                else
                                                    hm.reserveRoom();
                                        break;
                                        case 4:if(rcount==0)
                                                {
                                                    cout<<"\nRoom's data is not available.\nPlease add the rooms first.";
                                                    sleep(2);
                                                }
                                                else
                                                {
                                                    int roomno;
                                                    cout<<"Enter room number: ";
                                                    cin>>roomno;
                                                    hm.searchRoom(roomno);
                                                }
                                        break;
                                        case 5:if(rcount==0)
                                                {
                                                    cout<<"\nRoom's data is not available.\nPlease add the rooms first.";
                                                    sleep(2);
                                                }
                                                else
                                                {
                                                    int rno;
                                                    cout<<"Enter Room Number: ";
                                                    cin>>rno;
                                                    hm.generateBill(rno);
                                                }
                                        break;
                                        case 6:char upw;
                                                updateWorker:
                                                system("cls");
                                                for(int d=1;d<55;d++){cout<<"=";}
                                                cout<<"\n                  WORKER DETAILS\n";
                                                for(int d=1;d<55;d++){cout<<"=";}
                                                cout<<"\nWorker name\t: "<<worker[e].getname()<<"\t\tUpdate? Press N\n";
                                                cout<<"Worker ID\t: "<<worker[e].getid()<<"\t\tUpdate? Press I\n";
                                                cout<<"Worker section\t: "<<worker[e].getsection()<<"\t\tUpdate? Press S\n";
                                                cout<<"worker Password\t: "<<worker[e].getpass()<<"\t\tUpdate? Press P\n";
                                                upw=getch();
                                                if(upw=='N' || upw=='I' || upw=='S' || upw=='P')
                                                {
                                                    worker[e].update_details(upw);
                                                    goto updateWorker;
                                                }
                                        break;
                                        case 7:cout<<"\n LOGGING OUT...";
                                                sleep(1);
                                                goto logout;
                                    }
                                }
                          }
                    }
                    if(flag==0)
                    {
                        cout<<"\nWRONG PASSWORD\n";
                        sleep(1);
                    }
                break;
                case 3:exit(0);
            }
        }
    return 0;
}

