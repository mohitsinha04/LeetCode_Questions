class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    int size = 0;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxheap.empty() || maxheap.top() >= num)
            maxheap.push(num);
        else 
            minheap.push(num);
        if(maxheap.size() > minheap.size() + 1) {
            minheap.push(maxheap.top());
            maxheap.pop();
        } 
        if(minheap.size() > maxheap.size()) {
            maxheap.push(minheap.top());
            minheap.pop();
        }
        size++;
    }
    
    double findMedian() {
        if(size % 2 == 0) {
            return (double) (maxheap.top() + minheap.top()) / 2.0;
        }
        return maxheap.top();
    }
};
​
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
