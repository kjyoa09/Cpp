# include <iostream>
# include <cstring>

// class string{
//     char* str;
//     int length;

//     public:
//         string(char c);
//         string(const char* c);
//         string(const string& c);

// };

// string::string(char c){
//     str = new char[1];
//     str[0] = c;
//     length = 1;
// }

// string::string(const char* c){
//     length = strlen(c);
//     str = new char[length];
//     for (int i = 0;i<length;i++){str[i] = c[i];}
// }

// string::string(const string& c){
//     length = c.length;
//     for (int i = 0; i < c.length; i ++){str[i] = c.str[i];}
// }

// string::~string(){delete[] str;}

int main(){
    const char* a = "aaaaa";
    int i = 0;
    while (i<8){
        if (a[i]){
            std::cout << "A" << std::endl;
            std::cout << a[i] << std::endl;
        }
        i++;
    }

    std::cout << a << std::endl;
}