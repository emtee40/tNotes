/*
     ��̨������ Operation
     ��������ɾ�������
*/
#include "json/json.h"
#include "Article.h"
#include "Directory.h"
#include<vector>
#include<algorithm>
#ifndef OPERATION_H
#define OPERATION_H
bool createRoot(Directory dir);        //����Ŀ¼������Ŀ¼��
bool createArticle(int iRoot,Article art);     //�������£�����Ŀ¼������������
bool deleteRoot(int index);         //ɾ��Ŀ¼������Ŀ¼����
bool deleteArticle(int iRoot,int iArticle); //ɾ�����£�����Ŀ¼����������
vector<Directory> searchAllRoot();//��������Ŀ¼������Ŀ¼�б�
vector<Article> searchAllArticle(int iRoot);  //����ĳ��Ŀ¼���������£�����Ŀ¼���������������б�
Article searchArticle(int iRoot,int iArticle);  //����ĳ��Ŀ¼���ض����£�����Ŀ¼����������������������
#endif