#ifndef SJTU_DEQUE_HPP
#define SJTU_DEQUE_HPP

#include "exceptions.hpp"
#include <cstddef>

namespace sjtu {
    template<class T>
    class deque {
    public:
        class const_iterator;
        class node
        {
            friend class iterator;
            friend class const_iterator;
            friend class deque<T>;
        private:
            size_t nodesize;
            T** thedata;
            node* prev, * next;
            //const deque<T> thedeque;
        public:
            size_t nowsize;
            node(int size = 1000) :nodesize(size), nowsize(0), thedata(NULL), prev(NULL), next(NULL)
            {
                thedata = new T * [size];
            }
            node(const node& othernode) :nodesize(othernode.nodesize), nowsize(othernode.nowsize), thedata(NULL), prev(NULL), next(NULL)
            {
                thedata = new T * [nodesize];
                for (size_t i = 0;i < nowsize;++i)
                {
                    thedata[i] = new T(*(othernode.thedata[i]));
                }
            }
            ~node()
            {
                for (size_t i = 0;i < nowsize;++i)
                {
                    delete thedata[i];
                }
                delete[] thedata;
            }
        };
    private:
        node* head, * tail;
    public:
        size_t nowlength;
        class iterator {
            friend class deque<T>;
            friend class const_iterator;
        private:
            int i_p;
            const deque<T>* thedeque;
            node* thenode;
            /**
             * TODO add data members
             *   just add whatever you want.
             */
        public:
            iterator(const deque<T>* thedeque = NULL, node* thenode = NULL, int i_p = 0) :thedeque(thedeque), thenode(thenode), i_p(i_p) {}
            iterator(const iterator& other) :thedeque(other.thedeque), thenode(other.thenode), i_p(other.i_p) {}
            /**
             * return a new iterator which pointer n-next elements
             *   even if there are not enough elements, the behaviour is **undefined**.
             * as well as operator-
             */
            iterator operator+(const int& n) const
            {
                //TODO
                iterator tmp = *this;
                if (n == 0) return tmp;
                else if (n < 0) return tmp - (-n);
                else
                {
                    int distance = n;
                    while (tmp.thenode->nowsize - tmp.i_p <= distance)
                    {
                        if (tmp.thenode->next == tmp.thedeque->tail) break;
                        distance -= tmp.thenode->nowsize - tmp.i_p;
                        tmp.i_p = 0;
                        tmp.thenode = tmp.thenode->next;
                    }
                    if (tmp.thenode == tmp.thedeque->tail) throw index_out_of_bound();
                    tmp.i_p += distance;
                    return tmp;
                }
            }
            iterator operator-(const int& n) const {
                //TODO
                iterator tmp = *this;
                if (n == 0) return tmp;
                else if (n < 0) return tmp + (-n);
                else
                {
                    int distance = n;
                    while (tmp.i_p < distance && tmp.thenode != tmp.thedeque->head)
                    {
                        distance -= tmp.i_p + 1;
                        tmp.thenode = tmp.thenode->prev;
                        tmp.i_p = tmp.thenode->nowsize - 1;
                    }
                    if (tmp.thenode == tmp.thedeque->head && tmp.i_p < distance) throw index_out_of_bound();
                    tmp.i_p -= distance;
                    return tmp;
                }
            }
            // return th distance between two iterator,
            // if these two iterators points to different vectors, throw invaild_iterator.
            int operator-(const iterator& rhs) const {
                //TODO
                int distance = 0;
                if (thedeque != rhs.thedeque) throw invalid_iterator();
                if (thenode == rhs.thenode)
                {
                    return i_p - rhs.i_p;
                }
                else
                {
                    node* p = thenode->next;
                    distance -= thenode->nowsize - i_p;
                    while (p != rhs.thenode && p != NULL)
                    {
                        distance -= p->nowsize;
                        p = p->next;
                    }
                    if (p != NULL)
                    {
                        distance -= rhs.i_p;
                        return distance;
                    }
                    else
                    {
                        distance = 0;
                        node* q = rhs.thenode->next;
                        distance += rhs.thenode->nowsize - rhs.i_p;
                        while (q != thenode && q != NULL)
                        {
                            distance += q->nowsize;
                            q = q->next;
                        }
                        if (q != NULL)
                        {
                            distance += i_p;
                            return distance;
                        }
                        else throw runtime_error();
                    }
                }
            }
            iterator& operator+=(const int& n) {
                //TODO
                *this = (*this) + n;
                return *this;
            }
            iterator& operator-=(const int& n) {
                //TODO
                *this = (*this) - n;
                return *this;
            }
            /**
             * TODO iter++
             */
            iterator operator++(int)
            {
                iterator tmp = *this;
                if (i_p == thenode->nowsize - 1)
                {
                    i_p = 0;
                    if (thenode->next == NULL) throw index_out_of_bound();
                    else thenode = thenode->next;
                }
                else i_p++;
                return tmp;
            }
            /**
             * TODO ++iter
             */
            iterator& operator++()
            {
                (*this)++;
                return *this;
            }
            /**
             * TODO iter--
             */
            iterator operator--(int)
            {
                iterator tmp = *this;
                if (i_p == 0)
                {
                    if (thenode->prev == NULL) throw index_out_of_bound();
                    else
                    {
                        thenode = thenode->prev;
                        i_p = thenode->nowsize - 1;
                    }
                }
                else i_p--;
                return tmp;
            }
            /**
             * TODO --iter
             */
            iterator& operator--()
            {
                (*this)--;
                return *this;
            }
            /**
             * TODO *it
             */
            T& operator*() const
            {
                if (i_p < 0 || i_p >= thenode->nowsize) throw index_out_of_bound();
                return *(thenode->thedata[i_p]);
            }
            /**
             * TODO it->field
             */
            T* operator->() const noexcept
            {
                return (thenode->thedata[i_p]);
            }
            /**
             * a operator to check whether two iterators are same (pointing to the same memory).
             */
            bool operator==(const iterator& rhs) const
            {
                return((thenode == rhs.thenode && i_p == rhs.i_p) || (thenode->next == NULL && rhs.thenode->next == thenode && rhs.thenode->nowsize == rhs.i_p) || (thenode->next == rhs.thenode && rhs.thenode->next == NULL && i_p == thenode->nowsize));
            }
            bool operator==(const const_iterator& rhs) const
            {
                return((thenode == rhs.thenode && i_p == rhs.i_p) || (thenode->next == NULL && rhs.thenode->next == thenode && rhs.thenode->nowsize == rhs.i_p) || (thenode->next == rhs.thenode && rhs.thenode->next == NULL && i_p == thenode->nowsize));
            }
            /**
             * some other operator for iterator.
             */
            bool operator!=(const iterator& rhs) const
            {
                return !(*this == rhs);
            }
            bool operator!=(const const_iterator& rhs) const
            {
                return !(*this == rhs);
            }
        };
        class const_iterator {
            // it should has similar member method as iterator.
            //  and it should be able to construct from an iterator.
            friend class deque<T>;
            friend class iterator;
        private:
            int i_p;
            const deque<T>* thedeque;
            node* thenode;
            // data members.
        public:
            const_iterator(const deque<T>* thedeque = NULL, node* thenode = NULL, int i_p = 0) : thedeque(thedeque), thenode(thenode), i_p(i_p)
            {
                // TODO
            }
            const_iterator(const const_iterator& other) :thedeque(other.thedeque), thenode(other.thenode), i_p(other.i_p)
            {
                // TODO
            }
            const_iterator(const iterator& other) :thedeque(other.thedeque), thenode(other.thenode), i_p(other.i_p)
            {
                // TODO
            }
            // And other methods in iterator.
            // And other methods in iterator.
            // And other methods in iterator.
            const_iterator operator+(const int& n) const {
                //TODO
                const_iterator tmp = *this;
                if (n == 0) return tmp;
                else if (n < 0) return tmp - (-n);
                else
                {
                    int distance = n;
                    while (tmp.thenode->nowsize - tmp.i_p <= distance)
                    {
                        if (tmp.thenode->next == tmp.thedeque->tail) break;
                        distance -= tmp.thenode->nowsize - tmp.i_p;
                        tmp.i_p = 0;
                        tmp.thenode = tmp.thenode->next;
                    }
                    if (tmp.thenode == tmp.thedeque->tail) throw index_out_of_bound();
                    tmp.i_p += distance;
                    return tmp;
                }
            }
            const_iterator operator-(const int& n) const {
                //TODO
                const_iterator tmp = *this;
                if (n == 0) return tmp;
                else if (n < 0) return tmp + (-n);
                else
                {
                    int distance = n;
                    while (tmp.i_p < distance && tmp.thenode != tmp.thedeque->head)
                    {
                        distance -= tmp.i_p + 1;
                        tmp.thenode = tmp.thenode->prev;
                        tmp.i_p = tmp.thenode->nowsize - 1;
                    }
                    if (tmp.thenode == tmp.thedeque->head && tmp.i_p < distance) throw index_out_of_bound();
                    tmp.i_p -= distance;
                    return tmp;
                }
            }
            // return th distance between two iterator,
            // if these two iterators points to different vectors, throw invaild_iterator.
            int operator-(const const_iterator& rhs) const {
                //TODO
                int distance = 0;
                if (thedeque != rhs.thedeque) throw invalid_iterator();
                if (thenode == rhs.thenode)
                {
                    return i_p - rhs.i_p;
                }
                else
                {
                    node* p = thenode->next;
                    distance -= thenode->nowsize - i_p;
                    while (p != rhs.thenode && p != NULL)
                    {
                        distance -= p->nowsize;
                        p = p->next;
                    }
                    if (p != NULL)
                    {
                        distance -= rhs.i_p;
                        return distance;
                    }
                    else
                    {
                        distance = 0;
                        node* q = rhs.thenode->next;
                        distance += rhs.thenode->nowsize - rhs.i_p;
                        while (q != thenode && q != NULL)
                        {
                            distance += q->nowsize;
                            q = q->next;
                        }
                        if (q != NULL)
                        {
                            distance += i_p;
                            return distance;
                        }
                        else throw runtime_error();
                    }
                }
            }

            const_iterator& operator+=(const int& n) {
                //TODO
                *this = (*this) + n;
                return *this;
            }
            const_iterator& operator-=(const int& n) {
                //TODO
                *this = (*this) - n;
                return *this;
            }
            /**
             * TODO iter++
             */
            const_iterator operator++(int)
            {
                const_iterator tmp = *this;
                if (i_p == thenode->nowsize - 1)
                {
                    i_p = 0;
                    if (thenode->next == NULL) throw index_out_of_bound();
                    else thenode = thenode->next;
                }
                else i_p++;
                return tmp;
            }
            /**
             * TODO ++iter
             */
            const_iterator& operator++()
            {
                (*this)++;
                return *this;
            }
            /**
             * TODO iter--
             */
            const_iterator operator--(int)
            {
                const_iterator tmp = *this;
                if (i_p == 0)
                {
                    if (thenode->prev == NULL) throw index_out_of_bound();
                    else
                    {
                        thenode = thenode->prev;
                        i_p = thenode->nowsize - 1;
                    }
                }
                else i_p--;
                return tmp;
            }
            /**
             * TODO --iter
             */
            const_iterator& operator--()
            {
                (*this)--;
                return *this;
            }

            T& operator*() const
            {
                if (i_p < 0 || i_p >= thenode->nowsize) throw index_out_of_bound();
                return *(thenode->thedata[i_p]);
            }
            /**
             * TODO it->field
             */
            T* operator->() const noexcept
            {
                return (thenode->thedata[i_p]);
            }
            /**
             * a operator to check whether two iterators are same (pointing to the same memory).
             */
            bool operator==(const iterator& rhs) const
            {
                return((thenode == rhs.thenode && i_p == rhs.i_p) || (thenode->next == NULL && rhs.thenode->next == thenode && rhs.thenode->nowsize == rhs.i_p) || (thenode->next == rhs.thenode && rhs.thenode->next == NULL && i_p == thenode->nowsize));
            }
            bool operator==(const const_iterator& rhs) const
            {
                return((thenode == rhs.thenode && i_p == rhs.i_p) || (thenode->next == NULL && rhs.thenode->next == thenode && rhs.thenode->nowsize == rhs.i_p) || (thenode->next == rhs.thenode && rhs.thenode->next == NULL && i_p == thenode->nowsize));
            }
            /**
             * some other operator for iterator.
             */
            bool operator!=(const iterator& rhs) const
            {
                return !(*this == rhs);
            }
            bool operator!=(const const_iterator& rhs) const
            {
                return !(*this == rhs);
            }
        };
        /**
         * TODO Constructors
         */
        deque() :nodesize(1000), head(NULL), tail(NULL), nowlength(0)
        {
            head = new node(1000);
            tail = new node(1);
            head->next = tail;
            tail->prev = head;
        }
        deque(const deque& other) :nodesize(other.nodesize), head(NULL), tail(NULL), nowlength(other.nowlength)
        {
            head = new node(*other.head);
            tail = new node(1);
            node* p, * q;
            p = head;
            q = other.head->next;
            while (q != other.tail)
            {
                p->next = new node(*q);
                p->next->prev = p;
                p = p->next;
                q = q->next;
            }
            p->next = tail;
            tail->prev = p;
        }
        /**
         * TODO Deconstructor
         */
        ~deque()
        {
            clear();
            delete head;
            delete tail;
        }
        /**
         * TODO assignment operator
         */
        deque& operator=(const deque& other)
        {
            if (this == &other) return *this;
            else
            {
                clear();
                nowlength = other.nowlength;
                delete head;
                head = new node(*other.head);
                node* p = head;
                node* q = other.head->next;
                while (q != other.tail)
                {
                    p->next = new node(*q);
                    p->next->prev = p;
                    p = p->next;
                    q = q->next;
                }
                p->next = tail;
                tail->prev = p;
                return *this;
            }
        }
        /**
         * access specified element with bounds checking
         * throw index_out_of_bound if out of bound.
         */
        T& at(const size_t& pos)
        {
            node* p = head;
            size_t tmp = pos;
            while (p != tail && tmp >= p->nowsize)
            {
                tmp -= p->nowsize;
                p = p->next;
            }
            if (p == tail || tmp < 0) throw index_out_of_bound();
            return *(p->thedata[tmp]);
        }
        const T& at(const size_t& pos) const
        {
            node* p = head;
            size_t tmp = pos;
            while (p != tail && tmp >= p->nowsize)
            {
                tmp -= p->nowsize;
                p = p->next;
            }
            if (p == tail || tmp < 0) throw index_out_of_bound();
            return *(p->thedata[tmp]);
        }
        T& operator[](const size_t& pos)
        {
            return at(pos);
        }
        const T& operator[](const size_t& pos) const
        {
            return at(pos);
        }
        /**
         * access the first element
         * throw container_is_empty when the container is empty.
         */
        const T& front() const
        {
            if (nowlength == 0) throw container_is_empty();
            else return *(head->thedata[0]);
        }
        /**
         * access the last element
         * throw container_is_empty when the container is empty.
         */
        const T& back() const
        {
            if (nowlength == 0) throw container_is_empty();
            else return *(tail->prev->thedata[tail->prev->nowsize - 1]);
        }
        /**
         * returns an iterator to the beginning.
         */
        iterator begin()
        {
            if (nowlength == 0) return end();
            else
            {
                iterator tmp(this, head, 0);
                return tmp;
            }
        }
        const_iterator cbegin() const
        {
            if (nowlength == 0) return cend();
            else
            {
                const_iterator tmp(this, head, 0);
                return tmp;
            }
        }
        /**
         * returns an iterator to the end.
         */
        iterator end()
        {
            iterator tmp(this, tail, 0);
            return tmp;
        }
        const_iterator cend() const
        {
            const_iterator tmp(this, tail, 0);
            return tmp;
        }
        /**
         * checks whether the container is empty.
         */
        bool empty() const
        {
            return nowlength == 0;
        }
        /**
         * returns the number of elements
         */
        size_t size() const
        {
            return nowlength;
        }
        /**
         * clears the contents
         */
        void clear()
        {
            node* p, * q;
            p = head->next;
            delete head;
            head = new node(1000);
            head->next = tail;
            tail->prev = head;

            while (p != tail)
            {
                q = p->next;
                delete p;
                p = q;
            }

            nowlength = 0;
        }
        /**
         * inserts elements at the specified locat on in the container.
         * inserts value before pos
         * returns an iterator pointing to the inserted value
         *     throw if the iterator is invalid or it point to a wrong place.
         */
        iterator insert(iterator pos, const T& value)
        {
            if (this != pos.thedeque) throw invalid_iterator();
            if (pos.i_p == 0 && pos.thenode != pos.thedeque->head)
            {
                pos.thenode = pos.thenode->prev;
                pos.i_p = pos.thenode->nowsize;
            }
            nowlength++;
            changenode(pos.thenode);
            while (pos.i_p > pos.thenode->nowsize&& pos.thenode != pos.thedeque->tail)
            {
                pos.i_p -= pos.thenode->nowsize;
                pos.thenode = pos.thenode->next;
            }
            if (pos.thenode == pos.thedeque->tail) throw index_out_of_bound();

            if (pos.i_p == pos.thenode->nowsize)
            {
                pos.thenode->thedata[pos.i_p] = new T(value);
                pos.thenode->nowsize++;
                return pos;
            }
            for (int i = pos.thenode->nowsize;i > pos.i_p;--i)
            {
                pos.thenode->thedata[i] = pos.thenode->thedata[i - 1];
            }
            pos.thenode->thedata[pos.i_p] = new T(value);
            pos.thenode->nowsize++;
            return pos;
        }
        /**
         * removes specified element at pos.
         * removes the element at pos.
         * returns an iterator pointing to the following element, if pos pointing to the last element, end() will be returned.
         * throw if the container is empty, the iterator is invalid or it points to a wrong place.
         */
        iterator erase(iterator pos)
        {
            if (this != pos.thedeque) throw invalid_iterator();
            if (pos.thenode == tail) throw invalid_iterator();
            nowlength--;

            //if (pos.i_p == 0 && pos.thenode != pos.thedeque->head)
            //{
            //    pos.thenode = pos.thenode->prev;
            //    pos.i_p = pos.thenode->nowsize;
            //}

            while (pos.i_p < 0) {
                pos.thenode = pos.thenode->prev;
                pos.i_p += pos.thenode->nowsize;
            }
            if (pos.i_p == pos.thenode->nowsize) {
                pos.i_p = 0;
                pos.thenode = pos.thenode->next;
            }

            changenode(pos.thenode);
            while (pos.i_p >= pos.thenode->nowsize && pos.thenode != pos.thedeque->tail)
            {
                pos.i_p -= pos.thenode->nowsize;
                pos.thenode = pos.thenode->next;
            }
            if (pos.thenode == pos.thedeque->tail) throw index_out_of_bound();
            if (pos.i_p == pos.thenode->nowsize - 1)
            {
                delete pos.thenode->thedata[pos.thenode->nowsize - 1];
                pos.thenode->nowsize--;
                if (pos.i_p == pos.thenode->nowsize)
                {
                    pos.i_p = 0;
                    pos.thenode = pos.thenode->next;
                }
                return pos;
            }
            delete pos.thenode->thedata[pos.i_p];

            for (int i = pos.i_p;i < pos.thenode->nowsize - 1;++i)
            {
                pos.thenode->thedata[i] = pos.thenode->thedata[i + 1];
            }
            pos.thenode->nowsize--;
            if (pos.i_p == pos.thenode->nowsize)
            {
                pos.i_p = 0;
                pos.thenode = pos.thenode->next;
            }
            return pos;
        }
        /**
         * adds an element to the end
         */
        void push_back(const T& value)
        {
            insert(iterator(this, tail->prev, tail->prev->nowsize), value);
        }
        /**
         * removes the last element
         *     throw when the container is empty.
         */
        void pop_back()
        {
            erase(iterator(this, tail->prev, tail->prev->nowsize - 1));
        }
        /**
         * inserts an element to the beginning.
         */
        void push_front(const T& value)
        {
            insert(begin(), value);
        }
        /**
         * removes the first element.
         *     throw when the container is empty.
         */
        void pop_front()
        {
            erase(begin());
        }

    private:
        size_t nodesize = 1000;
        void changenode(node*& thenode)
        {
            if (thenode == tail) return;
           // else if (thenode->nowsize < nodesize / 2) 
                merge(thenode);
           // else if (thenode->nowsize >= nodesize) 
                split(thenode);
        }
        void merge(node*& thenode)
        {
            if (thenode == tail) return;
            if (thenode->nowsize < nodesize / 2)
            {
                while (thenode->nowsize + thenode->next->nowsize <= nodesize)
                {
                    if (thenode->next->next == NULL) break;
                    while (thenode->nowsize == 0)
                    {
                        if (thenode->next->next == NULL) break;
                        node* tmp = thenode;
                        thenode = tmp->next;
                        if (tmp == head) head = thenode;
                        delete tmp;
                    }
                    node* tmp = thenode->next;
                    if (tmp == tail)
                        break;
                    for (size_t i = thenode->nowsize;i < thenode->nowsize + thenode->next->nowsize;++i)
                    {
                        thenode->thedata[i] = thenode->next->thedata[i - thenode->nowsize];
                    }
                    thenode->nowsize += thenode->next->nowsize;

                    tmp->nowsize = 0;
                    thenode->next = thenode->next->next;
                    thenode->next->prev = thenode;
                    delete tmp;
                }
            }
        }

        void split(node*& thenode)
        {
            if (thenode == tail) return;
            if (thenode->nowsize >= nodesize)
            {
                node* newnode = new node(thenode->nodesize);
                newnode->prev = thenode;
                newnode->next = thenode->next;
                thenode->next->prev = newnode;
                thenode->next = newnode;
                size_t newsize = thenode->nowsize / 2;
                for (size_t i = newsize;i < thenode->nowsize;++i)
                {
                    newnode->thedata[i - newsize] = thenode->thedata[i];
                }
                newnode->nowsize = thenode->nowsize - newsize;
                thenode->nowsize = newsize;
            }
           
        }
    };

}

#endif
