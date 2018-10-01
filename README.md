# BusWay
北京高校间交通查询系统

## 1.问题描述 
北工大学生可能需要去清华听报告，北大教授也可能来北工大做报告。校际间需要查询交通线路。本系统就是一款在北京几所大学之间查询公交线路的小软件。数据来自高德地图。

## 2.基本要求
输入：用户选择起点和终点，并选择“费用最少”和“时间最短”两种模式之一。

输出：将查询得到的公交线路方案提示给用户，包括公里数、持续时间、费用。


## 3.已实现功能
1)至少包括7个候选大学：例如：北工大、北大、清华、人大、北师大、北航、中国传媒大学。

2)原始的真实信息：学校间的交通可参考百度地图、各大学官网的原始信息 。

3)查询的数据来源只能是用户的输入、百度地图的路程信息，也就是只能将原始信息作参数，执行算法，计算得到；切记：不能提前计算好几种方案，存储在文本文件中，按用户需要，对文本文件进行简单的显示，这样做将无法增、删候选大学、无法进行系统升级。

4)实现最少步行、最少换乘功能；

## 4.未实现扩展功能
1)实现必经中转站：在返回的路上可能要去西单图书大厦买书，因此增设几个候选结点，每次行程需要设置一个必经中转站。
2)参考百度地图等商业软件的实现方案，自定义你认为实用的功能，使查询方案更多样，查询结果更详细。

# 系统设计：
## 1.需要处理的数据
站点数量，站点序号，站点名称，路线数量，路线序号，路线权值，路线公交方式。

## 2.输入数据
从文件dingdianhebian.txt读入站点数量与路线数量。
从文件daxue.txt、feiyong.txt、bx.txt、huancheng.txt分别读入站点序号与路线权值。具体格式为（起始站，终点站，权值（时间、费用、步行距离、换乘次数））。
从文件bus.txt读入公交路线方式。
从文件xiaoxue.txt读入路线序号。
从文件mingcheng.txt读入各站点的中文名称。

## 3.输出数据
输出路线信息，包括各换乘站以及相应的公交方式。

## 4.开发环境
VS2013

## 5.用户界面的设计等
提示输入起始站和终点站
选择希望的出行需求（费用最少、时间最短、最少步行、最少换乘）
DOS输出路线信息
提示继续或退出

## 6.数据结构设计
### 建立图的存储结构
定义交通图的存储结构。用邻接矩阵来表示图是唯一的。需要用一个二维数组存储顶点之间相邻关系的邻接矩阵，并且还需要用一个具有n个元素的一维数组来存储顶点信息。下标为i的元素存储顶点V[i]的信息。 
```
typedef struct{
	char s[100][20];//存储顶点信息,char型
	int vexs[100];//顶点数组，int型
	int arcs[100][100];//邻接矩阵,int型
int num[1000][1000];//邻接矩阵的序号,int型
}MGraph;
```
### 定义边的数据结构
两个节点之间有一条边，用一维数组存储边的序号，并用一个二维数组存储边的信息。
```
typedef struct{
	char s[1000][1000];//存储边的信息
	int shuliang[1000];//存储边的序号
}Side;
```
### 程序整体结构
根据文件里的信息用邻接矩阵建立图的存储结构，分别建立时间无向图、费用无向图、步行距离无向图、换乘无向图。根据用户输入的起始站与终点站。使用FLOYD算法求出最优路径，将值存入数组，并输出相应的站点与公交出行方式。
### 各模块的功能描述
```
void CreateMGraph(MGraph * G, Side*E, int n, int e){
 //根据节点与边的信息建立带权无向图
}
```
```
void Floyd(MGraph *G, int n){
//用FLOYD算法求出最优路径
}
```
```
void main(){
//主函数，读取文件，建立存储结构，进行选择输入输出
}
```

## 程序界面
![image](https://github.com/Haitons/BusWay/raw/master/img-folder/e.png)

## 功能展示
1)从北大到人大耗时最短路径：
1)从北大到中国传媒大学费用最少路径：
1)从北大到人大耗时最短路径：
