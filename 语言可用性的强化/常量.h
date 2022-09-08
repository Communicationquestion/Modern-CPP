#pragma once
#include <iostream>
#include <type_traits>

void foo(char*) {
    std::cout << "foo(char*) is called" << std::endl;
}
void foo(int i) {
    std::cout << "foo(int) is called" << std::endl;
}

void constex()
{
    if (std::is_same<decltype(NULL), decltype(0)>::value)
        std::cout << "NULL == 0" << std::endl;
    if (std::is_same<decltype(NULL), decltype((void*)0)>::value)
        std::cout << "NULL == (void *)0" << std::endl;
    if (std::is_same<decltype(NULL), std::nullptr_t>::value)
        std::cout << "NULL == nullptr" << std::endl;

    foo(0);          // 调用 foo(int)
    // foo(NULL);    // 该行不能通过编译
    foo(nullptr);    // 调用 foo(char*)
}



#include <iostream>
#define LEN 10

int len_foo() {
    int i = 2;
    return i;
}
constexpr int len_foo_constexpr() {
    return 5;
}

constexpr int fibonacci(const int n) {
    return n == 1 || n == 2 ? 1 : fibonacci(n - 1) + fibonacci(n - 2);
}

int constexprEX() {
    char arr_1[10];                      // 合法
    char arr_2[LEN];                     // 合法

    int len = 10;
    // char arr_3[len];                  // 非法

    const int len_2 = len + 1;
    constexpr int len_2_constexpr = 1 + 2 + 3;
    // char arr_4[len_2];                // 非法
    char arr_4[len_2_constexpr];         // 合法

    // char arr_5[len_foo()+5];          // 非法
    char arr_6[len_foo_constexpr() + 1]; // 合法

    std::cout << fibonacci(10) << std::endl;
    // 1, 1, 2, 3, 5, 8, 13, 21, 34, 55
    std::cout << fibonacci(10) << std::endl;
    return 0;
}

#include <vector>
#include <algorithm>
#include<string>
template<typename T>
class if_switch {

public :
    if_switch() {};
    if_switch(T vec) {
        this->vec = vec;
    }

    void out() {
        for (typename T::iterator element = vec.begin(); element != vec.end(); ++element) {
            std::cout << *element << std::endl;
        }
            
    }
    
    void findex() {
        // 将临时变量放到 if 语句内
        if (const typename T::iterator itr = std::find(vec.begin(), vec.end(), 3);
            itr != vec.end()) {
            *itr = 4;
        }
    }


private: 
    T vec;
};

class Foo {
public:
    int value_a;
    int value_b;
    Foo(int a, int b) : value_a(a), value_b(b) {}

    int Ecfoo() {
        // before C++11
        int arr[3] = { 1, 2, 3 };
      
        std::vector<int> vec = { 1, 2, 3, 4, 5 };

        std::cout << "arr[0]: " << arr[0] << std::endl;
        std::cout << "foo:" << value_a << ", " << value_b << std::endl;
        for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
            std::cout << *it << std::endl;
        }
        return 0;
    }
};


#include <initializer_list>

class MagicFoo {
public:

    void foo(std::initializer_list<int> list) {
        for (std::initializer_list<int>::iterator it = list.begin();
            it != list.end(); ++it) vec.push_back(*it);
    }
    std::vector<int> vec;
    MagicFoo(std::initializer_list<int> list) {
        for (std::initializer_list<int>::iterator it = list.begin();
            it != list.end(); ++it)
            vec.push_back(*it);
    }
    void out() {
        std::cout << "magicFoo: " << std::endl;
        for (std::vector<int>::iterator it = vec.begin();
            it != vec.end(); ++it)
            std::cout << *it << std::endl;
    }

};


#include <tuple>
class tupleex {
public:   
    tupleex() {};
    std::tuple<int, double, std::string> f() {
        return std::make_tuple(1, 2.3, "456");
    }





};

class dec {
public:
    dec() {};
    decltype(auto) look_up_a_string_1() {
        return lookup1();
    }
    decltype(auto) look_up_a_string_2() {
        return lookup2();
    }
private:
    std::string  lookup1();
    std::string& lookup2();
};

template<typename T>
class p {
public:
    p() {};
  
    auto print_type_info(const T& t) {
        if constexpr (std::is_integral<T>::value) {
            return t + 1;
        }
        else {
            return t + 0.001;
        }
    }

};

template<typename... Ts>
void magic(Ts... args) {
    std::cout << sizeof...(args) << std::endl;
}

template<typename T0>
void printf1(T0 value) {
    std::cout << value << std::endl;
}
template<typename T, typename... Ts>
void printf1(T value, Ts... args) {
    std::cout << value << std::endl;
    printf1(args...);
}

template<typename T0, typename... T>
void printf2(T0 t0, T... t) {
    std::cout << t0 << std::endl;
    if constexpr (sizeof...(t) > 0) printf2(t...);
}

template<typename T, typename... Ts>
auto printf3(T value, Ts... args) {
    std::cout << value << std::endl;
    (void)std::initializer_list<T>{([&args] {
        std::cout << args << std::endl;
        }(), value)...};
}

#include <memory>
#include<utility>

void lambda_expression_capture() {
	auto important = std::make_unique<int>(1);
	auto add = [v1 = 1, v2 = std::move(important)](int x, int y) -> int {
		return x + y + v1 + (*v2);
	};
	std::cout << add(3, 4) << std::endl;
}