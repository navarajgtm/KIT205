#include <stdio.h>
#include <stdlib.h>
#include "list.h"


// Function to create and return a new empty list.
List new_list() {
	List temp;
	temp.head = NULL;
	return temp;
}

// Function to print the contents of a list.
void print_list(List* self) {
	ListNodePtr current = self->head;
	while (current != NULL) {
		printf("%d", current->data);
		current = current->next;

		if (current != NULL)
			printf(", ");
	}
	printf("\n");
}

// Function to insert a new node with given data at the front of the list.
void insert_at_front(List* self, int data) {
	ListNodePtr new_node = malloc(sizeof * new_node);

	new_node->data = data;
	new_node->next = self->head;
	self->head = new_node;
}

// Function to insert a new node with given data in the list in ascending order.
void insert_in_order(List* self, int data) {
	ListNodePtr current = self->head;
	ListNodePtr prev = NULL;

	ListNodePtr new_node = malloc(sizeof * new_node);
	new_node->data = data;
	new_node->next = NULL;

	while (current != NULL && current->data < data) {
		prev = current;
		current = current->next;
	}

	if (current == self->head) { // at front
		new_node->next = current;
		self->head = new_node;
	}
	else {                     // middle
		new_node->next = current;
		prev->next = new_node;
	}
}

// Function to delete the first occurrence of a node with given data from the list.
void delete_list(List* self, int data) {
	ListNodePtr current = self->head;
	ListNodePtr prev = NULL;

	while (current != NULL) {
		if (current->data == data) {
			if (prev == NULL) {        // front of list
				self->head = current->next;
				free(current);
				current = self->head;
			}
			else {                    // middle of list
				prev->next = current->next;
				free(current);
				current = prev->next;
			}
		}
		else {
			prev = current;
			current = current->next;
		}
	}
}

// Function to free the memory allocated to a list and all its nodes.
void destroy_list(List* self) {
	ListNodePtr current = self->head;
	while (current != NULL) {
		ListNodePtr to_free = current;
		current = current->next;
		free(to_free);
	}
	self->head = NULL;
}

//Function to reverse the given list and  return the new list
List reverse(List* self) {
	ListNodePtr curr = self->head;
	ListNodePtr prev = NULL;
	ListNodePtr next = NULL;

	while (curr != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	List reversed_list;
	reversed_list.head = prev;

	return reversed_list;
}


List merge(List* list1, List* list2) {
    List merged_list = new_list();
    ListNodePtr curr_node1 = list1->head;
    ListNodePtr curr_node2 = list2->head;
    while (curr_node1 != NULL && curr_node2 != NULL) {
        if (curr_node1->data < curr_node2->data) {
            insert_in_order(&merged_list, curr_node1->data);
            curr_node1 = curr_node1->next;
        } else {
            insert_in_order(&merged_list, curr_node2->data);
            curr_node2 = curr_node2->next;
        }
    }
    while (curr_node1 != NULL) {
        insert_in_order(&merged_list, curr_node1->data);
        curr_node1 = curr_node1->next;
    }
    while (curr_node2 != NULL) {
        insert_in_order(&merged_list, curr_node2->data);
        curr_node2 = curr_node2->next;
    }
    return merged_list;
}