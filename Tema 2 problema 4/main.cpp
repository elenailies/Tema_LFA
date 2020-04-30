#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
char a[100][100][100];
int fin[100],nfin;

int apartine(int nr,int stare,char w[100])
    {
        int i=0,j,len,stare2[100]={0},ok=0,k;
        char cuv[100];
        strcpy(cuv,w);
        if(strlen(cuv)==0)
            for(k=0;k<nfin;k++)
            {
                if(stare==fin[k])
                return 1;
            }
        else{
            for(j=0;j<nr;j++)
            {
                len=strlen(a[stare][j]);
                for(k=0;k<len;k++)

                    if(a[stare][j][k]==w[0] )
                        {stare2[i++]=j;
                        ok=1;
                        }
            }

        if(ok==0 && strlen(cuv)!=0)
            return 0;

        strcpy (cuv,cuv+1);
        for(k=0;k<i;k++)
            if(apartine(nr,stare2[k],cuv)==1)
                return 1;
        }
           return 0;
    }

int main()
{
    ifstream f("fisier4.in");
    int nr,init=0,i,j,n,k;
    char z,x,i1,j1;
    char w[100],y[100];

    f>>w;//cuvant de verificat
    f>>nr;//numar de stari
    f>>n;//numar de tranzitii

    for(i=0;i<nr+1;i++)
        for(j=0;j<nr+1;j++)
                a[i][j][0]='0';

    int j_fin=nr;

    nfin=-1;

    while(n)
    {
        f>>x>>y>>z;
        i1=x-48;
        if(z!='-')
        {
            j1=z-48;

                if(a[i1][j1][0]!='0')
                    strcat(a[i1][j1],y);
                else strcpy(a[i1][j1],y);
        }
        else if(y[0]=='^')
                {
                    fin[++nfin]=i1;
                }
        else
        {
            fin[++nfin]=j_fin;
            cout<<"j_fin este: "<<j_fin;
            if(a[i1][j_fin][0]!='0')
                    strcat(a[i1][j_fin],y);
                else strcpy(a[i1][j_fin],y);

        }
        n--;
    }

    nfin++;

    for(i=0;i<nr+1;i++)
    {
        cout<<endl;
        for(j=0;j<nr+1;j++)
            cout<<a[i][j]<<" ";
    }
    cout<<endl;
    for(i=0;i<nfin;i++)
        cout<<fin[i]<<" ";

    cout<<endl;
    cout<<endl;
    if(apartine(nr+1,init,w))
        cout<<"Cuvantul poate fi generat de gramatica regulata";
    else
        cout<<"Cuvantul nu poate fi generat de gramatica regulata";
    cout<<endl;


    f.close();

    return 0;
}
