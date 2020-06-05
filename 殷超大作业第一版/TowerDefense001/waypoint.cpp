#include "waypoint.h"

#include <QPainter>
#include <QColor>

WayPoint::WayPoint(QPoint pos)
    : _pos(pos)
    , _nextWayPoint(NULL)
{
}

void WayPoint::setNextWayPoint(WayPoint *nextPoint)
{
    _nextWayPoint = nextPoint;
}

WayPoint* WayPoint::nextWayPoint() const
{
    return _nextWayPoint;
}

const QPoint WayPoint::pos() const
{
    return _pos;
}
