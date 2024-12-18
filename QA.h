#pragma once
#include<string>
#include<iostream>
using namespace std;
class QA{
	private:
		string question;
		string answer;
		string choiceA;
		string choiceB;
		string choiceC;
		string choiceD;
	public:
		QA():question(""),answer(""),choiceA(""),choiceB(""),choiceC(""),choiceD(""){
		};
		QA(string q,string a,string cA,string cB,string cC,string cD): question(q),answer(a),choiceA(cA),choiceB(cB),choiceC(cC),choiceD(cD){
		};
		void setQuestion(string q){
			question = q;
		}
		void setAnswer(string a){
			answer = a;
		}
		void setChoiceA(string cA){
			choiceA = cA;
		}
		void setChoiceB(string cB){
			choiceB = cB;
		}
		void setChoiceC(string cC){
			choiceC = cC;
		}
		void setChoiceD(string cD){
			choiceD = cD;
		}
		string getQuestion(){
			return question;
		}
		string getAnswer(){
			return answer;
		}
		string getChoiceA(){
			return choiceA;
		}
		string getChoiceB(){
			return choiceB;
		}
		string getChoiceC(){
			return choiceC;
		}
		string getChoiceD(){
			return choiceD;
		}
		void AddQuestion(){
			cout<<"Nhap cau hoi: ";
			getline(cin,question);
			cout<<"Nhap lua chon A: ";
			getline(cin,choiceA);
			cout<<"Nhap lua chon B: ";
			getline(cin,choiceB);
			cout<<"Nhap lua chon C: ";
			getline(cin,choiceC);
			cout<<"Nhap lua chon D: ";
			getline(cin,choiceD);
			cout<<"Nhap dap an: ";
			getline(cin,answer);
		}
};
