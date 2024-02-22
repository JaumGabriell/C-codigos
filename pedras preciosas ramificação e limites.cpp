#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Item {
   int value;
   int weight;
   int volume;
};

struct Node {
   int level;
   int value;
   int weight;
};

bool operator<(const Node& n1, const Node& n2) {
   return n1.value < n2.value;
}

int bound(Node u, int n, int W, vector<Item> items, int V) {
   if (u.weight >= W) return 0;
   int valueBound = u.value;
   int j
