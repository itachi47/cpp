/* Implementation of linked list in cpp and reversing it without using the stack*/
#include <iostream>
#include <string.h>
using namespace std;

// structure of the node for the list
struct node{
	int data;
	node* next;
} *head = NULL;

//function to insert the values in the list
void insert(int val){
	node *temp = new node;
	temp->data = val;
	if(head == NULL){
		head = temp;
		temp->next = NULL;
	}
	else{
		node *ptr = head;
		while(ptr->next != NULL){
			ptr = ptr->next;
		}
		ptr->next = temp;
		temp->next = NULL;
	}
}

//function to display the data
void display(){
	node *ptr = head;
	while(ptr != NULL){
		cout << ptr->data << " ";
		ptr = ptr->next;
	}
}

//important funtion 
//reverse the list 
void reverse(){
	node *p, *n, *current;
  
  /* p is the  previous node pointer, n is the next node pointer and the current is the current node pointer.
  Initially p and n are pointing to NULL and current is pointing to head
  
  What we will do is we move the n to current->next, now we can break the link and
  point the current->next to p and then move p to current and current to next.
  Repeat till current is not null and then set head to p;
  
  Visualize it something like this:
  1 -> 2 -> 3 -> NULL
  after first iteration:
  NULL <- 1  2 -> 3 -> NULL and so on.
  */
  
	p = NULL, n = NULL;
	current = head;
	while(current != NULL){
		n = current->next;
		current->next = p;
		p = current;
		current = n;
	}
	head = p;
}

//main function
int main() {
	int num;
	string input;
	while(getline(cin, input, ' ')){
		num = atoi(input.c_str());
		insert(num);
	}
	display();
	reverse();
	cout << endl;
	display();
	return 0;
}
