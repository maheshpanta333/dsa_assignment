# Problem:
How can we implement the doubly linked list using structure? Write a method to
insert(after given node) and delete the node in a doubly linked list. Write main() to
demonstrate the use of the functions.<br>

# Solution:
### Files

- doubly_linked_list.c (contains node struct, list logic, and main function)

### Compile and Run
```bash
g++ prog_4.c -o doubly_linked_list
./doubly_linked_list
```

## What I did??<br>
Created two structures one for node another for list with head and tail pointer to track end and beginning of the list for the traversal and then used **insertatend** function to add values into the list as nodes where **createnode** function would return a node with *key, next pointer and prev pointer* and replaces the tail pointer of the list everytime. The **insert_valueat** function handles insertion at any position including edge cases like empty list and position ≤ 0. The **delete_node** function removes nodes at specified positions while properly updating prev/next pointers. **reversal_traversal** works by starting with tail to head using *prev* pointer from each node and then **deleteall** for clearing the occupied memory!
