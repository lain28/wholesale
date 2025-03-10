#include "functions.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //create a stacked widget
    stackedWidget = new QStackedWidget(this);
    setCentralWidget(stackedWidget);

    //create login page
    loginPage = new QWidget();
    QVBoxLayout *loginLayout = new QVBoxLayout(loginPage);

    QLabel *loginLabel = new QLabel("Enter username:");
    QLineEdit *usernameInput = new QLineEdit();
    QPushButton *loginButton = new QPushButton("Login");

    loginLayout->addWidget(loginLabel);
    loginLayout->addWidget(usernameInput);
    loginLayout->addWidget(loginButton);

    stackedWidget->addWidget(loginPage);

    //create menu page
    menuPage = new QWidget();
    QVBoxLayout *menuLayout = new QVBoxLayout(menuPage);

    QLabel *menuLabel = new QLabel("Main Menu");
    QPushButton *menuOption1 = new QPushButton("Option 1");
    QPushButton *menuOption2 = new QPushButton("Option 2");
    QPushButton *logoutButton = new QPushButton("Logout");

    menuLayout->addWidget(menuLabel);
    menuLayout->addWidget(menuOption1);
    menuLayout->addWidget(menuOption2);
    menuLayout->addWidget(logoutButton);

    stackedWidget->addWidget(menuPage);

    //connect login button
    connect(loginButton, &QPushButton::clicked, this, &MainWindow::login);
    connect(menuOption1, &QPushButton::clicked, this, &MainWindow::mainMenu);
    connect(menuOption2, &QPushButton::clicked, this, &MainWindow::mainMenu);
    connect(logoutButton, &QPushButton::clicked, [=]() {
        stackedWidget->setCurrentWidget(loginPage);
    });

    //start on the login page
    stackedWidget->setCurrentWidget(loginPage);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::login()
{
    //find the QLineEdit from the login page
    QLineEdit *usernameInput = loginPage->findChild<QLineEdit *>();

    if (!usernameInput) {
        QMessageBox::critical(this, "Error", "Login input field not found!");
        return;
    }

    //get the text from the input field
    QString username = usernameInput->text().trimmed();  // Trim to remove spaces

    if (username.isEmpty()) {
        //show an error message and stay on the login page
        QMessageBox::warning(this, "Login Failed", "Username cannot be empty.");
        return;
    }

    //if input is valid, proceed to the main menu
    stackedWidget->setCurrentWidget(menuPage);
    QMessageBox::information(this, "Login", "Login Successful!");
}


void MainWindow::mainMenu()
{
    QMessageBox::information(this, "Menu", "You selected a menu option.");
}


