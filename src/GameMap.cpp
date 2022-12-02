#include "GameMap.h"
#include<iostream>
#include<fstream>
#include<windows.h>
#include<Enemy.h>
using namespace std;

GameMap::GameMap()
{
    PlayerCell=NULL; //
    EnemyCell=NULL;
    //SetEnemyCell(10,10);
    IsGameover=false;
    ChoseLevel();
}

void GameMap::ChoseLevel()
{
    if(level==0)
    {
        LoadMapFromFile();
    }
    else if(level==1)
    {
        LoadMapFromFile1();
    }
    else if(level==2)
    {
        LoadMapFromFile2();
    }
}

void GameMap::Draw()
{
    for(int i=0; i<15; i++)
    {
        for(int j=0; j<40; j++)
        {
            cout<<cells[i][j].Id;
        }
        cout<<endl;
    }
}

bool GameMap::SetPlayerCell(int PlayerX, int PlayerY)
{
    if(cells[PlayerY][PlayerX].IsBlocked()==false)
        {
            if(cells[PlayerY][PlayerX].Id=='$'&&level==2)
            {
                IsGameover=true;
                DrawVictory();
                return false;
            }
            else if(cells[PlayerY][PlayerX].Id=='$'&&level==1)
            {
                ChoseLevel();
                level++;
                PlayerX=2;
                PlayerY=2;
                LoadMapFromFile2();
                return true;
            }
            else if(cells[PlayerY][PlayerX].Id=='$'&&level==0)
            {
                ChoseLevel();
                level++;
                PlayerX=2;
                PlayerY=2;
                PlayerCell = &cells[PlayerY][PlayerX];
                LoadMapFromFile1();
                return true;
            }
            else if(cells[PlayerY][PlayerX].Id==2)
            {
                Enemy En;
                ChoseLevel();
                PlayerCell = &cells[PlayerY][PlayerX];
                //LoadMapFromFile1();
                En.EResetToSafePosition();
                IsGameover=true;
                DrawGameOver();
                return false;
            }
            else
            {
                if(PlayerCell!=NULL) //Borra el valor en la posicion donde paso el jugador
                {
                    PlayerCell->Id = 0;//0 espacio vacio //con char dibuja camino
                }

    Enemy Ene;
                PlayerCell = &cells[PlayerY][PlayerX];
                PlayerCell->Id = 4; //4 diamante, 5 trebol, 3 corazón, 8 vacio, 1 cara negra,2 cara blanca,7 As pica,
                Ene.CallEnemy();
                EnemyCell = &cells[Ene.y][Ene.x];
                EnemyCell->Id = 2;
            }
            return true;
        }
    else
    {
        return false;
    }
}

/*bool GameMap::SetEnemyCell(int EnemyX, int EnemyY)
{
    Enemy Enemigo;
    //if(cells[EnemyY][EnemyX].IsBlocked()==false)
      //  {
/*            if(cells[EnemyY][EnemyX].Id==4)//&&level==2)
            {
                Enemigo.EResetToSafePosition();
                IsGameover=true;
                return false;
            }*/
  /*          if(EnemyCell==NULL) //Borra el valor en la posicion donde paso el jugador
                {
                    EnemyCell->Id = '#';//0 espacio vacio //con char dibuja camino
                    cout<<"ENEMIGO"<<endl;
            EnemyCell = &cells[EnemyY][EnemyX];
            EnemyCell->Id = 4; //4 diamante, 5 trebol, 3 corazón, 8 vacio, 1 cara negra,2 cara blanca,7 As pica,

                    return true;
                }
           // else
             //   {
               // }
        //}
        else
                    cout<<"ENEMIGO_TR"<<endl;
         return false;
}*/

void GameMap::DrawIntro()
{
    string line;
    ifstream MyFile("Intro.txt");
    if(MyFile.is_open())
    {
        while(getline(MyFile, line))
        {
            cout<<line<<endl;
        }
        cin>>line;
    }
    else
    {
        cout<<"FATAL ERROR: INTRO COULD NOT BE LOADED!"<<endl;
    }
}

void GameMap::DrawVictory()
{
    string line;
    ifstream MyFile("Victory.txt");
    if(MyFile.is_open())
    {
        while(getline(MyFile, line))
        {
            cout<<line<<endl;
        }
        cin>>line;
    }
    else
    {
        cout<<"FATAL ERROR: VICTORY COULD NOT BE LOADED! :( "<<endl;
    }
}

void GameMap::DrawGameOver()
{
    string line;
    ifstream MyFile("GameOver.txt");
    if(MyFile.is_open())
    {
        while(getline(MyFile, line))
        {
            cout<<line<<endl;
        }
        cin>>line;
    }
    else
    {
        cout<<"FATAL ERROR: GAME OVER COULD NOT BE LOADED! :( "<<endl;
    }
}

void GameMap::LoadMapFromFile()
{
/*    ofstream FileCreated("Map.txt");
    if(FileCreated.is_open())    {    }
    else    {cout<<"FATAL ERROR: MAP COULD NOT BE CREATED!"<<endl;    }*/
    string line;
    int row = 0;
    ifstream MyFile("Map.txt");
    if(MyFile.is_open())
    {
        while(getline(MyFile, line))
        {
            for(int l=0; l<line.length(); l++)
            {
                if(line[l]=='0')
                {
                    cells[row][l].Id = 0;
                }
                else
                    cells[row][l].Id = line[l];
            }
            row++;
        }
    }
    else
    {
        cout<<"FATAL ERROR: MAP COULD NOT BE LOADED!"<<endl;
    }
}

void GameMap::LoadMapFromFile1()
{
/*    ofstream FileCreated("Map.txt");
    if(FileCreated.is_open())    {    }
    else    {cout<<"FATAL ERROR: MAP COULD NOT BE CREATED!"<<endl;    }*/
    string line;
    int row = 0;
    ifstream MyFile("Map1.txt");
    //cout<<"MAP 1"<<endl;
    if(MyFile.is_open())
    {
        while(getline(MyFile, line))
        {
            for(int l=0; l<line.length(); l++)
            {
                if(line[l]=='0')
                    cells[row][l].Id = 0;
                else
                    cells[row][l].Id = line[l];
            }
            row++;
        }
    }
    else
    {
        cout<<"FATAL ERROR: MAP COULD NOT BE LOADED!"<<endl;
    }
}


void GameMap::LoadMapFromFile2()
{
/*    ofstream FileCreated("Map.txt");
    if(FileCreated.is_open())    {    }
    else    {cout<<"FATAL ERROR: MAP COULD NOT BE CREATED!"<<endl;    }*/
    string line;
    int row = 0;
    ifstream MyFile("Map2.txt");
    //cout<<"MAP 2"<<endl;
    if(MyFile.is_open())
    {
        while(getline(MyFile, line))
        {
            for(int l=0; l<line.length(); l++)
            {
                if(line[l]=='0')
                    cells[row][l].Id = 0;
                else
                    cells[row][l].Id = line[l];
            }
            row++;
        }
    }
    else
    {
        cout<<"FATAL ERROR: MAP COULD NOT BE LOADED!"<<endl;
    }
}

GameMap::~GameMap(){}
