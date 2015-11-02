#ifndef BABYPEDESTRIAN_H
#define BABYPEDESTRIAN_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class BabyPedestrian: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    BabyPedestrian(QGraphicsItem * parent =0);
    ~BabyPedestrian();
    virtual double getMaxRange();
    virtual double getDistanceCrawled();
    virtual void setMaxRange(double range);
    virtual void setDistanceCrawled(double dist);
    virtual void setCrawlSpeed(int speed);
    virtual int  getCrawlSpeed();
    virtual void crawl();
public slots:
    virtual void move();
private:
    double maxRange;
    double distanceTravelled;
    int speed; //to be changed for control via window
};

#endif // BABYPEDESTRIAN_H
