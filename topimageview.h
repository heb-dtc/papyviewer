#ifndef TOPIMAGEVIEW_H
#define TOPIMAGEVIEW_H

#include <QGraphicsScene>
#include <QRubberBand>

class TopImageView : public QGraphicsScene
{
    Q_OBJECT

public:
    TopImageView(QObject *parent = nullptr);
    ~TopImageView();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QPoint origin;
    QRubberBand *rubberBand;
};

#endif // TOPIMAGEVIEW_H
