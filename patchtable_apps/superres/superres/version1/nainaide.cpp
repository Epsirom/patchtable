// nainaide.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void WriteFile(int rows, int cols, float **data){
	/*int m = 10;
	int n = 20;
*/
	//float **data = new float*[rows];
	/*for (int i = 0; i <rows; i++){
		data[i] = new float[cols];
		for (int j = 0; j < cols; j++){
			data[i][j] = 1.1f;
		}
	}
*/
	
	ofstream out ("D:/dataout.txt");
	for(int i = 0; i <rows ; i++){
		for(int j = 0; j < cols - 1; j++){
			out<<data[i][j]<<" ";
		}
		out << data[i][cols - 1] << endl;
	}
	out.close();
}
int main()
{

	//��ȡ�ļ�
	ifstream in("D:/dataout2.txt");
	char line[256];
	in.getline(line, 256);

	int m = 10, n = 10;
    stringstream ss;
	ss<<line;
	ss>>m;
	ss>>n;
	cout<<"����:" << m << ";����:"<<n<<endl;

	////��ʼ������
	float **data = new float*[m];
	for(int i = 0; i <m ; i++){
		data[i] = new float[n];
		for(int j = 0; j < n; j++){
			data[i][j] = 2.0f;
		}
	}

	//�����ļ���ת��Ϊ����
	int lineno = 0;
	while(in.getline(line, 256)){
		stringstream ss2;
		ss2<<line;
		for(int j = 0; j < n; j++){
			ss2>>data[lineno][j];
		}
		lineno++;
	}
	
	//���
	for(int i = 0; i <m ; i++){
		for(int j = 0; j < n - 1; j++){
			cout<<data[i][j]<<" ";
		}
		cout<<data[i][n-1]<<endl;
	}
	return 0;
}