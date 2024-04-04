#include <iostream>
#include <string>
#include <vector>

template <typename E> void print(std::vector<E> v){
    for (auto kv : v){ //can use E instead of auto
        std:: cout << kv << " ";
    }
    std::cout << std::endl;
}

int main (){

std::vector<int> v(5, 0);
std::vector<std::string> w(5, "Hello");

print(w);

v.push_back(10); // 0(1)
v.push_back(12);
v.push_back(44);
v.at(0) = 5; // 0(1)

std::cout<< v.at(7)<< std:: endl;
std::cout << v[7] << std::endl;
print(v);

std::vector<int>:: iterator iter= v.begin();
std::vector<int>:: iterator end = v.end();
std::cout << "iter: " << *iter << std::endl;

//while (iter != v.end){
//    std::cout << *iter << " ";
//    iter++;
//}
std::cout<< std::endl;

v.insert(v.begin(),10);
v.insert(v.begin()+3,69); // 0(n)

//std::sort(v.begin(),v.end()); // 0(n*log(n))
//std::reverse(v.begin(),v.end()); 0(n)
print(v);

int a[]={44, 28, 3, 89, 69, 420, 77, 5,23};
std::vector<int> v3 (a, a+9);
//can't sort arrays can sort vectors
print(v3);

iter = v3.begin();

std::cout << *iter <<std::endl;
iter++;
std::cout << *iter<< std::endl;
iter +=4;
std::cout << *iter<< std::endl;
iter --;
std::cout << *iter<< std::endl;

  iter = v3.begin();
  int min = *iter;

  
  while (iter != v.end()) {
    if (min > *iter) {
      min = *iter;
    }
    iter++;
  }
  std::cout << "Min: " << min << std::endl;
return 0; 


}