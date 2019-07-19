#include "Dijkstra.h"

std::map<int, std::map<int, int>> getExample()
{
	//����һ������ͼ����
	return std::map<int, std::map<int, int>> {
		{1, {{2,10},{6,3}}},
		{ 2,{{3,7} } },
		{3,{}},
		{4,{{1,3},{3,4},{5,7} }},
		{5,{}},
		{ 6,{{2,2},{5,1}, {4,6}} }
	};
	
	
}

std::vector<int> findRoad(int startPoint,std::map<int, std::map<int, int>> example)
{
	if (startPoint >= example.size()) { //������
		return std::vector<int>{};
	}
	//***********************
	//���ݳ�ʼ��
	std::vector<int> s;
	int n = example.size();
	const int infinity = 0x0fffffff;
	std::vector<int> l(n+1);
	std::vector<int> distances(n+1,infinity);
	distances[startPoint] = 0;
	auto startPosition = example[startPoint];
	s.push_back(startPoint);
	int currentPoint = startPoint;
	//***************************
	//��ʼѭ��
	while (s.size() <n) {
		for (auto eachPoint : example[currentPoint]) { 
			//��ʼȡ�㣬������ά���ľ����
			//����ӵ�ǰ���ߵ��������ӵĵ�ľ���ҪС�ڼ�¼����ľ���
			//����¼�¼��ľ���Ϊ�ӵ�ǰ��ļ�¼���루�϶�����С�ģ�����Ȩֵ
			//ͬʱ��������l����Ŀ�������·����Դ�����ŵ�ǰ�㡣
			if (distances[currentPoint] + eachPoint.second < distances[eachPoint.first]) {
				distances[eachPoint.first] = distances[currentPoint] + eachPoint.second;
				l[eachPoint.first] = currentPoint;
			}
		}
		example.erase(currentPoint);
		int min = infinity;
		int j = -1;
		//���¹�һ��֮�󣬴�ʣ��ĵ������ҵ���¼�ľ�����̵��Ǹ�
		//ȡ������ʼ��һ��ѭ��
		for (auto remainedPoint : example) {
			if (distances[remainedPoint.first] < min) {
				j = remainedPoint.first;
				min = distances[remainedPoint.first];
			}
		}
		s.push_back(j);
		currentPoint = j;
	}
	distances.erase(distances.begin());
	return distances;
}
