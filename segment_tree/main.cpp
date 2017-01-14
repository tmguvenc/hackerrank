#include <iostream>
#include <math.h>
#include <limits>

using namespace std;

/*
 * We have an array arr[0 . . . n-1]. We should be able to
 * Find the min of elements from index l to r where 0 <= l <= r <= n-1
*/

inline int closest(int v){
    v--;
    for(int i = 0; i < 5; ++i)
        v |= v >> (1<<i);
    v++;
    return v;
}

template<typename T>
class MinSegmentTree{
public:
    MinSegmentTree(int size) : m_size(size), m_tree_size(closest(size) * 2 - 1){
        m_arr = new T[m_tree_size];
    }
    MinSegmentTree(const std::initializer_list<T>& list) : MinSegmentTree(list.size()){
        construct(list.begin(), list.size());
    }

    ~MinSegmentTree(){
        if(m_arr){
            delete[] m_arr;
            m_arr = nullptr;
        }
    }

    void print(){
        for(int i = 0; i < m_tree_size; ++i){
            cout << m_arr[i] << " ";
        }
    }

    T query(int query_low, int query_high){
        return query_internal(query_low, query_high, 0, m_size - 1, 0);
    }

protected:

    T query_internal(int query_low, int query_high, int low, int high, int pos){

        // complete overlap
        if(query_low <= low && query_high >= high)
            return m_arr[pos];

        // no overlap
        if(query_low > high || query_high < low)
            return std::numeric_limits<T>::max();

        int middle = (low + high) / 2;

        return min(query_internal(query_low, query_high, low, middle, 2*pos + 1),
                    query_internal(query_low, query_high, middle + 1, high, 2*pos + 2));
    }

    void construct(const T arr[], int size){
        construct_internal(arr, 0, size - 1, 0);
    }

    void construct_internal(const T arr[], int low, int high, int pos){
        if(low == high){
            m_arr[pos] = arr[low];
            return;
        }
        int middle = (low + high) / 2;
        int left_index = 2*pos + 1;
        int right_index = left_index + 1;
        construct_internal(arr, low, middle, left_index);
        construct_internal(arr, middle + 1, high, right_index);
        m_arr[pos] = min(m_arr[left_index], m_arr[right_index]);
    }

private:
    int m_size, m_tree_size;
    T *m_arr;
};

int main(int argc, char *argv[])
{
    MinSegmentTree<int> tree({-1, 2, 4, 0, 5, -3, 10, 2, 4, 234, 342, 1, 3 ,4});
    cout << tree.query(5, 8) << endl;
    return 0;
}
