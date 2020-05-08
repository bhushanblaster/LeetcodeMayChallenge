class Solution {
public:
    //for 3 points p1(x1,y1),p2(x2,y2) and p3(x3,y3)
    //to be in same line the slope should be equal
    //(y2-y1)/(x2-x1) = (y3-y2)/(x3-x2)
    double getSlope(int x1,int y1,int x2,int y2)
    {
        if(x2-x1 == 0)
            return 0;
        else
            return (double)(y2-y1)/(x2-x1);
    }
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size()<=2)
            return true;
        else
        {
            auto p1 = coordinates[0];
            auto p2 = coordinates[1];
            double slope = getSlope(p1[0],p1[1],p2[0],p2[1]);
            for(int i=2;i<coordinates.size();i++)
            {
                auto p3 = coordinates[i];
                double slope1 = getSlope(p2[0],p2[1],p3[0],p3[1]);
                if(slope1!=slope)
                    return false;
            }
            return true;
        }
    }
};
