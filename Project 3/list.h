#ifndef _LIST_H
#define _LIST_H

#include "exceptions.h"

template <class ListType>
class LinearList;

template <class ListType>
class ListNode {
public:
  ListNode(const ListType &d) {
    datum = d;
    next = nullptr;
  }

  ~ListNode() { }

  friend class LinearList<ListType>;

private:
  ListType
    datum;
  ListNode<ListType>
    *next;
};

template <class ListType>
class LinearList {
public:
  LinearList() {
    head = nullptr;
    count = 0;
  }

  ~LinearList() { clear(); }

  bool isEmpty() { return count == 0; }
  int size() { return count; }

  void clear() {
    ListNode<ListType>
      *cur,
      *tmp;

    cur = head;
    for (int i=0;i<count;i++) {
      tmp = cur->next;
      delete cur;
      cur = tmp;
    }
  }

  int search(const ListType &key) {
    ListNode<ListType>
      *tmp;

    tmp = head;
    for (int i=0;i<count;i++) {
      if (tmp->datum == key)
        return i;
      tmp = tmp->next;
    }

    throw KeyNotFoundException(to_string(key));
  }

  ListType &operator[](int pos) {
    ListNode<ListType>
      *tmp;

    if (pos < 0 || pos >= count)
      throw InvalidIndexException(pos);

    tmp = head;
    for (int i=0;i<pos;i++)
      tmp = tmp->next;

    return tmp->datum;
  }

  void traverse(void (*fp)(ListType &)) {
    ListNode<ListType>
      *tmp;

    tmp = head;
    for (int i=0;i<count;i++) {
      (*fp)(tmp->datum);
      tmp = tmp->next;
    }
  }

  void insert(int pos,const ListType &d) {
    ListNode<ListType>
      **pPred,
      *tmp;

      if (pos < 0 || pos > count)
        throw InvalidIndexException(pos);

      tmp = new ListNode<ListType>(d);

      pPred = &head;
      for (int i=0;i<pos;i++)
        pPred = &((*pPred)->next);

      tmp->next = *pPred;
      *pPred = tmp;

      count++;
  }

  void remove(int pos) {
    ListNode<ListType>
      **pPred,
      *tmp;

    if (pos < 0 || pos >= count)
      throw InvalidIndexException(pos);

    pPred = &head;
    for (int i=0;i<pos;i++)
      pPred = &((*pPred)->next);

    tmp = *pPred;
    *pPred = tmp->next;

    delete tmp;

    count--;
  }

private:
  ListNode<ListType>
    *head;
  unsigned int
    count;
};

#endif
