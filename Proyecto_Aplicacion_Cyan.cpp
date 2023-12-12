#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <clocale>
#include <iomanip>
#include <windows.h>

using namespace std;


bool existe(string archivo)
{
    ifstream arch(archivo.c_str());
    return arch.good();
}

void crea(string archivo){
	ofstream arch(archivo.c_str());
	arch.close();
}

void escribe_datos()
{
	string texto = 
        "10   Real del Monte        Mineral del Monte   Pintoresco pueblo minero con arquitectura inglesa.\n"
        "7    Prismas Basalticos    Huasca de Ocampo    Formaciones basalticas unicas y cascadas impresionantes.\n"
        "4    Tula                 Tula de Allende     Zona arqueologica con las famosas esculturas atlantes.\n"
        "6    Grutas de Tolantongo  Cardonal            Grutas termales con aguas turquesas y paisajes increibles.\n"
        "2    Pachuca              Pachuca de Soto     Capital del estado con arquitectura colonial y moderna.\n"
        "9    Huasca de Ocampo     Huasca de Ocampo    Pueblo magico con antiguas haciendas y bosques encantadores.\n"
        "3    Teotihuacan          Tepeji del Rio      Sitio arqueologico con piramides prehispanicas imponentes.\n"
        "5    Santa Maria Regla    Huasca de Ocampo    Hacienda con arquitectura unica y hermosos jardines.\n"
        "1    El Chico              Mineral del Chico   Pueblo con encanto, rodeado de bosques y cascadas.\n"
        "8    Zimapan               Zimapan             Presa de la Esperanza, ideal para deportes acuaticos y pesca.";

ofstream datos("datos.txt");
datos << texto << endl;
datos.close();
}

void escribe_visitas(){
	if(!existe("visitas.txt")){
		crea("visitas.txt");
		ofstream visitas("visitas.txt");
		visitas << "0" << endl;
		visitas.close();
	}
}

void crea_datos()
{
	if(!existe("datos.txt")){
		crea("datos.txt");
		escribe_datos();
	}
}


void regresa()
{
    system("pause");
    system("cls");
}

void contador_visitas()
{
    int visitas;
    ifstream visitas_in("visitas.txt");

    visitas_in >> visitas;
    visitas_in.close();

    ofstream visitas_out("visitas.txt");
    visitas++;
    visitas_out << visitas;
    cout << "Numero de visitas: " << visitas << endl;
    visitas_out.close();
}

int num_visitas(){
	int n;
	ifstream visitas("visitas.txt");
	visitas >> n;
	return n;
}

void portada()
{
    cout << "Universidad Autonoma del Estado de Hidalgo" << endl
         << endl
         << "Lugares turisticos en el Estado de Hidalgo" << endl
         << endl
         << "Equipo Cyan:" << endl
         << endl
         << "- Romero Juarez Jose Antonio" << endl
         << "- Eliseo Juarez de Jesus Moises" << endl
         << "- Garcia Bernal Axel Ivan" << endl;
}

void imprime(string texto, int width = 80)
{
    int i;
    for(i = 0; i < texto.size() ; i++) {
        cout << texto[i] ;
        if(i % 80 == 0 && i != 0) {
            cout << "-\n" ;
        }
    }
    cout << endl;
}

void acerca()
{
    string texto = "Acerca del Estado de Hidalgo:\n"
                   "El estado de Hidalgo cuenta con una gran variedad de lugares turisticos que podrian interesarte. Algunos de los lugares mas populares son Pachuca de Soto, la capital del estado, conocida por su reloj monumental, exquisitos pastes, hermosos paisajes boscosos y mas; el Dinoparque en el Museo del Rehilete, un centro de atracciones que cuenta con mas de 40 figuras de dinosaurios en tamano real; y las Grutas de Tolantongo, un conjunto de cuevas situadas en el municipio hidalguense de Cardonal, a 97 km al noroeste de Pachuca de Soto. Otros lugares turisticos incluyen el Parque Nacional El Chico, el Bosque de las Truchas, el Zona Arqueologica de Tula, el Pueblo Magico de Huasca de Ocampo, y mas";
    imprime(texto);
}


int opciones()
{
    int respuesta;
    int n = num_visitas();
    cout << "Numero de visitas: " << n << endl
		<< "Las siguientes acciones estan disponibles" << endl
         << "0.- Muestra la base de datos" << endl
         << "1.- Realizar busqueda en la base" << endl
         << "2.- Ordenar conjunto de datos" << endl
         << "3.- Agregar un elemento a la base" << endl
         << "4.- Eliminar un elemento de la base de datos" << endl
         << "5.- Muestra de nuevo la portada" << endl
         << "6.- Muestra de nuevo informacion relevante acerca del Estado de Hidalgo" << endl
         << "7.- SALIR" << endl
         << "Inserte una opcion: " ;
    cin >> respuesta;
    return respuesta;
}

void muestra_base()
{
    string linea;
    cout <<
         "ID\t" <<
         "Nombre" <<
         "Municipio" <<
         "Descripcion o atracciones" <<
         endl;
    ifstream datos("datos.txt");
    while(getline(datos,linea)) {
        cout << linea << endl;
    }
    datos.close();
}

void carga_datos(vector<int> *id,
                 vector<string> *lugar,
                 vector<string> *estado,
                 vector<string> *atracciones)
{
    // cargemos la base de datos
    ifstream datos("datos.txt");
    string linea;

    while(getline(datos,linea)) {
        string v1,v2,v3,v4;
        int pos;

        pos = linea.find("\t"); //encuentra posicion
        v1 = linea.substr(0,pos);
        pos = v1.find("\t");
        v2 = v1.substr(0,pos);
        pos = v2.find("\t");
        v3 = v2.substr(0,pos);
        pos = v3.find("\t");
        v4 = v3.substr(0,pos);


        id -> push_back(stoi(v1));
        lugar -> push_back(v2);
        estado -> push_back(v3);
        atracciones -> push_back(v4);
    }
    datos.close();
}

void muestra_elemento(int num)
{
    int pos;
    int id;
    string str,linea;
    ifstream datos("datos.txt");
    while(getline(datos,linea)) {
        pos = linea.find("\t");
        str = linea.substr(0,pos);
        if(stoi(str) == num) {
            cout << linea << endl;
        }
    }
    datos.close();
}

void busca()
{
    int i;
    cout << "Ingrese el ID del elemento que desea observar: " << endl;
    cin >> i;
    muestra_elemento(i);
}

vector<int> ids()
{
    int pos,id;
    string linea,str;
    ifstream datos("datos.txt");
    vector<int> ids;
    while(getline(datos,linea)) {
        pos = linea.find("\t");
        str = linea.substr(0,pos);
        id = stoi(str);
        ids.push_back(id);
    }
    datos.close();

    return ids;
}

bool en(int elemento,vector<int> vec)
{
    for(auto i: vec) {
        if(elemento == i) {
            return true;
        }
    }
    return false;
}


void agrega()
{
    int id;
    vector<int> lista;
    stringstream cadena;
    string lugar, estado,atracciones,str;
    ofstream datos;
    datos.open("datos.txt",std::ios_base::app);
    cout << "Inserte id: ";
    cin >> id;

    lista = ids();
    if(en(id,lista)) {
        cout << "Este ID ya ha sido usado" << endl;
        return;
    }

    cout << "Inserte lugar: ";
    cin >> lugar;
    cout << "Inserte municipio: ";
    cin >> estado;
    cout << "Inserte atracciones: ";
    cin >> atracciones;

    cadena << id
           << "\t"
           << lugar
           << "\t"
           << estado
           << "\t"
           << atracciones;

    str = cadena.str();
    datos << str << endl;
    datos.close();
    
    muestra_base();
}

int extrae_id(string linea)
{
    int pos;
    string str;
    pos = linea.find("\t");
    str = linea.substr(0,pos);
    return stoi(str);
}

void elimina()
{
    int respuesta,j;
    string linea;
    ifstream datos("datos.txt");
    ofstream nuevo("nuevo.txt");

    cout << "Las entradas en la base de datos"
         " son las siguientes" << endl;
    muestra_base();
    cout << "Inserte el ID que desea quitar: " << endl;
    cin >> respuesta;
    if(!en(respuesta,ids())) {
        cout << "el ID especificado no ha sido registrado" << endl;
    }

    while(getline(datos,linea)) {
        j = extrae_id(linea);
        if(j != respuesta) {
            nuevo << linea << "\n";
        }
    }
    datos.close();
    nuevo.close();

    remove("datos.txt");
    rename("nuevo.txt","datos.txt");
    remove("nuevo.txt");

    cout << "ahora puede ver la base actualizada con su baja" << endl;
    muestra_base();
}

void copia(string archivo, string copia)
{
    ifstream arch(archivo);
    ofstream cop(copia);
    string linea;
    while(getline(arch,linea)) {
        cop << linea << "\n";
    }
    arch.close();
    cop.close();
}

int encuentra(vector<int> vec, int elemento)
{
    int i;
    for(i=0; i < vec.size(); i++) {
        if(vec[i] == elemento) {
            return i;
        }
    }
    return -1;
}

bool es_ordenada_asc(vector<int> id)
{
    int i;
    vector<int> v = id;
    for(i=0; i<v.size(); i++) {
        if(v[i]>v[i+1]) {
            return false;
        }
    }
    return true;
}

vector<int> extrae_ids(vector<string> lineas)
{
    vector<int> id;
    int pos;
    string linea;
    for(auto k: lineas) {
        pos = k.find("\t");
        linea = k.substr(0,pos);
        id.push_back(stoi(linea));
    }
    return id;
}

void limpia_lineas_vacias(string archivo){
	ifstream arch(archivo.c_str());
	ofstream out("temp.txt");
	string line;
	
	while(getline(arch,line)){
		if(!line.empty()){
			out << line << endl;
		}
	}
	arch.close();
	out.close();
	
	remove(archivo.c_str());
	rename("temp.txt",archivo.c_str());
}

void ascendente()
{
    int k;
    int i = 0,j = 0;
    vector<int> id;
    vector<string> lineas;
    string linea;

    ifstream datos("datos.txt");

    while(getline(datos,linea)) {
        lineas.push_back(linea);
    }

    datos.close();

    id = extrae_ids(lineas);

    for(i=1; i<=id.size(); i++) {
        for(j=0; j<= id.size() - i; j++) {
            if(id[j] > id[j+1]) {
                swap(id[j],id[j+1]);
                swap(lineas[j],lineas[j+1]);
            }
        }
    }

    ofstream dat("datos.txt");
    for(i=0; i<lineas.size(); i++) {
        dat << lineas[i] << endl;
    }
    dat.close();
    
    limpia_lineas_vacias("datos.txt");
}

void descendente()
{
    int i;
    ascendente();
    vector<string> lineas;
    string linea;
    ifstream datos("datos.txt");
    while(getline(datos,linea)) {
        lineas.push_back(linea);
    }
    datos.close();
    reverse(lineas.begin(),lineas.end());
    ofstream dat("datos.txt");

    for(i=0; i < lineas.size(); i++) {
        dat << lineas[i] << endl;
    }
    dat.close();
    
    limpia_lineas_vacias("datos.txt");
}

void ordena()
{
    int respuesta;
    muestra_base();
    cout << endl;
respuesta:
    cout << "Tiene dos opciones: " << endl
         << "1.- Orden ascendente" << endl
         << "2.- Orden descendente" << endl
         << "3.- Regresar al menú principal" << endl
         << "Inserte respuesta: ";
    cin >> respuesta;

    switch(respuesta) {
        case 1:
            ascendente();
            muestra_base();
            regresa();
            break;
        case 2:
            descendente();
            muestra_base();
            regresa();
            break;
        case 3:
            system("cls");
            return;
        default:
            break;
    }
    goto respuesta;
}

void restaura()
{
    remove("datos.txt");
    copia("backup.txt","datos.txt");
}


int main()
{
	escribe_visitas();
	crea_datos();
	
    int opcion;
    vector<int> id;
    vector<string> lugar;
    vector<string> estado;
    vector<string> atracciones;

    setlocale(LC_ALL,"");

    portada();
    cout << endl;
    acerca();
    cout << endl;
    contador_visitas();
    cout << endl;

opciones:
    opcion = opciones();

    switch(opcion) {
        case 0:
            system("cls");
            muestra_base();
            regresa();
            break;
        case 1:
            system("cls");
            busca();
            regresa();
            break;
        case 2:
            system("cls");
            ordena();
            regresa();
            break;
        case 3:
            system("cls");
            agrega();
            regresa();
            break;
        case 4:
            system("cls");
            elimina();
            regresa();
            break;
        case 5:
            system("cls");
            portada();
            regresa();
            break;
        case 6:
            system("cls");
            acerca();
            regresa();
            break;
        case 7:
            return 0;
            break;
        default:
            break;
    }
    goto opciones;
    return 0;
}
