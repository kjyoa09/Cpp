#include <iostream>

using namespace std;
class Marine{
    /*
    static 변수 & static 함수 
    클래스의 모든 객체들이 공유하는 변수 >> 각 객체별로 따로 존재하는 맴버 변수들과는 달리 '하나의' static 맴버 변수 공유
    */
    static int total_marine_num;
    // static int total_marine_num = 0;은 안됨
    const static int i = 0;
    int hp;
    int coord_x, coord_y;
    // int damage;
    
    bool is_dead;
    const int default_damage;
    
    public:
        Marine();
        Marine(int x, int y);
        Marine(int coord_x, int coord_y, int default_damage);
        int attack() const;
        // void be_attacked(int damage_earn);
        Marine& be_attacked(int damage_earn);
        void move(int x, int y);

        void show_status();
        static void show_total_marine();
        ~Marine() { total_marine_num--; }
};

/*
모든 전역 및 static 변수들은 정의하지 않아도 동시에 값이 자동으로 0으로 초기화됨
다만 Class내 static의 경우 초기화 해야함.
*/
int Marine::total_marine_num = 0;
void Marine::show_total_marine(){cout << "Total numeber of marine : " << total_marine_num << endl;}

/* 
초기화 리스트(initializer list) >> 생성자 호출과 동시에 맴버 변수 초기화.

따라서 생성과 동시에 초기화 되어야하는 것 EX. 래퍼런스와 상수 들은 초기화 리스트로 선언해야함.

*/
Marine::Marine() : hp(50),coord_x(0),coord_y(0),default_damage(5),is_dead(false){total_marine_num++;}

Marine::Marine(int coord_x, int coord_y): hp(50),coord_x(coord_x),coord_y(coord_y),default_damage(5),is_dead(false){total_marine_num++;}

Marine::Marine(int coord_x, int coord_y, int default_damage): hp(50),coord_x(coord_x),coord_y(coord_y),default_damage(default_damage),is_dead(false){total_marine_num++;}

/*

이렇게 선언하는 것은 생성을 먼저 하고 이후 대입함. >>
Marine::Marine(int coord_x, int coord_y){
    coord_x = coord_x;
    coord_y = coord_y;
    hp = 50;
    default_damage = 5; 'const int Marine::default_damage' should be initialized
    is_dead = false;
} 


*** Marine ***
 Location : ( 1978429229 , 4201392 )
 HP : 50
*** Marine ***
 Location : ( 6422476 , 1978453184 )
 HP : 50

*/

void Marine::move(int x, int y){
    coord_x = x;
    coord_y = y;
}

int Marine::attack() const {return default_damage;}

// void Marine::be_attacked(int damage_earn){
//     hp -= damage_earn;
//     if (hp <= 0){is_dead = true;}
// }

Marine& Marine::be_attacked(int damage_earn){
    hp -= damage_earn;
    if (hp <= 0){is_dead = true;}
    return *this; // 객체 자신을 가리키는 포인터 역할. >> 맴버 함수를 호출하는 객체 자신을 가리킴..
}

void Marine::show_status(){
    cout << "*** Marine ***" << endl;
    cout << " Location : ( " << coord_x <<" , " << coord_y << " )" << endl;
    cout << " HP : " << hp << endl;
    cout << " Number of marine : " << total_marine_num << endl;
}

void create_marine(){
    Marine marine3(10,10,4);
    Marine::show_total_marine();
    // marine3.show_status();
}
/*


*** Marine ***
 Location : ( 2 , 3 )
 HP : 50
 Number of marine : 1
*** Marine ***
 Location : ( 3 , 5 )
 HP : 50
 Number of marine : 2
*** Marine ***
 Location : ( 10 , 10 )
 HP : 50
 Number of marine : 3
*** Marine ***
 Location : ( 2 , 3 )
 HP : 50
 Number of marine : 2 >> Marine 3 클래스 종료시 사라져서 2임.
*** Marine ***
 Location : ( 3 , 5 )
 HP : 45
 Number of marine : 2 >> Marine 3 클래스 종료시 사라져서 2임.

 */
int main(){
    Marine marine1(2,3,5);
    marine1.show_status();
    // Marine::show_total_marine(); // 어떤 객체도 static 함수를 보유하지 않음으로 ::로 호출.
    Marine marine2(3,5,10);
    marine2.show_status();
    // Marine::show_total_marine();

    // create_marine();

    marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());
    marine1.show_status();
    marine2.show_status();

}