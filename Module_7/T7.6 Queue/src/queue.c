#include "queue.h"
#include <stdlib.h>
#include <string.h>

int enqueue(struct studentqueue *q, const char *name)
{
    struct studentqueue *newStudent = (struct studentqueue *)malloc(sizeof(struct studentqueue));
    newStudent->name = (char *)malloc((strlen(name) + 1) * sizeof(char));
    if (newStudent->name == NULL) {
        free(newStudent);
        return 0; 
    }
    strcpy(newStudent->name, name);

    newStudent->next = NULL;

    if (q->next == NULL) {
        q->next = newStudent;
    } else {
        
        struct studentqueue *current = q->next;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newStudent;
    }

    return 1;
}

int dequeue(struct studentqueue *q, char *buffer, unsigned int size)
{

    if (q->next == NULL) {
        return 0;
    }

    struct studentqueue *removedStudent = q->next;
    strncpy(buffer, removedStudent->name, size);
    buffer[size - 1] = '\0'; 

    q->next = removedStudent->next;

    free(removedStudent->name);
    free(removedStudent);

    return 1;
}
