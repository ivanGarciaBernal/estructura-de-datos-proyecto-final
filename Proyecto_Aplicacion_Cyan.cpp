#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <clocale>

//#define endl "\n\n"
using namespace std;


//IMPLEMENTAR contador de visitar
void contador_visitas() {
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

void portada() {
	cout << "Universidad Autonoma del Estado de Hidalgo" << endl
	     << "Lugares turisticos en el Estado de Hidalgo" << endl
	     << "Equipo Cyan:" << endl
	     << "- Romero Juarez Jose Antonio" << endl
	     << "- Eliseo Juarez de Jesus Moises" << endl
	     << "- Garcia Bernal Axel Ivan" << endl;
}

void imprime(string texto, int width = 80) {
	int i;
	for(i = 0; i < texto.size() ; i++) {
		cout << texto[i] ;
		if(i % 80 == 0 && i != 0) {
			cout << "-\n" ;
		}
	}
	cout << endl;
}

void acerca() {
	string texto = "Acerca del Estado de Hidalgo:\n"
	               "El estado de Hidalgo cuenta con una gran variedad de lugares turisticos que podrian interesarte. Algunos de los lugares mas populares son Pachuca de Soto, la capital del estado, conocida por su reloj monumental, exquisitos pastes, hermosos paisajes boscosos y mas; el Dinoparque en el Museo del Rehilete, un centro de atracciones que cuenta con mas de 40 figuras de dinosaurios en tamano real; y las Grutas de Tolantongo, un conjunto de cuevas situadas en el municipio hidalguense de Cardonal, a 97 km al noroeste de Pachuca de Soto. Otros lugares turisticos incluyen el Parque Nacional El Chico, el Bosque de las Truchas, el Zona Arqueologica de Tula, el Pueblo Magico de Huasca de Ocampo, y mas";
	imprime(texto);
}


int opciones() {
	int respuesta;
	cout << "Las siguientes acciones estan disponibles" << endl
	     << "0.- Muestra la base de datos" << endl
	     << "1.- Realizar busqueda en la base" << endl
	     << "2.- Ordenar conjunto de datos" << endl
	     << "3.- Agregar un elemento a la base" << endl
	     << "4.- Eliminar un elemento de la base de datos" << endl
	     << "Inserte una opcion: " ;
	cin >> respuesta;
	return respuesta;
}

void muestra_base() {
	string linea;
	ifstream datos("datos.txt");
	while(getline(datos,linea)) {
		cout << linea << endl;
	}
}

void carga_datos(vector<int> *id,
                 vector<string> *lugar,
                 vector<string> *estado,
                 vector<string> *atracciones) {
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

void muestra_elemento(int num) {
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

void busca() {
	int i;
	cout << "Ingrese el ID del elemento que desea observar: " << endl;
	cin >> i;
	muestra_elemento(i);
}

vector<int> ids() {
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

bool en(int elemento,vector<int> vec) {
	for(auto i: vec) {
		if(elemento == i) {
			return true;
		}
	}
	return false;
}


void agrega() {
	int id;
	vector<int> lista;
	stringstream cadena;
	string lugar, estado,atracciones,str;
	ofstream datos;
	datos.open("datos.txt",std::ios_base::app);
	cout << "Inserte id:";
	cin >> id;

	lista = ids();
	if(en(id,lista)) {
		cout << "Este ID ya ha sido usado" << endl;
		return;
	}

	cout << "Inserte lugar:";
	cin >> lugar;
	cout << "Inserte estado:";
	cin >> estado;
	cout << "Inserte atracciones";
	cin >> atracciones;

	cadena << "\n"
	       << id
	       << "\t"
	       << lugar
	       << "\t"
	       << estado
	       << "\t"
	       << atracciones;

	str = cadena.str();
	datos << str;
	datos.close();

}

int main() {
	int opcion;
	vector<int> id;
	vector<string> lugar;
	vector<string> estado;
	vector<string> atracciones;

	setlocale(LC_ALL,"");
	portada();
	acerca();
	contador_visitas();

	opcion = opciones();

	switch(opcion) {
		case 0:
			muestra_base();
			break;
		case 1:
			busca();
			break;
		case 3:
			agrega();
			break;
	}


	return 0;
}
