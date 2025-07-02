struct DLList_node {
    float data;
    struct DLList_node *next, *prev;
};

struct DLList_node *DLList_new_head(struct DLList_node *old_head, float data);
struct DLList_node *DLList_new_tail(struct DLList_node *old_tail, float data);
void DLList_delete(struct DLList_node *head);
