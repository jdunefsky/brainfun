#include <iostream>
#include <string>

using namespace std;

int main(){
	char cells[30000] = {(char)0};
	string program;
	cin >> program;
	program += " ";
	int d = 0; //data pointer
	for(int i = 0; i < program.length(); i++){ //i is instruction pointer
		switch(program.at(i)){
			case '>': d++; break;
			case '<': d--; break;
			case '+': cells[d]+=1; break;
			case '-': cells[d]-=1; break;
			case '.': cout << cells[d]; break;
			case ',': cin >> cells[d]; break;
			case '[':
				if(cells[d]==0){
					int count = 1;
					i++;
					for(;count!=0;i++){
						if(program.at(i)=='['){
							count++;
						}
						if(program.at(i)==']'){
							count--;
						}
						cout << "i = " << i;
						cout << "count = " << count;
					}
					continue;
				}
				break;
			case ']':
				 if(cells[d]!=0){
					int count = 1;
					i--;
					for(;count!=0;i--){
						if(program.at(i)=='['){
							count--;
						}
						if(program.at(i)==']'){
							count++;
						}
					}
					count-=1;
					continue;
				}
				break;
		}
	}
	cout <<"\n";
	for(int i = 0; i < 20; i++){
		cout << (int)cells[i] << " ";
	}
	return 0;
}
