#include <iostream>
template <typename T>
struct vector {
    private:
        T* m_arr = nullptr;
        size_t m_size;
        size_t m_capacity;
    private:
        void recap(size_t new_capacity) {
            if (m_size == m_capacity) {
                T* tmp = new T[new_capacity];
                for (size_t i = 0; i < m_size; ++i) {
                    tmp[i] = m_arr[i];
                }
                delete [] m_arr;
                m_arr = tmp;
                m_capacity = new_capacity;
            }
        }
    public:
        void init(size_t size) {
            if (m_arr != nullptr){
                delete [] m_arr;
                m_arr = nullptr;
            }
            m_arr = new T[size];
            m_capacity = size * 2;
            m_size = size;
        }
    public:
        void init(size_t size, const T& val){
            init(size);
            for (size_t i = 0; i < size; ++i) {
                m_arr[i] = val;
            }
        }
    public:
        void clear() {
            if (m_arr != nullptr) {
                delete [] m_arr;
                m_arr = nullptr;
            }
            m_size = 0;
            m_capacity = 0;
        }
    public:
        void resize(size_t size, const T& val) {
            if (size < m_size) {
                m_size = size;
            } else {
                recap(size);
            for (size_t i = m_size; i < size; ++i) {
                m_arr[i] = val;
            }
            m_size = size;
            }
        }
    public:
        void push_back(const T& val) {
            recap(m_capacity * 2);
            m_arr[m_size] = val;
            ++m_size;
        }
        void pop_back(){
            if (m_size != 0) {
                --m_size;
            }
        }
    public:
        void insert(size_t index, const T& val){
            recap(m_size);
            ++m_size;
            for (size_t i = m_size - 1; i > index; --i){
                m_arr[i] = m_arr[i - 1];
                m_arr[index] = val;
            }
        }
        void erase(size_t index) {
            for (size_t i = index; i < m_size - 1; ++i) {
                m_arr[i] = m_arr[i + 1];
            }
            --m_size;
        }
    public:
        T& at(size_t index) {
            if (index < m_size) {
                return m_arr[index];
            }
        throw 1;
        }
        T& front() {
            if (m_size > 0) {
                return m_arr[0];
            }
            throw 1;
        }
        T& back() {
            if (m_size > 0) {
                return m_arr[m_size - 1];
            }
        throw 1;
        }
    public:
        bool empty() {
            return !m_size;
        }
        size_t size(){
            return m_size;
        }
        size_t capacity() {
            return m_capacity;
        }
};
int main() {
  int size = 6;
  vector<int> ob;
  ob.init(size);
return 0;
}
