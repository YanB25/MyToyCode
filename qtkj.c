#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
int main() {
	double start = 0;
	double end = 1;
	double step = 0.01;
	srand(time(0));
	for (double other = start; other < end; other += step) {
		for (double me = other; me < end; me += step) {
			const int times = 1000;
			int meTime = 0, otherTime = 0;
			for (int i = 0; i < times; ++i) {
				bool meDo = (rand()/rand() <= me);
				bool otherDo = (rand()/rand() <= other);
				//printf("%d %d",  meDo, otherDo);
				if (meDo && otherDo) {
					meTime++;
					otherTime++;
				} else if (meDo && !otherDo) {
					otherTime += 5;
				} else if (!meDo && otherDo) {
					meTime += 5;
				} else {
					meTime += 2;
					otherTime += 2;
				}
			}
			printf("me:%lf  other:%lf  (%d) \n", me, other, meTime - otherTime);
		}
	}
}
