#include "MyQItemDelegate.h"


MyQItemDelegate::MyQItemDelegate(void)
{
}


MyQItemDelegate::~MyQItemDelegate(void)
{
}
void MyQItemDelegate::paint(QPainter*painter,const QStyleOptionViewItem&option, const QModelIndex&index)const  
{  
	QStyleOptionViewItem myOption=option; 
	QFont qf(s2q("΢���ź�"));
	QFont qfNormal(s2q("΢���ź�"));
	qf.setPixelSize(14);
	qf.setBold(true);


	QString content = index.model()->data(index, Qt::DisplayRole).toString(); // ȡ��ģ����ԭ��������

    QString qstrName=content;
	QString qstrDate=s2q("2014/3/14");
	QString qstrContent=s2q("1��2��3��4��5��6����7��8��9����10����11����12����13����14����15����16������17��������������������������1��2��3��4��5��6����7��8��9����10����11����1��2��3��4��5��6����7��8��9����10����11����");

	QRect drawRectTextName=QRect(option.rect.topLeft(), QSize(option.rect.size().width()/2,option.rect.size().height()/4));
	QRect drawRectTextDate=QRect(option.rect.topLeft()+QPoint(option.rect.size().width()/2,0), QSize(option.rect.size().width()/2,option.rect.size().height()/4));

	QRect drawRectTextContent=QRect(option.rect.topLeft()+QPoint(0,option.rect.size().height()/4), QSize(option.rect.size().width(),option.rect.size().height()*3/4));

	QTextOption qto;
	painter->setFont(qf);
	painter->setPen(QColor(23,48,5));
	painter->drawText(drawRectTextName, qstrName);

	painter->setFont(qfNormal);
	painter->setPen(Qt::darkGreen);
	painter->drawText(drawRectTextDate, qstrDate);

	painter->setFont(qfNormal);
	painter->setPen(Qt::black);
	painter->drawText(drawRectTextContent, qstrContent);

	painter->setPen(Qt::darkGreen);
	painter->drawLine(option.rect.bottomLeft(),option.rect.bottomRight());


	myOption.displayAlignment = Qt::AlignRight | Qt::AlignVCenter; // �����ı��Ķ��뷽ʽ (����Ҫ)  
	drawFocus(painter,option,option.rect);  
}  



void MyQItemDelegate::updateEditorGeometry( QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index ) const
{
	editor->setGeometry(option.rect);  
}

void MyQItemDelegate::drawFocus( QPainter *painter, const QStyleOptionViewItem &option, const QRect &rect ) const
{
	//����пؼ���ѡ�У����Ǿ���ѡ�еĿؼ�����
	if (option.state & QStyle::State_Selected){
		painter->setBrush(QBrush(QColor(157,206,122,122)));
		painter->setPen(QColor(157,206,122,122));
		painter->drawRect(rect);
		painter->setBrush(Qt::NoBrush);
		painter->setPen(Qt::darkGreen);
		painter->drawRect(rect);
	}
}
