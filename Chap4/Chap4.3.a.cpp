#include <string.h>
#include <iostream>

using namespace std;

class Marine{
    int hp;
    int coord_x,coord_y;
    int damage;
    bool is_dead;
    char* name;

    public:
        Marine();
        Marine(int x, int y, const char* marine_name);
        Marine(int x, int y);
        ~Marine();

        int attack();
        void be_attacked(int damage_earn);
        void move(int x, int y);

        void show_status();
};

Marine::Marine(){
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;
    name = NULL;
}
Marine::Marine(int x, int y, const char* marine_name){
    name = new char[strlen(marine_name) + 1]; // > 직접 delete 해줘야함  >> marine이 죽어서 delete 될 때, 같이 안사라짐. >> 소멸자(Destructor) 생성해야함.
    strcpy(name,marine_name);
    hp = 50;
    coord_x = x;
    coord_y = y;
    damage = 5;
    is_dead = false;

}
void Marine::move(int x, int y){
    coord_x = x;
    coord_y = y;
}
int Marine::attack(){return damage;}
void Marine::be_attacked(int damage_eran){
    hp -= damage_eran;
    if (hp <=0 ){is_dead = true;}
}
void Marine::show_status(){
    cout << "*** Marine : ***" << name << endl;
    cout << "Location : ( " <<coord_x << ", " << coord_y << " )" << endl;
    cout << " HP : " << hp << endl;
}
Marine::~Marine(){ // 생성자가 Class 이름과 같다면 ~만 붙여주면 됨.
    cout << name << " Destructor" << endl;
    if (name != NULL){
        delete[] name;
    }
}

// int main(){
//     Marine marine1(2,3);
//     Marine marine2(3,5);

//     marine1.show_status();
//     marine2.show_status();

//     marine2.be_attacked(marine1.attack());

//     marine1.show_status();
//     marine2.show_status();

// }

int main(){
    Marine* marines[100];

    marines[0] = new Marine(2,3, "Marine 2"); // > new는  동시에 생성자도 호출.
    marines[1] = new Marine(3,5, "Marine 1");

    marines[0] -> show_status(); // marines[0].show_status() 는 안됨. pointer 라
    marines[1] -> show_status();

    marines[0] -> be_attacked(marines[1] -> attack());

    marines[0] -> show_status();
    marines[1] -> show_status();

    delete marines[0];
    delete marines[1];

    return 0;
}