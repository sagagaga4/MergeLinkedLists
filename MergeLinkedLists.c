#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val; 
    struct ListNode *next;  
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    struct ListNode *mergedList = NULL;
    struct ListNode *current = NULL;

    if (list1->val <= list2->val) {
        mergedList = list1;
        list1 = list1->next;
    } else {
        mergedList = list2;
        list2 = list2->next;
    }

    current = mergedList;

    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    if (list1 != NULL) {
        current->next = list1;
    } else {
        current->next = list2;
    }

    return mergedList;
}
