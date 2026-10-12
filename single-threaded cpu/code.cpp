class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<tuple<long long, long long, int>> jobs;
        for (int i=0; i<n; i++) {
            jobs.push_back({tasks[i][0], tasks[i][1], i});
        }
        sort(jobs.begin(), jobs.end());
        priority_queue<
        pair<long long, int>,
        vector<pair <long long, int>>,
        greater<pair<long long, int>>
        >pq;
        vector<int> answer;
        long long currentTime =0;
        int i=0;
        while(i<n ||!pq.empty()){
            if (pq.empty()){
                currentTime = max(currentTime, get<0> (jobs[i]));
            }
            while (i<n && get<0> (jobs[i])<= currentTime){
                pq.push({get<1>(jobs[i]), get<2> (jobs[i])});
                i++;

            }
            auto[processingTime, index]= pq.top();
            pq.pop();
            answer.push_back(index);
            currentTime += processingTime;
        }
        return answer;
    }

    
};

