#include <stdio.h>
#include <math.h>

struct Driver {
    int id;
    float x;
    float y;
};


float calculateDistance(float x1, float y1, float x2, float y2) {
    return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}

int main() {
    struct Driver drivers[] = {
        {1, 2.0, 3.0},
        {2, 5.0, 1.0},
        {3, 1.0, 1.0}
    };

    float userX = 0.0, userY = 0.0;
    float minDistance = 9999;
    int nearestDriverId = -1;

    for (int i = 0; i < 3; i++) {
        float dist = calculateDistance(
            userX, userY,
            drivers[i].x, drivers[i].y
        );

        if (dist < minDistance) {
            minDistance = dist;
            nearestDriverId = drivers[i].id;
        }
    }

    printf("Nearest Driver ID: %d\n", nearestDriverId);
    return 0;
}