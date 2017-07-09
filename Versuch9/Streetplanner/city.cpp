#include "city.h"

City::City(QString name, int x, int y) : name(name), x(x), y(y)
{

}

void City::draw(QGraphicsScene& scene) const
{
    qDebug() << "Drawing city %1.\n".arg(this.name);
    QGraphicsTextItem* text = new QGraphicsTextItem;
    text->setPos(this->x-25, this->y-30);
    text->setPlainText(this->name);
    scene.addItem(text);
    scene.addEllipse(this->x-1, this->y-1, 4.0, 4.0, QPen(Qt::red), QBrush(Qt::SolidPattern));
    return;
}
