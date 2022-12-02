// Code 1 - Add Last In a LinkedList

  void addLast(int n) {
    node *temp = new node();
      temp->data = n;
      temp->next = NULL;
      
      if(size == 0) {
        head = tail = temp;
      }
      else {
        tail->next = temp;
        tail = temp;
      }
      size++;
  }

// Code 2 - Remove first in a LinkedList

  void removeFirst() {
      if(size == 0) {
          cout << "List is empty" << endl;
      }
      else if(size == 1) {
        head = tail = NULL;
        size = 0;
      }
      else {
        head = head->next;
        size--;
      }
  }


// Code 3 - Add first in a LinkedList

  void addFirst(int val) {
        node temp = new node();
        temp->data = val;
        if(size == 0) {
            head = tail = temp;
            tail->next = null;
        }
        else {
            temp->next = head;
            head = temp;
        }
        size++;
    }

// Code 4 - Add at index in LinkedList

