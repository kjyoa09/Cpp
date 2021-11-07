#include <iostream>

using namespace std;

// 구조체 정의
typedef struct Animal{
    char name[30];
    int age;

    int health;
    int food;
    int clean;
} Animal;

void create_animal(Animal * animal) {
    cout << "Name : " ;
    cin >> animal->name;

    cout << "age : ";
    cin >> animal->age;

    animal ->health = 100;
    animal ->food = 100;
    animal ->clean = 100; 
}

void play(Animal *animal){
    animal -> health +=10;
    animal -> food -=10;
    animal -> clean -=10;
}

void one_day_pass(Animal *animal){
    animal -> health -=10;
    animal -> food -=10;
    animal -> clean -=10;
}

void show_stat(Animal *animal){
    cout << animal->name << "`s stat" << endl;

    cout << "health : " << animal->health << "`s stat" << endl;
    cout << "food : " << animal->food << "`s stat" << endl;
    cout << "clean : " << animal->clean << "`s stat" << endl;
}

int main(){
    Animal *list[10];
    int animal_num = 0;

    for (;;){
        cout << "1.Create" << endl;
        cout << "2.play" << endl;
        cout << "3.stat" << endl;
    

        int input;
        cin >> input ;
        
        switch (input)
        {   int playwith;
            case 1 :
                list[animal_num] = new Animal;
                create_animal(list[animal_num]);
                animal_num ++;        
                break;

            case 2 :
                cout << "pal";
                cin >> playwith;
                if (playwith < animal_num){play(list[playwith]);}
                break;
            
            case 3:
                cout << "pal";
                cin >> playwith;
                if (playwith < animal_num){show_stat(list[playwith]);}
                break;

            for(int i = 0;i<animal_num;i++){
                one_day_pass(list[i]);
            }    
        }
    }
}