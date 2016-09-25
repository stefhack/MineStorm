#ifndef MINE_H
#define MINE_H

#include <QPolygon>

using namespace std;
/**
 * @brief The Mine class represents mine objects
 */
class Mine
{
public:
    /**
     * @brief Mine Constructor
     * @param qPointRand an x,y random point
     * @param compteur, a loop counter
     */
    Mine(QPoint qPointRand,int &compteur);
    /**
      * @brief Mine Destructor
      */
    ~Mine();
    /**
     * @brief getPolygon, get Mines Polygon
     * @return QPolygon
     */
    QPolygon getPolygon();
    /**
     * @brief reDrawMine used to re-draw the mine whan it's out of screen
     */
    void reDrawMine(const QSize &size);
    /**
     * @brief hatch, make the mines hatchs
     */
    void hatch();
    /**
     * @brief destroy, destroy mine Polygon
     */
    void destroy();
    /**
     * @brief move, move the mine according to its direction
     */
    void move();
    /**
     * @brief getType, get mine type 1 : little, 2 : middle, 3 great
     * @return Integer 1 : little, 2 : middle, 3 great
     */
    int getType();
    /**
     * @brief getCenter, get the QPoint center of specific mine
     * @return QPoint
     */
    QPoint* getCenter();
    /**
     * @brief setCenter, set the QPoint center of a specific mine
     * @param center
     */
    void setCenter(QPoint center);
    /**
     * @brief state
     */
    string state;
    /**
     * @brief _direction, mine direction
     */
    QPoint _direction;
    /**
     * @brief getRandomDirection, used to get a random direction for mine (x,y)
     */
    void getRandomDirection();
private:
    /**
     * @brief QPolygon _points, represents the mine polygon
     */
    QPolygon _points;
    /**
     * @brief QPoint _center, represents the center point of mine
     */
    QPoint _center;
    /**
     * @brief _sommet, represents the sommet point of mine
     */
    QPoint _sommet;
    int _x;
    int _y;
    /**
     * @brief mineType, 1 : little, 2 : middle, 3 great
     */
    int mineType;
    /**
     * @brief The _mineType enum, mine type
     */
    enum _mineType {
        small,
        meduim,
        large,
        Num_Count
    };
    /**
     * @brief direction, direction of mine by x axis
     */
    int direction_x;
    /**
     * @brief direction_y, direction of mine by Y axis
     */
    int direction_y;
};

#endif // MINE_H
