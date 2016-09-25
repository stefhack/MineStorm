#ifndef POINTSCOUNTER_H
#define POINTSCOUNTER_H
#include <QPainter>
using namespace std;
/**
 * @brief The PointsCounter class represents the Point counter into the game board
 */
class PointsCounter
{
public:
    /**
     * @brief PointsCounter, constructor of PointsCounter object
     */
    PointsCounter();
    /**
     * @brief increment, used to increment the counter
     * @param ennemyShip, used to know if ennemyship is destroy
     */
    void increment(bool ennemyShip);
    /**
     * @brief drawPointsIntoGameBoard, used to draw the counter into the gameboard
     * @param painter, used to draw
     * @param size, used to place the counter
     */
    void drawPointsIntoGameBoard(QPainter &painter,const QSize &size);
    /**
     * @brief setPoint, used to set points
     * @param points
     */
    void setPoint(int points);
private:
    /**
     * @brief _points
     */
    int _points;
};

#endif // POINTSCOUNTER_H
