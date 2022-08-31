#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <iterator>
#include <map>

#include "LinkedList.h"

// Testing header file
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace std;

// To use command prompt to build and execute
    // for building exe	// "g++ -o source source.cpp"
    // for running exe // "source"

// To use git bash to build and execute
    // for building exe	// "g++ -o source source.cpp"
    // for running exe // "./source.exe"

// catch2 testing
    // for both cmd and bash, add a '-?' to the exe for more info on testing
        // ex: g++ -o Source Source.cpp && ./Source.exe -s [fibonacci]

// 894 - All Possible Full Binary Trees
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};



int maxSubArray(vector<int>& nums) {
    int max = -100000;  // -10^5 <= nums[i] <= 10^5

    int temp = 0;
    if (nums.size() == 1) return nums[0];

    for (int j = 0; j < nums.size(); j++) {
        for (int i = j; i < nums.size(); i++) {
            temp += nums[i];
            if (temp > max) max = temp;
        }
        temp = 0;
    }
    return max;
}
vector<int> countBits(int n) {
    vector<int> bits = { 0 };
    for (int i = 1; i <= n; i++) {
        int count = 0;
        int quotient = i;
        int r;
        while (quotient != 0) {
            r = quotient % 2;   // n =6, r = 0
            quotient = quotient / 2;   // n =6, q = 6/2 = 3
            if (r == 1) count++;
        }
        bits.push_back(count);
    }
    return bits;
}
int fib(int n) {
    if (n == 0 || n == 1) return n;
    return (fib(n - 1) + fib(n - 2));

    // F(4) = F(4-1) + F(4-2)
        // = F(3) + F(2)
            // F(3-1) + F(3-2) + F(2-1) + F(2-2)
                // F(2) + F(1) + F(1) + F(0)
                    // F(2-1) + F(2-2) + F(1) + F(0)
                        // F(1) + F(0) + F(1) + F(1) + F(0)
}

TEST_CASE("Fibonacci are computed", "[fibonacci]") {
    REQUIRE(fib(4) == 3);
    REQUIRE(fib(5) == 5);
    REQUIRE(fib(6) == 8);
    REQUIRE(fib(10) == 55);
    REQUIRE(fib(20) == 6765);
}


bool divisorGame(int n) {
    bool turn = 0;  // 0 - Alice, 1 -Bob
    int countTurn = 0;
    for (int x = 1; x < n; x++)
    {
        if (0 < x < n && n % x == 0) {
            n = n - x;
            x = 0;
            countTurn++;
            if (countTurn % 2 == 1) turn = 1; // Now Bob's Turn
            if (countTurn % 2 == 0) turn = 0;  // Now Alice's Turn
        }
    }
    if (turn == 1) return true;
    else return false;
}
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> triangle{ {1} };
    if (numRows == 1) return triangle;
    if (numRows == 2) {
        vector<int> row = { 1 , 1 };
        triangle.push_back(row);
        return triangle;
    }

    vector<int> row = { 1 , 1 };
    triangle.push_back(row);

    for (int64_t i = 2; i < numRows; i++) {
        vector<int> rows = { 1 };
        int sum;

        for (int64_t j = 0; j < triangle[i - 1].size() - 1; j++) {
            sum = triangle[i - 1][j] + triangle[i - 1][j + 1];
            rows.push_back(sum);
        }
        rows.push_back(1);
        triangle.push_back(rows);
    }

    // 1
    //1 1
    //1 2 1

    return triangle;

}
int tribonacci(int n) {
    if (n == 0) return n;
    else if (n == 1 || n == 2) return 1;
    return (tribonacci(n - 3) + tribonacci(n - 2) + tribonacci(n - 1));
}
int tribonacci1(int n) {  // This tribonacci is much more faster than the above implmentation
    vector<int> nums = { 0,1,1 };
    for (int64_t i = 3; i <= n; i++) {
        nums.push_back(nums[i - 3] + nums[i - 2] + nums[i - 1]);
    }
    return nums[n];
}
int distributeCandies(vector<int>& candyType) {
    int val;
    int type = 0, count = 0;
    for (int i = 0; i < 100000; i++) {
        for (int j = 0; j < candyType.size(); j++) {
            val = candyType[j];
            if (val == i) {
                count++;
            }
        }
        if (count > 0) {
            type++;
            count = 0;
        }
    }
    int edibleCandies;
    edibleCandies = candyType.size() / 2;
    if (edibleCandies >= type) {
        return type;
    }
    else return edibleCandies;

}
int minCostClimbingStairs(vector<int>& cost) {
    for (int64_t i = 2; i < cost.size(); i++) {
        cost[i] += min(cost[i - 1], cost[i - 2]);
    }
    return min(cost[cost.size() - 1], cost[cost.size() - 2]);
}
vector<int> getRow(int rowIndex) {
    vector <vector<int>> triangle = { {1}, {1,1} };

    if (rowIndex == 0) return triangle[0];
    if (rowIndex == 1) return triangle[1];

    for (int64_t i = 2; i <= rowIndex; i++) {
        vector<int> row;
        row.push_back(1);
        int sum;

        for (int64_t j = 0; j < triangle[i - 1].size() - 1; j++) {
            sum = triangle[i - 1][j] + triangle[i - 1][j + 1];
            row.push_back(sum);
        }
        row.push_back(1);
        triangle.push_back(row);
    }
    return triangle[rowIndex];
}

int maxProfit(vector<int>& prices) {
    int profit = 0;
    int i = 0;
    int min = prices[0];

    while (i < prices.size()) {
        if (prices[i] < min) min = prices[i];
        else {
            profit = max(profit, prices[i] - min);
        }
        i++;

    }
    return profit;
}
int maxProfitII(vector<int>& prices) {
    int min = prices[0];
    int profit = 0;

    for (int i = 0; i < prices.size(); i++) {
        if (prices[i] < min) min = prices[i];
        else {
            profit += (prices[i] - min);
            min = prices[i];
        }
    }

    return profit;
}
int climbStairs(int n) {
    if (n == 1 || n == 2 || n == 3) return n;
    return (climbStairs(n - 1) + climbStairs(n - 2));
}

int climbStairs2(int n) {
    if (n == 0 || n == 1 || n == 2) return n;



    int output = 0;

    int previousStep = 2;  // n-1 = 2 ways 
    int previousStep2 = 1; // n-2 = 1 ways    

    // n = 3
        // n - 1 = > 3 -1 = 2
        // n - 2 = > 3 -2 = 1

    // n = 1 1 ways
    // n = 2 2 ways
    // n = 3 3 ways
    // n = 4 5 ways


    for (int i = 3; i <= n; i++) {
        output = previousStep + previousStep2;
        previousStep2 = previousStep;
        previousStep = output;
    }
    return output;
}


// Definition for singly-linked list.
    //struct ListNode {
    //    int val;
    //    ListNode* next;
    //    ListNode() : val(0), next(nullptr) {}
    //    ListNode(int x) : val(x), next(nullptr) {}
    //    ListNode(int x, ListNode* next) : val(x), next(next) {}
    //};

    //ListNode* node1 = new ListNode(1, new ListNode(2));
    //ListNode* node3 = new ListNode(3, new ListNode(4));
    //node1->next->next = node3;
    //ListNode* node5 = new ListNode(5);
    //node3->next->next = node5;

    //ListNode* temp = node1;

    //cout << "\nListNode Struct:\n[ ";
    //while (temp != nullptr) {
    //    cout << temp->val << " ";
    //    temp = temp->next;
    //}
    //cout << "]\n";

void reorderList(LinkedList::Node* head) {
    LinkedList::Node* temp = head;
    LinkedList::Node* half = head;
    LinkedList::Node* prev = nullptr;

    // if (head == nullptr) return;

    // First find half
    while (temp->next && temp->next->next) {
        temp = temp->next->next;
        half = half->next;
    }

    // split list into half
    while (half) {
        temp = half->next;
        half->next = prev;
        prev = half;
        half = temp;
    }

    half = prev;

    // merge both lists
    while (half && head) {
        temp = head->next;
        prev = half->next;

        head->next = half;
        half->next = temp;

        head = temp;
        half = prev;
    }
}

vector<int> twoSum(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) return { i,j };
        }
    }

    // this return is never reached but needed to compile
    return { 0,1 };
}

// This is a slower alternative to the above solution
    //vector<int> v;
    //v.push_back(i);
    //v.push_back(j);
    //return v;


vector<vector<int>> merge(vector<vector<int>>& intervals) {
    // Sorting a 2d array with intervals based on starting element of each interval
    // time exceeded though it passes all 216 test cases
    sort(intervals.begin(), intervals.end(),
        [](const std::vector<int>& a, const std::vector<int>& b)
        {
            return a[0] < b[0];
        });

    for (int i = 0; i < intervals.size() - 1; i++) {
        if (intervals[i][1] >= intervals[i + 1][0]) {
            if (intervals[i][1] >= intervals[i + 1][1]) {
                intervals.erase(intervals.begin() + (i + 1));
                i--;
            }
            else {
                intervals[i][1] = intervals[i + 1][1];
                intervals.erase(intervals.begin() + (i + 1));
                i--;
            }
        }
    }
    return intervals;
}
vector<vector<int>> merge2(vector<vector<int>>& intervals) {
    // Sorting a 2d array with intervals based on starting element of each interval
    // nlogn
    sort(intervals.begin(), intervals.end(),
        [](const std::vector<int>& a, const std::vector<int>& b)
        {
            return a[0] < b[0];
        });
    vector < vector<int>> ans = { intervals[0] };

    for (int i = 1; i < intervals.size(); i++) {
        if (ans.back()[1] >= intervals[i][0]) {
            ans.back()[1] = max(intervals[i][1], ans.back()[1]);
        }
        else {
            ans.push_back(intervals[i]);
        }
    }
    return ans;
}

LinkedList::Node* addTwoNumbers(LinkedList::Node* l1, LinkedList::Node* l2) {
    LinkedList::Node* head = l1;
    LinkedList::Node* temp = l1;
    LinkedList::Node* prev = nullptr;

    string val1, val2 = "";
    int result{ 0 };

    LinkedList::Node* head2 = l2;
    LinkedList::Node* temp2 = l2;
    LinkedList::Node* prev2 = nullptr;

    while (head) {
        temp = head->next;
        head->next = prev;

        prev = head;
        head = temp;
    }
    l1 = prev;

    while (l1) {
        val1 += to_string(l1->val);
        l1 = l1->next;
    }

    while (head2) {
        temp2 = head2->next;
        head2->next = prev2;

        prev2 = head2;
        head2 = temp2;
    }
    l2 = prev2;

    while (l2) {
        val2 += to_string(l2->val);
        l2 = l2->next;
    }

    //result = stoi(val1) + stoi(val2); // stoi,stol, stoll is out of range 

    //cout << result;

    string ans = to_string(result);
    reverse(ans.begin(), ans.end());
    cout << ans << endl;

    LinkedList::Node* newHead = new LinkedList::Node();
    LinkedList::Node* newtemp = newHead;

    for (int i = 0; i < ans.size(); i++) {
        newtemp->val = ans[i] - '0';
        if (i != ans.size() - 1) {
            LinkedList::Node* container = new LinkedList::Node();
            newtemp->next = container;
            newtemp = container;
        }

    }
    newtemp->next = nullptr;
    return newHead;
}
LinkedList::Node* addTwoNumbers2(LinkedList::Node* l1, LinkedList::Node* l2) {
    LinkedList::Node* head = l1;
    LinkedList::Node* temp = l1;
    LinkedList::Node* prev = l1;

    int val1, val2;
    int sum;

    LinkedList::Node* head2 = l2;
    LinkedList::Node* temp2 = l2;
    LinkedList::Node* prev2 = nullptr;

    int carry = 0;
    while (temp2 && temp) {
        val2 = temp2->val;

        val1 = temp->val;
        if (carry != 0) { sum = val1 + val2 + carry; }
        else { sum = val1 + val2; }
        carry = sum / 10;
        sum = sum % 10;

        temp->val = sum;
        temp2->val = sum;

        temp = temp->next;
        temp2 = temp2->next;

    }

    while (temp) {
        prev = temp;
        sum = temp->val + carry;
        carry = sum / 10;
        sum = sum % 10;

        temp->val = sum;
        temp = temp->next;
        if (temp == nullptr && carry != 0) {
            prev->next = new LinkedList::Node(carry);
            return head;
        }

        if (temp == nullptr) { return head; }
    }

    while (temp2) {
        prev2 = temp2;
        sum = temp2->val + carry;
        carry = sum / 10;
        sum = sum % 10;

        temp2->val = sum;
        temp2 = temp2->next;
        if (temp2 == nullptr && carry != 0) {
            prev2->next = new LinkedList::Node(carry);
            return head2;

        }
        if (temp2 == nullptr) { return head2; }

    }
    LinkedList::Node* lastTemp = head;
    if (temp == nullptr && temp2 == nullptr) {
        while (lastTemp) {
            prev = lastTemp;
            lastTemp = lastTemp->next;

            if (lastTemp == nullptr && carry != 0) {
                prev->next = new LinkedList::Node(carry);
                return head;
            }
        }
    }
    return head;

    // 99999999
    // 9999
    // 89990001
}

bool isPalindrome(int x) {
    if (x < 0) { return false; }
    string first = to_string(x);
    string second = to_string(x);
    int size = second.size();

    // 121 

    for (int i = 0; i < (size / 2); i++) {
        char temp = second[size - 1 - i];
        second[size - 1 - i] = second[i];
        second[i] = temp;
    }

    if (first == second) { return true; }
    return false;
}

TEST_CASE("Palindrome are computed", "[palindrome]") {
    REQUIRE(isPalindrome(121) == true);
    REQUIRE(isPalindrome(1211) == false);
    REQUIRE(isPalindrome(1234554321) == true);
    REQUIRE(isPalindrome(852258) == true);
    REQUIRE(isPalindrome(12) == false);
}

int romanToInt(string s) {

    // vector<string> specialCases ={"IV", "IX", "XL", "XC", "CD", "CM"};
    map<string, int> specialCases;
    specialCases.insert(pair<string, int>("IV", 4));
    specialCases.insert(pair<string, int>("IX", 9));
    specialCases.insert(pair<string, int>("XL", 40));
    specialCases.insert(pair<string, int>("XC", 90));
    specialCases.insert(pair<string, int>("CD", 400));
    specialCases.insert(pair<string, int>("CM", 900));

    specialCases.insert(pair<string, int>("I", 1));
    specialCases.insert(pair<string, int>("V", 5));
    specialCases.insert(pair<string, int>("X", 10));
    specialCases.insert(pair<string, int>("L", 50));
    specialCases.insert(pair<string, int>("C", 100));
    specialCases.insert(pair<string, int>("D", 500));
    specialCases.insert(pair<string, int>("M", 1000));

    int  answer = 0;




    if (s.length() == 1) {
        string temp(1, s[s.length() - 1]);
        auto it = specialCases.find(temp);
        answer += it->second;

        return answer;
    }


    for (int i = 1; i < s.length();) {
        string temp(1, s[i - 1]); temp += s[i];
        auto it = specialCases.find(temp);
        if (it != specialCases.end()) {
            answer += it->second;
            i += 2;

            if (i == s.length()) {
                string temp(1, s[s.length() - 1]);
                auto it = specialCases.find(temp);
                answer += it->second;
            }
        }
        else {
            temp = s[i - 1];
            it = specialCases.find(temp);
            answer += it->second;
            i++;

            if (i == s.length()) {
                string temp(1, s[s.length() - 1]);
                auto it = specialCases.find(temp);
                answer += it->second;
            }
        }
    }


    return answer;
}

int romanToInt2(string s) {

    map<char, int> specialCases;

    specialCases.insert(pair<char, int>('I', 1));
    specialCases.insert(pair<char, int>('V', 5));
    specialCases.insert(pair<char, int>('X', 10));
    specialCases.insert(pair<char, int>('L', 50));
    specialCases.insert(pair<char, int>('C', 100));
    specialCases.insert(pair<char, int>('D', 500));
    specialCases.insert(pair<char, int>('M', 1000));

    int answer = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'I') {
            if (i + 1 < s.length() && s[i + 1] == 'V') {
                answer += 4;
                i++;
            }
            else if (i + 1 < s.length() && s[i + 1] == 'X') {
                answer += 9;
                i++;
            }
            else {
                auto it = specialCases.find('I');
                answer += 1;
            }
        }

        else if (s[i] == 'C') {
            if (i + 1 < s.length() && s[i + 1] == 'D') {
                answer += 400;
                i++;
            }
            else if (i + 1 < s.length() && s[i + 1] == 'M') {
                answer += 900;
                i++;

            }
            else {
                auto it = specialCases.find('C');
                answer += 100;
            }
        }

        else if (s[i] == 'X') {
            if (i + 1 < s.length() && s[i + 1] == 'L') {
                answer += 40;
                i++;

            }
            else if (i + 1 < s.length() && s[i + 1] == 'C') {
                answer += 90;
                i++;

            }
            else {
                auto it = specialCases.find('X');
                answer += 10;
            }

        }

        else {
            auto it = specialCases.find(s[i]);
            answer += it->second;
        }
    }

    return answer;
}

vector<int> getConcatenation(vector<int>& nums) {

    vector<int> answer;
    int size = nums.size();
    answer.reserve(size * 2);

    for (int i = 0; i < size; i++) { answer.push_back(nums[i]); }
    for (int i = 0; i < size; i++) { answer.push_back(nums[i]); }

    return answer;
}



TEST_CASE("Concatenated Arrays are computed", "[concat-arrays]") {
    vector<int> input;
    vector<int> result;

    input = { 1,2,1,1 };
    result = { 1,2,1,1,1,2,1,1 };
    REQUIRE(getConcatenation(input) == result);

    input = { 12,21,131 };
    result = { 12,21,131,12,21,131 };
    REQUIRE(getConcatenation(input) == result);

    input = { 11,2214,1253 };
    result = { 11,2214,1253,11,2214,1253 };
    REQUIRE(getConcatenation(input) == result);

    input = { 98,42,78,33 };
    result = { 98,42,78,33,98,42, 78, 33 };
    REQUIRE(getConcatenation(input) == result);
}



//     int maximumWealth(vector<vector<int>>& accounts) {

// }



// int main() {

// 	Solution ob;
//     vector<int> input = {1,2,1};
//     ob.getConcatenation(input);

//     cout << "HEKKIW WORKD";

    // int n = 20;
    // vector<vector<int>> triangle;
    // triangle = ob.generate(n);
    // for (int i = 0; i < triangle.size(); i++) {    // triangle.size() represents the # of rows
    //    for (int j = 0; j < triangle[i].size(); j++) {  //triangle[i].size() represents the # of colums within that row
    //        cout << triangle[i][j] << " ";
    //    }
    //    cout << endl;
    // }





    //cout << "\nADDITION CALCULATOR\n" ;
    //int x{ 0 }, y{ 0 }, sum{ 0 };
    //cout << "Enter fist #: "; cin >>x;
    //cout << "Enter second #: "; cin >>y;
    //sum = x+y;
    //cout << "Sum is: " << sum << "\n";

// }


// Examples
// 53- Sub ArrayMeximum
    // Input: nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
    // Output : 6
    // Explanation : [4, -1, 2, 1] has the largest sum = 6.
// 338-Counting Bits
    //Input: n = 2
        //Output: [0, 1, 1]
        //Explanation :
        //    0 -- > 0
        //    1 -- > 1
        //    2 -- > 10
// 509 - Fibonacci Number
    //Input: n = 2
    //Output : 1
    //Explanation : F(2) = F(1) + F(0) = 1 + 0 = 1.
// 1025 - Divisor Game
    //Input: n = 2
    //Output : true
    //Explanation : Alice chooses 1, and Bob has no more moves.
// 	118 - Pascal's Triangle
    //Input: numRows = 5
    //Output : [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1], [1, 4, 6, 4, 1]]
// 1137 - N-th Tribonacci Number
    //Input: n = 4
    //Output : 4
    //Explanation :
    //    T_3 = 0 + 1 + 1 = 2
    //    T_4 = 1 + 1 + 2 = 4
// 575 - Distribute Candies
    // Input: candyType = [1, 1, 2, 2, 3, 3]
    // Output : 3
    // Explanation : Alice can only eat 6 / 2 = 3 candies. Since there are only 3 types, she can eat one of each type.
// 894 - All Possible Full Binary Trees
// 746 - Min Cost Climbing Stairs
    //Input: cost = [10, 15, 20]
    //Output : 15
    //Explanation : Cheapest is : start on cost[1], pay that cost, and go to the top.
// 119  Pascal's Triangle II
    //Input: rowIndex = 3
    //Output : [1, 3, 3, 1]
// 121. Best Time to Buy and Sell Stock
    //Input: prices = [7, 1, 5, 3, 6, 4]
    //Output : 5
    //Explanation : Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6 - 1 = 5.
    //Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
// 122 - Best Time to Buy and Sell Stock II
    //Input: prices = [7, 1, 5, 3, 6, 4]
    //Output : 7
    //Explanation : Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5 - 1 = 4.
    //Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6 - 3 = 3.
    //Total profit is 4 + 3 = 7.
// 70 - Climbing Stairs
    //Input: n = 2
    //Output : 2
    //Explanation : There are two ways to climb to the top.
    //1. 1 step + 1 step
    //2. 2 steps
// 143. Reorder List
    //Input: head = [1, 2, 3, 4]
    //Output : [1, 4, 2, 3]
    //Input: head = [1, 2, 3, 4, 5]
    //Output : [1, 5, 2, 4, 3]
// 1. Two Sum
    //Input: nums = [2, 7, 11, 15], target = 9
    //Output : [0, 1]
    //Output : Because nums[0] + nums[1] == 9, we return[0, 1].
//56. Merge Intervals
    //Input: intervals = [[1, 3], [2, 6], [8, 10], [15, 18]]
    //Output : [[1, 6], [8, 10], [15, 18]]
    //Explanation : Since intervals[1, 3] and [2, 6] overlaps, merge them into[1, 6].
//2. Add Two Numbers
    //Input: l1 = [2, 4, 3], l2 = [5, 6, 4]
    //Output : [7, 0, 8]
    //Explanation : 342 + 465 = 807.
//9. Palindrome Number
    // Input: x = 121
    // Output: true
    // Explanation: 121 reads as 121 from left to right and from right to left.
//13. Roman to integer 
    // Input: s = "MCMXCIV"
    // Output: 1994
    // Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
// 1929. Concatenation of Array
    // Input: nums = [1,2,1]
    // Output: [1,2,1,1,2,1]
    // Explanation: The array ans is formed as follows:
    // - ans = [nums[0],nums[1],nums[2],nums[0],nums[1],nums[2]]
    // - ans = [1,2,1,1,2,1]
// -----------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------

// Code to run each Problem
// 53-Meximum Sub Array
    // vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    // vector<int> nums = { 5,4,-1,7,8 };
    // vector<int> nums = { 5 };
    // cout << ob.maxSubArray(nums);
// 338 - Counting Bits
    // int n = 15;
    // vector<int> bits = ob.countBits(n);
    // for (int i = 0; i < bits.size(); i++) {
    //        cout << bits[i] << ", ";
    // }
// 509 - Fibonacci Number
    //int n = 4;
    //cout << ob.fib(n);
// 1025 Divisor Game
    //int n = 3;
    //cout << ob.divisorGame();
// 118 - Pascal's Triangle
    //int n = 5;
    //vector<vector<int>> triangle;
    //triangle = ob.generate(n);
    //for (int i = 0; i < triangle.size(); i++) {    // triangle.size() represents the # of rows
    //    for (int j = 0; j < triangle[i].size(); j++) {  //triangle[i].size() represents the # of colums within that row
    //        cout << triangle[i][j] << " ";
    //    }
    //    cout << endl;
    //}
// 1137 - N-th Tribonacci Number
    // cout << ob.tribonacci(35);  // Takes 35 seconds to compute
    // cout << ob.tribonacci1(35);   // Takes less than a second
// 575 - Distribute Candies
    // vector<int> candyType = { 1, 1, 2, 2, 3, 3 };
    //vector<int> candyType = {1,1,2,3 };
    // vector<int> candyType = { 6,6,6,6 };
    // cout << ob.distributeCandies(candyType);
// 894 - All Possible Full Binary Trees
// 746. Min Cost Climbing Stairs
    // vector<int> cost = { 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 };
    // vector<int> cost = { 10,15,20 };
    //vector<int> cost = { 0,0,2, 1 };
// 119  Pascal's Triangle II
    //vector<int> row;
    //row = ob.getRow(4);
    //
    //for (int i = 0; i < row.size(); i++) {
    //    cout << row[i];
    //}
// 121 - Best Time to Buy and Sell Stock
    //vector<int> prices = { 7, 1, 5, 3, 6, 4 };
    //cout << ob.maxProfit(prices);
// 122 - Best Time to Buy and Sell Stock II
    // vector<int> prices = { 7, 1, 5, 3, 6, 4 };
    // vector<int> prices = { 1,2,3,4,5 };
    // vector<int> prices = { 7,6,4,3,1 };
    // cout << ob.maxProfitII(prices);
// 70 - Climbing Stairs
       // cout << ob.climbStairs(21);
// 143. Reorder List
    //LinkedList l1;
    //l1.addNodeEnd(l1.createNode(1));
    //l1.addNodeEnd(l1.createNode(2));
    //l1.addNodeEnd(l1.createNode(3));
    //l1.addNodeEnd(l1.createNode(4));
    //l1.addNodeEnd(l1.createNode(5));
    //l1.addNodeEnd(l1.createNode(6));
    //l1.removeNodeEnd();
    //
    //cout << "LinkedList Class:\n";
    //l1.printList();
    //
    ////%p is the pointer specifier for printf
    //printf("Head is at address: %p\n", l1.getHead());
    //
    //
    //Solution ob;
    //ob.reorderList(l1.getHead());
    //l1.printList();

//56. Merge Intervals
    //vector<vector<int>> input = { {1,4}, {0,2}, {3,5} };
    ////vector<vector<int>> input = { {3,3}, {2,6}, {8,10}, {15,18} };
    //
    //
    //Solution ob;
    //ob.merge(input);
    //
    //for (int i = 0; i < input.size(); i++) {
    //    cout << "[ ";
    //    for (int j = 0; j < input[i].size(); j++) {
    //        cout << input[i][j] << " ";
    //    }
    //    cout << "] ";
    //}
//2. Add Two Numbers
    //LinkedList l1;
    //l1.addNodeEnd(l1.createNode(0));
    //LinkedList l2;
    //l2.addNodeEnd(l2.createNode(7));
    //l2.addNodeEnd(l2.createNode(3));
    //
    ////l1.printList();
    //Solution ob;
    //
    //LinkedList result;
    //result.addNodeEnd(ob.addTwoNumbers2(l1.getHead(), l2.getHead()));
    //result.printList();
//9. Palindrome 
    //Solution ob;
    //cout << ob.isPalindrome(1251);
//13. Roman to integer 
    // Solution ob;
    // cout << ob.romanToInt2("MCMXCIV");
// 1929. Concatenation of Array
    // Solution ob;
    // vector<int> input = {1,2,1};
    // ob.getConcatenation(input);
