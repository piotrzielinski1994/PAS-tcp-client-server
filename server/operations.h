#ifndef operations_h__
#define operations_h__
	struct node {
		double val;
		struct node *next;
	};

	char* operation(char** tab, int size);
	double addition(struct node *header);
	double substraction(struct node *header);
	void ascSorting(struct node *header);
	void descSorting(struct node *header);
	//====================================================================
	char** str_split(char* a_str, const char a_delim);
	int getSize(char** tab);
	//====================================================================
	char* printList(struct node *header);
	void insertFirst(double val, struct node *header);
	void swap(struct node *a, struct node *b);
	int length(struct node *header);
#endif