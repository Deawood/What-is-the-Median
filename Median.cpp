#include <cstdio>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

typedef unsigned int unit;

int main() {
	std::priority_queue<unit> smallerHalf;
	std::priority_queue<unit, vector<unit>, std::greater<unit> > largerHalf;
	unit n, count;

	if (1 != scanf("%u", &n)) { return 0; }
	smallerHalf.push(n);
	printf("%u\n", n);

	for (count = 1; 1 == scanf("%u", &n); ++count){
		if (0 == (count&0x01)) { //insert into smallerHalf
			if (largerHalf.top() < n) { //insert in into largerHalf
				largerHalf.push(n);
				n = largerHalf.top();
				largerHalf.pop();
			}
			smallerHalf.push(n);
			printf("%u\n", smallerHalf.top());
		} else { // insert into largerHalf
			if (smallerHalf.top() > n) { //insert in into smallerHalf
				smallerHalf.push(n);
				n = smallerHalf.top();
				smallerHalf.pop();
			}
			largerHalf.push(n);
			printf("%u\n", (smallerHalf.top()+largerHalf.top())/2);
		}
		//printf("\tThe top of the heaps are \n\t%u and %u\n", smallerHalf.top(), largerHalf.top());
	}

	return 0;

}