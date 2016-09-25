#ifndef DUMMYGAME_H
#define DUMMYGAME_H
#include "game.h"

#include <QPoint>
#include <QBrush>
#include <vector>
using namespace std;
/**
 * @brief La classe DummyGame donne un exemple de l'utilisation de la classe Game
 */
class DummyGame : public Game
{
    Q_OBJECT
public:
    DummyGame(const QSize &size,QObject *parent = nullptr);
    virtual void draw(QPainter &painter, QRect &rect);
    void mousePressed( int x, int y);
    void keyPressed( int key );
    void keyReleased( int key );
private:
    virtual void step();
    void initialize();
    void addEllipse( int x, int y, Qt::BrushStyle style = Qt::SolidPattern);

    vector<QPoint> _points;
    vector<int> _pointsSize;
    vector<QColor> _pointsColor;
    vector<Qt::BrushStyle> _pointsPattern;
    Qt::BrushStyle _currentStyle;
};

#endif // DUMMYGAME_H
