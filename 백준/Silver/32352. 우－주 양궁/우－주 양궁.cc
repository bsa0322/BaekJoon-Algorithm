#include <iostream>

using namespace std;
typedef struct Cuboid {
    int x_lo, x_hi, y_lo, y_hi, z_lo, z_hi;
} cuboid;

bool isFace(cuboid &a, cuboid &t) {
    if (t.x_lo < a.x_hi && t.x_hi > a.x_lo && t.y_lo < a.y_hi && t.y_hi > a.y_lo) {
        return true;
    }
    if (a.x_lo >= t.x_lo && a.x_hi <= t.x_hi && a.y_lo >= t.y_lo && a.y_hi <= t.y_hi) {
        return true;
    }
    if (t.x_lo >= a.x_lo && t.x_hi <= a.x_hi && t.y_lo >= a.y_lo && t.y_hi <= a.y_hi) {
        return true;
    }
    return false;
}

int main() {
    cuboid a, t;

    cin >> a.x_lo >> a.x_hi >> a.y_lo >> a.y_hi >> a.z_lo >> a.z_hi;
    cin >> t.x_lo >> t.x_hi >> t.y_lo >> t.y_hi >> t.z_lo >> t.z_hi;

    if (isFace(a, t) && a.z_hi >= t.z_lo) {
        int intersection_frame = a.z_lo - t.z_hi + 1;
        cout << (intersection_frame < 0 ? 0 : intersection_frame);
    } else {
        cout << "-1";
    }
    return 0;
}