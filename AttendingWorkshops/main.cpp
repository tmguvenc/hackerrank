#include<bits/stdc++.h>

using namespace std;

#include <vector>
#include <algorithm>

struct Workshops{
    int start_time, duration, end_time;

//    Workshops(){}

    Workshops(int start, int dur) :
        start_time(start),
        duration(dur),
        end_time(start + dur) { }
};

struct Available_Workshops{
    vector<Workshops> workshops;
    int size;
};

Available_Workshops* initialize(int* start_times, int* durations, int n){

    auto availables = new Available_Workshops;

    for(int i = 0; i < n; ++i) {
        availables->workshops.push_back(Workshops(start_times[i], durations[i]));
    }

    return availables;
}

int CalculateMaxWorkshops(Available_Workshops* ptr){

    sort(ptr->workshops.begin(), ptr->workshops.end(), [](Workshops& w1, Workshops& w2){
         return w1.end_time < w2.end_time;
    });

    vector<Workshops> result;
    int current_end_time = 0;

    for(auto it = ptr->workshops.begin(); it != ptr->workshops.end(); ++it){
        if(it->start_time >= current_end_time){
            result.push_back(*it);
            current_end_time = it->end_time;
        }
    }

    return result.size();
}

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
