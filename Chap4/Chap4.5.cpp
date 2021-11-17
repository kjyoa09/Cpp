# include <iostream>

using namespace std;

class Mystring{
    char* string_contents; // 문자열 Pointer
    int string_length; // 문자열 길이
    int memory_capacity; // 메모리 용량

    public:
        Mystring(char str);
        Mystring(const char* str);
        Mystring(const Mystring& str);
        ~Mystring();

        int length() const;
        int capacity() const;

        void print(bool with_line) const;

        void assign(const Mystring& str);
        void assign(const char* str);

        void concat(const Mystring& str);
        void concat(char str);
        void concat(const char* str);
};

Mystring::Mystring(char str){
    string_length = 1;
    string_contents = new char[1];
    string_contents[0] = str;
    memory_capacity = string_length;
}


Mystring::Mystring(const char* str){
    string_length = 0;
    while(str[string_length] != '\0'){
        string_length ++;
    }
    memory_capacity = string_length;
    string_contents = new char[string_length];
    for (int i = 0; i < string_length ; i++){string_contents[i] = str[i];}
}


Mystring::Mystring(const Mystring& str){
    string_length = str.string_length;
    for (int i = 0; i != string_length; i++){string_contents[i] = str.string_contents[i];}
}


Mystring::~Mystring() {delete [] string_contents;}

int Mystring::length() const{return string_length;}
int Mystring::capacity() const{return memory_capacity;}

void Mystring::print(bool with_line = true) const{
    for (int i = 0; i != string_length; i++){cout << string_contents[i];}
    if (with_line){cout << '\n';}
}


void Mystring::assign(const Mystring& str){
    if (str.string_length > string_length){
        delete[] string_contents;
        string_contents = new char[str.string_length];

        for (int i)
    }
}


int main(){
    Mystring A("AAAAA");
    cout << A.length() << endl;
    A.print(false);
    A.print();

    return 0;
}