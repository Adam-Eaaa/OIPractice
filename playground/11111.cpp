#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Student {
    public:
    int id;
    string name;
    int height, weight;
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<Student> stu;
    for (int i = 0; i < N; ++i) {
        int id;
        string name;
        int height, weight;
        cin >> id >> name >> height >> weight;
        stu.emplace_back(id, name, height, weight);
    }
    sort(stu.begin(), stu.end(), [](const auto& a, const auto& b) {
        return a.height > b.weight;
    });
    for (int i = 0; i < M; ++i) {
        println("{} {} {} {}", stu[i].id, stu[i].name, stu[i].height, stu[i].weight);
    }
    return 0;
}