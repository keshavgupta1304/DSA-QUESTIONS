/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        int directions[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        int currentDirection=0;
        int row=0;
        int col=0;
        while(head)
        {
            ans[row][col]=head->val;
            int nextRow=row+directions[currentDirection][0];
            int nextCol=col+directions[currentDirection][1];
            if(nextRow<0 || nextCol<0 || nextRow>=m || nextCol>=n || ans[nextRow][nextCol]!=-1)
            {
                currentDirection=(currentDirection+1)%4;
            }
            row=row+directions[currentDirection][0];
            col=col+directions[currentDirection][1];
            head=head->next;
        }
        return ans;
    }
};