/*
MA TRAN PHUC
Version 1.0
Sinh vien thuc hien: Nguyen Thanh Tung
SHSV: 20093128
Lop: DT04-K54
*/
#include <iostream>
using namespace std;
#include <math.h>
/*--------------------------XAY DUNG LOP COMPLEX---------------------------*/
class complex
{
      public:
             double re,im;
             complex(double, double);// ham khoi tao 2 tham so
             void display(); //ham hien thi
             complex operator+ (complex ); //dinh nghia phep cong
             complex operator- (complex ); //dinh nghia phep tru
             complex operator* (complex ); //dinh nghia phep nhan
             complex operator/ (complex ); //dinh nghia phep chia 
             complex &operator+=(complex ); //dinh nghia phep tu cong
             complex &operator-=(complex ); //dinh nghia phep tu tru
             complex &operator*=(complex ); //dinh nghia phep tu nhan
             complex &operator/=(complex ); //dinh nghia phep tu chia
             complex &operator= (complex ); //gan so phuc=so phuc
             };
complex::complex(double real=0,double image=0)
{
        re=real;
        im=image;                     
}
void complex::display()
{
        cout<<re<<(im>=0?'+':'-')<<"j*"<<fabs(im)<<"     ";
}
/*------------------dinh nghia cac toan tu lop complex----------------*/
complex complex::operator+ (complex b)
{      
        complex c;
        c.re=re+b.re;
        c.im=im+b.im;
        return c;
}
complex complex::operator- (complex b)
{
        complex c;
        c.re=re-b.re;
        c.im=im-b.im;
        return c;
}
complex complex::operator* (complex b)
{
        complex c;
        c.re=re*b.re-im*b.im;
        c.im=re*b.im+im*b.re;
        return c;
}
complex complex::operator/ (const complex b)
{
        double x=b.re*b.re-b.im*b.im;
        complex c;
        c.re=(re*b.re+im*b.im)/x;
        c.im=(-re*b.im+im*b.re)/x;
        return c;
}
complex  &complex::operator+= (complex b)
{
         this->re=re+b.re;
         this->im=im+b.im;
         return *this;
}
complex  &complex::operator-= (complex b)
{
         this->re=re-b.re;
         this->im=im-b.im;
         return *this;
}
complex  &complex::operator*= (complex b)
{
         this->re=re*b.re-im*b.im;
         this->re=re*b.im+im*b.re;
         return *this;
}
complex  &complex::operator/= (complex b)
{
        double x=b.re*b.re-b.im*b.im;
        this->re=(re*b.re+im*b.im)/x;
        this->re=(-re*b.im+im*b.re)/x;
        return *this;
}
complex &complex::operator= (complex b)
{
        re=b.re; im=b.im;
        return *this;
}
/*----------------------------MATRIX COMPLEX---------------------------*/
class matrix:complex  //ke thua lop complex
{
      int n,m;
      complex **data; //con tro data tro toi con tro khac
public:
      matrix(){}
      matrix(matrix &a);//ham thiet lap sao chep
      ~matrix();
      void nhap();
      void display();
      matrix & operator=(matrix &a); //dinh nghia toan tu =
      friend matrix operator+(matrix &a,matrix &b);
      friend matrix operator-(matrix &a,matrix &b);
      friend matrix operator*(matrix &a,matrix &b);
      void nhap_tudong(matrix &a, matrix &b);
};
matrix::matrix(matrix &a){
                        n=a.n;m=a.m;
                        data=new complex*[n];
                        for(int i=0;i<n;i++)
                        data[i]=new complex[m];
                        for(int i=0;i<n;i++)
                        for(int j=0;j<m;j++)
                        data[i][j]=a.data[i][j];
                        }
matrix::~matrix(){
                  for(int i=0;i<n;i++) 
                  delete data[i];
                  delete data;
                  }
void matrix::nhap(){
                    cout<<"Nhap so hang: ";cin>>n;
                    cout<<"\nNhap so cot: ";cin>>m;
                    data=new complex*[n];
                    for(int i=0;i<n;i++)
                    data[i]=new complex[m];
                    for(int i=0;i<n;i++)
                    for(int j=0;j<m;j++){
                        cout<<"\nNhap phan tu thu ["<<i+1<<"]["<<j+1<<"]: ";
                        cin>>data[i][j].re>>data[i][j].im;
                        }
                    }

void matrix::display(){
                    for(int i=0;i<n;i++){
                                        for(int j=0;j<m;j++)
                                          data[i][j].display();
                                        cout<<"\n";
                                        }
                    cout<<"\n";
                    }

matrix & matrix::operator=(matrix &a){
                                    n=a.n;m=a.m;
                                    //cap phat bo nho dong cho n vector complex
                                    data=new complex*[n];
                                    for(int i=0;i<n;i++)
                                    //cap phat bo nho dong cho n phan tu complex
                                    data[i]=new complex[m];
                                    for(int i=0;i<n;i++)
                                            for(int j=0;j<m;j++)
                                            data[i][j]=a.data[i][j];
                                    return *this;
                                    }
matrix operator+(matrix &a,matrix &b){
                                    if((a.n==b.n)&&(a.m==b.m)){
                                        matrix c;
                                        c.n=a.n;c.m=a.m;
                                        //cap phat bo nho dong cho n vector complex
                                        c.data=new complex*[c.n]; 
                                        for(int i=0;i<c.n;i++)
                                        //cap phat bo nho dong cho n phan tu complex
                                        c.data[i]=new complex[c.m];
                                        for(int i=0;i<c.n;i++)
                                        for(int j=0;j<c.m;j++)
                                        //su dung chuc nang lop complex
                                        c.data[i][j]=a.data[i][j]+b.data[i][j]; 
                                        return c;}
                                        
                                    else {
                                    cout<<"\nHai ma tran khong cung cap.\n";
                                    system("PAUSE");
                                    exit(0);
                                    }
}
matrix operator-(matrix &a,matrix &b){
                                if((a.n==b.n)&&(a.m==b.m)){
                                matrix c;
                                c.n=a.n;c.m=a.m;
                                //cap phat bo nho dong cho n vector complex
                                c.data=new complex*[c.n];
                                for(int i=0;i<c.n;i++)
                                //cap phat bo nho dong cho n phan tu complex
                                c.data[i]=new complex[c.m];
                                for(int i=0;i<c.n;i++)
                                for(int j=0;j<c.m;j++)
                                c.data[i][j]=a.data[i][j]-b.data[i][j];
                                return c;
                                }
                                else {
                                cout<<"\nHai ma tran khong cung cap.\n";
                                system("PAUSE");
                                exit(0);
                                }
}
matrix operator*(matrix &a,matrix &b){
                                if(a.m==b.n){
                                matrix c;
                                c.n=a.n;c.m=b.m;
                                //cap phat bo nho dong cho n vector complex
                                c.data=new complex*[c.n];
                                for(int i=0;i<c.n;i++)
                                //cap phat bo nho dong cho n phan tu complex
                                c.data[i]=new complex[c.m];
                                //thuc hien phep nhan 2 ma tran phuc
                                for(int i=0;i<c.n;i++)
                                for(int j=0;j<c.m;j++){
                                    c.data[i][j]=complex();
                                    for(int k=0;k<a.m;k++)
                                    c.data[i][j]+=a.data[i][k]*b.data[k][j];}
                                return c;}
                                else{
                                cout<<"\nKhong the thuc hien phep nhan nay !\n";
                                system("PAUSE"); 
                                exit(0);
                                }
                                }
void matrix::nhap_tudong(matrix &a,matrix &b)
 {
     a.n=5;a.m=5;
     b.n=5;b.m=5;
     a.data=new complex*[5];
     b.data=new complex*[5];
     for(int i=0;i<5;i++){
           a.data[i]=new complex[5];
           b.data[i]=new complex[5];
           }
   for (int i=0;i<=4;i++)
   for (int j=0;j<=4;j++)
   {a.data[i][j]=complex(i+1,j+1);
   b.data[i][j]=complex(i+2,j+3); }  
 }
/*-------------------------------------HAM MAIN----------------------------*/
main()//dung Kev-C++ nen ham main() hoac tra ve int, hoac dung nhu trong bai tap nay
{
        matrix a,b,c;
        int n;
        cout<<"Nhap du lieu theo cach sau: phan_thuc phan_ao\n";
        cout<<"Lua chon cach nhap:\n0.Thu Cong\n1.Tu Dong.\n"; cin>>n;
        if (!n){
                 a.nhap();b.nhap();
                 }
        else a.nhap_tudong(a,b);
        cout<<"\nMa tran a la:\n";a.display();
        cout<<"\nMa tran b la:\n";b.display();
        cout<<"\nTong hai ma tran la:\n";(a+b).display();
        cout<<"\nHieu hai ma tran la:\n";(a-b).display();
        cout<<"\nTich hai ma tran la:\n";(a*b).display();
      system("PAUSE");
}
