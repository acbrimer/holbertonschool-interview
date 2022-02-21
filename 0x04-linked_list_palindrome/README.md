# 0x04. Linked List Palindrome

## Task Description

Write a function to check if a linked list of type `listint_t` is a palindrome.

## Method

1. Get the length of the linked list.
2. Increment a linked list pointer until the midway point in the list is reached. If the lenght of the linked list is odd, increment this pointer to the next position (skip the middle value).
3. Reverse the second half of the linked list assigned at the pointer used in 2.
4. Increment both linked list pointers until values don't match (return 0) or end of list is reached (return 0).
