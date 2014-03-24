/*
PROBLEM 
Find and fix the bugs in the following C function that is supposed to
remove the head element from a singly linked list:
void removeHead( ListElement *head ){
free( head ); // Line 1
head = head->next; // Line 2
}
*/

/*
bugs:
1. free the memory and then try to use it's next
2. error condition on empty list
3. doesn't update the caller
*/

void removeHead(ListElement **head){
	ListElement *temp;
	if( *head && head){
		//Q: is it necessary for the ()
		temp = (*head)-next;
		free(*head);
		*head = temp;
	}
}