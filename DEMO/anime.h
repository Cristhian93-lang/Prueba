#include "anime.h"

int main(){

	Shojo candy("Candy Candy", 1970, 1980, "Candy", "Terry", "Anthony");
	candy.imprime_personajes();
	
	candy.agrega_extra("Abuelo William");
	candy.agrega_extra("Paty");
	candy.agrega_extra("Annie");
	
	candy.imprime_personajes();
	
	Shonnen saint_seiya("Saint Seiya", 1980, 1994, "Seiya", "Gran Patriarca");
	saint_seiya.imprime_personajes();
	
	saint_seiya.agrega_b("Ikki");
	saint_seiya.agrega_b("Yoga");
	saint_seiya.agrega_b("Shun");
	saint_seiya.agrega_b("Shiru");
	
	
	saint_seiya.agrega_m("Shina");
	saint_seiya.agrega_m("Misti");
	saint_seiya.agrega_m("Cannon");
	saint_seiya.agrega_m("Afrodita");
	saint_seiya.agrega_m("Cancer");
	saint_seiya.agrega_m("Medusa");
	
	saint_seiya.imprime_personajes();
}