#include <stdio.h>
#include <stdarg.h>
#include "data_structures/data.h"



int main() {

	Data* date = data_create();
	Data* date2 = data_create();
	
	
	date->set(date, 30, 1, 1990);

	date2->set(date2, 10, 02, 1991);
	printf("%d/%d/%d", date2->dia, date2->mes, date2->ano); 

	system("pause");
}

