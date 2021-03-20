#ifndef SJTU_VECTOR_HPP
#define SJTU_VECTOR_HPP

#include "exceptions.hpp"

#include <climits>
#include <cstddef>

namespace sjtu {
	/**
	 * a data container like std::vector
	 * store data in a successive memory and support random access.
	 */

	template<typename T>
	class vector {
	private:
		T* thedata;
		size_t used_memory;
		size_t total_memory;
		void doublespace()
		{
			total_memory *= 2;
			T* temp = (T*)malloc(sizeof(T) * total_memory);
			memset(temp, 0, total_memory * sizeof(T));
			for (size_t i = 0;i < used_memory;++i)
			{
				temp[i] = thedata[i];
				thedata[i].~T();
			}
			free(thedata);
			thedata = temp;
		}
	public:
		/**
		 * TODO
		 * a type for actions of the elements of a vector, and you should write
		 *   a class named const_iterator with same interfaces.
		 */
		 /**
		  * you can see RandomAccessIterator at CppReference for help.
		  */

		class const_iterator;
		class iterator {
			friend class vector<T>;
		private:
			/**
			 * TODO add data members
			 *   just add whatever you want.
			 */
			T* i_p;
			vector<T>* thevector;
		public:
			iterator()
			{
				i_p = NULL;
				thevector = NULL;
			}

			iterator(iterator const& other)
			{
				thevector = other.thevector;
				i_p = other.i_p;
			}

			iterator(vector<T>* vect, T* x)
			{
				thevector = vect;
				i_p = x;
			}
			/**
			 * return a new iterator which pointer n-next elements
			 * as well as operator-
			 */
			iterator operator+(const int& n) const {
				//TODO
				iterator temp(thevector, i_p + n);
				return temp;
			}
			iterator operator-(const int& n) const {
				//TODO
				iterator temp(thevector, i_p - n);
				return temp;
			}
			// return the distance between two iterators,
			// if these two iterators point to different vectors, throw invaild_iterator.
			int operator-(const iterator& rhs) const {
				size_t distance;
				if (thevector != rhs.thevector) throw invalid_iterator();
				else distance = ((i_p > rhs.i_p) ? i_p - rhs.i_p : rhs.i_p - i_p);
				return distance;
				//TODO
			}
			iterator& operator+=(const int& n) {
				//TODO
				i_p += n;
				return *this;
			}
			iterator& operator-=(const int& n) {
				//TODO
				i_p -= n;
				return *this;
			}
			/**
			 * TODO iter++
			 */
			iterator operator++(int) {
				iterator temp = *this;
				i_p++;
				return temp;
			}
			/**
			 * TODO ++iter
			 */
			iterator& operator++() {
				i_p++;
				return *this;
			}
			/**
			 * TODO iter--
			 */
			iterator operator--(int) {
				iterator temp = *this;
				i_p--;
				return temp;
			}
			/**
			 * TODO --iter
			 */
			iterator& operator--() {
				i_p--;
				return *this;
			}
			/**
			 * TODO *it
			 */
			T& operator*() const { return *i_p; }
			/**
			 * a operator to check whether two iterators are same (pointing to the same memory address).
			 */
			bool operator==(const iterator& rhs) const {
				return i_p == rhs.i_p;
			}
			bool operator==(const const_iterator& rhs) const {
				return i_p == rhs.i_p;
			}
			/**
			 * some other operator for iterator.
			 */
			bool operator!=(const iterator& rhs) const {
				return i_p != rhs.i_p;
			}
			bool operator!=(const const_iterator& rhs) const {
				return i_p != rhs.i_p;
			}

			~iterator() {}
		};
		/**
		 * TODO
		 * has same function as iterator, just for a const object.
		 */
		class const_iterator {
			friend class vector<T>;
		private:
			/**
			 * TODO add data members
			 *   just add whatever you want.
			 */
			T* i_p;
			const vector<T>* thevector;
		public:
			const_iterator()
			{
				i_p = NULL;
				thevector = NULL;
			}

			const_iterator(iterator const& other)
			{
				thevector = other.thevector;
				i_p = other.i_p;
			}

			const_iterator(const vector<T>* vect, T* x)
			{
				thevector = vect;
				i_p = x;
			}
			/**
			 * return a new iterator which pointer n-next elements
			 * as well as operator-
			 */
			const_iterator operator+(const int& n) const {
				//TODO
				const_iterator temp(thevector, i_p + n);
				return temp;
			}
			const_iterator operator-(const int& n) const {
				//TODO
				const_iterator temp(thevector, i_p - n);
				return temp;
			}
			// return the distance between two iterators,
			// if these two iterators point to different vectors, throw invaild_iterator.
			int operator-(const const_iterator& rhs) const {
				size_t distance;
				if (thevector != rhs.thevector) throw invalid_iterator();
				else distance = ((i_p > rhs.i_p) ? i_p - rhs.i_p : rhs.i_p - i_p);
				return distance;
				//TODO
			}
			const_iterator& operator+=(const int& n) {
				//TODO
				i_p += n;
				return *this;
			}
			const_iterator& operator-=(const int& n) {
				//TODO
				i_p -= n;
				return *this;
			}
			/**
			 * TODO iter++
			 */
			const_iterator operator++(int) {
				const_iterator temp = *this;
				i_p++;
				return temp;
			}
			/**
			 * TODO ++iter
			 */
			const_iterator& operator++() {
				i_p++;
				return *this;
			}
			/**
			 * TODO iter--
			 */
			const_iterator operator--(int) {
				const_iterator temp = *this;
				i_p--;
				return temp;
			}
			/**
			 * TODO --iter
			 */
			const_iterator& operator--() {
				i_p--;
				return *this;
			}
			/**
			 * TODO *it
			 */
			T& operator*() const { return *i_p; }
			/**
			 * a operator to check whether two iterators are same (pointing to the same memory address).
			 */
			bool operator==(const iterator& rhs) const {
				return i_p == rhs.i_p;
			}
			bool operator==(const const_iterator& rhs) const {
				return i_p == rhs.i_p;
			}
			/**
			 * some other operator for iterator.
			 */
			bool operator!=(const iterator& rhs) const {
				return i_p != rhs.i_p;
			}
			bool operator!=(const const_iterator& rhs) const {
				return i_p != rhs.i_p;
			}

			~const_iterator() {}
		};
		/**
		 * TODO Constructs
		 * Atleast two: default constructor, copy constructor
		 */
		vector()
		{
			used_memory = 0;
			total_memory = 1;
			thedata = (T*)malloc(sizeof(T));
			memset(thedata, 0, sizeof(T));
		}
		vector(const vector& other)
		{
			thedata = (T*)malloc(sizeof(T) * other.total_memory);
			memset(thedata, 0, other.total_memory * sizeof(T));
			for (size_t i = 0;i < other.used_memory;++i)
			{
				thedata[i] = other.thedata[i];
			}
			total_memory = other.total_memory;
			used_memory = other.used_memory;
		}
		/**
		 * TODO Destructor
		 */
		~vector()
		{
			for (size_t i = 0;i < used_memory;++i)
				thedata[i].~T();
			used_memory = 0;
			total_memory = 1;
			free(thedata);
		}
		/**
		 * TODO Assignment operator
		 */
		vector& operator=(const vector& other)
		{
			if (this == &other) return *this;
			for (size_t i = 0;i < used_memory;++i)
			{
				thedata[i].~T();
			}
			free(thedata);
			total_memory = other.total_memory;
			used_memory = other.used_memory;
			thedata = (T*)malloc(sizeof(T) * other.total_memory);
			memset(thedata, 0, other.total_memory * sizeof(T));
			for (size_t i = 0;i < other.used_memory;++i)
			{
				thedata[i] = other.thedata[i];
			}
			return *this;
		}
		/**
		 * assigns specified element with bounds checking
		 * throw index_out_of_bound if pos is not in [0, size)
		 */
		T& at(const size_t& pos) {
			if (pos < 0 || pos >= used_memory) throw index_out_of_bound();
			return thedata[pos];
		}
		const T& at(const size_t& pos) const {
			if (pos < 0 || pos >= used_memory) throw index_out_of_bound();
			return thedata[pos];
		}
		/**
		 * assigns specified element with bounds checking
		 * throw index_out_of_bound if pos is not in [0, size)
		 * !!! Pay attentions
		 *   In STL this operator does not check the boundary but I want you to do.
		 */
		T& operator[](const size_t& pos)
		{
			if (pos < 0 || pos >= used_memory) throw index_out_of_bound();
			return thedata[pos];
		}
		const T& operator[](const size_t& pos) const
		{
			if (pos < 0 || pos >= used_memory) throw index_out_of_bound();
			return thedata[pos];
		}
		/**
		 * access the first element.
		 * throw container_is_empty if size == 0
		 */
		const T& front() const
		{
			if (used_memory == 0) throw container_is_empty();
			return thedata[0];
		}
		/**
		 * access the last element.
		 * throw container_is_empty if size == 0
		 */
		const T& back() const
		{
			if (used_memory == 0) throw container_is_empty();
			return thedata[used_memory - 1];
		}
		/**
		 * returns an iterator to the beginning.
		 */
		iterator begin()
		{
			iterator temp(this, thedata);
			return temp;
		}
		const_iterator cbegin() const
		{
			const_iterator temp(this, thedata);
			return temp;
		}
		/**
		 * returns an iterator to the end.
		 */
		iterator end()
		{
			iterator temp(this, thedata + used_memory);
			return temp;
		}
		const_iterator cend() const
		{
			const_iterator temp(this, thedata + used_memory);
			return temp;
		}

		/**
		 * checks whether the container is empty
		 */
		bool empty() const
		{
			if (used_memory == 0) return true;
			else return false;
		}
		/**
		 * returns the number of elements
		 */
		size_t size() const { return used_memory; }
		/**
		 * clears the contents
		 */
		void clear()
		{
			if (used_memory > 0 || total_memory > 1)
			{
				for (size_t i = 0;i < used_memory;++i)
					thedata[i].~T();
				free(thedata);
				thedata = (T*)malloc(sizeof(T));
				memset(thedata, 0, sizeof(T));
				used_memory = 0;
				total_memory = 1;
			}
		}
		/**
		 * inserts value before pos
		 * returns an iterator pointing to the inserted value.
		 */
		iterator insert(iterator pos, const T& value)
		{
			if (used_memory == total_memory)
			{
				size_t distance = pos.i_p - thedata;
				doublespace();
				pos.i_p = thedata + distance;
			}
			T* temp = thedata + used_memory;
			while (temp > pos.i_p)
			{
				*temp = *(temp - 1);
				--temp;
			}
			*pos.i_p = value;
			used_memory++;
			return pos;
		}
		/**
		 * inserts value at index ind.
		 * after inserting, this->at(ind) == value
		 * returns an iterator pointing to the inserted value.
		 * throw index_out_of_bound if ind > size (in this situation ind can be size because after inserting the size will increase 1.)
		 */
		iterator insert(const size_t& ind, const T& value)
		{
			iterator iter;
			iter.i_p = thedata + ind;
			iter.thevector = this;
			if (ind > used_memory) throw index_out_of_bound();
			if (used_memory == total_memory)
			{
				doublespace();
			}
			size_t temp = used_memory;
			while (temp > ind)
			{
				thedata[temp] = thedata[temp - 1];
				--temp;
			}
			thedata[ind] = value;
			used_memory++;

			return iter;
		}

		/**
		 * removes the element at pos.
		 * return an iterator pointing to the following element.
		 * If the iterator pos refers the last element, the end() iterator is returned.
		 */
		iterator erase(iterator pos)
		{
			T* temp = pos.i_p;
			--used_memory;
			while (temp < thedata + used_memory)
			{
				*temp = *(temp + 1);
				temp++;
			}
			return pos;
		}
		/**
		 * removes the element with index ind.
		 * return an iterator pointing to the following element.
		 * throw index_out_of_bound if ind >= size
		 */
		iterator erase(const size_t& ind)
		{
			size_t temp = ind;
			--used_memory;
			while (temp < used_memory)
			{
				thedata[temp] = thedata[temp + 1];
				temp++;
				iterator iter;
				iter.i_p = thedata + ind;
				iter.thevector = this;
				return iter;
			}
		}
		/**
		 * adds an element to the end.
		 */
		void push_back(const T& value)
		{

			if (used_memory == total_memory) doublespace();
			thedata[used_memory++] = value;
		}
		/**
		 * remove the last element from the end.
		 * throw container_is_empty if size() == 0
		 */
		void pop_back()
		{
			if (used_memory == 0) throw container_is_empty();
			else --used_memory;
		}
	};

}

#endif