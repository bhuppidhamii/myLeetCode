class SpecialQueue {

  public:
    // Jai Shri Ram
    queue<int>q;
    map<int,int>mp;
    void enqueue(int x) {
        q.push(x);
        mp[x]++;
    }

    void dequeue() {
        mp[q.front()]--;
        if(mp[q.front()] == 0){
            mp.erase(q.front());
        }
        q.pop();
    }

    int getFront() {
        return q.front();
    }

    int getMin() {
        auto min_it = mp.begin();
        return min_it->first;
    }

    int getMax() {
        auto max_it = prev(mp.end());
        return max_it->first;
    }
};