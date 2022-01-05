#include "data.lib.h"

Data* dataFromBuffer(char* buffer) {
	int pos = 0;
	int i = 0;
	int tLen = 0;
	int counter = 0;

	int values[3] = { 0 };

	if (strlen(buffer) < 9) {
		return NULL;
	}
	for (i = 0; i < strlen(buffer); i++) {
		if (pos == Data_Nascimento_A) {
			int j = i + 1;
			while (buffer[j] != ',')
			{
				j++;
				if (buffer[j] == '-') {
					tLen = j - i;
					char* dataNascimento = (char*)malloc(tLen + 1);
					sprintf(dataNascimento, "%.*s", tLen, &buffer[i]);
					values[counter] = atoi(dataNascimento);
					counter++;
					i = j + 1;
				}
				if (buffer[j] == ',') {
					tLen = j - i;
					char* dataNascimento = (char*)malloc(tLen + 1);
					sprintf(dataNascimento, "%.*s", tLen, &buffer[i]);
					values[counter] = atoi(dataNascimento);
					counter++;
					i = j + 1;
					break;
				}
			}
			break;
		}
		else if (buffer[i] == ',') {
			pos++;
		}
	}

	return data_create(values[2],values[1],values[0]);
}