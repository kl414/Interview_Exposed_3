/* page 50
PROBLEM 
Given a singly linked list, devise a time- and space-efficient algorithm
to find the mth-to-last element of the list. Implement your algorithm, taking care
to handle relevant error conditions. Define mth to last such that when m = 0 the
last element of the list is returned.
*/

/* 
Idea: traverse the list and make a new list that is backward of head
However this will take O(n * m) and more spaces.

Solution: using a queue of length m instead of making a new list
*/
ListElement *findMToLastElement(ListElement *head, int m){
		ListElement *current, *mToLast;
		int i  = 0;
		if(!head)
			return NULL;
		current = head;
		for( ; i < m; i++){
			//the list's length is less than m
			if(!current->next){
				return NULL;
			}else{	
				current = current->next;
			}
		}
		//keep traversing and keep current and mToLast m distance apart
		mToLast = head;
		while(current->next){
			current = current->next;
			mToLast = mToLast->next;
		}
		return mToLast;	
}
