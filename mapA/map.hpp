/**
 * implement a container like std::map
 */
#ifndef SJTU_MAP_HPP
#define SJTU_MAP_HPP

// only for std::less<T>
#include <functional>
#include <cstddef>
#include "utility.hpp"
#include "exceptions.hpp"

namespace sjtu {

template<
    class Key,
    class T,
    class Compare = std::less<Key>
> class map {
public:
    /**
     * the internal type of data.
     * it should have a default constructor, a copy constructor.
     * You can use sjtu::map as value_type by typedef.
     */
    typedef pair<const Key, T> value_type;
    /**
     * see BidirectionalIterator at CppReference for help.
     *
     * if there is anything wrong throw invalid_iterator.
     *     like it = map.begin(); --it;
     *       or it = map.end(); ++end();
     */

    struct node
    {
        value_type* thedata;
      //  int s;
        int h;
        node* left;
        node* right;
        node* prev;
        node* next;
        node(value_type* d = NULL, int height = 1, node* l = NULL, node* r = NULL, node* pr = NULL, node* ne = NULL)
        {
            if (d != NULL) thedata = new value_type(*d);
            else thedata = NULL;

           // s = size;
            h = height;
            left = l;
            right = r;
            prev = pr;
            next = ne;

        }
        ~node() { delete thedata; }
    };


    class const_iterator;
    class iterator 
    {
        friend class const_iterator;
        friend class map;
    private:
        const map* themap;
        node* point;
        /**
         * TODO add data members
         *   just add whatever you want.
         */
    public:
        iterator() 
        {
            themap = NULL;
            point = NULL;
        }

        iterator(map* m, node* p)
        {
            themap = m;
            point = p;
        }

        iterator(const iterator &other) 
        {
            themap = other.themap;
            point = other.point;
        }
        /**
         * return a new iterator which pointer n-next elements
         *   even if there are not enough elements, just return the answer.
         * as well as operator-
         */
        /**
         * TODO iter++
         */
        iterator operator++(int) 
        {
            iterator tmp(*this);
            ++(*this);
            return tmp;
        }
        /**
         * TODO ++iter
         */
        iterator & operator++() 
        {
            if (point == NULL || point->next == NULL) throw invalid_iterator();
            point = point->next;
            return *this;
        }
        /**
         * TODO iter--
         */
        iterator operator--(int) 
        {
            iterator tmp(*this);
            --(*this);
            return tmp;
        }
        /**
         * TODO --iter
         */
        iterator & operator--() 
        {
            if (point == NULL || point->prev == NULL) throw invalid_iterator();
            point = point->prev;
            return *this;
        }
        /**
         * a operator to check whether two iterators are same (pointing to the same memory).
         */
        value_type & operator*() const 
        {
            return *(point->thedata);
        }
        bool operator==(const iterator &rhs) const 
        {
            return (point == rhs.point && themap == rhs.themap);
        }
        bool operator==(const const_iterator &rhs) const 
        {
            return (point == rhs.point && themap == rhs.themap);
        }
        /**
         * some other operator for iterator.
         */
        bool operator!=(const iterator &rhs) const 
        {
            return (point != rhs.point || themap != rhs.themap);
        }
        bool operator!=(const const_iterator &rhs) const 
        {
            return (point != rhs.point || themap != rhs.themap);
        }

        /**
         * for the support of it->first.
         * See <http://kelvinh.github.io/blog/2013/11/20/overloading-of-member-access-operator-dash-greater-than-symbol-in-cpp/> for help.
         */
        value_type* operator->() const noexcept 
        {
            return point->thedata;
        }
    };
    class const_iterator 
    {
        // it should has similar member method as iterator.
        //  and it should be able to construct from an iterator.
        friend class iterator;
        friend class map;
        private:
            const map* themap;
            node* point;
            // data members.
        public:
            const_iterator() 
            {
                themap = NULL;
                point = NULL;
            }

            const_iterator(const map* m, node* p)
            {
                themap = m;
                point = p;
            }

            const_iterator(const const_iterator &other) 
            {
                themap = other.themap;
                point = other.point;
            }
            const_iterator(const iterator &other) 
            {
                themap = other.themap;
                point = other.point;
            }
            // And other methods in iterator.
            // And other methods in iterator.
            // And other methods in iterator.

            const_iterator operator++(int)
            {
                const_iterator tmp(*this);
                ++(*this);
                return tmp;
            }
            /**
             * TODO ++iter
             */
            const_iterator& operator++()
            {
                if (point == NULL || point->next == NULL) throw invalid_iterator();
                point = point->next;
                return *this;
            }
            /**
             * TODO iter--
             */
            const_iterator operator--(int)
            {
                const_iterator tmp(*this);
                --(*this);
                return tmp;
            }
            /**
             * TODO --iter
             */
            const_iterator& operator--()
            {
                if (point == NULL || point->prev == NULL) throw invalid_iterator();
                point = point->prev;
                return *this;
            }
            /**
             * a operator to check whether two iterators are same (pointing to the same memory).
             */
            value_type& operator*() const
            {
                return *(point->thedata);
            }
            bool operator==(const iterator& rhs) const
            {
                return (point == rhs.point && themap == rhs.themap);
            }
            bool operator==(const const_iterator& rhs) const
            {
                return (point == rhs.point && themap == rhs.themap);
            }
            /**
             * some other operator for iterator.
             */
            bool operator!=(const iterator& rhs) const
            {
                return (point != rhs.point || themap != rhs.themap);
            }
            bool operator!=(const const_iterator& rhs) const
            {
                return (point != rhs.point || themap != rhs.themap);
            }

            const value_type* operator->() const noexcept
            {
                return point->thedata;
            }

    };

private:
        size_t sizeoftree;
        node* root;
        node* head;
        node* tail;
        Compare cmp;
public:
    /**
     * TODO two constructors
     */
    map() 
    {
        root = NULL;
        head = new node;
        tail = head;
        sizeoftree = 0;
    }
    map(const map &other) 
    {
        if (other.root == NULL)
        {
            root = NULL;
            tail = new node;
            head = tail;
            sizeoftree = 0;
            return;
        }
        else
        {
            root = new node;
            root->thedata = new value_type(*(other.root->thedata));
            sizeoftree = other.sizeoftree;
          //  root->s = other.root->s;
            root->h = other.root->h;
            tail = new node;
            copy(root, other.root);
            node* tmp = NULL;
            middleline(root, tmp);
            tmp->next = tail;
            tail->prev = tmp;
        }
    }

    void copy(node* a, node* b)
    {
        if (b->left != NULL)
        {
            a->left = new node;
            a->left->thedata = new value_type(*(b->left->thedata));
           // a->left->s = b->left->s;
            a->left->h = b->left->h;
            copy(a->left, b->left);
        }
        if (b->right != NULL)
        {
            a->right = new node;
            a->right->thedata = new value_type(*(b->right->thedata));
           // a->right->s = b->right->s;
            a->right->h = b->right->h;
            copy(a->right, b->right);
        }
    }

    void middleline(node* cnt, node*& pr)
    {
        if (cnt->left != NULL) middleline(cnt->left, pr);
        if (pr == NULL) head = cnt;
        cnt->prev = pr;
        if (pr != NULL) pr->next = cnt;
        pr = cnt;
        if (cnt->right != NULL) middleline(cnt->right, pr);
    }


    void cleartree(node* rot)
    {
        sizeoftree = 0;
        if (rot == NULL) return;
        else
        {
            cleartree(rot->left);
            cleartree(rot->right);
            delete rot;
        }
    }
    /**
     * TODO assignment operator
     */
    map & operator=(const map &other) 
    {
        if (this == &other) return *this;

        clear();

        sizeoftree = other.sizeoftree;
        if (other.root == NULL) return *this;
        else
        {
            root = new node;
            root->thedata = new value_type(*(other.root->thedata));
           // root->s = other.root->s;
            root->h = other.root->h;
            copy(root, other.root);
            node* tmp = NULL;
            middleline(root, tmp);
            tmp->next = tail;
            tail->prev = tmp;
            return *this;
        }
    }
    /**
     * TODO Destructors
     */
    ~map() 
    {
        clear();
     //   delete head;
        delete tail;
    }



    node* findnode(const Key& key, node* rot)const
    {
        if (rot == NULL) return NULL;
        else
        {
            if (cmp(key, rot->thedata->first)) return findnode(key, rot->left);
            else if (cmp(rot->thedata->first, key)) return findnode(key, rot->right);
            else return rot;
        }
    }
    /**
     * TODO
     * access specified element with bounds checking
     * Returns a reference to the mapped value of the element with key equivalent to key.
     * If no such element exists, an exception of type `index_out_of_bound'
     */



    T & at(const Key &key) 
    {
        node* ans;
        ans = findnode(key, root);
        if (ans == NULL) throw index_out_of_bound();
        else return ans->thedata->second;
    }



    const T & at(const Key &key) const 
    {
        node* ans;
        ans = findnode(key, root);
        if (ans == NULL) throw index_out_of_bound();
        else return ans->thedata->second;
    }
    /**
     * TODO
     * access specified element
     * Returns a reference to the value that is mapped to a key equivalent to key,
     *   performing an insertion if such key does not already exist.
     */
    T & operator[](const Key &key) 
    {
        node* p = insert(pair<Key, T>(key, T())).first.point;
        return p->thedata->second;
    }
    /**
     * behave like at() throw index_out_of_bound if such key does not exist.
     */
    const T & operator[](const Key &key) const 
    {
        return at(T);
    }
    /**
     * return a iterator to the beginning
     */
    iterator begin() 
    {
        return iterator(this, head);
    }
    const_iterator cbegin() const 
    {
       return const_iterator(this, head);
    }
    /**
     * return a iterator to the end
     * in fact, it returns past-the-end.
     */
    iterator end() 
    {
        return iterator(this, tail);
    }
    const_iterator cend() const 
    {
        return const_iterator(this, tail);
    }
    /**
     * checks whether the container is empty
     * return true if empty, otherwise false.
     */
    bool empty() const 
    {
        return (root == NULL);
    }
    /**
     * returns the number of elements.
     */
    size_t size() const 
    {
        if (root != NULL) return sizeoftree;
        else return 0;
    }
    /**
     * clears the contents
     */
    void clear() 
    {
        cleartree(root);
        delete tail;
        tail = new node;
        head = tail;
        root = NULL;
    }


    node* insertnode(const value_type& value, node*& rot)
    {
        node* inserted;
        if (rot == NULL)
        {
            sizeoftree++;
            rot = new node;
            rot->thedata = new value_type(value);
            return rot;
        }
        else if (cmp(value.first, rot->thedata->first))
        {
            bool leftnull = false;
            if (rot->left == NULL) leftnull = true;
            inserted = insertnode(value, rot->left);
            if (leftnull)
            {
                inserted->next = rot;
                inserted->prev = rot->prev;
                rot->prev = inserted;

                if (inserted->prev == NULL) head = inserted;
                else inserted->prev->next = inserted;
            }
            updatenode(rot);
            if (getheight(rot->left) - getheight(rot->right) > 1)
            {
                if (cmp(value.first, rot->left->thedata->first)) LL(rot);
                else LR(rot);
            }
            return inserted;
        }
        else
        {
            bool rightnull = false;
            if (rot->right == NULL) rightnull = true;
            inserted = insertnode(value, rot->right);
            if (rightnull)
            {
                inserted->prev = rot;
                inserted->next = rot->next;
                rot->next = inserted;
                inserted->next->prev = inserted;
            }
            updatenode(rot);
            if (getheight(rot->right) - getheight(rot->left) > 1)
            {
                if (cmp(value.first, rot->right->thedata->first)) RL(rot);
                else RR(rot);
            }
            return inserted;
        }
    }

    /**
 * insert an element.
 * return a pair, the first of the pair is
 *   the iterator to the new element (or the element that prevented the insertion),
 *   the second one is true if insert successfully, or false.
 */

    pair<iterator, bool> insert(const value_type &value) 
    {
        node* trytofind = findnode(value.first, root);
        if (trytofind != NULL) return pair<iterator, bool>(iterator(this, trytofind), false);
        else
        {
            node* inserted = insertnode(value, root);
            if (sizeoftree == 1)
            {
                head = inserted;
                inserted->next = tail;
                tail->prev = inserted;
            }
            return pair<iterator, bool>(iterator(this, inserted), true);
        }    
    }



    bool deletenode(node* target, node*& rot)
    {
        if (rot == NULL) return true;

        if (cmp(target->thedata->first, rot->thedata->first))
        {
            if (deletenode(target, rot->left)) return true;
            return adjust(rot, 0);
        }
        else if (cmp(rot->thedata->first, target->thedata->first))
        {
            if (deletenode(target, rot->right)) return true;
            return adjust(rot, 1);
        }
        else
        {
            if (rot->left == NULL || rot->right == NULL)
            {
                sizeoftree--;
                node* oldnode = rot;
                if (rot == head)
                {
                    head = head->next;
                    head->prev = NULL;
                }
                else
                {
                    rot->prev->next = rot->next;
                    rot->next->prev = rot->prev;
                }
                if (rot->left == NULL && rot->right == NULL)
                {
                    delete oldnode;
                    rot = NULL;
                }
                else if (rot->left != NULL)
                {
                    rot = rot->left;
                    delete oldnode;
                }
                else if (rot->right != NULL)
                {
                    rot = rot->right;
                    delete oldnode;
                }
                return false;
            }
            else
            {
                node* tmp = rot->right;
                while (tmp->left != NULL) tmp = tmp->left;
                delete rot->thedata;
                rot->thedata = new value_type(*tmp->thedata);
                if (deletenode(tmp, rot->right)) return true;
                return adjust(rot, 1);
            }
        }
    }

    bool adjust(node*& rot, int subtree)
    {
       // rot->s--;
        if (subtree)
        {
            if (getheight(rot->left) - getheight(rot->right) == 1)
            {
                return true;
            }
            if (getheight(rot->left) - getheight(rot->right) == 0)
            {
                rot->h--;
                return false;
            }
            if (getheight(rot->left->right) > getheight(rot->left->left))
            {
                LR(rot);
                return false;
            }
            else
            {
                LL(rot);
                if (getheight(rot->left) - getheight(rot->right) == 0) return false;
                else return true;
            }
        }
        else
        {
            if (getheight(rot->right) - getheight(rot->left) == 1)
            {
                return true;
            }
            if (getheight(rot->right) - getheight(rot->left) == 0)
            {
                rot->h--;
                return false;
            }
            if (getheight(rot->right->left) > getheight(rot->right->right))
            {
                RL(rot);
                return false;
            }
            else
            {
                RR(rot);
                if (getheight(rot->left) - getheight(rot->right) == 0) return false;
                else return true;
            }
        }
    }
    /**
     * erase the element at pos.
     *
     * throw if pos pointed to a bad element (pos == this->end() || pos points an element out of this)
     */
    void erase(iterator pos) 
    {
        if (pos.themap != this) throw invalid_iterator();
        else if (pos.point == NULL) throw invalid_iterator();
        else if (pos.point->thedata == NULL) throw invalid_iterator();
        else deletenode(pos.point, root);
    }
    /**
     * Returns the number of elements with key
     *   that compares equivalent to the specified argument,
     *   which is either 1 or 0
     *     since this container does not allow duplicates.
     * The default method of check the equivalence is !(a < b || b > a)
     */
    size_t count(const Key &key) const 
    {
        node* tmp;
        tmp = findnode(key, root);
        if (tmp == NULL) return 0;
        else return 1;
    }
    /**
     * Finds an element with key equivalent to key.
     * key value of the element to search for.
     * Iterator to an element with key equivalent to key.
     *   If no such element is found, past-the-end (see end()) iterator is returned.
     */
    iterator find(const Key &key) 
    {
        node* tmp;
        tmp = findnode(key, root);
        if (tmp == NULL) return end();
        else return iterator(this, tmp);
    }
    const_iterator find(const Key &key) const 
    {
        node* tmp;
        tmp = findnode(key, root);
        if (tmp == NULL) return cend();
        else return const_iterator(this, tmp);
    }

    int maxnum(int a, int b)
    {
        return (a > b) ? a : b;
    }

    int getheight(node* tmp)
    {
        return (tmp == NULL) ? 0 : tmp->h;
    }

    //int getsize(node* tmp)
    //{
    //    return (tmp == NULL) ? 0 : tmp->s;
    //}

    void LL(node*& tmp)
    {
        node* t = tmp->left;
        tmp->left = t->right;
        t->right = tmp;
        updatenode(tmp);
        updatenode(t);
        tmp = t;
    }

    void LR(node*& tmp)
    {
        RR(tmp->left);
        LL(tmp);
    }

    void RL(node*& tmp)
    {
        LL(tmp->right);
        RR(tmp);
    }

    void RR(node*& tmp)
    {
        node* t = tmp->right;
        tmp->right = t->left;
        t->left = tmp;
        updatenode(tmp);
        updatenode(t);
        tmp = t;
    }

    void updatenode(node* rot)
    {
        rot->h = maxnum(getheight(rot->left), getheight(rot->right)) + 1;
       // rot->s = getsize(rot->left) + getsize(rot->right) + 1;
    }
};

}

#endif
