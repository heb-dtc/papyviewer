#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>
#include <QPainter>
#include <QPaintEvent>
#include <QRect>
#include <QGraphicsScene>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->viewport()->installEventFilter(this);

    QPixmap img("/Users/flow/Desktop/ours-chauvet.jpg");
    baseImageView = scene->addPixmap(img);
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->graphicsView->viewport())
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            qDebug() << "MouseButtonPress on graphic view";

            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            origin = mouseEvent->pos();

            if (!rubberBand)
            {
                rubberBand = new QRubberBand(QRubberBand::Rectangle, ui->graphicsView);
            }
            rubberBand->setGeometry(QRect(origin, QSize()));
            rubberBand->show();
            return true;
        }

        if (event->type() == QEvent::MouseMove)
        {
            qDebug() << "MouseMove on graphic view";

            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            rubberBand->setGeometry(QRect(origin, mouseEvent->pos()).normalized());
            return true;
        }

        if (event->type() == QEvent::MouseButtonRelease)
        {
            QImage selectedRegion = image.copy(rubberBand->geometry());
            auto bla = scene->addPixmap(QPixmap::fromImage(selectedRegion));
            this->regionItem = new RegionItem(bla);
            rubberBand->hide();

            return true;
        }
    }

    return false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

