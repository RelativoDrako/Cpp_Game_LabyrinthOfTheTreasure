#ifndef ENEMY_H
#define ENEMY_H

class Enemy
{
    public:
        Enemy();
        int x, y; //Crear funciones GET, SET para que esten protected
        int LastX, LastY;
        void CallEnemy();
        void CallEnemy1();
        void EResetToSafePosition();

        virtual ~Enemy();

    protected:

    private:
};

#endif // ENEMY_H
