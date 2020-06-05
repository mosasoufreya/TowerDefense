#include "towerposition.h"
#include <QPainter>

const QSize TowerPosition::_fixedSize(144, 92);

TowerPosition::TowerPosition(QPoint pos, const QPixmap & picture)
    : _hasTower(false)
    , _hasShow(false)
    , _pos(pos)
    , _picture(picture)
{
}

void TowerPosition::setHasTower(bool hasTower)
{
    _hasTower = hasTower;
}

bool TowerPosition::hasTower() const
{
    return _hasTower;
}

bool TowerPosition::hasShow() const
{
    return _hasShow;
}

void TowerPosition::setHasShow(bool hasShow)
{
    _hasShow = hasShow;
}

bool TowerPosition::inRange(const QPoint &pos) const
{
    bool inX = (this->_pos.x() < pos.x()) && (pos.x() < this->_pos.x() + _fixedSize.width());
    bool inY = (this->_pos.y() < pos.y()) && (pos.y() < this->_pos.y() + _fixedSize.height());
    return inX && inY;
}

QPoint TowerPosition::getPos()
{
    QPoint Pos(this->_pos.x() + this->_fixedSize.width() / 2 - 3, this->_pos.y() + this->_fixedSize.height() / 2 - 20);
    return Pos;
}

void TowerPosition::drawer(QPainter *painter) const
{
    painter->drawPixmap(_pos.x(), _pos.y(), _fixedSize.width(), _fixedSize.height(),this->_picture);
}

