#include<stdio.h>

#include<stdlib.h>

#include<string.h>





enum state{menu,loggedin};

enum state currentstate=menu;



typedef struct user

{

    char username[100];

    char password[100];

    char place[100];

    float price;

    int numtick;



    struct user *next;

}user;



void ShowBrochure();

user* InitializeList(user*);

user* AddUser(user*);

void LoginUser(user*);

void BookTicket(user*);

void PrintTicket(user*);

void CancelTicket(user*);

void ChangePassword(user*);

void LogoutUser();

void CheckTicket(user*);

void DisplayAll(user*);

void WriteToFile(user*);

void ExitProgram();



char currentuser[100];



int main()

{

    system("color e4");

    printf("\n\n\n\t\t\t*******************************\n\n\t\t\t:::::^^^ TOUR MANAGER ^^^:::::\n\n\t\t\t*******************************\n\n\n");

    user *h=NULL;

    int ch1,ch2;

    h=InitializeList(h);

    while (1)

    {



        if(currentstate==menu)

        {



            printf("\n\n\t\t\t\tAdd User - 1\n\t\t\t\tLogin User - 2\n\t\t\t\tAdvertisement - 3\n\t\t\t\tExit - 4\n\n\t\t\t\tEnter:");

            scanf("%d",&ch1);

            switch(ch1)

            {

                case 1:

                    system("CLS");

                    h=AddUser(h);

                    break;

                case 2:

                    system("CLS");

                    LoginUser(h);

                    break;

                case 3:

                    system("CLS");

                    ShowAdd();

                    break;

                case 4:

                    system("CLS");

                    ExitProgram();

                    exit(0);

                    break;

                default:

                    printf("Not a valid input at this stage\n");

            }

        }

        else if(currentstate==loggedin)

        {

        system("CLS");

        printf("\n\t\t\t\t:::::::::::::::::");

   printf("\n\t\t\t\tTOUR MANAGER");

  printf("\n\t\t\t\t:::::::::::::::::\n");

        printf("\n\t\t\t\tBook Package - 1\n\t\t\t\tCheck Ticket - 2\n\t\t\t\tCancel Ticket - 3\n\t\t\t\tChange Password - 4"

                   "\n\t\t\t\tLogout User - 5\n\t\t\t\tAdvertisement - 6\n\t\t\t\tExit - 7\n");

            scanf("%d",&ch2);

            switch(ch2)

            {

                case 1:

                    BookTicket(h);

                    system("PAUSE");

                    system("CLS");

                    break;

                case 2:

                    CheckTicket(h);

                    system("PAUSE");

                    system("CLS");

                    break;

                case 3:

                    CancelTicket(h);

                    system("PAUSE");

                    system("CLS");

                    break;

                case 4:

                    ChangePassword(h);

                    system("PAUSE");

                    system("CLS");

                    break;

                case 5:

                    LogoutUser(h);

                    system("PAUSE");

                    system("CLS");

                    break;

                case 6:

                    ShowAdd();

                    system("PAUSE");

                    system("CLS");

                    break;

                case 7:

                    ExitProgram();

                    exit(0);

                    break;

                default:

                    printf("Not a valid input at this stage\n");

            }

        }

    }

    return 0;

}



user* InitializeList(user *h)

{

    user* t,*ptr,temp;

    FILE *fp;

    int cc=0,x;

    float ff;

    fp=fopen("users.txt","r");



    if(fp==NULL)

        return NULL;



    if(fgetc(fp)==EOF)

        return NULL;



    rewind(fp);

 while(fscanf(fp,"%s %s %s %f %d",temp.username,temp.password,temp.place,&temp.price,&temp.numtick)!=EOF)

 {

  ptr=(user*)malloc(sizeof(user));

  strcpy(ptr->username,temp.username);

  strcpy(ptr->password,temp.password);

  strcpy(ptr->place,temp.place);

  ptr->price=temp.price;

  ptr->numtick=temp.numtick;

  ptr->next=NULL;



  if(h==NULL)

            h=t=ptr;

  else

  {

   h->next=ptr;

   h=ptr;

  }

 }

 fclose(fp);

    return t;

}



void WriteToFile(user *h)

{

    system("color 4e");

    FILE *fp;

    fp=fopen("users.txt","w");

    while(h!=NULL)

    {

        fprintf(fp,"%s %s %s %f %d\n",h->username,h->password,h->place,h->price,h->numtick);

        h=h->next;

    }

    fclose(fp);

}



void ShowAdd()

{

    system("color e4");

 system("CLS");

    printf("\t\t\tPRICE LIST\n\t\t\t^^^^^^^^^^^^^^****^^^^^^^^^^^^\n\nThis cost is for a single person\n\n\n1. CO - Cox's Bazar - TK 6000\n2. SV - Sazek valley - TK 3500\n3. RG - Rangamati - TK 4500\n4. SK - shitakundu TK 5000\n"

           "5. KU - Kuakata - TK 8000\n6. KS-Kashmir - TK 10000\n7. SM - Sentmartin - TK 6000\n8. SN - Sundarban - TK 10000\n9. LM - Lalmatia - TK 7000\n10. DJ - Darjeeling - TK 10000\n");

}



void CheckTicket(user *h)

{

    system("color f5");

    while(h!=NULL)

    {

        if(!strcmp(h->username,currentuser))

            break;

        h=h->next;

    }

    if(!strcmp(h->place,"\0") || h->price==0.0 || h->numtick==0)

    {

        printf("You do not have a ticket booked yet\n");

        return;

    }

    float total=0.0;

    total=(h->price)*(h->numtick);

    printf("You have booked %d tickets for a sum total of Tk %f for tour code %s\n",h->numtick,total,h->place);

}



user* AddUser(user* h)

{

    user *t;

    t=h;

    user *nw;

    nw=(user*)malloc(sizeof(user));

    fflush(stdin);

    printf("Enter username or email\n");

    scanf("%s",nw->username);

    while(h!=NULL)

    {

        if(!strcmp(h->username,nw->username))

        {

            printf("That email already exists\n");

            return t;

        }

        h=h->next;

    }

    h=t;

    fflush(stdin);

    printf("Enter password\n");

    scanf(" %[^\n]s",&nw->password);

    nw->next=NULL;

    strcpy(nw->place,"N/A");

    nw->price=0.0;

    nw->numtick=0;



    if(h==NULL)

    {

        h=t=nw;

    }

    else

    {

        while(h->next!=NULL)

        {

            h=h->next;

        }

        h->next=nw;

    }

    WriteToFile(t);

    return t;

}



void LoginUser(user* h)

{

    system("color b1");

    char username[100];

    char password[100];

    fflush(stdin);

    printf("\n\n");

    printf("\t\tEnter Email/Username:\n\t\t");

    scanf("%s",username);

    fflush(stdin);

    printf("\n\t\tEnter Password:\n\t\t");

    scanf(" %[^\n]s",password);

    while(h!=NULL)

    {

        if((!strcmp(h->username,username)) && (!strcmp(h->password,password)))

        {

            currentstate=loggedin;

            strcpy(currentuser,username);



            printf("\n\t\tLogin successful!\n");

            system("PAUSE");

            return;

        }

        else if((!strcmp(h->username,username)) && (strcmp(h->password,password)))

        {

            printf("Password mismatch\n");

            return;

        }

        h=h->next;

    }

    printf("Sorry, no such user record was found\n");

}



void BookTicket(user *h)

{

    system("color e1");

    user *t=h;

    char place[100];

    while(h!=NULL)

    {

        if(!strcmp(h->username,currentuser))

            break;

        h=h->next;

    }

    if(h==NULL)

        return;

    if(h->price!=0.0)

    {

        printf("You must cancel your previous ticket before buying a new one\n");

        return;

    }

    ShowAdd();

    float pricelist[]={8000.0,6000.0,5000.0,10000.0,12000.0,10000.0,9000.0,14000.0,45000.0,15000.0};

    fflush(stdin);

    printf("\nEnter place code (eg: CO, SV)\n");



    scanf(" %[^\n]s",place);

    char choice;

    choice=toupper(place);

    fflush(stdin);



    long int phn_no;

    printf("\nEnter phone no.: \n");

    scanf("%ld",&phn_no);





    float price;





    if(strcmp(place,"CO")==0)

        price=pricelist[0];

    else if(strcmp(place,"SV")==0)

        price=pricelist[1];

    else if(strcmp(place,"RG")==0)

        price=pricelist[2];

    else if(strcmp(place,"SK")==0)

        price=pricelist[3];

    else if(strcmp(place,"KU")==0)

        price=pricelist[4];

    else if(strcmp(place,"HIM")==0)

        price=pricelist[5];

    else if(strcmp(place,"SM")==0)

        price=pricelist[6];

    else if(strcmp(place,"SM")==0)

        price=pricelist[7];

    else if(strcmp(place,"SN")==0)

        price=pricelist[8];

    else if(strcmp(place,"LM")==0)

        price=pricelist[9];

    else if(strcmp(place,"DJ")==0)

        price=pricelist[10];

    else

    {

        printf("That tour code doesn't exist\n");

        return;

    }

    printf("Enter the number of tickets you want to book?\n");

    scanf("%d",&h->numtick);

    if(h->numtick==0)

    return;

    strcpy(h->place,place);

    h->price=price;

    WriteToFile(t);



    printf("Bookings Done!!\n");

    system("PAUSE");







}



void CancelTicket(user *h)

{

    system("color A4");

    user *t=h;

    while(h!=NULL)

    {

        if(!strcmp(h->username,currentuser))

            break;

        h=h->next;

    }



    int flag=-1;



    if(h==NULL)

        printf("No such user\n");



     if(strcmp(h->place,"CO")==0)

        flag++;

    else if(strcmp(h->place,"SV")==0)

        flag++;

    else if(strcmp(h->place,"RG")==0)

        flag++;

    else if(strcmp(h->place,"SK")==0)

        flag++;

    else if(strcmp(h->place,"KU")==0)

        flag++;

    else if(strcmp(h->place,"HIM")==0)

        flag++;

    else if(strcmp(h->place,"SM")==0)

        flag++;

    else if(strcmp(h->place,"SN")==0)

        flag++;

    else if(strcmp(h->place,"LM")==0)

        flag++;

    else if(strcmp(h->place,"DJ")==0)

        flag++;

    else

    {

        printf("You haven't booked a tour yet\n");

        return;

    }

    if(flag==0)

    {

        printf("Your ticket has been successfully cancelled\nA refund of Rs %f for Tour Code %s for %d tickets will soon be made to your original source of purchase\n",h->price,h->place,h->numtick);

        strcpy(h->place,"N/A");

        h->price=0.0;

        h->numtick=0;

        WriteToFile(t);

    }

}



void ChangePassword(user *h)

{

    system("color e3");

    user *t=h;

    char passcurr[100];

    fflush(stdin);

    printf("Enter your current password to continue:\n");

    scanf(" %[^\n]s",passcurr);

    while(h!=NULL)

    {

        if(!strcmp(h->username,currentuser))

            break;

        h=h->next;

    }

    if(h==NULL)

        return;

    if(!strcmp(passcurr,h->password))

    {

        printf("Enter new password:\n");

        scanf(" %[^\n]s",h->password);

    }

    WriteToFile(t);

}



void LogoutUser()

{

    system("color b1");

    if(currentstate==menu || strcmp(currentuser,"\0")==0)

    {

        printf("You must be logged in to logout\n");

        return;

    }

    strcpy(currentuser,"\0");

    currentstate=menu;

    printf("You have been successfully logged out\n");

}



void ExitProgram()

{

    system("color 40");

    printf("Exiting...\n:^:^:Developed by The Royal Coder Team:^:^:\n\nPress \"Enter\" to exit");

    char exitprog;

    fflush(stdin);

    scanf("%c",&exitprog);

}
