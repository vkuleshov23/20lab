#include<iostream>
#include"parse_file.h"
#include"search.h"

//обход в глубину

using namespace std;

int main() {
	ofstream fout("result.txt");

	ParseFile file;
	if (file.filling_adj_list("list.txt", fout) < 0) {
		return -1;
	}

	search list(file.get_graph(), file.get_vertex());
	list.dfs(fout);
}