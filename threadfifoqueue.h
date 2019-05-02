/******************************************************************************
 *                                                                            *
 * MIT License                                                                *
 *                                                                            *
 * Copyright 2019 Gereon Such                                                 *
 *                                                                            *
 * Permission is hereby granted, free of charge, to any person obtaining      *
 * a copy of this software and associated documentation files (the            *
 * "Software"), to deal in the Software without restriction, including        *
 * without limitation the rights to use, copy, modify, merge, publish,        *
 * distribute, sublicense, and/or sell copies of the Software, and to         *
 * permit persons to whom the Software is furnished to do so, subject         *
 * to the following conditions:                                               *
 *                                                                            *
 * The above copyright notice and this permission notice shall be             *
 * included in all copies or substantial portions of the Software.            *
 *                                                                            *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,            *
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES            *
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND                   *
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS        *
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN         *
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN          *
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. *
 ******************************************************************************/

#ifndef THREADFIFOQUEUE_H
#define THREADFIFOQUEUE_H

#include <deque>
#include <mutex>
#include <condition_variable>

/**
 * \class ThreadFIFOQueue
 *
 * \brief Thread safe Queue with waiting for items.
 *
 * Implements a templated FIFO Queue as header only with
 * inline definition, use of std::deque, std::mutex and
 * std::condition_variable. It thus utilizes C++11
 * functionality and needs to be compiled with a standard
 * implementing these.
 *
 * \author Gereon Such
 *
 * Contact: gereonsuch@gmail.com
 */

namespace gs {

template<typename T>
class ThreadFIFOQueue //all methods are implemented in class, thus are implicitly inline, thus class is inline
{
    std::mutex d_itemlock;
    std::deque<T> d_items;
    std::condition_variable d_cv;
public:
    ThreadFIFOQueue() {}

    void push(T val){
        /** \brief Pushes another item to the back of the queue. */
        std::lock_guard<std::mutex> lock(d_itemlock);
        d_items.push_back(val);
        d_cv.notify_one(); //if pop is waiting, notify it.
    }

    T pop(){
        /** \brief Returns the first item in the queue or waits until an item is inserted if the queue is empty at call. */
        std::unique_lock<std::mutex> lock(d_itemlock);

        //wait for data and access to queue
        d_cv.wait(lock, [this]{return this->d_items.size();});

        T val=d_items.front();
        d_items.pop_front();
        return val;
    }

    size_t size(){
        /** \brief Returns the number of items in the queue. */
        std::lock_guard<std::mutex> lock(d_itemlock);
        return d_items.size();
    }

    bool empty(){
        /** \brief Returns true, if number of elements in queue is 0. */
        return size()==0;
    }

};

} // namespace gs

#endif // THREADFIFOQUEUE_H
