#include<iostream>
#include<iomanip>
#include<math.h>
#include<stdlib.h>

#define TAMANIO 10

using namespace std;

int main()
{
		 float a[TAMANIO][TAMANIO], x[TAMANIO], ratio;
		 int i,j,k,n;

         /* precision de decimales  */
         cout<< setprecision(7)<< fixed;

		 /* entradas*/
		 /* 1. Orden de la matriz*/
		 cout<<"Ingrese Orden de la matriz: ";
		 cin>>n;

		 /* 2. leer valores matriz*/
		 cout<<"Ingrese los coeficientes de la matriz " << endl;
		 for(i=1;i<=n;i++)
		 {
			  for(j=1;j<=n;j++)
			  {
				   cout<<"a["<< i<<"]"<< j<<"]=";
                   cin>>a[i][j];//**
			  }
			  cout<<endl;
		 }

		 /* Argumento de la matriz */
		 for(i=1;i<=n;i++)
		 {
			  for(j=1;j<=n;j++)
			  {
				   if(i==j)
				   {
				    	a[i][j+n] = 1;
				   }
				   else
				   {
				    	a[i][j+n] = 0;
				   }
			  }
		 }

		 /* Aplicando eliminacion de Gauss jordan */
		 for(i=1;i<=n;i++)
		 {
			  if(a[i][i] == 0.0)
			  {
				   cout<<" Error!";
				   exit(0);
			  }
			  for(j=1;j<=n;j++)
			  {
				   if(i!=j)
				   {
					    ratio = a[j][i]/a[i][i];
					    for(k=1;k<=2*n;k++)
					    {
					     	a[j][k] = a[j][k] - ratio*a[i][k];
					    }
				   }
			  }
		 }
		 /* Row Operation to Make Principal Diagonal to 1 */
		 for(i=1;i<=n;i++)
		 {
			  for(j=n+1;j<=2*n;j++)
			  {
			   	a[i][j] = a[i][j]/a[i][i];
			  }
		 }
		 /* Muestra Inversa Matriz */
		 cout<< endl<<"Inversa de la matriz es: \n A' = "<< endl;
		 for(i=1;i<=n;i++)
		 {    cout<<"º";
			  for(j=n+1;j<=2*n;j++)
			  {
			   	cout<< a[i][j]<<"\t";
			  }
			  cout<<"º";
			  cout<< endl;
		 }
		 return(0);
}
