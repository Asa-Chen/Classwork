#include <string>
#include <iostream>
#include <cstdlib>
#include <queue>
#include "chore.h"

int main() {
//queue<chore> chores;
priority_queue<chore> chores;
chore tmp;

for (int i = 0; i < 5; i++) {
    tmp.input();
    chores.push(tmp);
}

for (int i = chores.size(); i > 0; i--) {
    //chores.front().out();
    chores.top().out();
    chores.pop();
}


return 0;
}