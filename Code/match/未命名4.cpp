#include <string>
using namespace std;

int main() {
    std::string str = "12345";
    int num = std::stoi(str);     // ת��Ϊ int
    long long big_num = std::stoll(str);  // ת��Ϊ long long
    return 0;
}
