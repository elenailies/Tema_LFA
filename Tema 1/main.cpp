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
{   ifstream f("verificare.txt");
    int nr,init,i,j,n,k;
    char x,w[100];
    f>>w;//cuvant de verificat
    f>>nr; //nr de stari
    f>>init; //starea initiala
    f>>nfin; //nr de stari finale
    for(i=0;i<nfin;i++)
        f>>fin[i]; //starile finale
    f>>n; //numar de tranzitii

    for(i=0;i<nr;i++)
        for(j=0;j<nr;j++)
                a[i][j][0]='0';

    for(k=0;k<n;k++)
       {
        f>>i>>j>>x;
        strncat(a[i][j], &x, 1);
        if(a[i][j][0]=='0')
            strcpy(a[i][j],a[i][j]+1);
       }
    for(i=0;i<nr;i++)
        {
            cout<<endl;
            for(j=0;j<nr;j++)
                cout<<a[i][j]<<" ";
        }
        cout<<endl;

    if(apartine(nr,init,w))
        cout<<"Cuvantul apartine limbajului recunoscut de automat";
    else
        cout<<"Cuvantul nu apartine limbajului recunoscut de automat";

    f.close();

    return 0;
}
