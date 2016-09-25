#include "pointscounter.h"
/**
 * @brief PointsCounter::PointsCounter constructor, points are initialize to 0
 */
PointsCounter::PointsCounter()
{
    _points = 0;
}

/**
 * @brief PointsCounter::increment, increment the points counter
 */
void PointsCounter::increment(bool ennemyShip){
    if(ennemyShip==true){
        _points += 100;
    }
    else{
        _points += 10;
    }
}

void PointsCounter::drawPointsIntoGameBoard(QPainter &painter,const QSize &size){
    //Set font
    QFont font=painter.font() ;
    font.setPointSize (12);
    painter.setFont(font);
    //Convert int to Qstring
    QString qPoints = QString("Points : %1").arg(_points);

    //Then draw it into the gameboard
    painter.drawText(QPoint(10,(size.height() - 20)),qPoints);
}


void PointsCounter::setPoint(int points){
    _points=points;
}
