#include "player.h"
#include "line.h"


void Player::read(string name, string file) {
  this->lines.clear();
    ifstream ifs(file);
	string line_str;
	line l;
	while (getline(ifs, line_str)) {
	  
		istringstream is(line_str);
		if (!(is >> l.linen)) {
			// could not extract line number or first whitespace-delimited
			// string was not a positive number
			continue;
		}

		// need to ignore extra spaces after line number, so extract one
		// word from the line
		if (!(is >> l.msg)) {
			// line is empty
			continue;
		}
		// now get remaining text from the line
		getline(is, line_str);
		l.msg += line_str;
		l.character = name;
		lines.insert(l);
	}
}

void Player::act(size_t frag_num) {
	for (auto it = lines.begin(); it != lines.end(); it++) {
	  
	  p.recite(it, frag_num);
	}
	p.player_exit();
}

void Player::work(sync_que &q, condition_variable &cv_dir) {
    while (!q.done) {
        p_info p = q.pop();
	if(q.done){
	  break;
	}
        read(p.name, p.file);
        act(p.frag_num);
	cv_dir.notify_all();
	
    }
}

void Player::enter(sync_que &q, condition_variable &cv_dir) {
	thread th([&] {
	    this->work(q, cv_dir);
		});
	this->t = std::move(th);
}

bool Player::exit() {
	if (this->t.joinable()) {
		t.join();
		return true;
	}
	return false;
}