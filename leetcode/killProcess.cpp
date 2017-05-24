#include "all.h"
using namespace std;

vector<int> killProcess_v0(vector<int>& pid, vector<int>& ppid, int kill) {
    vector<int> result;
    result.push_back(kill);
    for (int i = 0; i < pid.size(); ++i) {
        if (pid[i] == kill) {
            swap(pid[i], pid[pid.size() - 1]);
            pid.pop_back();
            swap(ppid[i], ppid[ppid.size() - 1]);
            ppid.pop_back();
            --i;
            break;
        }
    }
    if (find(ppid.begin(), ppid.end(), kill) != ppid.end()) {
        queue<int> toVisit;
        for (int i = 0; i < ppid.size(); ++i) {
            if (ppid[i] == kill) {
                toVisit.push(pid[i]);
                //result.push_back(pid[i]);
                swap(pid[i], pid[pid.size() - 1]);
                swap(ppid[i], ppid[ppid.size() - 1]);
                ppid.pop_back();
                pid.pop_back();
                --i;
                
            }
        }
        while (!toVisit.empty()) {
            kill = toVisit.front();
            toVisit.pop();
            result.push_back(kill);
            
            for (int i = 0; i < ppid.size(); ++i) {
                if (ppid[i] == kill) {
                    toVisit.push(pid[i]);
                    swap(pid[i], pid[pid.size() - 1]);
                    pid.pop_back();
                    swap(ppid[i], ppid[ppid.size() - 1]);
                    ppid.pop_back();
                    --i;
                }
            }
           
        }
    }
    
    return result;
}

vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> result;
        unordered_map<int, vector<int>> m;
        
        for (int i = 0; i < pid.size(); ++i) {
            m[ppid[i]].push_back(pid[i]);
        }
        
        queue<int> toVisit;
        toVisit.push(kill);
        while (!toVisit.empty()) {
            kill = toVisit.front();
            toVisit.pop();
            result.push_back(kill);
            for (auto p : m[kill]) toVisit.push(p);
        }
        return result;
    }

int main() {
    vector<int> pid = {1, 3, 10, 5};
    vector<int> ppid = {3, 0, 5, 3};
    int kill = 5;
    auto result = killProcess(pid, ppid, kill);
    print(result);
    
    return 0;
}
