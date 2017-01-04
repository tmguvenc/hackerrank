#include <iostream>
#include <vector>
using namespace std;

class Spell {
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell {
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell {
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell {
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
};
string SpellJournal::journal = "";

void counterspell(Spell *spell) {
    /* Enter your code here */
       if(spell->revealScrollName().empty()){

           auto fire = dynamic_cast<Fireball*>(spell);
           auto water = dynamic_cast<Waterbolt*>(spell);
           auto frost = dynamic_cast<Frostbite*>(spell);
           auto thunder = dynamic_cast<Thunderstorm*>(spell);

           if(fire){
               fire->revealFirepower();
           }
           else if(water){
               water->revealWaterpower();
           }
           else if(frost){
               frost->revealFrostpower();
           }
           else if(thunder){
               thunder->revealThunderpower();
           }
       }else{

           auto sj = SpellJournal::read();
           auto sn = spell->revealScrollName();

           auto sj_size = sj.size();
           auto sn_size = sn.size();

           int **arr = new int*[sj_size + 1];

           for(int i = 0; i < sj_size + 1; ++i){

               arr[i] = new int[sn_size + 1];

               for(int j = 0; j < sn_size + 1; ++j){
                   arr[i][j] = 0;
               }
           }

           for(int i = 0; i < sj_size; ++i){
               for(int j = 0; j < sn_size; ++j){

                   if(sj[i] == sn[j]){
                       arr[i + 1][j + 1] = arr[i][j] + 1;
                   }
                   else{
                       arr[i + 1][j + 1] = arr[i][j + 1] > arr[i + 1][j] ? arr[i][j + 1] : arr[i + 1][j];
                   }
               }
           }

           cout << arr[sj_size][sn_size] << endl;

           for(int i = 0; i < sj_size + 1; ++i){
               delete [] arr[i];
           }

           delete [] arr;
       }
}
class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            }
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}
