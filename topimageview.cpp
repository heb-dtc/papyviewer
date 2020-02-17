#include "topimageview.h"

TopImageView::TopImageView(QObject *parent)
    : QGraphicsScene(parent)
{

}

void TopImageView::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        origin = event->pos();

        if (!rubberBand)
        {
            rubberBand = new QRubberBand(QRubberBand::Rectangle, ui->graphicsView);
        }
        rubberBand->setGeometry(QRect(origin, QSize()));
        rubberBand->show();
    }
}

void TopImageView::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton))
    {
        rubberBand->setGeometry(QRect(origin, event->pos()).normalized());
    }
}

void TopImageView::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

}
