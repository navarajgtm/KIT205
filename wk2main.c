#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void option_insert(List* self) {
    int data;
    printf("Enter a value to insert: ");
    scanf("%d", &data);
    insert_at_front(self, data);
}

void option_delete(List* self) {
    int data;
    printf("Enter a value to delete: ");
    scanf("%d", &data);
    delete_list(self, data);
}

void option_print(List* self) {
    print_list(self);
}

void option_reverse(List* list) {
    List reversed_list = reverse(list);
    printf("Reversed list: ");
    print_list(&reversed_list);
    destroy_list(&reversed_list);
}

void option_merge() {
    List list1 = new_list();
    List list2 = new_list();

    printf("Enter data for list 1 (0 to stop):\n");
    int data;
    scanf("%d", &data);
    while (data != 0) {
        insert_in_order(&list1, data);
        scanf("%d", &data);
    }

    printf("Enter data for list 2 (0 to stop):\n");
    scanf("%d", &data);
    while (data != 0) {
        insert_in_order(&list2, data);
        scanf("%d", &data);
    }

    List merged_list = merge(&list1, &list2);
    printf("Merged list: ");
    print_list(&merged_list);
    destroy_list(&list1);
    destroy_list(&list2);
    destroy_list(&merged_list);
}



int main() {
    //Create a new list
    List my_list = new_list();

    // Declare an int for storing input
    int input;
    int quit = 0;

    //Read Input while quit is false
    while (!quit) {
        int option;
        printf("\nSelect an option:\n");
        printf("0 - Quit\n");
        printf("1 - Insert data\n");
        printf("2 - Delete data\n");
        printf("3 - Print list\n");
        printf("4 - Reverse list\n");
        printf("5 - Merge lists\n");

        scanf("%d", &option);
        switch (option) {
        case 0:
            quit = 1;
            break;
        case 1:
            option_insert(&my_list);
            break;
        case 2:
            option_delete(&my_list);
            break;
        case 3:
            option_print(&my_list);
            break;
        case 4:
            option_reverse(&my_list);
            break;
        case 5:
            option_merge();
            break;
        default:
            printf("Invalid option.\n");
            break;
        }
    }

    // Free the memory allocated to the list and its nodes
    destroy_list(&my_list);

    return 0;
}
