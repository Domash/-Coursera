//
//  task_tracker.cpp
//  coursera
//
//  Created by Денис Домашевич on 10/1/18.
//  Copyright © 2018 Денис Домашевич. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>

enum class TaskStatus {
    NEW,
    IN_PROGRESS,
    TESTING,
    DONE
};

using TasksInfo = std::map<TaskStatus, int64_t>;

class TeamTasks {
public:
    const TasksInfo& GetPersonTasksInfo(const std::string& person) const {
        return table.at(person);
    }
    
    void AddNewTask(const std::string &person) {
        table[person][TaskStatus::NEW]++;
    }
    
    std::tuple<TasksInfo, TasksInfo> PerformPersonTasks(const std::string& person, int64_t task_count) {
        std::tuple <TasksInfo, TasksInfo> result;
        TasksInfo new_status;
        
        int sum = 0;
        sum += table[person][TaskStatus::NEW];
        sum += table[person][TaskStatus::IN_PROGRESS];
        sum += table[person][TaskStatus::TESTING];
                             
        task_count = std::fmin(task_count, sum);
                             
        while(task_count--) {
            if(table[person][TaskStatus::NEW]) {
                table[person][TaskStatus::NEW]--;
                new_status[TaskStatus::IN_PROGRESS]++;
            } else if(table[person][TaskStatus::IN_PROGRESS]) {
                table[person][TaskStatus::IN_PROGRESS]--;
                new_status[TaskStatus::TESTING]++;
            } else if(table[person][TaskStatus::TESTING]) {
                table[person][TaskStatus::TESTING]--;
                new_status[TaskStatus::DONE]++;
            }
        }
        
        result = std::tuple<TasksInfo, TasksInfo>(new_status, table[person]);
        
        for(const auto &it : new_status) {
            table[person][it.first] += it.second;
        }
        
        return result;
    }
private:
    std::map<std::string, TasksInfo> table;
};

void PrintTasksInfo(TasksInfo tasks_info) {
    std::cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
    ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
    ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
    ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << std::endl;
}

int main(int argc, const char * argv[]) {
    
    TeamTasks tasks;
    tasks.AddNewTask("Ilia");
    for (int i = 0; i < 3; ++i) {
        tasks.AddNewTask("Ivan");
    }
    std::cout << "Ilia's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
    std::cout << "Ivan's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
    
    TasksInfo updated_tasks, untouched_tasks;
    
    tie(updated_tasks, untouched_tasks) =
    tasks.PerformPersonTasks("Ivan", 2);
    std::cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    std::cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);
    
    tie(updated_tasks, untouched_tasks) =
    tasks.PerformPersonTasks("Ivan", 2);
    std::cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    std::cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);
    
    return 0;
}










