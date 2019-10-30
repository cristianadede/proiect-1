#include <iostream>
#include <math.h>
using namespace std;

class matrice
{
    int nr_l;
    int nr_c;
    float **a;
    public:
    matrice();//const pt initializare
    matrice(const matrice&);//const de copiere
    matrice(int,int,int);//const de initializare cu un nr dat
    ~matrice();
    void citire();//metoda de citire
    void afisare();//metoda de afisare
    matrice& operator=(const matrice &);

    matrice& operator[](const matrice &);
    friend matrice operator+(const matrice&,const matrice&);//suma
    friend matrice operator+(const matrice&);//matricea insasi

    friend matrice operator-(const matrice&,const matrice&);//diferenta
    friend matrice operator-(const matrice&);//opusa

    friend matrice operator*(const matrice&, const matrice&);//inmultire
    friend matrice operator*(const matrice&,int);//inmultire cu scalar

    friend matrice operator+=(const matrice&, const matrice&);//adunare

    friend matrice operator-=(const matrice&,const matrice&);//scadere

    friend matrice operator*=(const matrice&, const matrice&);//inmultire
    friend matrice operator*=(const matrice&,int);//inmultire cu scalar

    friend int operator==(const matrice&, const matrice&);//testarea egalitatii
    friend int operator==(float v[100],const matrice&);
    friend int operator==(const matrice&,float v[100]);

    friend int operator!=(const matrice&, const matrice&);//testarea neegalitatii
    friend int operator!=(float v[100], const matrice&);
    friend int operator!=(const matrice&,float v[100]);

    friend int operator<(const matrice&,const matrice&);
    friend int operator<(float v[100], const matrice&);
    friend int operator<(const matrice&,float v[100]);

    friend int operator<=(const matrice&,const matrice&);
    friend int operator<=(float v[100],const matrice&);
    friend int operator<=(const matrice&,float v[100]);

    friend int operator>(const matrice&,const matrice&);
    friend int operator>(float v[100],const matrice&);
    friend int operator>(const matrice&,float v[100]);

    friend int operator>=(const matrice&,const matrice&);
    friend int operator>=(float v[100],const matrice&);
    friend int operator>=(const matrice&,float v[100]);

    friend int operator!(const matrice&);//daca toate elem =0 return 0 altfel return 1
    friend int determinant(matrice,int);//calculare determinant
    friend matrice operator~(const matrice&);//inversa

    friend int nrlinii(const matrice&);//returneaza nr de linii
    friend int nrcoloane(const matrice&);//returneaza nr de coloane
    friend int nrelemente(const matrice&);//returneaza nr de elemente

    friend void ecuatie(matrice, matrice);//rezolvarea ecuatie A*X+B=0

};

matrice::matrice(){a=new float*[1];a[1]=new float[0];nr_l=0;nr_c=0;} //constructor pt initializare

matrice::matrice(const matrice&ob) //constructor de copiere
{
    nr_l=ob.nr_l;
    nr_c=ob.nr_c;
    a=new float*[nr_l];
    for(int i=0;i<nr_l;i++)
         a[i]=new float[nr_c];
    for(int i=0;i<nr_l;i++)
        for(int j=0;j<nr_c;j++)
        a[i][j]=ob.a[i][j];
}

matrice::matrice(int x,int y,int nr)//initializare cu un nr dat pe toate componentele
{
    nr_l=x; nr_c=y;
    a=new float*[nr_l];
    for(int i=0;i<nr_l;i++)
         a[i]=new float[nr_c];

    for(int i=0;i<nr_l;i++)
        for(int j=0;j<nr_c;j++)
        a[i][j]=nr;
}
matrice::~matrice() //destructor
{
    for(int i=0;i<nr_l;i++)
        delete [] a[i];
    delete [] a;
}

void matrice::citire() //functie(metoda) de citire
{
    cin>>nr_l;
    cin>>nr_c;
    a=new float*[nr_l];
    for(int i=0;i<nr_l;i++)
         a[i]=new float[nr_c];
     for(int i=0;i<nr_l;i++)
        for(int j=0;j<nr_c;j++)
        cin>>a[i][j];
}

void matrice::afisare()//functie de afiare
{
    for(int i=0;i<nr_l;i++)
      {
          for(int j=0;j<nr_c;j++)
            cout<<a[i][j]<<" ";
            cout<<endl;
      }
}


matrice& matrice :: operator=(const matrice &ob) //suprascriere operator de atribuire
{
    if(this!=&ob)
    {
        for(int i=0;i<nr_l;i++)
        delete [] a[i];
        delete [] a;
        nr_l=ob.nr_l;
        nr_c=ob.nr_c;
        a=new float*[nr_l];
        for(int i=0;i<nr_l;i++)
              a[i]=new float[nr_c];
        for(int i=0;i<nr_l;i++)
             for(int j=0;j<nr_c;j++)
                a[i][j]=ob.a[i][j];
    }
    return*this;
}

matrice operator+(const matrice& A, const matrice& B)//funtie prietena pentru suma a doua matrici
{
    matrice rez;
    rez.nr_l=A.nr_l;
    rez.nr_c=A.nr_c;
     rez.a=new float*[rez.nr_l];
        for(int i=0;i<rez.nr_l;i++)
              rez.a[i]=new float[rez.nr_c];
    for(int i=0;i<rez.nr_l;i++)
             for(int j=0;j<rez.nr_c;j++)
                rez.a[i][j]=0;
    for(int i=0;i<rez.nr_l;i++)
             for(int j=0;j<rez.nr_c;j++)
                rez.a[i][j]=A.a[i][j]+B.a[i][j];
    return rez;
}

matrice operator+(const matrice& A)//functie prietena pentru returnarea matricei insasi
{
    return A;
}

matrice operator-(const matrice& A, const matrice& B)//funtie prietena pentru diferenta a doua matrici
{
    matrice rez;
    rez.nr_l=A.nr_l;
    rez.nr_c=A.nr_c;
     rez.a=new float*[rez.nr_l];
        for(int i=0;i<rez.nr_l;i++)
              rez.a[i]=new float[rez.nr_c];
    for(int i=0;i<rez.nr_l;i++)
             for(int j=0;j<rez.nr_c;j++)
                rez.a[i][j]=0;
    for(int i=0;i<rez.nr_l;i++)
             for(int j=0;j<rez.nr_c;j++)
                rez.a[i][j]=A.a[i][j]-B.a[i][j];
    return rez;
}

matrice operator-(const matrice& A) //functie prietena pentru opusa unei matrici
{
   matrice rez;
    rez.nr_l=A.nr_l;
    rez.nr_c=A.nr_c;
     rez.a=new float*[rez.nr_l];
        for(int i=0;i<rez.nr_l;i++)
              rez.a[i]=new float[rez.nr_c];
    for(int i=0;i<rez.nr_l;i++)
             for(int j=0;j<rez.nr_c;j++)
                rez.a[i][j]=0;
    for(int i=0;i<rez.nr_l;i++)
             for(int j=0;j<rez.nr_c;j++)
                rez.a[i][j]=-1*A.a[i][j];
    return rez;
}

matrice operator*(const matrice& A, const matrice& B)//functie pentru prdusul a doua matrici
{
     matrice rez;
    rez.nr_l=A.nr_l;
    rez.nr_c=A.nr_c;
     rez.a=new float*[rez.nr_l];
        for(int i=0;i<rez.nr_l;i++)
              rez.a[i]=new float[rez.nr_c];
     for(int i=0;i<rez.nr_l;i++) {
        for(int j=0;j<rez.nr_c;j++) {
            rez.a[i][j]=0;
            for(int x=0;x<rez.nr_l;x++) {
                rez.a[i][j] += A.a[i][x]*B.a[x][j];
            }
        }
     }
     return rez;
}

matrice operator*(const matrice& A, int x)//functie pentru inmultirea cu un scalar
{
    matrice rez;
    rez.nr_l=A.nr_l;
    rez.nr_c=A.nr_c;
     rez.a=new float*[rez.nr_l];
        for(int i=0;i<rez.nr_l;i++)
              rez.a[i]=new float[rez.nr_c];
    for(int i=0;i<rez.nr_l;i++)
             for(int j=0;j<rez.nr_c;j++)
                rez.a[i][j]=0;
    for(int i=0;i<rez.nr_l;i++)
         for(int j=0;j<rez.nr_c;j++)
        rez.a[i][j]=x*A.a[i][j];
    return rez;
}

matrice operator+=(const matrice& A, const matrice& B)//functie pentru suma a doua matrici retinuta in prima matrice
{
    matrice rez;
    rez.nr_l=A.nr_l;
    rez.nr_c=A.nr_c;
     rez.a=new float*[rez.nr_l];
        for(int i=0;i<rez.nr_l;i++)
              rez.a[i]=new float[rez.nr_c];
    for(int i=0;i<rez.nr_l;i++)
             for(int j=0;j<rez.nr_c;j++)
                rez.a[i][j]=A.a[i][j];

    for(int i=0;i<A.nr_l;i++)
         for(int j=0;j<A.nr_c;j++)
            rez.a[i][j]+=B.a[i][j];
         return rez;
}

matrice operator-=(const matrice& A, const matrice& B)//functie pentru diferenta a doua matrici retinuta in prima matrice
{
    matrice rez;
    rez.nr_l=A.nr_l;
    rez.nr_c=A.nr_c;
     rez.a=new float*[rez.nr_l];
        for(int i=0;i<rez.nr_l;i++)
              rez.a[i]=new float[rez.nr_c];
    for(int i=0;i<rez.nr_l;i++)
             for(int j=0;j<rez.nr_c;j++)
                rez.a[i][j]=A.a[i][j];

    for(int i=0;i<A.nr_l;i++)
         for(int j=0;j<A.nr_c;j++)
            rez.a[i][j]-=B.a[i][j];
         return rez;
}

matrice operator*=(const matrice& A, const matrice& B)//functie pentru produsul a doua matrici retinut in prima matrice
{
    matrice rez;
    rez.nr_l=A.nr_l;
    rez.nr_c=A.nr_c;
     rez.a=new float*[rez.nr_l];
        for(int i=0;i<rez.nr_l;i++)
              rez.a[i]=new float[rez.nr_c];
    for(int i=0;i<rez.nr_l;i++)
             for(int j=0;j<rez.nr_c;j++)
                rez.a[i][j]=A.a[i][j];

    for(int i=0;i<A.nr_l;i++)
         for(int j=0;j<A.nr_c;j++)
            rez.a[i][j]*=B.a[i][j];
         return rez;
}

matrice operator*=(const matrice& A, int x)//functie pentru inmultirea unei matrici cu un scalar retinut in matrice
{
    matrice rez;
    rez.nr_l=A.nr_l;
    rez.nr_c=A.nr_c;
     rez.a=new float*[rez.nr_l];
        for(int i=0;i<rez.nr_l;i++)
              rez.a[i]=new float[rez.nr_c];
    for(int i=0;i<rez.nr_l;i++)
             for(int j=0;j<rez.nr_c;j++)
                rez.a[i][j]=x;
    for(int i=0;i<rez.nr_l;i++)
         for(int j=0;j<rez.nr_c;j++)
        rez.a[i][j]*=A.a[i][j];
    return rez;
}

int operator==(const matrice& A, const matrice& B)//functie care testeaza daca doua matrici au toate elementele egale
{
    int ok=1;
    for(int i=0;i<A.nr_l;i++)
         for(int j=0;j<A.nr_c;j++)
            if(A.a[i][j]!=B.a[i][j])
                ok=0;
         return ok;
}

int nrlinii(const matrice&A)//functie care returneaza nr de linii din matrice
{
    return A.nr_l;
}

int nrcoloane(const matrice&A)//functie care returneaza nr de coloane din matrice
{
    return A.nr_c;
}

int nrelemente(const matrice&A)//functie care returneaza nr de elemente din matrice
{
    return A.nr_c*A.nr_l;
}


int operator==(float v[100], const matrice& A)//functie care testeaza daca un vector are elementele agale cu o matrice
{   int ok=1;
    for(int i=0;i<A.nr_l;i++)
         for(int j=0;j<A.nr_c;j++)
            if(A.a[i][j]!=v[i])
                ok=0;
         return ok;
}

int operator==(const matrice& A, float v[100])//functie care testeaza daca o matrice are elementele agale cu un vector
{   int ok=1;
    for(int i=0;i<A.nr_l;i++)
         for(int j=0;j<A.nr_c;j++)
            if(A.a[i][j]!=v[i])
                ok=0;
         return ok;
}


int operator!=(const matrice& A, const matrice& B)//functie care testeaza daca doua matrici au elementele diferite
{
    int ok=1;
    for(int i=0;i<A.nr_l;i++)
         for(int j=0;j<A.nr_c;j++)
            if(A.a[i][j]!=B.a[i][j])
                ok=0;
         return ok;
}

int operator!=(float v[100], const matrice& A)//fucntie care testeaza daca un vector are elementele diferite de o matrice
{   int ok=1;
    for(int i=0;i<A.nr_l;i++)
         for(int j=0;j<A.nr_c;j++)
            if(A.a[i][j]!=v[i])
                ok=0;
         return ok;
}

int operator!=(const matrice& A, float v[100])//functie care testeaza daca o matrice are elementele diferite de un vector
{   int ok=1;
    for(int i=0;i<A.nr_l;i++)
         for(int j=0;j<A.nr_c;j++)
            if(A.a[i][j]!=v[i])
                ok=0;
         return ok;
}

int operator<(const matrice& A, const matrice& B)//fucntie care tssteaza daca elementele dintr-o matrice sunt mai mici ca elementele din alta matrice
{
    int ok=1;
    for(int i=0;i<A.nr_l;i++)
         for(int j=0;j<A.nr_c;j++)
            if(A.a[i][j]>=B.a[i][j])
                ok=0;
         return ok;
}

int operator<(float v[100], const matrice& A)//fucntie care tssteaza daca elementele dintr-un vector sunt mai mici ca elementele dintr-o matrice
{   int ok=1;
    for(int i=0;i<A.nr_l;i++)
         for(int j=0;j<A.nr_c;j++)
            if(A.a[i][j]>=v[i])
                ok=0;
         return ok;
}

int operator<(const matrice& A, float v[100])//fucntie care tssteaza daca elementele dintr-o matrice sunt mai mici ca elementele dintr-un vector
{   int ok=1;
    for(int i=0;i<A.nr_l;i++)
         for(int j=0;j<A.nr_c;j++)
            if(A.a[i][j]>=v[i])
                ok=0;
         return ok;
}

int operator<=(const matrice& A, const matrice& B)//fucntie care tssteaza daca elementele dintr-o matrice sunt mai mici sau egale ca elementele din alta matrice
{
    int ok=1;
    for(int i=0;i<A.nr_l;i++)
         for(int j=0;j<A.nr_c;j++)
            if(A.a[i][j]>B.a[i][j])
                ok=0;
         return ok;
}

int operator<=(float v[100], const matrice& A)//fucntie care tssteaza daca elementele dintr-un vector sunt mai mici sau egale ca elementele dintr-o matrice
{   int ok=1;
    for(int i=0;i<A.nr_l;i++)
         for(int j=0;j<A.nr_c;j++)
            if(A.a[i][j]>v[i])
                ok=0;
         return ok;
}

int operator<=(const matrice& A, float v[100])//fucntie care tssteaza daca elementele dintr-o matrice sunt mai mici sau egale ca elementele dintr-un vector
{   int ok=1;
    for(int i=0;i<A.nr_l;i++)
         for(int j=0;j<A.nr_c;j++)
            if(A.a[i][j]>v[i])
                ok=0;
         return ok;
}

int operator>(const matrice& A, const matrice& B)//fucntie care tssteaza daca elementele dintr-o matrice sunt mai mari ca elementele din alta matrice
{
    int ok=1;
    for(int i=0;i<A.nr_l;i++)
         for(int j=0;j<A.nr_c;j++)
            if(A.a[i][j]<=B.a[i][j])
                ok=0;
         return ok;
}

int operator>(float v[100], const matrice& A)//fucntie care tssteaza daca elementele dintr-un vector sunt mai mari ca elementele dintr-o matrice
{   int ok=1;
    for(int i=0;i<A.nr_l;i++)
         for(int j=0;j<A.nr_c;j++)
            if(A.a[i][j]<=v[i])
                ok=0;
         return ok;
}

int operator>(const matrice& A, float v[100])//fucntie care tssteaza daca elementele dintr-o matrice sunt mai mari ca elementele dintr-un vrctor
{   int ok=1;
    for(int i=0;i<A.nr_l;i++)
         for(int j=0;j<A.nr_c;j++)
            if(A.a[i][j]<=v[i])
                ok=0;
         return ok;
}

int operator>=(const matrice& A, const matrice& B)//fucntie care tssteaza daca elementele dintr-o matrice sunt mai mari sau egale ca elementele din alta matrice
{
    int ok=1;
    for(int i=0;i<A.nr_l;i++)
         for(int j=0;j<A.nr_c;j++)
            if(A.a[i][j]<B.a[i][j])
                ok=0;
         return ok;
}

int operator>=(float v[100], const matrice& A)//fucntie care tssteaza daca elementele dintr-un vector sunt mai mari sau egale ca elementele dintr-o matrice
{   int ok=1;
    for(int i=0;i<A.nr_l;i++)
         for(int j=0;j<A.nr_c;j++)
            if(A.a[i][j]<v[i])
                ok=0;
         return ok;
}

int operator>=(const matrice& A, float v[100])//fucntie care tssteaza daca elementele dintr-o matrice sunt mai mari sau egale ca elementele dintr-un vector
{   int ok=1;
    for(int i=0;i<A.nr_l;i++)
         for(int j=0;j<A.nr_c;j++)
            if(A.a[i][j]<v[i])
                ok=0;
         return ok;
}

int operator!(const matrice& A)//functie care testeaza daca elementele dintr=o matrice sunt nule
{   int ok=1;
    for(int i=0;i<A.nr_l;i++)
         for(int j=0;j<A.nr_c;j++)
            if(A.a[i][j]!=0)
                ok=0;
         return ok;
}

int determinant(matrice A,int n)//functie care calculeaza determinantul unei matric de n*n
{
    int c, subi, i, j, subj,d=0;
    matrice submat;
    submat.nr_l=n;
    submat.nr_c=n;
     submat.a=new float*[submat.nr_l];
        for(int i=0;i<submat.nr_l;i++)
              submat.a[i]=new float[submat.nr_c];
    if (n == 2)
    {
        return( (A.a[0][0] * A.a[1][1]) - (A.a[1][0] * A.a[0][1]));
    }
    else
    {
        for(c = 0; c < n; c++)
        {
            subi = 0;
            for(i = 1; i < n; i++)
            {
                subj = 0;
                for(j = 0; j < n; j++)
                {
                    if (j == c)
                    {
                        continue;
                    }
                    submat.a[subi][subj] = A.a[i][j];
                    subj++;
                }
                subi++;
            }
        d = d + (pow(-1 ,c) * A.a[0][c] * determinant(submat,n-1));
        }
    }
    return d;
}

matrice operator~(const matrice&A)//functie care returneaza inversa unei matrici de 3*3
{   int i,j;
    int det=determinant(A,A.nr_l);
    matrice rez;
    rez.nr_l=A.nr_l;
    rez.nr_c=A.nr_c;
     rez.a=new float*[rez.nr_l];
        for( i=0;i<rez.nr_l;i++)
              rez.a[i]=new float[rez.nr_c];
    for(i = 0; i < rez.nr_l; i++)
		for(j = 0; j < rez.nr_l; j++)
			rez.a[i][j]=((A.a[(j+1)%3][(i+1)%3] * A.a[(j+2)%3][(i+2)%3]) - (A.a[(j+1)%3][(i+2)%3] * A.a[(j+2)%3][(i+1)%3]))/ det;
    return rez;
}

void ecuatie(matrice A, matrice B)//functie care rezolva ecuatia A*X+B=0
{
    int i,j;
    matrice mat_nul,inv,rez;
    mat_nul.nr_l=A.nr_l;
    mat_nul.nr_c=A.nr_c;
    mat_nul.a=new float*[mat_nul.nr_l];
        for( i=0;i<mat_nul.nr_l;i++)
              mat_nul.a[i]=new float[mat_nul.nr_c];
    for(i=0;i<mat_nul.nr_l;i++)
        for(j=0;j<mat_nul.nr_l;j++)
        mat_nul.a[i][j]=0;
      inv.nr_l=A.nr_l;
    inv.nr_c=A.nr_c;
    inv.a=new float*[inv.nr_l];
        for( i=0;i<inv.nr_l;i++)
              inv.a[i]=new float[inv.nr_c];
    rez.nr_l=A.nr_l;
    rez.nr_c=A.nr_c;
     rez.a=new float*[rez.nr_l];
        for(int i=0;i<rez.nr_l;i++)
              rez.a[i]=new float[rez.nr_c];
   inv.operator=(operator~(A));
    rez.operator=(operator-(B));
    rez.operator=(operator*(inv,rez));
    for(i=0;i<rez.nr_l;i++)
     {
         for(j=0;j<rez.nr_l;j++)
        cout<<rez.a[i][j]<<' ';
       cout<<endl;
     }


}
int main()
{
    matrice x,y,z,p,q;
    int n,w;
    float v[100];

    cout<<"Citire linii, coloane, prima matrice:";
    x.citire();
    cout<<"Citire linii, coloane, a doua matrice:";
    y.citire();

    cout<<endl<<"Afisarea nr de linii"<<endl;
    cout<<nrlinii(x);

    cout<<endl<<"Afisarea nr de coloane"<<endl;
    cout<<nrcoloane(x);

    cout<<endl<<"Afisarea nr de elemente"<<endl;
    cout<<nrelemente(x);

    z.operator=(operator+(x,y));
    cout<<endl<<"Afisarea sumei celor doua matrici citite"<<endl;
    z.afisare();

    cout<<"Afisarea matricei insasi (prima citita)"<<endl;
    z.operator=(operator+(x));
    z.afisare();

    cout<<"Afisarea diferentei celor doua matrici citite"<<endl;
    z.operator=(operator-(x,y));
    z.afisare();

    cout<<"Afisarea matricei opuse (prima citita)"<<endl;
    z.operator=(operator-(x));
    z.afisare();

    cout<<"Afisarea produsului celor doua matrici"<<endl;
    z.operator=(operator*(x,y));
    z.afisare();

    cout<<"Citirea scalarului cu care vom inmulti matricea:"<<endl;
    cin>>w;
    cout<<"Afisarea primei matrice inmultita cu scalarul "<<w<<endl;
    z.operator=(operator*(x,w));
    z.afisare();

    cout<<"Afisarea sumei retinuta in prima matrice"<<endl;
    z.operator=(operator+=(x,y));
    z.afisare();

    cout<<"Afisarea diferentei retinuta in prima matrice"<<endl;
    z.operator=(operator-=(x,y));
    z.afisare();

    cout<<"Afisarea produsului celor doua matrici element cu element"<<endl;
    z.operator=(operator*=(x,y));
    z.afisare();

    cout<<"Citirea scalarului cu care vom inmulti matricea:"<<endl;
    cin>>w;
    cout<<"Afisarea primei matrice inmultita cu scalarul "<<w<<endl;
    z.operator=(operator*=(x,w));
    z.afisare();

    cout<<"Verificare daca cele doua matrci sunt identice (au toate elementele egale)"<<endl;
        if(operator==(x,y)==1)
            cout<<"Matricile au toate elementele egale"<<endl;
        else
            cout<<"Matricile nu au toate elementele egale"<<endl;

   n=nrlinii(x);
    cout<<"Citirea vectorului cu care vom compara matricea"<<endl;
    for(int i=0;i<n;i++)
        cin>>v[i];

    cout<<"Verificare daca vectorul citit are elementele egale cu cele din matrice var 1"<<endl;
        if(operator==(v,x)==1)
            cout<<"da"<<endl;
        else
            cout<<"nu"<<endl;


    cout<<"Verificare daca vectorul citit are elementele egale cu cele din matrice var 2"<<endl;
        if(operator==(x,v)==1)
            cout<<"da"<<endl;
        else
            cout<<"nu"<<endl;

    cout<<"Verificare daca cele doua matrci sunt diferite (nu sunt egale)"<<endl;
        if(operator!=(x,y)==0)
            cout<<"matricile nu sunt egale"<<endl;
        else
            cout<<"matricile sunt egale"<<endl;


    cout<<"Verificare daca vectorul citit are elementele diferite fata de cele din matrice var 1"<<endl;
        if(operator!=(v,x)==0)
            cout<<"da"<<endl;
        else
            cout<<"nu"<<endl;


    cout<<"Verificare daca vectorul citit are elementele diferite fata de cele din matrice var 2"<<endl;
        if(operator!=(x,v)==0)
            cout<<"da"<<endl;
        else
            cout<<"nu"<<endl;

    cout<<"Verificare daca toate elementele din prima matrice sunt mai mici ca elementele din a doua matrice"<<endl;
        if(operator<(x,y)==1)
            cout<<"Da"<<endl;
        else
            cout<<"Nu"<<endl;


    cout<<"Verificare daca toate elementele din prima matrice sunt mai mici ca elementele din vector (var 1)"<<endl;
        if(operator<(v,x)==1)
            cout<<"Da"<<endl;
        else
            cout<<"Nu"<<endl;


    cout<<"Verificare daca toate elementele din prima matrice sunt mai mici ca elementele din vector (var 2)"<<endl;
        if(operator<(x,v)==1)
            cout<<"Da"<<endl;
        else
            cout<<"Nu"<<endl;

    cout<<"Verificare daca toate elementele din prima matrice sunt mai mici sau egale ca elementele din a doua matrice"<<endl;
        if(operator<=(x,y)==1)
            cout<<"Da"<<endl;
        else
            cout<<"Nu"<<endl;


    cout<<"Verificare daca toate elementele din prima matrice sunt mai mici sau egale ca elementele din vector (var 1)"<<endl;
        if(operator<=(v,x)==1)
            cout<<"Da"<<endl;
        else
            cout<<"Nu"<<endl;


    cout<<"Verificare daca toate elementele din prima matrice sunt mai mici sau egale ca elementele din vector (var 2)"<<endl;
        if(operator<=(x,v)==1)
            cout<<"Da"<<endl;
        else
            cout<<"Nu"<<endl;

    cout<<"Verificare daca toate elementele din prima matrice sunt mai mari ca elementele din a doua matrice"<<endl;
        if(operator>(x,y)==1)
            cout<<"Da"<<endl;
        else
            cout<<"Nu"<<endl;


    cout<<"Verificare daca toate elementele din prima matrice sunt mai mari ca elementele din vector (var 1)"<<endl;
        if(operator>(v,x)==1)
            cout<<"Da"<<endl;
        else
            cout<<"Nu"<<endl;


    cout<<"Verificare daca toate elementele din prima matrice sunt mai mari ca elementele din vector (var 2)"<<endl;
        if(operator>(x,v)==1)
            cout<<"Da"<<endl;
        else
            cout<<"Nu"<<endl;

    cout<<"Verificare daca toate elementele din prima matrice sunt mai mari sau egale ca elementele din a doua matrice"<<endl;
        if(operator>=(x,y)==1)
            cout<<"Da"<<endl;
        else
            cout<<"Nu"<<endl;


    cout<<"Verificare daca toate elementele din prima matrice sunt mai mari sau egale ca elementele din vector (var 1)"<<endl;
        if(operator>=(v,x)==1)
            cout<<"Da"<<endl;
        else
            cout<<"Nu"<<endl;


    cout<<"Verificare daca toate elementele din prima matrice sunt mai mari sau egale ca elementele din vector (var 2)"<<endl;
        if(operator>=(x,v)==1)
            cout<<"Da"<<endl;
        else
            cout<<"Nu"<<endl;

    cout<<"Verificare daca toate elementele din prima matrice sunt nule"<<endl;
        if(operator!(x)==1)
            cout<<"Toate elementele din matrice sunt nule"<<endl;
        else
            cout<<"Nu toate elementele din matrice sunt nule"<<endl;

    cout<<endl<<"Citirea nr de linii, nr de coloane si a primei matrice de 3*3, A"<<endl;
    p.citire();

    cout<<endl<<"Afisarea determinantului"<<endl;
    cout<<determinant(p,nrlinii(p));

    cout<<endl<<"Afisarea matricei inverse"<<endl;
    z.operator=(operator~(p));
    z.afisare();

    cout<<endl<<"Citirea nr de linii, nr de coloane si a celei de-a doua matrice de 3*3, B"<<endl;
    q.citire();

    cout<<endl<<"Rezolvarea ecuatiei A*X+B=0"<<endl;
    ecuatie(p,q);


       return 0;
}
