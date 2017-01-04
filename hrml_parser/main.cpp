#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <assert.h>
#include <map>
#include <sstream>

using namespace std;

struct Tag{
    string name;
    map<string, string> attr;
    map<string, Tag> children;
    Tag* parent;

    Tag() : parent(nullptr)
    { }

    Tag(Tag&& other) :
        name(std::move(other.name)),
        attr(std::move(other.attr)),
        children(std::move(other.children)),
        parent(std::move(other.parent)) {

    }

    Tag& operator =(Tag&& other){
        this->attr = std::move(other.attr);
        this->name = std::move(other.name);
        this->children = std::move(other.children);
        this->parent = std::move(other.parent);
        return *this;
    }

private:
    Tag(const Tag& other);
    Tag& operator =(const Tag& other);
};

inline vector<string> split(const std::string& str, char delim){
    stringstream stream(str);
    string word;
    vector<string> words;

    while(std::getline(stream, word, delim)){
        words.push_back(word);
    }

    return words;
}

inline vector<string> get_words(std::string line){
    auto aa = std::remove_if(line.begin(), line.end(), [](char c){
        return c == '<' || c == '>' || c == '\"';
    });

    line.erase(aa, line.end());

    return split(line, ' ');
}

inline string getWord(string line, int startIndex){
    int a = startIndex;

    while(line[++a] != ' ' && line[a] != '>');

    return line.substr(startIndex, a - 1);
}

inline Tag getTagWithAttributes(const std::vector<std::string>& words){

    Tag newTag;

    for(std::vector<std::string>::size_type i = 1; i < words.size(); ++i){
        if(words[i] == "="){
            newTag.attr[words[i - 1]] = words[i + 1];
        }
    }

    return newTag;
}

class HRMLParser{
public:

    void parse(const vector<string>& script_lines){

        vector<string>::size_type counter = 0;

        Tag *current_parent = nullptr;
        string current_parent_name;

        do{
            auto words = std::move(get_words(script_lines[counter]));

            auto& name = words[0];

            if(name[0] != '/'){
                // it is a nested tag
                if(counter > 0 && current_parent != nullptr){
                    current_parent->children[name] = move(getTagWithAttributes(words));
                    current_parent->children[name].parent = current_parent;
                    current_parent = &current_parent->children[name];
                    current_parent_name = name;
                }
                else{
                    tags[name] = move(getTagWithAttributes(words));
                    current_parent = &tags[name];
                    current_parent_name = name;
                }
            }else{
                name = name.substr(1);

                if(current_parent != nullptr){
                    current_parent = current_parent->parent;
                }else{
                    current_parent = tags[name].parent;
                }
                current_parent_name = current_parent ? current_parent->name : "";
            }

        }while(++counter < script_lines.size());
    }

    void execute(const vector<string>& queries){

        for(auto query : queries){

            Tag *tag = nullptr;
            while(!query.empty()){

                auto dot_index = query.find_first_of('.');

                if(dot_index == string::npos) {
                    auto tilde_index = query.find_last_of('~');

                    auto inner_name = query.substr(0, tilde_index);

                    if(tag == nullptr){
                        tag = &tags[inner_name];
                    }else{
                        tag = &tag->children[inner_name];
                    }

                    auto attr_name = query.substr(tilde_index + 1);

                    auto att = tag->attr.find(attr_name);

                    if(att == tag->attr.end()){
                        cout << "Not Found!" << endl;
                    }else{
                        cout << att->second << endl;
                    }

                    query.clear();
                }

                auto name = query.substr(0, dot_index);

                if(tag == nullptr)
                    tag = &tags[name];
                else
                    tag = &tag->children[name];

                query = query.substr(dot_index + 1);
            }
        }
    }

private:
    map<string, Tag> tags;
};

int main() {

    int line_count, query_count;

    cin >> line_count >> query_count;

    string aa;
    std::getline(cin, aa);

    vector<string> lines, queries;

    for(int i = 0; i < line_count; ++i){
        string line;
        std::getline(cin, line);
        lines.push_back(line);
    }
    for(int i = 0; i < query_count; ++i){
        string line;
        std::getline(cin, line);
        queries.push_back(line);
    }

    HRMLParser parser;

    parser.parse(lines);

    parser.execute(queries);
    // auto words = get_words(line);

    // getAttributes(line);

    return 0;
}
