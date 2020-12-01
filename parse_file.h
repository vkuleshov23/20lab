#ifndef _PARSE_H_
#define _PARSE_H_
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class ParseFile {
private:
	int vertex = 0;
	vector<vector<int>> graph;
	size_t size = 0;
public:
	
	int filling_adj_list(const string filename, ofstream& fout) {

		ifstream fin(filename);
		if(!fin.is_open()) 
			cout << "No such file or problem with opening\n";

		string buffer;
		int value = 0;
		char c;
		vector<int> tmp;

		while (!fin.eof()) {

			getline(fin, buffer, '\n');
			
			istringstream ss(buffer);

			ss >> c;
			if (!isdigit(c) && c != '\n') {
				while (ss >> c)
				{
					if (std::isdigit(c))
					{
						ss.putback(c);
						ss >> vertex;
					}
				}
				if (vertex >= size) {
					fout << "non-existent vertex"; return -1;
				}
				break;
			}
			else {
				ss.putback(c);
			}

			while (ss >> value) {
				tmp.push_back(value);
			}
			graph.push_back(tmp);
			size++;
			tmp.clear();
		}

		for (size_t i = 0; i < size; i++) {
			for (vector<int>::iterator it = graph[i].begin(); it != graph[i].end(); ++it)
				fout << *it << ' ';
			fout << '\n';
		}
		fout << '\n';
		fout << "vertex of the beginning " << vertex << "\n\n";
		return 0;
	}
	vector<vector<int>> get_graph() {	return graph; }
	int get_vertex() { return vertex; }
};
#endif _PARSE_H_