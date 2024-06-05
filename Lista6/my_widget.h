///
/// Miejsce na copyright :-)
///

#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <vector>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    constexpr static double DEFAULT_RADIUS = 75.0;  // Promień kółek, w pikselach

    explicit MyWidget(QWidget *parent = nullptr);       // Konstruktor
    void paintEvent(QPaintEvent *event) override;       // Obsługuje zdarzenie repaint(), czyli "odmaluj swój wygląd"
    void mousePressEvent(QMouseEvent *event) override;  // Obsługuje zdarzenia myszy
    void keyPressEvent(QKeyEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    struct Circle
    {
        QPointF center;  // QPointF to punkt o współrzędnych zmiennopozycyjnych, stąd `F` na końcu nazwy
        double radius;
        QColor color = QColor(rand() % 256, rand() % 256, rand() % 256);
    };

signals:   // Ten program nie definiuje własnych sygnałów, dlatego ta sekcja jest pusta

private:
    std::vector<Circle> circles;  // Tu przechowujemy "wyklikane" obiekty
    bool isPointInCircle(const QPointF &point, const Circle &circle) const;
};

#endif  // MYWIDGET_H
