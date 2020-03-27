#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main()
{
    int n, nfin, init, fin[100],i,j,nstari,k,z,max=0,ok=0;
    char w[100],x[100],a[100][100][100];

    ifstream f("fisier3.in");

    f>>w;//cuvant dat
    f>>nstari;//numar de stari
    f>>init;//stare initiala
    f>>nfin;//numar de stari finite
    for(i=1;i<=nfin;i++)
    {
        f>>fin[i];//stare finita
    }
    f>>n;//numar de tranzitii

    for(i=0;i<nstari;i++)
        for(j=0;j<nstari;j++)
                a[i][j][0]=' ';
    while(n)
    {
        f>>i>>j>>x;//tranzitie de la i la j cu simbolul x
        if(a[i][j][0]!=' ')
            {
                strcat(a[i][j],x);
                if(strlen(a[i][j])>max)
                    max=strlen(a[i][j]);
            }
        else strcpy(a[i][j],x);
        n--;
    }

    for(i=init;i<nstari;i++)
        for(j=0;j<nstari;j++)
            for(k=0;k<max;k++)
            {
                if(w!=NULL)
                {
                    if(j!=i+1&&w[0]==a[i][j][k]&&a[i][j][k]!=NULL)
                    {
                        strcpy(w,w+1);
                        for(z=1;z<=nfin;z++)
                            if(fin[z]==j&&w[0]==NULL)
                            {
                                ok=1;
                                cout<<"Cuvantul apartine limbajului recunoscut de automat"<<endl;
                                break;
                            }
                        i=j;
                        j=0;
                        k=0;
                    }

                    if(i==j)
                    {
                        while(w[0]==a[i][j][k]&&a[i][j][k]!=NULL)
                        {
                            strcpy(w,w+1);
                            for(z=1;z<=nfin;z++)
                                if(fin[z]==j&&w[0]==NULL)
                                {
                                    ok=1;
                                    cout<<"Cuvantul apartine limbajului recunoscut de automat"<<endl;
                                    break;
                                }
                        }
                    }
                    else if(j==i+1)
                    {
                        if(w[0]==a[i][j][k]&&j==i+1&&a[i][j][k]!=NULL)
                        {
                            strcpy(w,w+1);
                            for(z=1;z<=nfin;z++)
                                    if(fin[z]==j&&w[0]==NULL)
                                    {
                                        ok=1;
                                        cout<<"Cuvantul apartine limbajului recunoscut de automat"<<endl;
                                        break;
                                    }
                        }
                    }
                }
            }

    if(ok==0)
        cout<<"Cuvantul nu apartine limbajului recunoscut de automat"<<endl;
}
