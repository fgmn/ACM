#include <io.h>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

/* 
TODO:
1. 处理文件层次结构(目录树)
2. 过滤cpp以外文件
*/

// 解析文件名
string parseFilename(string path)
{
    int sz = path.length();
    int i;
    for (i = sz - 1; i >= 0; i--)
    {
        if (path[i] == '\\')
            break;
    }
    return path.substr(i + 1, sz - i - 5);
}

// 获取文件绝对路径
void getFiles(string path, vector<string> &files)
{
    // 文件句柄
    intptr_t hFile = 0;
    // 文件信息，声明一个存储文件信息的结构体
    struct _finddata_t fileinfo;
    string p;                                                                        // 字符串，存放路径
    if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1) // 若查找成功，则进入
    {
        do
        {
            // 如果是目录,迭代之（即文件夹内还有文件夹）
            if ((fileinfo.attrib & _A_SUBDIR))
            {
                // 文件名不等于"."&&文件名不等于".."
                // .表示当前目录
                // ..表示当前目录的父目录
                // 判断时，两者都要忽略，不然就无限递归跳不出去了！
                if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
                    getFiles(p.assign(path).append("\\").append(fileinfo.name), files);
            }
            // 如果不是,加入列表
            else
            {
                files.push_back(p.assign(path).append("\\").append(fileinfo.name));
            }
        } while (_findnext(hFile, &fileinfo) == 0);
        // _findclose函数结束查找
        _findclose(hFile);
    }
}

void copy2OneObj(vector<string>& files, ofstream& f) {
    int cnt = 0;
    string fn, str;
    ifstream f1;
    int sz = files.size();
    for (int i = 0; i < sz; i++) {
        fn = parseFilename(files[i]);
        // cout << fn << '\n';
        f << ++cnt << ". " << fn << '\n';
        f1.open(files[i]);

        // 复制文件内容
        while (getline(f1, str)) {
            f << str << '\n';
        }
        f << '\n';
        f1.close();     // 复用前应先关闭
    }
}

int main()
{
    string filePath = "D:\\study\\ACM\\ACM\\Graph"; // 自己设置目录
    vector<string> files;

    // 获取该路径下的所有文件
    getFiles(filePath, files);

    int size = files.size();
    for (int i = 0; i < size; i++)
    {
        cout << files[i].c_str() << endl;
    }

    ofstream f;
    f.open("5-27.txt");
    copy2OneObj(files, f);
}