#ifndef operations_h__
#define operations_h__
	char* operation(char** tab, int size);
	double addition(double* doubleArray, int size);
	double substraction(double* doubleArray, int size);
	void ascSorting(double* tab, int size);
	void descSorting(double* tab, int size);
	void parseDouble(char** stringTab, double* doubleTab, int size);
	int compareAsc(const void * a, const void * b);
	int compareDesc(const void * a, const void * b);
#endif