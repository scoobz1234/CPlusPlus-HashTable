#include <iostream>
#include <stdlib.h>
#include "MyHash.h"
#include "MyHash.cpp"

using namespace std;

int main() {
	
	//Create HashTable that takes String as Key and String as Data
	MyHash<string, string> stringHash("empty", "empty", 40);

	string contacts[13][13] = 
	{ 
		{"Stephen Ouellette",	"503-351-1867"},
		{"Marissela Ouellette",	"503-290-8378"},
		{"Maddison Clarke",		"503-936-8232"},
		{"William Murdock",		"907-632-6645"},
		{"Joe Aiello",			"858-353-4229"},
		{"Brandy Vasquez",		"503-290-8377"},
		{"Kristie Salatino",	"864-540-1654"},
		{"Jr Velasquez",		"503-442-9953"},
		{"Dana Ouellette",		"864-986-2634"},
		{"Gail Ouellette",		"864-986-2632"},
		{"Jesus Velasquez",		"971-255-6113"},
		{"Suzanne Velasquez",	"503-504-8476"},
		{"Shya Villobos",		"503-820-9041"}
	};

	stringHash.AddItem(contacts[0][0], contacts[0][1]);
	stringHash.AddItem(contacts[1][0], contacts[1][1]);
	stringHash.AddItem(contacts[2][0], contacts[2][1]);
	stringHash.AddItem(contacts[3][0], contacts[3][1]);
	stringHash.AddItem(contacts[4][0], contacts[4][1]);
	stringHash.AddItem(contacts[5][0], contacts[5][1]);
	stringHash.AddItem(contacts[6][0], contacts[6][1]);
	stringHash.AddItem(contacts[7][0], contacts[7][1]);
	stringHash.AddItem(contacts[8][0], contacts[8][1]);
	stringHash.AddItem(contacts[9][0], contacts[9][1]);
	stringHash.AddItem(contacts[10][0], contacts[10][1]);
	stringHash.AddItem(contacts[11][0], contacts[11][1]);
	stringHash.AddItem(contacts[12][0], contacts[12][1]);


	stringHash.PrintHash();
	stringHash.PrintItemsInIndex(0);
	stringHash.RemoveItem("Joe Aiello");
	stringHash.PrintItemsInIndex(0);

	stringHash.FindData("Suzanne Velasquez");
	stringHash.RemoveItem("Stephen Ouellette");
	stringHash.PrintHash();


	//// creating a hash table that takes string as key and int as data
	//MyHash<string, long> intHash("empty", 0, 4);

	//intHash.AddItem(contacts[0][0], 1867);
	//intHash.AddItem(contacts[1][0], 8378);
	//intHash.AddItem(contacts[2][0], 8232);
	//intHash.AddItem(contacts[3][0], 6645);
	//intHash.AddItem(contacts[4][0], 4229);
	//intHash.AddItem(contacts[5][0], 8377);
	//intHash.AddItem(contacts[6][0], 1654);
	//intHash.AddItem(contacts[7][0], 9953);
	//intHash.AddItem(contacts[8][0], 2634);
	//intHash.AddItem(contacts[9][0], 2632);
	//intHash.AddItem(contacts[10][0], 6113);
	//intHash.AddItem(contacts[11][0], 8476);
	//intHash.AddItem(contacts[12][0], 9041);

	//intHash.PrintHash();
	//intHash.PrintItemsInIndex(0);

	return 0;
}