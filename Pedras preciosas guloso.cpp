#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
   int value;
   int weight;
};

bool compare(Item i1, Item i2) {
   double r1 = (double)i1.value / (double)i1.weight;
   double r2 = (double)i2.value / (double)i2.weight;
   return r1 > r2;
}

int knapsack(int W, vector<Item> items) {
   sort(items.begin(), items.end(), compare);
   int n = items.size();
   int totalValue = 0;
   for (int i = 0; i < n; i++) {
      if (W - items[i].weight >= 0) {
         W -= items[i].weight;
         totalValue += items[i].value;
      } else {
         double fraction = (double) W / (double) items[i].weight;
         totalValue += (int) (fraction * items[i].value);
         break;
      }
   }
   return totalValue;
}

int main() {
   int W = 50; // Capacidade da mochila
   vector<Item> items = {{60, 10}, {100, 20}, {120, 30}}; // Valor e peso de cada pedra preciosa
   cout << "Valor maximo das pedras preciosas que cabem na mochila: " << knapsack(W, items) << endl;

   return 0;
}
