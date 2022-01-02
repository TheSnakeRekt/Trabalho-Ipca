#include "data_parser.h"
#define JSMN_HEADER

int jsoneq(const char* json, jsmntok_t* tok, const char* s) {
	if (tok->type == JSMN_STRING && (int)strlen(s) == tok->end - tok->start &&
		strncmp(json + tok->start, s, tok->end - tok->start) == 0) {
		return 0;
	}
	return -1;
}
char* get_value(char* json, char* key) {
	jsmn_parser p;
	jsmntok_t t[255];

	jsmn_init(&p);
	int r = jsmn_parse(&p, json, strlen(json), t, 5);

	for (int i = 1; i < r; i++) {
		if (jsoneq(json, &t[i], key) == 0) {
			char* str;

			int buff = snprintf(NULL, 0, "%.*s\n", t[i + 1].end - t[i + 1].start,
				json + t[i + 1].start);

			str = (char*) malloc(buff);
			snprintf(str, 0, "%.*s\n", t[i + 1].end - t[i + 1].start,
				json + t[i + 1].start);

			return str;
		}
	}
}
