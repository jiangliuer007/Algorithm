#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef enum red_black_tree_color {
    __black,
    __red
} rbt_color;

typedef struct red_black_tree_node {
    int ival;
    rbt_color color;
    struct red_black_tree_node *pparent;
    struct red_black_tree_node *pleft;
    struct red_black_tree_node *pright;
} rbt_node, *prbt_node;

typedef struct red_black_tree_head_info {
    struct red_black_tree_node *proot;
    struct red_black_tree_node *pnil;
} rbt_info, *prbt_info;

int rb_init(rbt_info *prbt_info);
int rb_insert(rbt_info *prbt_info, int ival);
int rb_delete(rbt_info *prbt_info, rbt_node *pz);
int rb_search(rbt_info *prbt_info, int ival, rbt_node **pptarget);

int rb_inorder_tree_walk(rbt_info *prbt_info);

