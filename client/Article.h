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
    Article(string articleId,string name,string context,string createTime,string modifiedTime)
    {
        this->articleId=articleId;
        this->name=name;
        this->context=context;
        this->createTime=createTime;
        this->modifiedTime=modifiedTime;
    }
    ~Article(){}
};
#endif