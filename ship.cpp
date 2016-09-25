#include "ship.h"
#include "QTransform"
#include "math.h"
#include "iostream"
#include <QDebug>
#include <QPainter>
using namespace std;

Ship::Ship(/*Weapon *aWeapon*/) //: shipWeapon(aWeapon)
{
    initShip();
    _isShooting=false;
}

void Ship::initShip(){

    //Ship center;
    _centerShip= QPoint(300,300);
    //Initialize speed 0 by default
    speed = 0;
    //Create top of ship according to its center
    _sommet = QPoint(_centerShip.x(),_centerShip.y()-35);

    QPointF qPoint1 = QPointF(_centerShip.x()+10,_centerShip.y());
    QPointF qPoint2 = QPointF(_centerShip.x()+15,_centerShip.y());
    QPointF qPoint3 = QPointF(_centerShip.x()+15,_centerShip.y()-15);
    QPointF qPoint4 = QPointF(_centerShip.x()+15,_centerShip.y());
    QPointF qPoint5 = QPointF(_centerShip.x()+20,_centerShip.y());
    QPointF qPoint6 = QPointF(_centerShip.x()+20,_centerShip.y()-10);
    QPointF qPoint7 = QPointF(_centerShip.x()+25,_centerShip.y()-10);
    QPointF qPoint8 = QPointF(_centerShip.x()+25,_centerShip.y()-30);
    QPointF qPoint9 = QPointF(_centerShip.x()+25,_centerShip.y()-10);
    QPointF qPoint10 = QPointF(_centerShip.x()+30,_centerShip.y()-10);
    QPointF qPoint11 = QPointF(_centerShip.x()+30,_centerShip.y()+10);
    QPointF qPoint12 = QPointF(_centerShip.x()+20,_centerShip.y()+10);
    QPointF qPoint13 = QPointF(_centerShip.x()+20,_centerShip.y()+5);
    QPointF qPoint14 = QPointF(_centerShip.x()+10,_centerShip.y()+10);
    QPointF qPoint15 = QPointF(_centerShip.x()+10,_centerShip.y()+15);
    QPointF qPoint16 = QPointF(_centerShip.x()+5,_centerShip.y()+15);
    QPointF qPoint17 = QPointF(_centerShip.x()+5,_centerShip.y()+10);
    QPointF qPoint18 = QPointF(_centerShip.x()-5,_centerShip.y()+10);
    QPointF qPoint19 = QPointF(_centerShip.x()-5,_centerShip.y()+15);
    QPointF qPoint20 = QPointF(_centerShip.x()-10,_centerShip.y()+15);
    QPointF qPoint21 = QPointF(_centerShip.x()-10,_centerShip.y()+10);
    QPointF qPoint22 = QPointF(_centerShip.x()-20,_centerShip.y()+5);
    QPointF qPoint23 = QPointF(_centerShip.x()-20,_centerShip.y()+10);
    QPointF qPoint24 = QPointF(_centerShip.x()-30,_centerShip.y()+10);
    QPointF qPoint25 = QPointF(_centerShip.x()-30,_centerShip.y()-10);
    QPointF qPoint26 = QPointF(_centerShip.x()-25,_centerShip.y()-10);
    QPointF qPoint27 = QPointF(_centerShip.x()-25,_centerShip.y()-30);
    QPointF qPoint28 = QPointF(_centerShip.x()-25,_centerShip.y()-10);
    QPointF qPoint29 = QPointF(_centerShip.x()-20,_centerShip.y()-10);
    QPointF qPoint30 = QPointF(_centerShip.x()-20,_centerShip.y());
    QPointF qPoint31 = QPointF(_centerShip.x()-15,_centerShip.y());
    QPointF qPoint32 = QPointF(_centerShip.x()-15,_centerShip.y()-15);
    QPointF qPoint33 = QPointF(_centerShip.x()-15,_centerShip.y());
    QPointF qPoint34 = QPointF(_centerShip.x()-10,_centerShip.y());
    QPointF qPoint35 = QPointF(_centerShip.x(),_centerShip.y()-35);


    _points << _sommet << qPoint1 << qPoint2 << qPoint3 << qPoint4 << qPoint5 << qPoint6 << qPoint7 << qPoint8 << qPoint9 << qPoint10
                                  << qPoint11 << qPoint12 << qPoint13 << qPoint14 << qPoint15 << qPoint16 << qPoint17 << qPoint18 << qPoint19 << qPoint20
                                     << qPoint21 << qPoint22 << qPoint23 << qPoint24 << qPoint25 << qPoint26 << qPoint27 << qPoint28 << qPoint29 << qPoint30
                                        << qPoint31 << qPoint32 << qPoint33 << qPoint34 << qPoint35;
}

Ship::~Ship(){
    qDebug()<< "destructeur vaisseau";
    _points.clear();//Destroy the polygon of space ship
}

void Ship::accelerate(){



    QTransform transform;
    int xSommet=_sommet.x();
    int ySommet=_sommet.y();
    int xCenter=_centerShip.x();
    int yCenter=_centerShip.y();


    transform=transform.translate((xSommet-xCenter)*this->speed,(ySommet-yCenter)*this->speed);

    _points=transform.map(_points);
    _centerShip=transform.map(_centerShip);
    _sommet=transform.map(_sommet);



}

void Ship::incrementSpeed(){
    if(this->speed < 3){
        this->speed = this->speed + 0.2;
    }
}

void Ship::reDrawShip(const QSize &size){

    QTransform transform;
    int xSommet=_sommet.x();
    int ySommet=_sommet.y();
    int xCenter=_centerShip.x();
    int yCenter=_centerShip.y();


    //Detect if center of user ship is out of screen
    //Right side
    if(_centerShip.x() > size.width()){
        //qDebug() << "RIGHT OUT";
        transform=transform.translate(xSommet-xCenter-size.width(),ySommet-yCenter);
    }
    //Left side
    else if(_centerShip.x() < 0){
        //qDebug() << "LEFT OUT";
        transform=transform.translate(xSommet-xCenter+size.width(),ySommet-yCenter);
    }
    //Bottom side
    else if(_centerShip.y() > size.height()){
        transform=transform.translate(xSommet-xCenter,ySommet-yCenter-size.height());
    }
    //Top side
    else if(_centerShip.y() < 0){
        transform=transform.translate(xSommet-xCenter,ySommet-yCenter+size.height());
    }
    //Map the polygon
    _points=transform.map(_points);
    _centerShip=transform.map(_centerShip);
    _sommet=transform.map(_sommet);
}

void Ship::killShotOutOfScreen(const QSize &size){
    for(auto i = 0;i<_shotQPoint.size();i++){
        if(_shotQPoint.at(i)->detectOutOfScreen(size)){
            qDebug() << "ERASE SHOT FROM VECTOR";
            _shotQPoint.erase(_shotQPoint.begin()+i);
        }
    }
}

void Ship::rotate(string direction){

    //qDebug() << "Rotate ...";

    const int angle = (direction == "right") ? 5 : -5;


    int xCenter=_centerShip.x();
    int yCenter=_centerShip.y();

    QTransform trans;
    trans.translate(xCenter,yCenter);
    trans.rotate(angle);
    trans.translate(-xCenter,-yCenter);

    _points=trans.map(_points);
    _sommet=trans.map(_sommet);
}


void Ship::destroy(){
    _points.clear();
}

void Ship::slowDown(){

    this->speed = 0;
    /*if(this->speed >= 0.2){
        this->speed = this->speed - 0.2;
    }*/
}

Weapon* Ship::getWeapon(){
    return _shipWeapon;
}

QPolygonF Ship::getPolygon(){
    return _points;
}

QPoint* Ship::getSommet(){
    return &_sommet;
}

QPoint Ship::getCenter(){
    return _centerShip;
}

vector<Shot*> Ship::getShotsVector(){
    return this->_shotQPoint;
}

void Ship::createShot(){
    int x = _sommet.x();
    int y = _sommet.y();
    QPoint pointShot(x,y);
    _shotQPoint.push_back(new Shot(pointShot,_centerShip));
}


bool Ship::getIsShooting(){
    return _isShooting;
}

void Ship::setIsShooting(bool result){
    _isShooting = result;
}

