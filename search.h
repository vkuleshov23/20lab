#ifndef _SEARCH_H_
#define _SEARCH_H_
#include<iostream>
#include<vector>
#include"parse_file.h"

using namespace std;

class search {
private:
	vector<vector<int>> graph;
	vector<bool> visited;
	vector<int> stack;
	int vertex = 0;

public:
	int get_vertex() {
		return vertex;
	}

	search(vector<vector<int>> _graph, int _vertex) {
		vertex = _vertex;
		graph = _graph;
		for (size_t i = 0; i < graph.size(); i++) {
			visited.push_back(false);
		}
	}

	void dfs(ofstream& fout) {
		int i = 0;
		bool flag = false;
		visited[vertex] = true;
		stack.push_back(vertex);
		fout << "digraph G {\n";
		while (!stack.empty()) {
			int cur = stack[stack.size() - 1];
			
			for (i = 0; i < graph[cur].size(); i++) {
				if (visited[graph[cur][i]] == 0) {
					visited[graph[cur][i]] = 1;
					stack.push_back(graph[cur][i]);
					fout << "	" << stack[stack.size() - 2] << " -> " << stack[stack.size() - 1] << " [color = \"red\"];\n";
					flag = true;
					break;
				}
				else if(visited[graph[cur][i]] == 1 && flag){
					flag = false;
					if (stack.size() > 2) {
						for (int j = 0; j < stack.size()-2; j++) {
							for (int k = 0; k < graph[cur].size(); k++) {
								if (graph[cur][k] == stack[j]) {
									fout << "	" << stack[stack.size() - 1] << " -> " << stack[j] << " [color = \"blue\"];\n";
								}
							}
						}
					}
				}
			}
			if (i == graph[cur].size()) {
				if (stack.size() > 1) {
					fout << "	" << stack[stack.size() - 1] << " -> " << stack[stack.size() - 2] << " [color = \"green\"];\n";
				}
				stack.pop_back();
			}
		}
		fout << '}';
	}

};
#endif _SEARCH_H_