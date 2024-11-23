#include <iostream>
#include "OneList.cpp"
#include "DoubleList.cpp"

void proccesingOneList(OneList<char>String) {
	int i = 0;
	int j;
	
	while (String[i] != '\0') {
		if (String[i] == '?') {
			if ((String[i + 1] > 64 and String[i + 1] < 91) or (String[i + 1] > 96 and String[i + 1] < 123)) {
				if (String[i + 1] != 65 and String[i + 1] != 69 and String[i + 1] != 73 and String[i + 1] != 79 and String[i + 1] != 85 and String[i + 1] != 89
					and String[i + 1] != 97 and String[i + 1] != 101 and String[i + 1] != 105 and String[i + 1] != 111 and String[i + 1] != 113 and String[i + 1] != 117) {
					j = i + 1;
					String[i] = '!';
					String.insert(i + 1, '!');
				}
				else
				{
					String[i] = ' ';
				}
			}
		}
		i++;
	}
}

void proccesingDoubleList(DoubleList<char>String) {
	int i = 0;
	int j;
	while (String[i] != '\0') {
		if (String[i] == '?') {
			if ((String[i + 1] > 64 and String[i + 1] < 91) or (String[i + 1] > 96 and String[i + 1] < 123)) {
				if (String[i + 1] != 65 and String[i + 1] != 69 and String[i + 1] != 73 and String[i + 1] != 79 and String[i + 1] != 85 and String[i + 1] != 89
					and String[i + 1] != 97 and String[i + 1] != 101 and String[i + 1] != 105 and String[i + 1] != 111 and String[i + 1] != 113 and String[i + 1] != 117) {
					j = i + 1;
					String[i] = '!';
					String.insert(i + 1, '!');
				}
				else
				{
					String[i] = ' ';
				}
			}
		}
		i++;
	}
}

int main()
{	
	OneList<char>String;
	DoubleList<char>String2;
	char simv;
	std::cin >> simv;
	while (simv != '0') {
		String.push_back(simv);
		String2.push_back(simv);
		std::cin >> simv;
	}
	String.push_back('\0');
	String2.push_back('\0');
	proccesingOneList(String);

	for (int i = 0; i < String.size(); i++) {
		std::cout << String[i];
	}
	std::cout << "\n";

	proccesingDoubleList(String2);
	for (int i = 0; i < String.size(); i++) {
		std::cout << String2[i];
	}

}
