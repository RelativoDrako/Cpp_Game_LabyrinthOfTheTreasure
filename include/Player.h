#ifndef PLAYER_H
#define PLAYER_H

class Player
{
    public:
        Player();
        int x, y; //Crear funciones GET, SET para que esten protected
        int LastX, LastY;
        void CallInput();
        void ResetToSafePosition();

        virtual ~Player();
    protected:
    private:
};

#endif // PLAYER_H
