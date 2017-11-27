#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

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
char** str_split(char* a_str, const char a_delim) {
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}

int getSize(char** tab) {
	int i = 0;

	if (tab) {
        while(*(tab + i)) {
        	i++;
        }
     }

     return i;
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
