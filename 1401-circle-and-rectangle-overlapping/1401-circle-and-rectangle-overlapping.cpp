
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter,
                      int x1, int y1, int x2, int y2) {
        
        // Find the closest point of the rectangle to the circle center
        int closestX = max(x1, min(xCenter, x2));
        int closestY = max(y1, min(yCenter, y2));

        // Calculate squared distance
        long long dx = xCenter - closestX;
        long long dy = yCenter - closestY;

        long long distanceSquared = dx * dx + dy * dy;

        // Overlap if closest point is inside/on the circle
        return distanceSquared <= 1LL * radius * radius;
    }
};
