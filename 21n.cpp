#include<iostream>
using namespace std;

class emp{
	public:
	int eid;
	string ename;
	string ede;
	int emob;
	int esal;
	emp *next;
	
	void create();
	void display();
	void insertBeg();
	void insertEnd();
	void insertAtAnyPos();
	void removeStart();
	void removeEnd();
	void removeAtAnyPos();
	void table();
}*start;

void emp :: create(){
	int data,mo,sa;
	string name,de;
	emp *temp;
	temp = new emp;
	
	if(temp == NULL) {
		cout<<"Memory is not Allocated\n";
		return;
	}else {
		cout<<"Enter the data\n";
		cin>>data;
		cout<<"Enter the name of emp \n";
		cin>>name;
		cout<<"Enter the degs \n";
		cin>>de;
		cout<<"Enter the mobile no. \n";
		cin>>mo;
		cout<<"Enter the salary \n";
		cin>>sa;
		temp->eid = data;
		temp->ename = name;
		temp->ede = de;
		temp->emob = mo;
		temp->esal = sa;
		temp->next = NULL;
	}
	start = temp;
}

void emp :: display() {
	int data,mo,sa;
	string name,de;
	emp *temp;
	temp = new emp;
	temp = start;
	if(temp == NULL) {
		cout<<"List is Empty\n";
		return;
	} else{
		cout<<"Emp_id  "<<"Emp_Name  "<<"Emp_Deg  "<<"Emp_mob  "<<"Emp_sal "<<endl;
		while(temp!=NULL){
		
			cout<<temp -> eid<<"\t";
			cout<<temp -> ename <<"\t";
			cout<<temp -> ede <<" \t";
			cout<<temp -> emob <<"\t ";
			cout<<temp -> esal <<" \t";
			temp = temp -> next;
			cout<<endl;
		}
	}
	cout<<"\n";
	
}

void emp :: insertBeg() {
	int data,mo,sa;
	string name,de;
	emp *ptr;
	ptr = new emp;
	cout<<"Enter the data\n";
	cin>>data;
	cout<<"Enter the name of emp \n";
	cin>>name;
	cout<<"Enter the degs \n";
	cin>>de;
	cout<<"Enter the mobile no. \n";
	cin>>mo;
	cout<<"Enter the salary \n";
	cin>>sa;
	ptr->eid = data;
	ptr->ename = name;
	ptr->ede = de;
	ptr->emob = mo;
	ptr->esal = sa;
	ptr->next = NULL;
	if(start == NULL) {
		start = ptr;
		return;
	} else{
		ptr->next = start;
	}
	start = ptr;
}

void emp :: insertEnd() {
	int data,mo,sa;
	string name,de;
	emp *temp;
	temp = new emp;
	temp = start;
	emp *ptr;
	ptr = new emp;
	cout<<"Enter the data\n";
	cin>>data;
	
	cout<<"Enter the name of emp \n";
	cin>>name;
	cout<<"Enter the degs \n";
	cin>>de;
	cout<<"Enter the mobile no. \n";
	cin>>mo;
	cout<<"Enter the salary \n";
	cin>>sa;
	ptr->eid = data;
	ptr->ename = name;
	ptr->ede = de;
	ptr->emob = mo;
	ptr->esal = sa;
	
	
	ptr->next = NULL;
	if(start == NULL) {
		start = ptr;
		return;
	} else{
		while(temp->next != NULL) {
			temp = temp->next;
		}
	}
	temp->next = ptr;
}

void emp :: insertAtAnyPos() {
	int i = 0;
	int loc;
	int data,mo,sa;
	string name,de;
	
	
	emp *temp;
	temp = new emp;
	temp = start;
	
	emp *ptr;
	ptr = new emp;
	
	cout<<"Enter the data\n";
	cin>>data;
	
	cout<<"Enter the name of emp \n";
	cin>>name;
	cout<<"Enter the degs \n";
	cin>>de;
	cout<<"Enter the mobile no. \n";
	cin>>mo;
	cout<<"Enter the salary \n";
	cin>>sa;
	ptr->eid = data;
	ptr->ename = name;
	ptr->ede = de;
	ptr->emob = mo;
	ptr->esal = sa;
	
	
	ptr->next = NULL;
	
	cout<<"Enter the location where you want to insert the data\n";
	cin>>loc;
	
	if(temp == NULL) {
		cout<<"List is EMPTY\n";
		return;
	} else {
		while(i<loc-1) {
			temp = temp->next;
			i++;
		}
	}
	emp *succ;
	succ = new emp;
	
	succ  = temp->next;
	temp->next = ptr;
	ptr->next = succ;
}

void emp :: removeStart() {
	emp *temp;
	temp = new emp;
	temp = start;
	if(start == NULL) {
		cout<<"List is EMPTY";
		return;
	} else{
		start = start->next;
		delete(temp);
	}
}

void emp :: removeEnd() {
	emp *del;
	del = new emp;
	
	emp *temp;
	temp = new emp;
	temp = start;
	
	if(start == NULL) {
		cout<<"List is EMPTY";
		return;
	} else if(start->next == NULL){
		del = start;
		delete(del);
		start = NULL;
	} else{
		while((temp->next)->next != NULL) {
			temp = temp->next;
		}
		del = temp->next;
		delete(del);
		temp->next = NULL;
	}
}

void emp :: removeAtAnyPos() {
	int i = 0;
	int loc;
	
	emp *curr;
	curr = new emp;
	
	emp*prev;
	prev = new emp;
	
	emp *temp;
	temp = new emp;
	temp = start;
	
	cout<<"Enter the location where you want to delete the data\n";
	cin>>loc;
	
	if(temp == NULL) {
		cout<<"List is EMPTY\n";
		return;
	} else {
		while(i<=loc) {
			if(i == loc) {
				curr = temp;
				break;
			}
			else if(i<loc){
				prev = temp;
				temp = temp->next;
			}
			i++;
		}
		prev->next = curr->next;
		delete(curr);
	}
	
}

void emp :: table(){
	
	
}
	

int main(){
	emp emp1;
	int ch;
	
	do{
		cout<<"\nMenu";
		cout<<"\n1.Create the Linked List\n2.Display the Linked List\n3.Insert the Node at Beginning\n4.Insert the Node at the End\n5.Insert the node at Any position\n6.Delete the start node\n7.Delete the last Node\n8.Delete the Node From any position";
		cout<<"\nEnter your Choice\n";
		cin>>ch;
		
		switch(ch) {
			case 1:
				emp1.create();
				break;
			case 2:
				emp1.display();
				break;
			case 3:
			    emp1.insertBeg();
				break;
			case 4:
			    emp1.insertEnd();
				break;
			case 5:
				emp1.insertAtAnyPos();
				break;
			case 6:
			    emp1.removeStart();
				break;
			case 7:
				emp1.removeEnd();
				break;
			case 8:
				emp1.removeAtAnyPos();
				break; 
			case 9: 
			 emp1.table();
		}
	}while(ch != 0);
}
