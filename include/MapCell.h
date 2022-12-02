#ifndef MAPCELL_H
#define MAPCELL_H

class MapCell
{
    public:
        MapCell();
        char Id;
        bool IsBlocked();

        virtual ~MapCell();

    protected:

    private:
};

#endif // MAPCELL_H
