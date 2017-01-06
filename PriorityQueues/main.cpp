#include <iostream>
#include <sstream>

using namespace std;

template<typename T, typename Comp>
class PriorityQueue{
public:
    PriorityQueue(int max_size) :
        m_max_size(max_size),
        N(0)
    {
        m_arr = new T[m_max_size];
    }
    ~PriorityQueue(){
        delete[] m_arr;
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
    using MaxPQ = PriorityQueue<char, less<char>>;
    using MinPQ = PriorityQueue<char, greater<char>>;
    MaxPQ max_queue(1000);
    MinPQ min_queue(1000);

    stringstream ss;
    string line;

    while(std::getline(std::cin, line)){
        ss << line;
    }

    const auto str = ss.str();

    cout << str << endl << endl;

    for(auto c : str){
        if(c == ' ') continue;
        max_queue.push(c);
        min_queue.push(c);
    }

    cout << "Descending: \t";
    while(!max_queue.empty()){
        cout << max_queue.top();
        max_queue.pop();
    }

    cout << endl << "Ascending: \t";

    while(!min_queue.empty()){
        cout << min_queue.top();
        min_queue.pop();
    }

    cout << endl;
    return 0;
}
