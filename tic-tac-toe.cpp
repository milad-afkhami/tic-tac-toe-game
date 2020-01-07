#include <iostream>
#include <windows.h>

using namespace std;

char a[9];
int X=0,O=0,g=0;
string xp;
string op;

void namayesh();
char bord();
void play();
void natayej();

int main()
{
    string input="0";
    cout<<"   Hello, Welcome to 'Tic Tac Toe' Game."<<endl<<endl;
    cout<<"   Enter The First Player Nickname:"<<endl;
    getline(cin,op);
    cout<<"   Enter The Second Player Nickname:"<<endl;
    getline(cin,xp);
    system("cls");
    while(input!="end")
    {
        cout<<endl<<"   For Starting A New Game Enter 'start', For Ending Game Enter 'end', And For Visiting Scores Enter 'score':"<<endl;
        cin>>input;
        system("cls");
        if(input=="start")
        {
            g++;
            cout<<endl<<"   Game Number "<<g<<endl;
            cout<<endl;
            play();
        }
        else if(input=="end")
            cout<<endl<<"   Bye :)"<<endl;
        else if(input=="score")
        {
            system("cls");
            natayej();
        }
    }
    return 0;
}
void namayesh()
{
    cout<<endl<<"                  "<<a[0]<<"       "<<a[1]<<"       "<<a[2]<<endl<<endl<<endl<<"                  "<<a[3]<<"       "<<a[4]<<"       "<<a[5]<<endl<<endl<<endl<<"                  "<<a[6]<<"       "<<a[7]<<"       "<<a[8]<<endl<<endl;
}
char bord()
{
    if((a[0]==a[1])&&(a[1]==a[2]))
    {
        if(a[1]!='.')
            return a[0];
    }
    if((a[3]==a[4])&&(a[4]==a[5]))
    {
        if(a[3]!='.')
            return a[3];
    }
    if((a[6]==a[7])&&(a[7]==a[8]))
    {
        if(a[6]!='.')
            return a[6];
    }
    if((a[0]==a[3])&&(a[3]==a[6]))
    {
        if(a[3]!='.')
            return a[3];
    }
    if((a[1]==a[4])&&(a[4]==a[7]))
    {
        if(a[1]!='.')
            return a[1];
    }
    if((a[2]==a[8])&&(a[8]==a[5]))
    {
        if(a[5]!='.')
            return a[5];
    }
    if((a[0]==a[4])&&(a[4]==a[8]))
    {
        if(a[0]!='.')
            return a[0];
    }
    if((a[2]==a[4])&&(a[4]==a[6]))
    {
        if(a[4]!='.')
            return a[4];
    }
    return 'p';
}
void play()
{
    bool flag1=0,flag2=0;
    int n,cnt=0,omid=g;
    for(int i=0;i<9;i++)
        a[i]='.';
    while((cnt<9)&&(bord()=='p'))
    {
        system("cls");
        cout<<endl<<"   Game Number "<<g<<endl<<endl;
        namayesh();
        cout<<endl<<endl;
        if(flag1==1)
        {
            cout<<"   Please Enter A Number Between 1 and 9"<<endl<<endl;
        }
        else if(flag2==1)
            cout<<"   Repetitious Number. Please Choose Another One."<<endl<<endl;
        flag1=0,flag2=0;
        if(omid%2==0)
        {
            cout<<"   "<<xp<<", Enter Your Entended Number:";
        }
        else
            cout<<"   "<<op<<", Enter Your Entended Number:";
        cin>>n;
        cout<<endl;
        n--;
        if((n>10)||(n<0))
        {
            flag1=true;
                continue;
        }
        else if(omid%2==0)
        {
            if(a[n]=='.')
                a[n]='X';
            else
            {
                flag2=true;
                continue;
            }
        }

        else
        {
            if(a[n]=='.')
                a[n]='O';
            else
            {
                flag2=1;
                continue;
            }

        }
        cnt++;
        omid++;
        if(bord()=='X')
        {
            system("cls");
            cout<<endl<<"   Game Number "<<g<<endl<<endl;
            namayesh();
            cout<<endl<<endl<<"          *****     "<<xp<<" Won.     *****";
            X++;
        }
        else if(bord()=='O')
        {
            system("cls");
            namayesh();
            cout<<endl<<endl<<"          *****     "<<op<<" Won.     *****";
            O++;
        }
    }
    if(bord()=='p')
    {
        system("cls");
        cout<<endl<<"   Game Number "<<g<<endl<<endl;
        namayesh();
        cout<<endl<<endl<<"          *****            *****";
    }

}
void natayej()
{
    cout<<endl<<endl<<op<<"'s Point = "<<O<<endl<<endl<<xp<<"'s Point = "<<X<<endl;
}
