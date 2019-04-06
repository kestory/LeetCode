//和剑指Offer 25-合并两个排序的链表 一样
//递归版
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		ListNode *pResult = NULL;
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;

		if (l1->val < l2->val) {
			pResult = l1;
			pResult->next = mergeTwoLists(l1->next, l2);
		}
		else {
			pResult = l2;
			pResult->next = mergeTwoLists(l1, l2->next);
		}
		return pResult;
	}
};


//迭代版
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		//有空链表的情况
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;
		//生成头结点
		ListNode *pHead = NULL;
		if (l1->val < l2->val) {
			pHead = l1;
			l1 = l1->next;
		}
		else {
			pHead = l2;
			l2 = l2->next;
		}
//			D(pHead->val)
		ListNode *pCurr = pHead;
		//遍历两个链表
		while (l1 != NULL && l2 != NULL) {
//				D(pCurr->val)
			if (l1->val < l2->val) {
				pCurr->next = l1;
				l1 = l1->next;
				pCurr = pCurr->next;
			}
			else {
				pCurr->next = l2;
				l2 = l2->next;
				pCurr = pCurr->next;
			}
		}

		//处理剩余部分
		if (l1 != NULL)
			pCurr->next = l1;
		if (l2 != NULL)
			pCurr->next = l2;

		return pHead;//返回这个！
	}
};
