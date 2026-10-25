class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        int freq[26]={0}; // 0 = A, 1 = B

        for(char& task : tasks)
        {
            freq[task - 'A']++;
        }

        priority_queue<pair<int,char>> pq;
        // {freq, "A"} 但其實這題不需要紀錄字元。

        for(int i=0 ; i<26 ; ++i)
        {
            if(freq[i] != 0)
            {
                pq.push({freq[i], (char)(i + 'A')});
            }
        }

        // priority_queue<pair<int, pair<int,char>>, vector<>, greater<>> minHeap;

        priority_queue<
                    pair<int, pair<int,char>>,
                    vector<pair<int, pair<int,char>>>,
                    greater<pair<int, pair<int,char>>>
                > minHeap;

        int time=0;
        while(!pq.empty() || !minHeap.empty())
        {
            time++;

            // 要先釋放 因為釋放完可以馬上處理
            if(!minHeap.empty())
            {
                while(!minHeap.empty() && minHeap.top().first == time)
                {
                    pq.push(minHeap.top().second);
                    minHeap.pop();
                }
            }

            if(!pq.empty())
            {
                pair<int,char> task = pq.top();
                pq.pop();

                --task.first;
                if(task.first > 0)
                {
                    minHeap.push({time+n+1, task});
                    // 注意！ 是 time+n + "1"
                }
            }
        }

        return time;
    }
};

// 這題有每個 task 的出現次數後，只要 greedy 的把重複最多的 task 先做就可以取得最好的時間

// 另外的是這題有個為什麼不能用 sort 解題的原因：
// 是因為每 pop 一個字母就要重新 sort 不可能
// 這情況用 pq (heap) 最好

// 重點！這題要怎麼計算 cooldown 時間：
// 用另一個暫存的資料結構來當我們的 cooldown 區，只要 cool n 個 time 就可以回去 pq 裡面

// 所以會需要紀錄 available time 回去 pq 的時間，每次取這個 time 最小的 task 來決定可不可以回去 => 所以用 minHeap 當資結