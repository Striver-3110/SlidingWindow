#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int maxSatisfied(vector<int>& NotGrupmy, vector<int>& grumpy, int minutes) {

        vector<pair<pair<int,int>,int>> windowDiff;
        if(NotGrupmy.size() == 1){
            return NotGrupmy[0];
        }
        vector<int> Grupmy;
        int grumpySum = 0, NotGrumpySum = 0, totalSum = 0;
        for(int i = 0; i < NotGrupmy.size(); i++){
            totalSum += NotGrupmy[i];
            if(grumpy[i] == 0){
                Grupmy.push_back(NotGrupmy[i]);
            }
            else{
                Grupmy.push_back(0);
            }
            if(i < minutes){
                NotGrumpySum += NotGrupmy[i];
                grumpySum += Grupmy[i];
            }
        }

        windowDiff.push_back({{0,minutes-1},NotGrumpySum - grumpySum});
        int i = 1, j = minutes;

        int n = NotGrupmy.size();

        while(j < n){
            NotGrumpySum = NotGrumpySum - NotGrupmy[i-1] + NotGrupmy[j];
            grumpySum = grumpySum - Grupmy[i-1]  + Grupmy[j];
            windowDiff.push_back({{i,j},NotGrumpySum - grumpySum});
            i++;
            j++;
        }

        sort(windowDiff.begin(),windowDiff.end(),[](pair<pair<int,int>,int> &a ,pair<pair<int,int>,int> &b){
            return a.second > b.second;
        });
       
        i = windowDiff[0].first.first; j = windowDiff[0].first.second;
        int ans = 0;

        for(int k = 0; k < n ; k++){
            if(k < i || k > j)
                ans += Grupmy[k];
            else{
                ans += NotGrupmy[k];
            }
        }
        return ans;
    }

    int maxSatisfied(vector<int>& NotGrupmy, vector<int>& grumpy, int minutes) {

        if(NotGrupmy.size() == 1){
            return NotGrupmy[0];
        }
        vector<int> Grupmy;
        int grumpySum = 0, NotGrumpySum = 0, totalSum = 0;
        for(int i = 0; i < NotGrupmy.size(); i++){
            totalSum += NotGrupmy[i];
            if(grumpy[i] == 0){
                Grupmy.push_back(NotGrupmy[i]);
            }
            else{
                Grupmy.push_back(0);
            }
            if(i < minutes){
                NotGrumpySum += NotGrupmy[i];
                grumpySum += Grupmy[i];
            }
        }

        int i = 1, j = minutes;

        int n = NotGrupmy.size();

        int maxSum =  NotGrumpySum - grumpySum;
        pair<int,int> pr = {0,minutes-1};

        while(j < n){
            NotGrumpySum = NotGrumpySum - NotGrupmy[i-1] + NotGrupmy[j];
            grumpySum = grumpySum - Grupmy[i-1]  + Grupmy[j];
            if(maxSum < NotGrumpySum - grumpySum){
                maxSum = NotGrumpySum - grumpySum;
                pr = {i,j};
            }
            i++;
            j++;
        }

        int ans = 0;

        i = pr.first; 
        j = pr.second;

        for(int k = 0; k < n ; k++){
            if(k < i || k > j)
                ans += Grupmy[k];
            else{
                ans += NotGrupmy[k];
            }
        }
        return ans;
    }

    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int satisfied = 0;
        int n = customers.size();
        // if the owner is not grumpy then all the customer will be satisfied
        for(int i = 0; i < n; i++){
            if(grumpy[i] == 0){
                satisfied += customers[i];
                customers[i] = 0;
            }
        }
        // now we will just focus on the customers thoes who were not satisfied
        int notSatisfied = 0;
        int i = 0;
        while(i < minutes){
            notSatisfied += customers[i++];
        }

        int max = notSatisfied;

        while(i < n){
            notSatisfied += customers[i];
            notSatisfied -= customers[i-minutes];
            max = std::max(max,notSatisfied);
            i++;
        }

        return max + satisfied;

    }
};


int main() {
    Solution solution;
    vector<int> NotGrumpy = {1, 0, 1, 2, 1, 1, 7, 5};
    vector<int> grumpy = {0, 1, 0, 1, 0, 1, 0, 1};
    int minutes = 3;

    int result = solution.maxSatisfied(NotGrumpy, grumpy, minutes);

    cout << "Maximum number of satisfied customers: " << result << endl;

    return 0;
}
