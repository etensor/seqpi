// STL algorithm, numeric: Vector y Lista.
// etensor : replit/@kxp/listasalgorithm-1
#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ctime>
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace std::chrono;

typedef struct
{
    const int min, max, len, opt;
} parametros; // estructura básica utilizar luego. (const var)

auto def_parametros()
{
    int minp, maxp, lenp, optp;
    do
    {
        cout << "\033[32m\n Usar:\n[1] Vector\n[2] Lista\n[3] Salir.\v Opción: \033[0m";
        cin >> optp;
    } while (optp != 1 && optp != 2 && optp != 3);
    cout << "\n Número de valores: ";
    cin >> lenp;
    do
    {
        cout << "\n Mínimo: ";
        cin >> minp;
        cout << "\n Máximo: ";
        cin >> maxp;
        if (maxp < minp)
            cout << "\nError: max < min, reingrese:\n";
    } while (maxp < minp);
    maxp++;

    parametros s = {.min = minp, .max = maxp, .len = lenp, .opt = optp}; // declaración de estructura definida en linea.14

    return s;
}

void print(int val) { cout << " " << val; }; // para for_each -> cada valor del contenedor entra y se imprime.

template <typename V> // template: reducción de lineas, misma tarea.
void llenar_sacarPromedio(V &nums, parametros &lims, double &promedio)
{ // Vector o Lista
    double suma = 0;
    promedio = 0;

    auto aleatorio = [&lims]()
    { return lims.min + rand() % (lims.max - lims.min); }; // lambda porque generate no permite parametros.

    // llenado
    nums.resize(lims.len);
    generate(nums.begin(), nums.end(), aleatorio);
    // promedio                                     //promedio es el único valor que no difiere en el método para calcularlo.
    cout << "\n Antes de sortear:" << endl; // lo modifica internamente, reduce lineas.
    for_each(nums.begin(), nums.end(), print);
    suma = accumulate(nums.begin(), nums.end(), 0.0); // sumamos los valores.
    promedio = suma / (lims.len);
}

double mediana_v(vector<int> &nums)
{                   // el acceso a los valores del vector es sencillo
    double mediana; // toma en cuenta si el # de valores es par o impar.

    sort(nums.begin(), nums.end());
    mediana = nums[nums.size() / 2];
    if (nums.size() % 2 == 0)
        mediana = (mediana + nums[(nums.size() / 2) - 1]) / 2.0;

    return mediana;
}

double mediana_li(list<int> &nums)
{ // Para list el proceso es más complejo, pero muy similar.
    double mediana;

    nums.sort();
    list<int>::iterator lt = nums.begin();
    advance(lt, nums.size() / 2); // ubicamos el iterador en la mitad.

    mediana = *lt;
    if (nums.size() % 2 == 0)
    {
        lt = prev(lt); // lo devolvemos uno para sacar promedio con el otro.
        mediana = (mediana + *lt) / 2.0;
    }
    return mediana;
}

int moda_v(vector<int> nums)
{ // Esta función podría hacerse en template, pero difieren al final.
    int moda;
    vector<int>::iterator uq;
    vector<int> copia_unica(nums.size());

    uq = unique_copy(nums.begin(), nums.end(), copia_unica.begin()); // Nos interesa solo los valores que salieron(no sus copias)
    copia_unica.resize(distance(copia_unica.begin(), uq));           // Ahora conocemos todos los valores que salieron.

    vector<int> repeticiones(copia_unica.size());

    auto contar = [&repeticiones, nums, copia_unica](int i) { // lambda para usar en el for_each que recibe 1 parametro.
        int conteo = 0;                                       // si no era lambda, el vector quedaba por fuera.
        static int idx = 0;                                   // static para que su estado sea independiente del exterior.

        conteo = count(nums.begin(), nums.end(), i);
        repeticiones[idx] = conteo;
        idx++;
        if (idx >= repeticiones.size())
            idx = 0;
    };

    for_each(copia_unica.begin(), copia_unica.end(), contar);
    cout << "\n\n Después de sortear: " << endl; // sortear es NECESARIO para los pasos anteriores.
    for_each(nums.begin(), nums.end(), print);

    int max, j;
    max = *max_element(repeticiones.begin(), repeticiones.end());   // repeticiones y copia_unica tienen el mismo orden.
    auto aux = find(repeticiones.begin(), repeticiones.end(), max); // ubicamos al maximo para extraer idx e usar en copia.
    j = distance(repeticiones.begin(), aux);
    moda = copia_unica[j];

    return moda;
}

int moda_li(list<int> nums)
{ // funciona exactamente igual...
    int moda;
    list<int>::iterator uq;
    list<int> copia_unica(nums.size());

    uq = unique_copy(nums.begin(), nums.end(), copia_unica.begin());
    copia_unica.resize(distance(copia_unica.begin(), uq));

    list<int> repeticiones(copia_unica.size());

    auto contar = [&repeticiones, nums, copia_unica](int i)
    {
        int conteo = 0;
        static list<int>::iterator idx = repeticiones.begin();

        conteo = count(nums.begin(), nums.end(), i);
        *idx = conteo;
        idx++;
        if (*idx >= repeticiones.size())
            *idx = 0;
    };

    for_each(copia_unica.begin(), copia_unica.end(), contar);
    cout << "\n Despues de sortear: " << endl;
    for_each(nums.begin(), nums.end(), print);

    int mode;
    mode = *max_element(repeticiones.begin(), repeticiones.end());
    auto aux = find(repeticiones.begin(), repeticiones.end(), mode);
    int j = distance(repeticiones.begin(), aux);
    list<int>::iterator fi = copia_unica.begin();
    advance(fi, j);
    moda = *fi;

    return moda;
}

double varianzaDesvest_v(vector<int> nums, double &promedio, double &desvest)
{
    double varianza;
    vector<double> copia(nums.begin(), nums.end()); // sacamos una copia para transformarla con el promedio
    vector<double> transf_copia;                    // transform no recibe lambda, se define internamente.

    transform(copia.begin(), copia.end(), back_inserter(transf_copia), [promedio](double it) -> double
              { return pow(it - promedio, 2); });
    varianza = accumulate(transf_copia.begin(), transf_copia.end(), 0.0);
    varianza /= nums.size();
    desvest = sqrt(varianza); // de paso sacamos la desviación estándar, para no crear oootra función.

    return varianza;
}

double varianzaDesvest_li(list<int> nums, double &promedio, double &desvest)
{ // igual pero con lista.
    double varianza;
    list<double> copia(nums.begin(), nums.end());
    list<double> transf_copia;

    transform(copia.begin(), copia.end(), back_inserter(transf_copia), [promedio](double it) -> double
              { return pow(it - promedio, 2); });
    varianza = accumulate(transf_copia.begin(), transf_copia.end(), 0.0);
    varianza /= nums.size();
    desvest = sqrt(varianza);

    return varianza;
}

void imprimir_resultados(int moda, double promedio, double varianza, double desvest, double mediana)
{
    cout << "\n\n Valores estadísticos extraídos: \n________________________________" << endl;
    cout << "Promedio: " << promedio << "\t|\tMed: " << mediana << "\t|\tMod: " << moda << endl;
    cout << "Varianza σ²: " << varianza << "  |  Desvest σ: " << desvest << endl
         << endl;
}

int main()
{
    srand(time(0));
    vector<int> aleatoriosV;
    list<int> aleatoriosL;
    int moda;
    double promedio, varianza, desvest, mediana;
    bool continuar = true;

    do
    {
        auto lims = def_parametros();
        switch (lims.opt)
        {
        case 1:
        {
            auto start = high_resolution_clock::now();
            llenar_sacarPromedio(aleatoriosV, lims, promedio);
            mediana = mediana_v(aleatoriosV);
            moda = moda_v(aleatoriosV);
            varianza = varianzaDesvest_v(aleatoriosV, promedio, desvest);
            auto stop = high_resolution_clock::now();
            auto duracion = duration_cast<milliseconds>(stop - start);
            imprimir_resultados(moda, promedio, varianza, desvest, mediana);
            cout << "\n Tiempo por VECTOR: " << duracion.count() << " milisegundos." << endl;
            aleatoriosV.clear();
            break;
        }

        case 2:
        {
            auto start = high_resolution_clock::now();
            llenar_sacarPromedio(aleatoriosL, lims, promedio);
            mediana = mediana_li(aleatoriosL);
            moda = moda_li(aleatoriosL);
            varianza = varianzaDesvest_li(aleatoriosL, promedio, desvest);
            auto stop = high_resolution_clock::now();
            auto duracion = duration_cast<milliseconds>(stop - start);
            imprimir_resultados(moda, promedio, varianza, desvest, mediana);
            cout << "\n Tiempo por LISTA: " << duracion.count() << " milisegundos." << endl;
            aleatoriosL.clear();
            break;
        }
        case 3:
            continuar = false;
            break;
        }
        cin.get();
        cin.get();

        system("clear");
    } while (continuar);

    return 0;
}