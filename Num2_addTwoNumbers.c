struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* list = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* retList = list;
    int higher = 0;
    int tmp = 0;

    while (1) {
        if (l2 != NULL) {
            tmp = l2->val;
            l2 = l2->next;
        } else {
            tmp = 0;
        }

        tmp += l1->val + higher;
        list->val = tmp % 10;
        higher = tmp/10;

        l1 = l1->next;
        if (l1 == NULL) {
            break;
        }
        list->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        list = list->next;
    }

    
    while (l2 != NULL) {
        list->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        list = list->next;
        
        tmp = l2->val + higher;
        list->val = tmp % 10;
        higher = tmp/10;

        l2 = l2->next;
    }

    if (higher > 0) {
        list->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        list = list->next;
        list->val = higher;
    }
    
    list->next = NULL;

    return retList;
}