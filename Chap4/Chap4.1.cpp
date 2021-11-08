# include<iostream>
using namespace std ;
class Animal{
    private: // 자기 객체 안에서만 접근 가능 >> 외부에서는 불가능
        int food; // 맴버 변수
        int weight;// 맴버 변수
    
    public:// 외부에서도 접근 가능.
    
        void set_animal(int _food, int _weight){// 맴버 함수
            food = _food;
            weight = _weight;
        }
        
        void increase_food(int inc){
            food += inc;
            weight += (inc/3);
        }

        void view_stat(){
            cout << "이 동물의 food : " << food << endl;
            cout << "이 동물의 weight : " << weight << endl; 
        }
};

int main(){
    Animal animal;
    animal.set_animal(100,50);
    animal.increase_food(30);

    animal.view_stat();
    return 0;
}