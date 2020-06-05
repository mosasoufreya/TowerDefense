#ifndef WAYPOINT_H
#define WAYPOINT_H
#include <QPoint>

class QPainter;

class WayPoint
{
public:
        WayPoint(QPoint pos);

        void setNextWayPoint(WayPoint *nextPoint);
        WayPoint* nextWayPoint() const;
        const QPoint pos() const;

private:
        const QPoint _pos;
        WayPoint *_nextWayPoint;
};

#endif // WAYPOINT_H
