#include <thread>
#include <mutex>
#include <sstream>
#include <iostream>
#include <vector> 
#include <deque>
#include <cmath>

using namespace std;
class Stream {
private:
    istringstream _sin;
public:
    Stream(string s) : _sin(s) { }

    float getNext() {
        float f;
        if (_sin >> f) {
            return f;
        } else {
            while(true);
        }
        
    }
};

int main() {
    Stream s1("0.1 0.8 1.3 1.9 2.3");
    Stream s2("0.3 0.7 1.2 1.4 3.8");

    mutex mu;
    vector<pair<float, float>> res;
    deque<float> q1, q2;

	auto foo = [&](Stream& s, deque<float>& q1, deque<float>& q2) {
        while (true) {
            auto v = s.getNext();
            mu.lock();

            q1.push_back(v);
            while(q2.size() > 0 && abs(q2.front() - v) > 1) {
                q2.pop_front();
            }
			for (auto v2 : q2) {
                if (abs(v - v2) >= 1) break;
                res.push_back({v, v2});
                cout << '(' << v << ' ' << v2 << ")\n";
            }
            mu.unlock();

        }
    };

    thread t1(foo, ref(s1), ref(q1), ref(q2));
    thread t2(foo, ref(s2), ref(q2), ref(q1));

    t1.join();
    t2.join();
    return 0;
}
