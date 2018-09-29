// LinkedList.cpp

// tom bailey   0745  5 oct 2010
// Definition of methods for the List class.

#include "LinkedList.h"

#include <utility>


List::List()
	: first_(NULL), size_(0), sum_(0)
{
}


List::List(const List & other)
	: first_(clone(other.first_))
{
    size_ = other.size();
    sum_ = other.sum();
}


List::~List()
{
	while (!empty())
	{
		removeFirst();
	}
	size_ = 0;
    sum_ = 0;
}

const List & List::operator=(const List & other)
{
	// check for list = list
	if (&other != this)
	{
		// clear the current contents of this List
		this -> ~List();
		// and get a copy of other
		first_ = clone(other.first_);
		size_ = other.size_;
        sum_ = other.sum_;
	}
	return *this;
}


/*bool List::operator==(const List &rhs){
    if(size() == 0 && rhs.size() == 0){return true;}//both empty
    if(size() != rhs.size()){return false;}//sizes not the same

    Node * lptr = this->next_;
    Node * rptr = rhs->next_;
		Double lEntry = lptr->entry_;
    Double rEntry = rptr->entry_;
		while (lptr != NULL && rptr != NULL)
		{
      if(lEntry != rEntry){
        return false;
      }
      lptr = lptr->next_;
      rptr = rptr->next_;
      lEntry = lptr->entry_;
      rEntry = rptr->entry_;
		}

  	return true;
}*/


bool List::empty() const
{
	return first_ == NULL;
}

int List::size() const
{
    return size_;
}

double List::sum() const
{
    return sum_;
}

void List::insertAsFirst(double x)
{
    size_ = size_ + 1;
    sum_ = sum_ + x;
	first_ = new Node(x, first_);
}

// I'm adding lots of comments to this to help myself better understand it even though over commenting is a bad thing.
//Creates the commands for the function call insert as last, takes in a double as a parameter
void List::insertAsLast(double x){
    //Creates a pointer that points at the first Node in the list
    Node *ptr = first_;
    //Checks if the first Node contains nothing
    if (ptr == NULL){
        //If the Node contains nothing then the first node is set equal to a new node the contains the double and NULL
        first_ = new Node(x, first_);
    }
    else {
        // This while loop checks if the pointer is pointing at the last node and if it isn't it moves to the next
        // until it is pointing at the last node
        while (ptr->next_ != NULL) {
            // Moves the pointer to the next node
            ptr = ptr->next_;
        }
        //if (ptr->next_ == NULL) {  This if statement isn't necessary because the while loop breaks when
        //                           this condition is true

            // Creates a new node at the end of the list and
            ptr->next_ = new Node(x, NULL);
       // }
    }
}




double List::removeFirst()
{
    size_ = size_ - 1;
	double item = first_->entry_;
	Node * tempPtr = first_;
	first_ = first_->next_;
	delete tempPtr;
	sum_ = sum_ - item;
	return item;
}


void List::print(ostream & outfile) const
{
	outfile << "[ ";
	if (!empty())
	{
		// The first entry is printed separately because no comma
		// is needed.
		outfile << first_->entry_;
		Node * ptr = first_->next_;
		while (ptr != NULL)
		{
			outfile << ", " << ptr->entry_;
			ptr = ptr->next_;
		}
	}
	outfile << " ]";
}


// Iterative version of clone.
// This version walks down the linked structure making a
//   new Node for each double in the structure.
Node * List::clone(Node * ptr)
{
    if (ptr == NULL)
    {
        return NULL;
    }
    Node * first = new Node(ptr->entry_);
    Node * last = first;
    ptr = ptr->next_;
    while (ptr != NULL)
    {
        last->next_ = new Node(ptr->entry_);
        last = last->next_;
        ptr = ptr->next_;
    }
    return first;
}


//// Recursive version of clone.
//// This version handles two cases, a linked structure with
////   no Nodes, and a linked structure with one or more
////   Nodes.
//Node * List::clone( Node * ptr )
//{
//   if( ptr == NULL )
//   {
//      return NULL;
//   }
//   return new Node( ptr->entry_, clone( ptr->next_ ) );
//}


ostream & operator<<(ostream & outfile, const List & list)
{
	list.print(outfile);
	return outfile;
}
