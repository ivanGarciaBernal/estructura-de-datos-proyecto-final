#include <iostream>
#include <string>
#include <fstream>

#define endl "\n\n"
using namespace std;


//IMPLEMENTAR contador de visitar
void contador_visitas(){
	int visitas;
	ifstream visitas_in("visitas.txt");
	ofstream visitas_out("visitas.txt");
	
	visitas_in >> visitas;
	cout << visitas + 1 << endl;
	visitas_out << visitas + 1;
	visitas_in.close();
	visitas_out.close();
}

void portada(){
	cout << "Universidad Autonoma del Estado de Hidalgo" << endl
	<< "Lugares turisticos en el Estado de Hidalgo" << endl
	<< "Equipo Cyan:" << endl
	<< "- Romero Juarez Jose Antonio" << endl
	<< "- Eliseo Juarez de Jesus Moises" << endl
	<< "- Garcia Bernal Axel Ivan" << endl
	<< "Numero de visitas: " << endl;
}

void imprime(string texto, int width = 80){
	int i;
	for(i = 0; i < texto.size() ; i++){
		cout << texto[i] ;
		if(i % 80 == 0 && i != 0){
			cout << "-\n" ;
		}
	}
	cout << endl;
}

void acerca(){
	string texto = "Acerca del Estado de Hidalgo:\n" 
	"El estado de Hidalgo cuenta con una gran variedad de lugares turisticos que podrian interesarte. Algunos de los lugares mas populares son Pachuca de Soto, la capital del estado, conocida por su reloj monumental, exquisitos pastes, hermosos paisajes boscosos y mas; el Dinoparque en el Museo del Rehilete, un centro de atracciones que cuenta con mas de 40 figuras de dinosaurios en tamano real; y las Grutas de Tolantongo, un conjunto de cuevas situadas en el municipio hidalguense de Cardonal, a 97 km al noroeste de Pachuca de Soto. Otros lugares turisticos incluyen el Parque Nacional El Chico, el Bosque de las Truchas, el Zona Arqueologica de Tula, el Pueblo Magico de Huasca de Ocampo, y mas";
	imprime(texto);
}


int opciones(){
	int respuesta;
	cout << "Las siguientes acciones estan disponibles" << endl
	<< "1.- Realizar busqueda" << endl
	<< "2.- Ordenar conjunto de datos" << endl
	<< "3.- Agregar un elemento a la base" << endl
	<< "4.- Eliminar un elemento de la base de datos" << endl
	<< "Inserte una opcion: " ;
	cin >> respuesta;
	return respuesta;
}

int main(){
	portada();
	acerca();
	contador_visitas();
	return 0;
}
