#include "conveyor.h"
#include "data_structs.h"
#include <vector>
#include <iostream>
#include <queue>
#include <mutex>
#include <thread>

int main()
{
	std::queue<task> first_queue;
	std::queue<task> second_queue;
	std::queue<task> third_queue;

	std::vector<task> complited_tasks;

	std::mutex first_mutex;
	std::mutex second_mutex;
	std::mutex third_mutex;
	std::mutex com_t_mutex;

	std::vector<std::thread> tape_threads;

	std::thread tape1([&](){first_tape(first_queue, first_mutex,
									   second_queue, second_mutex);});
	tape_threads.push_back(std::move(tape1));

	std::thread tape2([&](){second_tape(second_queue, second_mutex,
									   third_queue, third_mutex);});
	tape_threads.push_back(std::move(tape2));

	std::thread tape3([&](){third_tape(third_queue, third_mutex,
									   complited_tasks, com_t_mutex);});
	tape_threads.push_back(std::move(tape3));


	std::thread tsk_pusher([&](){task_pusher(first_queue, first_mutex);});

	for (auto &thr : tape_threads)
		if (thr.joinable())
			thr.join();

	if (tsk_pusher.joinable())
		tsk_pusher.join();

	for (auto i : complited_tasks)
		printTaskInfo(i);

	getchar();

	return 0;
}
