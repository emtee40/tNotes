/*
     ������ Article
     ��������Ҫ����
*/
#include<string>
using namespace std;
#ifndef ARTICLE_H
#define ARTICLE_H
class Article
{
public:
    string articleId;                //����id,�������ͬ��ʹ��
    string name;                     //���±���
    string context;                  //��������
    string createTime;               //���´���ʱ��
    string modifiedTime;             //�����޸�ʱ��
    bool isSyn;                      //�Ƿ�ͬ�����ƶ�
    Article(string articleId,string name,string context,string createTime,string modifiedTime,bool isSyn)
    {
        this->articleId=articleId;
        this->name=name;
        this->context=context;
        this->createTime=createTime;
        this->modifiedTime=modifiedTime;
        this->isSyn=isSyn;
    }
    Article(){}
    ~Article(){}
};
#endif