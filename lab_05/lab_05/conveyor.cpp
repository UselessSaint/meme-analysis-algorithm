#include "conveyor.h"

static std::chrono::time_point<std::chrono::steady_clock> start;

void first_tape(std::queue<task> &first_queue, std::mutex &first_mutex,
				std::queue<task> &second_queue, std::mutex &second_mutex)
{
	bool exit = false;
	bool waiting = false;
	std::chrono::time_point<std::chrono::steady_clock> start_awaiting_time;

	long long total_waiting_time = 0;
	int amount_of_waitings = 0;

	while(!exit)
	{
		first_mutex.lock();
		if (first_queue.size() > 0)
		{
			auto cur_task = first_queue.front();
			first_queue.pop();

			auto startft = get_time(start);
			first_task_part(cur_task);
			auto endft = get_time(start);

			cur_task.first_tape_start = startft;
			cur_task.first_tape_end = endft;

			first_mutex.unlock();

			second_mutex.lock();
			second_queue.push(cur_task);
			second_mutex.unlock();

			if (waiting)
			{
				waiting = false;
				total_waiting_time += get_time(start_awaiting_time);
				amount_of_waitings += 1;
			}
		}
		else
		{
			first_mutex.unlock();

			if (!waiting)
			{
				waiting = true;
				start_awaiting_time = std::chrono::steady_clock::now();
			}
			else if (amount_of_waitings > 0 && get_time(start_awaiting_time) > 2*(total_waiting_time/amount_of_waitings))
			{
				exit = true;
			}
		}
	}
}

void first_task_part(task &inTask)
{
	std::ifstream file(inTask.fileName);

	if (file.is_open())
	{
		char c;
		while (file.get(c))
		{
			inTask.msg += c;
		}
	}

	file.close();
}

void second_tape(std::queue<task> &second_queue, std::mutex &second_mutex,
				 std::queue<task> &third_queue, std::mutex &third_mutex)
{
	bool exit = false;
	bool waiting = false;
	std::chrono::time_point<std::chrono::steady_clock> start_awaiting_time;

	long long total_waiting_time = 0;
	int amount_of_waitings = 0;

	while(!exit)
	{
		second_mutex.lock();
		if (second_queue.size() > 0)
		{
			auto cur_task = second_queue.front();
			second_queue.pop();

			auto starts = get_time(start);
			second_task_part(cur_task);
			auto ends = get_time(start);

			cur_task.second_tape_start = starts;
			cur_task.second_tape_end = ends;

			second_mutex.unlock();

			third_mutex.lock();
			third_queue.push(cur_task);
			third_mutex.unlock();

			if (waiting)
			{
				waiting = false;
				total_waiting_time += get_time(start_awaiting_time);
				amount_of_waitings += 1;
			}
		}
		else
		{
			second_mutex.unlock();

			if (!waiting)
			{
				waiting = true;
				start_awaiting_time = std::chrono::steady_clock::now();
			}
			else if (amount_of_waitings > 0 && get_time(start_awaiting_time) > 2*(total_waiting_time/amount_of_waitings))
			{
				exit = true;
			}
		}
	}
}

void second_task_part(task &inTask)
{
	std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	int encode_num = 3;
	inTask.encoded_num = encode_num;

	for (int i = 0; i < inTask.msg.size(); i++)
	{
		if (inTask.msg[i] != ' ' || inTask.msg[i] != '\n' || inTask.msg[i] != '.' || inTask.msg[i] != ',')
		{
			for (int j = 0; j < alphabet.size(); j++)
			{
				if (toupper(inTask.msg[i]) == alphabet[j])
				{
					if (isupper(inTask.msg[i]))
						inTask.msg[i] = alphabet[(j + encode_num) % alphabet.size()];
					else
						inTask.msg[i] = tolower(alphabet[(j + encode_num) % alphabet.size()]);
					break;
				}
			}
		}
	}
}

void third_tape(std::queue<task> &third_queue, std::mutex &third_mutex,
				std::vector<task> &complited_tasks, std::mutex &com_t_mutex)
{
	bool exit = false;
	bool waiting = false;
	std::chrono::time_point<std::chrono::steady_clock> start_awaiting_time;

	long long total_waiting_time = 0;
	int amount_of_waitings = 0;

	while(!exit)
	{
		third_mutex.lock();
		if (third_queue.size() > 0)
		{
			auto cur_task = third_queue.front();
			third_queue.pop();

			auto starttd = get_time(start);
			third_task_part(cur_task);
			auto endtd = get_time(start);

			cur_task.third_tape_start = starttd;
			cur_task.third_tape_end = endtd;

			third_mutex.unlock();

			com_t_mutex.lock();
			complited_tasks.push_back(cur_task);
			com_t_mutex.unlock();

			if (waiting)
			{
				waiting = false;
				total_waiting_time += get_time(start_awaiting_time);
				amount_of_waitings += 1;
			}
		}
		else
		{
			third_mutex.unlock();

			if (!waiting)
			{
				waiting = true;
				start_awaiting_time = std::chrono::steady_clock::now();
			}
			else if (amount_of_waitings > 0 && get_time(start_awaiting_time) > 2*(total_waiting_time/amount_of_waitings))
			{
				exit = true;
			}
		}
	}
}

void third_task_part(task &inTask)
{
	std::vector<std::pair<char, double>> analisys;
	analisys.push_back(std::pair<char, double>('A', 0.081));
	analisys.push_back(std::pair<char, double>('B', 0.014));
	analisys.push_back(std::pair<char, double>('C', 0.027));
	analisys.push_back(std::pair<char, double>('D', 0.039));
	analisys.push_back(std::pair<char, double>('E', 0.13));
	analisys.push_back(std::pair<char, double>('F', 0.029));
	analisys.push_back(std::pair<char, double>('G', 0.02));
	analisys.push_back(std::pair<char, double>('H', 0.052));
	analisys.push_back(std::pair<char, double>('I', 0.065));
	analisys.push_back(std::pair<char, double>('J', 0.002));
	analisys.push_back(std::pair<char, double>('K', 0.004));
	analisys.push_back(std::pair<char, double>('L', 0.034));
	analisys.push_back(std::pair<char, double>('M', 0.025));
	analisys.push_back(std::pair<char, double>('N', 0.072));
	analisys.push_back(std::pair<char, double>('O', 0.079));
	analisys.push_back(std::pair<char, double>('P', 0.020));
	analisys.push_back(std::pair<char, double>('R', 0.069));
	analisys.push_back(std::pair<char, double>('S', 0.061));
	analisys.push_back(std::pair<char, double>('T', 0.105));
	analisys.push_back(std::pair<char, double>('U', 0.024));
	analisys.push_back(std::pair<char, double>('V', 0.009));
	analisys.push_back(std::pair<char, double>('W', 0.015));
	analisys.push_back(std::pair<char, double>('X', 0.002));
	analisys.push_back(std::pair<char, double>('Y', 0.019));
	analisys.push_back(std::pair<char, double>('Z', 0.001));

	std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	std::vector<std::pair<char, double>> taskAnalisys;
	int taskMsgLen = 0;

	for (int i = 0; i < alphabet.size(); i++)
		taskAnalisys.push_back(std::pair<char, double>(alphabet[i], 0));

	for (int i = 0; i < inTask.msg.size(); i++)
	{
		auto c = inTask.msg[i];
		if (c != ' ' || c != '\n' || c != '.' || c != ',')
		{
			for (int j = 0; j < taskAnalisys.size(); j++)
			{
				if (toupper(c) == taskAnalisys[j].first)
				{
					taskAnalisys[j].second += 1;
				}
			}

			taskMsgLen += 1;
		}
	}

	for (int i = 0; i < taskAnalisys.size(); i++)
	{
		taskAnalisys[i].second /= taskMsgLen;
	}

	double closest = 10.0;
	int decode = -1;

	for (auto i : taskAnalisys)
	{
		for (auto j : analisys)
		{
			if (fabs(i.second - j.second) < closest)
			{
				closest = fabs(i.second - j.second);
				decode = abs(i.first - j.first);
			}
		}
	}

	inTask.decoded_num = decode;
}

void task_pusher(std::queue<task> &first_queue, std::mutex &first_mutex)
{
	for (int i = 1; i < 16; i++)
	{
		task newTask;
		newTask.id = i;
		newTask.fileName = "msg";
		newTask.fileName += std::to_string(1 + i % 5);
		newTask.fileName += ".txt";

		std::cout << newTask.fileName << std::endl;

		first_mutex.lock();
		first_queue.push(newTask);
		first_mutex.unlock();
	}
}

long long get_time(std::chrono::time_point<std::chrono::steady_clock> &start_time)
{
	auto end = std::chrono::steady_clock::now();
	auto result = std::chrono::duration_cast<std::chrono::microseconds>(end-start_time).count();

	return (result % 1000000000);
}

void printTaskInfo(task &inTask)
{
	std::cout << "Task id: " << inTask.id << std::endl;
	std::cout << "	1st tape st: " << inTask.first_tape_start << "; 1st tape end: " << inTask.first_tape_end << std::endl;
	std::cout << "	2st tape st: " << inTask.second_tape_start << "; 2st tape end: " << inTask.second_tape_end << std::endl;
	std::cout << "	3st tape st: " << inTask.third_tape_start << "; 3st tape end: " << inTask.third_tape_end << std::endl;
	std::cout << "	Encoded num: " << inTask.encoded_num << "; Decodec num: " << inTask.decoded_num << std::endl << std::endl;
}
















