#include<iostream>
#include<fstream>
#include<time.h>
#include<string>
#include"hashTable.h"
#include"BinaryTree.h"

using namespace std;

char my_tolower(unsigned char c)
{
	return tolower(c);
}

BinaryTree stop;

void stopWordAddtoTree(string array[]) {
	

	for (int i = 0; i < 329;i+=2) { 

		if (i < 328) {
			stop.insert(array[327 - i]);
			stop.insert(array[328 - i]);
		}
		else  {
			stop.insert(array[328 - i]);
		}
		if (i < 328) {
			stop.insert(array[331 + i]);
			stop.insert(array[330 + i]);
		}
		else  {
			stop.insert(array[i]);
		}
		
		
	}
}

void düzenleyiciSoldan(string &new1) {

	if (new1[0] == '~' || new1[0] == '=' || new1[0] == '|' || new1[0] == ' ' || new1[0] == '\'' || new1[0] == '_' || new1[0] == '[' || new1[0] == ']' || new1[0] == '?' || new1[0] == '!' || new1[0] == '@' || new1[0] == '.' || new1[0] == '-' || new1[0] == ',' || new1[0] == '"' || new1[0] == '#' || new1[0] == '+' || new1[0] == '*' || new1[0] == '%' || new1[0] == '&' || new1[0] == '$' || new1[0] == '/' || new1[0] == ':' || new1[0] == ';' || new1[0] == '(' || new1[0] == ')') {

		new1.erase(0, 1);

		düzenleyiciSoldan(new1);
	}


}

void düzenleyiciSagdan(string &new2) {



	if (new2.back() == '~' || new2.back() == '=' || new2.back() == '|' || new2.back() == ' ' || new2.back() == '\'' || new2.back() == '_' || new2.back() == '[' || new2.back() == ']' || new2.back() == '?' || new2.back() == '!' || new2.back() == '@' || new2.back() == '.' || new2.back() == '-' || new2.back() == ',' || new2.back() == '"' || new2.back() == '#' || new2.back() == '+' || new2.back() == '*' || new2.back() == '%' || new2.back() == '&' || new2.back() == '$' || new2.back() == '/' || new2.back() == ':' || new2.back() == ';' || new2.back() == '(' || new2.back() == ')') {

		new2.pop_back();

		düzenleyiciSagdan(new2);
	}
}

int main() {

	clock_t tStart = clock();

	ifstream okumaDosyasi;
	ifstream okumaDosyasi2;

	okumaDosyasi.open("training.1600000.processed.noemoticon.csv");
	okumaDosyasi2.open("stopWords.txt");
	
	hashTable a;
	string deneme;
	string stopWord;
	string kelime;
	string sW[659];


	int d = 0;

	while (!okumaDosyasi2.eof()) {
		okumaDosyasi2 >> stopWord;
		sW[d] = stopWord;
		d++;

	}
	stop.insert(sW[329]); 
	stopWordAddtoTree(sW);

	int b = 0;  //count for nick only once on every line

	while (!okumaDosyasi.eof()) {

		
		getline(okumaDosyasi, deneme);


		for (int i = 59; i < deneme.length(); i++) { 
			if(((int)deneme[i])<127 && ((int)deneme[i])>32)
			{
				kelime += my_tolower(deneme[i]);
			}
			else {
				continue;
			}

			if (deneme[i] == ',' && b == 0) { //passing tweet's owner nick

				kelime.clear();
				b = 1;
				continue;
			}



			if (deneme[i + 1] == ' ' || i == (deneme.length() - 1)) {

				
				düzenleyiciSoldan(kelime);

				if (kelime == "") {
					while (deneme[i + 1] == ' ') {
						i++;
					}
					continue;
				}
				else if (kelime == " ") {
					i++;
					continue;
				}
				else if (kelime == "  ") {
					i += 2;
					continue;
				}

				düzenleyiciSagdan(kelime);

				if (stop.search(kelime)) {
					i++;
					kelime.clear();
					continue;
					
				}

				a.insert(kelime);

				kelime.clear();

				

				while (deneme[i + 1] == ' ') {
					i++;
				}
			}
			
		}
		b = 0;
		
	}
	
	

	a.printMax();
	a.printMax();
	a.printMax();
	a.printMax();
	a.printMax();
	a.printMax();
	a.printMax();
	a.printMax();
	a.printMax();
	

	printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
	system("pause");
	return 0;
}