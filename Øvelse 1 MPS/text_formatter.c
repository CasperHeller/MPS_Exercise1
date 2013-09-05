/*
 ============================================================================
 Name        : text_formatter.c
 Author      : PHM
 Version     :
 Copyright   : Your copyright notice
 Description : Text Formatter C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "formatter.h"
#include <conio.h>
int main(void) {
	// Create formatter object
	formatter my_formatter; 

	puts("Running my formatting tool!"); 
	
	// Invoke formatter constructor
	formatter_init(&my_formatter, TEXT, "c:\\temp\\abc");
//	formatter_init(&my_formatter, HTML, "c:\\temp\\abc");

	// Use formatter methods
	formatter_header(&my_formatter, "head head header");
	formatter_body(&my_formatter, "bod bod body");

	// Invoke formatter destructor
	formatter_release(&my_formatter);
	
	getch();
	return EXIT_SUCCESS;
}
