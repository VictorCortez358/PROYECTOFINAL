#include "iostream"
#include "cstring"
#include "string.h"
using namespace std;
const int longCad = 20;

struct costoPorArticulo{
char nombreArticul[longCad + 1];
int cantidad;
float precio;
float costo;
};
void leerdatos(int,costoPorArticulo factura[]);
void costo(int,costoPorArticulo factura[]);
void mostrardatos(int,costoPorArticulo factura[]);
void retornarcostos(int,costoPorArticulo factura[],float*);

int main(void)
{
	cout<<endl;
	cout<<"GENERADOR DE FACTURA DE COMPRA DE ARTICULOS"<<endl<<endl;
    int n;
    float costototal=0;
    cout<<"Ingrese la cantidad de articulos comprados: ";
    cin>>n;
    cin.ignore(100, '\n' );
    costoPorArticulo factura[n];
    leerdatos(n,factura);
    costo(n,factura);
    mostrardatos(n,factura);
    retornarcostos(n,factura,&costototal);
    cout<<"El costo total es de: "<<costototal<<endl;
    return 0;
    
}
void leerdatos(int n,costoPorArticulo factura[])
{
 char c;
 string cad;
  for(int i=0;i<n;i++){
    cout<<"Ingrese el nombre del Articulo:";
    getline(cin,cad, '\n');
    strncpy(factura[i].nombreArticul,cad.c_str(),longCad);
    factura[i].nombreArticul[longCad]='\n';
    cout<<"Ingrese la cantidad comprada: ";
    cin>>factura[i].cantidad;
    cout<<"Ingrese el precio del Articulo: ";
    cin>>factura[i].precio;
    cin.ignore(100, '\n');
 }
 }
 void costo(int n,costoPorArticulo factura[])
 {
 	
 	for(int i=0;i<n;i++){
 		factura[i].costo= factura[i].cantidad*factura[i].precio;
	 }
 	
 }

 void mostrardatos(int n,costoPorArticulo factura[])
 {
 	for(int i=0;i<n;i++){
	 
 	cout<<"Articulo comprado: "<<factura[i].nombreArticul<<endl;
 	cout<<"Cantidad comprada: "<<factura[i].cantidad<<endl;
 	cout<<"Precio unitario del Articulo: "<<factura[i].precio<<endl;
 	cout<<"Costo por Articulo: "<<factura[i].costo<<endl;
 	}
 }
 void retornarcostos(int n,costoPorArticulo factura[],float*costototal)
 {
 	for(int i=0;i<n;i++){
 	*costototal+=factura[i].costo;
	 }
 }
