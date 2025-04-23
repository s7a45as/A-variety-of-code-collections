#include <string>
using namespace std;

int main() {
    std::string str = "12345";
    int num = std::stoi(str);     // 转换为 int
    long long big_num = std::stoll(str);  // 转换为 long long
    return 0;
}
