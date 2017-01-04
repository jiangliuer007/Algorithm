
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


int left_rotate(rbt_node *proot, rbt_node *pnode);
