#ifndef CONVEYOR_H
#define CONVEYOR_H

#include "data_structs.h"
#include <queue>
#include <mutex>
#include <thread>
#include <iostream>
#include <chrono>
#include <fstream>
#include <cmath>

void first_tape(std::queue<task> &first_queue, std::mutex &first_mutex,
				std::queue<task> &second_queue, std::mutex &second_mutex);
void first_task_part(task &inTask);

void second_tape(std::queue<task> &second_queue, std::mutex &second_mutex,
				 std::queue<task> &third_queue, std::mutex &third_mutex);
void second_task_part(task &inTask);

void third_tape(std::queue<task> &third_queue, std::mutex &third_mutex,
				std::vector<task> &complited_tasks, std::mutex &com_t_mutex);
void third_task_part(task &inTask);

void task_pusher(std::queue<task> &first_queue, std::mutex &first_mutex);
long long get_time(std::chrono::time_point<std::chrono::steady_clock> &start_time);
void printTaskInfo(task &inTask);

#endif // CONVEYOR_H
