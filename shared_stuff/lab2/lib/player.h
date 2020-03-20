#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <set>
#include <string>
#include <thread>

#include "line.h"
#include "play.h"
#include "sync_que.h"
#include "line.h"

using namespace std;

class Play;


/* Player class that actually stores the lines for each character and
   is coordinated by play class */
class Player {
	string name;
	set<line> lines;
	Play& p;
	ifstream ifs;
	thread t;

public:
	Player(Play& p) : p(p) {}

	void read(string name, string file);

	void act(size_t frag_num);

	void work(sync_que &q, condition_variable &cv_dir);

	void enter(sync_que &q, condition_variable &cv_dir);

	bool exit();
};

#endif
