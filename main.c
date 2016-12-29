#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>


void startonly()
{

    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t|\\/|");pause(0.3);
    printf("i");pause(0.3);
    printf("|\\|");pause(0.3);
    printf("e");pause(0.3);
    printf("  s");pause(0.3);
    printf("\\/\\/");pause(0.3);
    printf("e");pause(0.3);
    printf("e");pause(0.3);
    printf("p");pause(0.3);
    printf("e");pause(0.3);
    printf("r\n\n\n\n\n\n\n\n\n\n");
    system("pause");

}
int mainmenu (int d,char dd[3])
{
    do
        {
            system("COLOR F4");
            system("cls");
            printf("\n\t\t\t\t********MINESWEEPER GAME********\n\n\n\t\t\t\t");pause(0.4);
            printf("    1-New Game\n\n\t\t\t\t");pause(0.3);
            printf("    2-Load Game\n\n\t\t\t\t");pause(0.3);
            printf("    3-Leader Board\n\n\t\t\t\t");pause(0.3);
            printf("    4-EXIT\n\n\t\t\t\t==> ");
            d=scanner(dd);
            if(d==3)
            {
                FILE *score=fopen("score.txt","a");
                fclose(score);
                loadsheet();

            }
            system("cls");
        }
        while(d!=1&&d!=2&&d!=4);
        return d;
}
void startups(int n,int m,int numofmoves,int numofmines,int left,int numofQ,char logic[n+1][m+1], char userprint[n+1][m+1],clock_t time1,clock_t time2)
{
    int i,j;
    for(i=0; i<n+1; i++)
        for(j=0; j<m+1; j++)        //making logic array elements equal zeros
            logic[i][j]=48;

    for(i=1; i<n+1; i++)
        for(j=1; j<m+1; j++)        //printing X,s
            userprint[i][j]='X';
    system("COLOR 80");
    print(n,m,numofmoves,numofmines,left,numofQ,userprint,time1,time2);
}
void print(int n, int m,int numofmoves,int numofmines,int left,int numofQ,char A[n+1][m+1],clock_t time1,clock_t time2)
{
    int i,j;
    printf(" \n\n\t\t\t\t*****MINESWEEPER GAME*****\n");
    printf("\t\t\t\t\t\t\t\t\tNumber of moves: %d\n",numofmoves);
    printf("\t\t\t\t\t\t\t\t\tNumber of mines: %d\n",numofmines);
    printf("\t\t\t\t\t\t\t\t\tNumber of '?'s : %d\n",numofQ);
    printf("\t\t\t\t\t\t\t\t\tPossible flags : %d\n",(numofmines-left));
    printf("\t\t\t\t\t\t\t\t\tTime passed    : %.1f secs\n",(double)(time2-time1)/CLOCKS_PER_SEC);
    for(i=0; i<=m; i++)
        printf("  ");
    printf("\t\t\t   %c\n",1);
    printf("\t\t\t   ");      //instead of zero
    for(i=1; i<m+1; i++)
    {
        if(i<10) printf(" | %d",i);
        else if (i==10)
            printf(" |10 ");
        else
            printf("|%d ",i);
    }
    printf(" |\n\t\t\t    ");
    for(i=0; i<m+1; i++)
        printf("====");


    printf("\n\t\t\t");
    int f;
    printf("1  ");
    for(i=1; i<n+1; i++)
    {

        for(j=1; j<m+1; j++)
        {
            printf(" | %c",A[i][j]);
        }
        printf(" |\n\t\t\t    ");
        for(f=0; f<m+1; f++)
            printf("+---");

        if(i!=n)
        {
            if(i<9) printf("\n\t\t\t%d  ",i+1);
            else printf("\n\t\t\t%d ",i+1);
        }
    }
    printf("\n\t\t\t");
}
void spreadnumber (int i,int j,int n,int m,char logic[n+1][m+1])
{
    int z,l;
    for(z=i-1; z<i+2; z++)
    {
        for(l=j-1; l<j+2; l++)
        {
            if(logic[z][l]!='*')
                logic[z][l]=logic[z][l]+1;
        }
    }
}
void spreadmine (int n, int m, int a, int b, char logic[n+1][m+1] )
{
    int k,i,j,numofmines;
    numofmines = 1+(n*m/10);       //number of mines

    time_t t;
    srand((unsigned) time(&t));
    for(k=0; k<numofmines; k++)
    {
        // in order to not get any zeros in random.
        i=1+rand()%(n); //random range between 1 & n
        j=1+rand()%(m); //random range between 1 & m
        if(i==a&&j==b)
        {
            k--;               //to not put mine in the first click
        }
        else if (logic[i][j]!='*')
        {
            //checking if this two random numbers were already given before
            logic[i][j]='*';
            spreadnumber(i,j,n,m,logic);

        }
        else k--;
    }
    conv0tospace(n,m,logic);
    FILE*test=fopen("test.txt","w");
    fprintf(test,"\t\t\t   ");      //instead of zero
    for(i=1; i<m+1; i++)
    {
        if(i<10) fprintf(test," | %d",i);
        else if (i==10)
            fprintf(test," |10 ");
        else
            fprintf(test,"|%d ",i);
    }
    fprintf(test," |\n\t\t\t    ");
    for(i=0; i<m+1; i++)
        fprintf(test,"====");


    fprintf(test,"\n\t\t\t");
    int f;
    fprintf(test,"1  ");
    for(i=1; i<n+1; i++)
    {

        for(j=1; j<m+1; j++)
            fprintf(test," | %c",logic[i][j]);
        fprintf(test," |\n\t\t\t    ");
        for(f=0; f<m+1; f++)
            fprintf(test,"+---");

        if(i!=n)
        {
            if(i<9) fprintf(test,"\n\t\t\t%d  ",i+1);
            else fprintf(test,"\n\t\t\t%d ",i+1);
        }
    }
    fclose(test);

}
void cleanopen(int n,int m,int a,int b,char A[n+1][m+1],char B[n+1][m+1])
{
    int z,l;
    if(A[a][b]==' ')
    {
        B[a][b]=A[a][b];

        for(z=a-1; z<a+2; z++)
        {
            if(z>n+1)
                break;
            for(l=b-1; l<b+2; l++)
            {
                if(l>m+1)
                    break;
                if(A[z][l]==' ')
                {
                    if(B[z][l]!=A[z][l])
                    {

                        B[z][l]=A[z][l];
                        cleanopen(n,m,z,l,A,B);
                    }

                }
                else
                    B[z][l]=A[z][l];



            }
        }
    }
    else
    {
        B[a][b]=A[a][b];

    }

}
void conv0tospace(int n,int m,char logic[n+1][m+1])
{
    int i,j;
    for(i=1; i<n+1; i++)
        for(j=1; j<m+1; j++)
            if(logic[i][j]==48)
                logic[i][j]=32;
}
int action(int n,int m,int a,int b,char z[0],int left,int numofmines,char logic[n+1][m+1],char userprint[n+1][m+1])
{
    if(z[0]=='f'&&(userprint[a][b]==32||userprint[a][b]!='X'));  //to don't add flags on empty opened cells
    else
    {
        if((z[0]=='o'||z[0]=='O')&&userprint[a][b]=='X')
        {
            //if(userprint[a][b]=='f');                     //akram hena lama 7atet brackets 3al condition bta3 if elkbera 3ashan tshtaghal sa7 maba2enash m7tagen el if el gowa
            //else
            userprint[a][b]=logic[a][b];
        }

        else if(z[0]=='f'||z[0]=='F'&&userprint[a][b]=='X')
        {
            if(numofmines-left>0)
                userprint[a][b]='f';                                //new
            else
                return 23;
        }

        else if(z[0]=='?'&&userprint[a][b]=='X')
            userprint[a][b]='?';
        else if(z[0]=='r'||z=='R')
            userprint[a][b]='X';
    }
}
int helpfulopen(int n,int m,int a,int b,char logic[n+1][m+1],char userprint[n+1][m+1],int numofmoves,int numofmines,int left,int numofQ,clock_t time1,clock_t time2)
{
    int z,l,f=0,i,j;
    for(z=a-1; z<a+2; z++)
    {
        for(l=b-1; l<b+2; l++)
        {
            if(userprint[z][l]=='f')
                f++;
        }
    }
    if(userprint[a][b]-48==f)
    {
        {
            for(z=a-1; z<a+2; z++)
            {
                for(l=b-1; l<b+2; l++)
                {
                    if(userprint[z][l]!='f')
                        userprint[z][l]=logic[z][l];
                }
            }
        }
        for(z=a-1; z<a+2; z++)
        {
            for(l=b-1; l<b+2; l++)
            {
                if(logic[z][l]=='*'&&userprint[z][l]!='f')
                {
                    system("cls");
                    lose(n,m,a,b,numofmoves,numofmines,left,numofQ,logic,userprint,time1,time2);
                    return 1;
                }
            }
        }
    }
}
void lose(int n,int m,int a, int b,int numofmoves,int numofmines,int left,int numofQ,char logic[n+1][m+1],char userprint[n+1][m+1],clock_t time1,clock_t time2)
{
    int i,j;
    for(i=0; i<n+1; i++)
    {
        for(j=0; j<m+1; j++)
        {
            if(logic[i][j]=='*'&&userprint[i][j]!='f')
                logic[i][j]='M';
            else if(logic[i][j]!='*'&&userprint[i][j]=='f')
                logic[i][j]='_';
        }
    }
    logic[a][b]='!';
    numofmoves ++;
    system("COLOR C0");
    print(n,m,numofmoves,numofmines,left,numofQ,logic,time1,time2);
    printf("\n\n\t\t\t\t**** BOOOM!! Game Over ****\n\n\a\a\a");
}
void save(int numofmoves,int numofmines,int numofQ,int left,double savetime,int t1,int t2,int n,int m,char logic[n+1][m+1],char userprint[n+1][m+1])
{
    FILE *time=fopen("time.txt","w");
    fprintf(time,"%d\n%d",t1,t2);
    fclose(time);
    FILE *save = fopen("save.txt","w");
    fprintf(save,"%d\n%d\n%d\n%d\n%.1f\n",numofmoves,numofmines,numofQ,left,savetime);
    fclose(save);
    FILE *savearray = fopen("savearray.txt","w");
    fwrite(logic,sizeof(char),(n+1)*(m+1),savearray);
    fwrite(userprint,sizeof(char),(n+1)*(m+1),savearray);
    fclose(savearray);
    FILE *nm = fopen("nm.txt","w");
    fprintf(nm,"%d\n%d\n",n,m);
    fclose(nm);

}
int loadn (int n)
{
    FILE *nm=fopen("nm.txt","r");
    fscanf(nm,"%d",&n);
    fclose(nm);
    return n;
}
int loadm(int m)
{
    int i;
    FILE *nm=fopen("nm.txt","r");
    for(i=0; i<2; i++)
        fscanf(nm,"%d",&m);
    fclose(nm);
    return m;
}
void scoresheetsave(char username[100],int playerscore)
{
    int i = 0;
    FILE *score = fopen("score.txt","a");
    for(i=0; username[i]!='\0'; i++)
        fprintf(score,"%c",username[i]);
    fprintf(score,"\n%d\n",playerscore);
    fclose(score);
}
void sort(int l,int scores[l],char names[50][15])
{
    int i;
    int temp;
    int pos;
    char tmp[10][10];
    for(i=1; i<l; i++)
    {
        temp=scores[i];
        strcpy(tmp[0],names[i]);
        pos=i;
        while(temp>scores[pos-1]&&pos>0)
        {
            scores[pos]=scores[pos-1];
            strcpy(names[pos],names[pos-1]);
            pos--;
        }
        scores[pos]=temp;
        strcpy(names[pos],tmp[0]);
    }
}
void pause ( float sec )
{
    clock_t end_pause;
    end_pause = clock ()*1.0+ sec * CLK_TCK *1.0;

    while (clock() < end_pause) {}
}
void loadsheet()
{
    int i=0,counter=0,k=0,l=0;
    int scores[50];
    char names[50][15];
    char garbage[20][20];
    FILE *score = fopen("score.txt","r");
    rewind(score);
    while(!feof(score))
    {
        if (i%2==0)
        {
            fgets(names[k],15,score);
            k++;
        }
        else
        {
            fscanf(score,"%d",&scores[l]);
            l++;
            fgets(garbage[19],20,score);
        }
        i++;
    }
    fclose(score);
    int s;
    int count=0;
    for(i=0; i<k; i++)
    {
        for(s=i+1; s<l; s++)
        {
            int foundAt=-1;
            int i1=0;
            while(names[i][i1]!='\0')
            {
                int i2=0;
                if(names[i][i1]==names[s][i2])
                {
                    int z=i1;
                    while(names[i][z]==names[s][i2] && names[s][i2]!='\0')
                    {
                        z++;
                        i2++;
                    }
                    if(names[s][i2]=='\0')
                    {
                        foundAt=i1;
                        break;
                    }
                }
                i1++;
            }
            if (foundAt==i1)
            {
                scores[i]=scores[i]+scores[s];
                scores[s]=0;
                count++;
            }
        }
    }
    sort(l,scores,names);
    l=l-count;
    system("cls");
    system("COLOR 6F");
    printf("\n\n\t\t\t      ==>SCORE SHEET<==\n\n");
    for(i=1; i<=l; i++)
    {
        printf("\t\t\t%d. %s\t\t\t\t\t\t%d\n\t\t\t   _____________________________\n",i,names[i-1],scores[i-1]);
        pause(0.7);
    }
                char R[10];
                printf("\n\n\n\n\t\t\tpress R to Reset it.   Any key to continue\n\t\t  ==> ");
                gets(R);
                if((R[0]=='R'||R[0]=='r')&&R[1]=='\0')
                {
                    FILE *score = fopen("score.txt","w");
                    fprintf(score,"");
                    fclose(score);
                }
}
int scanner(char nn[3])
{
    int req=0,i;
    int count =0;
    while (req == 0)
    {
        scanf(" %30[^\n]%*c",nn);
        count=0;
        for(i=0; nn[i]!='\0'; i++)
        {
            if(nn[i]<48||nn[i]>57)
            {
                printf("\n\t\t\t\t   *Retry please*               (don't enter a letter or negative num)\n\t\t\t\t==> ");
                break;
            }
            count++;
        }
        if(nn[i]=='\0')
            req++;
        if(count>2&&req==1)
        {
            printf("\n\t\t\t\t   *retry please*               (number between 2&99)\n\t\t\t\t==> ");
            req--;
        }
    }
    if(count==2)
        return 10*(nn[0]-48)+(nn[1]-48);
    else if(count==1)
        return nn[0]-48;
}
int countstring(char username[100])
{
    int i = 0,j;
    for(j=0; username[j]!='\0'; j++)
    {
        i++;
    }
    return i;
}
void goodbye()
{
    system("COLOR 9F");
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\tThanks for playing\n\n\t\t\t\t\t");
    pause(1);
    printf("   G");pause(0.3);
    printf("O");pause(0.3);
    printf("O");pause(0.3);
    printf("D");pause(0.3);
    printf("B");pause(0.3);
    printf("Y");pause(0.3);
    printf("E");pause(0.3);
    printf("!");pause(0.3);
    printf("\n\n\n\n\n\n\n\n\n");
}
int wincheck (int openedcellsnum,int n ,int m ,char userprint[n+1][m+1],char logic [n+1][m+1])
{
   openedcellsnum=0;
   int i,j;
            for(i=1; i<n+1; i++)
            {
                for(j=1; j<m+1; j++)
                {
                    if(userprint[i][j]!='X'&&logic[i][j]!='*'&&userprint[i][j]!='f'&&userprint[i][j]!='?')
                        openedcellsnum++;
                }
            }
            return openedcellsnum;
}
void exitcase(int numofmoves,int numofmines,int left , int numofQ,int n , int m , char userprint[n+1][m+1],char logic[n+1][m+1],clock_t time1,clock_t time2,int t1,int t2,double savetime)
{
            int exit;
            system("cls");
            print(n,m,numofmoves,numofmines,left,numofQ,userprint,time1,time2);
            printf("\n\n\t\t\t\tBefore you exit do you want to save your game \n\t\t\t\tin order to continue it later ?? \n\n\t\t\t1-Yes.\n\t\t\t2-No.\n\n\t\t\t\t--> ");
            scanf("%d",&exit);
            if(exit==1)
            {
                t1=time1/CLOCKS_PER_SEC;
                t2=time2/CLOCKS_PER_SEC;
                save(numofmoves,numofmines,numofQ,left,savetime,t1,t2,n,m,logic,userprint);
                printf("\n\n\t\t\tYour progress has been saved successfully .. ;)\n\n ");
                getchar();
                return 0;
            }
            else if (exit == 2)
            {
                system("cls");
                goodbye();
                return 0;
            }
}
void usersavescore(int n, int m,int numofmoves,int numofmines,int left,int numofQ,char userprint[n+1][m+1],char logic[n+1][m+1],clock_t time1,clock_t time2,int checking,double wintime)
{
                    system("cls");
                    print(n,m,numofmoves,numofmines,left,numofQ,logic,time1,time2);
                    char username [100];
                    int counts=0,i,j;
                    do
                    {
                        if(checking!=0)
                            printf("\n\t\t\tplease enter a name without numbers: ");
                        else if(counts>=15)
                            printf("\n\t\t\tplease enter a smaller name: ");
                        else
                            printf("\n\n\t\t\tPlease Enter your name: ");
                        //fgets(username,100,stdin);
                        scanf(" %30[^\n]%*c",username);         //because gets is not working
                        counts=0;
                        counts=countstring(username);
                        checking=0;
                        for(j=0; username[j]!='\0'; j++)
                        {
                        if(username[j]>=48&&username[j]<=57)
                            checking++;
                        }
                    }
                    while(checking!=0||counts>=15);

                    for(j=0; username[j]!='\0'; j++)
                    {
                        if(username[j]<='Z'&&username[j]!=' ')
                            username[j]=username[j]+32;

                    }
                    char lol[10];
                    int playerscore = (pow(n,4)*pow(m,4))/(wintime*numofmoves);
                    scoresheetsave(username,playerscore);
                    printf("\n\t\t\t\tYour score is %d\n",playerscore);
                    printf("\n\t\t\tpress L to view leaderboard .. Any key to continue\n\n\t\t\t==> ");
                    gets(lol);
                    if((lol[0]=='L'||lol[0]=='l')&&lol[1]=='\0')
                        loadsheet();
                    //break;

}



int main()
{
    system("MODE 150 ,50");
    clock_t time1,time2,time3=0;
    int timeloaded=0,t1,t2,st,n,m,i,j,a,b,d,numofmoves=0,exit,kkk=0,checker=0/*for n & m entries*/,checker2=0;
    char nn[3],mm[3],aa[3],bb[3],dd[3],stt[3],z[3],oo='k'/*for game loop*/;
    system("COLOR F4");
    startonly();
    while(oo!='X'&&oo!='x')
    {
        checker = 0 ;        //for n & m entries
        checker2 = 0 ;
        d=mainmenu(d,dd);
        if(d==1)
        {
            do
            {
                printf("\n\n\t\t\t\t********MINESWEEPER GAME********\n\n\n\t\t\t\t");
                pause(0.3);
                printf("    1-Beginner\n\n\t\t\t\t");pause(0.3);
                printf("    2-Intermediate\n\n\t\t\t\t");pause(0.3);
                printf("    3-Expert\n\n\t\t\t\t");pause(0.3);
                printf("    4-Custom\n\n\t\t\t\t==> ");
                st=scanner(stt);
                system("cls");
            }
            while(st!=1&&st!=2&&st!=3&&st!=4);

            if(st==1)
            {
                n=6;
                m=6;
            }
            else if(st==2)
            {
                n=9;
                m=9;
            }
            else if(st==3)
            {
                n=15;
                m=15;
            }
            else if(st==4)
            {
                while(1)
                {
                    if (checker!=1)   //If number of columns contain error, it will not ask about rows again
                    {
                        if (checker2 != 1)
                            printf("\n\n\t\t\t\tEnter the number of rows\n\n\t\t\t\t==> ");
                        n=scanner(nn);
                    }

                    if(n<2)
                    {
                        printf("\n\t\t\t\t   *retry please*               (number between 2&99)\n\t\t\t\t==> ");
                        checker2=1;
                    }
                    else
                    {
                        if (checker2!=2)
                            printf("\n\n\t\t\t\tEnter the number of columns\n\n\t\t\t\t==> ");
                        m=scanner(mm);
                        checker = 1 ;
                        if(m<2)
                        {
                            printf("\n\t\t\t\t   *retry please*               (number between 2&99)\n\t\t\t\t==> ");
                            checker2 = 2;
                        }
                        else
                            break;

                    }
                }
            }
        }
        if(d==2)
        {
            time3=clock();
            n=loadn(n);
            m=loadm(m);
        }
        if(d==4)
        {
            break;
        }
        system("cls");
        int numofmines = 1+(n*m/10),left=0,numofQ=0,possibleflags,q=0,count2;
        char logic[n+1][m+1],userprint[n+1][m+1];
        time1=0;time2=0;
        double savetime;
        if(d==1)
        {
            startups(n,m,numofmoves,numofmines,left,numofQ,logic,userprint,time1,time2);
            z[0]='a';
            while(q==0)
            {
                while(z[0]!='o'&&z[0]!='f'&&z[0]!='?'&&z[0]!='O'&&z[0]!='F'&&z[0]!='R'&&z[0]!='r'&&z[0]!='x'&&z[0]!='X')
                {
                    do
                    {
                        numofmoves=0;
                        system("cls");                       //new
                        print(n,m,numofmoves,numofmines,left,numofQ,userprint,time1,time2);
                        printf("\n\t\t\t    Select ( o , f , ? , X )\n\n\t\t\tO --> open\n\t\t\tf --> flag\n\t\t\t? -->unknown\n\t\t\tR --> Remove flag or '?'\n\n\t\t\tX -->EXIT\n\n\t\t\t  --> ");
                        scanf(" %30[^\n]%*c",z);
                        count2=0;
                        for(i=0; z[i]!='\0'; i++)
                            count2++;
                    }
                    while(count2!=1);
                }
                if(z[0]=='x'||z[0]=='X')
                {
                    printf("\n\n\t\t\t\tThere is no actions to save. GOOD BYE\n\n");
                    return 0;         //the player did not even do anything to save it
                }
                printf("\n\t\t\tenter the dimensions of the wanted box : ");
                printf("\n\t\t\t  --> Row : ");
                a=scanner(aa);
                printf("\t\t\t  --> Column : ");
                b=scanner(bb);

                if(a==0||b==0)
                {
                    system("cls");
                    print(n,m,numofmoves,numofmines,left,numofQ,userprint,time1,time2);    //checking if the user entered zeros
                    printf("\n\t\t\t\tWARNING !!! \n\t\t\tDont enter zeros in dimensions \a\a\n\n");
                }
                else if(a>n||b>m)
                {
                    system("cls");
                    print(n,m,numofmoves,numofmines,left,numofQ,userprint,time1,time2);
                    printf("\n\t\t\t\tWARNING !!! \n\t\t\tPlease enter within limits \a\a\n\n");
                }
                else
                {
                    spreadmine(n,m,a,b,logic);
                    conv0tospace(n,m,logic);
                    action(n,m,a,b,z,left,numofmines,logic,userprint);
                    if(logic[a][b]==32&&(z[0]=='o'||z[0]=='O'))
                        cleanopen(n,m,a,b,logic,userprint);
                    system("cls");
                    numofmoves ++;
                    print(n,m,numofmoves,numofmines,left,numofQ,userprint,time1,time2);
                    time1=clock();
                    q++;
                }
            }
        }

        if(d==2)//load
        {
            FILE *save=fopen("save.txt","r");
            fscanf(save,"%d%d%d%d%f",&numofmoves,&numofmines,&numofQ,&left,&savetime);
            fclose(save);
            FILE *savearray=fopen("savearray.txt","r");
            fread(logic,sizeof(char),(n+1)*(m+1),savearray);
            fread(userprint,sizeof(char),(n+1)*(m+1),savearray);
            fclose(savearray);
            FILE *time=fopen("time.txt","r");
            fscanf(time,"%d%d",&t1,&t2);
            fclose(time);
            time1=t1*CLOCKS_PER_SEC;
            timeloaded=t2*CLOCKS_PER_SEC;
            time2=timeloaded;
            system("COLOR 80");
            print(n,m,numofmoves,numofmines,left,numofQ,userprint,time1,time2);
        }
        float wintime;
        int openedcellsnum=0,ll=0,checking=0/*used in refusing numbers within player name entry*/;
        while (1)
        {

            openedcellsnum=wincheck(openedcellsnum,n,m,userprint,logic);//win check
            if(openedcellsnum==n*m-numofmines)
            {
                for(i=0; i<n+1; i++)
                    for(j=0; j<m+1; j++)
                        if(logic[i][j]=='*')
                            logic[i][j]='f';
                system("cls");
                numofmoves ++;
                left=numofmines;
                system("COLOR A0");
                time2=clock()+timeloaded;
                print(n,m,numofmoves,numofmines,left,numofQ,userprint,time1,time2);
                printf("\n\n\n\t\t\t\t**** You Win!! ****\n\n");
                wintime=(double)(time2-time1)/CLOCKS_PER_SEC;
                printf("\n\t\t\t\tDo you want to save your score ? \n\n\t\t\t\t   1-Yes\n\n\t\t\t\t   2-No\n\n\t\t\t\t--> ");
                scanf("%d",&exit);
                if(exit==2)
                    break;
                else if(exit==1)
                {
                    usersavescore(n,m,numofmoves,numofmines,left,numofQ,userprint,logic,time1,time2,checking,wintime);
                    break;
                }
            }
            z[0]='a';
            time2=clock()+timeloaded-time3;
            while(z[0]!='o'&&z[0]!='f'&&z[0]!='?'&&z[0]!='O'&&z[0]!='F'&&z[0]!='R'&&z[0]!='r'&&z[0]!='x'&&z[0]!='X')
            {
                do
                {
                    printf("\n\t\t\t    Select ( o , f , ? , X )\n\n\t\t\tO --> open\n\t\t\tf --> flag\n\t\t\t? -->unknown\n\t\t\tR --> Remove flag or '?'\n\n\t\t\tX -->EXIT\n\n\t\t\t  --> ");
                    scanf(" %30[^\n]%*c",z);
                    count2=0;
                    for(i=0; z[i]!='\0'; i++)
                        count2++;
                }
                while(count2!=1);
            }
            if(z[0]=='x'||z[0]=='X')
                break;
            printf("\n\t\t\tenter the dimensions of the wanted box :");
            printf("\n\t\t\t  --> Row : ");
            a=scanner(aa);
            printf("\t\t\t  --> Column : ");
            b=scanner(bb);
            time2=clock()+timeloaded-time3;
            if(a==0||b==0)
            {
                system("cls");
                print(n,m,numofmoves,numofmines,left,numofQ,userprint,time1,time2);
                printf("\n\t\t\t\tWARNING !!! \n\t\t\tDont enter zeros in dimensions \n\n\a\a");
            }
            else if(a>n||b>m)
            {
                system("cls");
                print(n,m,numofmoves,numofmines,left,numofQ,userprint,time1,time2);
                printf("\n\t\t\t\tWARNING !!! \n\t\t\tPlease enter within limits \n\n\a\a");
            }
            else
            {
                if(logic[a][b]==32&&(z[0]=='o'||z[0]=='O'))
                    cleanopen(n,m,a,b,logic,userprint);
                int qw;
                if(userprint[a][b]!='X'&&userprint[a][b]!='f'&&userprint[a][b]!='?'&&(z[0]=='o'||z[0]=='O'))
                    qw=helpfulopen(n,m,a,b,logic,userprint,numofmoves,numofmines,left,numofQ,time1,time2);
                if (qw==1)     //condition to end game if the helpful open function found a mine near by
                    return 0;
                system("cls");
                int h;
                h=action(n,m,a,b,z,left,numofmines,logic,userprint);
                if(h==23)
                    printf("\n\t\t\t\tMaximum number of flags is used\n");
                left=0;
                for(i=1; i<n+1; i++)
                    for(j=1; j<m+1; j++)
                        if(userprint[i][j]=='f')
                            left++;
                numofQ=0;
                for(i=1; i<n+1; i++)
                    for(j=1; j<m+1; j++)
                        if(userprint[i][j]=='?')
                            numofQ++;
                if(userprint[a][b]=='*')
                {
                    lose(n,m,a,b,numofmoves,numofmines,left,numofQ,logic,userprint,time1,time2);
                    ll=1;
                    break;
                }
                numofmoves ++;
                print(n,m,numofmoves,numofmines,left,numofQ,userprint,time1,time2);
            }
        }
        savetime=(double)(time2-time1)/CLOCKS_PER_SEC;
        if(z[0]=='x'||z[0]=='X')
        {
            exitcase(numofmoves,numofmines,left,numofQ,n,m,userprint,logic,time1,time2,t1,t2,savetime);//Exit case
        }
        printf("\n\t\t\tpress any key to Play again.\n\t\t\t  **To Exit press X**\n\n\t\t\t--> ");
        scanf(" %c",&oo);
        system("cls");
        numofmoves=0;
        left=0;
        numofQ=0;
    }
    goodbye();
    return 0;
}
