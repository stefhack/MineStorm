#ifndef LIFECOUNTER_H
#define LIFECOUNTER_H
#include <QPainter>

using namespace std;
/**
 * @brief The LifeCounter class is the class used to count and display the lifes of the user
 */
class LifeCounter
{
public:
    /**
     * @brief LifeCounter constructor of LifeCounter object
     */
    LifeCounter();
    /**
     * @brief decrement, decrement the total life number by 1
     */
    void decrement();
    /**
     * @brief drawLifeOnGameBoard used to display the user lifes
     * @param painter used to draw the text
     * @param size used to know where to put the text into the gameboard
     */
    void drawLifeOnGameBoard(QPainter &painter,const QSize &size);
    /**
     * @brief getLifes return the total number of lifes
     * @return integer
     */
    int getLifes();
    /**
     * @brief setLifes, used to set the number of lifes
     * @param nbLives, integer
     */
    void setLifes(int nbLives);
private:
    /**
     * @brief _lifes, private attribute, used to store lifes as int
     */
    int _lifes;
};

#endif // LIFECOUNTER_H
