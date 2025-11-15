#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
static void* indicator_memory = NULL; /*то, где эта память будет(пока указывает вникуда)*/
static size_t size_memory = 10*1024*1024;/*то, сколько нам надо выделить памяти*/
static int operation_count = 0;

void* my_alloc(size_t N){
    operation_count++;
    printf("Операция %d, память %zu ",operation_count, N);
    if (indicator_memory == NULL){
        void* variable=malloc(size_memory);
        if (variable != NULL){
            indicator_memory = variable;
            printf("Выделена память %zu, адрес %p\n", 
                size_memory/(1024*1024),indicator_memory);
        }
        else{
            printf("Не удалось выдклить %zu байт", size_memory);
            return NULL;
        }
    }
}

void my_free(void *p){
    
}
