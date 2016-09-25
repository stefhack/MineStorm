#ifndef WEAPON_H
#define WEAPON_H
#include "shot.h"
#include "vector"
#include <QPainter>

using namespace std;
/**
 *
 */
class Weapon
{
public:
    Weapon();
    /**
     *
     */
    void fire(QPainter &painter);

private:
    int speed;
    vector<Shot*> shots;
};

#endif // WEAPON_H
