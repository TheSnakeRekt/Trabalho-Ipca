#pragma once
#include "malloc.h"
#include "stdio.h"
#include "string.h"
#include "jsmn.h"

#define JSMN_HEADER

int jsoneq(const char* json, jsmntok_t* tok, const char* s);
char* get_value(char* json, char* key);