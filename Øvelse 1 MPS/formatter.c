/*
 * formatter.c
 *
 *  Created on: 23/08/2013
 *      Author: phm
 */
#include <stdio.h>
#include <stdlib.h>
#include "formatter.h"

/*
 * Protected Methods
 */
void formatter_preamble_(formatter *cthis, char* string);
void formatter_postamble_(formatter *cthis, char* string);

/*
 * HTML sub-class of formatter class
 */

void html_preamble_(formatter *cthis, char* string){
	char html_start[]= {"<!DOCTYPE html>"};
	char html_header_start[]={"<HEAD>\n<TITLE>\n"};
	char html_header_end[]={"</TITLE>\n</HEAD>\n"};
	char html_body_start[]={"<BODY>\n"};

	fprintf(cthis->fp, "%s", html_start);
	fprintf(cthis->fp, "%s", html_header_start);
	fprintf(cthis->fp, "%s\n", string);
	fprintf(cthis->fp, "%s", html_header_end);
	fprintf(cthis->fp, "%s", html_body_start);
}

void html_postamble_(formatter *cthis, char* string){
	char html_body_end[]={"</BODY>\n"};
	char html_end[]={"</HTML>\n"};
	fprintf(cthis->fp, "%s", html_body_end);
	fprintf(cthis->fp, "%s", html_end);
}

void html_header_(formatter *cthis, char* string){
	fprintf(cthis->fp, "<H1>%s</H1>\n", string);
}

void html_body_(formatter *cthis, char* string){
	fprintf(cthis->fp, "<P>%s</P>\n", string);
}

/*
 * TEXT sub-class of formatter class
 */

void text_preamble_(formatter *cthis, char* string){
	char text_start[]= {"#### "};
	char text_header_start[]={"Start File: "};
	char text_header_end[]={" ####\n\n"};
	char text_body_start[]={"=====================================\n\n"};

	fprintf(cthis->fp, "%s", text_start);
	fprintf(cthis->fp, "%s", text_header_start);
	fprintf(cthis->fp, "%s", string);
	fprintf(cthis->fp, "%s", text_header_end);
	fprintf(cthis->fp, "%s", text_body_start);
}

void text_postamble_(formatter *cthis, char* string){
	char text_body_end[]={"-------------------------------------\n\n"};
	char text_end[]={"#### End File: "};

	fprintf(cthis->fp, "%s", text_body_end);
	fprintf(cthis->fp, "%s", text_end);
	fprintf(cthis->fp, "%s ####\n\n", string);
}

void text_header_(formatter *cthis, char* string){
	fprintf(cthis->fp, "%s\n\n", string);
}

void text_body_(formatter *cthis, char* string){
	char text_body_start[]={"=====================================\n\n"};

	fprintf(cthis->fp, "%s", text_body_start);
	fprintf(cthis->fp, "%s\n\n", string);
}
 
/*
 * Formatter class Constructor & Destructor
 */

void formatter_init(formatter *cthis, formatter_strategy strategy, char *pathname){

	char fullpathname[255];
	switch(strategy) {
	case HTML:
		cthis->preamble = html_preamble_;
		cthis->header = html_header_;
		cthis->body = html_body_;
		cthis->postamble = html_postamble_;

		puts("Formatting HTML\n");
		sprintf(fullpathname, "%s.html", pathname);
		break;
	case TEXT:
		cthis->preamble = text_preamble_;
		cthis->header = text_header_;
		cthis->body = text_body_;
		cthis->postamble = text_postamble_;

		puts("Formatting TXT\n");
		sprintf(fullpathname, "%s.txt", pathname);
		break;
	default:
		break;
	}

	cthis->fp=fopen(fullpathname, "w");
	if(cthis->fp <= 0) {
		printf("Invalid file pointer!\n");
		exit(0);
		}
	formatter_preamble_(cthis, fullpathname);
}

void formatter_release(formatter *cthis){
	formatter_postamble_(cthis, "Thanks Folks!");
	fclose(cthis->fp);
}

/*
 * Formatter class public methods 
 * (Prototypes are placed in formatter.h)
 ÆNDRING HERUNDER!!!
 */

void formatter_header(formatter *cthis, char* string){
	cthis->header(cthis, string);
}

void formatter_body(formatter *cthis, char* string){
	cthis->body(cthis, string);
}

void formatter_preamble_(formatter *cthis, char* string){
	cthis->preamble(cthis, string);
}

void formatter_postamble_(formatter *cthis, char* string){
	cthis->postamble(cthis, string);
}

