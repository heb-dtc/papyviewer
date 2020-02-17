#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "RegionItem.cpp"

#include <QMainWindow>
#include <QGraphicsItem>
#include <QRubberBand>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool eventFilter(QObject *obj, QEvent *event) override;

protected:
    QImage image = QImage("/Users/flow/Desktop/ours-chauvet.jpg");

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *baseImageView;
    QGraphicsPixmapItem *region;
    RegionItem *regionItem;

    bool drawingActive;
    QPoint origin;
    QRubberBand *rubberBand;

};
#endif // MAINWINDOW_H
