#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "operations.h"

char* operation(char** tab, int size) {
	struct node *head = NULL;
	char* output = malloc(0);

	for(int i = 1; i<size; i++) {
		struct node *link = (struct node*) malloc(sizeof(struct node));
		link->val = atof(tab[i]);
		link->next = head;
		head = link;
	}

	if(strcmp(tab[0], "add") == 0) {
		double result = addition(head);
		sprintf(output, "%.2f", result);
	} else if(strcmp(tab[0], "sub") == 0) {
		double result = substraction(head);
		sprintf(output, "%.2f", result);
	} else if(strcmp(tab[0], "asc") == 0) {
		ascSorting(head);
		output = printList(head);
	} else if(strcmp(tab[0], "desc") == 0) {
		descSorting(head);
		output = printList(head);
	} else {
		output = "Bad parameters";
	}

	return output;
}

double addition(struct node *header) {
	struct node *ptr = header;

	double sum = 0.0;
	while(ptr != NULL) {
		sum += ptr->val;
		ptr = ptr->next;
	}

	return sum;
}

double substraction(struct node *header) {
	struct node *ptr = header;

	double diff;
	diff = ptr->val;
	ptr = ptr->next;

	while(ptr != NULL) {
		diff -= ptr->val;
		ptr = ptr->next;
	}

	return diff;
}

void ascSorting(struct node *header) {
   int i, j, k;
   double tempVal;
   struct node *current;
   struct node *next;
	
   int size = length(header);
   k = size ;
	
   for ( i = 0 ; i < size - 1 ; i++, k-- ) {
      current = header;
      next = header->next;
		
      for ( j = 1 ; j < k ; j++ ) {   
		
         if ( current->val > next->val ) {
            tempVal = current->val;
            current->val = next->val;
            next->val = tempVal;
         }
			
         current = current->next;
         next = next->next;
      }
   }
}

void descSorting(struct node *header) {
   int i, j, k;
   double tempVal;
   struct node *current;
   struct node *next;
	
   int size = length(header);
   k = size ;
	
   for ( i = 0 ; i < size - 1 ; i++, k-- ) {
      current = header;
      next = header->next;
		
      for ( j = 1 ; j < k ; j++ ) {   
		
         if ( current->val < next->val ) {
            tempVal = current->val;
            current->val = next->val;
            next->val = tempVal;
         }
			
         current = current->next;
         next = next->next;
      }
   }
}
//====================================================================
int splitString(char* stringTab, char** returnTab){
	char* p = strtok(stringTab, " ");
	int n_spaces = 0;

	while(p) {
		returnTab = realloc(returnTab, sizeof(char*) *++n_spaces);

		if(returnTab == NULL) {
			exit(1);
		}
		
		returnTab[n_spaces-1] = p;

		p = strtok (NULL, " ");
	}

	returnTab = realloc (returnTab, sizeof (char*) * (n_spaces+1));

	return n_spaces;
}
//====================================================================
void insertFirst(double val, struct node *header) {
   struct node *link = (struct node*) malloc(sizeof(struct node));
   link->val = val;
   link->next = header;
   header = link;
}

char* printList(struct node *header) {
	struct node *ptr = header;

	char* output = malloc(0);

	while(ptr != NULL) {
		char temp[sizeof(double)];
		sprintf(temp, "%.2f", ptr->val);
		strcat(temp," ");
		strcat(output, temp);
		ptr = ptr->next;
	}

	return output;
}

int length(struct node *header) {
   int length = 0;
   struct node *current;
	
   for(current = header; current != NULL; current = current->next) {
      length++;
   }
	
   return length;
}
