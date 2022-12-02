#ifndef GAMEMAP_H
#define GAMEMAP_H
#include "MapCell.h"

class GameMap
{
    public:
        GameMap();
        MapCell* PlayerCell;
        MapCell* EnemyCell;
        MapCell cells[15][40];
        void DrawIntro();
        void DrawVictory();
        void DrawGameOver();
        void Draw();
        void ChoseLevel();
        int level=0;
        bool SetPlayerCell(int PlayerX, int PlayerY);
        bool SetEnemyCell(int EnemyX, int EnemyY);
        bool IsGameover=false;

        virtual ~GameMap();

    protected:
           void LoadMapFromFile();
           void LoadMapFromFile1();
           void LoadMapFromFile2();
    private:
};

#endif // GAMEMAP_H
