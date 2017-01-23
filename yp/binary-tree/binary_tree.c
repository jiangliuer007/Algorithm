#include <stdio.h>                  
#include <stdlib.h>                 
#include <time.h>

typedef struct tree                 
{                                   
    struct tree * p;            
    struct tree * pleft;        
    struct tree * pright;       
    int     key;                
}node, *pnode;                      

void inorder_tree_walk(node *x)
{
    if( x != NULL)
    {
        inorder_tree_walk(x->pleft);
        printf("key = %d \r\n",x->key);
        inorder_tree_walk(x->pright);
    }
}

node* tree_search(node* x, int k)   
{                                   
    while( x != NULL && k != x->key)
    {                           

        if(k < x->key)              
            x = x->pleft;       
        else                        
            x = x->pright;      
    }
    return x;                   
}                                   

node* tree_minnum(node* x)          
{                                   
    while(x->pleft != NULL)     
        x = x->pleft;       
    return x;                   
}                                   


node* tree_maxnum(node* x)          
{                                   
    while(x->pright != NULL)    
        x = x->pright;      
    return x;                   
}                                   

node * tree_successor(node* x)             
{                                   
    if(x->pright != NULL)      
        return tree_minnum(x->pright);
    node * y = x->p;            
    while( y != NULL && x == y->pright)
    {
        x = y;
        y = y->p;
    }

    return y;
}

void tree_insert(node** T, node *z)
{
    node * y = NULL;
    node * x = *T;
    while (x != NULL)
    {
        y = x;
        if( z->key < x->key)
            x = x->pleft;
        else
            x = x->pright;
    }

    z->p = y;
    if( y == NULL)
        *T = z;
    else if (z->key < y->key)
        y->pleft = z;
    else
        y->pright = z;
}


void transplant( node ** T, node * u, node *v)
{
    if(u->p ==NULL)
        *T = v;
    else if (u ==u->p->pleft)
        u->p->pleft = v;
    else
        u->p->pright =v;

    if( v != NULL)
        v->p = u->p;
}

void tree_delete(node **T, node *z)
{
    if( z->pleft == NULL)
        transplant(T,z,z->pright);
    else if( z->pright == NULL)
        transplant(T,z,z->pleft);
    else 
    {
        node * y =NULL;
        y = tree_minnum(z->pright);
        if( y->p != z)
        {
            transplant(T,y,y->pright);
            y->pright = z->pright;
            y->pright->p = y;
        }
        transplant(T,z,y);
        y->pleft = z->pleft;
        y->pleft->p = y;
    }
}

int main()
{
    node * T = NULL;
    unsigned int seed= 200;
    srand(seed);
    int i =0;
    for(i = 0;i< 100; i++)
    {
        int randx =rand()%100;
        printf( " key = %d \r\n ", randx);
        node *z = (node*) malloc(sizeof(node));
        z->p = NULL;
        z->pleft =NULL;
        z->pright = NULL;
        z->key = randx;
        tree_insert(&T,z);
    }

    inorder_tree_walk(T);	
    node * max = tree_maxnum(T);
    printf( "max = %d \n ", max->key);

    node * min = tree_minnum(T);
    printf( "min = %d \n ", min->key);
    node * temp = tree_search(T, 41);
    node * succesor = tree_successor(temp);
    tree_delete(&T, temp);
    inorder_tree_walk(T);

    temp = tree_search(T, 40);
    tree_delete(&T, temp);
    inorder_tree_walk(T);
    return 0;
}
