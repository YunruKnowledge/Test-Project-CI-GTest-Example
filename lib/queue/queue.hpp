

#ifndef QUEUE_H
#define QUEUE_H

#include <cstddef>
#include <new>

class IMemory {
public:
  virtual void *malloc(const size_t _size) = 0;
  virtual void free(void *_ptr) = 0;
};

template <typename T> class Queue {
  class Node {
  public:
    T value;
    Node *next;
  };

  IMemory &memory;
  Node *head{nullptr};
  Node *tail{nullptr};
  size_t count{0};

public:
  // CONSTRUCT
  Queue(IMemory &_memory) : memory{_memory} {};
  ~Queue() { clear(); }

  // COPY
  Queue(const Queue &) = delete;
  Queue &operator=(const Queue &) = delete;

  // MOVE
  Queue(Queue &&_inst) noexcept;
  Queue &operator=(Queue &&_inst) noexcept;

public:
  bool enqueue(const T &_value);

  bool dequeue(T &_var);

  size_t amount(void);

  void clear(void);
};

#endif