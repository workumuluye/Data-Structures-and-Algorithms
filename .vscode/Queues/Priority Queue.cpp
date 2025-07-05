#include <iostream> //for input-output operations
#include <queue> //for using priority_queue container
#include <vector> //for internal use by priority_queue
#include <string>

using namespace std;
struct Task {
    string name;//description of the task
    int priority;//priority of the task (higher = more important)

    // Overload the < operator to make higher priority come first
    bool operator<(const Task& other) const {
        return priority < other.priority; // Higher priority comes first
    }
};
//function to conceptually enqueue a task into the priority queue
void enqueue(priority_queue<Task>& pq, const string& name, int priority) {
    pq.push({name, priority});//internally uses push enqueue data into a queue
}

int main() {
    
    priority_queue<Task> pq;//create a max-heap priority queue for Task objects

    //enqueue software project tasks with their priorities
    enqueue(pq, "Implement user authentication", 15);
    enqueue(pq, "Fix critical security bug", 20);//the most urgent
    enqueue(pq, "Refactor legacy code", 6);
    enqueue(pq, "Write unit tests", 8);
    enqueue(pq, "Update project documentation", 3);//low priority
    enqueue(pq, "Design project dashboard", 10);

    cout << "Software Project Tasks in Priority Order:\n" << endl;
    while (!pq.empty()) {
        Task t = pq.top();//get the highest-priority task
        cout << "- " << t.name << " (Priority: " << t.priority << ")\n";
        pq.pop();
    }
    return 0;
}