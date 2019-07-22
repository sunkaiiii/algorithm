#include "Nqueens.h"
std::vector<int> current;

void findAnswer(int n, std::vector<std::vector<int>>& queens, std::vector<std::vector<int>>& ans)
{
	for (auto i : queens) {
		for (int j : i) {
			std::cout << j << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "-------------------\n";
	if (n == 0) {
		ans.push_back(current);
		return;
	}
	for (int i = 0; i < queens.size(); i++) {
		bool ok = true;
		for (int j = 0; j < queens.size() - n && ok; j++) { //�Ҷ�Ӧ��ֱ������û���ظ���
			if (queens[j][i] == 1) {
				ok = false;
			}
		}
		if (queens.size() - n > 0) { //���߽�
			if (i > 0 && queens[queens.size() - n - 1][i - 1] == 1) { //��б�Ϸ���
				ok = false;
			}
			if (i < queens.size() - 1 && queens[queens.size() - n - 1][i + 1] == 1) { //��б�Ϸ���
				ok = false;
			}
		}
		if (ok) {
			queens[queens.size() - n][i] = 1; //���ѡ��
			current.push_back(i); //���ܵĽ� ��ջ
			findAnswer(n - 1, queens, ans);
			current.pop_back(); //���ݱ��
			queens[queens.size() - n][i] = 0;
		}
	}
}

void Nqueen() {
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> queens;
	for (int i = 0; i < n; i++) {
		std::vector<int> eachLine(n);
		queens.push_back(eachLine);
	}
	std::vector<std::vector<int>> ans;
	findAnswer(n, queens, ans);
	for (auto i : ans) {
		for (int j : i) {
			std::cout << j << " ";
		}
		std::cout << std::endl;
	}
}

