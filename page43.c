/* Page 43
PROBLEM :
head and tail are global pointers to the first and last element, respectively,
of a singly linked list of integers. Implement C functions for the following
prototypes:
bool delete( Element *elem );
bool insertAfter( Element *elem, int data );
The argument to delete is the element to be deleted. The two arguments to
insertAfter give the element after which the new element is to be inserted and
the data for the new element. It should be possible to insert at the beginning of the
list by calling insertAfter with NULL as the element argument. These functions
should return a boolean indicating success.
Your functions must keep the head and tail pointers current.
*/
bool delete (Element *elem){
	//error checking
	if(!head) 
		return false;
	if(!elem) 
		return false;
	
	if(elem == head){
		head = elem->next;
		free(elem);
		//update tail in one element list
		if(!head)
			tail = NULL;
		return true;
	}
	Element *curPos = head;
	while(curPos){
		if(curPos->next == elem){
			curPos->next = elem->next;
			//the last item to delete
			if(tail == elem){
				tail = curPos;
			}
			free(elem);
			return true;
		}
		curPos = curPos->next;
	}
	return false;
}
bool insertAfter(Element * elem, int data){
	Element *curPos = head;
	Element *insert = malloc(sizeof(Element));
	if(!insert)
		return false;
	insert->data = data;
	
	//inserting the front
	if(!elem){
		insert->next = head;
		head = insert;
		
		//empty list
		if(!tail)
			tail = insert;
		
		return true;
	}
	
	while(curPos){
		if(curPos == elem){
			insert->next = curPos->next;
			curPos->next = insert;
			//if insert after tail, update tail
			if(tail = elem)
				tail = insert;
				
			return true;
		}
		curPos = curPos->next;
	}
	
	//fail
	free(insert);
	return false;
}