#include <QtGui> 
#include <QTreeView>
#include "nwindows.h"
class TreeView :public QTreeView  
{  
public:  
	TreeView();
	void iterateOverItems();
	QList<QStandardItem*> returnTheItems();
	void mouseDoubleClickEvent(QMouseEvent *event);   //�������Ӧ
private:
	//QStandardItemModel��һ������;��model,�����ڱ�ʾlist,table,tree views����Ҫ�ĸ��ֲ�ͬ�����ݽṹ��
	QStandardItemModel *model;
};