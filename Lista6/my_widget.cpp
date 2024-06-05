#include "my_widget.h"
#include <iostream>
#include <QPainter>
#include <QMouseEvent>
#include <QKeyEvent>

MyWidget::MyWidget(QWidget* parent)
    : QWidget(parent)
{
    setFocusPolicy(Qt::StrongFocus);
}

///
/// \brief MyWidget::paintEvent obsługuje zdarzenia systemowe "odrysuj zawartość tego widżetu/okienka"
/// \param event - nieużywany
///
void MyWidget::paintEvent([[maybe_unused]] QPaintEvent* event)
{
    QPainter painter(this); // painter to obiekt odpowiedzialny za pisanie i rysowanie piórem, malowanie pędzlem itp.

    painter.setRenderHint(QPainter::Antialiasing);                   // bajer. Rysunki w tym trybie wyglądają nieco lepiej.
    painter.setBrush(QBrush(QColor(Qt::GlobalColor::darkMagenta)));  // pędzel (brush) maluje duże powierzchnie
    auto r = this->rect();                                           // rect() zwraca prostokąt obszaru roboczy bieżącego okienka
    painter.drawRect(r);                                             // malujemy cały obszar roboczy kolorem darkMagenta


    for (const auto& circ : circles)                                // malujemy wszystkie "wyklikane" kółka
    {
        painter.setBrush(QBrush(QColor(circ.color)));

        QPointF point(circ.center.x() * r.width(), circ.center.y() * r.height());
        painter.drawEllipse(point, circ.radius, circ.radius);  // koło jest przypadkiem szczególnym elipsy
    }
}

///
/// \brief MyWidget::mousePressEvent obsługuje zdarzenia systemowe wygenerowane przyciśnięciem (któregokolwiek) klawisza myszy
/// \param event - parametry zdarzenia (np. położenie kursora myszy w momencie kliknięcia)
///
void MyWidget::mousePressEvent(QMouseEvent* event)
{
        auto pos = event->localPos();           // współrzędne położenia myszy we współrzędnmch obszaru roboczego bieżącego okna
        auto rec = rect();                      // prostokąt obszaru roboczego bieżącego okna
        Circle c;                               // kolejne kółko
        c.radius = DEFAULT_RADIUS;              // w tej wersji programu wszystkie kółka mają ten sam promień
        c.center.setX(pos.x() / rec.width());   // składowa "x" środka kółka
        c.center.setY(pos.y() / rec.height());  // składowa "y" środka kółka
        circles.push_back(c);                   // dodanie kółka na koniec wektora `circles`
        repaint();
}

void MyWidget::keyPressEvent(QKeyEvent* event)
{
    if (event->modifiers() == Qt::ControlModifier && event->key() == Qt::Key_Z)
    {
        if(!circles.empty())
        {
            circles.pop_back();
            repaint();
        }
    }
}

void MyWidget::mouseReleaseEvent(QMouseEvent *event)
{
    for (int i = 0; i < circles.size(); i++)
    {
        circles[i].color = QColor(Qt::GlobalColor::red);
        repaint();
    }
}
