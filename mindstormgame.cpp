#include "mindstormgame.h"
#include <QPainter>
#include <QRect>
#include <QColor>
#include <QDebug>
#include <stdlib.h>
#include <memory>

using namespace std;
//Define the pen used to draw all elements in the game
QPen thePen;
MindStormGame::MindStormGame(const QSize &size,QObject *parent):Game(size,parent) {
    //Initialize the pen
    thePen.setColor(Qt::blue);
    thePen.setStyle(Qt::SolidLine);
    thePen.setWidth(2);
    //Loop counter is initialize to 0
    loopCounter = 0;
    //Loop counter for hacth mine is initialize to 0
    loopCounterHatchMines = 0;
    //Loop counter for ennemyship initialize to 0
    loopCounterEnnemyShip=0;

    //User space ship initialization
    _userShip=new Ship();
    //User space Ennemy ship initialization
    _EnnemyShip=new EnnemySpaceShip();
    //Build mines
    buildMines(30);
    _lifecounter = new LifeCounter();
    _pointcounter = new PointsCounter();
    //connect(minesTimer,SIGNAL(timeout()),this,SLOT(test()));
    //minesTimer->start(1000);
}

void MindStormGame::moveMines(int counter){
    for(auto i=0;i<counter;++i){
        try{
            _mines.at(i)->move();
        }
        catch (const std::out_of_range& error) {
            qDebug() << "Out of Range error from moveMoines: " << error.what() << '\n';
        }
    }
}

void MindStormGame::buildMines(int nbMines){
    for(auto i=0;i<nbMines;++i){
        auto x = rand() %size().width();
        auto y = rand() %size().height();
        try{
        //Add a mine in mines vector
        _mines.push_back(new Mine(QPoint(x,y),i));
        //_mines.push_back(make_unique<Mine>(QPoint(x,y),i));

        }
        catch (const std::out_of_range& error) {
            qDebug() << "Out of Range error from buildMines: " << error.what() << '\n';
        }
    }
}

void MindStormGame::draw(QPainter &painter, QRect &rect){
    //Antialiasing on painter
    painter.setRenderHint(QPainter::Antialiasing);
    //Set the painter pen
    painter.setPen(thePen);
    //Fill the background of the game board
    painter.fillRect(rect, QColor(0,0,0));

    //Ennemyship appear and dispose mines only if in screen
    if((_EnnemyShip->getCenter().y() < size().height())&&(loopCounter==0)){
        disposeEnnemyShip(painter);
        _EnnemyShip->move();
        //Fill mines
        disposeMines(painter);
    }
    //When Ennemy ship clear, the game start
    else{
        //Increment the loop counter for passage ennemyship
        if(loopCounterEnnemyShip <600){
            ++loopCounterEnnemyShip;
        }

        if(loopCounterEnnemyShip == 600){
            buildMines(5);
            // Innitialize ennemy ship
            _EnnemyShip->initShip();
        }
        if(_EnnemyShip->getCenter().y() < size().height() ){
            disposeEnnemyShip(painter);
            _EnnemyShip->move();
            loopCounterEnnemyShip = 0;
        }

        //Increment the loop counter
        if(loopCounter <(100*_mines.size())){
            ++loopCounter;
        }

        //Hatch each mines at 2.5 seconds (100 loops)
        if((loopCounter % 50 == 0)&&(loopCounterHatchMines<_mines.size())){
            ++loopCounterHatchMines;
        }
        hatchMines(painter,loopCounterHatchMines);
        moveMines(loopCounterHatchMines);




        //Fill mines
        disposeMines(painter);
        //Fille user space ship
        disposeUserShip(painter);
        //Used to display lifes of user
        _lifecounter->drawLifeOnGameBoard(painter,size());
        //Used to display the score of the user
        _pointcounter->drawPointsIntoGameBoard(painter,size());

        if(_userShip->getIsShooting()==true){
            _userShip->createShot();
        }
        disposeShot(painter);
        //End of game
        if(_lifecounter->getLifes() == 0 ){

            showEndofGame(painter,rect);
            pause();
        }

        //Draw explosions of mine and ship
        if(!_explosion.empty()){
            painter.drawPolygon(_explosion);
            _explosion.clear();
        }
    }
}


void MindStormGame::disposeShot(QPainter &painter){
   // qDebug()<< "Nb shots : "<<_userShip->getShotsVector().size();
    for(auto i=0;i<_userShip->getShotsVector().size();++i){
        painter.drawPolygon(_userShip->getShotsVector().at(i)->getPolygon());
        _userShip->getShotsVector().at(i)->reDrawShot();
        //used to kill a shot if it is out of screen
        _userShip->killShotOutOfScreen(size());
    }
}


void MindStormGame::hatchMines(QPainter &painter, int counter){
    //Hatch each mine
    for(auto i=0;i<counter;++i){
        try{
        //"Remove" the center point by drawing the point in black
        thePen.setColor(Qt::black);
        painter.setPen(thePen);
        QPointF point(_mines.at(i)->getCenter()->x(),_mines.at(i)->getCenter()->y());
        painter.drawPoint(point);
        //Then hatch mines in blue
        thePen.setColor(Qt::blue);
        painter.setPen(thePen);
        _mines.at(i)->hatch();
        painter.drawPolygon(_mines.at(i)->getPolygon());
        //Used to detect out of screen
        _mines.at(i)->reDrawMine(size());
        }
        catch (const std::out_of_range& error) {
            qDebug() << "Out of Range error from hatchMines " << error.what() << '\n';
        }
    }
}

void MindStormGame::disposeUserShip(QPainter &painter){
    QPolygonF polygon=_userShip->getPolygon();
    painter.setBrush(Qt::blue);
    painter.drawPolygon(polygon,Qt::WindingFill);
    _userShip->reDrawShip(size());
}

void MindStormGame::disposeEnnemyShip(QPainter &painter){
    QPolygon polygon=_EnnemyShip->getPolygon();
    painter.setBrush(Qt::blue);
    painter.drawPolygon(polygon,Qt::WindingFill);
}


void MindStormGame::blastPolygon(QPoint center){
    QPoint qPoint = QPoint(center.x()+40,center.y());
    QPoint qPoint1 = QPoint(center.x(),center.y());
    QPoint qPoint2 = QPoint(center.x()+30,center.y()-30);
    QPoint qPoint3 = QPoint(center.x(),center.y());
    QPoint qPoint4 = QPoint(center.x(),center.y()-40);
    QPoint qPoint5 = QPoint(center.x(),center.y());
    QPoint qPoint6 = QPoint(center.x()-30,center.y()-30);
    QPoint qPoint7 = QPoint(center.x(),center.y());
    QPoint qPoint8 = QPoint(center.x()-40,center.y());
    QPoint qPoint9 = QPoint(center.x(),center.y());
    QPoint qPoint10 = QPoint(center.x()-30,center.y()+30);
    QPoint qPoint11 = QPoint(center.x(),center.y());
    QPoint qPoint12 = QPoint(center.x(),center.y()+40);
    QPoint qPoint13 = QPoint(center.x(),center.y());
    QPoint qPoint14 = QPoint(center.x()+30,center.y()+30);
    QPoint qPoint15 = QPoint(center.x(),center.y());
    _explosion << qPoint << qPoint1 << qPoint2 << qPoint3 << qPoint4 << qPoint5 << qPoint6 << qPoint7 << qPoint8 << qPoint9 << qPoint10 << qPoint11 << qPoint12 << qPoint13 << qPoint14 << qPoint15;
    //qDebug() << "BOOOOOMMMMMMM";
}

void MindStormGame::mousePressed( int x, int y){

}

void MindStormGame::keyPressed( int key ){
    // qDebug() << "KEY PRESSED " << key;
    switch(key) {
    case Qt::Key_Up: _userShip->incrementSpeed();
        break;
    case Qt::Key_Down: _userShip->slowDown();
        break;
    case Qt::Key_Left: _userShip->rotate("left");
        break;
    case Qt::Key_Right: _userShip->rotate("right");
        break;
    case Qt::Key_Space: _userShip->setIsShooting(true);
        break;
    default:
        break;
    }

}

void MindStormGame::showEndofGame(QPainter &painter,QRect &rect)
{
    //Fill the background of the game board
    painter.fillRect(rect, QColor(0,0,0));
    //Set font
    QFont font=painter.font() ;
    font.setPointSize (32);
    painter.setFont(font);

    //Then draw it into the gameboard
    painter.drawText(QPoint((size().width()/3),(size().height()/2)),"GAME OVER");
}





void MindStormGame::disposeMines(QPainter &painter){
    //For each mines, drawing a point according
    //to its center
    for(auto i=0;i<_mines.size();++i){
        try{
        if((_mines.at(i)->getCenter()->y()) < (_EnnemyShip->getCenter().y())){
            QPointF point(_mines.at(i)->getCenter()->x(),_mines.at(i)->getCenter()->y());
            painter.drawPoint(point);
        }
        }
        catch (const std::out_of_range& error) {
            qDebug() << "Out of Range error disposeMines: " << error.what() << '\n';
        }
    }
}




void MindStormGame::keyReleased( QKeyEvent * event){

    switch(event->key()) {
    case Qt::Key_Up:
        //qDebug() << "KEY UP...";
        //If the event handled isn't an autorepeat event
        //Decelerate the ship
        if(!event->isAutoRepeat()){
            _userShip->slowDown();
        }
        break;
    case Qt::Key_Space:_userShip->setIsShooting(false);//End of shots
        break;
    }
}

void MindStormGame::step(){
    if(loopCounter!=0){
        QPolygon polyShip=_EnnemyShip->getPolygon();
        if(hasCollision(polyShip)){
            qDebug() << "Collision";
            _userShip->destroy();
            _EnnemyShip->destroy();
            blastPolygon(_userShip->getCenter());
            blastPolygon(_EnnemyShip->getCenter());
            //Decrement the life number
            _lifecounter->decrement();
            samePlayerPlayAgain();
        }
    }
    for(auto i=0;i<_mines.size();++i){
        QPolygon poly=_mines.at(i)->getPolygon();
        //Case with collision between ship and mine
        if(hasCollision(poly)){
            try{
            qDebug() << "Collision";
            _userShip->destroy();
            QPoint centerShip = _userShip->getCenter();
            blastPolygon(centerShip);
            _mines.at(i)->destroy();
            //Construction center of the to blast mine
            QPoint centerMine = QPoint(_mines.at(i)->getCenter()->x(),_mines.at(i)->getCenter()->y());
            blastPolygon(centerMine);
            //Decrement the life number
            _lifecounter->decrement();
            //Init the ship
            //_userShip->initShip();
            samePlayerPlayAgain();
            }
            catch (const std::out_of_range& error) {
                qDebug() << "Out of Range error step->hasCollision: " << error.what() << '\n';
            }
        }

        //Case with collision between one shot and mine or ennemy ship
        for(auto z=0;z<_userShip->getShotsVector().size();++z)
        {
            if(isShot(_userShip->getShotsVector().at(z)->getPolygon(),_mines.at(i)->getPolygon()))
            {
                QPoint centerMine = QPoint(_mines.at(i)->getCenter()->x(),_mines.at(i)->getCenter()->y());
                blastPolygon(centerMine);
                _mines.at(i)->destroy();
                //Erase mine from vector
                try {
                    qDebug()<< "ERASE MINE FROM VECTOR";
                    qDebug()<< "Nb mines avant : "<<_mines.size();
                    //vector<Mine*>* mines=&_mines;
                    if(_mines.begin()+i != _mines.end()){
                        _mines.erase(_mines.begin()+i);
                        --loopCounterHatchMines;
                        --loopCounter;
                    }
                     qDebug()<< "Nb mines aprés : "<<_mines.size();
                }
                catch (const std::out_of_range& error) {
                    qDebug() << "Out of Range error: " << error.what() << '\n';
                }

                //Incrément points counter
                _pointcounter->increment(false);
            }
            //Ennemy ship
            if(isShot(_userShip->getShotsVector().at(z)->getPolygon(),_EnnemyShip->getPolygon())){
                blastPolygon(_EnnemyShip->getCenter());
                _EnnemyShip->destroy();
                //Incrément points counter
                _pointcounter->increment(true);
            }
        }
    }
    _userShip->accelerate();
}

bool MindStormGame::hasCollision(QPolygon &poly)
{

    bool retour = false;
    //Collision between ship and mines
    QPolygonF intersection=_userShip->getPolygon().intersected(poly);
    if(!intersection.isEmpty()){
        retour = true;
    }
    return retour;
}

bool MindStormGame::isShot(QPolygon shoot,QPolygon mineOrEnnemy){
    bool isShot=false;
    QPolygon intersect=shoot.intersected(mineOrEnnemy);
    if(!intersect.isEmpty()){
        isShot=true;
    }
    return isShot;
}


void MindStormGame::resetPlace(){
    _mines.clear();
    _userShip=nullptr;
    loopCounter=0;
    loopCounterHatchMines=0;
    loopCounterEnnemyShip=0;
    _userShip=new Ship();    
    buildMines(30);
}
void MindStormGame::samePlayerPlayAgain(){  
    resetPlace();
    _pointcounter->setPoint(0);
}

void MindStormGame::initialize(){
    _EnnemyShip=nullptr;
    resetPlace();
    _EnnemyShip=new EnnemySpaceShip();
    _lifecounter->setLifes(4);
    _pointcounter->setPoint(0);

}
