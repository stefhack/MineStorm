#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QWidget>
#include <QSet>
class Game;
/**
 * @brief La class GameBoard définit un widget permettant l'affichage d'un
 * jeu. Elle gère également les évènements souris et clavier
 */
class GameBoard : public QWidget
{
    Q_OBJECT
public:
    explicit GameBoard(Game *game,QWidget *parent = 0);

signals:

public slots:


protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent ( QMouseEvent * event );
    void keyPressEvent ( QKeyEvent * event );
    void keyReleaseEvent ( QKeyEvent * event );
    /**
     * @brief eventFilter Handle multi-touch events, used to stack events
     * @param obj
     * @param event
     * @return boolean value
     */
    bool eventFilter(QObject * obj, QEvent * event);
    QSet<int> pressedKeys;
    QSet<int>::iterator iterator;
private:
    Game *_game;
};

#endif // GAMEBOARD_H
