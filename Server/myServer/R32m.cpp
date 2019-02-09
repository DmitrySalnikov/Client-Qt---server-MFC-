#include "stdafx.h"
#include <random>

using namespace std;

static int ac, bc, as, bs;
default_random_engine g;

long rcome() {
	uniform_int_distribution<long> come(ac, bc);
	return come(g);
}


void rcomeinit(int a, int b) {
	ac = a;
	bc = b;
}

long rserv() {
	uniform_int_distribution<long> come(as, bs);
	return come(g);
}


void rservinit(int a, int b) {
	as = a;
	bs = b;
}