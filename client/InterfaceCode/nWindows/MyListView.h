#ifndef MYLISTVIEW_H
#define MYLISTVIEW_H

#include <QtGui> 
#include <QListView>
#include <string>

class MyListView :public QListView
{  
public:  
	QBrush qbr;
	QIcon qic;
	MyListView();
	void mouseDoubleClickEvent(QMouseEvent *event);   //�������Ӧ

	//QStandardItemModel��һ������;��model,�����ڱ�ʾlist,table,tree views����Ҫ�ĸ��ֲ�ͬ�����ݽṹ��
	QStandardItemModel *model;
};

#endif