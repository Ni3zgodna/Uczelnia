#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
, ui(new Ui::MainWindow)
{
    this->Wylacz = true;
    ui->setupUi(this);

    connect(ui->action_Koniec, SIGNAL(triggered()), this, SLOT(koniec_programu()));
    connect(ui->przycisk, SIGNAL(clicked()), this, SLOT(Ikona()));

    ui->przycisk->setIcon(QIcon(":/img/media-playback-pause.png"));
 //   connect(ui->przycisk, SIGNAL(clicked()), ui->widget, SLOT(toggle_animation()));
}

void MainWindow::Ikona()
{
    this->Wylacz = !this->Wylacz;
    if (this->Wylacz)
    {
        ui->przycisk->setIcon(QIcon(":/img/media-playback-pause.png"));
    }
    else
    {
        ui->przycisk->setIcon(QIcon(":/img/media-playback-start.png"));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::koniec_programu()
{
    bool Pytanie = QMessageBox::question(this, "Pytanie", "Czy napewno?", "Nie", "Tak", "");
        if(Pytanie)
            qApp->quit();
}


void MainWindow::on_action_O_programie_triggered()
{
    QMessageBox::aboutQt(this,"O wspaniałym programie");
}
