#ifndef SHOT_H
#define SHOT_H
#include <QPolygon>

using namespace std;
/**
 * @brief The Shot class represents a shot
 */
class Shot
{
public:
    /**
     * @brief Shot, Shot constructor
     * @param shotPoint, a QPoint which represents the shot
     * @param centerShip, QPoint the center ship
     */
    Shot(QPoint shotPoint,QPoint centerShip);
    /**
      * @brief ~Shot, Shot destructor
      */
    ~Shot();
    /**
     * @brief hatch, used to hatch a shot
     */
    void hatch();
    /**
     * @brief getShot, get the Shot QPoint
     * @return QPoint
     */
    QPoint* getShot();
    /**
     * @brief reDrawShot, used to re draw a shot
     */
    void reDrawShot();
    /**
     * @brief getPolygon, used to get the Shot QPolygon
     * @return QPolygon
     */
    QPolygon getPolygon();
    /**
     * @brief detectOutOfScreen, used to know if a shot is out of screen
     * @return boolean, true if it is out of creen, else false
     */
    bool detectOutOfScreen(const QSize &size);
private:
    /**
     * @brief _shotPoint, Shot QPolygon
     */
    QPolygon _shotPoint;
    /**
     * @brief _centerShot, QPoint center of Shot
     */
    QPoint _centerShot;
    /**
     * @brief _centerShip QPoint center of Ship
     */
    QPoint _centerShip;
    bool _isShooting=false;
};

#endif // SHOT_H
