#include "nwindows.h"



//************************************
//ȫ�ֺ���  ����QString string��ת  �ļ���ȡ��QSS��
//************************************
QString s2q( const std::string &s) 
{ 
	return QString(QString::fromLocal8Bit(s.c_str())); 
}
std::string q2s( const QString &s) 
{ 
	return std::string((const char *)s.toLocal8Bit()); 
}
QString readFile(std::string filePath)
{
	std::ifstream file(filePath);
	std::string strTemp((std::istreambuf_iterator<char>(file)),  
		std::istreambuf_iterator<char>());  
	return s2q(strTemp);
}

//************************************
//���캯��������
//************************************
nWindows::nWindows(QWidget *parent)
	: QFrame(parent)
{
	//���ô��ڴ�С  ����
	setMainWindowsSize();
	setWindowFlags(Qt::FramelessWindowHint);
	setMouseTracking(true);

	//����������
	m_TitleBar = new MyTitleBar(this);
	//����������
	m_ToolBar = new MyToolBar(this);
	//������������
	m_ContentWidget = new MyContentWidget();
	//����״̬��
	m_StatusBar = new MyStatusBar();
	//��������
	m_pMainLayout = new QVBoxLayout(this);
	//���������뵽������
	m_pMainLayout->addWidget(m_TitleBar);
	m_pMainLayout->addWidget(m_ToolBar,2);
	m_pMainLayout->addWidget(m_ContentWidget,10);
	m_pMainLayout->addWidget(m_StatusBar,2);
	//���ü�����Ե�հ�
	m_pMainLayout->setSpacing(0);
	m_pMainLayout->setContentsMargins(0,0,0,0);

	//m_TitleBar  ��Ӧ����
	connect(m_TitleBar->maxmizeButton, SIGNAL(clicked()), this, SLOT(showMaxRestore()));
	connect(m_TitleBar->minimizeButton, SIGNAL(clicked()), this, SLOT(showMinimized()));
	connect(m_TitleBar->closeButton, SIGNAL(clicked()), this, SLOT(close()));
	//m_ToolBar  ��Ӧ����
	connect(m_ToolBar->loginButton, SIGNAL(clicked()), this, SLOT(login()));
	connect(m_ToolBar->newFileButton, SIGNAL(clicked()), this, SLOT(newFile()));
	connect(m_ToolBar->deleteFileButton, SIGNAL(clicked()), this, SLOT(deleteFile()));
	connect(m_ToolBar->sysButton, SIGNAL(clicked()), this, SLOT(synchronized()));
	connect(m_ToolBar->searchButton, SIGNAL(clicked()), this, SLOT(searchNote()));

	//mListView  ��Ӧ����
	connect(m_ContentWidget->mListView, SIGNAL(clicked(QModelIndex)),
		this, SLOT(clicked(QModelIndex)));

	//mListView2  ��Ӧ����
	connect(m_ContentWidget->mListView2, SIGNAL(clicked(QModelIndex)),
		this, SLOT(clicke(QModelIndex)));

	MyListView *mylistviewTemp1 = m_ContentWidget->mListView;
	MyListView2 *mylistviewTemp2 = m_ContentWidget->mListView2;
	//��ʼ������
	dirVector1 = searchAllRoot();
	for (int i=0;i<dirVector1.size();i++)
	{
		QStandardItem *itemTemp=new QStandardItem(s2q(dirVector1[i].name));
		itemTemp->setSizeHint(QSize(150,40));
		itemTemp->setIcon(mylistviewTemp1->qic);
		itemTemp->setBackground(mylistviewTemp1->qbr);
		mylistviewTemp1->model->appendRow(itemTemp);
	}


	MyQItemDelegate *myqit=new MyQItemDelegate();
	mylistviewTemp2->setItemDelegate(myqit);

	vector<Article> dir2Vector = searchRootArticle(dirVector1[0].nodeId);
	for (int i=0;i<dir2Vector.size();i++)
	{
		QStandardItem *itemTemp=new QStandardItem(s2q(dir2Vector[i].name));
		itemTemp->setSizeHint(QSize(150,70));
		mylistviewTemp2->model->appendRow(itemTemp);
	}
}

nWindows::~nWindows()
{
	
}


//************************************
// �������ڴ�С�ĺ���
//************************************
void nWindows::setMainWindowsSize(){
	QDesktopWidget dw;
	int x = dw.width()*0.8;
	int y = dw.height()*0.8;
	this->resize(x, y);
}
void nWindows::showSmall()
{
	showMinimized();
}
void nWindows::showMaxRestore()
{
	if (m_TitleBar->maxNormal) {
		showNormal();
		m_TitleBar->maxNormal = !(m_TitleBar->maxNormal);
		m_TitleBar->maxmizeButton->setIcon(m_TitleBar->maxPix);
	} else {
		showMaximized();
		m_TitleBar->maxNormal = !(this->m_TitleBar->maxNormal);
		m_TitleBar->maxmizeButton->setIcon(m_TitleBar->restorePix);
	}
}


//************************************
//  ����������ť�ȵ���Ӧ����
//************************************

/////////////������////////////////
//��½
void nWindows::login()
{
	QDialog qd;
	qd.show();
}
//�����µ��ļ�
void nWindows::newFile()
{
	MyListView*mlist1 = m_ContentWidget->mListView;
	
	QStandardItem *itemTemp=new QStandardItem(s2q("�±ʼǱ�"));  ;
	itemTemp->setIcon(mlist1->qic);
	itemTemp->setBackground(mlist1->qbr);

	mlist1->model->appendRow(itemTemp);
}
//ɾ���ļ�
void nWindows::deleteFile()
{
	MyListView*mlist1 = m_ContentWidget->mListView;
	
}
//ͬ���ļ�
void nWindows::synchronized()
{
	QDialog qd;
	qd.show();
}
//�����ļ�
void nWindows::searchNote()
{
	
}


/////////////�༭��////////////////
//���尴ť
void nWindows::editBoldButton()
{
	QDialog qd;
	qd.show();
}
//�»��߰�ť
void nWindows::editUnderLineButton()
{
	QDialog qd;
	qd.show();
}



/////////////�ʼǱ���ListView1��ͼ��Ӧ����////////////////

//�����QModelIndex��
void nWindows::clicked(const QModelIndex &index){
	QDialog qd;
	qd.show();
}

/////////////�ʼǱ�ListView2��ͼ��Ӧ����////////////////
void nWindows::clicke(const QModelIndex &index){
	QDialog qd;
	qd.show();
}