#include "Calculator2.h"

using namespace std;

void error(string message) {
	cout << message << endl;
	exit(0);
}

list<string> get_data(){
	list<string> result;
	string line;
	cout << "Write the line: ";
	cin >> line;

	int result_i = 0;

	if (isdigit(line[0])) {
		result.push_front(string(1, line[0]));
	}
	else {
		error("Line is incorrect");
	}

	for (int i = 1; i < line.size(); i++){
		char value = line[i];

		if (isdigit(value) || value == '.' || value == 'e') {
			result.back() += value;
			continue;
		}
		if (value == '+' || value == '-' || value == '*' || value == '/'){
			result.push_back(string(1, value));
			result.push_back("");
			result_i += 2;
			continue;
		}
		error("Line is incorrect");
	}

	return result;
}

double calc(list<string> line) {
	auto iter = line.begin();
	double result = stod(*iter);
	iter++;
	while (iter != line.end()) {
		if (*iter == "+"){
			++iter;
			try {
				result += stod(*iter);
			}
			catch (...) {
				error("Line is incorrect");
			}
			continue;
		}
		if (*iter == "-") {
			++iter;
			try {
				result -= stod(*iter);
			}
			catch (...) {
				error("Line is incorrect");
			}
			continue;
		}
		if (*iter == "*") {
			++iter;
			try {
				result *= stod(*iter);
			}
			catch (...) {
				error("Line is incorrect");
			}
			continue;
		}
		if (*iter == "/") {
			++iter;
			try {
				result /= stod(*iter);
			}
			catch (...) {
				error("Line is incorrect");
			}
			continue;
		}
		++iter;
	}
	return result;
}

int main(){
	list<string> line = get_data();
	cout << calc(line) << endl;

	return 0;
}
