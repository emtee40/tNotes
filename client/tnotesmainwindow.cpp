#include <QDesktopWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSizePolicy>
#include <QGroupBox>
#include <QSplitter>
#include <QPushButton>
#include <QSize>
#include <QIcon>
#include <QDate>

#include "tnotesmainwindow.h"
#include "tnotestexteditor.h"
#include "tnotessearchtool.h"
#include "tnotesbutton.h"
#include "tnoteslogindialog.h"

#include "tnotestitlebar.h"
#include "tnotestoolbar.h"
#include "tnotescontentwidget.h"
#include "tnotesstatusbar.h"
#include "Operation.h"



tNotesMainWindow::tNotesMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
	/* set window size */

	setMainWindowsSize();
    setWindowFlags(Qt::FramelessWindowHint);
	/* initialization */
    initWidgets();
    setMouseTracking(true);

	setMainWindowLayout();
    pointValid(1, 2);
	setupActions();
}

tNotesMainWindow::~tNotesMainWindow()
{


}




void tNotesMainWindow::setMainWindowsSize()
{
    QDesktopWidget dw;
    int x = dw.width()*0.8;
    int y = dw.height()*0.8;
    //this->resize(950, 600);
    this->resize(x, y);
}

void tNotesMainWindow::initWidgets()
{

    currentDir = new Directory();

    titleBar = new tNotesTitleBar();
    toolBar = new tNotesToolBar();
    contentWidget = new tNotesContentWidget();
    statusBar = new tNotesStatusBar();
    dialogLogin = new tNotesLoginDialog();

}

void tNotesMainWindow::setMainWindowLayout()
{	
	centralWidget = new QWidget;

	this->setCentralWidget(centralWidget);


    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(titleBar);
    mainLayout->addWidget(toolBar, 2);
    mainLayout->addWidget(contentWidget, 10);
    mainLayout->addWidget(statusBar, 2);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

	centralWidget->setLayout(mainLayout);
}


void tNotesMainWindow::setupActions()
{
    connect(toolBar, SIGNAL(openLoginDialog()), this, SLOT(openLoginDialog()));
    connect(dialogLogin, SIGNAL(acceptLogin(QString&,QString&,int&)), this, SLOT(userAuthenticated(QString&,QString&,int&)));
//    connect(buttonNewNotebook, SIGNAL(clicked()), this, SLOT(createDirectory()));
//    connect(buttonSettings, SIGNAL(clicked()), this, SLOT(saveArticle()));
}

void tNotesMainWindow::userAuthenticated(QString &username, QString &pass, int &index)
{
    initNotesByUser(username);
}

void tNotesMainWindow::openLoginDialog()
{

	dialogLogin->exec();
}

bool tNotesMainWindow::createDirectory()
{
    currentDir->name = "foo";
    currentDir->modifiedTime = q2s(QDate::currentDate().toString("yyyy.MM.dd"));
    currentDir->createTime = q2s(QDate::currentDate().toString("yyyy.MM.dd"));
    currentDir->isSyn = true;
    createRoot(*currentDir);
    return true;
}

bool tNotesMainWindow::saveArticle()
{
    currentArticle->context = "helloworld!";
    currentArticle->name = "bar";
    currentArticle->createTime = q2s(QDate::currentDate().toString("yyyy.MM.dd"));
    currentArticle->createTime = q2s(QDate::currentDate().toString("yyyy.MM.dd"));
    currentArticle->isSyn = true;
    createArticle("foo", *currentArticle);
}


void tNotesMainWindow::initNotesByUser(QString &name)
{
    print(name);
    emit initNotebooks(currentDir);
}

void tNotesMainWindow::pointValid(int x, int y)
{

    QRect qrTemp = geometry();
    int x1, x2, y1, y2;
    qrTemp.getCoords(&x1, &x2, &y1, &y2);
}

