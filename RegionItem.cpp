#include<QDebug>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

class RegionItem : public QGraphicsPixmapItem
{
public:
    RegionItem(QGraphicsItem *parent = nullptr)
        : QGraphicsPixmapItem(parent)
    {
        setFlags(QGraphicsItem::ItemIsMovable
                 |QGraphicsItem::ItemIsFocusable
                 |QGraphicsItem::ItemIsSelectable);
        setEnabled(true);
    }

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event)
    {
        if(event->button() == Qt::LeftButton) {
            if(event->modifiers() == Qt::ShiftModifier) {
                qDebug() << "Custom item left clicked with shift key.";
                // add the item to the selection
                setSelected(true);
            } else {
                qDebug() << "Custom item left clicked.";
                QGraphicsItem::mousePressEvent(event);
                event->accept();
            }
        } else if(event->button() == Qt::RightButton) {
            qDebug() << "Custom item right clicked.";
            event->ignore();
        }
    }

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event)
    {
        if(event->modifiers() != Qt::AltModifier) {
            qDebug() << "Custom item moved.";
            QGraphicsItem::mouseMoveEvent(event);
            qDebug()<<"moved"<<pos();
        }
    }

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
    {
        if(event->modifiers() != Qt::ShiftModifier) {
            QGraphicsItem::mouseReleaseEvent(event);
        }
    }

    int type() const
    {
        // Enable the use of qgraphicsitem_cast with this item.
        return UserType+1;
    }

private:
    QPointF _center;
};
