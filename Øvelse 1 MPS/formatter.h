/*
 * formatter.h
 *
 *  Created on: 23/08/2013
 *      Author: phm
 */

#ifndef FORMATTER_H_
#define FORMATTER_H_

// Forward declaration of struct 
// ("formatter" is used in formatter declaration below)
typedef struct formatter formatter;

// Struct to carry formatter attributes and virtual methods
struct formatter {
	FILE *fp;

	// Virtual Methods here! �NDRING HER!!!
	void (*header)(formatter *cthis, char* string);
	void (*body)(formatter *cthis, char* string);
	void (*preamble)(formatter *cthis, char* string);
	void (*postamble)(formatter *cthis, char* string);
};

// Formatter Strategies: TEXT=0, HTML=1
typedef enum {TEXT, HTML} formatter_strategy;

/*
 * Formatter class public methods 
 */

void formatter_header(formatter*, char*);
void formatter_body(formatter*, char*);
void formatter_init(formatter *cthis, formatter_strategy strategy, char *pathname);
void formatter_release(formatter *cthis);

#endif /* FORMATTER_H_ */
