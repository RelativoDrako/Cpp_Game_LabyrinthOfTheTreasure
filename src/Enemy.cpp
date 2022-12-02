#include "Enemy.h"
#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

Enemy::Enemy()
{
    x=5;
    y=5;
}

void Enemy::CallEnemy()
{
    srand(time(NULL));
    y = 2+rand()%(14-1);
    x = 2+rand()%(39-1);

    cout<<"Mi enemigo esta en la coordenada: "<<x<<", "<<y<<endl;
}
void Enemy::CallEnemy1()
{
    srand(time(NULL));
    y = 2+rand()%(14-1);
    x = 3+rand()%(38-1);

    cout<<"Mi enemigo esta en la coordenada: "<<x<<", "<<y<<endl;
}

void Enemy::EResetToSafePosition()
{
    cout<<"Choque!"<<endl;
}

Enemy::~Enemy(){}
