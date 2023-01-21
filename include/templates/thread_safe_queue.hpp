#ifndef ZMQWRAPPER_TEMPLATES_THREAD_SAFE_QUEUE_HPP
#define ZMQWRAPPER_TEMPLATES_THREAD_SAFE_QUEUE_HPP

#include <queue>
#include <mutex>
#include <condition_variable>

// A threadsafe-queue.
template <class T>
class thread_safe_queue
{
public:
  thread_safe_queue(void)
    : queue_instance_()
    , mutex_()
    , condition_variable_()
  {}

  ~thread_safe_queue(void)
  {}

  // Add an element to the queue.
  void emplace_back(T t)
  {
    std::lock_guard<std::mutex> lock(mutex_);
    queue_instance_.push(t);
    condition_variable_.notify_one();
  }

  // Get the "front"-element.
  // If the queue is empty, wait till a element is avaiable.
  T pop_front(void)
  {
    std::unique_lock<std::mutex> lock(mutex_);
    while(queue_instance_.empty())
    {
      // release lock as long as the wait and reaquire it afterwards.
      condition_variable_.wait(lock);
    }
    T val = queue_instance_.front();
    queue_instance_.pop();
    return val;
  }

private:

    // instance of the queue, not thread safe
    std::deque<T> queue_instance_;

    // mutex
    mutable std::mutex mutex_;
    std::condition_variable condition_variable_;
};

#endif // ZMQWRAPPER_TEMPLATES_THREAD_SAFE_QUEUE_HPP