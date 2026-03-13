#include <iostream>
#include <string>

using namespace std;

class creature
{
    private:
        int health ;
        int originalhealth ;
        int  maxdamage;
        string name ;

    public:
        creature(int health,int maxdamage,string name)
        {
            this->health = health;
            this->maxdamage = maxdamage;
            this->name = name;
            this->originalhealth = health;
        }

        void takedamage(int damage_taken)
        {
            this->health = this->health - damage_taken;
            cout << this->name << " took " << damage_taken << " pts of damage" << endl;
            if(health <= 0)
            {
                health = 0;
                cout << "you cant damage him more, hes dead" << endl;
            }
        }
        int givedamage()
        {
            if(health <= 0)
            {
                health = 0;
                cout << "he cant give damage, hes dead" << endl;
                return 0;
            }
            if(health > (3/4 * originalhealth))
            {
                return maxdamage;
            }
            else if(health > (1/2 * originalhealth))
            {
                return 3/4 * maxdamage;
            }
            else if(health > (1/4 * originalhealth))
            {
                return 1/2 * maxdamage;
            }  
            else
                return 1/4 * maxdamage;  
        }
        void showstats()
        {
            cout << this->name << " health:  " << this->health  << endl;
        }



};
int main()
{
    creature x(100,50,"monster");
    creature y(150,50,"zombie");

    x.showstats();
    y.showstats();

    
    x.takedamage(y.givedamage());
    y.takedamage(x.givedamage());
    y.takedamage(x.givedamage());
    x.takedamage(y.givedamage());

    x.showstats();
    y.showstats();

    return 0;
}