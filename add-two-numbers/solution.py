                tail.next = temp
                tail = tail.next
            
            l1 = l1.next
            l2 = l2.next
        
        while l1:
            value = (remainder + l1.val) % 10
            remainder = (remainder + l1.val) // 10
            
            if not tail:
                head = ListNode(value, None)
                tail = head
            else:
                temp = ListNode(value, None)
                tail.next = temp
                tail = tail.next
                temp = ListNode(value, None)
                head = ListNode(value, None)
                tail = head
            else:
            remainder = (remainder + l1.val + l2.val) // 10
            
            if not tail:
        head = None
        remainder = 0
        
        while l1 and l2:
            value = (remainder + l1.val + l2.val) % 10
        
        
        tail = None
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:

import math
# Definition for singly-linked list.
# class ListNode:
