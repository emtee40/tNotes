#ifndef TNOTESCATEGORYLIST_H
#define TNOTESCATEGORYLIST_H

#include <QtGui> 
#include <QListView>
#include <string>

class tNotesCategoryList :public QListView
{  
public:  
    tNotesCategoryList();
	void mouseDoubleClickEvent(QMouseEvent *event);   //�������Ӧ
private:
	//QStandardItemModel��һ������;��model,�����ڱ�ʾlist,table,tree views����Ҫ�ĸ��ֲ�ͬ�����ݽṹ��
	QStandardItemModel *model;
};

#endif
