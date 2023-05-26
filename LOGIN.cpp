 #include <iostream>
 #include <fstream>
 #include <string.h>

using namespace std;

void login();
void registration();
void forgot();

int main()

{
    int c;
    cout<<"t\t\t___________________________________________________ \n\n\n";
    cout<<"\t\t\t              Welcome To The Page                    \n\n\n";
    cout<<"\t\t\t_____________________  MENU  ________________________ \n\n\n";
    cout<<"                                                             \n\n";
    cout<<"\t| Press 1 to LOGIN                    |"<<endl;
    cout<<"\t| Press 2 to REGISTER                 |"<<endl;
    cout<<"\t| Press 3 if FORGOT PASSWORD          |"<<endl;
    cout<<"\t| Press 4 to EXIT                     |"<<endl;
    cout<<"\n\t\t\t select options: ";
    cin>>c;
    cout<<endl;

    switch(c)
    {

        case 1:
            login();
            break;

        case 2:
            registration();
            break;

        case 3:
            forgot();
            break;
         ;

        case 4:
            cout<<"\t\t\t Thank You \n\n";
            break;

        default:
            system("cls");
            cout<<"\t\t\t Select Options \n"<<endl;
            main();
    }

}

void login() {

    int count;
    string userId, password, Id, pass;
    system("cls");
    cout<<"\t\t\t Enter surname and password : "<<endl;
    cout<<"\t\t\t USERNAME ";
    cin>>userId;
    cout<<"\t\t\t PASSWORD ";
    cin>>password;


    ifstream input("record.text");

    while(input>>Id>>pass)
    {
        if(Id == userId && pass == password)
        {
            count = 1;
            system("cls");
        }
    }

    input.close();

    if(count == 1)
    {
        cout<<userId<<"\n LOGNED IN \n successful! \n";
        main();
    }
    else {
        cout<<"\n LOGIN ERROR \n check surname or password";
    }
}

void registration() {

    string ruserId, rpassword, rId, rpass;
    system("cls");
    cout<<"\t\t\t Enter surname : ";
    cin>>ruserId;
    cout<<"\t\t\t Enter password : ";
    cin>>rpassword;

    ofstream f1("records.text" , ios::app);
    f1<<ruserId<<' '<<rpassword<<endl;
    system("cls");
    cout<<"\n\t\t\t Successfully Registered! \n";
    main();

}

void forgot() {

    int option;
    system("cls");
    cout<<"\t\t\t forgot password? \n";
    cout<<"Press 1 to search for id by surname "<<endl;
    cout<<"Press 2 to the main menu "<<endl;
    cout<<"\t\t\t Enter Choice: ";
    cin>>option;
    switch(option) {


        case 1:
        {
            int count = 0;
            string suserId,sId,spass;
            cout<<"\n\t\t\t Enter Previous Surname :";
            cin>>suserId;

            ifstream f2("records.text");
            while(f2>>sId>>spass)
            {

                if(sId == suserId)
                {

                    count = 1;
                }
            }
            f2.close();
            if(count == 1)
            {

                cout<<"\n\n Account Found! \n";
                cout<<"\n\n Your password: "<<spass;
                main();



            }
            else {
                cout<<"\n\t Account NOT Found! \n";
                main();

            }
            break;
        }

      case 2 :
            {
                main();
            }

        default:
            cout<<"\t\t\t wrong choice! try again "<<endl;
            forgot();

    }


 }
