
#include "matrix.h"
#include "stdlib.h"

Matrix matrix_construction(void) {return bstree_ini();}
// Returns 1 or 0 if a key object occurs in the matrix
unsigned char matrix_index_in(Matrix m, Index1 index1, Index2 index2) {
    Key n_key = key_ini();
    key_set(n_key, index1, index2);
    if (bstree_search(m, n_key) == NULL) {
        key_free(n_key);
        return 0;
    } else {
        key_free(n_key);
        return 1;
    }
}
// Gets the value of a data object specified by index1,index2 as
// represented by key object notation
const Value *matrix_get(Matrix m, Index1 index1, Index2 index2) {
    Key n_key = key_ini();
    key_set(n_key, index1, index2);
    if (bstree_search(m, n_key) == NULL) {
        key_free(n_key);
        return NULL;
    } else {
        return bstree_search(m, n_key);
    }
}

// Inserts a key object into the bst thus the matrix as well.
void matrix_set(Matrix m, Index1 index1, Index2 index2, Value value) {
    Key n_key = key_ini();
    key_set(n_key, index1, index2);
    if (bstree_search(m, n_key) == NULL) {
        Data data = data_ini();
        data_set(data, value);
        bstree_insert(m, n_key, data);
    } else {
        data_set(bstree_search(m, n_key), value + 1);
        key_free(n_key);
    }}
void matrix_list(Matrix m) {bstree_traverse(m);}
// Frees the memory used by a matrix object.
void matrix_destruction(Matrix m) {bstree_free(m);}