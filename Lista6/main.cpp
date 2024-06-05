#include "mainwindow.h"

#include <QApplication>

///
/// \brief main - standardowa funkcja `main()` w Qt, wygenerowana przez QtCreator.
/// \param argc - wiadomo
/// \param argv - wiadomo
/// \return - stan końcowy aplikcaji (0 = EXIT_SUCCESS)
///
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
