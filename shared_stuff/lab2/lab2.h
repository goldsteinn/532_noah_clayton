#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <assert.h>
#include <string.h>
#include <string>
#include <atomic>
#include <sstream>
#include <vector>
#include <iostream>
#include <thread>
#include <condition_variable>
#include <algorithm>
#include <mutex>
#include <iterator>
#include <map>


#include "helpers/locks.h"
#include "helpers/temp.h"
#include "helpers/opt.h"
#include "helpers/util.h"
#include "helpers/arg.h"
#include "helpers/bits.h"
#include "helpers/timing.h"
#include "play.h"
#include "player.h"