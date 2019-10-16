#include "mainwindow.h"
#include "QPushButton"
#include "QHBoxLayout"
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
   QHBoxLayout *mainLayout = new QHBoxLayout;

   QPushButton *dialogRunButton = new QPushButton("Dialog");
   QWidget *mainWidget = new QWidget(this);
   mainLayout->addWidget(dialogRunButton);

   mainWidget->setLayout(mainLayout);
   setCentralWidget(mainWidget);
   connect(dialogRunButton,&QPushButton::clicked, [&] () {

       Dialog m_dialog(this);
       m_dialog.show();
       m_dialog.exec();

   });

}

MainWindow::~MainWindow()
{
}

