#ifndef MYLISTVIEW_H2
#define MYLISTVIEW_H2

#include <QtGui> 
#include <QListView>
#include <string>

class MyListView2 :public QListView
{  
public:  
	QIcon qic;
	MyListView2();
	void mouseDoubleClickEvent(QMouseEvent *event);   //�������Ӧ

	//QStandardItemModel��һ������;��model,�����ڱ�ʾlist,table,tree views����Ҫ�ĸ��ֲ�ͬ�����ݽṹ��
	QStandardItemModel *model;
};

#endif