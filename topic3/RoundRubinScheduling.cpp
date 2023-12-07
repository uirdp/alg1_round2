#include <iostream>
#include <queue>
#include <string>

using std::string;
using std::cin;
using std::cout;

class Process {

private: 
	string process_name;
	int time_remaining;

public:
	Process(string name, int time) : process_name{ name }, time_remaining{time} {}

	bool isCompleted() { return this->time_remaining <= 0; }

	
	void showStatusUponCompletion(int completion_time){
		cout << this->process_name << " " << completion_time << std::endl;
	}

	int updateProcess(int quantum) { 
		
		int processing_time;
		
		if (time_remaining < quantum) processing_time = time_remaining;
		else processing_time = quantum;

		this->time_remaining -= quantum; 
		return processing_time;
	}

	~Process() {}
};

void RoundRubinScheduling() {

	int num_of_process;
	cin >> num_of_process;

	int quantum;
	cin >> quantum;

	std::queue<Process> process_queue;
	for (int i = 0; i != num_of_process; ++i) {
		string name;
		cin >> name;

		int time_required;
		cin >> time_required;

		Process process(name, time_required);
		process_queue.push(process);
	}

	int time_elapsed = 0;
	while (!process_queue.empty()) {

		Process process = process_queue.front();
		time_elapsed += process.updateProcess(quantum);

		process_queue.pop();
		if (process.isCompleted()) process.showStatusUponCompletion(time_elapsed);
		else process_queue.push(process);
	}
}

