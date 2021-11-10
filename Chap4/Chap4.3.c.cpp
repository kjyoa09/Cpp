#include <string.h>
#include <iostream>

using namespace std;

class Photon_Cannon{
    int hp,shield;
    int coord_x,coord_y;
    int damage;

    char *name;
    public:
        Photon_Cannon(int x, int y);
        Photon_Cannon(int x, int y, const char *cannon_name);
        ~Photon_Cannon();
        void show_status();
};

// Copy constructor
// 다른 T 객체의 pc를 상수 레퍼런스로 받는다. >> &참조자이기 때문에 변경 불가 >> 복사만 가능
// 인자로 받는 변수의 내용을 함수 내부에서 바꾸지 않는다면 const 사용하는 것이 좋음.

Photon_Cannon::Photon_Cannon(int x, int y){
    // cout << "B" <<endl;
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;

    name = NULL;
}

Photon_Cannon::Photon_Cannon(int x, int y, const char *cannon_name){ 
    // cout << "A" << endl;

    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;

    name = new char[strlen(cannon_name) + 1];
    strcpy(name,cannon_name);
}

Photon_Cannon::~Photon_Cannon(){if (name) delete[] name;}

void Photon_Cannon::show_status(){
    cout << "Photon Canon :: " <<name <<endl;
    cout << "Location : ( " << coord_x << "," << coord_y << " ) " << endl;
    cout << "HP : " << hp << endl;
}

/*
Photon Canon :: Cannon
Location : ( 3,3 )
HP : 100
Photon Canon :: Cannon
Location : ( 3,3 )
HP : 100
Photon Canon :: 0
Location : ( 3,3 )
HP : 100
*/
int main(){
    Photon_Cannon pc1(3,3,"Cannon");
    Photon_Cannon pc2 = pc1;
    // Photon_Cannon pc2(pc1);
    // Photon_Cannon pc3(pc2) >> 복사생성자가 호출됨
    // pc3 = pc2 랑 같지 않음 >> 그냥 생성자 1번 호출 + pc3 = pc2 명령 실행
    // Photon_Cannon pc3 = pc2;

    pc1.show_status();
    pc2.show_status();
    pc1.~Photon_Cannon();
    pc2.show_status();
}