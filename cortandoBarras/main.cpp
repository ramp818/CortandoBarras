#include <iostream>
#include <algorithm>

using namespace std;

int lugar_corte[60],arr[60][60];

void arreglo()
{
    for(int i=0;i<60;i++)
        for(int j=0;j<60;j++)
            arr[i][j]=-1;
}


int costoMinimo(int a,int b)
{
    int costo=0,minimo=100000000;
    if(a+1==b)
    {
        return 0;
    }
    if(arr[a][b]!=-1)
    {
        return arr[a][b];
    }
    for(int i=a+1;i<b;i++)
    {
        costo=costoMinimo(a,i)+costoMinimo(i,b)+lugar_corte[b]-lugar_corte[a];
        minimo=min(costo,minimo);
    }

    return arr[a][b]=minimo;
}

int main()
{
    int barra,cortes,costo_minimo;

    cin>>barra;
    while(barra != 0)
    {
        cin>>cortes;
        for(int i=1;i<=cortes;i++)
        {
            cin>>lugar_corte[i];
        }
        arreglo();
        lugar_corte[0]=0;
        lugar_corte[cortes+1]=barra;
        costo_minimo=costoMinimo(0,cortes+1);
        cout<<"The minimum cutting is "<<costo_minimo<<"."<<endl;
        cin>>barra;
    }
    return 0;
}
