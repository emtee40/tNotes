#include "Operation.h"
#include<fstream>
/************************************************************************/
/* ��json�ļ�������json��                                                                     */
/************************************************************************/
Json::Value returnRoot()
{
    Json::Reader reader;
    Json::Value root;
    ifstream ifs;
    ifs.open("tnote.json");
    reader.parse(ifs,root);
    if(ifs.is_open())
    {
         ifs.close();       
    }
    return root;
}

/************************************************************************/
/* ��json��д��json�ļ������ļ������ڣ��򴴽�һ�����ļ�������Ŀ¼������Ϊ"tnote.json"                                                                     */
/************************************************************************/
bool writeInJson(Json::Value root)
{
    Json::FastWriter writer;
    ofstream ofs;
    ofs.open("tnote.json");
    if(ofs.is_open())
    {
        string json_file = writer.write(root);
        ofs<<json_file;
        ofs.close();
        return 1;
    }
    return 0;
}

/************************************************************************/
/* ������Ŀ¼������Ŀ¼�࣬��Ŀ¼id��Ϊ���������߱༭ʱ�Կͻ���ʱ�����Ϊid��
   �����߱༭�������������id��ʱ���
   �����ɹ�����1�����򷵻�0*/
/************************************************************************/
bool createRoot(Directory dir)
{
    Json::Value root=returnRoot();
    Json::Value d;
    d["name"] = dir.name;
    d["createTime"] = dir.createTime;
    d["modifiedTime"]=dir.modifiedTime;
    d["isSyn"]=dir.isSyn;
   
    
    root[dir.nodeId]=d;
    if(writeInJson(root))return 1;
    else return 0;
}

/************************************************************************/
/* �½����£�����Ŀ¼ID��������
�½�����ֻ�轫ǰ̨��������Ϣ��װ��һ������Ϊ��������
�����ɹ�����1�����򷵻�0
*/
/************************************************************************/
bool createArticle(string iRoot,Article art)
{
    Json::Value root=returnRoot();
    Json::Value a;


    a["context"] = art.context;
    a["name"] = art.name;
    a["createTime"] = art.createTime;
    a["modifiedTime"]=art.modifiedTime;
    a["isSyn"]=art.isSyn;

    root[iRoot]["array"][art.articleId]=a;

    if(writeInJson(root))return 1;
    else return 0;
}

/************************************************************************/
/* ɾ��Ŀ¼������Ŀ¼ID��ɾ����Ŀ¼��Ŀ¼���������£������ɹ�����1�����򷵻�0                                                                     */
/************************************************************************/
bool deleteRoot(string index)
{
    Json::Value root=returnRoot();
    
    root.removeMember(index);
    if(writeInJson(root))return 1;
    else return 0;
}

/************************************************************************/
/* ɾ��ָ��Ŀ¼���ص����£�����Ŀ¼ID������ID   
   �����ɹ�����1�����򷵻�0*/
/************************************************************************/
bool deleteArticle(string iRoot,string iArticle)
{
    Json::Value root=returnRoot();

    root[iRoot]["array"].removeMember(iArticle);


    if(writeInJson(root))return 1;
    else return 0;
}

/************************************************************************/
/* ��������Ŀ¼��Ϣ������Ŀ¼�б���������Ŀ¼���򷵻�һ�����б�                                                                     */
/************************************************************************/
vector<Directory> searchAllRoot()
{
    Json::Value root=returnRoot();
    vector<string> listRoot=root.getMemberNames();
    vector<Directory> allRoot;
    Directory obj;
    string nodeId;
    for(int i=0;i<(int)listRoot.size();i++)
    {
        nodeId=listRoot[i];
        obj.nodeId=nodeId;
        obj.createTime=root[nodeId]["createTime"].asString();
        obj.name=root[nodeId]["name"].asString();
        obj.modifiedTime=root[nodeId]["modifiedTime"].asString();
        obj.isSyn=root[nodeId]["isSyn"].asBool();
        allRoot.push_back(obj);
    }

    return allRoot;
}

/************************************************************************/
/* �����ض�Ŀ¼���������£�����Ŀ¼ID�����������б�����Ŀ¼�������£�����һ�����б�                                                                     */
/************************************************************************/
vector<Article> searchRootArticle(string iRoot)
{
    Json::Value root=returnRoot();
    Json::Value allArticle=root[iRoot]["array"];
    vector<string> listRootArticle=allArticle.getMemberNames();
    vector<Article> allRootArticle;
    Article obj;
    string articleId;
    for(int i=0;i<(int)listRootArticle.size();i++)
    {
        articleId=listRootArticle[i];
        obj.articleId=articleId;
        obj.createTime=allArticle[articleId]["createTime"].asString();
        obj.name=allArticle[articleId]["name"].asString();
        obj.modifiedTime=allArticle[articleId]["modifiedTime"].asString();
        obj.isSyn=allArticle[articleId]["isSyn"].asBool();
        obj.context=allArticle[articleId]["context"].asString();
        allRootArticle.push_back(obj);
    }

    return allRootArticle;
}

/************************************************************************/
/* �����������£�ǰ̨�������ã��������������б��������£����ؿն���                                                                     */
/************************************************************************/
vector<Article> searchAllArticle()
{
    Json::Value root=returnRoot();
    vector<string>listRoot=root.getMemberNames();
    vector<Article>allArticle;
    vector<Article>rootArticle;
    vector<Article>::iterator it;
    for(int i=0;i<(int)listRoot.size();i++)
    {
        it=allArticle.end();
        rootArticle=searchRootArticle(listRoot[i]);
        allArticle.insert(it,rootArticle.begin(),rootArticle.end());

    }
 
    return allArticle;
}

/************************************************************************/
/* �����ض�Ŀ¼���ض����£�����Ŀ¼ID������ID�����������࣬���޸����£����ؿն���                                                                     */
/************************************************************************/
Article searchArticle(string iRoot,string iArticle)
{
    Json::Value root=returnRoot();
    Json::Value art=root[iRoot]["array"][iArticle];
    Article article;
    if(!art.isNull())
    {
       
        article.articleId=iArticle;
        article.context=art["context"].asString();
        article.name=art["name"].asString();
        article.createTime=art["createTime"].asString();
        article.modifiedTime=art["modifiedTime"].asString();
        article.isSyn=art["isSyn"].asBool();
      
    }
    return article;
}

/************************************************************************/
/* �޸�Ŀ¼,����Ŀ¼����ID��ʱ����� 
   ����ԭĿ¼ID����Ŀ¼��
   �����ҵ�ԭĿ¼���򷵻�1�����򷵻�0
/************************************************************************/
bool changeRoot(string iRoot ,Directory dir)
{
    Json::Value root=returnRoot();
    Json::Value obj=root[iRoot];
    if(!obj.isNull())
    {
        
        obj["name"]=dir.name;
        obj["createTime"]=dir.createTime;
        obj["isSyn"]=dir.isSyn;
        obj["modifiedTime"]=dir.modifiedTime;       
        if(dir.nodeId!=iRoot)
        {
            root.removeMember(iRoot);
           
        }
        root[dir.nodeId]=obj;
        writeInJson(root);
        return 1;
    }
    else return 0;
   
}

/************************************************************************/
/* �޸�����,������������ID��ʱ��������ݡ� 
   ����ԭ��������Ŀ¼ID��ԭ����ID����������
   �����ҵ�ԭ���£��򷵻�1�����򷵻�0
/************************************************************************/
bool changeArticle(string iRoot,string iArticle,Article art)
{
    Json::Value root=returnRoot();
    Json::Value obj=root[iRoot]["array"][iArticle];
    if(!obj.isNull())
    {
       
        obj["name"]=art.name;
        obj["context"]=art.context;
        obj["createTime"]=art.createTime;
        obj["isSyn"]=art.isSyn;
        obj["modifiedTime"]=art.modifiedTime;
        if(iArticle!=art.articleId)
        {
            root[iRoot]["array"].removeMember(iArticle);
        }
        root[iRoot]["array"][art.articleId]=obj;
        writeInJson(root);
        return 1;
    }
    else return 0;
   
}