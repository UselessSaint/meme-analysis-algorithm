#ifndef DATA_STRUCTS_H
#define DATA_STRUCTS_H

#include <string>

typedef struct
{
	int id;
	std::string fileName;
	std::string msg;

	int encoded_num;
	int decoded_num;

	long long first_tape_start;
	long long first_tape_end;

	long long second_tape_start;
	long long second_tape_end;

	long long third_tape_start;
	long long third_tape_end;
}task;

#endif // DATA_STRUCTS_H
