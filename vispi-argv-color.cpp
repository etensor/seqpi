#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include <fstream>
#include <sstream>

using namespace std;

string pi_value;

void getpi(){
  ifstream leerpi;
  leerpi.open("./seqpi/pitxt.txt", ifstream :: in);

    while(!leerpi.eof()) {
    string linea;
    getline(leerpi,linea);
    pi_value = linea;
  }
  leerpi.close();
}

string colors[11];

void feel_Datapi (int dim, int max,int* reps,int lim_izq){     // dec system: h = 9, count system interactions possible
  string cols[max+2][dim+1];

  static int dt = lim_izq;
  int val_y;
  string plot;
  
  if (dt == lim_izq){
    for (int i = lim_izq; i < dim+lim_izq; i++) reps[stoi(string(1,pi_value[i]))]++;
  }
  else reps[stoi(string(1,pi_value[dt+dim-1]))]++; // if not dec sys -> pi_v[x] > len(1) V p[x] -T->: p_sys(p[x])

  for(int x = dt; x < dim+dt; x++){
      val_y = stoi(string(1,pi_value[x]));
      string color = colors[val_y];                    

        for (int j = max; j >= val_y; j--){
          cols[j][x-dt] = " ";

        }
                       
        for (int k = 0; k < val_y; k++){
          //cols[k][x-dt] = "Ø";
          cols[k][x-dt] = color+"█"+colors[10];
        }

  }

  plot.append("\t\b______________\n\t visual PI\n");
  for (int j = max; j >= 0;j--){

        for (int i = 0; i < dim; i++){
          plot.append("  "+ cols[j][i]);
        }
    
    plot.append("\n");
  }
  plot.append(" ");
  for (int i = 0; i < dim; i++) plot.append("___");
  plot.append("\n");

  for (int i = dt; i < dim+dt; i++){
    plot.append("  ");
    plot += pi_value[i];      
  }

  cout<<plot<<endl;
  plot.clear();
  dt++;

}


int main(int argc, char** argv) {
  
srand(time(NULL));

cout<<" Visualizar distribución de cifras de pi.\n\n"<<endl;
cout<<"_________obteniendo pi. . ."<<endl;
getpi();

cout<<"\n Δ π = ";
for (int ix = 0; ix < 10; ix++){
  cout<<pi_value[ix]<<" ";
  ostringstream oss;
  oss << "\x1b[38;5;"<<ix+1<<"m";
  colors[ix] = oss.str();
  oss.clear();
}
cout<<". . ."<<endl;
colors[10] = "\x1b[0m";

if (argc < 4){
  cout<<"ARGV: from, to, width-term, time"<<endl;
  return 0;
}


int pirange_a, pirange_b, width;
pirange_a = atoi(argv[1]), pirange_b = atoi(argv[2]), width = atoi(argv[3]);

if (pirange_b < pirange_a){
  int x = pirange_b;
  pirange_b = pirange_a;
  pirange_a = x;
}

int ncifras = pirange_b - pirange_a;
//cout<<"\n\t ancho (cifras): ";cin>>width;cout<<endl;
if (width > ncifras) width = ncifras;             /// ARGV sett

int* cphrcount = new int[10] {0}; // 0-9 system count
//for (int i = 0; i < 10; i++) cphrcount[i] = 0;

int dts;
cout<<"\t x cifras : "<<ncifras<<endl;
cout<<"\n\tdesde cifra : "<<pirange_a<<endl;
cout<<"\n\thasta cifra : "<<pirange_b<<endl;

dts = atoi(argv[4]);
cout<<"\n dt (millisecs): "<<dts<<endl;
dts *= 1000;

cout<<"\v press enter";
cin.get();

for (int dt = 0; dt < ncifras-width+1; dt++){
  usleep(dts);
  if (dt < ncifras-width+1) system("clear");
  feel_Datapi(width, 10, cphrcount,pirange_a);
  
}

int suma = 0;

cout<<"_____________________________\n Resultados:\n"<<endl;
for (int i = 0; i < 10; i++){
  cout<<"\t#"<<i<<" salió "<<cphrcount[i]<<" veces\n";
  suma += cphrcount[i];
}
cout<<"\n\t | "<<suma<<" cifras analizadas."<<endl;

delete[] cphrcount;

return 0;
}