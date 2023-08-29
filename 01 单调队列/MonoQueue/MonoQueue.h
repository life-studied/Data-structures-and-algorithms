#pragma once
#include <deque>
template <typename T>
class MonoQueue
{
protected:
	std::deque<T> queue;
public:
	template <typename InitIterator>
	MonoQueue(InitIterator begin,InitIterator end);
	MonoQueue() = default;
public:
	virtual void push(const T &value);
	T getMax();
	virtual void pop(const T& value);
};

template<typename T>
inline void MonoQueue<T>::push(const T &value)
{
	if (!queue.empty() && value < queue.back())
		queue.push_back(value);
	else 
	{
		for (int i = queue.size() - 1; i >= 0; i--)
			if (value > queue[i])
				queue.pop_back();
			else
			{
				break;
			}
		queue.push_back(value);
	}
}

template<typename T>
inline T MonoQueue<T>::getMax()
{
	return queue.front();
}

template<typename T>
inline void MonoQueue<T>::pop(const T& value)
{
	if (value == queue.front())
		queue.pop_front();
}

template<typename T>
template<typename InitIterator>
inline MonoQueue<T>::MonoQueue(InitIterator begin, InitIterator end)
{
	for (auto it = begin; it != end; it++)
	{
		push(*it);
	}
}
