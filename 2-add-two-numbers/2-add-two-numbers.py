# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1, l2):
        
        dummy = pre = ListNode()
        carry = 0
        
        while l1 or l2:
            add = 0
            if l1:
                add += l1.val
                l1 = l1.next
            if l2:
                add += l2.val
                l2 = l2.next
                
            add += carry
            
            val = add % 10
            carry = add // 10
            
            pre.next = ListNode(val)
            pre = pre.next
            
        if carry:
            pre.next = ListNode(carry)
        
        return dummy.next
        