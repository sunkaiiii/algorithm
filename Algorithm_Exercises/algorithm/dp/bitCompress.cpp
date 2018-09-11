#include<vector>
#include<iostream>
#include<algorithm>
#include"bitCompress.h"
//����ѹ��
void compress(std::vector<int> origin) {
	//header�洢������Ϣ ǰ8���洢��������3λÿһ�εĴ洢λ������һ����Ҫ11λ��
	const static int maxLength = 256;
	const static int header = 11;
	std::vector<int> s;
	std::vector<int> b;
	std::vector<int> l;
	s.push_back(0);
	b.push_back(0);
	l.push_back(0);
	std::vector<int> p{ 0 };
	for (int value : origin) {
		p.push_back(value);
	}
	for (int i = 1; i < p.size(); i++) {
		b.push_back(length(p[i])); //��ʾ��ǰ���ֵ�λ��
		int bmax = b[i];
		s.push_back(s[i - 1] + bmax); //��һ��ѭ�������ֵ���һ��
		l.push_back(1);
		for (int j = 2; j <= std::min(i, maxLength); j++) { //��ʼ�ж���ǰ������ֹ���һ�ε�Ч��
			if (bmax < b[i - j + 1]) { //ͳһ��һ�����ֵ�λ���������ǰλ��С��������ͳһ��С
				bmax = b[i - j + 1];
			}
			if (s[i] > s[i - j] + j * bmax) { //��ʼ�ж���һ���Ƿ�Ϊ��ǰ�����Ž�
				s[i] = s[i - j] + j * bmax;
				l[i] = j;
			}
		}
		s[i] += header;
	}
	for (int count : s) {
		std::cout << count << " ";
	}
	std::cout << std::endl;
	std::cout << s[p.size() - 1] << std::endl;
	traceBack(p.size() - 1, l);
}

int length(int i) {
	int ii = ceil(log10(i + 1) / log10(2));
	return ii;
}

void traceBack(int n, std::vector<int> l) {
	std::vector<int> c;
	while (n != 0) {
		c.push_back(l[n]);
		n -= l[n];
	}
	for (int i : c) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}