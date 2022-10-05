#include <iostream>
#include "bank.h"
using namespace std;
using chen::Bankacct;

int main (){
    Bankacct mine, yours, ours;
    mine.input (cin);
    yours.input (cin);

    mine = mine * 3;
    ours = mine + yours;
}