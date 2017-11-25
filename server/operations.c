#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

#include "operations.h"

char* operation(char** tab, int size) {
	double doubleArray[size-1];
	parseDouble(tab, doubleArray, size);
	char* output = malloc(0);

	if(strcmp(tab[0], "add") == 0) {
		double result = addition(doubleArray, size-1);
		sprintf(output, "%.2f", result);
	} else if(strcmp(tab[0], "sub") == 0) {
		double result = substraction(doubleArray, size-1);
		sprintf(output, "%.2f", result);
	} else if(strcmp(tab[0], "asc") == 0) {
		ascSorting(doubleArray, size);

		for(int i=0; i<size-1; i++) {
			char temp[sizeof(double)];
			sprintf(temp, "%.2f", doubleArray[i]);
			strcat(temp,"\n");
			puts(temp);
			strcat(output, temp);
		}
	} else if(strcmp(tab[0], "desc") == 0) {
		descSorting(doubleArray, size);

		for(int i=0; i<size-1; i++) {
			char temp[sizeof(double)];
			sprintf(temp, "%.2f", doubleArray[i]);
			strcat(temp,"\n");
			puts(temp);
			strcat(output, temp);
		}
	} else {
		output = "Bad parameters";
	}

	return output;
}

double addition(double* doubleArray, int size) {
	double sum = 0.0;
	for(int i = 0; i<size; i++) {
		sum += doubleArray[i];
	}

	return sum;
}

double  substraction(double* doubleArray, int size) {
	double diff = doubleArray[0];
	for(int i = 1; i<size; i++) {
		diff -= doubleArray[i];
	}

	return diff;
}

void  ascSorting(double* tab, int size) {
	qsort(tab, size-1, sizeof(double), compareAsc);
}

void descSorting(double* tab, int size) {
	qsort(tab, size-1, sizeof(double), compareDesc);
}

void parseDouble(char** stringTab, double* doubleTab, int size) {
	for(int i=1; i<size; i++) {
		doubleTab[i-1] = atof(stringTab[i]);
	}
}

int compareAsc (const void * a, const void * b) {
  if (*(double*)a > *(double*)b) return 1;
  else if (*(double*)a < *(double*)b) return -1;
  else return 0;  
}

int compareDesc (const void * a, const void * b) {
  if (*(double*)a < *(double*)b) return 1;
  else if (*(double*)a > *(double*)b) return -1;
  else return 0;  
}
