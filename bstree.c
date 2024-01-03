//bstree.c
#include "bstree.h"
#include "stdio.h"
#include "stdlib.h"
void helper_free(BStree bst);
BStree bstree_ini(void) {
    BStree bst = (BStree) malloc(sizeof(BStree_node *));
    *bst = NULL;
    return bst;
}
//Insert a key object and data value in the bstree but avoid duplicates.
void bstree_insert(BStree bst, Key key, Data data) {
    if (*bst == NULL) {
        *bst = new_node(key, data);
    } else if (key_comp(key, (*bst)->key) < 0) {
        bstree_insert(&((*bst)->left), key, data);
    } else if (key_comp(key, (*bst)->key) > 0) {
        bstree_insert(&((*bst)->right), key, data);
    }
}
// Helper function to create a node to insert into the bstree
BStree_node *new_node(Key key, Data data) {
    BStree_node *node = (BStree_node *) malloc(sizeof(BStree_node));
    node->data = data;
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}
//bstree.c
// Function to search if the given bstree contains data
// corresponding to a given key,returns null if the key does not
// exist within the tree or returns the data object address if
// found within the tree.
Data bstree_search(BStree bst, Key key) {
    if (*bst == NULL) {
        return NULL;
    }
    if (key_comp(key, (*bst)->key) > 0) {
        return bstree_search(&((*bst)->right), key);
    } else if (key_comp(key, (*bst)->key) < 0) {
        return bstree_search(&((*bst)->left), key);
    } else if (key_comp(key, (*bst)->key) == 0) {
        return (*bst)->data;
    }
}

// Traverse and print the entire bstree.
void bstree_traverse(BStree bst) {
    if (*bst != NULL) {
        // & for adress passing
        bstree_traverse(&((*bst)->left));
        key_print2((*bst)->key);
        data_print((*bst)->data);
        bstree_traverse(&((*bst)->right));
    }
}
//bstree.c
// Frees memory used by the bstree after its usage is not needed.
void bstree_free(BStree bst) {
    helper_free(bst);
    free(bst);
}
void helper_free(BStree bst) {
    if (*bst != NULL) {
        helper_free(&((*bst)->left));
        helper_free(&((*bst)->right));
        key_free((*bst)->key);
        data_free((*bst)->data);
        free(*bst);
    }
}
