#include <QtGui> 
#include <QGroupBox>
#include <string>
extern QString s2q( const std::string &s);
extern std::string q2s(const QString &s);
class GroupBox :public QGroupBox
{  
public:
	GroupBox();
	void mouseDoubleClickEvent(QMouseEvent *event);   //�������Ӧ
private:
	//QStandardItemModel��һ������;��model,�����ڱ�ʾlist,table,tree views����Ҫ�ĸ��ֲ�ͬ�����ݽṹ��
	QStandardItemModel *model;
};