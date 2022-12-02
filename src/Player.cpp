#include<iostream>
#include<conio.h>
#include<Windows.h>
#include "Player.h"
using namespace std;

Player::Player()
{
    x=2;
    y=2;
}

void Player::CallInput()
{
    char UserInput = getch();
    switch(UserInput)
    {
    case 'w':
        LastY=y;
        y-=1;
        //cout << "El jugador se mueve arriba" <<endl;
        break;
    case 's':
        LastY=y;
        y+=1;
        //cout << "El jugador se mueve abajo" <<endl;
        break;
    case 'd':
        LastX=x;
        x+=1;
        //cout << "El jugador se mueve a la derecha" <<endl;
        break;
    case 'a':
        LastX=x;
        x-=1;
        //cout << "El jugador se mueve a la izquierda" <<endl;
        break;
    }
    cout<<"Mi jugador esta en la coordenada: "<<x<<", "<<y<<endl;
}

void Player::ResetToSafePosition()
{
    x = LastX;
    y = LastY;
}

Player::~Player(){}
