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
bool createArticle(string iRoot,Article art);     //�������£�����Ŀ¼������������
bool deleteRoot(string index);         //ɾ��Ŀ¼������Ŀ¼����
bool deleteArticle(string iRoot,string iArticle); //ɾ�����£�����Ŀ¼����������
vector<Directory> searchAllRoot();//��������Ŀ¼������Ŀ¼�б�
vector<Article> searchRootArticle(string iRoot);  //����ĳ��Ŀ¼���������£�����Ŀ¼���������������б�
vector<Article> searchAllArticle();  //������������
Article searchArticle(string iRoot,string iArticle);  //����ĳ��Ŀ¼���ض����£�����Ŀ¼����������������������
Json::Value returnRoot();  //����json�����ļ������ļ������ڣ�����null
bool writeInJson(Json::Value root);         //д��json�ļ�
#endif