struct SLList_node {
    float data;
    struct SLList_node *next;
};

struct SLList_node *SLList_new_head(struct SLList_node *old_head, float data);
struct SLList_node *SLList_new_tail(struct SLList_node *old_tail, float data);
void SLList_delete(struct SLList_node *head);