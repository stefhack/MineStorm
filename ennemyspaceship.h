#ifndef ENNEMYSPACESHIP_H
#define ENNEMYSPACESHIP_H

#include <QPolygon>
#include <QPainter>
/**
 * @brief The EnnemySpaceShip class, represent the ennemy space ship which fill mines into gameboard
 */
class EnnemySpaceShip
{
public:
    /**
     * @brief EnnemySpaceShip constructor of EnnemySpaceShip object
     */
    EnnemySpaceShip();
    /**
      * @brief ~EnnemySpaceShip destructor of EnnemySpaceShip object
      */
    ~EnnemySpaceShip();
    /**
     * @brief getPolygon, get the ennemy space ship QPolygon
     * @return QPolygon, the ennemy space ship polygon
     */
    QPolygon getPolygon();
    /**
     * @brief fileMines is used to fill the gameboard with mines
     */
    void fileMines();
    /**
     * @brief initShip, construction of the ennemy space ship Polygon
     */
    void initShip();
    /**
     * @brief move, used to move the annemy space ship accrosthe gameboard
     */
    void move();
    /**
     * @brief getCenter, return a QPoint which is the center of ennemy space ship polygon
     * @return, QPoint center of enney space ship Polygon
     */
    QPoint getCenter();
    /**
     * @brief destroy, destroy the polygon
     */
    void destroy();
private:
    /**
     * @brief _centerEnnemySpaceShip, private attribute Qpoint center of ennemy space ship
     */
    QPoint _centerEnnemySpaceShip;
    /**
     * @brief _pointsEnnemySpaceShip, private attribute Is the ennemy space ship polygon
     */
    QPolygon _pointsEnnemySpaceShip;
};

#endif // ENNEMYSPACESHIP_H
