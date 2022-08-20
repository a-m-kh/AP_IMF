#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;

string  operator+(int &a , string s){
	stringstream code ;
		code<<a;
		string strsnn;
		code>>strsnn;
		strsnn += "  ";
		strsnn[7] = strsnn[5];
		strsnn[6] = strsnn[4];
		strsnn[5] = strsnn[3];
		strsnn[3] = s[0];
		strsnn[4] = s[1];
		return strsnn;
}

string Caesar(string p){
	int size = p.size();
	for(int i=0;i<size;i++){
		if((int(p[i])<91) && (int(p[i])>64)){
			int x;
			x = int(p[i]) + 32;
			p[i] = char(x);
		}
	}
	for(int i = 0 ; i<size ; i++){
		int x;
		x = int(p[i])-5;
		if(x<97){
			x+=26;
		}
		p[i] = char(x);
	}
	return p;
}
string Playfair(string p){
	for(int i = 0 ; i<p.size() ;i++){
		if((64<(int(p[i]))&& (int(p[i])<91))){
			int x = int(p[i]) + 32 ;
			p[i] = char(x);
		}
	}
	string mabna[5][5] = {{"m" , "o" , "n" , "a" , "r"} , {"c" , "h" , "y", "b","d"} , {"e" ,"f" ,"g" ,"i" , "k"} ,{"l" ,"p" ,"q" ,"s" , "t"} , {"u" , "v" , "w" , "x" , "z"} };
	int x = p.size();
	int y;
	if(x%2 ==  0){
		y = x/2;
	}
	else{
		y = x/2 + 1 ;
	}
	string **dotaii; 
	dotaii = new string *[x];
	for(int i =0;i<x;i++){
		dotaii[i] = new string[2];
	}
	for(int i = 0 ; i<y ;i++){
		dotaii[i][0] = p[2*i];
		dotaii[i][1] = p[(2*i) + 1];
	}
	for(int i = 0 ; i<y ; i++){
		if(dotaii[i][0] == dotaii[i][1]){
			string n = dotaii[i][1];
			string m , k;
			dotaii[i][1] = "x";
			int j = i+1;
			y+=1;
			for(;j<y+1 ; j++){
				if( j == i+1){
					m = dotaii[j][1] ;
					dotaii[j][1] = dotaii[j][0];
					dotaii[j][0] = n;
				}
				else{
					k = dotaii[j][1];
					dotaii[j][1] = dotaii[j][0];
					dotaii[j][0] = m;
					m = k;
				}
			}
		}
	}
	int word;
	int word2;
	for(int i = 0 ; i<x ; i++){
		if(dotaii[i][0] == ""){
			break;
		}
		if (dotaii[i][0] !=""){
			word = 0;
			word2 = 0; 
		}
		if(dotaii[i][0] == "j"){
			dotaii[i][0] = "i";
		}
		if(dotaii[i][1] == "j"){
			dotaii[i][1] = "i";
		}
		for(int j = 0 ; j<5 ; j++){
			for(int k = 0 ;k<5 ; k++){
				if(dotaii[i][0] !=""){
					if(dotaii[i][0] == mabna[j][k]){
						word = (10*j) + k;
					}
				}
			}
		}
		for(int j = 0 ; j<5 ; j++){
			for(int k = 0 ;k<5 ; k++){
				if(dotaii[i][1] != ""){			
					if(dotaii[i][1] == mabna[j][k]){
						word2 = (10*j)+ k;
					}
				}
			}
		}
		int N_E = 0 ;
		if((word%10) == (word2%10)){
			N_E+=1;
			int z = word%10;
			int l = word/10;
			if(l == 4){
				dotaii[i][0] = mabna[0][z];
			}
			else{
				dotaii[i][0] = mabna[l+1][z];
			}
			l= word2/10;
			if(l == 4){
				dotaii[i][1] = mabna[0][z];
			}
			else{
				dotaii[i][1] = mabna[l+1][z];
			}
		}
		if((word/10) == (word2/10)){
			N_E+=1;
			int z = word/10;
			int l = word%10;
			if(l == 0){
				dotaii[i][0] = mabna[z][4];
			}
			else{
				dotaii[i][0] = mabna[z][l-1];
			}
			l = word2%10;
			if(l == 0){
				dotaii[i][1] = mabna[z][4];
				
			}
			else{
				dotaii[i][1] = mabna[z][l-1];
			}
		}
		if(N_E == 0){
			int z =word/10;
			int l = word2/10;
			dotaii[i][0] = mabna[z][word2%10];
			dotaii[i][1] = mabna[l][word%10];
		}
	}
	
	string nahaii;
	for(int i = 0 ; i<x; i++){
		nahaii += (dotaii[i][0] + dotaii[i][1]);
		if(dotaii[i][0] == ""){
			break;
		}
	}
	return nahaii;
}

string Vigenere(string p){// function for Vigenere
	string key = "lieutenant";
	string mainkey = "";
	string finally;
	int x = p.size();
	int y = x/10;
	int z = x%10;
	int d =  0;
	for(int j = 0; j<x ;j++ , d++){
		mainkey +=key[d];
		if(d == key.size()-1){
			d = -1;
		} 
	}
	for(int j =0; j<x ; j++){
		int ascci = int(p[j]) - int(mainkey[j]);
		if(ascci < 0){
			ascci+=26;
		}
		ascci+=97;
		finally +=char(ascci);
	}
	
	return finally;
	
}

class IMF{ // class of IMF 
	

private:
	string Name = "";
	string Family = "";
	int Snn = 0;
	string OperationCode = "";	
	string PersonalCode;
	int TagCode;

public:
	void SetName(string name){
		this->Name = name;
	}
	void SetFamily(string family){
		this->Family = family;
	}
	void SetSnn(int snn){
		int x , y;
		this->Snn = snn; // set snn
		string name , family , names;
		name = this->Name;// bardashtan avalin horof az name v family
		family = this->Family;
		if((int(family[0])<91) && (int(family[0])>64)){
			x = int(family[0]) + 32;
		}
		else{
			x = int(family[0]);
		}
		if((int(name[0])<91) && (int(name[0])>64)){
			y = int(name[0]) + 32;
		}
		else{
			y = int(name[0]);
		}
		names += char(y);
		names += char(x);
		string strsnn = snn + names;
		SetPersonalCode(strsnn);
	}
	void SetOperationCode(string code){
		this->OperationCode = code;
	}
	void SetPersonalCode(string code){
		this->PersonalCode = code;
		string tag = this->Name + this->Family + code;
		int x = this->Name.size() + this->Family.size() + 8;
		int sum = 0 ; 
		for(int i = 0 ; i<x ;i++){
			sum += int(tag[i]);
		}
		int tagnumber = sum % 220 ;
		SetTagCode(tagnumber);//set tag code;
	}
	void SetTagCode(int x){
		this->TagCode = x;
	}
	string GetName(){
		return this->Name;
	}

	string GetFamily(){
		return this->Family;
	}

	int GetSnn(){
		return this-> Snn ;
	}
	string GetOperationCode(){
		return this->OperationCode;
	}
	string GetPersonalCode(){
		return this->PersonalCode;
	}
	int GetTagCode(){
		return this->TagCode;
	}
};






int main(){
	string name , family , operationcode , personalcode , tagcode, snn;
	int marhale;
	int edame = 0 ;
	IMF *all;
	IMF *old;
	all = new IMF[10000];
	old = new IMF[10000];
	while(cin>>marhale){
		if(marhale == 1){ // sabte name
			int N_Er = 0 ;
			int tedad;
			cin>>tedad;
			IMF *New;
			New = new IMF[tedad];
			for(int i =0 ; i<tedad ; i++){
				N_Er = 0;
				cin>>name;
				cin>>family;
				cin>>snn;
				for(int j = 0 ;j<name.size() ; j++){ // check be string or int for name 
					if ((64<(int(name[j]))&& (int(name[j])<91)) || (96<(int(name[j])) && (int(name[j]))<123)){
						continue ;
					}
					else{
						N_Er+=1;
					}		
				}
				for(int j = 0 ;j<family.size() ; j++){// check be string or int for family
					if ((64<(int(family[j]))&& (int(family[j])<91)) || (96<(int(family[j])) && (int(family[j]))<123)){
						continue ;
					}
					else{
						N_Er+=1;
					}
				}
				int R_Snn = atoi(snn.c_str());
				if((R_Snn == 0) || (R_Snn/100000 == 0) || ((R_Snn/1000000)>0)){
					N_Er += 1 ;
				}
				for(int k = 0 ; k <(edame+tedad) ; k++){ // check kardan ke inke ghblan sabte name karde ya na
					if(all[k].GetSnn() == R_Snn){
						N_Er +=1;
						break;
					}
				}
					for(int k = 0 ; k <tedad ; k++){
						if(New[k].GetSnn() == R_Snn){
							N_Er +=1;
							break;
						}
				}
				if(N_Er == 0){ // register student
					New[i].SetName(name);
					New[i].SetFamily(family);
					New[i].SetSnn(R_Snn);
					cout<< "Spy " <<New[i].GetName()<<" "<<New[i].GetFamily()<<" with SSN:"<<New[i].GetSnn()<<" was registered successfully"<<endl;
				}
				if(N_Er !=0){
					cout<<"Your registration was unsuccessful"<<endl;
				}
			}
			for(int i = 0;i<edame;i++){  // rejister to all students
				all[i].SetName(old[i].GetName());
				all[i].SetFamily(old[i].GetFamily());
				all[i].SetSnn(old[i].GetSnn());
			}
			int i = edame;
			for(; i< (edame+tedad); i++){
				all[i].SetName(New[i-edame].GetName());
				all[i].SetFamily(New[i-edame].GetFamily());
				all[i].SetSnn(New[i-edame].GetSnn());
			}
			for(int i=0 ; i<edame+tedad ; i++){
				old[i].SetName(all[i].GetName());
				old[i].SetFamily(all[i].GetFamily());
				old[i].SetSnn(all[i].GetSnn());
			}
			edame= edame+ tedad;
		}
		if(marhale == 2){
			int number ;
			cin>>number;
			for(int i = 0 ; i<number ; i++){
				int N_Er = 0 ;
				int SNN ;
				string operation;
				cin >> SNN;
				cin >> operation;
				for(int j = 0 ; j<10000; j++){
					if(all[j].GetSnn() == SNN){
						if((operation != "IdiotErdogan") && (operation != "SaveRonaldo") && (operation != "PizzaHell")){ // check ke aya ghablan amaliate gerefte ya na
							N_Er+=1;
						}
						if(all[j].GetOperationCode() != "" ){
							N_Er +=1;
						}
						if(N_Er == 0 ){
							all[j].SetOperationCode( operation );
							string country;
							if(operation == "IdiotErdogan"){
								country = "Turkey";
							}
							if(operation == "SaveRonaldo"){
								country = "Portugal";
							}
							if(operation == "PizzaHell"){
								country = "Italy";
							}
							cout<< "Agent with personal code:"<<all[j].GetPersonalCode()<<" and tag:"<<all[j].GetTagCode()<<", We call you for an operation in "<<country<<endl;
							break;
						}
						else{
							cout<<"You couldn't register as an agent"<<endl;
							break;
						}						
					} 
					if(j == 9999){
							cout<<"You couldn't register as an agent"<<endl;
						}
				}
			}
			
		}
		if(marhale == 3){
			int number ;
			cin>>number;
			for(int i = 0 ; i<number ; i++){
				int TAg;
				int N_Er = 0 ;
				string rams;
				cin>>TAg;
				cin>>rams;
				for(int j = 0 ; j < 10000 ; j++){
					if(all[j].GetTagCode() == TAg){
						if(all[j].GetOperationCode() == ""){// check kardan ke ghablan amaliati sabt karde ya na
							N_Er +=1;
						}
						if(N_Er == 0){
							if(all[j].GetOperationCode() == "IdiotErdogan"){
								cout<<Caesar(rams)<<endl;
							}
							if(all[j].GetOperationCode() == "SaveRonaldo"){
								cout<<Playfair(rams)<<endl;
							}
							if(all[j].GetOperationCode() == "PizzaHell"){
								cout<<Vigenere(rams)<<endl;
							}
							
						}
						if(N_Er != 0){
							cout<<"WRONG"<<endl;
						}
						break;
						
					}
					if( j == 9999){
						cout<<"WRONG"<<endl;
					}
				}
			}
		}		
		if(marhale == 4){
			int number;
			cin>>number;
			for(int i = 0;i<number;i++){
				int TAg;
				int N_Er = 0 ;
				string rams;
				cin>>TAg;
				cin>>rams;
				string result;
				for(int j = 0 ; j < 10000 ; j++){
					int z = 0 ;
					if(all[j].GetTagCode() == TAg){
						if(all[j].GetOperationCode() == ""){
							N_Er +=1;
						}
						if(N_Er == 0){
							if(all[j].GetOperationCode() == "IdiotErdogan"){
								result = Caesar(rams) ; 
							}
							if(all[j].GetOperationCode() == "SaveRonaldo"){
								result = Playfair(rams);
							}
							if(all[j].GetOperationCode() == "PizzaHell"){
								result = Vigenere(rams);
							}
							for(int k = 0; k < rams.size() ; k++){
								if(result[k] == 'i'){
									if(result[k+1] == 'm'){
										if(result[k+2] == 'f'){
											cout<<"We get rid of tag:"<<all[j].GetTagCode()<<endl;
											all[j].SetName("");
											all[j].SetFamily("");
											all[j].SetSnn(0);
											all[j].SetOperationCode("");
											old[j].SetName("");
											old[j].SetFamily("");
											old[j].SetSnn(0);
											z++;											
										}
									}
								}
								if(z != 0 ){
									break;
								}
								if( k == (rams.size()-1)){
									N_Er +=1;
									break;
								}
							}							
						}
						if((N_Er != 0) && (z==0) ){
							cout<<"WRONG"<<endl;
							break;
						}						
					}
				if(z!= 0){
					break;
				}	
				if( j == 9999){
					if(z == 0){
						cout<<"WRONG"<<endl;
					}
				}
				}			
			}				
		}
		if(marhale == 5){
			int number = 0;
			for(int i = 0 ; i<10000 ; i++){
				if(all[i].GetName() !=""){
					number++;
				}
			}
			cout<<"We had "<<number<<" agent(s) in 2020"<<endl;
		}
		if(marhale == 6){
			int number = 0 ;
			string input;
			cin>>input;
			if((input!="IdiotErdogan") && (input != "SaveRonaldo") && (input != "PizzaHell")){
				cout<<"WRONG"<<endl;
			}
			if(input == "IdiotErdogan"){
				for(int i = 0 ; i<10000;i++){
					if(all[i].GetOperationCode() == "IdiotErdogan" ){
						number++;
					}
				}
				cout<<"We had "<<number<<" agent(s) in Turkey in 2020:"<<endl;
				for(int i = 0; i<10000 ; i++){
					if(all[i].GetOperationCode() == "IdiotErdogan"){
						cout<<"Agent with personal code:"<<all[i].GetPersonalCode()<<" and tag:"<<all[i].GetTagCode()<<endl;
					}
				}
			}
			if(input == "SaveRonaldo"){
				for(int i = 0 ; i<10000;i++){
					if(all[i].GetOperationCode() == "SaveRonaldo" ){
						number++;
					}
				}
				cout<<"We had "<<number<<" agent(s) in Portugal in 2020:"<<endl;
				for(int i = 0; i<10000 ; i++){
					if(all[i].GetOperationCode() == "SaveRonaldo"){
						cout<<"Agent with personal code:"<<all[i].GetPersonalCode()<<" and tag:"<<all[i].GetTagCode()<<endl;
					}
				}
			}
			if(input == "PizzaHell"){
				for(int i = 0 ; i<10000;i++){
					if(all[i].GetOperationCode() == "PizzaHell" ){
						number++;
					}
				}
				cout<<"We had "<<number<<" agent(s) in Italy in 2020:"<<endl;
				for(int i = 0; i<10000 ; i++){
					if(all[i].GetOperationCode() == "PizzaHell"){
						cout<<"Agent with personal code:"<<all[i].GetPersonalCode()<<" and tag:"<<all[i].GetTagCode()<<endl;
					}
				}
			}		
		}
	}
	return 1;
}


