#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Job {
    int id = 0;
    int weight = 0;
    int length = 0;
    int diff = 0;
    double ratio = 0.0;

    Job(int id, int w, int l, int d, double r) : 
        id(id), weight(w), length(l), diff(d), ratio(r) {}
};

bool compDiff (Job* j1, Job* j2) {
    return j1->diff != j2->diff? j1->diff > j2->diff : j1->weight > j2->weight;
}

bool compRatio (Job* j1, Job* j2) {
    return j1->ratio > j2->ratio;
}

void schedule(vector<Job* >& jobs) {
    sort(jobs.begin(), jobs.end(), compDiff);
    long completionTime = 0;
    long totalWeight = 0;

    for (auto v : jobs) {
        completionTime += v->length;
        totalWeight += completionTime * v->weight;
    }

    cout << "totalWeight diff: " << totalWeight << endl;

    sort(jobs.begin(), jobs.end(), compRatio);
    completionTime = 0;
    totalWeight = 0;
    for (auto v : jobs) {
        completionTime += v->length;
        totalWeight += completionTime * v->weight;
    }
    cout << endl;
    cout << "totalWeight ratio: " << totalWeight << endl;

}
int main() {
    ifstream infile("jobs.txt");
    vector<Job* > jobs;
    if (infile.is_open()) {
        int weight = 0;
        int length = 0;
        int id = 1;
        string size = "";
        getline(infile, size);
        while (infile >> weight >> length) {
            Job* newJob = new Job(id++, weight, length, weight - length, 1.0 * weight / length);
            jobs.push_back(newJob);
        }
    }
    schedule(jobs);
    infile.close();
    return 0;
}



