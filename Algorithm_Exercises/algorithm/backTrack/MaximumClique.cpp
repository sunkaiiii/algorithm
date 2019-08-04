#include "MaximumClique.h"
auto isOutboundFunction = [](int  level,int size, int current, int bound) { return size-level + current > bound; }; //���޺���

void mainAlgorithm(std::map<int, std::vector<int>>& graph, std::vector<int>& temp, std::map<int, std::vector<int>>::iterator it,int level, int current, int& bound,std::vector<int> &result)
{
	if (it == graph.end()) {
		return;
	}
	if (!isOutboundFunction(level,graph.size(), current, bound)) //�ж�ʣ��Ľڵ������Ƿ��ܹ�������
		return;
	bool ok = true;
	for (int i = 1; i != it->first && ok; i++) { //�жϵ�ǰ�ڵ��Ƿ����ŵ���
		if (temp[i] == 1) {
			auto points = graph[i];
			ok = std::find(points.begin(), points.end(), it->first) != points.end();
		}
	}
	if (ok) { //����ж�ͨ�����򽫽ڵ�����
		temp[it->first] = 1;
		current++;
		if (current > bound) {
			result = temp;
			bound = current;
		}
		mainAlgorithm(graph, temp, ++it, level+1, current--, bound,result);
		temp[(--it)->first] = 0; //���ҷ�֧�������ţ�������ָ�һ��״̬��
	}
	mainAlgorithm(graph, temp, ++it, level+1, current, bound,result);
	--it;
}

std::vector<int> findMaximumClique(std::map<int, std::vector<int>>& graph) {
	int bound = 0;
	int current = 0;
	int level = 0;
	std::vector<int> temp(graph.size() + 1);
	std::vector<int> result(graph.size()+1);
	mainAlgorithm(graph, temp,graph.begin(),level, current,bound,result);
	return result;
}

