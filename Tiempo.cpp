#include <iostream>
using namespace std;
class fecha
{
    private:
        int dia;
        int mes;
        int anio;
    public:
        fecha() {  dia=0; mes=0; anio=0;  }
        void get_fecha();
        void calcular(fecha,fecha);
        void show_fecha();
        int show_anio();
        int dia_mes(int,int);
        int bisiesto(int);

    };

void fecha::get_fecha()
    {
       cout<<"\tIngresa el dia = ";
       cin>>dia;

       cout<<"\tIngresa el mes = ";
       cin>>mes;

       cout<<"\tIngresa el año = ";
       cin>>anio;
    }

void fecha::show_fecha()
{
       cout<<"\n\t La fecha ingresada es:    ";
       cout<<((dia<10)?"0":"")<<this->dia<<" : ";
       cout<<((mes<10)?"0":"")<<this->mes<<" : "<<this->anio<<endl;
}
int fecha::show_anio()
{
    return this->anio;
}
void fecha::calcular(fecha d1,fecha d2)
{
    long d=1,m=0,a=0,year=0;
    year=d1.anio;
    a=d2.anio-d1.anio;
    if(a==0)
        m=d2.mes-d1.mes;
    if(a==1)
            m=12-(d1.mes)+d2.mes;
    if(a>1)
	{
		if(a-2==0)
			m=m+12+ 12-(d1.mes) + d2.mes;
		else
			m=m+((a-1)*12)+ 12-(d1.mes) + d2.mes;
	}
    
    if(a==0&&(d2.mes-d1.mes)==0)
        d=d2.dia-d1.dia;
    if(a==0&&(d2.mes-d1.mes)>0)
    {
        d = d+(dia_mes(d1.mes,d1.anio)) - d1.dia;
        for(int l=(d1.mes)+1;l<d2.mes;l++)
        {
			
            d=d+dia_mes(l,year);
        }
        d = d + d2.dia;
    }
    if(a>=1)
    {
		d = d+(dia_mes(d1.mes,d1.anio)) - d1.dia;
		for(int i=(d1.mes)+1;i<=12;i++)
        {
            d=d+dia_mes(i,year);
        }
	    for(int j=year+1;j<=d2.anio-1;j++)
		{
			d=d+(365+bisiesto(j));
		}
		for(int k=1;k<=d2.mes-1;k++)
		{
			d=d+dia_mes(k,d2.anio);
		}
		d = d + d2.dia;
    }
    cout<<"Han pasado: "<<d*24*60*60<< " segundos.\n";
    cout<<"Han pasado: "<<d*24*60<< " minutos.\n";
    cout<<"Han pasado: "<<d*24<< " horas.\n";
    cout<<"Han pasado: "<<d<< " dias.\n";
    cout<<"Han pasado: "<<d/7<< " semanas.\n";
    cout<<"Han pasado: "<<m<< " meses.\n";
    cout<<"Han pasado: "<<a<< " años.\n";
}


int fecha::dia_mes(int m,int y)
    {
       int dias;

       if(m<1)
            m+=12;
       else
        if(m>12)
            m-=12;

       switch(m)
      {
         case 1 : dias=31;
              break;

         case 2 : dias=28+bisiesto(y);
              break;

         case 3 : dias=31;
              break;

         case 4 : dias=30;
              break;

         case 5 : dias=31;
              break;

         case 6 : dias=30;
              break;

         case 7 : dias=31;
              break;

         case 8 : dias=31;
              break;

         case 9 : dias=30;
              break;

         case 10 : dias=31;
              break;

         case 11 : dias=30;
              break;

         case 12 : dias=31;
              break;
      }

       return dias;
}

int fecha::bisiesto(int y)
{
    if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
        return 1;
    else
        return 0;
}



int main()
    {
       fecha fecha1;
       fecha fecha2;
       fecha fecha3;

       cout<<"\n Ingrese las fechas en el patron i.e  dd/mm/aa "<<endl;

       cout<<"\n  Primera Fecha :"<<endl;
       fecha1.get_fecha();

       cout<<"\n  Second Date :"<<endl;
       fecha2.get_fecha();

       cout<<"\n********** First Date **********"<<endl;
       fecha1.show_fecha();

       cout<<"\n********** Second Date **********"<<endl;
       fecha2.show_fecha();

       cout<<"\n********** Result **********\n"<<endl;
       if(fecha1.show_anio()>fecha2.show_anio())
        fecha3.calcular(fecha2,fecha1);
       else
        fecha3.calcular(fecha1,fecha2);
       return 0;
}
