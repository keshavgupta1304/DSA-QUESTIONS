class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int emptyBottles=numBottles;
        int filledBottles=emptyBottles/numExchange;
        emptyBottles=(emptyBottles%numExchange)+(filledBottles);
        while(emptyBottles>=numExchange)
        {
            filledBottles+=1;
            emptyBottles-=numExchange;
            emptyBottles+=1;
        }
        return numBottles + filledBottles;
    }
};