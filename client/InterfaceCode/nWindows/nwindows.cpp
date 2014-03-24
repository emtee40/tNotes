#include "nwindows.h"
#include <string>
#include <QString>
#include <QRect>
QString s2q( const std::string &s) 
{ 
	return QString(QString::fromLocal8Bit(s.c_str())); 
}
std::string q2s( const QString &s) 
{ 
	return std::string((const char *)s.toLocal8Bit()); 
}

nWindows::nWindows(QWidget *parent)
	: QFrame(parent)
{
	setMainWindowsSize();
	//setWindowFlags(Qt::CustomizeWindowHint); 
	//setWindowFlags(Qt::Window|Qt::FramelessWindowHint|Qt::WindowTitleHint);
	setWindowFlags(Qt::FramelessWindowHint);
	setMouseTracking(true);

	//����������
	m_TitleBar = new MyTitleBar(this);
	//����������
	m_ToolBar = new MyToolBar();
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
	PointValid(1,2);
}

nWindows::~nWindows()
{
	
}

void nWindows::setMainWindowsSize(){
	QDesktopWidget dw;
	int x = dw.width()*0.8;
	int y = dw.height()*0.8;
	this->resize(x, y);

	//setGeometry(dw.availableGeometry());
}

//	QPoint m_ptPressGlobal;
//	bool m_bLeftBtnPress;
//	m_eDirection
//	//��갴���¼�
//	void MainWindow::mousePressEvent(QMouseEvent * event)
//{
//	
//	if (event ->button() == Qt::LeftButton)
//	{
//		m_ptPressGlobal = event ->globalPos();
//		m_bLeftBtnPress = true ;
//	}
//}
////����ƶ��¼�
//void MainWindow::mouseMoveEvent(QMouseEvent * event)
//{
//	
//	if (!m_bLeftBtnPress)
//	{
//		m_eDirection = PointValid( event ->x(),event ->y());
//		SetCursorStyle(m_eDirection);
//	}
//	else
//	{
//		int nXGlobal = event ->globalX();
//		int nYGlobal = event ->globalY();
//		SetDrayMove(nXGlobal,nYGlobal,m_eDirection);
//		m_ptPressGlobal =QPoint(nXGlobal,nYGlobal);
//	}
//}
////����ͷ��¼�
//void MainWindow::mouseReleaseEvent(QMouseEvent * event)
//{
//	if (event ->button() == Qt::LeftButton)
//	{
//		m_bLeftBtnPress = false ;
//		m_eDirection = eNone;
//	}
//}
////���˫���¼�
//void MainWindow::mouseDoubleClickEvent(QMouseEvent * event)
//{
//	if (event ->button() == Qt::LeftButton && event ->y()<= m_pTitleBar->height())
//	{
//		if (!m_bMaxWin)
//		{
//			m_rectRestoreWindow = geometry();
//			setGeometry(qApp->desktop()->availableGeometry());
//		}
//		else
//		{
//			setGeometry(m_rectRestoreWindow);
//		}
//		m_bMaxWin = !m_bMaxWin;
//	}
//}
//
////���������ʽ
//void MainWindow::SetCursorStyle(enum_Direction direction)
//{
//	//�������������Լ����ϡ����¡����ϡ����µ������״
//	switch (direction)
//	{
//	case eTop:
//	case eBottom:
//		setCursor(Qt::SizeVerCursor);
//		break ;
//	case eRight:
//	case eLeft:
//		setCursor(Qt::SizeHorCursor);
//		break ;
//	case eTopRight:
//	case eBottomLeft:
//		setCursor(Qt::SizeBDiagCursor);
//		break ;
//	case eRightBottom:
//	case eLeftTop:
//		setCursor(Qt::SizeFDiagCursor);
//		break ;
//	default :
//		setCursor(Qt::ArrowCursor);
//		break ;
//	}
//}
//
////��������϶��Ĵ���λ����Ϣ
//void MainWindow::SetDrayMove(int nXGlobal, int nYGlobal,enum_Direction direction)
//{
//	//����ƫ��
//	int ndX = nXGlobal - m_ptPressGlobal.x();
//	int ndY = nYGlobal - m_ptPressGlobal.y();
//	//���������λ����Ϣ
//	QRect rectWindow = geometry();
//	//��D����
//	if (direction & eTop)
//	{
//		rectWindow.setTop(rectWindow.top()+ndY);
//	}
//	if (direction & eRight)
//	{
//		rectWindow.setRight(rectWindow.right()+ndX);
//	}
//	if (direction & eBottom)
//	{
//		rectWindow.setBottom(rectWindow.bottom()+ndY);
//	}
//	if (direction & eLeft)
//	{
//		rectWindow.setLeft(rectWindow.left()+ndX);
//	}
//	if (rectWindow.width()< minimumWidth() || rectWindow.height()<minimumHeight())
//	{
//		return ;
//	}
//	//�������ô���λ��Ϊ��λ����Ϣ
//	setGeometry(rectWindow);
//}
void nWindows::PointValid(int x,int y){
	QRect qrTemp = geometry();
	int x1,x2,y1,y2;
	qrTemp.getCoords(&x1,&x2,&y1,&y2);

}