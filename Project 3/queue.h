#ifndef _QUEUE_H
#define _QUEUE_H

#include "exceptions.h"

const int DEFAULT_QUEUE_SIZE = 16;
const double DEFAULT_QUEUE_MULTIPLIER = 2.0;
const double DEFAULT_QUEUE_ADDER = 0.0;

template <class QueueType>
class Queue {
public:
  Queue(unsigned int s=DEFAULT_QUEUE_SIZE,
        double m=DEFAULT_QUEUE_MULTIPLIER,double b=DEFAULT_QUEUE_ADDER) {

    data = new QueueType[s];
    if (data == nullptr)
      throw Exception();

    capacity = s;
    this->m = m;
    this->b = b;

    head = s - 1;
    tail = 0;
    count = 0;
  }
  ~Queue() {

    delete[] data;
  }

  bool isEmpty() { return count == 0; }
  int size() { return count; }

  void clear() {

    head = capacity - 1;
    tail = 0;
    count = 0;
  }

  void enqueue(const QueueType &d) {

    if (count == capacity) {
      unsigned int
        newCap = m * capacity + b;

      if (newCap <= capacity)
        throw ContainerFullException();

      QueueType
        *tmpData = new QueueType[newCap];

      if (tmpData == nullptr)
        throw Exception("memory");

      for (int i=0;i<count;i++) {
        head = ++head % capacity;
        tmpData[i] = data[head];
      }

      head = newCap - 1;
      tail = capacity;

      delete[] data;
      data = tmpData;

      capacity = newCap;
    }

    data[tail] = d;

    tail = ++tail % capacity;
    count++;
  }

  QueueType dequeue() {

    if (count == 0)
      throw ContainerEmptyException();

    head = ++head % capacity;
    count--;

    return data[head];
  }

private:
  QueueType
    *data;
  unsigned int
    capacity,
    head,
    tail,
    count;
  double
    m,
    b;
};

#endif
