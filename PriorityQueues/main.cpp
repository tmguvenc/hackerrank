#include <iostream>
#include <sstream>

using namespace std;

template<typename T, typename Comp>
class PriorityQueue{
public:
    PriorityQueue(int max_size) :
        m_max_size(max_size),
        N(0),
        m_arr(new T[m_max_size])
    {
    }

    PriorityQueue(const std::initializer_list<int>& list){
        using size_type = std::initializer_list<int>::size_type;
        size_type size = list.size();
        m_arr = new T[size];
        N = size-1;
        m_max_size = size;
        std::copy(list.begin(), list.end(), m_arr);
        for(size_type i = size / 2; i > 0; --i){
            sink(i);
        }
    }

    ~PriorityQueue(){
        if(m_arr){
            delete[] m_arr;
            m_arr = nullptr;
        }
    }

    void push(const T& item){
        m_arr[++N] = item;
        swim(N);
    }

    const T& top(){
        return m_arr[1];
    }

    void pop(){
        exch(1, N--);
        sink(1);
    }

    bool empty(){
        return N == 0;
    }

private:
    void sink(int k){
        while(2*k <= N){
            int j = 2*k;
            if(j < N && comparator(m_arr[j], m_arr[j+1]))
                j++;
            if(!comparator(m_arr[k], m_arr[j]))
                break;
            exch(k, j);
            k = j;
        }
    }
    void swim(int k){
        while(k > 1 && comparator(m_arr[k/2], m_arr[k])){
            exch(k, k/2);
            k = k/2;
        }
    }

    void exch(int i, int j){
        T temp = m_arr[i];
        m_arr[i] = m_arr[j];
        m_arr[j] = temp;
    }

private:
    T *m_arr;
    int m_max_size;
    int N;
    Comp comparator;
};

int main(int argc, char *argv[])
{
//    using CharMaxPQ = PriorityQueue<char, less<char>>;
//    using CharMinPQ = PriorityQueue<char, greater<char>>;
    using IntMinPQ = PriorityQueue<int, greater<int>>;
//    CharMaxPQ max_queue(1000);
//    CharMinPQ min_queue(1000);

//    stringstream ss;
//    string line;

//    while(std::getline(std::cin, line)){
//        ss << line;
//    }

//    const auto str = ss.str();

//    cout << str << endl << endl;

//    for(auto c : str){
//        if(c == ' ') continue;
//        max_queue.push(c);
//        min_queue.push(c);
//    }

//    cout << "Descending: \t";
//    while(!max_queue.empty()){
//        cout << max_queue.top();
//        max_queue.pop();
//    }

//    cout << endl << "Ascending: \t";

//    while(!min_queue.empty()){
//        cout << min_queue.top();
//        min_queue.pop();
//    }

    cout << endl << "Constructed: \t";

    IntMinPQ queue({3,4,2,3,5,1,43,53,45,1,1,423,5,6,2,9,8,6});

    while(!queue.empty()){
        cout << queue.top() << " ";
        queue.pop();
    }

    cout << endl;
    return 0;
}
