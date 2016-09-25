#include "ennemyspaceship.h"
#include "QTransform"
#include "math.h"
#include "iostream"
#include <QDebug>
#include <QPainter>

EnnemySpaceShip::EnnemySpaceShip()
{
    initShip();
}

EnnemySpaceShip::~EnnemySpaceShip(){
    _pointsEnnemySpaceShip.clear();//Destroy the polygon of space ship
}

void EnnemySpaceShip::initShip(){
    destroy();
    //Ship center;
    _centerEnnemySpaceShip= QPoint(300,-100);


    //Ship body
    QPoint qPoint1 = QPoint(_centerEnnemySpaceShip.x(),_centerEnnemySpaceShip.y()-30);
    QPoint qPoint2 = QPoint(_centerEnnemySpaceShip.x()+10,_centerEnnemySpaceShip.y()-30);
    QPoint qPoint3 = QPoint(_centerEnnemySpaceShip.x()+30,_centerEnnemySpaceShip.y()-10);
    QPoint qPoint4 = QPoint(_centerEnnemySpaceShip.x()+30,_centerEnnemySpaceShip.y()+10);
    QPoint qPoint5 = QPoint(_centerEnnemySpaceShip.x()+50,_centerEnnemySpaceShip.y()+10);
    QPoint qPoint6 = QPoint(_centerEnnemySpaceShip.x()+30,_centerEnnemySpaceShip.y()+50);
    QPoint qPoint7 = QPoint(_centerEnnemySpaceShip.x()+50,_centerEnnemySpaceShip.y()+50);
    QPoint qPoint8 = QPoint(_centerEnnemySpaceShip.x()+70,_centerEnnemySpaceShip.y()+10);
    QPoint qPoint9 = QPoint(_centerEnnemySpaceShip.x()+70,_centerEnnemySpaceShip.y()-10);
    QPoint qPoint10 = QPoint(_centerEnnemySpaceShip.x()+50,_centerEnnemySpaceShip.y()-50);
    QPoint qPoint11 = QPoint(_centerEnnemySpaceShip.x()+30,_centerEnnemySpaceShip.y()-50);
    QPoint qPoint12 = QPoint(_centerEnnemySpaceShip.x()+50,_centerEnnemySpaceShip.y()-10);
    QPoint qPoint13 = QPoint(_centerEnnemySpaceShip.x()+30,_centerEnnemySpaceShip.y()-10);
    QPoint qPoint14 = QPoint(_centerEnnemySpaceShip.x()+30,_centerEnnemySpaceShip.y()+10);
    QPoint qPoint15 = QPoint(_centerEnnemySpaceShip.x()+10,_centerEnnemySpaceShip.y()+30);
    QPoint qPoint16 = QPoint(_centerEnnemySpaceShip.x()-10,_centerEnnemySpaceShip.y()+30);
    QPoint qPoint17 = QPoint(_centerEnnemySpaceShip.x()-30,_centerEnnemySpaceShip.y()+10);
    QPoint qPoint18 = QPoint(_centerEnnemySpaceShip.x()-30,_centerEnnemySpaceShip.y()-10);
    QPoint qPoint19 = QPoint(_centerEnnemySpaceShip.x()-50,_centerEnnemySpaceShip.y()-10);
    QPoint qPoint20 = QPoint(_centerEnnemySpaceShip.x()-30,_centerEnnemySpaceShip.y()-50);
    QPoint qPoint21 = QPoint(_centerEnnemySpaceShip.x()-50,_centerEnnemySpaceShip.y()-50);
    QPoint qPoint22 = QPoint(_centerEnnemySpaceShip.x()-70,_centerEnnemySpaceShip.y()-10);
    QPoint qPoint23 = QPoint(_centerEnnemySpaceShip.x()-70,_centerEnnemySpaceShip.y()+10);
    QPoint qPoint24 = QPoint(_centerEnnemySpaceShip.x()-50,_centerEnnemySpaceShip.y()+50);
    QPoint qPoint25 = QPoint(_centerEnnemySpaceShip.x()-30,_centerEnnemySpaceShip.y()+50);
    QPoint qPoint26 = QPoint(_centerEnnemySpaceShip.x()-50,_centerEnnemySpaceShip.y()+10);
    QPoint qPoint27 = QPoint(_centerEnnemySpaceShip.x()-30,_centerEnnemySpaceShip.y()+10);
    QPoint qPoint28 = QPoint(_centerEnnemySpaceShip.x()-30,_centerEnnemySpaceShip.y()-10);
    QPoint qPoint29 = QPoint(_centerEnnemySpaceShip.x()-10,_centerEnnemySpaceShip.y()-30);
    QPoint qPoint30 = QPoint(_centerEnnemySpaceShip.x(),_centerEnnemySpaceShip.y()-30);

    //_points << _sommet << qPoint1;
    //Create ship Qpolygon
    _pointsEnnemySpaceShip << qPoint1 << qPoint2 << qPoint3 << qPoint4 << qPoint5 << qPoint6 << qPoint7 << qPoint8 << qPoint9 << qPoint10
                              << qPoint11 << qPoint12 << qPoint13 << qPoint14 << qPoint15 << qPoint16 << qPoint17 << qPoint18 << qPoint19 << qPoint20
                                 << qPoint21 << qPoint22 << qPoint23 << qPoint24 << qPoint25 << qPoint26 << qPoint27 << qPoint28 << qPoint29 << qPoint30;
}

void EnnemySpaceShip::move(){

    QTransform transform;

    transform = transform.translate(0,5);

    _pointsEnnemySpaceShip=transform.map(_pointsEnnemySpaceShip);
    _centerEnnemySpaceShip=transform.map(_centerEnnemySpaceShip);

}

QPolygon EnnemySpaceShip::getPolygon(){
    return _pointsEnnemySpaceShip;
}

QPoint EnnemySpaceShip::getCenter(){
    return _centerEnnemySpaceShip;
}

void EnnemySpaceShip::destroy(){
    _pointsEnnemySpaceShip.clear();
}

void EnnemySpaceShip::fileMines(){

}

