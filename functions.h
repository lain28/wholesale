#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QMainWindow>
#include <QStackedWidget>
#include <iostream>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //implemented functions

private:
    Ui::MainWindow *ui;

    //implemented functions
    void login();  //slot to handle login
    void mainMenu();  //slot to handle menu options

    //implemented variables
    QStackedWidget *stackedWidget; //widget to switch between pages
    QWidget *loginPage;
    QWidget *menuPage;
};


#endif // FUNCTIONS_H
