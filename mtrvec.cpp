#include <vector>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <iomanip>
#include <cmath>

using namespace std;

////
////    EXPECTS 3 values in argv, dims of Γ
////

typedef vector<vector<vector<vector<int>>>> hvec;
typedef vector<vector<vector<vector<double>>>> hvecd;
typedef vector<vector<vector<double>>> dynamic_cube;

int *dimens(int x, int y, int z)
{
    int *dims = new int[3]{x, y, z};
    return dims;
};

vector<vector<vector<vector<int>>>> create_v_mtr(int dim_x, int dim_y, int dim_z)
{
    int dims[3] = {dim_x, dim_y, dim_z};

    cout << "mapping 3d coord\n_________..~\n \t\tdims: " << dim_x << ", " << dim_y << ", " << dim_z << "\n\n"
         << endl;

    vector<vector<vector<vector<int>>>> v_mtr(
        dims[0], vector<vector<vector<int>>>(
                     dims[1], vector<vector<int>>(
                                  dims[2], vector<int>(3))));

    for (int i = 0; i < dims[0]; i++)
    {
        for (int j = 0; j < dims[1]; j++)
        {
            for (int k = 0; k < dims[2]; k++)
            {
                v_mtr[i][j][k][0] = i;
                v_mtr[i][j][k][1] = j;
                v_mtr[i][j][k][2] = k;
            }
        }
    }

    string spc = "\t\t";
    string bpc = "\b\b\b\b\b\b\b"; // /t =><= 4\b

    for (int i = 0; i < dims[0]; i++)
    {
        cout << spc;
        for (int j = 0; j < dims[1]; j++)
        {
            cout << "(";
            for (int k = 0; k < dims[2]; k++)
            {
                cout << "(";
                for (int s = 0; s < 3; s++)
                {
                    cout << v_mtr[i][j][k][s];
                    cout << " ";
                }
                // if (v_mtr[i][j][k] < 10) cout<<" ";
                cout << "\b)";
                if (k < dims[2] - 1)
                    cout << ",";
            }
            cout << ")\v";
            cout << bpc;
        }
        cout << "\n"
             << endl;
    }

    cout << "\n___________________________________________________\n";
    return v_mtr;
}

void def_draw(int dims[], vector<vector<vector<int>>> &v_mtr, string opt)
{
    if (opt == "sum")
    {
        for (int i = 0; i < dims[0]; i++)
        {
            for (int j = 0; j < dims[1]; j++)
            {
                for (int k = 0; k < dims[2]; k++)
                {
                    v_mtr[i][j][k] = i + j + k + 3;
                }
            }
        }
    }

    else if (opt == "sym")
    { // i j k
        for (int i = 0; i < dims[0]; i++)
        {
            for (int j = 0; j < dims[1]; j++)
            {
                for (int k = 0; k < dims[2]; k++)
                {
                    static int tr = -1;
                    if (tr == 1)
                        tr = -1;
                    else if (tr == -1)
                        tr = 0;
                    else if (tr == 0)
                        tr = 1;
                    v_mtr[i][j][k] = tr;
                }
            }
        }
    }

    string spc = "\t\t\t";
    string bpc = "\b\b\b\b\b\b\b\b\b\b\b\b"; // /t =><= 4\b

    for (int i = 0; i < dims[0]; i++)
    {
        cout << spc;
        for (int j = 0; j < dims[1]; j++)
        {
            for (int k = 0; k < dims[2]; k++)
            {
                cout << v_mtr[i][j][k] << " ";
                if (v_mtr[i][j][k] < 10)
                    cout << " ";
            }
            cout << "\v";
            cout << bpc;
        }
        cout << "\n"
             << endl;
    }
}

void energize(int dims[], dynamic_cube &v_mtr, double &dx, double &dy, double &dz)
{
    string spc = "\t\t\t";
    string bpc = "\b\b\b\b\b\b\b\b\b\b\b\b"; // /t =><= 4\b
    static double x = 0.0, y = 0.0, z = 0.0;

    for (int i = 0; i < dims[0]; i++)
    {
        for (int j = 0; j < dims[1]; j++)
        {
            for (int k = 0; k < dims[2]; k++)
            {
                v_mtr[i][j][k] = (x + y + z) / 10000;
                z += dz;
                dz += dz / 1000;
            }
            y += dy;
            dy += dy / 1000;
        }
        x += dx;
        dx += dx / 1000;
    }

    for (int i = 0; i < dims[0]; i++)
    {
        cout << spc;
        for (int j = 0; j < dims[1]; j++)
        {
            for (int k = 0; k < dims[2]; k++)
            {
                cout << setprecision(3) << v_mtr[i][j][k] << " | ";
            }
            cout << "\b\b\v";
            cout << bpc;
        }
        cout << "\n"
             << endl;
    }
}

vector<vector<vector<int>>> vector_matrix(int dimx, int dimy, int dimz)
{
    int dims[3] = {dimx, dimy, dimz};

    vector<vector<vector<int>>> v_mtr(
        dims[0], vector<vector<int>>(
                     dims[1], vector<int>(
                                  dims[2]))); // 3x10x5
    return v_mtr;
}

dynamic_cube vmatrixd(int dimx, int dimy, int dimz)
{
    int dims[3] = {dimx, dimy, dimz};

    dynamic_cube v_mtr(
        dims[0], vector<vector<double>>(
                     dims[1], vector<double>(
                                  dims[2]))); // 3x10x5
    return v_mtr;
}

int main(int argc, char **argv)
{ /// expects 3 values in argv

    // string opt : sum (i+j+k) , sym (i 1, j -1, k 0) |
    cout << " \n\n\t run -> falla. Espera parametros. ./main dim x dim y dim z";
    cout << "\n\nN x M x K mtr vis\n___________________\n"
         << endl;

    int i = atoi(argv[1]), j = atoi(argv[2]), k = atoi(argv[3]);

    int dims[3] = {i, j, k};

    /*
      vector<vector<vector<int>>> vect_mtr = vector_matrix(dims[0],dims[1],dims[2]);

      def_draw(dims,vect_mtr,"sum");
      cout<<"\n____________________"<<endl;
      def_draw(dims,vect_mtr,"sym");

          //  vector<vector<vector<vector<vector<int>>>>> pauli(5);

          // for (int i=0; i < 5; i++) pauli[i] = create_v_mtr(i+2,i+2,i+2);


    cout<<"\t\t\t z -> right, y -> front, x-> down"<<endl;


    auto dev_mtr = [](vector<vector<vector<vector<int>>>> vmtr,int i, int j)
      -> vector<vector<int>> {
      return vmtr[i][j];
    };

     //hvec vpauli_s = create_v_mtr(3,3,3);

    vector<vector<int>> sub_mtr = dev_mtr(vpauli_s,1,2);

    for (int i = 0; i < sub_mtr.size();i++){
      for(int j = 0; j < sub_mtr[i].size(); j++){
        cout<<sub_mtr[i][j]<<" ";
      }
      cout<<"\n";
    }
    cout<<endl<<endl;

    sub_mtr = dev_mtr(vpauli_s,2,2);

    for (int i = 0; i < sub_mtr.size();i++){
      for(int j = 0; j < sub_mtr[i].size(); j++){
        cout<<sub_mtr[i][j]<<" ";
      }
      cout<<"\n";
    }
    cout<<"\n\n"<<endl;
    */

    dynamic_cube qubic_s = vmatrixd(dims[0], dims[1], dims[2]);
    // dynamic_cube* qubic_t = new dynamic_cube(qubic_s.begin(),qubic_s.end());
    // qubic_s.resize(0);

    int iter, duracion;
    double dx, dy, dz;
    cout << " n iteraciones: ";
    cin >> iter;
    cout << "\n dt (millisecs): ";
    cin >> duracion;
    cout << "\n set dx, dy, dz : ";
    cin >> dx >> dy >> dz;
    duracion *= 1000;

    for (int dt = 1; dt < iter; dt++)
    {
        cout << "\n\n\n";
        energize(dims, qubic_s, dx, dy, dz);
        usleep(duracion);
        system("clear");
        cout << endl;
    }

    // delete[] qubic_t;
    return 0;
}