#include "my_widget.h"

#include <QPainter>

MyWidget::MyWidget(QWidget* parent)  //
    : QWidget(parent), timer(this)
{
    timer.start(timer_interval);
    connect(&timer, SIGNAL(timeout()), this, SLOT(on_timer()));
}

void MyWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(QBrush(QColor(Qt::GlobalColor::gray)));
    auto r = this->rect();
    painter.drawRect(r);

    painter.setBrush(QBrush(QColor(Qt::GlobalColor::black)));
    painter.drawText(rect().width() / 2.0, rect().height() / 2.0, "X");


    painter.setBrush(QBrush(QColor(Qt::GlobalColor::magenta)));
    painter.translate(rect().width() / 2.0, rect().height() / 2.0);
    auto side = std::min(rect().width(), rect().height());
    painter.scale(side / 300.0, side / 300.0);
    painter.setPen(Qt::NoPen);
    for (int i = 0; i < num_disks; i++)
    {
        if (i != hidden)
        {
            painter.drawEllipse(-30, 90, 40, 40);
        }
        painter.rotate(360.0 / num_disks);
    }
}

void MyWidget::on_timer()
{
    hidden = (hidden + 1) % num_disks;
    update();
}

void MyWidget::toggle_animation()
{
    if (timer.isActive())
        timer.stop();
    else
        timer.start(timer_interval);
}
