#include "std_lib_facilities.h"
#include "Node.h"

/*  This problem follows the discussion we had in class. Read the function description carefully to understand
    the problem. A few modifications were made to the Node class definition by adding two member functions:

    // Sets the object's previous node pointer to some address.
    void setPreviousPointerToAddress(LinkedNode* address);
    // Sets the object's next node pointer to some address.
    void setNextPointerToAddress(LinkedNode* address);
*/


// helper function used to print out the entire list from head to tail
void printList(LinkedNode* head){
    LinkedNode* temp;
    if (head != nullptr){
        temp = head;
        while(temp != nullptr){
            cout << temp->getValue() << endl;
            temp = temp -> getNext();
        }
    }
}



// helper function used to construct list with the input vector values, returns the head and tail pointers of the list.
pair<LinkedNode*, LinkedNode*> constructList(vector<int> values){
    LinkedNode* head = nullptr;
    LinkedNode* temp = nullptr;
    for(int i = 0; i < values.size(); i++){
        if(i == 0){
            head = new LinkedNode(values[i], nullptr, nullptr);
            temp = head;
        }
        else {
            temp = new LinkedNode(values[i], temp, nullptr);
            temp->setBeforeAndAfterPointers();
        }
    }
    LinkedNode* tail = temp;
    return make_pair(head, tail);
}



// implement the following function (20 points)
// use heads and tails of all the lists created and concatenate them together to form 1 single long list, then returns
// head and tail of the new list
pair<LinkedNode*, LinkedNode*> concatenateLists(vector<LinkedNode*>& heads, vector<LinkedNode*>& tails){
    LinkedNode* newHead = nullptr;
    LinkedNode* newTail = nullptr;
    if (heads.size() == 0 || tails.size() == 0 || heads.size() != tails.size()) {
        return make_pair(newHead, newTail);
    }
    // concatenate all the lists together
    newHead = heads[0];
    newTail = tails[0];
    for (int i = 1; i < heads.size(); i++) {
        tails[i-1]->setNextPointerToAddress(heads[i]);
        heads[i]->setPreviousPointerToAddress(tails[i-1]);
    }
    return make_pair(newHead, tails[tails.size()-1]);
}

int main()
{
    /* One possible test case*/
    vector<vector<int>> values = {{1,2,3},
                                  {4,5,6,7,8,9},
                                  {10,11,12},
                                  {13,14,15,16,17}};
    vector<LinkedNode*> heads;
    vector<LinkedNode*> tails;
    // create 4 lists with values vector, create one vector to store all the heads and another vector to store all the tails,
    // you should have: (15 points)
    // List 1: [1,2,3]
    // List 2: [4,5,6,7,8,9]
    // List 3: [10,11,12]
    // List 4: [13,14,15,16,17]
    for (auto& v : values) {
        auto p = constructList(v);
        heads.push_back(p.first);
        tails.push_back(p.second);
    }
    // concatenate those 4 lists together to form one single list based on the function you defined above: (10 points)
    // [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17]
    auto p = concatenateLists(heads, tails);
    auto newHead = p.first;
    auto newTail = p.second;

    // use helper function to print out the entire list with the input of new head of the long list. (5 points)
    printList(newHead);

    /******************************************************************************************************************/
    return 0;
}