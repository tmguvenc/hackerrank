#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> getDirectFriendsForUser(string user){
    return vector<string>();
}

vector<string> getAttendedCoursesForUser(string user){
    return vector<string>();
}

void MyFunc(const string& friend_name, map<string, int>& my_map, map<string, int>& rec_map){
    for(const auto& my_friends_course : getAttendedCoursesForUser(friend_name)){
        // if I did not take this course
        if(my_map.find(my_friends_course) == my_map.end()){
            auto found_rec_course = rec_map.find(my_friends_course);
            if(found_rec_course == rec_map.end()){
                rec_map[my_friends_course] = 1;
            }else{
                rec_map[my_friends_course]++;
            }
        }
    }
}

vector<string> getRankedCourses(string user) {
    vector<string> courses;

    map<string, int> my_course_map;
    map<string, int> rec_course_map;

    // get my courses
    for(const auto& course : getAttendedCoursesForUser(user)){
        my_course_map[course] = 1;
    }

    for(const auto& my_friend : getDirectFriendsForUser(user)){
        MyFunc(my_friend, my_course_map, rec_course_map);
        for(const auto& my_friens_friend : getDirectFriendsForUser(my_friend)){
            MyFunc(my_friens_friend, my_course_map, rec_course_map);
        }
    }

    sort(rec_course_map.begin(), rec_course_map.end(), [](map<string, int>::value_type p1, map<string, int>::value_type p2){
            return p1.second > p2.second;
        });

    for(auto it = rec_course_map.begin(); it != rec_course_map.end(); ++it ) {
        courses.push_back( it->first );
    }

    return courses;
}

int main() {

    getRankedCourses("murat");

}
