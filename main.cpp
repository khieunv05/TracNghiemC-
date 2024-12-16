#include<graphics.h>
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<vector>
#include<windows.h>
//settextstyle(Kieu chu,huong chu,Co chu) (dieu chinh chu)
//outtextxy(vi tri x,vi tri y,text se in ra) (in chu)
//rectangle(x1,y1,x2,y2) (in ra hinh chu nhat theo toa do)
//setfillstyle(SOLID_FILL,mau) (to mau va thuong di cung voi bar de xac dinh vung can to)
//bar(x1,y1,x2,y2) (xac dinh vung to mau)
//ismouseclick(WM_LBUTTONDOWN) (kiem tra xem co duoc bam chuot trai chua) (khong clear trang thai cua chuot)
//getmouseclick(WM_LBUTTONDOWN,x1,y1) (Lay vi tri chuot trai vua bam vao 2 bien x1,y1)
using namespace std;
string FILENAME = "questions.txt";
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
class GiaoDien{
	public:
		void ManHinhLamBai(QA listQA){
			setfillstyle(SOLID_FILL,WHITE);
			bar(0,0,getmaxx(),getmaxy());
			setfillstyle(SOLID_FILL,BLUE);
			bar(0,0,getmaxx(),70);
			bar(0,0,30,getmaxy());
			bar(getmaxx(),0,getmaxx()-30,getmaxy());
			bar(0,getmaxy()-30,getmaxx(),getmaxy());
			setfillstyle(SOLID_FILL,LIGHTBLUE);
			bar(30,30,getmaxx()-30,120);
			setbkcolor(LIGHTBLUE);
			setcolor(WHITE);
			settextstyle(GOTHIC_FONT,0,5);
			outtextxy(600,50,(char *)"Lam bai tap");
			//cauhoi
			rectangle(200,150,getmaxx()-200,270);
			setfillstyle(SOLID_FILL,LIGHTGRAY);			
			bar(199,151,getmaxx()-199,269);
			//dapan A
			rectangle(100,320,getmaxx()-100,420);
			setfillstyle(SOLID_FILL,LIGHTGRAY);		
			bar(99,321,getmaxx()-99,419);
			//dapanB
			rectangle(100,430,getmaxx()-100,530);
			setfillstyle(SOLID_FILL,LIGHTGRAY);
			bar(99,431,getmaxx()-99,529);
			//dapanC
			rectangle(100,540,getmaxx()-100,640);
			setfillstyle(SOLID_FILL,LIGHTGRAY);
			bar(99,541,getmaxx()-99,639);
			//dapanD
			rectangle(100,650,getmaxx()-100,750);
			setfillstyle(SOLID_FILL,LIGHTGRAY);
			bar(99,651,getmaxx()-99,749);
			
			setcolor(BLACK);
			setbkcolor(LIGHTGRAY);
			outtextxy(230,170,const_cast<char*> (listQA.getQuestion().c_str()));	
			outtextxy(130,340,const_cast<char*> (listQA.getChoiceA().c_str()));
			outtextxy(130,450,const_cast<char*> (listQA.getChoiceB().c_str()));
			outtextxy(130,560,const_cast<char*> (listQA.getChoiceC().c_str()));
			outtextxy(130,670,const_cast<char*> (listQA.getChoiceD().c_str()));
}
		void MenuChuaCoCauHoi(){
			settextstyle(6,0,5);
			outtextxy(300,300,(char *)"Ban chua co cau hoi nao");
			outtextxy(100,600,(char *)"Quay ve menu chinh");
			rectangle(90,550,600,700);
}
		void menu(){
			setfillstyle(SOLID_FILL,WHITE);
			bar(0,0,getmaxx(),getmaxy());
			setbkcolor(BLACK);
			setcolor(BLACK);
			setfillstyle(SOLID_FILL,BLUE);
			bar(0,0,getmaxx(),100);
			int x1,y1;
			settextstyle(GOTHIC_FONT,0,5);
			setbkcolor(YELLOW);
			setfillstyle(SOLID_FILL,YELLOW);
			bar(450,50,1250,120);
			outtextxy(500,70,(char *)"ON TAP TRAC NGHIEM");
			bar(550,180,1100,250);
			outtextxy(700,200,(char *)"Lam bai");
			bar(550,380,1100,450);
			outtextxy(650,400,(char *)"Them cau hoi");
			bar(550,580,1100,650);
			outtextxy(650,600,(char *)"Sua cau hoi");
		
			int point[] = {0,900,0,580,200,900};
			setfillstyle(SOLID_FILL,LIGHTGRAY);
			fillpoly(4,point);
			int point2[]={1600,900,1600,580,1400,900};
			fillpoly(4,point2);
			readimagefile((char *)"SuaCauHoi.bmp",550,580,650,650);
			readimagefile((char *)"ThemCauHoi.bmp",550,380,650,450);
			readimagefile((char *)"TrangTri2.bmp",200,650,500,800);
			readimagefile((char *)"TrangTri.bmp",1100,650,1400,800);
			readimagefile((char *)"Lambai.bmp",550,180,650,250);
			setcolor(BLUE);
			setfillstyle(SOLID_FILL,BLUE);
			bar(0,0,30,getmaxy());
			bar(0,0,getmaxx(),30);
			bar(getmaxx()-30,0,getmaxx(),getmaxy());
			bar(0,getmaxy()-30,getmaxx(),getmaxy());
			
	
			//readimagefile("Test2.bmp",0,0,getmaxx(),getmaxy());
}
		void ManHinhMenuThemCauHoi(string question,string cA,string cB,string cC,string cD){
			setfillstyle(SOLID_FILL,WHITE);
			bar(0,0,getmaxx(),getmaxy());
			setfillstyle(SOLID_FILL,BLUE);
			bar(0,0,getmaxx(),70);
			bar(0,0,30,getmaxy());
			bar(getmaxx(),0,getmaxx()-30,getmaxy());
			bar(0,getmaxy()-30,getmaxx(),getmaxy());
			setfillstyle(SOLID_FILL,LIGHTBLUE);
			bar(30,30,getmaxx()-30,120);
			setbkcolor(LIGHTBLUE);
			setcolor(WHITE);
			outtextxy(580,50,(char *)"Tao cau hoi moi");
			setcolor(BLACK);
			outtextxy(getmaxx()-200,50,(char *)"Xong");
			setfillstyle(SOLID_FILL,BLACK);
			bar(getmaxx()-235,30,getmaxx()-230,120);//vach den
			
			setbkcolor(LIGHTGRAY);
			//boi xam phan dap an
			setfillstyle(SOLID_FILL,LIGHTGRAY);
			bar(1100,180,1350,250);
			rectangle(1100,180,1350,250);//dap an
			outtextxy(1120,195,(char *)"Dap an");
			//boi xam phan nhap cau hoi
			rectangle(100,170,900,270);
			bar(100,170,900,270);
			bar(150,300,850,400);
			bar(1120,300,1330,400);
			bar(150,430,850,530);
			bar(1120,430,1330,530);
			bar(150,560,850,660);
			bar(1120,560,1330,660);
			bar(150,690,850,790);
			bar(1120,690,1330,790);
			rectangle(150,300,850,400);
			setbkcolor(LIGHTBLUE);
			outtextxy(50,50,(char *)"Tro ve");
			
			rectangle(1120,300,1330,400);//hinh vuong A
			//outtextxy(110,240,(char *)"Nhap lua chon A");
			rectangle(150,430,850,530);
			rectangle(1120,430,1330,530);//hinh vuong B
			//outtextxy(110,410,(char *)"Nhap lua chon B");
			rectangle(150,560,850,660);
			rectangle(1120,560,1330,660);//hinh vuong C
			//outtextxy(110,580,(char *)"Nhap lua chon C");
			rectangle(150,690,850,790);
			rectangle(1120,690,1330,790);//hinh vuong A
			//outtextxy(110,750,(char *)"Nhap lua chon D");
			outtextxy(110,180,const_cast<char*>(question.c_str()));
			outtextxy(160,310,const_cast<char*>(cA.c_str()));
			outtextxy(160,440,const_cast<char*>(cB.c_str()));
			outtextxy(160,570,const_cast<char*>(cC.c_str()));
			outtextxy(160,700,const_cast<char*>(cD.c_str()));
			
}
		void ManHinhXacNhanThemCauHoi(){
			cleardevice();
			outtextxy(200,200,(char *)"Ban co muon them khong?");
			rectangle(190,200,1000,400);
			outtextxy(300,350,(char *)"Co");
			outtextxy(700,350,(char *)"Khong");
			rectangle(290,300,390,400);
			rectangle(690,300,890,400);
		}
		void ManHinhLuaChonRandom(){
			cleardevice();
			int x1,y1;
			outtextxy(200,200,(char *)"Ban co muon random cau hoi khong?");
			outtextxy(200,400,(char *)"Co");
			outtextxy(1010,400,(char *)"Khong");
			rectangle(100,300,400,500);
			rectangle(1000,300,1300,500);
}
		void ManHinhHoanThanhLamBai(vector<QA> & listQA,int &diem){
			setcolor(WHITE);
			setbkcolor(BLACK);
			setfillstyle(SOLID_FILL,BLACK);
			cleardevice();
			string score = to_string(diem);
			string soCau = to_string(listQA.size());
			string last = score + "/" + soCau;
			settextstyle(6,0,5);
			outtextxy(500,300,(char *)"Ban da lam het cau hoi");
			outtextxy(700,400,const_cast<char*>(last.c_str()));
			outtextxy(300,600,(char *)"ve menu");
			rectangle(250,500,600,700);
}
		void ManHinhThieuThongTin(){
			cleardevice();
			outtextxy(300,300,(char *)"Ban nhap thieu thong tin");
			delay(2000);
			cleardevice();
		}	
		
};
class BamChuot{
	public:
		bool BamChuotMenuThemCauHoi(int x1,int y1){
			if((x1>=100 && x1<=900) && (y1>=170 && y1<=270) ||(x1>=150 && x1<=850) && (y1>=300 && y1<=400) ||
				(x1>=150 && x1<=850) && (y1>=430 && y1<=530) ||
				(x1>=150 && x1<=850) && (y1>=560 && y1<=660) ||
				(x1>=150 && x1<=850) && (y1>=690 && y1<=790) ||
				( (x1>=1120 && x1<=1330) && (y1>=300 && y1<=400))||
				( (x1>=1120 && x1<=1330) && (y1>=430 && y1<=530))||
				( (x1>=1120 && x1<=1330) && (y1>=560 && y1<=660))||
				( (x1>=1120 && x1<=1330) && (y1>=690 && y1<=790))||
				( (x1>=1365 && x1<=1600) && (y1>=0 && y1<=120))
				||( (x1>=0 && x1<=200) && (y1>=0 && y1<=120))
				) return true;
			return false;
}
		bool BamChuotManHinhSuaCauHoi(int x1,int y1){
			if(((x1>=290 && x1<=1200) && (y1>=190 && y1<=240))||
					((x1>=290 && x1<=1200) && (y1>=290 && y1<=340))||
					((x1>=290 && x1<=1200) && (y1>=390 && y1<=440))||
					((x1>=290 && x1<=1200) && (y1>=490 && y1<=540))||
					((x1>=290 && x1<=1200) && (y1>=590 && y1<=640))||
					((x1>=990 && x1<=1150) && (y1>=790 && y1<=890))||
					((x1>=90 && x1<=410) && (y1>=790 && y1<=890))||
					((x1>=1190 && x1<=1320) && (y1>=90 && y1<=190))
				 ) return true;
				return false;
		}
		bool BamChuotManHinhLamBai(int x1,int y1){
			if(((x1>=100 && x1<=1500 ) && (y1>=320 && y1<=420))||
			((x1>=100 && x1<=1500 ) && (y1>=430 && y1<=530))||
			((x1>=100 && x1<=1500 ) && (y1>=540 && y1<=640))||
			((x1>=100 && x1<=1500 ) && (y1>=650 && y1<=750))
			) return true;
			return false;
}
		bool BamChuotManHinhChuaCoCauHoi(int x1,int y1){
			if((x1>=0 && x1<=600) && (y1>=500 && y1<=700)) return true;
			return false;
		}
		bool BamChuotManHinhMenu(int x1,int y1){
			
			if(((x1>=550 && x1<=1100) && (y1>= 180 && y1<=250))||
				((x1>=550&& x1<=1100) && (y1>=380 && y1<=450))||
				((x1>=550&& x1<=1100) && (y1>=580 && y1<=650))
			) return true;
			return false;
}
		bool BamChuotManHinhXacNhanThemCauHoi(int x1,int y1){
			if((x1>=290 && x1<=390) && (y1>=300 && y1<=400) || ((x1>=690 && x1<=890) && (y1>=300 && y1<=400))) return true;
			return false;
		}
		bool BamChuotManHinhLuaChonRandom(int x1,int y1){
			if((x1>=100 && x1<=400) && (y1 >= 300 && y1<=500) || ((x1>=1000 && x1<=1200) && (y1>=300 && y1<=500)) ) return true;
			return false;
		}
		bool BamChuotManHinhHoanThanhLamBai(int x1,int y1,vector<QA> & listQA,int &diem){
			if(((x1>=100 && x1<=500) && (y1>=500 && y1<=700) ) )return true;
			return false;
	/* TODO (#1#): Sua lai loi
 */
}
};
bool isFileEmpty(string &fileName){
	ifstream file(fileName,ios::ate);
	return file.tellg()==0;
}
void ChucNangSuaCauHoi(int &hienthi,vector<QA> &tempQA,vector<QA> &newQA){
	bool suaCauHoi=0;
	string cauHoi,cauTraLoi,luaChonA,luaChonB,luaChonC,luaChonD;
	int dapAn;
	char ch;
	int x1,y1;
	cleardevice();
	GiaoDien giaoDien;
	BamChuot bamChuot;
	ifstream inFile(FILENAME);
	string line;
	vector<QA> listQA;
	int heSo=0;
	while(getline(inFile,line)){
		QA a;
		a.setQuestion(line);
		getline(inFile,line);
		a.setAnswer(line);
		getline(inFile,line);
		a.setChoiceA(line);
		getline(inFile,line);
		a.setChoiceB(line);
		getline(inFile,line);
		a.setChoiceC(line);
		getline(inFile,line);
		a.setChoiceD(line);
		listQA.push_back(a);
	}
	for(int i =0;i<listQA.size();i++){
		cout<<i<<endl;
		int j = i%5;
		outtextxy(300,200+j*100,const_cast<char *>( listQA[i].getQuestion().c_str()));
		rectangle(290,190+j*100,1200,190+50+j*100);
		if((((i%4 ==0 && i<=4 ) || (i%5==4 && i>5) )&& (i!=0)) || (i == listQA.size()-1)){
			outtextxy(1000,800,(char *)"Tiep");
			rectangle(990,790,1150,890);
			outtextxy(100,800,(char*)"Quay lai");
			outtextxy(1200,100,(char*)"Xong");
			rectangle(90,790,410,890);
			rectangle(1190,90,1320,190);
			while(true){
				getmouseclick(WM_LBUTTONDOWN,x1,y1);
				if(bamChuot.BamChuotManHinhSuaCauHoi(x1,y1))break;
				delay(10);
			}
			
			cleardevice();
			if(((x1>=990 && x1<=1150) && (y1>=790 && y1<=890))){
				heSo=heSo+5;
				continue;
			}
			if(((x1>=90 && x1<=410) && (y1>=790 && y1<=890))){
				if(heSo-5<0) heSo =0;
				else	heSo=heSo-5;
				if((i-6) % 5 !=0){
					int m = (i-6)/5;
					i = m*5;
					i = i-1;
				}
				else{
					i = i-6;
				}
				continue;
			}
			if(((x1>=1190 && x1<=1320) && (y1>=90 && y1<=190))){
				hienthi=1;
				break;	
			}
			int k = (y1-150)/100+heSo;
			giaoDien.ManHinhMenuThemCauHoi(listQA[k].getQuestion(),listQA[k].getChoiceA(),
			listQA[k].getChoiceB(),listQA[k].getChoiceC(),listQA[k].getChoiceD());
			cauHoi=listQA[k].getQuestion();
			cauTraLoi=listQA[k].getAnswer();
			luaChonA=listQA[k].getChoiceA();
			luaChonB=listQA[k].getChoiceB();
			luaChonC=listQA[k].getChoiceC();
			luaChonD=listQA[k].getChoiceD();
			heSo = heSo+5;
			while(true){
			getmouseclick(WM_LBUTTONDOWN,x1,y1);
				if(listQA[k].getAnswer()==listQA[k].getChoiceA()){
					setfillstyle(SOLID_FILL,GREEN);
					bar(1120,300,1330,400);
					dapAn=1;
				}
				if(listQA[k].getAnswer()==listQA[k].getChoiceB()){
					setfillstyle(SOLID_FILL,GREEN);
					bar(1120,430,1330,530);
					dapAn=2;
					}
				if(listQA[k].getAnswer()==listQA[k].getChoiceC()){
					setfillstyle(SOLID_FILL,GREEN);
					bar(1120,560,1330,660);
					dapAn=3;
					}
				if(listQA[k].getAnswer()==listQA[k].getChoiceD()){
					setfillstyle(SOLID_FILL,GREEN);
					bar(1120,690,1330,790);
					dapAn=4;
					}
				if((x1>=100 && x1<=900) && (y1>=170 && y1<=270)){
				setfillstyle(SOLID_FILL,GREEN);
				bar(100,170,900,270);
				outtextxy(110,180,const_cast<char*>(listQA[k].getQuestion().c_str()));
				
			}
			
				if((x1>=150 && x1<=850) && (y1>=300 && y1<=400)){
					setfillstyle(SOLID_FILL,GREEN);
					bar(150,300,850,400);
						outtextxy(160,310,const_cast<char*>(listQA[k].getChoiceA().c_str()));
				}
				if((x1>=150 && x1<=850) && (y1>=430 && y1<=530)){
					setfillstyle(SOLID_FILL,GREEN);
					bar(150,430,850,530);
					outtextxy(160,440,const_cast<char*>(listQA[k].getChoiceB().c_str()));
				}
				if((x1>=150 && x1<=850) && (y1>=560 && y1<=660)){
					setfillstyle(SOLID_FILL,GREEN);
					bar(150,560,850,660);
					outtextxy(160,570,const_cast<char*>(listQA[k].getChoiceC().c_str()));
				}
				if((x1>=150 && x1<=850) && (y1>=690 && y1<=790)){
					setfillstyle(SOLID_FILL,GREEN);
					bar(150,690,850,790);
					outtextxy(160,700,const_cast<char*>(listQA[k].getChoiceD().c_str()));
				}
				if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
				delay(10);
			}
			while(true){
				if((x1>=100 && x1<=900) && (y1>=170 && y1<=270)){
					while(!kbhit()) delay(10);
					if(kbhit()){
						ch=getch();
						if(ch==13) 	{
							setfillstyle(SOLID_FILL,LIGHTGRAY);
							bar(100,170,900,270);
							rectangle(100,170,900,270);
							outtextxy(110,180,const_cast<char*>(listQA[k].getQuestion().c_str()));
							while(true){
								getmouseclick(WM_LBUTTONDOWN,x1,y1);
								if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
									delay(10);
			}
						}
						else if(ch==8){
							string question =listQA[k].getQuestion();
							question.pop_back(); 
							if(!listQA[k].getQuestion().empty()) listQA[k].setQuestion(question);
						}
						else listQA[k].setQuestion(listQA[k].getQuestion()+ch);
					}
				}
				else if((x1>=150 && x1<=850) && (y1>=300 && y1<=400)){
					while(!kbhit()) delay(10);
					if(kbhit()){
						ch=getch();
							if(ch==13) 	{
								setfillstyle(SOLID_FILL,LIGHTGRAY);
								bar(150,300,850,400);
								rectangle(150,300,850,400);
								outtextxy(160,310,const_cast<char*>(listQA[k].getChoiceA().c_str()));
								while(true){
									getmouseclick(WM_LBUTTONDOWN,x1,y1);
									if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
									delay(10);
			}
							}
						
							else if(ch==8){
								string cA =listQA[k].getChoiceA();
								cA.pop_back(); 
								if(!listQA[k].getChoiceA().empty()) listQA[k].setChoiceA(cA);
						}
						else listQA[k].setChoiceA(listQA[k].getChoiceA()+ch);
					}
					}
				else if((x1>=150 && x1<=850) && (y1>=430 && y1<=530)){
					while(!kbhit()) delay(10);
					if(kbhit()){
						ch=getch();
							if(ch==13) {
								setfillstyle(SOLID_FILL,LIGHTGRAY);
								bar(150,430,850,530);
								rectangle(150,430,850,530);
								outtextxy(160,440,const_cast<char*>(listQA[k].getChoiceB().c_str()));
								while(true){
									getmouseclick(WM_LBUTTONDOWN,x1,y1);
									if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
									delay(10);
			}
							}
						else if(ch==8){
							string cB =listQA[k].getChoiceB();
							cB.pop_back(); 
							if(!listQA[k].getChoiceB().empty()) listQA[k].setChoiceB(cB);
						}
						else listQA[k].setChoiceB(listQA[k].getChoiceB()+ch);
					}
				}
				else if((x1>=150 && x1<=850) && (y1>=560 && y1<=660)){
					while(!kbhit()) delay(10);
					if(kbhit()){
						ch=getch();
							if(ch==13) {
								setfillstyle(SOLID_FILL,LIGHTGRAY);
								bar(150,560,850,660);
								rectangle(150,560,850,660);
								outtextxy(160,570,const_cast<char*>(listQA[k].getChoiceC().c_str()));
								while(true){
									getmouseclick(WM_LBUTTONDOWN,x1,y1);
									if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
									delay(10);
			}
							}
						
						else if(ch==8){
							string cC =listQA[k].getChoiceC();
							cC.pop_back(); 
							if(!listQA[k].getChoiceC().empty()) listQA[k].setChoiceC(cC);
						}
						else listQA[k].setChoiceC(listQA[k].getChoiceC()+ch);
					}
					}
				else if((x1>=150 && x1<=850) && (y1>=690 && y1<=790)){
					while(!kbhit()) delay(10);
					if(kbhit()){
						ch=getch();
							if(ch==13) {
								setfillstyle(SOLID_FILL,LIGHTGRAY);
								bar(150,690,850,790);
								rectangle(150,690,850,790);
								outtextxy(160,700,const_cast<char*>(listQA[k].getChoiceD().c_str()));
								while(true){
									getmouseclick(WM_LBUTTONDOWN,x1,y1);
									if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
									delay(10);
			}
							}
						else if(ch==8){
							string cD =listQA[k].getChoiceD();
							cD.pop_back(); 
							if(!listQA[k].getChoiceD().empty()) listQA[k].setChoiceD(cD);
						}
						else listQA[k].setChoiceD(listQA[k].getChoiceD()+ch);
					}
				}
				/* TODO (#1#): Fix lai chuc nang nguoi dung
		 */
				
		
				else if((x1>=1300 && x1<=1800) && (y1>=0 && y1<=300)){
					if(listQA[k].getChoiceA() == "" || listQA[k].getChoiceB() == "" ||
					 listQA[k].getChoiceC() == "" || listQA[k].getChoiceD() == "" || listQA[k].getQuestion() == "" || listQA[k].getAnswer() == ""){
						giaoDien.ManHinhThieuThongTin();
						giaoDien.ManHinhMenuThemCauHoi(listQA[k].getQuestion(),
						listQA[k].getChoiceA(),
						listQA[k].getChoiceB(),
						listQA[k].getChoiceC(),
						listQA[k].getChoiceD());
						if(dapAn==1){
							setfillstyle(SOLID_FILL,GREEN);
							bar(1100,270,1300,370);
							listQA[k].setAnswer(listQA[k].getChoiceA());
						}
						if(dapAn==2){
							setfillstyle(SOLID_FILL,GREEN);
							bar(1100,440,1300,540);
							listQA[k].setAnswer(listQA[k].getChoiceB());
						}
						if(dapAn==3){
							setfillstyle(SOLID_FILL,GREEN);
							bar(1100,610,1300,710);
							listQA[k].setAnswer(listQA[k].getChoiceC());
						}
						if(dapAn==4){
							setfillstyle(SOLID_FILL,GREEN);
							bar(1100,780,1300,880);
							listQA[k].setAnswer(listQA[k].getChoiceD());
						}
						outtextxy(110,180,const_cast<char*>(listQA[k].getQuestion().c_str()));
						outtextxy(160,310,const_cast<char*>(listQA[k].getChoiceA().c_str()));
						outtextxy(160,440,const_cast<char*>(listQA[k].getChoiceB().c_str()));
						outtextxy(160,570,const_cast<char*>(listQA[k].getChoiceC().c_str()));
						outtextxy(160,700,const_cast<char*>(listQA[k].getChoiceD().c_str()));
						delay(10);
						while(true){
							getmouseclick(WM_LBUTTONDOWN,x1,y1);
							if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
									delay(10);
			}	
					}
					else{
						int x2,y2;
						giaoDien.ManHinhXacNhanThemCauHoi();
						while(true){
							getmouseclick(WM_LBUTTONDOWN,x2,y2);
							if((x2>=290 && x2<=390) && (y2>=300 && y2<=400) || ((x2>=690 && x2<=890) && (y2>=300 && y2<=400))) break;
							delay(10);
						}
						if((x2>=290 && x2<=390) && (y2>=300 && y2<=400)){
							setbkcolor(BLACK);
		                    setfillstyle(SOLID_FILL,BLACK);
			                setcolor(WHITE);
							suaCauHoi=1;
							cleardevice();
							break;
							delay(10);
				}
						else{
							/* TODO (#1#): Sua loi
	 */
							cleardevice();
							giaoDien.ManHinhMenuThemCauHoi(listQA[k].getQuestion(),
							listQA[k].getChoiceA(),
							listQA[k].getChoiceB(),
							listQA[k].getChoiceC(),
							listQA[k].getChoiceD());
							if(dapAn==1){
								setfillstyle(SOLID_FILL,GREEN);
								bar(1100,270,1300,370);
								listQA[k].setAnswer(listQA[k].getChoiceA());
							}
							if(dapAn==2){
								setfillstyle(SOLID_FILL,GREEN);
								bar(1100,440,1300,540);
								listQA[k].setAnswer(listQA[k].getChoiceB());
							}
							if(dapAn==3){
								setfillstyle(SOLID_FILL,GREEN);
								bar(1100,610,1300,710);
								listQA[k].setAnswer(listQA[k].getChoiceC());
							}
							if(dapAn==4){
								setfillstyle(SOLID_FILL,GREEN);
								bar(1100,780,1300,880);
								listQA[k].setAnswer(listQA[k].getChoiceD());
							}
							
							outtextxy(110,180,const_cast<char*>(listQA[k].getQuestion().c_str()));
							outtextxy(160,310,const_cast<char*>(listQA[k].getChoiceA().c_str()));
							outtextxy(160,440,const_cast<char*>(listQA[k].getChoiceB().c_str()));
							outtextxy(160,570,const_cast<char*>(listQA[k].getChoiceC().c_str()));
							outtextxy(160,700,const_cast<char*>(listQA[k].getChoiceD().c_str()));
							delay(10);
							while(true){
								getmouseclick(WM_LBUTTONDOWN,x1,y1);
								if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
										delay(10);
			}
				}
			}
				}
				else if((x1>=1120 && x1<=1330) && (y1>=300 && y1<= 400)){
					
					setfillstyle(SOLID_FILL,BLACK);
					bar(1120,300,1330,400);
			
					bar(1120,430,1330,530);
					
					bar(1120,560,1330,660);
				
					bar(1120,690,1330,790);
				
					
					setfillstyle(SOLID_FILL,GREEN);
					bar(1120,300,1330,400);
			
					dapAn=1;
					listQA[k].setAnswer(listQA[k].getChoiceA());
					while(true){
						getmouseclick(WM_LBUTTONDOWN,x1,y1);
						if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
						delay(10);
			}
				}
				else if((x1>=1120 && x1<=1330) && (y1>=430 && y1<= 530)){
					setfillstyle(SOLID_FILL,BLACK);
					bar(1120,300,1330,400);
			
					bar(1120,430,1330,530);
					
					bar(1120,560,1330,660);
				
					bar(1120,690,1330,790);
					setfillstyle(SOLID_FILL,GREEN);
					bar(1120,430,1330,530);
					dapAn=2;
					listQA[k].setAnswer(listQA[k].getChoiceB());
					while(true){
						getmouseclick(WM_LBUTTONDOWN,x1,y1);
						if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
									delay(10);
			}
				}
				else if((x1>=1120 && x1<=1330) && (y1>=560 && y1<= 660)){
					setfillstyle(SOLID_FILL,BLACK);
					bar(1120,300,1330,400);
			
					bar(1120,430,1330,530);
					
					bar(1120,560,1330,660);
				
					bar(1120,690,1330,790);
					setfillstyle(SOLID_FILL,GREEN);
					bar(1120,560,1330,660);
					dapAn=3;
					listQA[k].setAnswer(listQA[k].getChoiceC());
					while(true){
						getmouseclick(WM_LBUTTONDOWN,x1,y1);
						if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
									delay(10);
			}
				}
				else if((x1>=1120 && x1<=1330) && (y1>=690 && y1<= 790)){
					setfillstyle(SOLID_FILL,BLACK);
					bar(1120,300,1330,400);
			
					bar(1120,430,1330,530);
					
					bar(1120,560,1330,660);
				
					bar(1120,690,1330,790);
					setfillstyle(SOLID_FILL,GREEN);
					bar(1120,690,1330,790);
					dapAn=4;
					listQA[k].setAnswer(listQA[k].getChoiceD());
					while(true){
						getmouseclick(WM_LBUTTONDOWN,x1,y1);
						if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
						delay(10);
			}
				}
				else if((x1>=0 && x1<=200) && (y1>=0 && y1<=120)){
					    setbkcolor(BLACK);
					    setcolor(WHITE);
						cleardevice();
						break;
					}
				cleardevice();
				giaoDien.ManHinhMenuThemCauHoi(listQA[k].getQuestion(),
						listQA[k].getChoiceA(),
						listQA[k].getChoiceB(),
						listQA[k].getChoiceC(),
						listQA[k].getChoiceD());
				
				if(dapAn==1){
					setfillstyle(SOLID_FILL,GREEN);
					bar(1120,300,1330,400);
					listQA[k].setAnswer(listQA[k].getChoiceA());
						}
				if(dapAn==2){
					setfillstyle(SOLID_FILL,GREEN);
					bar(1120,430,1330,530);
					listQA[k].setAnswer(listQA[k].getChoiceB());
						}
				if(dapAn==3){
					setfillstyle(SOLID_FILL,GREEN);
					bar(1120,560,1330,660);
					listQA[k].setAnswer(listQA[k].getChoiceC());
						}
				if(dapAn==4){
					setfillstyle(SOLID_FILL,GREEN);
					bar(1120,690,1330,790);
					listQA[k].setAnswer(listQA[k].getChoiceD());
						}
				if((x1>=100 && x1<=900) && (y1>=170 && y1<=270)){
				setfillstyle(SOLID_FILL,GREEN);
				bar(100,170,900,270);
			}
				if((x1>=150 && x1<=850) && (y1>=300 && y1<=400)){
					setfillstyle(SOLID_FILL,GREEN);
					bar(150,300,850,400);
				}
				if((x1>=150 && x1<=850) && (y1>=430 && y1<=530)){
					setfillstyle(SOLID_FILL,GREEN);
					bar(150,430,850,530);
				}
				if((x1>=150 && x1<=850) && (y1>=560 && y1<=660)){
					setfillstyle(SOLID_FILL,GREEN);
					bar(150,560,850,660);
				}
				if((x1>=150 && x1<=850) && (y1>=690 && y1<=790)){
					setfillstyle(SOLID_FILL,GREEN);
					bar(150,690,850,790);
				}
				while(kbhit()){
						getch();
					}
				outtextxy(110,180,const_cast<char*>(listQA[k].getQuestion().c_str()));
				outtextxy(160,310,const_cast<char*>(listQA[k].getChoiceA().c_str()));
				outtextxy(160,440,const_cast<char*>(listQA[k].getChoiceB().c_str()));
				outtextxy(160,570,const_cast<char*>(listQA[k].getChoiceC().c_str()));
				outtextxy(160,700,const_cast<char*>(listQA[k].getChoiceD().c_str()));
				delay(10);
			}
			if(suaCauHoi==0){
				listQA[k].setQuestion(cauHoi);
				listQA[k].setAnswer(cauTraLoi);
				listQA[k].setChoiceA(luaChonA);
				listQA[k].setChoiceB(luaChonB);
				listQA[k].setChoiceC(luaChonC);
				listQA[k].setChoiceD(luaChonD);
		}
			}
			setbkcolor(BLACK);
			setfillstyle(SOLID_FILL,BLACK);
			setcolor(WHITE);
		}
			ofstream outFile(FILENAME);
			while(tempQA.size()!=0) tempQA.erase(tempQA.begin()+0);
			while(newQA.size()!=0) newQA.erase(newQA.begin()+0);
			for(int i =0;i<listQA.size();i++){
				tempQA.push_back(listQA[i]);
				newQA.push_back(listQA[i]);
				if(isFileEmpty(FILENAME)){
				outFile<<listQA[i].getQuestion()<<endl;
				outFile<<listQA[i].getAnswer()<<endl;
				outFile<<listQA[i].getChoiceA()<<endl;
				outFile<<listQA[i].getChoiceB()<<endl;
				outFile<<listQA[i].getChoiceC()<<endl;
				outFile<<listQA[i].getChoiceD();
							}
			else{
				outFile<<endl<<listQA[i].getQuestion()<<endl;
				outFile<<listQA[i].getAnswer()<<endl;
				outFile<<listQA[i].getChoiceA()<<endl;
				outFile<<listQA[i].getChoiceB()<<endl;
				outFile<<listQA[i].getChoiceC()<<endl;
				outFile<<listQA[i].getChoiceD();
						}
			}
			outFile.close();
}
void clickmouse(QA a,int &diem,vector<QA> & wrongQA){
	BamChuot bamChuot;
	string ans;
	int x1,y1;
	while(true){
		getmouseclick(WM_LBUTTONDOWN,x1,y1);
		if(bamChuot.BamChuotManHinhLamBai(x1,y1))
		 break;
		delay(10);
	}
	if((x1>=100 && x1<=1500 ) && (y1>=320 && y1<=420)){
		ans = a.getChoiceA();
	}
	if((x1>=100 && x1<=1500 ) && (y1>=430 && y1<=530)){
		ans = a.getChoiceB();
	}
	if((x1>=100 && x1<=1500 ) && (y1>=540 && y1<=640)){
		ans = a.getChoiceC();
	}
	if((x1>=100 && x1<=1500 ) && (y1>=650 && y1<=750)){
		ans = a.getChoiceD();
	}
	if(a.getAnswer() == a.getChoiceA()){
		setfillstyle(SOLID_FILL,RED);
		bar(99,321,getmaxx()-99,419);
		setbkcolor(RED);
		settextstyle(6,0,6);
		outtextxy(160,330,const_cast<char*> (a.getChoiceA().c_str()));
	}
	if(a.getAnswer() == a.getChoiceB()){
		setfillstyle(SOLID_FILL,RED);
		bar(99,431,getmaxx()-99,529);
		setbkcolor(RED);
		settextstyle(6,0,6);
		outtextxy(160,440,const_cast<char*> (a.getChoiceB().c_str()));
	}
	if(a.getAnswer() == a.getChoiceC()){
		setfillstyle(SOLID_FILL,RED);
		bar(99,541,getmaxx()-99,639);
		setbkcolor(RED);
		settextstyle(6,0,6);
		outtextxy(160,550,const_cast<char*> (a.getChoiceC().c_str()));
	}
	if(a.getAnswer() == a.getChoiceD()){
		setfillstyle(SOLID_FILL,RED);
		bar(99,651,getmaxx()-99,749);
		setbkcolor(RED);
		settextstyle(6,0,6);
		outtextxy(160,660,const_cast<char*> (a.getChoiceD().c_str()));
	}
	if(ans == a.getAnswer()){
		diem++;
	}
	else{
		wrongQA.push_back(a);
		}
	}
void ChucNangChuaCoCauHoi(int &hienthi){
	GiaoDien giaoDien;
	BamChuot bamChuot;
	int x1,y1;
	giaoDien.MenuChuaCoCauHoi();
	while(true){
		getmouseclick(WM_LBUTTONDOWN,x1,y1);
		if(bamChuot.BamChuotManHinhChuaCoCauHoi(x1,y1)) break;
		delay(10);
	}
	if((x1>=0 && x1<=600) && (y1>=500 && y1<=700)) hienthi=1;
}
void ChucNangMenu(vector<QA> &listQA,int &hienthi){
	int x1,y1;
	GiaoDien giaoDien;
	BamChuot bamChuot;
	giaoDien.menu();
	while(true){
		getmouseclick(WM_LBUTTONDOWN,x1,y1);
		if(bamChuot.BamChuotManHinhMenu(x1,y1)) break;
		delay(10);
	}
	if((x1>=550 && x1<=1100) && (y1>=380 && y1<=450)){
		hienthi=2;
	}
	if((x1>=550 && x1<=1100) && (y1>=580 && y1<=650)){
		hienthi=6; // hienthi=6 sua cau hoi
	}
	if((x1>=550 && x1<=1100) && (y1>=180 && y1<=250)){
		if(listQA.size() ==0){
			cleardevice();
			hienthi=5; // Hienthi =5 de hien thi menu thong bao chua co cau hoi
		}
		else hienthi=3;
	}
}

void ChucNangThemCauHoi(vector<QA> &listQA,vector<QA> &tempQA,int &hienthi){
	GiaoDien giaoDien;
	BamChuot bamChuot;
	int x1,y1,dapAn=0;
	QA a;
	string question;
	string ans,cA,cB,cC,cD;
	char ch;
	giaoDien.ManHinhMenuThemCauHoi(question,cA,cB,cC,cD);
	while(true){
		getmouseclick(WM_LBUTTONDOWN,x1,y1);
		if((x1>=100 && x1<=900) && (y1>=170 && y1<=270)){
			setfillstyle(SOLID_FILL,GREEN);
			bar(100,170,900,270);
		}
		
		if((x1>=150 && x1<=850) && (y1>=300 && y1<=400)){
			setfillstyle(SOLID_FILL,GREEN);
			bar(150,300,850,400);
		}
		if((x1>=150 && x1<=850) && (y1>=430 && y1<=530)){
			setfillstyle(SOLID_FILL,GREEN);
			bar(150,430,850,530);
		}
		if((x1>=150 && x1<=850) && (y1>=560 && y1<=660)){
			setfillstyle(SOLID_FILL,GREEN);
			bar(150,560,850,660);
		}
		if((x1>=150 && x1<=850) && (y1>=690 && y1<=790)){
			setfillstyle(SOLID_FILL,GREEN);
			bar(150,690,850,790);
		}
		if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
		delay(10);
	}
		
	while(true){
		if((x1>=100 && x1<=900) && (y1>=170 && y1<=270)){
			while(!kbhit()) delay(10);
			if(kbhit()){
				ch=getch();
				if(ch==13) {
					clearmouseclick(WM_LBUTTONDOWN);
					setfillstyle(SOLID_FILL,LIGHTGRAY);
					bar(100,170,900,270);
					rectangle(100,170,900,270);
					outtextxy(110,180,const_cast<char*>(question.c_str()));
					while(true){
						getmouseclick(WM_LBUTTONDOWN,x1,y1);
						if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
							delay(10);
	}
				}
				else if(ch==8){
					if(!question.empty()) question.pop_back();
				}
				else question = question+ch;
			}
		}
		else if((x1>=150 && x1<=850) && (y1>=300 && y1<=400)){
			while(!kbhit()) delay(10);
			if(kbhit()){
				ch=getch();
					if(ch==13) 	{
						clearmouseclick(WM_LBUTTONDOWN);
						setfillstyle(SOLID_FILL,LIGHTGRAY);
						bar(150,300,850,400);
						rectangle(150,300,850,400);
						outtextxy(160,310,const_cast<char*>(cA.c_str()));
						while(true){
							getmouseclick(WM_LBUTTONDOWN,x1,y1);
							if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
							delay(10);
	}
					}
				
					else if(ch==8){
						if(!cA.empty()) cA.pop_back();
				}
				else cA = cA+ch;
			}
			}
		else if((x1>=150 && x1<=850) && (y1>=430 && y1<=530)){
			while(!kbhit()) delay(10);
			if(kbhit()){
				ch=getch();
					if(ch==13) {
						clearmouseclick(WM_LBUTTONDOWN);
						setfillstyle(SOLID_FILL,LIGHTGRAY);
						bar(150,430,850,530);
						rectangle(150,430,850,530);
						outtextxy(160,440,const_cast<char*>(cB.c_str()));
						while(true){
							getmouseclick(WM_LBUTTONDOWN,x1,y1);
							if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
							delay(10);
	}
					}
				else if(ch==8){
					if(!cB.empty()) cB.pop_back();
				}
				else cB = cB+ch;
			}
		}
		else if((x1>=150 && x1<=850) && (y1>=560 && y1<=660)){
			while(!kbhit()) delay(10);
			if(kbhit()){
				ch=getch();
					if(ch==13) {
						clearmouseclick(WM_LBUTTONDOWN);
						setfillstyle(SOLID_FILL,LIGHTGRAY);
						bar(150,560,850,660);
						rectangle(150,560,850,660);
						outtextxy(160,570,const_cast<char*>(cC.c_str()));
						while(true){
							getmouseclick(WM_LBUTTONDOWN,x1,y1);
							if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
							delay(10);
	}
					}
				
				else if(ch==8){
					if(!cC.empty()) cC.pop_back();
				}
				else cC = cC+ch;
			}
			}
		else if((x1>=150 && x1<=850) && (y1>=690 && y1<=790)){
			while(!kbhit()) delay(10);
			if(kbhit()){
				ch=getch();
					if(ch==13) {
						clearmouseclick(WM_LBUTTONDOWN);
						setfillstyle(SOLID_FILL,LIGHTGRAY);
						bar(150,690,850,790);
						rectangle(150,690,850,790);
						outtextxy(160,700,const_cast<char*>(cD.c_str()));
						while(true){
							getmouseclick(WM_LBUTTONDOWN,x1,y1);
							if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
							delay(10);
	}
					}
				else if(ch==8){
					if(!cD.empty()) cD.pop_back();
				}
				else cD = cD+ch;
			}
		}
		/* TODO (#1#): Fix lai chuc nang nguoi dung
 */
		else if((x1>=1300 && x1<=1800) && (y1>=0 && y1<=300)){
			if(cA == "" || cB == "" || cC == "" || cD == "" || ans == "" || question == ""){
				giaoDien.ManHinhThieuThongTin();
				giaoDien.ManHinhMenuThemCauHoi(question,cA,cB,cC,cD);
				if(dapAn==1){
					setfillstyle(SOLID_FILL,GREEN);
					bar(1120,300,1330,400);
					ans=cA;
				}
				if(dapAn==2){
					setfillstyle(SOLID_FILL,GREEN);
					bar(1120,430,1330,530);
					ans=cB;
				}
				if(dapAn==3){
					setfillstyle(SOLID_FILL,GREEN);
					bar(1120,560,1330,660);
					ans=cC;
				}
				if(dapAn==4){
					setfillstyle(SOLID_FILL,GREEN);
					bar(1120,690,1330,790);
					ans = cD;
				}
				delay(10);
				while(true){
					getmouseclick(WM_LBUTTONDOWN,x1,y1);
					if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
							delay(10);
	}	
			}
			else{
				int x2,y2;
				giaoDien.ManHinhXacNhanThemCauHoi();
				while(true){
					getmouseclick(WM_LBUTTONDOWN,x2,y2);
					if((x2>=290 && x2<=390) && (y2>=300 && y2<=400) || ((x2>=690 && x2<=890) && (y2>=300 && y2<=400))) break;
					delay(10);
				}
				if((x2>=290 && x2<=390) && (y2>=300 && y2<=400)){
					cleardevice();
					ofstream outFile(FILENAME,ios::app);
					a.setChoiceA(cA);
					a.setQuestion(question);
					a.setChoiceB(cB);
					a.setChoiceC(cC);
					a.setChoiceD(cD);
					a.setAnswer(ans);
					if(isFileEmpty(FILENAME)){
						outFile<<question<<endl;
						outFile<<ans<<endl;
						outFile<<cA<<endl;
						outFile<<cB<<endl;
						outFile<<cC<<endl;
						outFile<<cD;
					}
					else{
						outFile<<endl<<question<<endl;
						outFile<<ans<<endl;
						outFile<<cA<<endl;
						outFile<<cB<<endl;
						outFile<<cC<<endl;
						outFile<<cD;
				}
					outFile.close();
					listQA.push_back(a);
					tempQA.push_back(a);
					cA="";
					question="";
					cB="";
					cC="";
					cD="";
					ans="";
					dapAn=0;
					cleardevice();
					giaoDien.ManHinhMenuThemCauHoi(question,cA,cB,cC,cD);
					delay(10);
					while(true){
						clearmouseclick(WM_LBUTTONDOWN);
						getmouseclick(WM_LBUTTONDOWN,x1,y1);
						if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
							delay(10);
	}
		}
			else{
				
				cleardevice();
				giaoDien.ManHinhMenuThemCauHoi(question,cA,cB,cC,cD);
				if(dapAn==1){
					setfillstyle(SOLID_FILL,GREEN);
					bar(1120,300,1330,400);
					ans=cA;
			}
				if(dapAn==2){
					setfillstyle(SOLID_FILL,GREEN);
					bar(1120,430,1330,530);
					ans=cB;
			}
				if(dapAn==3){
					setfillstyle(SOLID_FILL,GREEN);
					bar(1120,560,1330,660);
					ans=cC;
			}
				if(dapAn==4){
					setfillstyle(SOLID_FILL,GREEN);
					bar(1120,690,1330,790);
					ans = cD;
			}
				delay(10);
				while(true){
					getmouseclick(WM_LBUTTONDOWN,x1,y1);
					if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
							delay(10);
	}
		}
	}
		}
		else if((x1>=1120 && x1<=1330) && (y1>=300 && y1<= 400)){
			
			setfillstyle(SOLID_FILL,LIGHTGRAY);
			bar(1120,300,1330,400);
		
			bar(1120,430,1330,530);
			
			bar(1120,560,1330,660);
		
			bar(1120,690,1330,790);
		
			
			setfillstyle(SOLID_FILL,GREEN);
			bar(1120,300,1330,400);
			dapAn=1;
			ans = cA;
			clearmouseclick(WM_LBUTTONDOWN);
			while(true){
				getmouseclick(WM_LBUTTONDOWN,x1,y1);
				if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
				delay(10);
	}
		}
		else if((x1>=1120 && x1<=1330) && (y1>=430 && y1<= 530)){
			setfillstyle(SOLID_FILL,LIGHTGRAY);
			bar(1120,300,1330,400);
		
			bar(1120,430,1330,530);
			
			bar(1120,560,1330,660);
		
			bar(1120,690,1330,790);
			setfillstyle(SOLID_FILL,GREEN);
			bar(1120,430,1330,530);
			dapAn=2;
			ans = cB;
			clearmouseclick(WM_LBUTTONDOWN);
			while(true){
				getmouseclick(WM_LBUTTONDOWN,x1,y1);
				if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
							delay(10);
	}
		}
		else if((x1>=1120 && x1<=1330) && (y1>=560 && y1<= 660)){
			setfillstyle(SOLID_FILL,LIGHTGRAY);
			bar(1120,300,1330,400);
		
			bar(1120,430,1330,530);
			
			bar(1120,560,1330,660);
		
			bar(1120,690,1330,790);
			setfillstyle(SOLID_FILL,GREEN);
			bar(1120,560,1330,660);
			dapAn=3;
			ans = cC;
			clearmouseclick(WM_LBUTTONDOWN);
			while(true){
				getmouseclick(WM_LBUTTONDOWN,x1,y1);
				if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
							delay(10);
	}
		}
		else if((x1>=1120 && x1<=1330) && (y1>=690 && y1<= 790)){
			setfillstyle(SOLID_FILL,LIGHTGRAY);
			bar(1120,300,1330,400);
		
			bar(1120,430,1330,530);
			
			bar(1120,560,1330,660);
			bar(1120,690,1330,790);
			setfillstyle(SOLID_FILL,GREEN);
			bar(1120,690,1330,790);
			dapAn=4;
			ans=cD;
			clearmouseclick(WM_LBUTTONDOWN);
			while(true){
				getmouseclick(WM_LBUTTONDOWN,x1,y1);
				if(bamChuot.BamChuotMenuThemCauHoi(x1,y1)) break;
				delay(10);
	}
		}
		else if((x1>=0 && x1<=200) && (y1>=0 && y1<=120)){
				hienthi=1;
				cleardevice();
				break;
			}
		cleardevice();
		giaoDien.ManHinhMenuThemCauHoi(question,cA,cB,cC,cD);
		if(dapAn==1){
			setfillstyle(SOLID_FILL,GREEN);
			bar(1120,300,1330,400);
			ans=cA;
		}
		if(dapAn==2){
			setfillstyle(SOLID_FILL,GREEN);
			bar(1120,430,1330,530);
			ans=cB;
		}
		if(dapAn==3){
			setfillstyle(SOLID_FILL,GREEN);
			bar(1120,560,1330,660);
			ans=cC;
		}
		if(dapAn==4){
			setfillstyle(SOLID_FILL,GREEN);
			bar(1120,690,1330,790);
			ans = cD;
		}
		if((x1>=100 && x1<=900) && (y1>=170 && y1<=270)){
			setfillstyle(SOLID_FILL,GREEN);
			bar(100,170,900,270);
		}
		if((x1>=150 && x1<=850) && (y1>=300 && y1<=400)){
			setfillstyle(SOLID_FILL,GREEN);
			bar(150,300,850,400);
		}
		if((x1>=150 && x1<=850) && (y1>=430 && y1<=530)){
			setfillstyle(SOLID_FILL,GREEN);
			bar(150,430,850,530);
		}
		if((x1>=150 && x1<=850) && (y1>=560 && y1<=660)){
			setfillstyle(SOLID_FILL,GREEN);
			bar(150,560,850,660);
		}
		if((x1>=150 && x1<=850) && (y1>=690 && y1<=790)){
			setfillstyle(SOLID_FILL,GREEN);
			bar(150,690,850,790);
		}
			outtextxy(110,180,const_cast<char*>(question.c_str()));
			outtextxy(160,310,const_cast<char*>(cA.c_str()));
			outtextxy(160,440,const_cast<char*>(cB.c_str()));
			outtextxy(160,570,const_cast<char*>(cC.c_str()));
			outtextxy(160,700,const_cast<char*>(cD.c_str()));
		while(kbhit()){
				getch();
			}
		clearmouseclick(WM_LBUTTONDOWN);
		delay(10);
	}
	}
void ChucNangHoanThanhLamBai(vector<QA> & listQA,int &diem,int &hienthi){
	int x1,y1;
	GiaoDien giaoDien;
	BamChuot bamChuot;
	giaoDien.ManHinhHoanThanhLamBai(listQA,diem);
	while(true){
		getmouseclick(WM_LBUTTONDOWN,x1,y1);
		if(bamChuot.BamChuotManHinhHoanThanhLamBai(x1,y1,listQA,diem)) break;
		delay(10);
	}
	if((x1>=100 && x1<=500) && (y1>=500 && y1<=700)){
		hienthi=1;
		cleardevice();
		diem = 0;
	}
	/* TODO (#1#): Sua lai loi
 */
}

int main(){
	GiaoDien giaoDien;
	string line;
	ifstream inFile(FILENAME);
	int x,y,count=0;
	int hienthi=1; // Menu bat dau
	char temp[20];// hien thi diem
	srand(time(0));//sinh random
	int diem = 0;
	vector<QA> listQA;
	vector<QA> wrongQA;
	while(getline(inFile,line)){
		QA a;
		a.setQuestion(line);
		getline(inFile,line);
		a.setAnswer(line);
		getline(inFile,line);
		a.setChoiceA(line);
		getline(inFile,line);
		a.setChoiceB(line);
		getline(inFile,line);
		a.setChoiceC(line);
		getline(inFile,line);
		a.setChoiceD(line);
		listQA.push_back(a);
	}
	vector<QA> tempQA(listQA);
	initwindow(1600,900);
	while(true){
		setbkcolor(BLACK);
		setfillstyle(SOLID_FILL,BLACK);
		setcolor(WHITE);
		if(hienthi==1){
	//		readimagefile("rose.bmp",0,0,getmaxx(),getmaxy());
			ChucNangMenu(listQA,hienthi);
			delay(10);
		//	continue;
		}
		else if(hienthi==2){ // Menu them cau hoi => hienthi=2
			cleardevice();
			ChucNangThemCauHoi(listQA,tempQA,hienthi);
		//	clearmouseclick(WM_LBUTTONDOWN);
			continue;
		}
		else if(hienthi==3){// Menu lam bai hien thi =3
				int i =0;
				while(true){
					setbkcolor(BLACK);
					setfillstyle(SOLID_FILL,BLACK);
					cleardevice();
					sprintf(temp, "%d", diem);
					settextstyle(6,0,10);
					giaoDien.ManHinhLamBai(tempQA[i]);
					clearmouseclick(WM_LBUTTONDOWN);
					outtextxy(1500,50,temp);
					while(!ismouseclick(WM_LBUTTONDOWN)){
					delay(10);
					}
					clickmouse(tempQA[i],diem,wrongQA);
					i++;
					if(tempQA.size() == i){
						delay(2000);
						ChucNangHoanThanhLamBai(listQA,diem,hienthi);
						break;
					}
					else{
						delay(2000);
					}
			}	
	}
		else if(hienthi==5){ // Hienthi=5 menu chua co cau hoi
			ChucNangChuaCoCauHoi(hienthi);
		}
		else if(hienthi==6) {// Hienthi =6 sua cau hoi
			ChucNangSuaCauHoi(hienthi,tempQA,listQA);
		}
}
	getch();
	closegraph();
	return 0;
}
