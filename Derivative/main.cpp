#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

template<typename T>
struct Term{
    int degree;
    T coeff;
};

using IntTerm = Term<int>;
using FloatTerm = Term<float>;

static inline IntTerm deriv(const IntTerm& term){
    return {term.degree - 1, term.coeff * term.degree};
}

class Polynomial{
public:
    Polynomial() : c(0){

    }

    Polynomial(const vector<IntTerm>& terms, int c = 0) :
        terms(move(terms)),
        c(c)
    {

    }

    Polynomial derivative(){
        Polynomial p;
        for(const auto& term : terms)
            p = p + deriv(term);
        return p;
    }

    string toString(){
        stringstream ss;

        for(int i = 0; i < terms.size() - 1; ++i){
            ss << terms[i].coeff;
            if(terms[i].degree >= 1)
                ss << "X";
            if(terms[i].degree > 1)
                ss << "^" << terms[i].degree;
            if(i < terms.size() - 1){
                ss << ((terms[i].coeff > 0) ? "+" : "");
            }
        }
        ss << terms.back().coeff;
        if(terms.back().degree >= 1)
            ss << "X";
        if(terms.back().degree > 1)
            ss << "^" << terms.back().degree;
        if(c){
            ss << ((c > 0) ? "+" : "") << c;
        }

        return ss.str();
    }

    Polynomial& operator +(const IntTerm& term){
        if(term.degree > 0)
            this->terms.push_back(term);
        else
            this->c += term.coeff;
        return *this;
    }

    Polynomial& operator +(int c){
        this->c += c;
        return *this;
    }

private:
    vector<IntTerm> terms;
    int c;
};

int main(int argc, char *argv[])
{
    Polynomial p({{4,3},{2,6}}, 3);
    cout << p.toString() << endl;
    cout << p.derivative().toString() << endl;
    cout << p.derivative().derivative().toString() << endl;
    cout << p.derivative().derivative().derivative().toString() << endl;
    return 0;
}
