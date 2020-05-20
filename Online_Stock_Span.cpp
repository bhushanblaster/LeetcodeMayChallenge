/*
Write a class StockSpanner which collects daily price quotes for some stock, and returns the span of that stock's price for the current day.

The span of the stock's price today is defined as the maximum number of consecutive days (starting from today and going backwards) for which the price of the stock was less than or equal to today's price.

For example, if the price of a stock over the next 7 days were [100, 80, 60, 70, 60, 75, 85], then the stock spans would be [1, 1, 1, 2, 1, 4, 6].

 

Example 1:

Input: ["StockSpanner","next","next","next","next","next","next","next"], [[],[100],[80],[60],[70],[60],[75],[85]]
Output: [null,1,1,1,2,1,4,6]
Explanation: 
First, S = StockSpanner() is initialized.  Then:
S.next(100) is called and returns 1,
S.next(80) is called and returns 1,
S.next(60) is called and returns 1,
S.next(70) is called and returns 2,
S.next(60) is called and returns 1,
S.next(75) is called and returns 4,
S.next(85) is called and returns 6.

Note that (for example) S.next(75) returned 4, because the last 4 prices
(including today's price of 75) were less than or equal to today's price.
 

Note:

Calls to StockSpanner.next(int price) will have 1 <= price <= 10^5.
There will be at most 10000 calls to StockSpanner.next per test case.
There will be at most 150000 calls to StockSpanner.next across all test cases.
The total time limit for this problem has been reduced by 75% for C++, and 50% for all other languages.
*/

/*
Approach 1: Brute force
Store the stock price in a vector.
For each next(price), check all the stocks backward in the array.
Traverse and count backward till the stock prices are less tha or equal to current stock.
Return the count.

Time complexity = O(n^2)
This solution is resulted in time limit exceeded.

Approach 2:
Maintain a day counter. Initialized to 0 and incremented by 1 on each call to next.
Maintain a vector for stocks and a stack for days. 
For each call on next
  1. Increment the day counter. 
  2. Add the current stock price in the stocks vector.
  3. Check and pop out the top of stack, if on that day (top of stack will return day) stock price is less than or 
     equal current stock price.The stock price for a day can be obtained from vector.
     Perform this step until the stack is empty and current price is greater.
  4. If the stack is empty, the current price is greater than all the previous stocks prices
     Then span = current day 
     Push current day on stack.
     
     If the stack is not empty, that means we found the day on which the stock price was higher than current stock price.
     Then, span  = current day - top of stack;
     Push current day on stack.
     
     Return span.

*/

class StockSpanner {
    vector<int>stocks;
    stack<int>st;
        vector<int> span;
    int day;
public:
    StockSpanner() {
        day = 0;
    }
    
    /*
      Approach 1: brute force
      
      int next(int price) {
        stocks.push_back(price);
        int count = 0;
        for(int i = stocks.size()-1;i>=0;i--)
        {
            if(stocks[i]<=price)
                count++;
            else
                break;
        }
        return count;
    }*/
    /*
    Aprroach 2: Using stack.
    */
    int next(int price) 
    {
        int ret = -1;
        ++day;
        stocks.push_back(price);
        if(day ==1)
        {
            st.push(day);
            span.push_back(1);
            ret = 1;
        }
        else
        {
            while(!st.empty())
            {
                if(stocks[st.top()-1]<=price)
                    st.pop();
                else
                    break;
                    
            }
            if(st.empty())
            {
                ret =  day;
                st.push(day);
            }
            else
            { 
                ret =  day - st.top();
                st.push(day);
            }
                
        }
           return ret; 
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
