class MyCircularQueue {
private:
    int front, end, length;
    vector<int> que;
public:
    MyCircularQueue(int k) {
        que.reserve(k);  // 预定k个空间！
        front = -1, end = -1;
        length = k;
    }
    bool enQueue(int value) {
        if(isFull()) return false;  //满了
        else if(isEmpty()) {   //空的
            front++;
            end++;
        }
        else {
            if((end+1)==length)  end = 0;
            else end++;
        }
        que[end] = value;
        return true;
    }
    bool deQueue() {
        if(isEmpty())  return false;
        else if(front == end) {  //只有一个数
            front = -1;
            end = -1;
        }
        else {
            if(front+1 == length) front = 0;
            else front++;
        }
        return true;
    }
    int Front() {
        if(isEmpty()) return -1;
        return que[front];
    }
    int Rear() {
        if(isEmpty()) return -1;
        return que[end];
    }
    bool isEmpty() {
        if(front==end && front==-1) return true;
        else return false;
    }
    bool isFull() {
        if((end+1)%length==front) return true;
        else return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */