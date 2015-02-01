#pragma once

#include "stdafx.h",

namespace MedicalMP
{
	const std::string _peopleNamesInit[] = {
		"Remus", "Nicusor",
		"Horia", "Octavian",
		"Ilie", "Cristi",
		"Ciprian", "Matei",
		"Aurel", "Cristi",
		"Cezar", "David",
		"Dorin", "Stan",
		"Iuliu", "Iosif",
		"Mitica", "Costache",
		"Costin", "Costica",

		"Pompiliu", "Petre",
		"Remus", "Ion",
		"Andrei", "Iuliu",
		"Serafim", "Eduard",
		"Cristian", "Emilian",
		"Pompiliu", "Constantin",
		"Tiberiu", "Timotei",
		"Paul", "Costache",
		"Octavian", "Adrian",
		"Atanase", "Dan",

		"Augustin", "Cimbru",
		"Remus", "Petala",
		"Stefan", "Petrescu",
		"Marcela", "Horia",
		"Anton", "Balauta",
		"Neli", "Spataru",

		"Tudor", "Petru",
		"Simon", "Cezar",
		"Daniel", "Carol",
		"Dinu", "Veaceslav",
		"Dorin", "Petru",
		"Iancu", "Andrei",
		"Cristi", "Cornel",
		"Octavian", "Mitica",
		"Gavril", "Corneliu",
		"Cristian", "Carol",

		"Maria", "Silviu",
		"Gabi", "Augustin",
		"Dragomir", "Denis",
		"Octavian", "Vasile",
		"Iulian", "Serafim",
		"Simon", "Tiberiu",
		"Mihaita", "Eduard",
		"Ionut", "Dorin",
		"Haralamb", "Corneliu",
		"Alin", "Costel",

		"Nicu", "Horia",
		"Cristian", "Stefan",
		"Petrica", "Victor",
		"Paul", "Lucian",
		"Marian", "Eugen",
		"Andrei", "Traian",
		"Virgil", "Costin",
		"Emanuel", "Danut",
		"Dragomir", "Timotei",
		"Cornel", "Felix",

		"Iuliu", "Beniamin",
		"Vlad", "Remus",
		"Dionisie", "Flaviu",
		"Emanuel", "Vasilica",
		"Stelian", "Gabi",
		"Theodor", "Maria",
		"Ilie", "Mihail",
		"Miron", "Gabriel",
		"Anton", "Valeriu",
		"Eugen", "Corneliu",

		"Cosmin", "Mihail",
		"Darius", "Tiberiu",
		"Horea", "Virgil",
		"Bogdan", "Valerian",
		"Costin", "Gheorghe",
		"Virgil", "Horia",
		"Mihaita", "Pompiliu",
		"Doru", "Paul",
		"Gabriel", "Eugen",
		"Traian", "Marius",

		"Andrei", "Antoni",
		"Alexandru", "Mateescu",
		"Bogdan", "Musat",
		"Berta", "Bolini",
		"Bianca", "Rotaru",
		"Colin", "Draganu",
		"Costel", "Vasile",
		"Dan", "Caciula",
		"Daniela", "Matache",
		"Darius", "Adelei",
		"Erica", "Nicola"
	};

	const std::vector <std::string> PeopleNames(_peopleNamesInit, std::end(_peopleNamesInit));

	Grade grades[] = {
		Grade::Entry,
		Grade::Junior,
		Grade::Middle,
		Grade::Senior
	};
}
