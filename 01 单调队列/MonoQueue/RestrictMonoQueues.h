#pragma once
#include "MonoQueue.h"
#include <vector>
template <typename T>
class RestrictMonoQueues : public MonoQueue<T>
{
private:
	size_t size;
public:
	template <typename InitIterator>
	RestrictMonoQueues(size_t size, InitIterator begin, InitIterator end);
	RestrictMonoQueues(size_t size);
public:
	void push(const T& value) override;
	void pop(const T& value) override;
};

template<typename T>
template<typename InitIterator>
inline RestrictMonoQueues<T>::RestrictMonoQueues(size_t size, InitIterator begin, InitIterator end) :size(size), MonoQueue<T>(begin, end)
{
}

template<typename T>
inline RestrictMonoQueues<T>::RestrictMonoQueues(size_t size) : size(size), MonoQueue<T>()
{
}

template<typename T>
inline void RestrictMonoQueues<T>::push(const T& value)
{
	MonoQueue<T>::push(value);
	if (MonoQueue<T>::queue.size() > size)
		MonoQueue<T>::queue.pop_front();
}

template<typename T>
inline void RestrictMonoQueues<T>::pop(const T& value)
{
	MonoQueue<T>::pop(value);
}
