#ifndef TESTGAME_H
#define TESTGAME_H
#include "mine.h"
#include "game.h"
#include "ship.h"
#include "vector"
#include "lifecounter.h"
#include "pointscounter.h"
#include "ennemyspaceship.h"
#include "memory"
#include <QPaintEvent>
#include <QTimer>

using namespace std;
/**
 * @brief The MindStormGame class, normally named MineStormGame, is the game classe
 */
class MindStormGame:public Game
{

public:
    /**
     * @brief MindStormGame constructor of MindStormGame
     * @param size, size of the gameboard
     * @param parent
     */
    MindStormGame(const QSize &size,QObject *parent = nullptr);
    /**
     * @brief draw, used to draw everything into the gameboard for each loop
     * @param painter, a painter which is used to paint polygons
     * @param rect, the gameboard rectangle
     */
    virtual void draw(QPainter &painter, QRect &rect);
    /**
     * @brief mousePressed used to handle mouse pressed events
     * @param x, the x point
     * @param y, the y point
     */
    void mousePressed( int x, int y);
    /**
     * @brief keyPressed, used to handle a key pressed
     * @param key, int
     */
    void keyPressed( int key );
    /**
     * @brief keyReleased, used to handle a jey release
     * @param event
     */
    void keyReleased( QKeyEvent * event);
    /**
     * @brief hasCollision, detect collision between ship and mines
     * @param mine
     * @return
     */
    bool hasCollision(QPolygon &poly);
    /**
     * @brief isMineShot, detect collision between mine and shot
     * @param mine, a mine QPolygon
     * @param shot, a Shot QPolygon
     * @return true if there is a collission, false if there isn't
     */
    bool isShot(QPolygon shoot,QPolygon mineOrEnnemy);

private:
    /**
     * @brief hatchMines, used to draw mines hatched
     * @param painter, the game painter
     * @param counter, a logical loop counter
     */
    void hatchMines(QPainter &painter,int counter);
    /**
     * @brief step, used to make action for each loop, like detection of collisions
     */
    virtual void step();
    /**
     * @brief initialize used to initialize the game
     * Inititlize the ship, mines, life and points counters
     */
    void initialize();

    /**
     * @brief disposeShot, used to draw shots
     * @param painter, the game painter
     */
    void disposeShot(QPainter &painter);
    /**
     * @brief disposeOldMines, used to dispose mines into the gameboard
     * @param painter, the game painter
     */
    void disposeMines(QPainter &painter);
    /**
     * @brief disposeUserShip, draw the user ship polygon with the painter
     * @param painter, the game painter
     */
    void disposeUserShip(QPainter &painter);
    /**
     * @brief disposeEnnemyShip, draw ennemy ship polygon with the painter
     * @param painter, the game painter
     */
    void disposeEnnemyShip(QPainter &painter);
    /**
     * @brief showEndofGame, used to show end of game
     * @param painter, the game painter
     * @param rect, Gameboard QRect
     */
    void showEndofGame(QPainter &painter,QRect &rect);
    /**
     * @brief resetPlace, used to reset the game
     */
    void resetPlace();
    /**
     * @brief samePlayerPlayAgain, used to play again if life >0
     */
    void samePlayerPlayAgain();
    /**
     * @brief buildMines, used to build all mines into the gameboard
     */
    void buildMines(int nbMines);
    /**
     * @brief moveMines, say to mines for move
     * @param counter, logical loop counter
     */
    void moveMines(int counter);
    /**
     * @brief blastPolygon used to blast the ship or a mine
     * @param QPoint
     */
    void blastPolygon(QPoint center);
    /**
     * @brief _userShip, the user ship object
     */
    Ship *_userShip;
    /**
     * @brief _shot, the user ship shots
     */
    Shot *_shot;

    /**
     * @brief _EnnemyShip, the ennemy space ship object
     */
    EnnemySpaceShip *_EnnemyShip;
    /**
     * @brief _mines array vector of mines present into gameboard
     */
    vector<Mine*> _mines;
    /**
     * @brief _lifecounter, lifeCounter object, used to handle user lifes
     */
    LifeCounter *_lifecounter;
    /**
     * @brief _pointcounter pointCounter object, used to handle user points
     */
    PointsCounter *_pointcounter;
    /**
     * @brief _explosion, QPolygon, used to blast ship and mines
     */
    QPolygon _explosion;
    /**
     * @brief loopCounter, logical loop counter
     */
    int loopCounter;
    /**
     * @brief loopCounterHatchMines, logical loop counter
     */
    int loopCounterHatchMines;
    /**
     * @brief loopCounterEnnemyShip, logical loop counter
     */
    int loopCounterEnnemyShip;
};

#endif // TESTGAME_H
