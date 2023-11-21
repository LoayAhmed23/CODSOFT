//to clear the console
#ifdef _WIN32
#define CLEAR_COMMAND "CLS"
#else
#define CLEAR_COMMAND "clear"
#endif

#include <iostream>
#include <vector>
#include <algorithm>
#include <string> 

using namespace std;


struct task {
    string description;
    bool completed;
};

void viewtasks(const vector<task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks in the list." << endl;
        return;
    }

    cout << "tasks:" << endl;
    for (int i = 0; i < tasks.size(); i++) {
        task current = tasks[i];
        cout << i+1 << ". ";
        if (current.completed) {
            cout << "[Done] ";
        }
        else {
            cout << "[ ] ";
        }
        cout << current.description << endl;
    }
}

void marktaskCompleted(vector<task>& tasks, int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= tasks.size()) {
        tasks[taskIndex - 1].completed = true;
        cout << "task marked as completed." << endl;
    }
    else {
        cout << "Invalid task number." << endl;
    }
}

void removetask(vector<task>& tasks, int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= tasks.size()) {
        tasks.erase(tasks.begin() + taskIndex - 1);
        cout << "task removed from the list." << endl;
    }
    else {
        cout << "Invalid task number." << endl;
    }
}

int main() {
    vector<task> tasks_list;

    while (true) {
        cout << "\nTo-Do List Manager" << endl;
        cout << "1. Add task" << endl;
        cout << "2. View tasks" << endl;
        cout << "3. Mark task as Completed" << endl;
        cout << "4. Remove task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {   //add
            string Description;
            cout << "Enter task description: ";
            cin >> Description;
            task newtask = { Description, false };
            tasks_list.push_back(newtask);            
            system(CLEAR_COMMAND); // clear console
            break;
        }


        case 2: //view
            system(CLEAR_COMMAND); // clear console
            viewtasks(tasks_list);
            break;
        case 3: {   // complete
            system(CLEAR_COMMAND); // clear console
            int complete;
            viewtasks(tasks_list);
            cout << "Enter task number to mark as completed: ";
            cin >> complete;
            marktaskCompleted(tasks_list, complete);
            system(CLEAR_COMMAND); // clear console
            break;
        }
        case 4: {   // remove
            system(CLEAR_COMMAND); // clear console
            int removedindex;
            viewtasks(tasks_list);
            cout << "Enter task number to remove: ";
            cin >> removedindex;
            removetask(tasks_list, removedindex);
            system(CLEAR_COMMAND); // clear console
            break;
        }
        case 5:
            system(CLEAR_COMMAND); // clear console
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
