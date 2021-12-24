#pragma once

#include <string.h>
#include <malloc.h>

int charToInt(char c) {
	return c - '0';
}

char* stringToCString(char *s) {
	char* cString = malloc(strlen(s) - 2);

	s[0] = "";
	s[strlen(s) - 1] = "";

	strcpy(cString, s);

	return cString;
}

