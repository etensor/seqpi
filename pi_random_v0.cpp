#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include <algorithm>
#include <fstream>

using namespace std;

string plotmap[8];
int contador = 0;
string pi_value;

void getpi(){
  ifstream leerpi;
  leerpi.open("pitxt.txt", ifstream :: in);

    while(!leerpi.eof()) {
    string linea;
    getline(leerpi,linea);
    pi_value = linea;
  }
  leerpi.close();
}

void randomizar(int numeros[], int rango){
int rand_num;
  for (int i = 0; i<100; i++){
    rand_num = rand() % (rango+1);
    numeros[i] = rand_num;
  }
  
}

/*
contar_numeros

Luego de asignarse los valores del arreglo numeros en la función randomizar,
pasa el arreglo por esta función acompañado de otro arreglo repeticiones,
donde cada caso será contado. Para esto use los indices del arreglo repeticiones
como pauta para contar, ya que este segundo arreglo tiene la longitud del rango
de los números contenidos en el arreglo numeros y todos sus elementos empiezan en 0,
se puede recorrer el primer arreglo viendo que número es y luego el elemento del arreglo
con el indice del número que salió aumentará en 1, contando así el caso.


*/

//comprobar que son 100. [◙]



int contar_cifras (int* numeros, unsigned long int* repeticiones, int fase){
int max = 0;
for (int k = 0; k<fase; k++){
  int num_salio;
  num_salio = numeros[k];
  repeticiones[num_salio]++;
  if (max < repeticiones[num_salio]) max = repeticiones[num_salio];
  }

return max;
}



int contar_numeros (int* numeros, int* repeticiones){
int max = 0;
for (int k = 0; k<100; k++){
  int num_salio;
  num_salio = numeros[k];
  repeticiones[num_salio]++;
  if (max < repeticiones[num_salio]) max = repeticiones[num_salio];
  }

return max;
}

//////////////////plot cipher plot 

void feel_Datapi (string valor_pi,int dim, int max){

fstream plotpi;
plotpi.open("piplot.txt", fstream::out);

string data;
string cols[max+5][dim+1];
//string rows[max+5]; //plt space
int val_y;
string rs;
string plot;

cout<<"\n\n __________\n  piseq_r :\n"<<endl;
cout<<" distribución:"<<endl;
for(int x = 0; x < dim; x++){
    rs += valor_pi[x];
    val_y = stoi(rs);
    rs.clear();

      for (int j = max+4; j >= val_y; j--){
        data = ".";
        cols[j][x] = data;

      }
    
                  
      for (int k = 0; k < val_y; k++){
        data = "Ø";
        cols[k][x] = data;
        
      }

  data.clear();
}

plot.append("\n");
for (int j = max+3; j >= 0;j--){

      for (int i = 0; i < dim; i++){
        plot.append(cols[j][i] + "  ");
      }
  
  plot.append("\n");
  }
  for (int i = 0; i < dim; i++) plot.append("___");
  plot.append("\n");

  for (int i = 0; i < dim; i++){
    string rs;
    rs = valor_pi[i];
    plot.append(rs);
    if ( stoi(rs) < 10) plot.append("  ");
    else plot.append(" ");
  }


cout<<plot<<endl;
plotpi<<plot;
plotpi.close();
plot.clear();

}



///PI see_Data : correctn rep pi uli + dimension correct

void see_Datapi (unsigned long int* repeticiones, int dim, int max){

string data;
string cols[max+6][dim+1];
//string rows[max+5]; //plt space
int val_y;
string plot;

cout<<"\n\n __________\n  mtrT_r :\n"<<endl;
cout<<" distribución:"<<endl;
for(int x = 0; x < dim; x++){
    val_y = repeticiones[x];

      for (int j = max+5; j >= val_y; j--){
        data = ".";
        cols[j][x] = data;

      }
    
                  
    for (int k = 0; k < val_y; k++){
        data = "Ø";
        cols[k][x] = data;
        
      }

  data.clear();
}

for (int i = 0; i < dim; i++){
     plot.append(to_string(repeticiones[i]));
    if ( repeticiones[i] < 10) plot.append("  ");
    else plot.append(" ");
  }
plot.append("\n");
for (int j = max+4; j >= 0;j--){

      for (int i = 0; i < dim; i++){
        plot.append(cols[j][i] + "  ");
      }
  
  plot.append("\n");
  }
  for (int i = 0; i < dim; i++) plot.append("___");
  plot.append("\n");

  for (int i = 0; i < dim; i++){
    plot.append(to_string(i));
    if ( i < 10) plot.append("  ");
    else plot.append(" ");
  }


cout<<plot<<endl;
contador++;
if (contador < 8) plotmap[contador] = plot;
plot.clear();


}


void see_Data (int* repeticiones, int dim, int max){

string data;
string cols[max+6][dim+2];
//string rows[max+5]; //plt space
int val_y;
string plot;

cout<<"\n\n __________\n  mtrT_r :\n"<<endl;
cout<<" distribución: 100 random [0-"<<dim<<"] :\n"<<endl;
for(int x = 0; x < dim+1; x++){
    val_y = repeticiones[x];

    for (int j = max+5; j >= val_y; j--){
        data = ".";
        cols[j][x] = data;

      }
    
                  
    for (int k = 0; k < val_y; k++){
        data = "Ø";
        cols[k][x] = data;
        
      }

  data.clear();
}

for (int i = 0; i < dim+1; i++){
     plot.append(to_string(repeticiones[i]));
    if ( repeticiones[i] < 10) plot.append("  ");
    else plot.append(" ");
  }
plot.append("\n");
for (int j = max+4; j >= 0;j--){

      for (int i = 0; i < dim+1; i++){
        plot.append(cols[j][i] + "  ");
      }
  
  plot.append("\n");
  }
  for (int i = 0; i < dim; i++) plot.append("___");
  plot.append("\n");

  for (int i = 0; i < dim+1; i++){
    plot.append(to_string(i));
    if ( i < 10) plot.append("  ");
    else plot.append(" ");
  }


cout<<plot<<endl;
contador++;
if (contador < 8) plotmap[contador] = plot;
plot.clear();


}




int main() {
  
srand(time(NULL));
//get random !100 -> rand % n+1; n \in [0,n], get len.

cout<<" visualizar distribución de cifras de pi.\n\n"<<endl;
cout<<"_________obteniendo pi"<<endl;

getpi();

int len;
bool opt = 1;
int iter;
int duracion;

cout<<"\npi decomp_________\n\n"<<endl;
for (int ix = 0; ix < 10; ix++){
  cout<<"cphr["<<ix<<"] = "<<pi_value[ix]<<endl;
}

int pirange_a, pirange_b, fase;
cout<<"desde cifra n: "; cin>>pirange_a;
cout<<"\nhasta cifra m: ";cin>>pirange_b;
int ncifras = pirange_b - pirange_a;
cout<<" x cifras : "<<ncifras<<endl;
cout<<"ingresar fase <= x cifras : < "<<ncifras<<endl;
cout<<"de cuanto en cuanto? fase: ";cin>>fase;cout<<endl;

/// feelpi Sequence: 


feel_Datapi(pi_value, pirange_b, 9);

/*
for (int ix = pirange_a; ix < (pirange_b); ix++){
  string rs;
  rs +=(pi_value[ix]);
  int rk = stoi(rs);
  //cout<<"cphr["<<ix<<"] = "<<rk<<endl;

  rs.clear();
}
*/


unsigned long int* cphrcount = new unsigned long int[10]{0}; // 0-9 system count
int* n_pi = new int[fase];
//int* piciphreps = new int[len+2]{0};

unsigned long int* localcphrcnt = new unsigned long int[10]{0};


int dts;
int opcion;
cout<<"\n dt (millisecs): "; cin >> dts;
while(opcion != 1 && opcion !=2){
  cout<<"\n conteo progresivo, segmentado ? 1 o 2";cin>>opcion;
  }
dts *= 1000;
int ikx = 0;
while (ikx*fase < ncifras ) ikx++;


for (int dt = 0; dt < ikx; dt++){
  for (int ds = 0; (ds < fase); ds++){
      string rs;
      if (dt*fase + ds > ncifras) break;
      rs +=(pi_value[(dt*fase) + ds]);
      n_pi[ds] = stoi(rs);

      rs.clear();
  }

  int locmax = 0;
  if (opcion == 2){
    for (int i = 0; i < 10; i++){
      cphrcount[i] += localcphrcnt[i];
      localcphrcnt[i]= 0;
    }

    locmax = contar_cifras(n_pi, localcphrcnt,fase);
    see_Datapi(localcphrcnt, 10, locmax);
    usleep(dts);
    if (dt < ikx-1) system("clear");
  }
  else{

  locmax = contar_cifras(n_pi, cphrcount,fase);
  see_Datapi(cphrcount, 10, locmax);
  usleep(dts);
  if (dt < ikx-1) system("clear");
  }
}


for (int i = 0; i <= 9; i++){
  cout<<" "<< i <<" salió "<<cphrcount[i]<<" veces."<<endl;
}


delete[] cphrcount;
delete[] localcphrcnt;
delete[] n_pi;


cout<<"\n random len? 1 or 0 \n"<<endl;
cin>>opt;

if (!opt){ cout<<"\naleatorios de 0 a ? : "; cin >> len;}
else len = rand() % 41;


int* numeros = new int[100];
int* repeticiones = new int[len+2]{0};
int* rep_iteraciones = new int[len+2]{0};
int suma = 0;
int max_v = 0;

string **resultados; 
resultados = new string* [len+2]; 



cout<<"\n 100 valores aleatorios entre 0 y "<<len<<" : \n"<<endl;
cout<<" n iteraciones: ";cin>> iter;
cout<<"\n dt (millisecs): "; cin >> duracion;
duracion *= 1000;

for (int dt = 1; dt < iter; dt++){
  randomizar(numeros,len);
  max_v = contar_numeros(numeros, repeticiones);
  see_Data(repeticiones, len, max_v);
  usleep(duracion);
  system("clear");
  for (int i = 0; i <= len; i++){
    rep_iteraciones[i] += repeticiones[i];
    repeticiones[i] = 0;
  }
}

randomizar(numeros,len);
max_v = contar_numeros(numeros, repeticiones);
see_Data(repeticiones, len, max_v);

for (int i = 0; i <= len; i++){
    rep_iteraciones[i] += repeticiones[i];
    repeticiones[i] = 0;
}

delete[] numeros;

cout<<"\n___________________\n -resultados:\n despues de "<<iter<<" iteraciones:"<<endl;


int max_t2 = 0;



for (int i = 0; i <= len; i++){
  cout<<" "<< i <<" salió "<<rep_iteraciones[i]<<" veces."<<endl;

  suma += rep_iteraciones[i];
  if (max_t2 < rep_iteraciones[i]) max_t2 = rep_iteraciones[i];
}

cout<<"\n salieron en total: 100* (" << iter <<") numeros :\n"<<suma<<endl;
cout<<"_______________________\n data_final decomp: F(mtrR_r)\n"<<endl;


int inicial = 0;

int *min = min_element(rep_iteraciones, rep_iteraciones+len);

if (*min > 999) inicial = 1000;
else if (*min > 699) inicial = 700;
else if (*min > 499) inicial = 500;
else if (*min > 199) inicial = 200;
else if (*min > 99) inicial = 100; 


for (int dY = 0; dY < len+1; dY++){
      resultados[dY] = new string[max_t2+5];
  }


for (int dn = 0; dn <= len; dn++){
    int reps;
    reps = rep_iteraciones[dn];


    for (int dy = max_t2+4; dy >= reps; dy--){
      resultados[dn][dy] = "_";
    }

    for(int dy = inicial; dy < reps; dy++ ){
      resultados[dn][dy] = "◙";
    }

  }

string re_plot;
cout<<"\n"<<endl;

     // !! // re_plot.append(to_string(repeticiones[i]));

for (int i = 0; i < len+1; i++){
    re_plot.append(to_string(i));
    if ( i < 10) re_plot.append("    ");
    else re_plot.append("   ");
}
re_plot.append("\n");

for (int j = max_t2+4; j >= inicial;j--){
  string value="";

      for (int i = 0; i < len+1 ; i++){

        if ( j == rep_iteraciones[i]){
          value = to_string(rep_iteraciones[i]);
          if (j > 99) re_plot.append(value + "  ");
          if (j <= 99 && j > 9) re_plot.append(value + "   ");
          if (j < 10) re_plot.append(value + "    "); 
        continue;
        }

        re_plot.append(resultados[i][j] + "    ");
      }
  
  re_plot.append("\n");
}
for (int i = 0; i < len; i++) re_plot.append("____");

re_plot.append("\n");

cout<<re_plot<<endl;
re_plot.clear();

usleep(duracion);
cout<<"\n_____________\n height plot:\n"<<endl;


for (int i = 0; i < len+1; i++){
    re_plot.append(to_string(i));
    if ( i < 10) re_plot.append("  ");
    else re_plot.append(" ");
}
re_plot.append("\n");

for (int j = max_t2+4; j >= inicial;j--){
  string value="";

      for (int i = 0; i < len+1 ; i++){

        if ( j == rep_iteraciones[i]){
          value = to_string(rep_iteraciones[i]);
          if (j > 99) re_plot.append(value + " ");
          if (j <= 99) re_plot.append(value + " ");
          if (j < 10) re_plot.append(value + "  ");
          continue;
        }

        re_plot.append("   ");
      }
  
  re_plot.append("\n");
}
for (int i = 0; i < len; i++) re_plot.append("____");

re_plot.append("\n");

cout<<re_plot<<endl;
cout<<"\n____________finalizado."<<endl;




for (int i=0; i < len+1; i++) delete[] resultados[i];
delete [] resultados;


delete[] repeticiones;
delete[] rep_iteraciones;
re_plot.clear();
return 0;
}


//plot data
//interface (x,y)
//veces, len _> see (display) func
//sep matrix disp
//max in re