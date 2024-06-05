#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_Zakoncz_triggered();     // menu "Zakończ"

    void on_action_O_programie_triggered(); // menu "O programie"

private:
    Ui::MainWindow *ui;                     // Graficzny interfejs uzytkownika; zwykle definiowany ("klikany") w QtCreator
};
#endif  // MAINWINDOW_H
