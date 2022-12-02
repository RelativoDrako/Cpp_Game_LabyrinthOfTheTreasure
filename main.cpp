#include <iostream>
#include<Windows.h>
#include "Player.h"
#include "Enemy.h"
#include "MapCell.h"
#include "GameMap.h"

using namespace std;

int main()
{
    Player Hero;
    Enemy Mad;
    GameMap Map;
    MapCell Cel;
    Map.DrawIntro();
    Map.Draw();

    while(Map.IsGameover==false)
    {
        cout<<"Introduce el comando de movimiento: "<<endl;
        cout<<"a= Izquierda "<<endl;
        cout<<"d= Derecha "<<endl;
        cout<<"w= Arriba "<<endl;
        cout<<"s= Abajo "<<endl;
        cout<<"Nivel: "<<Map.level<<endl;
        Hero.CallInput();
        Mad.CallEnemy();
        Mad.CallEnemy1();

        if(Map.SetPlayerCell(Hero.x, Hero.y))//||Map.SetEnemyCell(Mad.x, Mad.y)) //Carga de posición Heroe en Mapa)
        {
            Map.Draw();//Dibujar Mapa
            //Map.EnemyCell->Id = 2;
        }
        else
        {
            Hero.ResetToSafePosition();
            Mad.EResetToSafePosition();
            Map.Draw();//Dibujar Mapa
        }
    }
    return 0;
}
