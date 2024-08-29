//
// Created by Leo on 11/19/21.
//

#include "Node.h"

LinkedNode::LinkedNode(int value, LinkedNode *prev, LinkedNode *next)
{
    m_prevNode = prev;
    m_nextNode = next;
    m_nodeValue = value;
}

int LinkedNode::getValue() const{
    return m_nodeValue;
}

LinkedNode* LinkedNode::getPrev() const {
    return m_prevNode;
}

LinkedNode* LinkedNode::getNext() const {
    return m_nextNode;
}

void LinkedNode::setNextPointerToAddress(LinkedNode* address) {
    m_nextNode = address;
}

void LinkedNode::setPreviousPointerToAddress(LinkedNode* address) {
    m_prevNode = address;
}

void LinkedNode::setBeforeAndAfterPointers() {
    if(m_prevNode != nullptr){
        m_prevNode -> m_nextNode = this;
    }
    if(m_nextNode != nullptr){
        m_nextNode -> m_prevNode = this;
    }
}

