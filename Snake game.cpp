#include <bits/stdc++.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

enum Edir {Stop=0,Left,Right,Up,Down};
Edir dir;
const int width= 20,height = 20;
int x,y,fruitx,fruity;
int score;
int len;
vector<int> tailx(100,0);
vector<int> taily(100,0);
bool alive;

void Setup()
{
    alive=1;
    score=0;
    dir=Stop;
    x=width/2;
    y=height/2;
    len=0;
    fruitx= (rand() % width)-1;
    fruity=(rand() % height)-1;
}

void Draw()
{
    system("cls");
    for(int i=0;i<width;i++){
        cout<<"#";
    }
    cout<<endl;
    
    for(int i=0;i<width;i++){
        for(int j=0;j<height;j++){
        bool pp=0;
        if((j==0)||(j==width-1)){cout<<"#";
        pp=1;}
        else if((j==x)&&(i==y)){cout<<"O";
        pp=1;}
        else if((i==fruitx)&&(j==fruity)) {cout<<"%";
        pp=1;}
        for(int k=0;k<len;k++){
            if(i==taily[k] && j==tailx[k]) {cout<<"o";
            pp=1;}
        }
        if(!pp) cout<<" ";
        }
        cout<<endl;
    }

    for(int i=0;i<width;i++){
        cout<<"#";
    }
    cout<<endl;
    cout<<"SCORE: "<<score<<endl;
}

void Input(){
    if(_kbhit()){
        switch (getch())
        {
        case 'w':
            dir=Up;
            break;
        case 'a':
            dir =Left;
            break;
        case 'd':
            dir =Right;
            break;
        case 's':
            dir =Down;
            break;
        case 'x':
            alive=0;
            break;
        default:
            break;
        }
    }

}

void Logic(){
    int prevx=tailx[0];
    int prevy=taily[0];
    tailx[0]=x;
    taily[0]=y;
    for(int k=1;k<len;k++){
        int tempx=tailx[k];
        int tempy=taily[k];
        tailx[k]=prevx;
        taily[k]=prevy;
        prevx=tempx;
        prevy=tempy;
    }

    switch (dir)
    {
        case Left:
            x--;
            break;
        case Right:
            x++;
            break;
        case Up:
            y--;
            Sleep(5);
            break;
        case Down:
            y++;
            Sleep(5);
            break;
    }
    for(int i=0;i<len;i++){
        if((x==tailx[i])&&(y==taily[i])) alive=0;
    }

    if (x >= width) x = 0; else if (x < 0) x = width - 1;
    if (y >= height) y = 0; else if (y < 0) y = height - 1;
    if((x==fruity && y==fruitx)){
        score+=10;
        fruitx= (rand() % (width));
        fruity=(rand() % (height));
        len++;
    }
}

int main()
{
    srand(time(NULL));
    Setup();
    while(alive){
        Draw();
        Input();
        Logic();
        Sleep(50);
    }
    return 0;
}