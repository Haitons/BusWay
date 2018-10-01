#include<stdio.h>
#include<fstream>
#include<iostream>
#include<string>
#include<stdlib.h> 

#pragma warning( disable : 4996) 
using namespace std;

#define Maxint 32767 
const int maxnum = 100;





typedef struct{
	char s[100][20];
	int vexs[100];
	int num[1000][1000];
	int arcs[100][100];

}MGraph;
typedef struct{
	char s[1000][1000];
	int shuliang[1000];

}Side;
int D1[100], p1[100];

int D[100][100], p[100][100];
int dist[maxnum]; 

int c[maxnum][maxnum];
int line;

void CreateMGraph(MGraph * G, Side*E, int n, int e)

{

	int i, j, k, w, z, i1, j1, num;
	char y;
	char car;

	for (i = 1; i <= n; i++)

		G->vexs[i] = i;

	for (j = 1; j <= e; j++)

		E->shuliang[j] = j;

	for (i = 1; i <= n; i++)

	for (j = 1; j <= n; j++)

		G->arcs[i][j] = Maxint;
	G->arcs[j][i] = Maxint;
	for (i1 = 1; i1 <= n; i1++)

	for (j1 = 1; j1 <= n; j1++)

		G->num[i1][j1] = Maxint;
	G->num[j1][i1] = Maxint;
	
	FILE *gp;
	gp = fopen("d:\\keshe\\daxue.txt", "r");



	for (k = 1; k <= e; k++){

		fscanf(gp, "%d %d %d", &i, &j, &w);


		G->arcs[i][j] = G->arcs[j][i] = w;


	}

	fclose(gp);

	int k1;
	FILE *yp;
	yp = fopen("d:\\keshe\\xiaoxue.txt", "r");



	for (k1 = 1; k1 <= e; k1++){

		fscanf(yp, "%d %d %d", &i1, &j1, &z);


		G->num[i1][j1] = G->num[j1][i1] = z;


	}

	fclose(yp);

}
void CreateMGraph1(MGraph * J, Side*E, int n, int e)

{

	int i, j, k, w, z, i1, j1, num;
	char y;
	char car;

	for (i = 1; i <= n; i++)

		J->vexs[i] = i;

	for (j = 1; j <= e; j++)

		E->shuliang[j] = j;

	for (i = 1; i <= n; i++)

	for (j = 1; j <= n; j++)

		J->arcs[i][j] = Maxint;
	    J->arcs[j][i] = Maxint;
	for (i1 = 1; i1 <= n; i1++)

	for (j1 = 1; j1 <= n; j1++)

		J->num[i1][j1] = Maxint;
	    J->num[j1][i1] = Maxint;

	FILE *gp;
	gp = fopen("d:\\keshe\\feiyong.txt", "r");



	for (k = 1; k <= e; k++){

		fscanf(gp, "%d %d %d", &i, &j, &w);


		J->arcs[i][j] = J->arcs[j][i] = w;


	}

	fclose(gp);

	int k1;
	FILE *yp;
	yp = fopen("d:\\keshe\\xiaoxue.txt", "r");



	for (k1 = 1; k1 <= e; k1++){

		fscanf(yp, "%d %d %d", &i1, &j1, &z);


		J->num[i1][j1] = J->num[j1][i1] = z;


	}

	fclose(yp);

}
void CreateMGraph2(MGraph * H, Side*E, int n, int e)

{

	int i, j, k, w, z, i1, j1, num;
	char y;
	char car;

	for (i = 1; i <= n; i++)

		H->vexs[i] = i;

	for (j = 1; j <= e; j++)

		E->shuliang[j] = j;

	for (i = 1; i <= n; i++)

	for (j = 1; j <= n; j++)

		H->arcs[i][j] = Maxint;
	H->arcs[j][i] = Maxint;
	for (i1 = 1; i1 <= n; i1++)

	for (j1 = 1; j1 <= n; j1++)

		H->num[i1][j1] = Maxint;
	H->num[j1][i1] = Maxint;

	FILE *gp;
	gp = fopen("d:\\keshe\\bx.txt", "r");



	for (k = 1; k <= e; k++){

		fscanf(gp, "%d %d %d", &i, &j, &w);


		H->arcs[i][j] = H->arcs[j][i] = w;


	}

	fclose(gp);

	int k1;
	FILE *yp;
	yp = fopen("d:\\keshe\\xiaoxue.txt", "r");



	for (k1 = 1; k1 <= e; k1++){

		fscanf(yp, "%d %d %d", &i1, &j1, &z);


		H->num[i1][j1] = H->num[j1][i1] = z;


	}

	fclose(yp);

}
void CreateMGraph3(MGraph * I, Side*E, int n, int e)

{

	int i, j, k, w, z, i1, j1, num;
	char y;
	char car;

	for (i = 1; i <= n; i++)

		I->vexs[i] = i;

	for (j = 1; j <= e; j++)

		E->shuliang[j] = j;

	for (i = 1; i <= n; i++)

	for (j = 1; j <= n; j++)

		I->arcs[i][j] = Maxint;
	I->arcs[j][i] = Maxint;
	for (i1 = 1; i1 <= n; i1++)

	for (j1 = 1; j1 <= n; j1++)

		I->num[i1][j1] = Maxint;
	I->num[j1][i1] = Maxint;

	FILE *gp;
	gp = fopen("d:\\keshe\\huancheng.txt", "r");



	for (k = 1; k <= e; k++){

		fscanf(gp, "%d %d %d", &i, &j, &w);


		I->arcs[i][j] = I->arcs[j][i] = w;


	}

	fclose(gp);

	int k1;
	FILE *yp;
	yp = fopen("d:\\keshe\\xiaoxue.txt", "r");



	for (k1 = 1; k1 <= e; k1++){

		fscanf(yp, "%d %d %d", &i1, &j1, &z);


		I->num[i1][j1] = I->num[j1][i1] = z;


	}

	fclose(yp);

}

void Floyd(MGraph *G, int n)

{
	int i, j, k, v, w;

	for (i = 1; i <= n; i++)

	for (j = 1; j <= n; j++)

	{

		if (G->arcs[i][j] != Maxint)

			p[i][j] = j;

		else

			p[i][j] = 0;

		D[i][j] = G->arcs[i][j];

	}

	for (k = 1; k <= n; k++)

	{

		for (i = 1; i <= n; i++)

		for (j = 1; j <= n; j++)

		{

			if (D[i][k] + D[k][j]<D[i][j])
			{

				D[i][j] = D[i][k] + D[k][j];

				p[i][j] = p[i][k];


			}

		}

	}

}

void main()

{

	MGraph *G, *H, *I, *J;
	Side *E;
	int m, n, e, v, w, k, i, i1;

	int xz = 1;

	G = (MGraph *)malloc(sizeof(MGraph));
	H = (MGraph *)malloc(sizeof(MGraph));
	I = (MGraph *)malloc(sizeof(MGraph));
	J = (MGraph *)malloc(sizeof(MGraph));
	E = (Side *)malloc(sizeof(Side));

	FILE *fp;
	fp = fopen("d:\\keshe\\dingdianhebian.txt", "r");
	fscanf(fp, "%d,%d", &n, &e);
	fclose(fp);

	ifstream ifs("d:\\keshe\\mingcheng.txt");
	streambuf* old_buffer = cin.rdbuf(ifs.rdbuf());


	for (i = 1; i <= n; i++)
		cin >> G->s[i];

	cin.rdbuf(old_buffer);
	ifstream ifs2("d:\\keshe\\mingcheng.txt");
	streambuf* old_buffer2 = cin.rdbuf(ifs2.rdbuf());


	for (i = 1; i <= n; i++)
		cin >> H->s[i];

	cin.rdbuf(old_buffer2);
	ifstream ifs3("d:\\keshe\\mingcheng.txt");
	streambuf* old_buffer3 = cin.rdbuf(ifs3.rdbuf());


	for (i = 1; i <= n; i++)
		cin >> I->s[i];

	cin.rdbuf(old_buffer3);
	ifstream ifs4("d:\\keshe\\mingcheng.txt");
	streambuf* old_buffer4 = cin.rdbuf(ifs4.rdbuf());


	for (i = 1; i <= n; i++)
		cin >>J->s[i];

	cin.rdbuf(old_buffer4);

	ifstream ifs1("d:\\keshe\\bus.txt");
	streambuf* aq = cin.rdbuf(ifs1.rdbuf());
	for (i = 1; i <= e; i++)
		cin >> E->s[i];

	cin.rdbuf(aq);
	
	CreateMGraph(G, E, n, e);
	CreateMGraph1(J, E, n, e);
	CreateMGraph2(H, E, n, e);
	CreateMGraph3(I, E, n, e);
	while (xz != 0)
	{

		cout << "************欢迎使用路线查询系统************\n";

		cout << "===========================================\n";

        cout << "    求任意的两个学校之间的最短路径         \n";

		cout << "        (所用数据来自高德地图）            \n";

		cout << "===========================================\n";
		cout << "请输入 1.求路线信息  0.退出" << endl;
		cin >> xz;
	
		if (xz == 1)
		{

			char qd[1000];
			char zd[1000];

			cout << "输入起始站和终点站";

			cout << endl;
			cin >> qd;
			int v = 0;

			while (v == 0)
			{
				for (i1 = 1; i1 <= n; i1++)
				{

					if (strcmp(qd, G->s[i1]) == 0)
						v = i1;



				}
				if (v == 0){
					cout << "抱歉，目前没有该学校站点,请重新输入:";

					cin >> qd;
				}
			}
			cin >> zd;
			int w = 0;
			while (w == 0)
			{
				for (int i2 = 1; i2 <= n; i2++){

					if (strcmp(zd, G->s[i2]) == 0)
						w = i2;


				}
				if (w == 0){
					cout << "抱歉，目前没有该学校站点,请重新输入:";

					cin >> zd;
				}
			}
			
			cout << "请选择您的出行方案：" << endl << "1.耗时最短" << endl << "2.费用最少" << endl << "3.最少步行" << endl << "4.换乘最少" << endl;
			int fangan;
			cin >> fangan;
			switch (fangan)
			{
			case 1:
			{
					  Floyd(G, n);
					  k = p[v][w];
					  if (k == 0)

						  cout << "从" << G->s[v] << "到" << G->s[w] << " 无路径!\n";

					  else

					  {

						  cout << "从" << G->s[v] << " 到" << G->s[w] << " 耗时最短路径是:" << endl;
						  cout << G->s[v];
						  int dd = k;
						  while (dd != w){

							  cout << "-->" << G->s[dd];

							  dd = p[dd][w];
						  }
						  cout << "-->" << G->s[w];
						  cout << endl;

						  cout << "所用时间约为" << D[v][w] << "min" << endl;
						  cout << "具体路线信息如下：" << endl;

						  cout << endl;
						  cout << "从" << G->s[v] << "-->";
						  cout << endl;


						  int bb;
						  int cc = v;

						  while (k != w){

							  for (int i2 = 1; i2 <= n; i2++)


							  for (int j2 = 1; j2 <= n; j2++)
							  if (i2 == v&&j2 == k){
								  bb = G->num[i2][j2];
								  cout << E->s[bb] << "到" << endl;

							  }
							  cout << G->s[k] << "-->";
							  v = k;

							  k = p[k][w];


						  }
						  int aa = G->num[v][w];
						  cout << E->s[aa];

						  cout << "到" << G->s[w];

						  cout << endl;
						  cout << "所用时间约为:" << D[cc][w] << "min" << endl;


					  }
					  break;
			}
			case 3:
			{
					  Floyd(H, n);
					  k = p[v][w];
					  if (k == 0)

						  cout << "从" << H->s[v] << "到" << H->s[w] << " 无路径!\n";

					  else

					  {

						  cout << "从" << H->s[v] << " 到" << H->s[w] << " 步行距离最短路径是:" << endl;
						  cout << H->s[v];
						  int dd = k;
						  while (dd != w){

							  cout << "-->" << H->s[dd];

							  dd = p[dd][w];
						  }
						  cout << "-->" << H->s[w];
						  cout << endl;

						  cout << "步行距离约为" << D[v][w] << "米" << endl;
						  cout << "具体路线信息如下：" << endl;

						  cout << endl;
						  cout << "从" << H->s[v] << "-->";
						  cout << endl;


						  int bb;
						  int cc = v;

						  while (k != w){

							  for (int i2 = 1; i2 <= n; i2++)


							  for (int j2 = 1; j2 <= n; j2++)
							  if (i2 == v&&j2 == k){
								  bb = H->num[i2][j2];
								  cout << E->s[bb] << "到" << endl;

							  }
							  cout << H->s[k] << "-->";
							  v = k;

							  k = p[k][w];


						  }
						  int aa = H->num[v][w];
						  cout << E->s[aa];

						  cout << "到" << H->s[w];

						  cout << endl;
						  cout << "步行距离约为:" << D[cc][w] << "米" << endl;


					  }
					  break;
			}
			case 4:
			{
					  Floyd(I, n);
					  k = p[v][w];
					  if (k == 0)

						  cout << "从" << I->s[v] << "到" << I->s[w] << " 无路径!\n";

					  else

					  {

						  cout << "从" << I->s[v] << " 到" << I->s[w] << " 换乘次数最少路径是:" << endl;
						  cout << I->s[v];
						  int dd = k;
						  while (dd != w){

							  cout << "-->" << I->s[dd];

							  dd = p[dd][w];
						  }
						  cout << "-->" << I->s[w];
						  cout << endl;

						  cout << "换乘次数为" << D[v][w] << "次" << endl;
						  cout << "具体路线信息如下：" << endl;

						  cout << endl;
						  cout << "从" << I->s[v] << "-->";
						  cout << endl;


						  int bb;
						  int cc = v;

						  while (k != w){

							  for (int i2 = 1; i2 <= n; i2++)


							  for (int j2 = 1; j2 <= n; j2++)
							  if (i2 == v&&j2 == k){
								  bb = I->num[i2][j2];
								  cout << E->s[bb] << "到" << endl;

							  }
							  cout << I->s[k] << "-->";
							  v = k;

							  k = p[k][w];


						  }
						  int aa = I->num[v][w];
						  cout << E->s[aa];

						  cout << "到" << I->s[w];

						  cout << endl;
						  cout << "共换乘:" << D[cc][w] << "次" << endl;


					  }
					  break;
			}
			case 2:
			{
					  Floyd(J, n);
					  k = p[v][w];
					  if (k == 0)

						  cout << "从" << J->s[v] << "到" << J->s[w] << " 无路径!\n";

					  else

					  {

						  cout << "从" << J->s[v] << " 到" << J->s[w] << " 费用最少路径是:" << endl;
						  cout << J->s[v];
						  int dd = k;
						  while (dd != w){

							  cout << "-->" << J->s[dd];

							  dd = p[dd][w];
						  }
						  cout << "-->" <<J->s[w];
						  cout << endl;

						  cout << "共花费" << D[v][w] << "元" << endl;
						  cout << "具体路线信息如下：" << endl;

						  cout << endl;
						  cout << "从" << J->s[v] << "-->";
						  cout << endl;


						  int bb;
						  int cc = v;

						  while (k != w){

							  for (int i2 = 1; i2 <= n; i2++)


							  for (int j2 = 1; j2 <= n; j2++)
							  if (i2 == v&&j2 == k){
								  bb = J->num[i2][j2];
								  cout << E->s[bb] << "到" << endl;

							  }
							  cout << J->s[k] << "-->";
							  v = k;

							  k = p[k][w];


						  }
						  int aa = J->num[v][w];
						  cout << E->s[aa];

						  cout << "到" << J->s[w];

						  cout << endl;
						  cout << "共花费:" << D[cc][w] << "元" << endl;


					  }
					  break;
			}
			}
		}

	}
	system("pause");
	cout << "结束求最短路径再见!\n";
	

}
