# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def length(self,head):
        count = 0
        cur = head
        while cur:
            count += 1
            cur = cur.next
        return count
    
    def reverse(self,head):
        cur = head
        pre = None
        while cur!=None:
            nex = cur.next
            cur.next = pre
            pre = cur
            cur = nex
        return pre
    
    def rotateRight(self, head: Optional[ListNode], k: int):
        if head==None or head.next==None:
            return head
        
        total = self.length(head)
        k = k%total
        
        first = second = head
        move = total-k-1
        while move:
            second = second.next
            move -= 1
        temp = second.next
        second.next = None
        second = temp
        
        newH1 = self.reverse(first)
        newH2 = self.reverse(second)
        head.next = newH2
        head = self.reverse(newH1)
        return head