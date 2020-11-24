#include<iostream>
#include<winbgim.h> 
#include<cstring>
#include<string>
#include<iomanip>
#include<conio.h>
#include<fstream>
#define MAX 100
using namespace std;
void xoa_man_hinh(){
	system("cls");
	cleardevice();//xoa man hinh do hoa
}
bool HOME(){
	rectangle(100,60,1400,750); // Ve hinh chu nhat rong qua 2 diem (100,60) va (1400,750)
	settextstyle(4,0,6); // Dat font chu :4 va size chu :4
	outtextxy(350,0,"QUAN LY SINH VIEN");//Xuat ra man hinh do hoa tai vi tri (350,0) 1 chuoi "..."
	rectangle(100,60,200,100); 
	settextstyle(4,0,1);
	outtextxy(105,70,"MENU");
	//Ve dau X, chuc nang: thoat
	setcolor(4);//Mau chu, 4: mau do
	for(int i=0;i<25;i++)
		rectangle(1375+i,61+i,1399,85);
	setcolor(0);//0: mau den
	line(1375,60,1399,84);//ve doan thang qua 2 diem (1375,60) va (1399,84)
	line(1375,84,1399,60);
	return true;//true: dang hien thi; false: khong hien thi
}
bool menu_nho(){
	bar(101,100,300,340);//Ve hinh chu nhat dac qua 2 diem (101,100) va (300,340)
    settextstyle(3,0,1);
    for(int j=0;j<6*40;j+=40)
    	line(100,140+j,300,140+j);
	outtextxy(105,107,"Nhap thong tin...");
    outtextxy(105,147,"Xuat thong tin...");
    outtextxy(105,187,"Sap xep...");
    outtextxy(105,227,"Tim kiem...");
    outtextxy(105,267,"Canh cao...");
    outtextxy(105,307,"Hoc bong...");
    return true;//true: dang hien thi; false: khong hien thi
}
void menu(){
	rectangle(100,60,1400,750);
	settextstyle(4,0,6);
	outtextxy(350,0,"QUAN LY SINH VIEN");
	outtextxy(200,100,"MENU");   
	settextstyle(4,0,2);  
	outtextxy(200,250,"Nhap thong tin sinh vien"); 
	outtextxy(200,300,"Xem thong tin tat ca sinh vien");
	outtextxy(200,350,"Sap xep sinh vien theo ten, MSSV, diem trung binh");
	outtextxy(200,400,"Tim kiem sinh vien theo ten, MSSV, nganh");
	outtextxy(200,450,"Danh sach sinh vien bi canh cao hoc tap");
	outtextxy(200,500,"Danh sach sinh vien nhan hoc bong");
	outtextxy(200,550,"Luu thong tin sinh vien vua nhap");
	outtextxy(200,600,"Thoat chuong trinh");
}
void backmenu() {//In ra nut MENU va nhan vao nut MENU de tro ve menu
	int x,y;
	rectangle(120,600,400,480);
	settextstyle(4,0,6);
	outtextxy(140,510,"MENU");
	while(1){
		delay(0.0001);
		//Bat su kien click chuot trai
		if (ismouseclick(WM_LBUTTONDOWN)){
	        getmouseclick(WM_LBUTTONDOWN, x, y);//Lay vi tri click
	        //Click tai khoang vi tri nay se tro lai menus
	    	if(x>=120&&y>=480&&x<=400&&y<=600){
	    		xoa_man_hinh();
	    		menu();
	    		break;
			}   	     
		}
	}
}
void menusort(){
	rectangle(100,60,1400,750);
	settextstyle(4,0,6);
	outtextxy(350,0,"QUAN LY SINH VIEN");
	settextstyle(4,0,10);
	outtextxy(320,70,"SAP XEP");   
	settextstyle(3,0,4);
	outtextxy(500,250,"Sap xep theo ten - A->Z");
	outtextxy(500,300,"Sap xep theo MSSV - A->Z");
	outtextxy(500,350,"Sap xep theo diem trung binh - A->Z");
	outtextxy(500,400,"Sap xep theo nganh hoc - A->Z");
	outtextxy(500,450,"Sap xep theo ten - Z->A");
	outtextxy(500,500,"Sap xep theo MSSV - Z->A");
	outtextxy(500,550,"Sap xep theo diem trung binh - Z->A");
	outtextxy(500,600,"Sap xep theo nganh hoc - Z->A");
}
void menusearch(){
	rectangle(100,60,1400,750);
	settextstyle(4,0,6);
	outtextxy(350,0,"QUAN LY SINH VIEN");
	settextstyle(4,0,10);
	outtextxy(300,70,"TIM KIEM");   
	settextstyle(3,0,4);
	outtextxy(550,300,"Tim kiem sinh vien theo MSSV");
	outtextxy(550,350,"Tim kiem sinh vien theo ten");
	outtextxy(550,400,"Tim kiem sinh vien theo nganh");
}
class People { 
protected:
	char hoten[30], noisinh[60], gioitinh[10];
	int dd, mm, yyyy;
};
class Diem{
protected:
	string ten_mon_hoc[8];//toi da 8 mon hoc, vi la mang nen dung` string
	float mon_hoc[8];
	int so_tin_chi[8];
	int size_mh;//so luong mon hoc
};
class Sinhvien :public People,public Diem {
private:
	int MSSV;
	char nganh[30];
	float dtb;
public:
	Sinhvien();//ham tao khong tham so
	Sinhvien(int, char [30], int, int, int, char [10] , char [60],
	 char [30], int, string [8], float [8], int [8], float );//ham tao co tham so
	Sinhvien(const Sinhvien&);//ham tao sao chep
	~Sinhvien();//ham huy
	bool DK_hoc_bong();//Dieu kien nhan hoc bong
	bool DK_canh_cao();//Dieu kien bi canh cao hoc tap
	int getMSSV();//tra ve MSSV
	int getNgay();//tra ve ngay sinh
	int getThang();//tra ve thang sinh
	int getNam();//tra ve nam sinh
	char* getTen();//tra ve ten
	char* getGT();//tra ve gioi tinh
	char* getNoiSinh();//tra ve noi sinh
	char* getNganh();//tra ve nganh hoc
	float getdtb();//tra ve diem trung binh
	friend ostream& operator<<(ostream&, Sinhvien&);//toan tu xuat
	friend istream& operator>>(istream&, Sinhvien&);//toan tu nhap
	void xemdiem();
	friend class stack;//khai bao lop ban de lop stack co the su dung du lieu lop Sinhvien
};
class stack {
private:
	Sinhvien data[MAX];
	int size;//kich thuoc stack
public:
	stack();//ham tao khong tham so
	~stack();//ham huy
	void push(Sinhvien);//them sinhvien vao cuoi
	void pop();//xoa sinhvien cuoi cung
	int length();//tra ve so luong sinhvien
	bool isempty();//kiem tra rong
	Sinhvien top();//tra ve sinh vien cuoi cung
	void display();//in ra man hinh
	void sort_Ten_AZ();//sap xep theo ten tang dan
	void sort_Ten_ZA();//sap xep theo ten giam dan
	void sort_MSSV_AZ();//sap xep theo ID tang dan
	void sort_MSSV_ZA();//sap xep theo ID giam dan
	void sort_Nganh_AZ();//sap xep theo nganh tang dan
	void sort_Nganh_ZA();//sap xep theo nganh tang dan
	void sort_dtb_AZ();//sap xep theo dtb tang dan
	void sort_dtb_ZA();//sap xep theo dtb giam dan
	void search_Ten();//tim kiem theo ten
	void search_Nganh();//tim kiem theo nganh
	void search_MSSV();//tim kiem theo ID
	void sort();//thuc hien viec sap xep 
	void search();//thuc hien viec tim kiem
	void hoc_bong();//danh sach sinhvien co hoc bong
	void canh_cao();//danh sach sinhvien bi canh cao hoc tap
	void doc_file(ifstream&);//doc file
	void ghi_file(ofstream&);//ghi file
};
float diem_he_4(float diem[], int tin_chi[], int n){// tinh diem trung binh he 4
	float b[n],Sum=0;
	int tch=0;
	for(int j=0;j<n;j++){
		if(diem[j]<=1.9) b[j]=0;
		else if(diem[j]>=2.0 && diem[j]<=3.9) b[j]=0.5;
		else if(diem[j]>=4.0 && diem[j]<=4.4) b[j]=1;
		else if(diem[j]>=4.5 && diem[j]<=5.4) b[j]=1.5;
		else if(diem[j]>=5.5 && diem[j]<=5.9) b[j]=2;
		else if(diem[j]>=6.0 && diem[j]<=6.9) b[j]=2.5;
		else if(diem[j]>=7.0 && diem[j]<=7.9) b[j]=3.0;
		else if(diem[j]>=8.0 && diem[j]<=8.4) b[j]=3.5;
		else if(diem[j]>=8.5 && diem[j]<=9.4) b[j]=3.8;
		else b[j]=4;
		tch+=tin_chi[j];
		Sum=Sum+b[j]*((float) tin_chi[j]);
	}
	float dtb=(float) Sum/tch;
	return dtb;
}
bool Ngay_hop_le(int dd, int mm, int yyyy) {//kiem tra ngay sinh co hop le khong
	if (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12) {
		if (dd > 0 && dd < 32) return true;
		else return false;
	}
	else if (mm == 4 || mm == 6 || mm == 9 || mm == 11) {
		if (dd > 0 && dd < 31) return true;
		else return false;
	}
	if (yyyy % 4 == 0 && yyyy % 400 == 0) {
		if (dd > 0 && dd < 30 && mm == 2) return true;
		else return false;
	}
	else {
		if (dd > 0 && dd < 29 && mm == 2) return true;
		else return false;
	}
}

Sinhvien::Sinhvien(const Sinhvien& x) {
	MSSV = x.MSSV;
	dd = x.dd;
	mm = x.mm;
	yyyy = x.yyyy;
	strcpy(hoten, x.hoten); //xai visual studio 2019 thi dung strcpy_s(str1,size,str2) thay vi strcpy(str1,str2);
	strcpy(gioitinh, x.gioitinh);
	strcpy(noisinh, x.noisinh);
	strcpy(nganh, x.nganh);
	size_mh=x.size_mh;
	for(int i=0;i<size_mh;i++){
		ten_mon_hoc[i]=x.ten_mon_hoc[i];
		mon_hoc[i]=x.mon_hoc[i];
		so_tin_chi[i]=x.so_tin_chi[i];
	}
	dtb=x.dtb;
}
Sinhvien::Sinhvien(int Id, char ten[30], int ngay, int thang, int nam, char gioi[10], char noi[60], char nganh[30], int n ,string tenmh[8], float diem[8], int tc[8], float dtb) {
	MSSV = Id;
	strcpy(hoten, ten);
	dd = ngay;
	mm = thang;
	yyyy = nam;
	strcpy(gioitinh, gioi);
	strcpy(noisinh, noi);
	strcpy(this->nganh,nganh);
	for(int i=0;i<n;i++){
		ten_mon_hoc[i]=tenmh[i];
		mon_hoc[i]=diem[i];
		so_tin_chi[i]=tc[i];
	}
	this->dtb=dtb;
}
Sinhvien::Sinhvien() {
	dd = yyyy = mm = 0;
	strcpy(hoten, "");
	strcpy(gioitinh, "");
	strcpy(noisinh, "");
	MSSV = 0;
	strcpy(nganh,"");
	size_mh=0;
	dtb=0.0;
}
Sinhvien::~Sinhvien() {}
int Sinhvien::getNgay(){
	return dd;
}
int Sinhvien::getThang(){
	return mm;
}
int Sinhvien::getNam(){
	return yyyy;
}
char* Sinhvien::getTen(){
	return hoten;
}
char* Sinhvien::getGT(){
	return gioitinh;
}
char* Sinhvien::getNoiSinh(){
	return noisinh;
}
char* Sinhvien::getNganh(){
	return nganh;
}
int Sinhvien::getMSSV(){
	return MSSV;
}
float Sinhvien::getdtb(){
	return dtb;
}
istream& operator>>(istream& is, Sinhvien& x) {
	cout << "Ma so sinh vien: ";
	is >> x.MSSV;
	is.ignore(1);//1 vi xoa ki tu ENTER
	cout << "Ten: ";
	is.getline(x.hoten,30);
	cout << "Noi sinh: ";
	is.getline(x.noisinh,60);
	cout << "Gioi tinh: ";
	is.getline(x.gioitinh,10);
	cout << "Nganh: ";
	is.getline(x.nganh,30);
	do {
		cout << "Nhap ngay thang nam sinh: "<<endl;
		cout<<"Ngay: ";
		is >> x.dd;
		cout<<"Thang: ";
		is >> x.mm;
		cout<<"Nam: ";
		is >> x.yyyy;
	} while (!Ngay_hop_le(x.dd, x.mm, x.yyyy));
	cout<<"So luong mon hoc can nhap diem: ";
	is>>x.size_mh;
	for(int j=0;j<x.size_mh;j++){
		is.ignore(1);
		cout<<"Nhap ten mon hoc: ";
		getline(is,x.ten_mon_hoc[j]);
		cout<<"Nhap diem: ";
		is>>x.mon_hoc[j];
		cout<<"Tin chi: ";
		is>>x.so_tin_chi[j];
	}
	x.dtb=diem_he_4(x.mon_hoc,x.so_tin_chi,x.size_mh);
	return is;
}
ostream& operator<<(ostream& os, Sinhvien& x) {
	os<<x.MSSV<<endl;
	os<<x.dd<<" "<<setw(2)<<x.mm<<" "<<setw(4)<<x.yyyy<<endl;
	os<<x.hoten<<endl;	
	os<<x.gioitinh<<endl;
	os<<x.noisinh<<endl;
	os<<x.nganh<<endl;
	os<<x.size_mh<<endl;
	for(int i=0;i<x.size_mh;i++){
		os<<x.ten_mon_hoc[i]<<endl;
		os<<x.mon_hoc[i]<<endl;
		os<<x.so_tin_chi[i]<<endl;
	}
	os<<setprecision(4);
	os<<x.dtb<<endl;
	return os;
}
void Sinhvien::xemdiem(){
	cleardevice();
	//in tieu de
	rectangle(500,175,1300,710);
	line(500,256,1300,256);
	char tc[4];
	settextstyle(3,0,1);
	char buffer[5];
	outtextxy(650,202,"Mon hoc");
	line(900,175,900,710);
	outtextxy(975,202,"Tin chi");
	line(1100,175,1100,710);
	outtextxy(1175,202,"Diem");
	//khoang cach tung hang
	int j=0;
	while(325+j<=710){
		line(500,325+j,1300,325+j);
		j+=55;
	}
	j=0;
	int i=0;
	while(i<size_mh){//in tung thong tin mon hoc 
		//chuyen string thanh char* vi outtextxy yeu cau char*
		char* c = new char[ten_mon_hoc[i].size() + 1];
		strcpy(c, ten_mon_hoc[i].c_str());
		outtextxy(510,281+j,c);
		
		itoa(so_tin_chi[i],tc,10);
		outtextxy(990,281+j,tc);
		
		sprintf(buffer,"%.2f",mon_hoc[i]);
		outtextxy(1190,281+j,buffer);
		i++;
		j+=55;
	}
	backmenu();
}
stack::stack() {
	size = 0;
}
stack::~stack() {}
int stack::length() {
	return size;
}
void stack::push(Sinhvien a) {
	if (size < MAX) {
		data[size] = a;
		size++;
	}
	else {
		cout << "Chuong trinh su dung toi da 100 sinh vien";
	}
}
void stack::pop() {
	if (size == 0) {
		cout << "Stack rong";
	}
	else {
		size--;
	}
}
bool stack::isempty() {
	if (size == 0) return true;
	return false;
}
Sinhvien stack::top() {
	return data[size - 1];
}
void swap(Sinhvien& a, Sinhvien& b) {//doi cho 2 Sinhvien (dung` trong sap xep)
	Sinhvien temp = a;
	a = b;
	b = temp;
}
void stack::display(){
	int x,y;
	int k=(length()-1)/14;//so luong trang, moi trang in 14 sinh vien
	int page=0;//khoang cach giua cac trang
	char pages[4];
	char id[4];
	char dd[3];
	char mm[3];
	char yyyy[4];
	cleardevice();//xoa man hinh do hoa
	//in so trang hien thi
		
	char buffer[5];
	int j=0;//khoang cach tung` hang`
	int row=14;//so luong dong` 
	settextstyle(3,0,1);//chinh front chu~ tren man hinh do hoa
	int chi_so=0;//chi so trang, =0 -> trang 1, =14  -> trang 2, =28 -> trang 3,...
	for(int row=0;row<=k;row++){
		//ve nut MENU
		rectangle(120,600,400,480);
		settextstyle(4,0,6);
		outtextxy(140,510,"MENU");
		settextstyle(3,0,1);
		
		//in so trang
		for(int i=0;i<=k;i++){
			rectangle(593+page,478,620+page,506);
			if(i<=3||i==k){//in 3 trang dau va trang cuoi
				itoa(i+1,pages,10);
				outtextxy(600+page,480,pages);
			}
			else
				outtextxy(600+page-1,480,"...");//in ... neu co hon 3 trang	
			page+=27;
		}
		page=0;
		rectangle(41,74,1350,99);
		line(99,75,99,100);
		line(419,75,419,100);
		line(499,75,499,100);
		line(799,75,799,100);
		line(1099,75,1099,100);
		line(1199,75,1199,100);
		setcolor(6);//In mau tieu de
		outtextxy(42,75,"MSSV");
		outtextxy(100,75,"Ho va ten");
		outtextxy(420,75,"Gioi tinh");
		outtextxy(500,75,"Noi Sinh");
		outtextxy(800,75,"Nganh");
		outtextxy(1100,75,"Ngay sinh");
		outtextxy(1210,75,"Diem trung binh");
		setcolor(0);
		for(int i=row*14;i<14+row*14;i++){
			if(data[i].getNgay()==0)//Khong in sinh vien cua ham` tao.
				break;
			circle(28,111+j,8);
			itoa(data[i].getMSSV(),id,10);//chuyen? int thanh` chuoi~ vi` khong the? xuat so' ra man hinh do hoa
			line(41,99,41,124+j);
			line(99,99,99,124+j);
			line(419,99,419,124+j);
			line(499,99,499,124+j);
			line(799,99,799,124+j);
			sprintf(buffer,"%.2f",data[i].getdtb());//chuyen? float thanh` chuoi~
			line(1099,99,1099,124+j);
			outtextxy(42,100+j,id);
			outtextxy(100,100+j,data[i].getTen());
			outtextxy(420,100+j,data[i].getGT());
			outtextxy(500,100+j,data[i].getNoiSinh());
			outtextxy(800,100+j,data[i].getNganh());
			itoa(data[i].getNgay(),dd,10);
			outtextxy(1100,100+j,dd);
			outtextxy(1125,100+j,"/");
			itoa(data[i].getThang(),mm,10);
			outtextxy(1130,100+j,mm);
			outtextxy(1155,100+j,"/");
			itoa(data[i].getNam(),yyyy,10);
			outtextxy(1160,100+j,yyyy);
			outtextxy(1250,100+j,buffer);
			line(1199,99,1199,124+j);
			line(1350,99,1350,124+j);
			j+=25;
			line(41,99+j,1350,99+j);
		}
		while(1){
			delay(0.0001);
			if(ismouseclick(WM_LBUTTONDOWN)){
	        	getmouseclick(WM_LBUTTONDOWN, x, y);
	        	
				//neu o trang 1-> chi_so =0, trang 2 -> chi_so=14, trang 3 ->chi_so=28,...
				if(x>=593&&x<=620&&y>=478&&y<=506){//neu chon trang 1
					chi_so=0;
					row=-1;//vi row++ nen gan = -1
					cleardevice();
					j=0;
					break;
				}
				else if(x>=120&&x<=400&&y>=480&&y<=600){//nhan nut MENU
					cleardevice();
					row=k;
					menu();
					break;
				}
				else if(x>=20&&x<=1350&&y>=100&&y<=450){//xem diem sinh vien
					row=k;
					int cs=(y-100)/25;//chi so cua sinh vien
					for(int n=0;n<5;n++){//in cac hinh` tron`
						circle(28,111+25*cs,n);
					}
					delay(300);
					data[cs+chi_so].xemdiem();
					// + chi_so de phan biet tung trang, tranh luu sai du lieu
					break;
				}
				else if(x>620&&x<=(620+k*27)&&y>=478&&y<=506){
					row=(x-620)/27;//neu chon trang khac trang 1, vi m++ se = so trang dang chon
					j=0;
					chi_so=14*(row+1);//khi chon trang khac trang 1, chi_so se thay doi tuong ung
					cleardevice();
					break;
				}
				else{//click vi tri khac thi khong lam gi ca
					continue;
				}
	        }
		}
	}
}

void stack::sort_Ten_AZ() {//Sap xep noi bot
	bool kq = false;
	for (int i = 0;i < size;i++) {
		kq = true;
		for (int j = 0;j < size-1;j++) {
			if (strcmp(data[j].hoten, data[j+1].hoten) > 0) {
					kq = false;
					swap(data[j], data[j + 1]);
				}
			}
		if (kq == true) break;
	}
}
void stack::sort_Ten_ZA() {//Sap xep noi bot
	bool kq = false;
	for (int i = 0;i < size;i++) {
		kq = true;
		for (int j = 0;j < size-1;j++) {
			if (strcmp(data[j].hoten, data[j+1].hoten) < 0) {
					kq = false;
					swap(data[j], data[j + 1]);
				}
			}
		if (kq == true) break;
	}
}
void stack::sort_MSSV_AZ(){//sap xep chon 
	int min;
	for (int i = 0;i < size - 1;i++) {
		min = i;
		for (int j = i + 1;j < size;j++) {
			if (data[min].MSSV > data[j].MSSV) {
				min = j;
			}
		}
		swap(data[min], data[i]);
	}
}
void stack::sort_MSSV_ZA(){//sap xep chon
	int max;
	for (int i = 0;i < size - 1;i++) {
		max = i;
		for (int j = i + 1;j < size;j++) {
			if (data[max].MSSV < data[j].MSSV) {
				max = j;
			}
		}
		swap(data[max], data[i]);
	}
}
void stack::sort_dtb_AZ(){//sap xep chen
	Sinhvien val;
	int j;
	for (int i = 1;i < size;i++) {
		val = data[i];
		j = i - 1;
		while (j >= 0 && data[j].dtb > val.dtb) {
			data[j + 1] = data[j];
			j--;
		}
		data[j + 1] = val;
	}
}
void stack::sort_dtb_ZA(){//sap xep chen
	Sinhvien val;
	int j;
	for (int i = 1;i < size;i++) {
		val = data[i];
		j = i - 1;
		while (j >= 0 && data[j].dtb < val.dtb) {
			data[j + 1] = data[j];
			j--;
		}
		data[j + 1] = val;
	}
}
void stack::sort_Nganh_AZ(){//sap xep chen
	Sinhvien val;
	int j;
	for (int i = 1;i < size;i++) {
		val = data[i];
		j = i - 1;
		while (j >= 0 && strcmp(data[j].nganh, val.nganh) > 0) {
			data[j + 1] = data[j];
			j--;
		}
		data[j + 1] = val;
	}
}
void stack::sort_Nganh_ZA(){
	bool kq = false;
	for (int i = 0;i < size;i++) {
		kq = true;
		for (int j = 0;j < size-1;j++) {
			if (strcmp(data[j].nganh, data[j+1].nganh) < 0) {
					kq = false;
					swap(data[j], data[j + 1]);
				}
			}
		if (kq == true) break;
	}
}

void stack::sort(){//thuc hien viec sap xep
	menusort();
	rectangle(120,600,400,480);
	settextstyle(4,0,6);
	outtextxy(140,510,"BACK");
	int x,y;
	while(1){
        delay(0.0001);//khoang thoi gian dung` giua cac lenh
        if (ismouseclick(WM_LBUTTONDOWN)){//neu xay ra click chuot
            getmouseclick(WM_LBUTTONDOWN, x, y);//lay gia tri x,y tai vi tri click chuot      
		 	if(x>=120&&y>=480&&x<=400&&y<=600){
            	cleardevice();
            	menu();
            	break;
			}
			else if(y>=250&&y<300&&x>=300){
            	sort_Ten_AZ();
            	display();
            	break;
			}    
			else if(y>=300&&y<350&&x>=300){
				sort_MSSV_AZ();
				display();
				break;
			}
			else if(y>=350&&y<400&&x>=300){
				sort_dtb_AZ();
				display();
				break;
			}
			else if(y>=400&&y<450&&x>=300){
				sort_Nganh_AZ();
				display();
				break;
			}
			else if(y>=450&&y<500&&x>=300){
				sort_Ten_ZA();
				display();
				break;
			}
			else if(y>=500&&y<550&&x>=300){
				sort_MSSV_ZA();
				display();
				break;
			}
			else if(y>=550&&y<600&&x>=300){
				sort_dtb_ZA();
				display();
				break;
			}
			else if(y>=600&&y<650&&x>=300){
				sort_Nganh_ZA();
				display();
				break;
			}
		}
 	}
 	
}
void stack::search_MSSV() {//tim kiem nhi phan
	int x;
	int i=0;
	cleardevice();
	rectangle(100,60,1400,650);
	outtextxy(300,300,"Dang nhap du lieu...");
	cout << "Nhap MSSV sinh vien can tim: ";
	cin>>x;
	stack a;//luu sinh vien can tim`
	xoa_man_hinh();
	for (i;i < size;i++) {
		if (data[i].MSSV==x) {
			a.push(data[i]);
			break;
		}
	}
	if (a.isempty()) {
		outtextxy(50,25,"Khong tim thay sinh vien");
		backmenu();
	}
	else
		a.display();
}
void stack::search_Ten(){//tim kiem tuyen tinh
	char x[30];
	cleardevice();
	rectangle(100,60,1400,650);
	outtextxy(300,300,"Dang nhap du lieu...");
	cout << "Nhap ten sinh vien can tim: ";
	cin.getline(x,30);
	int k=0;
	stack a;//luu sinh vien can` tim`
	xoa_man_hinh();
	for (int i = 0;i < size;i++) {
		if (strcmp(data[i].hoten,x)==0) 
			a.push(data[i]);
	}
	if (a.isempty()) {
		outtextxy(50,25,"Khong tim thay sinh vien");
		backmenu();
	}
	else
		a.display();
}
void stack::search_Nganh(){//tim kiem tuyen tinh
	char x[30];
	stack a;//luu sinh vien can` tim`
	cleardevice();
	rectangle(100,60,1400,650);
	outtextxy(300,300,"Dang nhap du lieu...");
	cout << "Nhap nganh cua sinh vien can tim: ";
	cin.getline(x,30);
	xoa_man_hinh();
	for (int i = 0;i < size;i++) {
		if (strcmp(data[i].nganh,x)==0) 
			a.push(data[i]);
	}
	if (a.isempty()) {
		outtextxy(50,25,"Khong tim thay sinh vien");
		backmenu();
	}
	else 
		a.display();
}
void stack::search(){//thuc hien viec tim kiem	
   	menusearch();
	rectangle(120,600,400,480);
	settextstyle(4,0,6);
	outtextxy(140,510,"BACK");
	int x,y;
	while (1){
        delay(0.0001);
        if (ismouseclick(WM_LBUTTONDOWN)){
            getmouseclick(WM_LBUTTONDOWN, x, y);
            if(x>=120&&y>=480&&x<=400&&y<=600){
            	cleardevice();
            	menu();
            	break;
			}
			else if(y>=300&&y<=350&&x>=350){
            	search_MSSV();
			   	break;
			}    
			else if(y>350&&y<=400&&x>=350){
				search_Ten();
				break;
			}
			else if(y>400&&y<=450&&x>=350){
				search_Nganh();
				break;
			}
		}
 	}
}
bool Sinhvien::DK_hoc_bong(){
	//khong co mon nao<5 hoac diem trung binh chung >=2.5
	int sum=0;//tong tin chi dang ky
	for(int j=0;j<size_mh;j++){
		if(mon_hoc[j]<5)
			return false;
		else
			sum+=so_tin_chi[j];
	}
	if(dtb>=2.5 && sum>=10) //Dang ki tu 10 tin chi tro len
		return true;
	else 
		return false;
}
bool Sinhvien::DK_canh_cao(){	
	if(dtb<1)
		return true;
	return false;
}
void stack::canh_cao(){
	stack temp;//luu sinh vien bi canh cao
	bool kt=false;
	for(int i=0;i<size;i++){
		if(data[i].DK_canh_cao()){
			kt=true;
			temp.push(data[i]);
		}
	}
	if(kt==false){
		cleardevice();
		outtextxy(100,50,"Khong co sinh vien bi canh cao");
		backmenu();
	}
	else
		temp.display();
}
void stack::hoc_bong(){
	bool kt=false;
	stack temp;// luu sinh vien nhan hoc bong
	for(int i=0;i<size;i++){
		if(data[i].DK_hoc_bong()){
			kt=true;
			temp.push(data[i]);
		}
	}
	if(kt==false){
		cleardevice();
		outtextxy(100,50,"Khong co sinh vien du dieu kien nhan hoc bong");
		backmenu();
	}
	else
		temp.display();
}
void stack::ghi_file(ofstream& ofs){
	ofs.open("QLsinhvien.txt", ios::app);//app: ghi tiep vao file da co
	while(size>0){	
		ofs<<data[size-1];//ghi thong tin tung sinh vien vao file
		size--;
	}
}
void stack::doc_file(ifstream& ifs){
	ifs.open("QLsinhvien.txt");
	char nganh[30], hoten[30], noisinh[60], gioitinh[10];
	string tenmh[8];
	int ID, dd, mm, yyyy,sizemh,tinchi[8];
	float dtb,diem[8];
	while(ifs>>ID){//doc du lieu tu file va` dua du lieu vao bien ID
		ifs>>dd>>mm>>yyyy;
		ifs.ignore(1);
		ifs.getline(hoten,30);
		ifs.ignore(0);
		ifs.getline(gioitinh,30);
		ifs.ignore(0);
		ifs.getline(noisinh,30);
		ifs.ignore(0);
		ifs.getline(nganh,30);
		if(ifs>>sizemh){
			for(int j=0;j<sizemh;j++){
				ifs.ignore(1);
				getline(ifs,tenmh[j]);
				ifs>>diem[j];
				ifs>>tinchi[j];
			}
		}
		ifs>>dtb;
		data[size]=Sinhvien(ID,hoten,dd,mm,yyyy,gioitinh,noisinh,nganh,sizemh,tenmh,diem,tinchi,dtb);
		data[size].size_mh=sizemh;//khi ra khoi ham docfile thi dulieu sizemh thay doi nen ta gan sizemh vao size_mh
		size++;
	}
}

int main(){
	initwindow(1600, 800);//Khoi tao kich thuoc man hinh do hoa ban dau		
	setbkcolor(5);//Mau nen
   	cleardevice();//Xoa man hinh do hoa
   	int x,y;
   	bool kt_menu=false,kt_HOME=false;
   	Sinhvien a;
   	stack q,q_save;
	setcolor(0); //Mau chu
	ofstream ofs;
	ifstream ifs;
	q.doc_file(ifs);
	ifs.close();
	kt_HOME=HOME();	
	while (1){
        delay(0.0000001);
        if(kt_HOME==true){//neu dang o trang chu
        	//menu phu
			while(1){
	        	delay(0.0000001);
	        	if (ismouseclick(WM_MOUSEMOVE)){//neu di chuyen chuot tren man hinh
		            getmouseclick(WM_MOUSEMOVE, x, y);
		            if(x>=100&&y>=60&&x<=200&&y<=100){
		            	kt_menu=menu_nho();
					}
					else if(x>=101&&x<=300&&y>=101&&y<=380&&kt_menu==true){
					//kt2==true de menu phu khong bi bien mat khi di chuyen chuot xuong
						kt_menu=menu_nho();
					}
					else{
						cleardevice();
						kt_HOME=HOME();
					}
		        }
		        if (ismouseclick(WM_LBUTTONDOWN)){
		            getmouseclick(WM_LBUTTONDOWN, x, y);
		            kt_HOME=false;
		        	if(x>=100&&y>=60&&x<=200&&y<=100) {//bam MENU -> in MENU
		        		cleardevice();
		        		kt_menu=false;
						menu();
						break;
					}
					else if(y>=61&&y<=85&&x<=1399&&x>=1375){//bam exit -> thoat
						exit(1);
						closegraph();
					}
					else if(y>=107&&y<=147&&x>=101&&x<=300){
		            	goto nhap;
					}
					else if(y>147 && y<=187&&x>=101&&x<=300){
						goto xuat;
					}
					else if(y>187 && y<=227&&x>=101&&x<=300){
						goto sapxep;
					}
					else if(y>227 && y<=267&&x>=101&&x<=300){
						goto timkiem;
					}
					else if(y>267 && y<=307&&x>=101&&x<=300){
						goto canhcao;
					}
					else if(y>307 && y<=347&&x>=101&&x<=300){
						goto hocbong;
					}
		    	}
			}
		}
		//menu chinh
        if (ismouseclick(WM_LBUTTONDOWN)){
            getmouseclick(WM_LBUTTONDOWN, x, y);
			if(x>=350&&x<=1110&&y<60&&y>=0){//bam QUAN LI SINH VIEN -> in HOME
				cleardevice();
				kt_HOME=HOME();
			}
            else if(y>=250&&y<=300){//nhap
            	nhap:
            	cleardevice();
            	rectangle(100,60,1400,650);
				outtextxy(300,300,"Dang nhap du lieu...");
            	while(1){
					cin >> a;
					q_save.push(a);
					q.push(a);
					cout << endl << "Nhap ENTER de tiep tuc nhap";
					cout << endl << "Nhap phim bat ki de quay lai MENU";
					char k = _getch();
					if (k != 13) {
						xoa_man_hinh();
						menu();
						break;
					}
					system("cls");
				}
			}   
			else if(y>300 && y<=350){//xuat
				xuat:
				cleardevice();
				q.sort_MSSV_AZ();//Xuat theo MSSV tang dan
				q.display();
			}
			else if(y>350 && y<=400){//sap xep
				sapxep:
				cleardevice();
				q.sort();
			}
			else if(y>400 && y<=450){//tim kiem
				timkiem:
				cleardevice();
				q.search();
			}
			else if(y>450 && y<=500){//canh cao
				canhcao:
				cleardevice();
				q.canh_cao();
			}
			else if(y>500 && y<=550){//hoc bong
				hocbong:
				cleardevice();
				q.hoc_bong();
			}
			else if(y>550&&y<=600){//ghi file
				cleardevice();
				q_save.ghi_file(ofs);
				ofs.close();
				rectangle(100,60,1400,750);
				settextstyle(4,0,2);
				outtextxy(500,300,"Luu thanh cong");
				backmenu();
			}
			else if(y>600&& y<=650){//thoat
				exit(1);
				closegraph();
			}
		}
 	}			
}
