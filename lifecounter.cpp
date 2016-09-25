#include "lifecounter.h"
#include <string>
/**
 * @brief LifeCounter::LifeCounter constructor, the life counter is initialize to 4
 */
LifeCounter::LifeCounter()
{
    _lifes = 4;
}
/**
 * @brief LifeCounter::decrement allow to decrement the counter
 */
void LifeCounter::decrement(){
    if(_lifes > 0){
        --_lifes;
    }
}
/**
 * @brief LifeCounter::drawLifeOnGameBoard
 * @param painter
 * @param size
 */
void LifeCounter::drawLifeOnGameBoard(QPainter &painter,const QSize &size){
    //Set font
    QFont font=painter.font() ;
    font.setPointSize (12);
    painter.setFont(font);
    //Convert int to Qstring
    QString qLifes = QString("Lifes : %1").arg(_lifes);

    //Then draw it into the gameboard
    painter.drawText(QPoint(size.width() - 70,size.height() - 20),qLifes);
}

int LifeCounter::getLifes(){
    return _lifes;
}

void LifeCounter::setLifes(int nbLives){
    _lifes=nbLives;
}
