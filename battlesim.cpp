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
        int ptshealth = 3;


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
            if(health > (0.75 * originalhealth))
            {
                return maxdamage;
            }
            else if(health > (0.5 * originalhealth))
            {
                return 0.75 * maxdamage;
            }
            else if(health > (0.25 * originalhealth))
            {
                return 0.5 * maxdamage;
            }  
            else
                return 0.25 * maxdamage;  
        }
        void showstats()
        {
            cout << this->name << " health:  " << this->health  << endl;
        }
        int health_getter()
        {
            return this->health;
        }
        void healing()
        {
            if(ptshealth == 0)
            {
                cout << "you do not have anymore pts of healing" << endl;
                return ;
            }
            health = health + 10 ;
            cout <<  this->name  << "restored 10 pts of health" << endl;
            ptshealth = ptshealth - 1;
            

        }
        int specialattack()
        {
            return maxdamage * 3;
        }
        
};
int main()
{
    cout << " welcome , give use ur name" << endl;
    string name ;

    cin >> name;

    creature x(100,50,name);
    
    creature y(150,50,"zombie");

    string str = "";
    
    //cin >> str;


    int i = 0;
    while(1)
    {
            cout << "player Menu" << endl;
        cout << " choose : attack 1 , heal 2 , special attack 3 ,quit 4" << endl;
        cin >> str;

        if(str == "1")
        {
             y.takedamage(x.givedamage());
        }
        if(str == "2")
        {
            x.healing();
        }
        if(str == "4")
        {
            break;
        }
        if(str == "3")
        {
            if(i >= 2)
            {
                 y.takedamage(x.specialattack());
                 i = 0;

            }
            else 
            {

                cout << "you are not fully recharged" << endl;
                continue;
            }
                
        }


        x.takedamage(y.givedamage());
        

        if( x.health_getter() == 0 || y.health_getter() == 0)
        {
            cout <<" game over " << endl;
            break;
            
        }
        x.showstats();
        y.showstats();
        i++;
    }
    



    return 0;
}