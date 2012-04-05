#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*** Stack ***/
typedef struct _node
{
    void *data;
    struct _node *next;
} Node;

typedef struct _stack
{
    Node *head;
    Node *tail;
    int size;
} Stack;

void stackInit( Stack *stack )
{
    stack->head = NULL;
    stack->tail = NULL;
    stack->size = 0;

    return;
}

int push( Stack *stack, void *data )
{
    Node *node;

    if( stack == NULL || data == NULL )
        return -1;

    node = ( Node * )malloc( sizeof( Node ) );
    node->data = data;

    if( stack->size == 0 )
    {
        node->next = NULL;
        stack->head = node;
        stack->tail = node;
    }
    else
    {
        node->next = stack->head;
        stack->head = node;
    }

    stack->size++;

    return 0;
}

int pop( Stack *stack )
{
    Node *oldNode;

    if( stack == NULL || stack->size == 0 )
        return -1;

    oldNode = stack->head;
    stack->head = stack->head->next;
    stack->size--;

    return 0;
}

/*** tree ***/
typedef struct _treeNode
{
    int data;
    struct _treeNode *left;
    struct _treeNode *right;
} TreeNode;

typedef struct _tree
{
    TreeNode *root;
    int size;
} Tree;

void treeInit( Tree *tree )
{
    tree->root = NULL;
    tree->size = 0;

    return;
}

int treeInsert( Tree *tree, int data )
{
    TreeNode *tnode;
    TreeNode *pos;

    if( tree == NULL )
        return -1;

    tnode = ( TreeNode * )malloc( sizeof( TreeNode ) );

    tnode->data = data;
    tnode->left = NULL;
    tnode->right = NULL;
    
    if( tree->size == 0 )
    {
        tree->root = tnode;
    }
    else
    {
        pos = tree->root;

        while( 1 )
        {
            if( pos->data > tnode->data )
            {
                //printf( "left and %d\n", ( int )pos->left );
                if( pos->left == NULL )
                {
                    pos->left = tnode;
                    break;
                }

                 pos = pos->left;
            }
            else
            {
                if( pos->right == NULL )
                {
                    pos->right = tnode;
                    break;
                }
                pos = pos->right;
            }
        }
    }

    tree->size++;
}

enum BOOL
{
    FALSE = 0,
    TRUE
};

int main()
{
    Stack s;
    Tree t;
    int i;
    int array2[] = { 4, 2, 6, 1, 3, 5, 7 };
    enum BOOL done;
    TreeNode *curr;

    stackInit( &s );
    treeInit( &t );

    for( i = 0; i < sizeof( array2 ) / sizeof( array2[0] ); i++ )
    {
        treeInsert( &t, array2[i] );
        //printf( "%d\n",  );
    }
    
    /*********************** ACTUAL ITERATIVE PROCEDURE *******************************/

    curr = t.root;
    done = FALSE;
     
    while( !done )
    {
        if( curr ) 
        {
            push( &s, curr );
            curr = curr->left;
        }
        else
        {
            if( s.size == 0 )
            { 
                done = TRUE;
            }
            else
            {
                curr = ( TreeNode * )( s.head->data );
                printf( "%d\n", curr->data );
                pop( &s );
                curr = curr->right;
            }
        }
    }

    return;
}
