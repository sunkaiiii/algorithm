#pragma once
#include<algorithm>
#include<string>
#include<vector>
#include<list>
#include<memory>

struct Node {
	int i;
	int n;

};


struct TreeNode {
	Node node;
	std::shared_ptr<TreeNode> left;
	std::shared_ptr<TreeNode> right;

	bool operator<(const TreeNode &other) {
		return this->node.n < other.node.n;
	}
};

std::shared_ptr<TreeNode> huffman(std::list<TreeNode> nodes) {
	//�����е�Ȩֵ��������
	nodes.sort();
	std::shared_ptr<TreeNode> root = nullptr;
	while (nodes.size() > 1) {
		//�����µĸ��ڵ�
		std::shared_ptr<TreeNode> rootNode = std::make_shared<TreeNode>();
		//�ѵ�ǰ�������ǰ��ڵ㵱���¸��ڵ��Ҷ�ӽ��
		rootNode->left = std::make_shared<TreeNode>(nodes.front());;
		nodes.pop_front();
		rootNode->right = std::make_shared<TreeNode>(nodes.front());;
		nodes.pop_front();
		//Ȩֵ���
		rootNode->node.n = rootNode->left->node.n + rootNode->right->node.n;
		//���¶����ڵ�
		root = rootNode;
		//����Ȩֵ�����µĽڵ���뵽����������
		auto node = nodes.begin();
		for (;;) {
			if (node == nodes.end()) {
				nodes.insert(node, *rootNode);
				break;
			}
			if (node->node.n>root->node.n) {
				nodes.insert(node, *rootNode);
				break;
			}
			node++;
		}
	}
	return root;
}