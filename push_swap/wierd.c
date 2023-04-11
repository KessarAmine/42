#include <stdio.h>
#include <stdlib.h>

// function to merge two sub-stacks
void merge_sort(int* stackA, int* stackB, int* aux, int lenA, int lenB) {
    int i = 0, j = 0, k = 0;
    while (i < lenA && j < lenB) {
        if (stackA[i] < stackB[j]) {
            aux[k++] = stackA[i++];
        } else {
            aux[k++] = stackB[j++];
        }
    }
    while (i < lenA) {
        aux[k++] = stackA[i++];
    }
    while (j < lenB) {
        aux[k++] = stackB[j++];
    }
    // copy the elements of aux back to stackA
    for (i = 0; i < lenA + lenB; i++) {
        stackA[i] = aux[i];
    }
}

// function to sort stack A using divide and conquer
void divide_and_conquer_sort(int* stackA, int* stackB, int* aux, int len) {
    if (len <= 1) return;
    int middle = len / 2;
    int* left_stack = stackA;
    int* right_stack = stackA + middle;
    int len_left = middle;
    int len_right = len - middle;
    divide_and_conquer_sort(left_stack, stackB, aux, len_left);
    divide_and_conquer_sort(right_stack, stackB, aux, len_right);
    merge_sort(left_stack, right_stack, aux, len_left, len_right);
}

int main() {
    int stackA[] = {4, 1, 3, 2, 6, 5};
    int stackB[6]; // empty stack
    int aux[6];
    int len = sizeof(stackA) / sizeof(stackA[0]);
    divide_and_conquer_sort(stackA, stackB, aux, len);

    // print sorted stack
    for (int i = 0; i < len; i++) {
        printf("%d ", stackA[i]);
    }
    return 0;
}