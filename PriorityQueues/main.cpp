#include <iostream>

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
            if(j < N && comperator(m_arr[j], m_arr[j+1]))
                j++;
            if(!comperator(m_arr[k], m_arr[j]))
                break;
            exch(k, j);
            k = j;
        }
    }
    void swim(int k){
        while(k > 1 && comperator(m_arr[k/2], m_arr[k])){
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
    Comp comperator;
};

int main(int argc, char *argv[])
{
    using MaxPQ = PriorityQueue<char, less<char>>;
    using MinPQ = PriorityQueue<char, greater<char>>;
    MaxPQ queue(100);

    for(auto c : "Turan Murat Guvenc")
        queue.push(c);

    while(!queue.empty()){
        cout << queue.top();
        queue.pop();
    }

    cout<<endl;
    return 0;
}
