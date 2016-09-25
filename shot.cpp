#include "shot.h"
#include <QPainter>

Shot::Shot(QPoint shotPoint, QPoint centerShip)
{
    _centerShot = shotPoint;
    _centerShip = centerShip;
    hatch();
}


Shot::~Shot(){
}

void Shot::hatch(){
    QPoint qPoint1 = QPoint(_centerShot.x(),_centerShot.y()-1);
    QPoint qPoint2 = QPoint(_centerShot.x()+1,_centerShot.y()-1);
    QPoint qPoint3 = QPoint(_centerShot.x()+1,_centerShot.y()+1);
    QPoint qPoint4 = QPoint(_centerShot.x()-1,_centerShot.y()+1);
    QPoint qPoint5 = QPoint(_centerShot.x()-1,_centerShot.y()-1);
   _shotPoint << qPoint1 << qPoint2 << qPoint3 << qPoint4 << qPoint5;
}

bool Shot::detectOutOfScreen(const QSize &size){
    bool isoutOfScreen = false;
    //Right side
    if(_centerShot.x() > size.width()){
        isoutOfScreen = true;
    }
    //Left side
    else if(_centerShot.x() < 0){
        isoutOfScreen = true;
    }
    //Top side
    else if(_centerShot.y() > size.height()){
        isoutOfScreen = true;
    }
    //Bottom side
    else if(_centerShot.y() < 0){
       isoutOfScreen = true;
    }

    return isoutOfScreen;
}

QPoint* Shot::getShot(){
    return &_centerShot;
}

QPolygon Shot::getPolygon(){
    return _shotPoint;
}

void Shot::reDrawShot(){

    QTransform transform;
    int xShotPoint=_centerShot.x();
    int yShotPoint=_centerShot.y();
    int xCenterShip=_centerShip.x();
    int yCenterShip=_centerShip.y();

    transform=transform.translate((xShotPoint-xCenterShip)*0.1,(yShotPoint-yCenterShip)*0.1);

    _shotPoint=transform.map(_shotPoint);
    _centerShot=transform.map(_centerShot);
}
