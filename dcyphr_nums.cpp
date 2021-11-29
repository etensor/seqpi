#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include <fstream>
#include <sstream>

using namespace std;

string num_val;

void get_number(string num){
  ifstream numfile;
  
  if (num == "pi"){
    numfile.open("./seqpi/pitxt.txt", ifstream :: in);
  }else if (num == "phi"){
    numfile.open("./seqpi/phitxt.txt", ifstream :: in);
  }else if (num == "e"){
    numfile.open("./seqpi/etxt.txt", ifstream :: in);
  }else return;
  
    while(!numfile.eof()) {
    string linea;
    getline(numfile,linea);
    num_val += linea;
  }
  numfile.close();
}

string colors[11];

void access_number (int dim, int max,int* reps,int lim_izq){     // dec system: h = 9, count system interactions possible
  string cols[max+2][dim+1];

  static int dt = lim_izq;
  int val_y;
  string plot;
  
  if (dt == lim_izq){
    for (int i = lim_izq; i < dim+lim_izq; i++) reps[stoi(string(1,num_val[i]))]++;
  }
  else reps[stoi(string(1,num_val[dt+dim-1]))]++; // if not dec sys -> pi_v[x] > len(1) V p[x] -T->: p_sys(p[x])

  for(int x = dt; x < dim+dt; x++){
      val_y = stoi(string(1,num_val[x]));
      string color = colors[val_y];                    

        for (int j = max; j >= val_y; j--){
          cols[j][x-dt] = " ";

        }
                       
        for (int k = 0; k < val_y; k++){
          //cols[k][x-dt] = "Ø";
          cols[k][x-dt] = color+"█"+colors[10];
        }

  }

  plot.append("\t\b______________\n\t cypher analyzer\n");
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
    plot += num_val[i];      
  }

  cout<<plot<<endl;
  plot.clear();
  dt++;

}


int main(int argc, char** argv) {

  if (argc < 5){
    cout<<"ARGV: number, from, to, width-term, time\n\tpi,phi,e"<<endl;
    return 0;
  }
  
srand(time(NULL));

cout<<" Visualizar distribución de cifras de "<<argv[1]<<"\n\n"<<endl;
cout<<"_________obteniendo cifras. . ."<<endl;
get_number(string(argv[1]));

string num = string(argv[1]);
string color_tagsu;
string color_tagsd;

if (num == "pi")  num = "π"; 
if (num == "phi") num = "φ";

cout << "\n\t λ "<<num<<" = ";
for (int ix = 0; ix < 10; ix++){
  cout<<num_val[ix]<<" ";
  if (ix == 0) cout<<"\b. ";
  ostringstream oss;
  oss << "\x1b[38;5;"<<ix<<"m";
  colors[ix] = oss.str();
  color_tagsu += colors[ix] + "██\x1b[0m | ";
  color_tagsd += " "+to_string(ix) + " | ";
  oss.clear();
}
cout<<". . .\n"<<endl;
colors[10] = "\x1b[0m";

cout<<"   _________________________________________________\n";
cout<<"  | "<<color_tagsu<<"\n  | "<<color_tagsd<<"\n  ---------------------------------------------------\n"<<endl;


int pirange_a, pirange_b, width;
pirange_a = atoi(argv[2]), pirange_b = atoi(argv[3]), width = atoi(argv[4]);

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
cout<<"\t   x cifras : "<<ncifras<<endl;
cout<<"\n\tdesde cifra : "<<pirange_a<<endl;
cout<<"\n\thasta cifra : "<<pirange_b<<endl;

dts = atoi(argv[4]);
cout<<"\n     dt (millisecs) : "<<dts<<endl;
dts *= 1000;

cout<<"\v press enter";
cin.get();

for (int dt = 0; dt < ncifras-width+1; dt++){
  usleep(dts);
  if (dt < ncifras-width+1) system("clear");
  access_number(width, 10, cphrcount,pirange_a);
  
}

int suma = 0;

cout<<"_____________________________\n   Resultados   | "<<argv[1]<<" :\n"<<endl;
for (int i = 0; i < 10; i++){
  cout<<"\t#"<<i<<" salió "<<cphrcount[i]<<" veces\n";
  suma += cphrcount[i];
}
cout<<"\n\t | "<<suma<<" cifras analizadas."<<endl;

delete[] cphrcount;

return 0;
}