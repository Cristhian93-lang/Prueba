/*En las siguiente clases indica con comentarios:
1) a que clase pertenece cada mÃ©todo
2) donde hay sobreescritura 
3) donde hay sobrecaga 
4) donde hay herencia */

#ifndef ANIME_H
#define ANIME_H

#include <iostream>

using namespace std;
 
class Anime{
	private:
		string nombre;
		int inicio;
		int fin;
		bool terminada;
		string desc_epis[1000];
		int episodios;
		
	public:
		Anime(string nom, int ini);
		Anime(string nom, int ini, int fin);
		void imprime_personajes();
		void agrega_epi(string desc);
		int get_inicio(){ return inicio;}
		int get_fin(){ return fin;}
		int get_terminada(){ return fin;}
		string get_episodio(int ep);
		void set_fin(int fin);

};

Anime::Anime(string nom, int ini){
	nombre = nom;
	inicio = ini;
	fin = 0;
	terminada = false;
	episodios = 0;
}

Anime::Anime(string nom, int ini, int f){
	nombre = nom;
	inicio = ini;
	fin = f;
	terminada = true;
	episodios = 0;
}

void Anime::set_fin(int f){
	fin =  f;
	terminada = true;
}

void Anime::agrega_epi(string desc){
	desc_epis[episodios]= desc;
	episodios++;
}

string Anime::get_episodio(int epi){
	if (epi < episodios)
		return desc_epis[epi];
	return "No hay episodio";
}

class Shojo : public Anime{
	private:
		string principal;
		string pareja_t;
		string pareja_y;
		string extras[100];
		int num_extras;
	
	public:
		Shojo(string nom, int ini, string prin, string p_t, string p_y):Anime(nom,ini){
			principal = prin;
			pareja_t = p_t;
			pareja_y = p_y;
			num_extras = 0;
		}
		Shojo(string nom, int ini, int fin, string prin, string p_t, string p_y):Anime(nom,ini,fin){
			principal = prin;
			pareja_t = p_t;
			pareja_y = p_y;
			num_extras = 0;
		}
		void agrega_extra(string nombre);
		void imprime_personajes();
};

void Shojo::imprime_personajes(){
	cout << "principal: "<< principal << endl;
	cout << "tsundere: "<< pareja_t << endl;
	cout << "yandere: "<< pareja_y << endl;
	cout << "extras: " << endl;
	for (int i = 0; i < num_extras; i++)
		cout << extras[i] << " ";
}

void Shojo::agrega_extra(string nombre){
	extras[num_extras] = nombre;
	num_extras++;
}

class Shonnen : public Anime{
	private:
		string principal;
		string enemigo;
		string equipo_b[100];
		string equipo_m[100];
		int num_b;
		int num_m;
	
	public:
		Shonnen(string nom, int ini, string prin, string en):Anime(nom,ini){
			principal = prin;
			enemigo = en;
			num_b = 0;
			num_m = 0;
		}
		Shonnen(string nom, int ini, int fin, string prin, string en):Anime(nom,ini,fin){
			principal = prin;
			enemigo = en;
			num_b = 0;
			num_m = 0;
		}
		void agrega_b(string nombre);
		void agrega_m(string nombre);
		void imprime_personajes();
};

void Shonnen::imprime_personajes(){
	cout << "her@: "<< principal << endl;
	cout << "villan@: "<< enemigo << endl;
	
	cout << "heroes:" << endl ;
	for (int i = 0; i < num_b; i++)
		cout << equipo_b[i] << " ";
	
	cout << endl << "villanos:" << endl ;
	for (int i = 0; i < num_m; i++)
		cout << equipo_m[i] << " ";
}

void Shonnen::agrega_b(string nombre){
	equipo_b[num_b] = nombre;
	num_b++;
}

void Shonnen::agrega_m(string nombre){
	equipo_m[num_m] = nombre;
	num_m++;
}

#endif