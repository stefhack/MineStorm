#include "mine.h"
#include <QDebug>
#include <QPainter>
Mine::Mine(QPoint qPointRand, int &compteur)
{

    //Get a random direction
    getRandomDirection();
    //qPointRand central point of a mine
    _center =qPointRand;
    //Determine the mine type (little, middle, great)
    if(compteur < 5){
        mineType = 1;
    }else if(compteur >= 5 && compteur < 25){
        mineType = 2;
    }else if(compteur >= 25 && compteur < 30){
        mineType = 3;
    }

    //Polygon initialize to a point
    _points << _center;
}

void Mine::getRandomDirection(){
    int min = -30;
    int max = 30;
    int newDirection_x = 1;
    int newDirection_y = 1;
    while((newDirection_x == 1 || newDirection_y == 1)){
        newDirection_x = min + (rand() % (int)(max - min + 1)) +1;
        newDirection_y = min + (rand() % (int)(max - min + 1)) +1;
    }

    //Set default direction on x and y for mine
    this->direction_x = newDirection_x;
    this->direction_y = newDirection_y;
}

void Mine::hatch(){
        switch ( mineType ) {
        case 1:
            _x = 7.5;
            _y = 2.5;
            break;
        case 2:
            _x = 15;
            _y = 5;
            break;
        case 3:
            _x = 30;
            _y = 10;
            break;
        }

        //Create tops of mines according to the central point
        _sommet = QPoint(_center.x(),_center.y()+_x);
        QPoint qPointSommetMine2 = QPoint(_center.x()+_y,_center.y()+_y);
        QPoint qPointSommetMine3 = QPoint(_center.x()+_x,_center.y());
        QPoint qPointSommetMine4 = QPoint(_center.x()+_y,_center.y()-_y);
        QPoint qPointSommetMine5 = QPoint(_center.x(),_center.y()-_x);
        QPoint qPointSommetMine6 = QPoint(_center.x()-_y,_center.y()-_y);
        QPoint qPointSommetMine7 = QPoint(_center.x()-_x,_center.y());
        QPoint qPointSommetMine8 = QPoint(_center.x()-_y,_center.y()+_y);
        _points.clear();
        //Create the mine polygon
        _points << _sommet << qPointSommetMine2 << qPointSommetMine3 << qPointSommetMine4 << qPointSommetMine5 << qPointSommetMine6 << qPointSommetMine7 << qPointSommetMine8;
        _direction=QPoint(1,1);
}

void Mine::reDrawMine(const QSize &size){

    QTransform transform;
    int xSommet=_sommet.x();
    int ySommet=_sommet.y();
    int xCenter=_center.x();
    int yCenter=_center.y();


    //Detect if center of mine is out of screen
    //Right side
    if(_center.x() >= size.width()){
       // qDebug() << "MINE RIGHT OUT";
        transform=transform.translate(xSommet-xCenter-size.width(),ySommet-yCenter);
    }
    //Left side
    else if(_center.x() <= 0){
        //qDebug() << "MINE LEFT OUT";
        transform=transform.translate(xSommet-xCenter+size.width(),ySommet-yCenter);
    }
    //Bottom side
    else if(_center.y() > size.height()){
        transform=transform.translate(xSommet-xCenter,ySommet-yCenter-size.height());
    }
    //Top side
    else if(_center.y() < 0){
        transform=transform.translate(xSommet-xCenter,ySommet-yCenter+size.height());
    }
    //Map the polygon
    _points=transform.map(_points);
    _center=transform.map(_center);
    _sommet=transform.map(_sommet);
}

Mine::~Mine(){
    _points.clear();//Destroy the polygon
}

int Mine::getType(){
    return mineType;
}

void Mine::destroy(){
    _points.clear();
    // qDebug() << "destruction mine ! ";
}

QPolygon Mine::getPolygon(){
    return _points;
}

void Mine::move(){
    // qDebug() << "move mine";
    QTransform transform;
    transform = transform.translate(this->direction_x*0.05,this->direction_y*0.05);
    _points=transform.map(_points);
    _center=transform.map(_center);
}

QPoint* Mine::getCenter(){
    return &_center;
}

void Mine::setCenter(QPoint center){
    _center=center;
}
