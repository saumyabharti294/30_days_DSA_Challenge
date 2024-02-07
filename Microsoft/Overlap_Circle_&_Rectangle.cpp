/*
Example 1: 

Input: radius = 1, xCenter = 0, yCenter = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1
Output: true
Explanation: Circle and rectangle share the point (1,0).
*/

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        //Time Complexity-->O(1)
        //Space Complexity-->O(1)
        //finding the co-ordinates of a point closest to the circle.
        int X = max(x1, min(xCenter, x2));
        int Y = max(y1, min(yCenter, y2));

        //distance of circle center to the closest co-ordinate of rectangle to compare it with radius.
        int distance = sqrt(std::pow(xCenter - X, 2) + pow(yCenter - Y, 2));

        return radius >= distance;
    }
};
