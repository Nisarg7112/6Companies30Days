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
    void f(ListNode* head,vector<int>& v){
        if(head->next==NULL){
            v.push_back(head->val);
            return;
        }

        v.push_back(head->val);
        f(head->next,v);

        return;
    }
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int>v;
        f(head,v);
        vector<int>d;
        d.push_back(0);
        int sum=0;
        for(int i=0;i<v.size();i++){
            sum+=v[i];
            d.push_back(sum);
        }

        vector<int>ans;
        for(int i=0;i<d.size();i++){
            if(i!=0 && v[i-1]==0){
                continue;
            }

            int j=d.size()-1;
            for(;j>=i;j--){
                if(d[j]==d[i]){
                    break;
                }
            }
            if(i!=0){
            ans.push_back(v[i-1]);
            }
            i=j;
        }

        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }

        if(ans.size()!=0){
            ListNode *temp=new ListNode(ans[0]);
            ListNode *x=temp;
            for(int i=1;i<ans.size();i++){
                ListNode *temp1=new ListNode(ans[i]);
                x->next=temp1;
                x=x->next;
            }

            return temp;
        }

        return NULL;
    }
};
